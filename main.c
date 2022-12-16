#include "gfx/gfx.h"
#include "vec2/vec2.h"
#include "planet/planet.h"
#include "system/system.h"
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

#define M_SOLEIL 1.989e30
// 6.95700e8
#define SIZE_SOLEIL 40

#define EXCENTRICITE_MERCURE 0.20563069
#define PERIHELIE_MERCURE 46001009
#define DEMI_GRAND_AXE_MERCURE 57894375.961
#define MASS_MERCURE 3.3011e23
// 2439700 meters
#define SIZE_MERCURE 0

#define EXCENTRICITE_VENUS 0.00677323 
#define PERIHELIE_VENUS 107476170
#define DEMI_GRAND_AXE_VENUS 108159260.52
#define MASS_VENUS 4.8675E24


#define EXCENTRICITE_EARTH 0.01671022 
#define PERIHELIE_EARTH 147098291
#define DEMI_GRAND_AXE_EARTH 149597870.7
#define MASS_EARTH 5.97217e24

#define EXCENTRICITE_MARS 0.09341233 
#define PERIHELIE_MARS 206655215
#define DEMI_GRAND_AXE_MARS 227987154.95
#define MASS_MARS 6.4171e23


#define EXCENTRICITE_JUPITER 0.04839266
#define PERIHELIE_JUPITER 740679835
#define DEMI_GRAND_AXE_JUPITER 778567158.27
#define MASS_JUPITER 1.8982e27


#define EXCENTRICITE_SATURN 0.05415060
#define PERIHELIE_SATURN 1349823615
#define DEMI_GRAND_AXE_SATURN 1433536555.8
#define MASS_SATURN 5.6834e26


#define EXCENTRICITE_URANUS 0.04716771 
#define PERIHELIE_URANUS 2734998229
#define DEMI_GRAND_AXE_URANUS 2875031718.26
#define MASS_URANUS 8.6810e25


#define EXCENTRICITE_NEPTUNE 0.00858587
#define PERIHELIE_NEPTUNE 4459753056
#define DEMI_GRAND_AXE_NEPTUNE 4504391886.78
#define MASS_NEPTUNE 1.02413e26


/*
Etapes simulation systeme planetaire:
    Créer une étoile au centre du domaine(soleil)
    Ajoute le nombre de planetes que l'on veut
    définir les conditions (vitesses ...)
    Afficher
        Afficher systemes
        Calculer forces resultatantes / nouvelles positions
        refresh
        puis recommencer cette étapes
*/

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
     planet_t planetes_systèmes[7];

     vec2 position_earth;
     position_earth.x = PERIHELIE_EARTH;
     position_earth.y = 0;
     orbite_t orbite_terre;
     orbite_terre.demi_grand_axe = DEMI_GRAND_AXE_EARTH;
     orbite_terre.excentricite = EXCENTRICITE_EARTH;
     orbite_terre.perihelie = PERIHELIE_EARTH;
     planet_t earth = create_planet(MASS_EARTH,position_earth, COLOR_BLUE, orbite_terre, 20);
     planetes_systèmes[0] = earth;

     vec2 position_venus;
     position_venus.x = PERIHELIE_VENUS;
     position_venus.y = 0;
     orbite_t orbite_venus;
     orbite_venus.demi_grand_axe = DEMI_GRAND_AXE_VENUS;
     orbite_venus.excentricite = EXCENTRICITE_VENUS;
     orbite_venus.perihelie = PERIHELIE_VENUS;
     planet_t venus = create_planet(MASS_VENUS,position_venus, COLOR_WHITE, orbite_venus, 24);
     planetes_systèmes[1] = venus;

     vec2 position_mercure;
     position_mercure.x = PERIHELIE_MERCURE;
     position_mercure.y = 0;
     orbite_t orbite_mercure;
     orbite_mercure.demi_grand_axe = DEMI_GRAND_AXE_MERCURE;
     orbite_mercure.excentricite = EXCENTRICITE_MERCURE;
     orbite_mercure.perihelie = PERIHELIE_MERCURE;
     planet_t mercure = create_planet(MASS_MERCURE,position_mercure, COLOR_WHITE, orbite_mercure, 32);
     planetes_systèmes[2] = mercure;

     vec2 position_mars;
     position_mars.x = PERIHELIE_MARS;
     position_mars.y = 0;
     orbite_t orbite_mars;
     orbite_mars.demi_grand_axe = DEMI_GRAND_AXE_MARS;
     orbite_mars.excentricite = EXCENTRICITE_MARS;
     orbite_mars.perihelie = PERIHELIE_MARS;
     planet_t mars = create_planet(MASS_MARS,position_mars, COLOR_WHITE, orbite_mars, 27);
     planetes_systèmes[3] = mars;

     planet_t sun;
     sun.mass = M_SOLEIL;
     sun.color = COLOR_YELLOW;
     sun.size = 40;
     vec2 position_soleil;
     position_soleil.x = 0;
     position_soleil.y = 0;
     sun.pos = position_soleil; 

     system_t systeme_maison = create_system(sun, 4,planetes_systèmes,4000);


    while (true)
    {
        gfx_present(ctxt);
        // TODO : draw the current state of your system
        show_system(ctxt, &systeme_maison);
        // TODO : update your system
        
        //gfx_clear(ctxt, COLOR_BLACK);
        if (gfx_keypressed() == SDLK_ESCAPE)
        {
            break;
        }
    }

    // TODO : Free your system
    gfx_destroy(ctxt);
    return EXIT_SUCCESS;
}
