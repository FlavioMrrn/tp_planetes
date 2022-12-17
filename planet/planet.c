#include "planet.h"
#include "../vec2/vec2.h"

#include <stdlib.h>

#define G 6.67e-11
#define M_SOLEIL 1.989e30

// TODO : magic

vec2 force_applied_b_on_a(planet_t A, planet_t B, planet_t Star)
{
    vec2 AB = sub(&B.pos, &A.pos);
    double distanceBetweenAAndB = norme(&AB);
    vec2 Fba = multiplication(&AB, G * ((A.mass * B.mass) / pow(distanceBetweenAAndB, 3)));
    return Fba;
}

planet_t create_planet(double mass, vec2 pos, int32_t color, orbite_t orbite, uint32_t size)
{
    planet_t p;
    vec2 prec_pos_ph;
    prec_pos_ph.x = 0;
    prec_pos_ph.y = 0;
    p.mass = mass;
    p.prec_pos = prec_pos_ph;
    p.pos = pos;
    p.color = color;
    p.orbite_planet = orbite;
    p.size = size;
    
    return p;
};

