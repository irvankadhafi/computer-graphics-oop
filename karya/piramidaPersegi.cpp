//
// Created by irvan on 12/1/20.
//

#include "karya.h"
void piramidaPersegi()
{
    int i = 1;
    int x, y, s,batas;
    s = 650;
    x=(getmaxx()/2)-(s/2);
    y=(getmaxy()/2)-(s/2);
    batas = s/10;
    Persegi rec(x,y,s,s);
    while (i<batas+2){
        rec.setColor(random(13));
        rec.setWidth(s);
        rec.setHeight(s);
        rec.setX(x);
        rec.setY(y);
        rec.draw();
        x += 5;
        y += 5;
        s -= 5*2;
        i++;
    }
}