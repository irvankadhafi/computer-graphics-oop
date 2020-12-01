//
// Created by irvan on 11/23/20.
//

#include "shape.h"

JajarGenjang::JajarGenjang(int x0, int y0, int width, int height){
    setX(x0);
    setY(y0);
    setWidth(width);
    setHeight(height);
    reloadMatrix();
}
void JajarGenjang::reloadMatrix(){
    mat[0][0] = (float)x;                         mat[0][1] = (float)y;
    mat[1][0] = (float)(x+panjang);               mat[1][1] = (float)y;
    mat[2][0] = (float)(x+(tinggi/2));            mat[2][1] = (float)(y+tinggi);
    mat[3][0] = (float)(x+(tinggi/2)+panjang);    mat[3][1] = (float)(y+tinggi);
}
void JajarGenjang::setX(int newX){
    x = newX;
    reloadMatrix();
}
void JajarGenjang::setY(int newY){
    y = newY;
    reloadMatrix();
}
void JajarGenjang::setWidth (int newWidth){
    panjang = newWidth;
    reloadMatrix();
}
void JajarGenjang::setHeight (int newHeight){
    tinggi = newHeight;
    reloadMatrix();
}
void JajarGenjang::setColor (int color){
    warna = color;
}
void JajarGenjang::setRotate(int angle, bool clockwise){
    rotasiGaris(mat,mat[0][0],mat[0][1],rowNum,angle,clockwise);
}
void JajarGenjang::setTranslation(float tx, float ty){
    float T[2] = {tx,ty};
    translasiGaris(mat,rowNum,T);
}
void JajarGenjang::draw (){
    segiEmpat(mat,warna);
}