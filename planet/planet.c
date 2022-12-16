#include "planet.h"
#include "../vec2/vec2.h"
#include "../system/system.h"
#include <stdlib.h>

#define G 6.67e-11
#define M_SOLEIL 1.989e30

// TODO : magic

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
}

vec2 force_applied_b_on_a(planet_t A, planet_t B, planet_t Star)
{
    vec2 Rab = Star.pos;
    vec2 AB = sub(&B.pos, &A.pos);
    double distanceBetweenAAndB = norme(&AB);
    vec2 Fba = multiplication(&AB, G * ((A.mass * B.mass) / pow(distanceBetweenAAndB, 3)));
    return Fba;
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

planet_t create_planet(double mass, vec2 pos, double dist_to_star)
{
    planet_t p;
    p.mass = mass;
    p.pos = pos;
    p.dist_to_star = dist_to_star;
    p.vitesse = sqrt();
};
