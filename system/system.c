/**
 * Nom : Morrone / Tayan
 * Prénom : Flavio / Jad
 * Date : 19.12.2022
 * Project : Simulation de système solaire
 * File : System.c
 * Brief of file : Partie qui calcule les mouvements ainsi que la création du système
*/

#include "system.h"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000


#define DEMI_GRAND_AXE_MARS 2.27944e11
#define G 6.67e-11
#define M_SOLEIL 1.989e30

/// @brief Fonction qui créer le système solaire
/// @param star L'étoile de notre système solaire
/// @param nb_planets Le nombre de planète dans notre système
/// @param planetes Tableau de planète
/// @param delta_t Delta temps de la simulation
/// @return système solaire
system_t create_system(planet_t star, uint32_t nb_planets, planet_t planetes[], double delta_t)
{
    system_t s;
    s.nb_planets = nb_planets;
    s.planets = planetes;
    s.star = star;
    s.delta_t = delta_t;

    return s;
};

/// @brief Mise à l'échelles des planète pour l'écran
/// @param planet Planète
/// @param sma Demi grand axe
/// @return Coordonnée de la planète
coordinates scale_planets_to_screen_coordinate(planet_t planet, double sma)
{
    // 110% du demi grand axe (semi major axis) de la planete du plus loin
    double rs = (sma / 100) * 130;
    // divison de la position par rs pour mettre à l'échelle.
    planet.pos = division(&planet.pos, rs);
    return vec2_to_coordinates(planet.pos, SCREEN_WIDTH, SCREEN_HEIGHT);
}

/// @brief Fonction qui affiche le système solaire
/// @param ctxt Contexte SDL2
/// @param system Système solaire
void show_system(struct gfx_context_t *ctxt, system_t *system)
{
    // On récupère les coordonnées de notre étoile (le soleil) et on la dessine a part
    coordinates coord_s = scale_planets_to_screen_coordinate(system->star, DEMI_GRAND_AXE_MARS);
    draw_full_circle(ctxt, coord_s.column, coord_s.row, system->star.size, system->star.color);

    // Pour chacun des planète on refait la même opération
    for (uint32_t i = 0; i < system->nb_planets; i++)
    {
        coordinates coord_p = scale_planets_to_screen_coordinate(system->planets[i], DEMI_GRAND_AXE_MARS);
        draw_full_circle(ctxt, coord_p.column, coord_p.row, system->planets[i].size, system->planets[i].color);
    }
}

/// @brief Calcul les forces d'un système sur une planète
/// @param A Planète
/// @param s Système
/// @return Vecteur des forces
vec2 force_applied_self(planet_t *A, system_t *s)
{
    // On calcul la force du soleil séparément car elle n'est pas dans le tableau de planète
    vec2 all_force = create_vec(0,0);
    vec2 force = force_applied_b_on_a(*A, s->star);
    all_force = add(&all_force, &force);
    // Pour chaque planète on calcul
    for (uint32_t i = 0; i < s->nb_planets; i++)
    {
        // On vérifie de ne pas se calculer avec soi-même
        if (A != &s->planets[i])
        {
            force = force_applied_b_on_a(*A, s->planets[i]);
            all_force = add(&all_force, &force);
        }
    }
    return all_force;
}

/// @brief Fonction qui retourne la position initial de la planète
/// @param A Planète
/// @param SysA Système solaire
/// @return Vecteur position
vec2 initial_planet_position(planet_t *A, system_t *SysA)
{
    // Vecteur perpendiculaire
    vec2 r_perp = create_vec(-A->pos.y, A->pos.x);
    vec2 rp_rpn = division(&r_perp, norme(&r_perp));

    // Masse fois gravité
    double GM = SysA->star.mass * G;
    // Calcul Nominateur
    double eP1 = 1 + A->orbite_planet.excentricite;
    // Calcul dénominateur
    double ape1 = A->orbite_planet.demi_grand_axe * (1 - A->orbite_planet.excentricite);
    // Résultat a la racine
    double sqrtdiv = sqrt((GM * eP1) / ape1);
    // Calcul de vp0
    vec2 vp0 = multiplication(&rp_rpn, sqrtdiv);
    // Vp et delta
    vec2 tmp1 = multiplication(&vp0, SysA->delta_t);
    // Planète doit être a la périhélie (addition des termes)
    vec2 tmp2 = add(&(A->pos), &tmp1);

    // Calcul de l'accélération
    vec2 force_self = force_applied_self(A, SysA);
    // Acceleration
    vec2 a = division(&force_self, A->mass);
    // Calcul du terme
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
    // Calcule l'accélération de la planète soit => accélération = Force/masse
    A->acceleration = division(&force_applied_on_planet, A->mass);
    // Premier termes
    vec2 times_position = multiplication(&A->pos, 2.0);
    // Première soustraction position - position précédente
    vec2 first_sub = sub(&times_position, &A->prec_pos);
    // Troisième termes
    vec2 mul_accel = multiplication(&A->acceleration, delta_t * delta_t);
    // Addition de la première soustraction avec le troisième terme
    vec2 nextPosition = add(&mul_accel, &first_sub);
    // On retourne la prochaine position de la planète
    return nextPosition;
}

/// @brief Fonction qui met a jour le système solaire
/// @param system Système solaire
/// @param delta_t Delta de temps (en seconde)
void update_system(system_t *system)
{
    for (uint32_t i = 0; i < system->nb_planets; i++)
    {
        vec2 updated_pos = planet_position(&(system->planets[i]), system->delta_t, system);
        system->planets[i].prec_pos = system->planets[i].pos;
        system->planets[i].pos = updated_pos;
    }
}

/// @brief Pour libérer la mémoire du système, dans notre cas nous n'avons pas d'allocation donc il n'y a pas besoin de faire grand chose
/// @param system Système solaire
void free_system(system_t *system)
{
    //Met les variables à une valeur impossible
    system->delta_t = -1;
    system->nb_planets = -1;
    system->planets = NULL;
}