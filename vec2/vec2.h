/*
addition vec2s
soustraction
produit scalaire
norme
multiplication par scalaire
normalisation
*/

typedef struct vec2_t
{
    double x, y;
} vec2;


vec2 add(vec2 *v1, vec2 *v2);
vec2 sub(vec2 *v1, vec2 *v2);
double dot(vec2 *v1, vec2 *v2);
double norme(vec2 *v1);
vec2 multiplication(vec2 *v1, float *scalaire);
vec2 normalisation(vec2 *v1);