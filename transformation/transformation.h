//
// Created by irvan on 11/23/20.
//

#ifndef SHAPE_TRANSFORMATION_H
#define SHAPE_TRANSFORMATION_H
#include "../util/util.h"
float * rotasiGaris(float P[][2], int x_pivot, int y_pivot, int baris, int angle, bool clockwise);
float * translasiGaris(float P[][2],int baris, float T[]);
float * scaleGaris(float P[][2], float S[2]);
#endif //SHAPE_TRANSFORMATION_H
