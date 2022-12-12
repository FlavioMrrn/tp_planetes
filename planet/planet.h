#ifndef _PLANET_H_
#define _PLANET_H_

#include "../vec2/vec2.h"
#include "../gfx/gfx.h"

typedef struct _planet
{
    double dist_to_star;
    double mass;
    vec2 pos;      // x(t)
    vec2 prec_pos; // x(t - dt)
} planet_t;

// Those function are not mandatory to implement,
// it's rather a hint of what you should have.
planet_t create_planet(double mass, vec2 pos, double dist_to_star);
vec2 force_applied_self(planet_t *p, system_t system);
void update_system(system_t *system, double delta_t);
vec2 force_applied_b_on_a(planet_t A,planet_t B);
#endif