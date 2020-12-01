//
// Created by irvan on 11/23/20.
//

#include "transformation.h"
float * translasiGaris(float P[][2],int baris, float T[])
{
    for (int i = 0; i < baris; ++i) {
        P[i][0] = P[i][0] + T[0];
        P[i][1] = P[i][1] + T[1];
    }
    return (float *)P;
}