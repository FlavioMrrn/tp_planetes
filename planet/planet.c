#include "planet.h"
#include "../vec2/vec2.h"

#include <stdlib.h>

#define G 6.67e-11
#define M_SOLEIL 1.989e30

// TODO : magic

/// @brief Formule de force de b sur a
/// @param A 
/// @param B 
/// @return 
vec2 force_applied_b_on_a(planet_t A, planet_t B)
{
    //printf("a = %lf, %lf \n", A.pos.x, A.pos.y);
    //printf("b = %lf, %lf \n", B.pos.x, B.pos.y);

    vec2 AB = sub(&B.pos, &A.pos);


    double distanceBetweenAAndB = norme(&AB);
    double masseR = A.mass * B.mass;
    double powNorm = pow(distanceBetweenAAndB, 3);
    vec2 Fba = multiplication(&AB, G * (masseR / powNorm));

    //printf("fba = %lf, %lf \n", Fba.x, Fba.y);


    
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

