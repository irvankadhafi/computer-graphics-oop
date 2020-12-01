//
// Created by irvan on 12/1/20.
//

#include "shape.h"
Segitiga::Segitiga(int x0, int y0, int a, int t) {
    setX(x0);
    setY(y0);
    setAlas(a);
    setTinggi(t);
    reloadMatrix();
}

void Segitiga::reloadMatrix() {
    mat[0][0] = (float)x;           mat[0][1] = (float)y;
    mat[1][0] = (float)x;           mat[1][1] = (float)(y+tinggi);
    mat[2][0] = (float)(x+alas);    mat[2][1] = (float)(y+tinggi);
    setRotate(sudut,searah);
}

void Segitiga::setAlas(int newAlas) {
    alas = newAlas;
    reloadMatrix();
}

void Segitiga::setTinggi(int newTinggi) {
    tinggi = newTinggi;
    reloadMatrix();
}

void Segitiga::setX(int newX) {
    x=newX;
    reloadMatrix();
}

void Segitiga::setY(int newY) {
    y=newY;
    reloadMatrix();
}

void Segitiga::setColor(int color) {
    warna = color;
}

void Segitiga::setRotate(int angle, bool clockwise) {
    sudut = angle;
    searah = clockwise;
    if (!siku){
        rowNum = 2;
    }
    rotasiGaris(mat,mat[0][0],mat[0][1],rowNum,sudut,searah);
}

void Segitiga::setTranslation(float tx, float ty) {
    float T[2] = {tx,ty};
    translasiGaris(mat,rowNum,T);
}

void Segitiga::draw() {
    if (!siku){
        float tempLines[2][2];
        memcpy(tempLines, mat, sizeof(tempLines));
        DDALine(mat[0][0], mat[0][1], mat[1][0], mat[1][1], 1, 1, "in", warna);
        rotasiGaris(tempLines,tempLines[0][0],tempLines[0][1],2,60,true);
        DDALine(tempLines[0][0], tempLines[0][1], tempLines[1][0], tempLines[1][1], 1, 1, "in", warna);
        DDALine(tempLines[1][0], tempLines[1][1], mat[1][0], mat[1][1], 1, 1, "in", warna);
    }else{
        //tinggi
        DDALine(mat[0][0], mat[0][1], mat[1][0], mat[1][1], 1, 1, "in", warna);
        //alas
        DDALine(mat[1][0], mat[1][1], mat[2][0], mat[2][1], 1, 1, "in", warna);
        //garis miring
        DDALine(mat[0][0], mat[0][1], mat[2][0], mat[2][1], 1, 1, "in", warna);
    }
}

void Segitiga::setSiku(bool segitigaSiku) {
    siku = segitigaSiku;
}
