#include "planet.h"
#include <stdlib.h>

#define G 6.67e-11
#define M_SOLEIL 1.989e30

// TODO : magic
planet_t create_planet(double mass, vec2 pos){
    planet_t p;
    p.mass = mass;
    p.pos = pos;
};

system_t create_system(planete_t star, uint32_t nb_planets, double delta_t){
    system_t s;
    s.nb_planets = nb_planets;
    s.planets = malloc(nb_planets * sizeof(planet_t));
    s.star = star;
    s.delta_t = delta_t;
};
