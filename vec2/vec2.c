#include "vec2.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/// Create a 2d vector.
/// @param x_ The first component.
/// @param y_ The second component.
/// @return The newly created vector.
vec2 vec2_create(double x_, double y_) {
    vec2 vec = {x_, y_};
    return vec;
}

/// Create a zero 2d vector.
/// @return The newly created zero vector.
vec2 vec2_create_zero() {
    return vec2_create(0.0, 0.0);
}

/// Add two vectors.
/// @param lhs The left operand.
/// @param rhs The right operand.
/// @return The sum in a new vector.
vec2 vec2_add(vec2 lhs, vec2 rhs) {
    vec2 v3 = {lhs.x + rhs.x,lhs.y + rhs.y};
    return v3;
}

/// Substract two vectors.
/// @param lhs The left operand.
/// @param rhs The right operand.
/// @return The difference in a new vector.
vec2 vec2_sub(vec2 lhs, vec2 rhs) {
    vec2 v3 = {lhs.x - rhs.x,lhs.y - rhs.y};
    return v3;
}

/// Multiply a vector by a scalar.
/// @param scalar The left operand, a scalar.
/// @param rhs The right operand, a vector.
/// @return The product in a new vector.
vec2 vec2_mul(double scalar, vec2 rhs) {
    vec2 v2 = {rhs.x * scalar, rhs.y * scalar};
    return v2;
}

/// Compute the dot product (scalar product) between two vectors.
/// @param lhs The left operand.
/// @param rhs The right operand.
/// @return The dot product.
double vec2_dot(vec2 lhs, vec2 rhs) {
    double r = lhs.x * rhs.x + lhs.y + rhs.y;
    //Vérifier la case du tableau
    return r;
}

/// Compute the square of the euclidean norm of a given vector.
/// @param v The vector.
/// @return The square of the norm.
double vec2_norm_sqr(vec2 v) {
    double norm = vec2_norm(v);
    return norm * norm;
}

/// Compute the euclidean norm of a given vector.
/// @param v The vector.
/// @return The norm.
double vec2_norm(vec2 v) {
    return sqrt((v.x * v.x) + (v.y * v.y));
}

/// Compute the normalization of a given vector.
/// @param v The vector.
/// @return The new normalized vector.
vec2 vec2_normalize(vec2 v) {
    double normev1 = vec2_norm(v);
    vec2 v2 = {v.x / normev1, v.y / normev1};
    return v2;
}

/// Check whether two vectors are approximately equals within a given tolerance.
/// @param lhs The left operand.
/// @param rhs The right operand.
/// @param eps The tolerance.
/// @return true if vector are approximately equal, false otherwise.
bool vec2_is_approx_equal(vec2 lhs, vec2 rhs, double eps) {
    if (abs(lhs.x - rhs.x) < eps && abs(lhs.y - rhs.y) < eps)
    {
        return true;
    }
    return false;
}

/// Compute the coordinates of a 2d vector (with components between 0 and 1)
/// in a given screen matrix.
/// @param v The 2d vector.
/// @param width The screen width.
/// @param height The screen height.
/// @return The coordinates (rwo, column).
coordinates vec2_to_coordinates(vec2 v, uint32_t width, uint32_t height) {
    
}

/// Print a vector in the standard output.
/// @param v The vector.
void vec2_print(vec2 v) {
    printf("x = %g, y = %g\n", v.x, v.y);
}
