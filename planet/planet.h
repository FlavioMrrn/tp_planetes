#ifndef _PLANET_H_
#define _PLANET_H_

#include "../vec2/vec2.h"
#include "../gfx/gfx.h"

typedef struct _orbite
{
    double demi_grand_axe;
    double perihelie;
    double excentricite;
} orbite_t;

typedef struct _planet
{
    double mass;    // Masse de la planète
    vec2 pos;      // x(t)
    vec2 prec_pos; // x(t - dt)
    int color;  // Couleur de la planète
    vec2 acceleration; // Accélération de la planète
    orbite_t orbite_planet; // Son orbite
    uint32_t size; // Rayon de la planète en pixel
} planet_t;

planet_t create_planet(double mass, double posX, double posY, double excentricite, double demi_grand_axe, double perihelie, int32_t color, uint32_t size);
orbite_t create_orbite(double demi_grand_axe, double perihelie, double excentricite);
vec2 force_applied_b_on_a(planet_t A,planet_t B);
#endif