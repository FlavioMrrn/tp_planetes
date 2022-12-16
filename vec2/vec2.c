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
}
vec2 normalisation(vec2 *v1){
    double normev1 = norme(v1);
    vec2 v2 = {v1->x / normev1, v1->y / normev1};
}