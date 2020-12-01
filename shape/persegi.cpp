//
// Created by irvan on 11/23/20.
//

#include "shape.h"

Persegi::Persegi(int x0, int y0, int width, int height){
    setX(x0);
    setY(y0);
    setWidth(width);
    setHeight(height);
    reloadMatrix();
}
void Persegi::reloadMatrix(){
    mat[0][0] = (float)x;            mat[0][1] = (float)y;
    mat[1][0] = (float)(x+panjang);    mat[1][1] = (float)y;
    mat[2][0] = (float)x;            mat[2][1] = (float)(y+lebar);
    mat[3][0] = (float)(x+panjang);    mat[3][1] = (float)(y+lebar);
    setRotate(sudut,searah);
}
void Persegi::setX(int newX){
    x = newX;
    reloadMatrix();
}
void Persegi::setY(int newY){
    y = newY;
    reloadMatrix();
}
void Persegi::setWidth (int newWidth){
    panjang = newWidth;
    reloadMatrix();
}
void Persegi::setHeight (int newHeight){
    lebar = newHeight;
    reloadMatrix();
}
void Persegi::setColor (int color){
    warna = color;
}
void Persegi::setRotate(int angle, bool clockwise){
    sudut = angle;
    searah = clockwise;
    rotasiGaris(mat,mat[0][0],mat[0][1],rowNum,sudut,searah);
}
void Persegi::setTranslation(float tx, float ty){
    float T[2] = {tx,ty};
    translasiGaris(mat,rowNum,T);
}
void Persegi::draw (){
    segiEmpat(mat,warna);
}