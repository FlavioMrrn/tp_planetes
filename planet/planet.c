#include "planet.h"
#include "../vec2/vec2.h"

#include <stdlib.h>

#define G 6.67e-11
#define M_SOLEIL 1.989e30

/// @brief Formule de force d'une planète b sur une planète a
/// @param A Planète
/// @param B Planète
/// @return Force de B sur A
vec2 force_applied_b_on_a(planet_t A, planet_t B)
{

    vec2 AB = sub(&B.pos, &A.pos);
    double distanceBetweenAAndB = norme(&AB);
    double masseR = A.mass * B.mass;
    double powNorm = pow(distanceBetweenAAndB, 3);
    vec2 Fba = multiplication(&AB, G * (masseR / powNorm));

    return Fba;
}

/// @brief Créer la structure de l'orbite
/// @param demi_grand_axe 
/// @param perihelie 
/// @param excentricite 
/// @return orbite
orbite_t create_orbite(double demi_grand_axe, double perihelie, double excentricite){
    orbite_t o1 = {
        .demi_grand_axe = demi_grand_axe,
        .excentricite = excentricite,
        .perihelie = perihelie
    };

    return o1;
}

/// @brief Fonction qui créer une planète en se basant sur le struct planète
/// @param mass masse de a planète
/// @param pos Vecteur de position
/// @param color Couleur de la planète
/// @param orbite Orbite de la planète
/// @param size Taille de la planète
/// @return une variable planète
planet_t create_planet(double mass, double posX, double posY, double excentricite, double demi_grand_axe, double perihelie, int32_t color, uint32_t size)
{
    //Initialize orbite and position before
    orbite_t o_p = create_orbite(demi_grand_axe,perihelie,excentricite);
    vec2 p_p = create_vec(posX, posY);
    planet_t p;
    p.mass = mass;
    p.prec_pos = p_p;
    p.pos = p_p;
    p.color = color;
    p.orbite_planet = o_p;
    p.size = size;

    return p;
};
