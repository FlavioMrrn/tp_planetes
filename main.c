/**
 * Nom : Morrone / Tayan
 * Prénom : Flavio / Jad
 * Date : 19.12.2022
 * Project : Simulation de système solaire
 * File : main.c
 * Brief of file : fichier principal du projet (créations des planètes)
*/
#include "gfx/gfx.h"
#include "vec2/vec2.h"
#include "planet/planet.h"
#include "system/system.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    //Création du soleil et système solaire
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
        //Supprime l'image d'avant
        gfx_clear(ctxt, COLOR_BLACK);
        // Dessine le système
        show_system(ctxt, &systeme_maison);
        // Met a jours le systèmes (bouge les planètes)
        update_system(&systeme_maison);

        if (gfx_keypressed() == SDLK_ESCAPE)
        {
            break;
        }
    }

    // Libère la mémoire
    free_system(&systeme_maison);
    gfx_destroy(ctxt);
    return EXIT_SUCCESS;
}
