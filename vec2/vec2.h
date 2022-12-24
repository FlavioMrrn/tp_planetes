/**
 * Nom : Morrone / Tayan
 * Prénom : Flavio / Jad
 * Date : 24.12.2022
 * Project : Simulation de système solaire
 * File : vec2.h
 * Brief of file : Header qui indique les fonctionnalités et opérations de la structure liés au vecteurs
*/
#ifndef _VEC_2_
#define _VEC_2_

/*addition vec2s
soustraction
produit scalaire
norme
multiplication par scalaire
normalisation
*/

typedef struct coordinate_t
{
    int row, column;
} coordinates;

typedef struct vec2_t
{
    double x, y;
} vec2;

vec2 create_vec(double x, double y);
vec2 add(vec2 *v1, vec2 *v2);
vec2 sub(vec2 *v1, vec2 *v2);
double dot(vec2 *v1, vec2 *v2);
double norme(vec2 *v1);
vec2 multiplication(vec2 *v1, double scalaire);
vec2 normalisation(vec2 *v1);
vec2 division(vec2 *v1, double scalaire);
coordinates vec2_to_coordinates(vec2 v, int width, int height);

#endif