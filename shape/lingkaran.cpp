//
// Created by irvan on 11/23/20.
//
#include "shape.h"
Lingkaran::Lingkaran(int x, int y, int r) {
    setX(x);
    setY(y);
    setRadius(r);
}
void Lingkaran::pixelLingkaran(int x0, int x, int y0, int y)
{
    putpixel(x0 + x, y0 + y, warna[0]);
    putpixel(x0 + y, y0 + x, warna[1]);
    putpixel(x0 - y, y0 + x, warna[2]);
    putpixel(x0 - x, y0 + y, warna[3]);
    putpixel(x0 - x, y0 - y, warna[4]);
    putpixel(x0 - y, y0 - x, warna[5]);
    putpixel(x0 + y, y0 - x, warna[6]);
    putpixel(x0 + x, y0 - y, warna[7]);
}

void Lingkaran::setX(int newX) {
    xp = newX;
}

void Lingkaran::setY(int newY) {
    yp = newY;
}

void Lingkaran::setRadius(int newR) {
    radius = newR;
}
void Lingkaran::setJenisGaris(int garis) {
    jenis = garis;
}

void Lingkaran::setTranslation(float tx, float ty) {
    xp += tx;
    yp += ty;
}

void Lingkaran::draw() {
    float dx = 1, dy = 1;
    float x = radius - 1, y = 0;
    float error = dx - (radius << 1);
    for(int i=0;(x >= y);i++)
    {
        switch (jenis) {
            case 1: //Solid
                pixelLingkaran(xp,x,yp,y);
                break;
            case 2: // Dash
                if(i%9<6){
                    pixelLingkaran(xp,x,yp,y);
                }
                break;
            case 3: //dotted
                if(i%9<0.5){
                    pixelLingkaran(xp,x,yp,y);
                }
                break;
            case 4: //Dashed Dotted
                if(i%9<2){

                }
                else if(i%9<6){
                    pixelLingkaran(xp,x,yp,y);
                }
                else if(i%9==7){

                }
                else{
                    pixelLingkaran(xp,x,yp,y);
                }
        }
        if(error > 0)
        {
            x = x - 1;
            dx = dx + 2;
            error = error + (-radius << 1) + dx;
        }
        if(error <= 0)
        {
            y = y + 1;
            error = error + dy;
            dy = dy + 2;
        }
    }
}

void Lingkaran::setColor(int color) {
    for (int i = 0; i < 8; ++i) {
        warna[i]=color;
    }
}
