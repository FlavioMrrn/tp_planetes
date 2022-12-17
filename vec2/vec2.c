#include "vec2.h"
#include <math.h>

vec2 add(vec2 *v1, vec2 *v2){
    vec2 v3 = {v1->x+ v2->x, v1->y + v2->y};
    return v3;
}

vec2 sub(vec2 *v1, vec2 *v2){
    vec2 v3 = {v1->x - v2->x, v1->y - v2->y};
    return v3;
}

double dot(vec2 *v1, vec2 *v2){
    double r = v1->x * v2->x + v1->y + v2->y;
    //Vérifier la case du tableau
    return r;
}

double norme(vec2 *v1){
    return sqrt((v1->x * v1->x) + (v1->y * v1->y));
}

vec2 multiplication(vec2 *v1, double scalaire){
    vec2 v2 = {v1->x * scalaire, v2.y * scalaire};
    return v2;
}

vec2 division(vec2 *v1, double scalaire){
    vec2 v2 = {v1->x * scalaire, v1->y*scalaire};
    return v2;
}

vec2 normalisation(vec2 *v1){
    double normev1 = norme(v1);
    vec2 v2 = {v1->x / normev1, v1->y / normev1};
}

/// @brief Calcul les coordonnées sur l'écran d'un vecteur donné (x et y [-1;1]).
/// @param v vecteur
/// @param width longueur de l'écran
/// @param height hauteur de l'écran
/// @return 
coordinates vec2_to_coordinates(vec2 v, int width, int height) {
    coordinates coo;
    coo.column = round((width - 1) / 2 + (v.x * (width - 1) / 2));
    coo.row = round((height - 1) / 2 + (v.y * (height - 1) / 2));
    return coo;
}