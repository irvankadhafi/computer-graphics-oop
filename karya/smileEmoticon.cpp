//
// Created by irvan on 12/1/20.
//

#include "karya.h"
void gambarSmile()
{
    int midX = getmaxx()/2;
    int midY = getmaxy()/2;
    Lingkaran cir(midX,midY,200);
    Lingkaran mataKiri(midX-70,midY-80, 50);
    Lingkaran mataKanan(midX+70,midY-80, 50);
    cir.draw();
    mataKiri.draw();
    mataKanan.draw();



    int x0 = midX, y0= midY, radius = 150;
    float dx = 1, dy = 1;
    float x = radius - 1, y = 0;
    float error = dx - (radius << 1);
    for(;x >= y;)
    {
        putpixel(x0 + y, y0 + x, 2);
        putpixel(x0 - y, y0 + x, 3);
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
        //cout<<"A : "<<x0 - y<<endl;
        //cout<<"B : "<<y0 + x<<endl;
    }
    DDALine(midX, midY - 80, midX, midY + 20, 1, 2, "in", WHITE);
    DDALine(midX - 108, midY + (150 - 44), midX + 105, midY + (150 - 44), 1, 1, "in", GREEN);
}