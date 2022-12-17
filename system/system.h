#ifndef _SYSTEMP_
#define _SYSTEMP_

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

#define M_SOLEIL 1.989e30
// 6.95700e8
#define SIZE_SOLEIL 50

#define EXCENTRICITE_MERCURE 0.20563069
#define PERIHELIE_MERCURE 4.60012e10
#define DEMI_GRAND_AXE_MERCURE 5.790905e10  
#define MASS_MERCURE 3.3011e23
// 2439700 meters
#define SIZE_MERCURE 10

#define EXCENTRICITE_VENUS 0.00677323 
#define PERIHELIE_VENUS 1.0747617e11
#define DEMI_GRAND_AXE_VENUS 1.082095e11
#define MASS_VENUS 4.8675E24
#define SIZE_VENUS 15


#define EXCENTRICITE_EARTH 0.01671022 
#define PERIHELIE_EARTH 1.47098291e11
#define DEMI_GRAND_AXE_EARTH 1.495978875e11
#define MASS_EARTH 5.97217e24
#define SIZE_EARTH 

#define EXCENTRICITE_MARS 0.09341233 
#define PERIHELIE_MARS 2.06655215e11
#define DEMI_GRAND_AXE_MARS 2.27944e11
#define MASS_MARS 6.4171e23
#define SIZE_MARS 12

#include "../planet/planet.h"
#include "../vec2/vec2.h"

typedef struct _system
{
    planet_t star;       // ex. The sun
    uint32_t nb_planets; // The number of orbiting planets
    planet_t *planets;   // An array of orbiting planets
    double delta_t;
} system_t;

system_t create_system(planet_t star, uint32_t nb_planets, planet_t planetes[], double delta_t);
void show_system(struct gfx_context_t *ctxt, system_t *system);
vec2 force_applied_self(planet_t *A, system_t *system);
void show_system(struct gfx_context_t *ctxt, system_t *system);
void update_system(system_t *system, double delta_t);
void free_system(system_t *system);
coordinates scale_planets_to_screen_coordinate(planet_t planet, double sma);
vec2 force_applied_self(planet_t *A, system_t *s);
vec2 initial_planet_position(planet_t *A, system_t *SysA);
vec2 planet_position(planet_t *A, double delta_t, system_t *p_sys);

#endif