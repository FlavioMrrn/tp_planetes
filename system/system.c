#include "system.h"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

#define G 6.67e-11
#define M_SOLEIL 1.989e30
//L'unité de la périhélie est le kilomètre
//L'unité de demi grand axe est le kilomètre
//L'unité de l'excentricité est sans unité
// unité astronomique (149.6e6 kilomètres)

#define EXCENTRICITE_MERCURE 0.20563069
#define PERIHELIE_MERCURE 46001009
#define DEMI_GRAND_AXE_MERCURE 57894375.961

#define EXCENTRICITE_VENUS 0.00677323 
#define PERIHELIE_VENUS 107476170
#define DEMI_GRAND_AXE_VENUS 108159260.52

#define EXCENTRICITE_EARTH 0.01671022 
#define PERIHELIE_EARTH 147098291
#define DEMI_GRAND_AXE_EARTH 149597870.7

#define EXCENTRICITE_MARS 0.09341233 
#define PERIHELIE_MARS 206655215
#define DEMI_GRAND_AXE_MARS 227987154.95

#define EXCENTRICITE_JUPITER 0.04839266
#define PERIHELIE_JUPITER 740679835
#define DEMI_GRAND_AXE_JUPITER 778567158.27

#define EXCENTRICITE_SATURN 0.05415060
#define PERIHELIE_SATURN 1349823615
#define DEMI_GRAND_AXE_SATURN 1433536555.8

#define EXCENTRICITE_URANUS 0.04716771 
#define PERIHELIE_URANUS 2734998229
#define DEMI_GRAND_AXE_URANUS 2875031718.26

#define EXCENTRICITE_NEPTUNE 0.00858587
#define PERIHELIE_NEPTUNE 4459753056
#define DEMI_GRAND_AXE_NEPTUNE 4504391886.78

system_t create_system(planet_t star, uint32_t nb_planets,planet_t planetes[] ,double delta_t){
    system_t s;
    s.nb_planets = nb_planets;
    s.planets = planetes;
    s.star = star;
    s.delta_t = delta_t;

    return s;
};

coordinates scale_planets_to_screen_coordinate(planet_t planet, double sma) {
    //110% du demi grand axe (semi major axis) de la planete du plus loin
    double rs = (sma / 100) * 110;
    //divison de la position par rs pour mettre à l'échelle.
    planet.pos = division(&planet.pos, rs);
    return vec2_to_coordinates(planet.pos, SCREEN_WIDTH, SCREEN_HEIGHT);
}


void show_system(struct gfx_context_t *ctxt, system_t *system){

    coordinates coord_s = scale_planets_to_screen_coordinate(system->star, DEMI_GRAND_AXE_MARS);
    draw_full_circle(ctxt,coord_s.column,coord_s.row,system->star.size,system->star.color);

    
    for (int i = 0; i < system->nb_planets; i++)
    {
        coordinates coord_p = scale_planets_to_screen_coordinate(system->planets[i],DEMI_GRAND_AXE_MARS);
        printf("x = %lf, y =  %lf, mass = %lf, i = %d \n",  system->planets[i].pos.x, system->planets[i].pos.y, system->planets[i].mass, i);
        draw_full_circle(ctxt,coord_p.column,coord_p.row,system->planets[i].size,system->planets[i].color);
    }
    
    
}

vec2 force_applied_self(planet_t *A, system_t *s)
{
    vec2 all_force = {0, 0};
    for (int i = 0; i < s->nb_planets; i++)
    {
        if (A != &s->planets[i])
        {
            vec2 force = force_applied_b_on_a(*A, s->planets[i], s->star);
            all_force = add(&all_force, &force);
        }
    }

    return all_force;
}

vec2 initial_planet_position(planet_t A, system_t SysA){
    vec2 r_perp;
    r_perp.x = -A.pos.y;
    r_perp.y = A.pos.x;
    vec2 rp_rpn = multiplication(&r_perp, 1/norme(&r_perp));
    vec2 velocity_at_t_0 = multiplication(&rp_rpn,sqrt(SysA.star.mass * G * (1+    A.orbite_planet.excentricite) / A.orbite_planet.demi_grand_axe * (1-A.orbite_planet.excentricite)));

    return velocity_at_t_0;
}

/// @brief Calcule la position de la planète avec les paramètre données depuis des positions antérieur.
/// @param A // Planète
/// @param delta_t Delta du temps (Prendre un espace assez grand)
/// @param p_sys (Système planétaires)
/// @return 
vec2 planet_position(planet_t A, double delta_t, system_t p_sys){

    //Calcule la force appliqué sur une planète ()
    vec2 force_applied_on_planet = force_applied_self(&A, &p_sys);
    //Calcule l'accélération de la planète soit => accéléraiton = Force/masse 
    A.acceleration = multiplication(&force_applied_on_planet,1/A.mass);

    //Premier termes
    vec2 times_position = multiplication(&A.pos,2.0);
    //Première soustraction position - position précédente
    vec2 first_sub = sub(&times_position, &A.prec_pos);
    //Troisième termes
    vec2 mul_accel = multiplication(&A.acceleration, delta_t * delta_t);
    //Addition de la première soustraction avec le troisième terme
    vec2 nextPosition = add(&mul_accel, &first_sub);

    return nextPosition;
}

void update_system(system_t *system, double delta_t){
    
}

void free_system(system_t *system){

}