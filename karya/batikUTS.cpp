//
// Created by irvan on 11/25/20.
//

#include "karya.h"
#include <future>
void motifBunga1(int x, int y, int s, int angle, int col){
    float motif[][2]={
            {x+55,y},
            {x+s+55,y},
            {x+s+s+55,y},
            {x+s+55,y-s},
            {x+s+55,y+s}
    };
    rotasiGaris(motif,motif[1][0],motif[1][1],5,angle, false);
    Persegi rec1(motif[0][0],motif[0][1],s,s);
    rec1.setColor(col);
    rec1.setRotate(45,false);
    rec1.draw();
    Persegi rec2(motif[1][0],motif[1][1],s,s);
    rec2.setColor(col);
    rec2.setRotate(45,false);
    rec2.draw();
    Persegi rec3(motif[2][0],motif[2][1],s,s);
    rec3.setRotate(45,false);
    rec3.setColor(col);
    rec3.draw();
    Persegi rec4(motif[3][0],motif[3][1],s,s);
    rec4.setRotate(45,false);
    rec4.setColor(col);
    rec4.draw();
    Persegi rec5(motif[4][0],motif[4][1],s,s);
    rec5.setRotate(45,false);
    rec5.setColor(col);
    rec5.draw();
//    usleep(10*1000);
}
void motifBunga2(int x, int y, int col){
    Ellipsee ellipse1(x - 35, y - 35, 45, 25);
    ellipse1.setColor(col);
    ellipse1.setAlpha(45,true);
    ellipse1.draw();

    ellipse1.setTranslation(72,72);
    ellipse1.draw();

    ellipse1.setAlpha(45,false);
    ellipse1.setTranslation(-72,0);
    ellipse1.draw();

    ellipse1.setTranslation(72,-72);
    ellipse1.draw();
}
void motifTambah(int x, int y, int col){
    Persegi rec1(x-(7+(15/5)),y-5,15,5);
    rec1.setColor(col);
    rec1.draw();
    rec1.setRotate(90,true);
    rec1.setTranslation(7+(15/5),-5);
    rec1.draw();
}
void motifBulat(int x, int y, int col){
    Lingkaran cir(x-35,y-35,8);
    cir.setColor(col);
    cir.draw();

    cir.setTranslation(72,0);
    cir.draw();

    cir.setTranslation(0,72);
    cir.draw();

    cir.setTranslation(-72,0);
    cir.draw();
}
void reload(int x, int y, int col){
    motifBunga2(x, y,col);
    motifBulat(x, y,col);
    motifTambah(x-35-20, y-35-20,col);
    motifTambah(x-35+20, y-35+20,col);

    motifTambah(x-35-20+115, y-35-20,col);
    motifTambah(x-35+20+35, y-35+20,col);


    motifTambah(x+35+20+2, y+35+20+2,col);
    motifTambah(x+35-20+2, y+35-20+2,col);

    motifTambah(x+35+20+2-110, y+35+20+2,col);
    motifTambah(x+35-20+2-30, y+35-20+2,col);
}
void reload2(int x, int y, int col){
    int i = 0;
    motifBunga1(x-2,y,12, i,col);
    motifBunga1(x-145-2,y,12, i,col);
    motifBunga1(x-75,y+75-2,12, i,col);
    motifBunga1(x-75,y-75+2,12, i,col);

}
void motifBungaGabung(int x, int y, int col) {
    reload(x, y, col);
    reload2(x, y, col);
//    thread th1(reload, x,y,col);
//    th1.join();
//    thread th2(reload2, x,y,col);
//    th2.join();
}
void batik(int col){
    for (int i = 0; i < 145*10; i+=145) {
        for (int j = 0; j < 145*10 ; j+=145) {
            motifBungaGabung(j,i,col);
        }
    }
}
void animasiBunga1(){
    int page = 1;
    motifTambah(getmaxx()/2,getmaxy()/2,5);
    for (int i = 0; i < (360*1); ++i) {
        motifBunga1(getmaxx()/2-220,getmaxy()/2,100,i,5);
        setactivepage(page);
        setvisualpage(1-page);
        page = 1 - page;
        cleardevice();
        usleep(10*1000);
    }
    motifBunga1(getmaxx()/2-220,getmaxy()/2,100,360,5);
}
void animasiBunga2(){
    float bunga[5][2];
    setactivepage(0);
    setvisualpage(0);
    cleardevice();
    bunga[0][0] = getmaxx()/2;
    bunga[0][1] = getmaxy()/2;
    motifBungaGabung(bunga[0][0],bunga[0][1],RED);
    int page=1;
    for (int i = 0; i < 50; ++i) {
        float T[2]={i,0};
        translasiGaris(bunga,1,T);
        motifBungaGabung(bunga[0][0],bunga[0][1],RED);
        setactivepage(page);
        setvisualpage(1-page);
        page = 1 - page;
        cleardevice();
        usleep(50*1000);
    }
    setactivepage(0);
    setvisualpage(0);
    cleardevice();
    bunga[0][0] = getmaxx()/2;
    bunga[0][1] = getmaxy()/2;
    motifBungaGabung(bunga[0][0],bunga[0][1],RED);
    page = 1;
    for (int i = 0; i < 50; ++i) {
        float T[2]={-i,0};
        translasiGaris(bunga,1,T);
        motifBungaGabung(bunga[0][0],bunga[0][1],RED);
        setactivepage(page);
        setvisualpage(1-page);
        page = 1 - page;
        cleardevice();
        usleep(50*1000);
    }
    setactivepage(0);
    setvisualpage(0);
    cleardevice();
    bunga[0][0] = getmaxx()/2;
    bunga[0][1] = getmaxy()/2;
    motifBungaGabung(bunga[0][0],bunga[0][1],RED);
    page = 1;
    for (int i = 0; i < 50; ++i) {
        float T[2]={0,-i};
        translasiGaris(bunga,1,T);
        motifBungaGabung(bunga[0][0],bunga[0][1],RED);
        setactivepage(page);
        setvisualpage(1-page);
        page = 1 - page;
        cleardevice();
        usleep(50*1000);
    }
    setactivepage(0);
    setvisualpage(0);
    cleardevice();
    bunga[0][0] = getmaxx()/2;
    bunga[0][1] = getmaxy()/2;
    motifBungaGabung(bunga[0][0],bunga[0][1],RED);
    page = 1;
    for (int i = 0; i < 50; ++i) {
        float T[2]={0,+i};
        translasiGaris(bunga,1,T);
        motifBungaGabung(bunga[0][0],bunga[0][1],RED);
        setactivepage(page);
        setvisualpage(1-page);
        page = 1 - page;
        cleardevice();
        usleep(50*1000);
    }
    setactivepage(0);
    setvisualpage(0);
    bunga[0][0] = getmaxx()/2;
    bunga[0][1] = getmaxy()/2;
    bunga[1][0] = getmaxx()/2+145;
    bunga[1][1] = getmaxy()/2;
    bunga[2][0] = getmaxx()/2-145;
    bunga[2][1] = getmaxy()/2;
    bunga[3][0] = getmaxx()/2;
    bunga[3][1] = getmaxy()/2-145;
    bunga[4][0] = getmaxx()/2;
    bunga[4][1] = getmaxy()/2+145;
    motifBungaGabung(bunga[0][0],bunga[0][1],RED);
    usleep(10*1000);
    motifBungaGabung(bunga[1][0],bunga[1][1],RED);
    usleep(10*1000);
    motifBungaGabung(bunga[2][0],bunga[2][1],RED);
    usleep(10*1000);
    motifBungaGabung(bunga[3][0],bunga[3][1],RED);
    usleep(10*1000);
    motifBungaGabung(bunga[4][0],bunga[4][1],RED);
    usleep(100*1000);
    cleardevice();
}
void animasiEllipse(){
    int page = 1;
    float ell[][2]={
            {50,20}
    };
    cleardevice();
    for (int i = 0; i < 20; ++i) {
        float S[2]={i,i};
        scaleGaris(ell,S);
        bungaDelapanKelopak(getmaxx()/2,getmaxy()/2,ell[0][0],ell[0][1]);
        setactivepage(page);
        setvisualpage(1-page);
        page = 1 - page;
        cleardevice();
        usleep(50*1000);
    }
    setactivepage(0);
    setvisualpage(0);
    usleep(50*1000);
    cleardevice();
}
void Loading(){
    outtextxy((getmaxx()/2)-10,(getmaxy()/2)+250,"Loading");
    Ellipsee ellipse1(getmaxx() / 2, getmaxy() / 2, 200, 50);
    for (int i = 0; i < 180; ++i) {
        ellipse1.setAlpha(i, false);
        ellipse1.draw();
        usleep(10*1000);
    }
    cleardevice();
    outtextxy((getmaxx()/2)-10,(getmaxy()/2)+250,"Loading");
    for (int i = 0; i < 180; ++i) {
        ellipse1.setAlpha(i, true);
        ellipse1.draw();
        usleep(10*1000);
    }
    cleardevice();
}
void motif1(int x, int y, int incX, int incY, int i, int col){
    motifBunga1(x-2+incX,y+incY,12, i,col);
    motifBunga1(x-145-2+incX,y+incY,12, i,col);
    motifBunga1(x-75+incX,y+75-2+incY,12, i,col);
    motifBunga1(x-75+incX,y-75+2+incY,12, i,col);
}
void motif2(int x, int y, int incX, int incY, int col){
    motifBunga2(x+incX, y+incY,col);
    motifBulat(x+incX, y+incY,col);
    motifTambah(x-35-20+incX, y-35-20+incY,col);
    motifTambah(x-35+20+incX, y-35+20+incY,col);
    motifTambah(x-35-20+115+incX, y-35-20+incY,col);
    motifTambah(x-35+20+35+incX, y-35+20+incY,col);
    motifTambah(x+35+20+2+incX, y+35+20+2+incY,col);
    motifTambah(x+35-20+2+incX, y+35-20+2+incY,col);
    motifTambah(x+35+20+2-110+incX, y+35+20+2+incY,col);
    motifTambah(x+35-20+2-30+incX, y+35-20+2+incY,col);
}
void reloadStatic(int col){
    int x = 0, y= 0;
    motif2(x, y, 145 * 0, 145 * 0, col);
    for (int j = 0; j < 8; ++j) {
        motif2(x, y, 145 * j, 145 * 0, col);
        for (int k = 0; k <6; ++k) {
            motif2(x, y, 145 * j, 145 * k, col);
        }
    }
}
void animasiBunga3(){
    int i = 0, x = 0, y= 0;
    int col = RED;
    int page = 1;
    int randNum;
    for (int i = 0; i < (360*10); i+=15) {
        randNum = rand()%(13-1 + 1) + 1;
        reloadStatic(randNum);
        motif1(x,y,145*0,145*0,i,col);
        for (int j = 1; j < 7; ++j) {
            motif1(x,y,145*0,145*j,i,col);
            motif1(x,y,145*j,145*0,i,col);
            for (int k = 1; k <5; ++k) {
                motif1(x,y,145*j,145*k,i,col);
            }
        }
        setactivepage(page);
        setvisualpage(1-page);
        page = 1 - page;
        cleardevice();
    }
    motifBunga1(x-2,y,12, i,col);
    motifBunga1(x-145-2,y,12, i,col);
    motifBunga1(x-75,y+75-2,12, i,col);
    motifBunga1(x-75,y-75+2,12, i,col);

    motifBunga1(x-2+145,y,12, i,col);
    motifBunga1(x-145-2+145,y,12, i,col);
    motifBunga1(x-75+145,y+75-2,12, i,col);
    motifBunga1(x-75+145,y-75+2,12, i,col);

    motifBunga1(x-2,y+145,12, i,col);
    motifBunga1(x-145-2,y+145,12, i,col);
    motifBunga1(x-75,y+75-2+145,12, i,col);
    motifBunga1(x-75,y-75+2+145,12, i,col);
}
void batikUTS(){
    Loading();
    animasiBunga1();
    animasiBunga2();
    animasiEllipse();
    animasiBunga3();
    batik(RED);
}