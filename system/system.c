#include "system.h"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

#define G 6.67e-11
#define M_SOLEIL 1.989e30
// L'unité de la périhélie est le kilomètre
// L'unité de demi grand axe est le kilomètre
// L'unité de l'excentricité est sans unité
//  unité astronomique (149.6e6 kilomètres)


system_t create_system(planet_t star, uint32_t nb_planets, planet_t planetes[], double delta_t)
{
    system_t s;
    s.nb_planets = nb_planets;
    s.planets = planetes;
    s.star = star;
    s.delta_t = delta_t;

    return s;
};

coordinates scale_planets_to_screen_coordinate(planet_t planet, double sma)
{
    // 110% du demi grand axe (semi major axis) de la planete du plus loin
    double rs = (sma / 100) * 110;
    // divison de la position par rs pour mettre à l'échelle.
    planet.pos = division(&planet.pos, rs);
    return vec2_to_coordinates(planet.pos, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void show_system(struct gfx_context_t *ctxt, system_t *system)
{

    coordinates coord_s = scale_planets_to_screen_coordinate(system->star, DEMI_GRAND_AXE_MARS);
    draw_full_circle(ctxt, coord_s.column, coord_s.row, system->star.size, system->star.color);

    for (int i = 0; i < system->nb_planets; i++)
    {

        coordinates coord_p = scale_planets_to_screen_coordinate(system->planets[i], DEMI_GRAND_AXE_MARS);
        if (i == 0)
        {
            printf("x = %d, y =  %d, mass = %lf, i = %d , nb = %d \n", coord_p.column, coord_p.row, system->planets[i].mass, i, system->nb_planets);
        }

        draw_full_circle(ctxt, coord_p.column, coord_p.row, system->planets[i].size, system->planets[i].color);
    }
}

vec2 force_applied_self(planet_t *A, system_t *s)
{
    vec2 all_force = {0, 0};
    vec2 force = force_applied_b_on_a(*A, s->star);
    all_force = add(&all_force, &force);
    for (int i = 0; i < s->nb_planets; i++)
    {
        if (A != &s->planets[i])
        {
            // printf("force ajout += %lf, %lf \n", A->pos.x, A->pos.y);

            force = force_applied_b_on_a(*A, s->planets[i]);
            all_force = add(&all_force, &force);
        }
    }

    return all_force;
}

vec2 initial_planet_position(planet_t *A, system_t *SysA)
{
/*
    vec2 r_perp;
    r_perp.x = -A->pos.y;
    r_perp.y = A->pos.x;
    vec2 res;
    double lhs = sqrt((G * SysA->star.mass * (1 + A->orbite_planet.excentricite)) / (A->orbite_planet.demi_grand_axe * (1 - A->orbite_planet.excentricite)));
    r_perp = normalisation(&r_perp);
    res = multiplication(&r_perp, lhs);
    return res;
  */  
    
    vec2 r_perp;
    r_perp.x = -A->pos.y;
    r_perp.y = A->pos.x;


    //vec2 rp_rpn = multiplication(&r_perp, 1 / norme(&r_perp));
    vec2 rp_rpn = division(&r_perp,norme(&r_perp));

    double GM = SysA->star.mass * G;
    double eP1 = 1 + A->orbite_planet.excentricite;

    double ape1 = A->orbite_planet.demi_grand_axe *  (1 - A->orbite_planet.excentricite);

    double sqrtdiv = sqrt((GM * eP1) / ape1);

     
    vec2 vp0 = multiplication(&rp_rpn, sqrtdiv);
    printf("vpx %lf, vpy %lf \n", vp0.x, vp0.y);
    //vec2 velocity_at_t_0 = multiplication(&rp_rpn, sqrt(SysA->star.mass * G * (1 + A->orbite_planet.excentricite) / A->orbite_planet.demi_grand_axe * (1 - A->orbite_planet.excentricite)));

    vec2 tmp1 = multiplication(&vp0, SysA->delta_t);
    //Planète doit être a la périhélie
    vec2 tmp2 = add(&(A->pos), &tmp1);

    vec2 force_self = force_applied_self(A, SysA);

    //Acceleration
    vec2 a = division(&force_self, A->mass);

    printf("accel x %lf , y %lf \n", a.x, a.y);

    vec2 tmp3 = multiplication(&a, (pow(SysA->delta_t, 2) / 2));

    return add(&tmp2, &tmp3);
    
}

/// @brief Calcule la position de la planète avec les paramètre données depuis des positions antérieur.
/// @param A // Planète
/// @param delta_t Delta du temps (Prendre un espace assez grand)
/// @param p_sys (Système planétaires)
/// @return
vec2 planet_position(planet_t *A, double delta_t, system_t *p_sys)
{

    // Calcule la force appliqué sur une planète ()
    vec2 force_applied_on_planet = force_applied_self(A, p_sys);
    // printf("planete = x -> %lf, y -> %lf \n", force_applied_on_planet.x, force_applied_on_planet.y);
    // Calcule l'accélération de la planète soit => accélération = Force/masse
    A->acceleration = division(&force_applied_on_planet, A->mass);
    //A->acceleration = multiplication(&force_applied_on_planet, 1 / A->mass);

    // Premier termes
    vec2 times_position = multiplication(&A->pos, 2.0);
    // Première soustraction position - position précédente
    vec2 first_sub = sub(&times_position, &A->prec_pos);
    // Troisième termes
    vec2 mul_accel = multiplication(&A->acceleration, delta_t * delta_t);
    // Addition de la première soustraction avec le troisième terme
    vec2 nextPosition = add(&mul_accel, &first_sub);

    return nextPosition;
}

void update_system(system_t *system, double delta_t)
{

    for (int i = 0; i < system->nb_planets; i++)
    {
        coordinates e = scale_planets_to_screen_coordinate(system->planets[i], DEMI_GRAND_AXE_MARS);
        printf("posx -> %lf,  posy %lf, pixx %d, pixy %d \n", system->planets[i].pos.x, system->planets[i].pos.y, e.column, e.row);

        vec2 updated_pos = planet_position(&(system->planets[i]), delta_t, system);
        system->planets[i].prec_pos = system->planets[i].pos;
        system->planets[i].pos = updated_pos;
    }
}

void free_system(system_t *system)
{
}