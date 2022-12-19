#include "gfx/gfx.h"
#include "vec2/vec2.h"
#include "planet/planet.h"
#include "system/system.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constante pour projet
#define START_Y_POSITION 0
#define START_X_POSITION_SUN 0
#define NB_PLANETS 6
#define SYSTEM_DELTA 10000

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

int main()
{
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
    planet_t earth = create_planet(MASS_EARTH, PERIHELIE_EARTH, START_Y_POSITION, EXCENTRICITE_EARTH, DEMI_GRAND_AXE_EARTH, PERIHELIE_EARTH, COLOR_EARTH, SIZE_EARTH);
    planet_t venus = create_planet(MASS_VENUS, PERIHELIE_VENUS, START_Y_POSITION, EXCENTRICITE_VENUS, DEMI_GRAND_AXE_VENUS, PERIHELIE_VENUS, COLOR_VENUS, SIZE_VENUS);
    planet_t mercure = create_planet(MASS_MERCURE, PERIHELIE_MERCURE, START_Y_POSITION, EXCENTRICITE_MERCURE, DEMI_GRAND_AXE_MERCURE, PERIHELIE_MERCURE, COLOR_MERCURY, SIZE_MERCURE);
    planet_t mars = create_planet(MASS_MARS, PERIHELIE_MARS, START_Y_POSITION, EXCENTRICITE_MARS, DEMI_GRAND_AXE_MARS, PERIHELIE_MARS, COLOR_MARS, SIZE_MARS);
    planet_t thanos = create_planet(MASS_THANOS, PERIHELIE_THANOS, START_Y_POSITION, EXCENTRICITE_THANOS, DEMI_GRAND_AXE_THANOS, PERIHELIE_THANOS, COLOR_THANOS, SIZE_THANOS);
    planet_t bubu = create_planet(MASS_BUBU, PERIHELIE_BUBU, START_Y_POSITION, EXCENTRICITE_BUBU, DEMI_GRAND_AXE_BUBU, PERIHELIE_BUBU, COLOR_BUBU, SIZE_BUBU);
    planet_t planetes_systemes[] = {earth, venus, mercure, mars, thanos, bubu};
    planet_t sun;

    sun = create_planet(M_SOLEIL,START_X_POSITION_SUN, START_Y_POSITION, 0, 0, 0, COLOR_YELLOW, SIZE_SOLEIL);
    system_t systeme_maison = create_system(sun, NB_PLANETS, planetes_systemes, SYSTEM_DELTA);

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
        update_system(&systeme_maison);

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
