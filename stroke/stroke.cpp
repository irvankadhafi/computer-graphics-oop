//
// Created by irvan on 11/23/20.
//

#include "stroke.h"
void plotLine(int x, int y , int tebal, float x1, float y1, float x2, float y2, string mode, int col)
{
    if (tebal>1){
        for (float j = 0; j < tebal; j+=0.1) {
            if(x1 == x2){
                if(mode=="in")
                    putpixel(x+j,y,col); //INSIDE
                else
                    putpixel(x-j,y,col); //OUTSIDE
            }
            else if(y1 == y2){
                if(mode=="in")
                    putpixel(x,y+j,col); //INSIDE
                else
                    putpixel(x,y-j,col); //OUTSIDE
            }
            else{
                if(mode=="in")
                {
//                    putpixel(x-j,y-j,col); //INSIDE
                    putpixel(x-j,y+j,col); //INSIDE
                }
                else
                    putpixel(x-j,y+j,col); //OUTSIDE
            }

        }
    }
    else{
        putpixel(x,y,col);
    }
}
void DDALine(float x1, float y1, float x2, float y2, int jenis, int tebal, string mode, int col)
{

    float dx,dy,len,x,y;
    int i;

    dx = abs(x2-x1);
    dy = abs(y2-y1);

    if(dx>=dy)
        len=dx;
    else
        len=dy;

    dx = (x2-x1)/len;
    dy = (y2-y1)/len;

    x = x1 + 0.1;
    y = y1 + 0.1;
    for(i=0;i<=len;i++)
    {
        switch (jenis) {
            case 1: //Solid
                plotLine(x, y, tebal, x1, y1, x2, y2, mode, col);
                break;
            case 2: // Dash
                if(i%9<6){
                    plotLine(x, y, tebal, x1, y1, x2, y2, mode, col);
                }
                break;
            case 3: //dotted
                if(i%9<0.5){
                    plotLine(x, y, tebal, x1, y1, x2, y2, mode, col);
                }
                break;
            case 4: //Dashed Dotted
                if(i%9<2){

                }
                else if(i%9<6){
                    plotLine(x, y, tebal, x1, y1, x2, y2, mode, col);
                }
                else if(i%9==7){

                }
                else{
                    plotLine(x, y, tebal, x1, y1, x2, y2, mode, col);
                }
        }
        x += dx;
        y += dy;
//        usleep(10*1000);
    }
}
void drawPattern ( int x, int y, int k, int type, int color)
{
    switch (type){
        case DOTTED_LINE :{
            if(k%7<4)
                putpixel( x, y, color );
            break;
        }
        case CENTER_LINE :{
            if( ( k%18 < 4 ) || ( k%18 > 6 && k%18 < 15 ) )
                putpixel( x, y, color );
            break;
        }
        case DASHED_LINE :{
            if(k%11<8)
                putpixel( x, y, color );
            break;
        }
        case USERBIT_LINE :{
            if(k%16<1)
                putpixel( x, y, color );
            break;
        }
        default :{
            putpixel( x, y, color );
            break;
        }
    }
}
void BLine(int x1, int y1, int x2, int y2, int col)
{
    // Bresenham line
    int x, y, dx, dy, incX, incY;
    int d, incUP, incDAWN, reverse, n;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if ( (reverse = (dx < dy)) != 0 )
    {
        int buffer;
        buffer = x1; x1 = y1; y1 = buffer;
        buffer = x2; x2 = y2; y2 = buffer;
        buffer = dx; dx = dy; dy = buffer;
    }
    incUP = -dx - dx + dy + dy; //if choosen S
    incDAWN = dy + dy;
    incX = (x1 <= x2) ? 1 : -1;
    incY = (y1 <= y2) ? 1 : -1;
    d = -dx + dy + dy;
    x = x1; y = y1; n = dx; //+ 1;
    while (n--)
    {
        if (reverse)
            putpixel(y, x, col);
        else
            putpixel(x, y, col);
        x += incX;
        if (d > 0)
        { d += incUP; y += incY; }
        else
            d += incDAWN;
    } // end while
} // End of function BLine
