#ifndef _SYSTEMP_
#define _SYSTEMP_


#include "../planet/planet.h"
#include "../vec2/vec2.h"

// Constante pour projet
#define START_Y_POSITION 0
#define START_X_POSITION_SUN 0
#define NB_PLANETS 6
#define SYSTEM_DELTA 10000

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000
#define MAGENTA 0xFF0099
#define CYAN 0x00FFFF

#define G 6.67e-11
#define M_SOLEIL 1.989e30
#define SIZE_SOLEIL 50

#define EXCENTRICITE_MERCURE 0.20563069
#define PERIHELIE_MERCURE 4.60012e10
#define DEMI_GRAND_AXE_MERCURE 5.790905e10
#define MASS_MERCURE 3.3011e23
#define SIZE_MERCURE 10
#define COLOR_MERCURY 0x808080

#define EXCENTRICITE_VENUS 0.00677323
#define PERIHELIE_VENUS 1.0747617e11
#define DEMI_GRAND_AXE_VENUS 1.082095e11
#define MASS_VENUS 4.8675e24
#define SIZE_VENUS 15
#define COLOR_VENUS 0xFFFFA7

#define EXCENTRICITE_EARTH 0.01671022
#define PERIHELIE_EARTH 1.47098291e11
#define DEMI_GRAND_AXE_EARTH 1.495978875e11
#define MASS_EARTH 5.97217e24
#define SIZE_EARTH 16
#define COLOR_EARTH COLOR_BLUE

#define EXCENTRICITE_MARS 0.09341233
#define PERIHELIE_MARS 2.06655215e11
#define DEMI_GRAND_AXE_MARS 2.27944e11
#define MASS_MARS 6.4171e23
#define SIZE_MARS 12
#define COLOR_MARS COLOR_RED

#define EXCENTRICITE_THANOS 0.1441233
#define PERIHELIE_THANOS 1.06655215e11
#define DEMI_GRAND_AXE_THANOS 1.27944e11
#define MASS_THANOS 1.4171e24
#define SIZE_THANOS 6
#define COLOR_THANOS MAGENTA

#define EXCENTRICITE_BUBU 0.00000003
#define PERIHELIE_BUBU 2.26655215e11
#define DEMI_GRAND_AXE_BUBU 3.07944e11
#define MASS_BUBU 2.4171e24
#define SIZE_BUBU 15
#define COLOR_BUBU COLOR_WHITE


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