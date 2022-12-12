#include "planet.h"
#include "../system/system.h"
#include <stdlib.h>

#define G 6.67e-11
#define M_SOLEIL 1.989e30

// TODO : magic

vec2 force_applied_self(planet_t *p, system_t s){
    vec2 force_res = {0,0};
    for (int i = 0; i < s.nb_planets; i++)
    {
        vec2 forcei = force_applied_b_on_a(*p, s.planets[i]);
        force_res = add(&force_res, &forcei);
    }
    return force_res;
}


vec2 force_applied_b_on_a(planet_t A,planet_t B){
    vec2 AB = sub(&B.pos, &A.pos);
    double distanceBetweenAAndB = norme(&AB);
    vec2 Fba = multiplication(&AB, G * ((A.mass * B.mass) / pow(distanceBetweenAAndB, 3)));
    return Fba;
}
planet_t create_planet(double mass, vec2 pos, double dist_to_star){
    planet_t p;
    p.mass = mass;
    p.pos = pos;
    p.dist_to_star = dist_to_star;
};
