#ifndef _SYSTEMP_
#define _SYSTEMP_


#include "../planet/planet.h"
#include "../vec2/vec2.h"

typedef struct _system
{
    planet_t star;       // ex. The sun
    uint32_t nb_planets; // The number of orbiting planets
    planet_t *planets;   // An array of orbiting planets
    double delta_t; // Delta temps
} system_t;

system_t create_system(planet_t star, uint32_t nb_planets, planet_t planetes[], double delta_t);
void show_system(struct gfx_context_t *ctxt, system_t *system);
vec2 force_applied_self(planet_t *A, system_t *system);
void show_system(struct gfx_context_t *ctxt, system_t *system);
void update_system(system_t *system);
void free_system(system_t *system);
coordinates scale_planets_to_screen_coordinate(planet_t planet, double sma);
vec2 force_applied_self(planet_t *A, system_t *s);
vec2 initial_planet_position(planet_t *A, system_t *SysA);
vec2 planet_position(planet_t *A, double delta_t, system_t *p_sys);

#endif