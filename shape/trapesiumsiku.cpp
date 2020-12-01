//
// Created by irvan on 11/23/20.
//

#include "shape.h"

//
// Created by irvan on 11/23/20.
//

#include "shape.h"

TrapesiumSiku::TrapesiumSiku(int x0, int y0, int sisi_atas, int sisi_bawah, int tinggi){
    setX(x0);
    setY(y0);
    setSisiAtas(sisi_atas);
    setSisiBawah(sisi_bawah);
    setHeight(tinggi);
    reloadMatrix();
}
void TrapesiumSiku::reloadMatrix(){
    mat[0][0] = (float)x;        mat[0][1] = (float)y;
    mat[1][0] = (float)(x+a);    mat[1][1] = (float)y;
    mat[2][0] = (float)x;        mat[2][1] = (float)(y+height);
    mat[3][0] = (float)(x+b);    mat[3][1] = (float)(y+height);
}
void TrapesiumSiku::setX(int newX){
    x = newX;
    reloadMatrix();
}
void TrapesiumSiku::setY(int newY){
    y = newY;
    reloadMatrix();
}
void TrapesiumSiku::setSisiAtas(int newA){
    a = newA;
    reloadMatrix();
}
void TrapesiumSiku::setSisiBawah(int newB){
    b = newB;
    reloadMatrix();
}
void TrapesiumSiku::setHeight (int newHeight){
    height = newHeight;
    reloadMatrix();
}
void TrapesiumSiku::setColor (int color){
    warna = color;
}
void TrapesiumSiku::setRotate(int angle, bool clockwise){
    rotasiGaris(mat,mat[0][0],mat[0][1],rowNum,angle,clockwise);
}
void TrapesiumSiku::setTranslation(float tx, float ty){
    float T[2] = {tx,ty};
    translasiGaris(mat,rowNum,T);
}
void TrapesiumSiku::draw (){
    segiEmpat(mat,warna);
}