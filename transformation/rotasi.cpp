//
// Created by irvan on 11/23/20.
//

#include "transformation.h"
float * rotasiGaris(float P[][2], int x_pivot, int y_pivot, int baris, int angle, bool clockwise)
{
    int i = 0;
//    int x_pivot,y_pivot;
//    x_pivot = P[0][0];
//    y_pivot = P[0][1];
    while (i < baris)
    {
        // Shifting the pivot point to the origin
        // and the given points accordingly
        int x_shifted = P[i][0] - x_pivot;
        int y_shifted = P[i][1] - y_pivot;

        // Calculating the rotated point co-ordinates
        // and shifting it back
        if(clockwise){
            //Clockwise
            P[i][0] = x_pivot + (x_shifted*COS(angle) - y_shifted*SIN(angle));
            P[i][1] = y_pivot + (x_shifted*SIN(angle) + y_shifted*COS(angle));
        } else{
            //Anti Clockwise
            P[i][0] = x_pivot + (x_shifted*COS(angle) + y_shifted*SIN(angle));
            P[i][1] = y_pivot + (y_shifted*COS(angle) - x_shifted*SIN(angle));
        }
        i++;
    }
    return (float *)P;
}