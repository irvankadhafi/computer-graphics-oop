//
// Created by irvan on 11/23/20.
//

#include "shape.h"
void segiEmpat(float P[][2], int colour)
{
    //Sisi Atas
    DDALine(P[0][0], P[0][1], P[1][0], P[1][1], 1, 1, "in", colour);

    //Sisi Bawah
    DDALine(P[2][0], P[2][1], P[3][0], P[3][1], 1, 1, "in", colour);

    //Sisi Kiri
    DDALine(P[0][0], P[0][1], P[2][0], P[2][1], 1, 1, "in", colour);

    //Sisi Kanan
    DDALine(P[1][0], P[1][1], P[3][0], P[3][1], 1, 1, "in", colour);
}