#include "system.h"

system_t create_system(planet_t star, uint32_t nb_planets, double delta_t){
    system_t s;
    s.nb_planets = nb_planets;
    s.planets = malloc(nb_planets * sizeof(planet_t));
    s.star = star;
    s.delta_t = delta_t;
};

void show_system(struct gfx_context_t *ctxt, system_t *system){

}
void free_system(system_t *system){

}