//
// Created by irvan on 11/23/20.
//

#include "karya.h"

void bungaEmpatKelopak(int xp, int yp, int px, int py){
    Ellipsee ellipse1(xp - px, yp, px, py);
    ellipse1.setColor(RED);
    ellipse1.draw();
    ellipse1.setAll(xp+px,yp,px,py);
    ellipse1.draw();
    ellipse1.setAll(xp,yp-px,py,px);
    ellipse1.draw();
    ellipse1.setAll(xp,yp+px,py,px);
    ellipse1.draw();
}
void bungaDelapanKelopak(int xp, int yp, int px, int py)
{
    float garis[3][2]={
            {(float)xp,         float(yp)},
            {(float)(xp+px),    float(yp)},
            {(float)(xp-px),    float(yp)}
    };
    float tempLines[3][2];
    memcpy(tempLines, garis, sizeof(tempLines));
    rotasiGaris(garis,garis[0][0],garis[0][1],3,45, false);
    rotasiGaris(tempLines,tempLines[0][0],tempLines[0][1],3,45, true);
    bungaEmpatKelopak(xp,yp,px,py);
    Ellipsee ellipse1(garis[1][0], garis[1][1], px, py);
    ellipse1.setColor(RED);
    ellipse1.setAlpha(45, false);
    ellipse1.draw();
    ellipse1.setAll(garis[2][0],garis[2][1],px,py);
    ellipse1.setAlpha(45, false);
    ellipse1.draw();
    ellipse1.setAll(tempLines[1][0],tempLines[1][1],px,py);
    ellipse1.setAlpha(45, true);
    ellipse1.draw();
    ellipse1.setAll(tempLines[2][0],tempLines[2][1],px,py);
    ellipse1.setAlpha(45, true);
    ellipse1.draw();
}