#include "system.h"

#define G 6.67e-11
#define M_SOLEIL 1.989e30
//L'unité de la périhélie est le kilomètre
//L'unité de demi grand axe est le kilomètre
//L'unité de l'excentricité est sans unité
// unité astronomique (149.6e6 kilomètres)

#define EXCENTRICITE_MERCURE 0.20563069
#define PERIHELIE_MERCURE 46001009
#define DEMI_GRAND_AXE_MERCURE 57894375.961


#define EXCENTRICITE_VENUS 0.00677323 
#define PERIHELIE_VENUS 107476170
#define DEMI_GRAND_AXE_VENUS 108159260.52

#define EXCENTRICITE_EARTH 0.01671022 
#define PERIHELIE_EARTH 147098291
#define DEMI_GRAND_AXE_EARTH 149597870.7

#define EXCENTRICITE_MARS 0.09341233 
#define PERIHELIE_MARS 206655215
#define DEMI_GRAND_AXE_MARS 227987154.95

#define EXCENTRICITE_JUPITER 0.04839266
#define PERIHELIE_JUPITER 740679835
#define DEMI_GRAND_AXE_JUPITER 778567158.27

#define EXCENTRICITE_SATURN 0.05415060
#define PERIHELIE_SATURN 1349823615
#define DEMI_GRAND_AXE_SATURN 1433536555.8

#define EXCENTRICITE_URANUS 0.04716771 
#define PERIHELIE_URANUS 2734998229
#define DEMI_GRAND_AXE_URANUS 2875031718.26

#define EXCENTRICITE_NEPTUNE 0.00858587
#define PERIHELIE_NEPTUNE 4459753056
#define DEMI_GRAND_AXE_NEPTUNE 4504391886.78

system_t create_system(planet_t star, uint32_t nb_planets,planet_t planetes[] ,double delta_t){
    system_t s;
    s.nb_planets = nb_planets;
    s.planets = malloc(nb_planets * sizeof(planet_t));
    s.star = star;
    s.delta_t = delta_t;

    return s;
};

void show_system(struct gfx_context_t *ctxt, system_t *system){
    draw_full_circle(ctxt,200,200,10,COLOR_WHITE);
}

void update_system(system_t *system, double delta_t){
    
}

void free_system(system_t *system){

}