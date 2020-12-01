//
// Created by irvan on 11/26/20.
//
#include "transformation.h"
float * scaleGaris(float P[][2], float S[2])
{
//    int x_shifted = P[0][1] - P[0][0];
//    int y_shifted = P[1][1] - P[1][0];

    P[0][0] = P[0][0] + (1 * S[0]);
    P[0][1] = P[1][0] + (1 * S[1]);
    return (float *)P;
}
