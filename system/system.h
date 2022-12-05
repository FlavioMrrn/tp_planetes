#include "../planet/planet.h"

typedef struct _system
{
    planet_t star;       // ex. The sun
    uint32_t nb_planets; // The number of orbiting planets
    planet_t *planets;   // An array of orbiting planets
    double delta_t;
} system_t;

system_t create_system(planet_t star, uint32_t nb_planets, double delta_t);
void show_system(struct gfx_context_t *ctxt, system_t *system);
void free_system(system_t *system);
