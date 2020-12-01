//
// Created by irvan on 11/23/20.
//

#include "shape.h"

BelahKetupat::BelahKetupat(int x0, int y0, int d1, int d2){
    setX(x0);
    setY(y0);
    setDiagonal1(d1);
    setDiagonal2(d2);
    reloadMatrix();
}
void BelahKetupat::reloadMatrix(){
    mat[0][0] = (float)x;                       mat[0][1] = (float)y;
    mat[1][0] = (float)(x+diagonal1);           mat[1][1] = (float)(y-diagonal2);
    mat[2][0] = (float)(x+diagonal1);             mat[2][1] = (float)(y+diagonal2);
    mat[3][0] = (float)(x+diagonal1+diagonal1); mat[3][1] = (float)y;
    setRotate(sudut,searah);
}
void BelahKetupat::setX(int newX){
    x = newX;
    reloadMatrix();
}
void BelahKetupat::setY(int newY){
    y = newY;
    reloadMatrix();
}
void BelahKetupat::setDiagonal1 (int newDiagonal){
    diagonal1 = newDiagonal;
    reloadMatrix();
}
void BelahKetupat::setDiagonal2 (int newDiagonal){
    diagonal2 = newDiagonal;
    reloadMatrix();
}
void BelahKetupat::setColor (int color){
    warna = color;
}
void BelahKetupat::setRotate(int angle, bool clockwise){
    sudut = angle;
    searah = clockwise;
    rotasiGaris(mat,mat[0][0],mat[0][1],rowNum,sudut,searah);
}
void BelahKetupat::setTranslation(float tx, float ty){
    float T[2] = {tx,ty};
    translasiGaris(mat,rowNum,T);
}
void BelahKetupat::draw (){
    segiEmpat(mat,warna);
}