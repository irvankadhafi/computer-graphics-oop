//
// Created by irvan on 11/23/20.
//

#ifndef SHAPE_STROKE_H
#define SHAPE_STROKE_H
#include "../util/util.h"
void plotLine(int x, int y , int tebal, float x1, float y1, float x2, float y2, string mode, int col);
void DDALine(float x1, float y1, float x2, float y2, int jenis = 1, int tebal = 1, string mode = "in", int col = 1);
void drawPattern ( int x, int y, int k, int type, int color);
void BLine(int x1, int y1, int x2, int y2, int col=1);

#endif //SHAPE_STROKE_H
