//
// Created by irvan on 11/23/20.
//
#include "shape.h"
Ellipsee::Ellipsee(int x, int y, int radius_x, int radius_y){
    setXp(x);
    setYp(y);
    setRx(radius_x);
    setRy(radius_y);
}
Ellipsee::Ellipsee() {
    xp = getmaxx()/2;
    yp = getmaxy()/2;
    rx = 100;
    ry = 50;
}
void Ellipsee::drawPlot(int midX, int midY, int x, int y, int angle, bool clockwise)
{
    float A[4][2] = {
            {(float) (midX + x), (float) (midY + y)},
            {(float) (midX - x), (float) (midY + y)},
            {(float) (midX + x), (float) (midY - y)},
            {(float) (midX - x), (float) (midY - y)},
    };

    rotasiGaris(A,midX,midY,4,angle,clockwise);

    putpixel( A[0][0], A[0][1],warna);
    putpixel( A[1][0], A[1][1],warna);
    putpixel( A[2][0], A[2][1],warna);
    putpixel( A[3][0], A[3][1],warna);
}
void Ellipsee::setAll(int x, int y, int newRx, int newRy) {
    xp = x;
    yp = y;
    rx = newRx;
    ry = newRy;
}
void Ellipsee::setXp(int newXp) {
    xp = newXp;
}

void Ellipsee::setYp(int newYp) {
    yp = newYp;
}

void Ellipsee::setRx(int newRx) {
    rx = newRx;
}

void Ellipsee::setRy(int newRy) {
    ry = newRy;
}

void Ellipsee::setAlpha(int newAlpha, bool clockwise) {
    sudut = newAlpha;
    searah = clockwise;
}
void Ellipsee::setColor(int color) {
    warna = color;
}

void Ellipsee::setTranslation(float tx, float ty) {
    xp += tx;
    yp += ty;
}

void Ellipsee::draw() {
    float P[][2]={
            {(float)xp, (float)yp}
    };
    rotasiGaris(P,P[0][0],P[0][1],1,sudut,searah);
    beforeDraw(P[0][0],P[0][1],rx,ry);
}

void Ellipsee::beforeDraw(int xc, int yc, int radius_x, int radius_y) {
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = radius_y;

    // Initial decision parameter of region 1
    d1 = (radius_y * radius_y) - (radius_x * radius_x * radius_y) +
         (0.25 * radius_x * radius_x);
    dx = 2 * radius_y * radius_y * x;
    dy = 2 * radius_x * radius_x * y;

    // For region 1
    while (dx < dy)
    {
        drawPlot(xc,yc,x,y,sudut,searah);
        // Checking and updating value of
        // decision parameter based on algorithm
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * radius_y * radius_y);
            d1 = d1 + dx + (radius_y * radius_y);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * radius_y * radius_y);
            dy = dy - (2 * radius_x * radius_x);
            d1 = d1 + dx - dy + (radius_y * radius_y);
        }
    }

    // Decision parameter of region 2
    d2 = ((radius_y * radius_y) * ((x + 0.5) * (x + 0.5))) +
         ((radius_x * radius_x) * ((y - 1) * (y - 1))) -
         (radius_x * radius_x * radius_y * radius_y);

    // Plotting points of region 2
    while (y >= 0)
    {

        drawPlot(xc,yc,x,y,sudut,searah);

        // Checking and updating parameter
        // value based on algorithm
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * radius_x * radius_x);
            d2 = d2 + (radius_x * radius_x) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * radius_y * radius_y);
            dy = dy - (2 * radius_x * radius_x);
            d2 = d2 + dx - dy + (radius_x * radius_x);
        }
    }
}





