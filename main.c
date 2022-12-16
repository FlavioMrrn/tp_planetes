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
#define SIZE_SOLEIL 50

#define EXCENTRICITE_MERCURE 0.20563069
#define PERIHELIE_MERCURE 46001009
#define DEMI_GRAND_AXE_MERCURE 57894375.961
#define MASS_MERCURE 3.3011e23
// 2439700 meters
#define SIZE_MERCURE 10



#define EXCENTRICITE_VENUS 0.00677323 
#define PERIHELIE_VENUS 107476170
#define DEMI_GRAND_AXE_VENUS 108159260.52
#define MASS_VENUS 4.8675E24
#define SIZE_VENUS 15


#define EXCENTRICITE_EARTH 0.01671022 
#define PERIHELIE_EARTH 147098291
#define DEMI_GRAND_AXE_EARTH 149597870.7
#define MASS_EARTH 5.97217e24
#define SIE_HEARTH 

#define EXCENTRICITE_MARS 0.09341233 
#define PERIHELIE_MARS 206655215
#define DEMI_GRAND_AXE_MARS 227987154.95
#define MASS_MARS 6.4171e23
#define SIZE_MARS 12


#define EXCENTRICITE_JUPITER 0.04839266
#define PERIHELIE_JUPITER 740679835
#define DEMI_GRAND_AXE_JUPITER 778567158.27
#define MASS_JUPITER 1.8982e27
#define SIZE_JUPITER 30


#define EXCENTRICITE_SATURN 0.05415060
#define PERIHELIE_SATURN 1349823615
#define DEMI_GRAND_AXE_SATURN 1433536555.8
#define MASS_SATURN 5.6834e26
#define SIZE_MERCURE 25


#define EXCENTRICITE_URANUS 0.04716771 
#define PERIHELIE_URANUS 2734998229
#define DEMI_GRAND_AXE_URANUS 2875031718.26
#define MASS_URANUS 8.6810e25
#define SIZE_URANUS 18


#define EXCENTRICITE_NEPTUNE 0.00858587
#define PERIHELIE_NEPTUNE 4459753056
#define DEMI_GRAND_AXE_NEPTUNE 4504391886.78
#define MASS_NEPTUNE 1.02413e26
#define SIZE_URANUS 17


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
     planet_t planetes_systèmes[8];
     vec2 position_earth;
     position_earth.x = PERIHELIE_EARTH;
     position_earth.y = 0;
     planet_t earth = create_planet(MASS_EARTH,position_earth,)
     //planetes_systèmes[0] =

     planet_t sun;
     sun.dist_to_star = 0;
     sun.mass = M_SOLEIL;
     system_t systeme_maison = create_system(sun, 8, , 10);


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
