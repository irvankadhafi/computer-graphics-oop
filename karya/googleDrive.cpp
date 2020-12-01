//
// Created by irvan on 12/1/20.
//

#include "karya.h"
void logoGoogleDrive()
{
    int midX = getmaxx()/2;
    int midY = getmaxy()/2;
    Lingkaran cir(midX,midY,150);
    cir.draw();
    midY = midY + 50;
    DDALine(midX - 100, midY, midX + 100, midY, 1, 2, "out", BLUE);
    DDALine(midX - 70, midY + 30, midX + 70, midY + 30, 1, 2, "out", BLUE);
    DDALine(midX - 100, midY, midX - 70, midY + 30, 1, 2, "out", BLUE); //kiri
    DDALine(midX + 100, midY, midX + 70, midY + 30, 1, 2, "out", BLUE); //kanan

    DDALine(midX - 70, midY + 30, midX + 20, midY - 100 - 30, 1, 2, "out", GREEN);
    DDALine(midX - 100, midY, midX - 30, midY - 100 - 30, 1, 2, "out", GREEN);
    DDALine(midX - 100, midY, midX - 70, midY + 30, 1, 2, "out", GREEN); //kiri

    DDALine(midX - 30, midY - 100 - 30, midX + 70, midY + 30, 1, 2, "out", YELLOW);
    DDALine(midX + 20, midY - 100 - 30, midX + 100, midY, 1, 2, "out", YELLOW);

    DDALine(midX - 30, midY - 100 - 30, midX + 20, midY - 100 - 30, 1, 2, "out", YELLOW); //atas lurus
}