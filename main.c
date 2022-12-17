#include "gfx/gfx.h"
#include "vec2/vec2.h"
#include "planet/planet.h"
#include "system/system.h"
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>

//Constante pour projet

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000
#define MAGENTA 0xFF0099
#define CYAN 0x00FFFF

#define M_SOLEIL 1.989e30
#define SIZE_SOLEIL 50

#define EXCENTRICITE_MERCURE 0.20563069
#define PERIHELIE_MERCURE 4.60012e10
#define DEMI_GRAND_AXE_MERCURE 5.790905e10  
#define MASS_MERCURE 3.3011e23
#define SIZE_MERCURE 10

#define EXCENTRICITE_VENUS 0.00677323 
#define PERIHELIE_VENUS 1.0747617e11
#define DEMI_GRAND_AXE_VENUS 1.082095e11
#define MASS_VENUS 4.8675e24
#define SIZE_VENUS 15


#define EXCENTRICITE_EARTH 0.01671022 
#define PERIHELIE_EARTH 1.47098291e11
#define DEMI_GRAND_AXE_EARTH 1.495978875e11
#define MASS_EARTH 5.97217e24
#define SIZE_EARTH 16

#define EXCENTRICITE_MARS 0.09341233 
#define PERIHELIE_MARS 2.06655215e11
#define DEMI_GRAND_AXE_MARS 2.27944e11
#define MASS_MARS 6.4171e23
#define SIZE_MARS 12

#define EXCENTRICITE_THANOS 0.1441233 
#define PERIHELIE_THANOS 1.06655215e11
#define DEMI_GRAND_AXE_THANOS 1.27944e11
#define MASS_THANOS 1.4171e24
#define SIZE_THANOS 6

#define EXCENTRICITE_BUBU 0.00000003 
#define PERIHELIE_BUBU 2.26655215e11
#define DEMI_GRAND_AXE_BUBU 3.07944e11
#define MASS_BUBU 2.4171e24
#define SIZE_BUBU 15


int main() {
    srand(time(NULL));
    struct gfx_context_t *ctxt =
        gfx_create("Planetary system", SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!ctxt)
    {
        fprintf(stderr, "Graphics initialization failed!\n");
        return EXIT_FAILURE;
    }

    // TODO : create your system
    // Ajout des planètes aux systèmes solaires
    // A chaque planète : initialisation des structures nécessaire a la structure
     planet_t planetes_systemes[6];
    
     vec2 position_earth;
     position_earth.x = PERIHELIE_EARTH;
     position_earth.y = 0.0;
     orbite_t orbite_terre;
     orbite_terre.demi_grand_axe = DEMI_GRAND_AXE_EARTH;
     orbite_terre.excentricite = EXCENTRICITE_EARTH;
     orbite_terre.perihelie = PERIHELIE_EARTH;
     planet_t earth = create_planet(MASS_EARTH,position_earth, COLOR_BLUE, orbite_terre, 20);
     planetes_systemes[0] = earth;
     

     vec2 position_venus;
     position_venus.x = PERIHELIE_VENUS;
     position_venus.y = 0.0;
     orbite_t orbite_venus;
     orbite_venus.demi_grand_axe = DEMI_GRAND_AXE_VENUS;
     orbite_venus.excentricite = EXCENTRICITE_VENUS;
     orbite_venus.perihelie = PERIHELIE_VENUS;
     planet_t venus = create_planet(MASS_VENUS,position_venus, COLOR_GREEN, orbite_venus, SIZE_VENUS);
     planetes_systemes[1] = venus;

     vec2 position_mercure;
     position_mercure.x = PERIHELIE_MERCURE;
     position_mercure.y = 0.0;
     orbite_t orbite_mercure;
     orbite_mercure.demi_grand_axe = DEMI_GRAND_AXE_MERCURE;
     orbite_mercure.excentricite = EXCENTRICITE_MERCURE;
     orbite_mercure.perihelie = PERIHELIE_MERCURE;
     planet_t mercure = create_planet(MASS_MERCURE,position_mercure, COLOR_RED, orbite_mercure, SIZE_MERCURE);
     
     planetes_systemes[2] = mercure;

     vec2 position_mars;
     position_mars.x = PERIHELIE_MARS;
     position_mars.y = 0.0;
     orbite_t orbite_mars;
     orbite_mars.demi_grand_axe = DEMI_GRAND_AXE_MARS;
     orbite_mars.excentricite = EXCENTRICITE_MARS;
     orbite_mars.perihelie = PERIHELIE_MARS;
     planet_t mars = create_planet(MASS_MARS,position_mars, COLOR_WHITE, orbite_mars, SIZE_MARS);
     planetes_systemes[3] = mars;
    
     vec2 position_thanos;
     position_thanos.x = PERIHELIE_THANOS;
     position_thanos.y = 0.0;
     orbite_t orbite_thanos;
     orbite_thanos.demi_grand_axe = DEMI_GRAND_AXE_THANOS;
     orbite_thanos.excentricite = EXCENTRICITE_THANOS;
     orbite_thanos.perihelie = PERIHELIE_THANOS;
     planet_t thanos = create_planet(MASS_THANOS,position_thanos, MAGENTA, orbite_thanos, SIZE_THANOS);
     planetes_systemes[4] = thanos;

     vec2 position_bubu;
     position_bubu.x = PERIHELIE_BUBU;
     position_bubu.y = 0.0;
     orbite_t orbite_bubu;
     orbite_bubu.demi_grand_axe = DEMI_GRAND_AXE_BUBU;
     orbite_bubu.excentricite = EXCENTRICITE_BUBU;
     orbite_bubu.perihelie = PERIHELIE_BUBU;
     planet_t bubu = create_planet(MASS_BUBU,position_bubu, CYAN, orbite_bubu, SIZE_BUBU);
     planetes_systemes[5] = bubu;
    
     planet_t sun;
     sun.mass = M_SOLEIL;
     sun.color = COLOR_YELLOW;
     sun.size = SIZE_SOLEIL;
     vec2 position_soleil;
     position_soleil.x = 0;
     position_soleil.y = 0;
     sun.pos = position_soleil; 

     system_t systeme_maison = create_system(sun, 6,planetes_systemes,10000);

    // Calcul vitesse de position initial de toute les planètes
    for (uint32_t i = 0; i < systeme_maison.nb_planets; i++)
    {
        systeme_maison.planets[i].pos = initial_planet_position(&(systeme_maison.planets[i]), &systeme_maison);
    }
    while (true)
    {
        
        gfx_present(ctxt);
        gfx_clear(ctxt, COLOR_BLACK);
        // TODO : draw the current state of your system
        show_system(ctxt, &systeme_maison);
        // TODO : update your system
        update_system(&systeme_maison,10000);
        
        if (gfx_keypressed() == SDLK_ESCAPE)
        {
            break;
        }
    }

    // TODO : Free your system
    free_system(&systeme_maison);
    gfx_destroy(ctxt);
    return EXIT_SUCCESS;
}
