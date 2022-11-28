#include "planet.h"
#include <stdlib.h>

#define G 6.67e-11
#define M_SOLEIL 1.989e30

// TODO : magic
<<<<<<< HEAD

void force_applied_b_on_a(planet_t A,planet_t B, planet_t Star){
    vec2 Rab = Star.pos;
    vec AB = B 
    vec2 Fba = G * ((A.mass * B.mass) / )
}
=======
planet_t create_planet(double mass, vec2 pos, double dist_to_star){
    planet_t p;
    p.mass = mass;
    p.pos = pos;
    d.dist_to_star = dist_to_star;
};

system_t create_system(planete_t star, uint32_t nb_planets, double delta_t){
    system_t s;
    s.nb_planets = nb_planets;
    s.planets = malloc(nb_planets * sizeof(planet_t));
    s.star = star;
    s.delta_t = delta_t;
};
>>>>>>> 8b8078fe730b65e735c6c1e21954d6d025051f9e
