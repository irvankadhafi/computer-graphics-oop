//
// Created by irvan on 11/23/20.
//

#ifndef SHAPE_SHAPE_H
#define SHAPE_SHAPE_H
#include "../util/util.h"
#include "../transformation/transformation.h"
#include "../stroke/stroke.h"
void segiEmpat(float P[][2], int colour);
class Persegi{
private:
    int x;
    int y;
    int panjang;
    int lebar;
    int warna = 2;
    float mat[4][2];
    int rowNum = sizeof(mat)/sizeof(mat[0]);
public:
    Persegi(int x0, int y0, int width, int height);
    void reloadMatrix();
    void setX(int newX);
    void setY(int newY);
    void setWidth (int newWidth);
    void setHeight (int newHeight);
    void setColor (int color);
    void setRotate(int angle, bool clockwise);
    void setTranslation(float tx, float ty);
    void draw ();
};

class JajarGenjang{
private:
    int x;
    int y;
    int panjang;
    int tinggi;
    int warna = 2;
    float mat[4][2];
    int rowNum = sizeof(mat)/sizeof(mat[0]);
public:
    JajarGenjang(int x0, int y0, int width, int height);
    void reloadMatrix();
    void setX(int newX);
    void setY(int newY);
    void setWidth (int newWidth);
    void setHeight (int newHeight);
    void setColor (int color);
    void setRotate(int angle, bool clockwise);
    void setTranslation(float tx, float ty);
    void draw ();
};

class TrapesiumSiku{
private:
    int x;
    int y;
    int a;
    int b;
    int height;
    int warna = 2;
    float mat[4][2];
    int rowNum = sizeof(mat)/sizeof(mat[0]);
public:
    TrapesiumSiku(int x0, int y0, int sisi_atas, int sisi_bawah, int tinggi);
    void reloadMatrix();
    void setX(int newX);
    void setY(int newY);
    void setHeight(int newHeight);
    void setSisiAtas (int newA);
    void setSisiBawah (int newB);
    void setColor (int color);
    void setRotate(int angle, bool clockwise);
    void setTranslation(float tx, float ty);
    void draw ();
};

class BelahKetupat{
private:
    int x;
    int y;
    int diagonal1;
    int diagonal2;
    int warna = 2;
    float mat[4][2];
    int rowNum = sizeof(mat)/sizeof(mat[0]);
public:
    BelahKetupat(int x0, int y0, int d1, int d2);
    void reloadMatrix();
    void setX(int newX);
    void setY(int newY);
    void setDiagonal1 (int newDiagonal);
    void setDiagonal2 (int newDiagonal);
    void setColor (int color);
    void setRotate(int angle, bool clockwise);
    void setTranslation(float tx, float ty);
    void draw ();
};

class Lingkaran{
private:
    int xp;
    int yp;
    int radius;
    int tebal = 1;
    int warna[8]={1,2,3,4,5,6,7,8};
    void pixelLingkaran(int x0, int x, int y0, int y);
    int jenis = 1;
public:
    Lingkaran(int x0, int y0, int r);
    void setX(int newX);
    void setY(int newY);
    void setRadius(int newR);
    void setColor (int color);
    void setJenisGaris(int garis);
    void setTebal(int newTebal);
    void setTranslation(float tx, float ty);
    void draw ();
};
class Ellipsee {
private:
    int xp;
    int yp;
    int rx;
    int ry;
    int alpha = 0;
    int warna = 1;
    bool clockwise;

    void drawPlot(int midX, int midY, int x, int y, int angle, bool clockwise);

    void beforeDraw(int xp, int yp, int radius_x, int radius_y);

public:
    Ellipsee(int x, int y, int radius_x, int radius_y);
    Ellipsee();
    void setAll(int x, int y, int radius_x, int radius_y);
    void setXp(int newXp);
    void setYp(int newYp);
    void setRx(int newRx);
    void setRy(int newRy);
    void setAlpha(int newAlpha, bool searah);
    void setColor(int color);
    void setTranslation(float tx, float ty);
    void draw ();
};
#endif //SHAPE_SHAPE_H
