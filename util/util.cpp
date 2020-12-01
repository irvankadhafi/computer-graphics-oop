//
// Created by irvan on 11/23/20.
//

#include "util.h"
#include "../shape/shape.h"
#include "../transformation/transformation.h"
#include "../stroke/stroke.h"
void makeWindow(int width, int height, char* windowName)
{
    initwindow(width,height,windowName);
}
void lineMenu()
{
    int pilih,colors;
    colors = 4;
    int x1,x2,y1,y2,tebal;
    string mode;
    system("clear");
    cout<<"*********LINE***********"<<endl;
    cout<<"[1] Solid Line"<<endl;
    cout<<"[2] Dashed Line"<<endl;
    cout<<"[3] Dotted Line"<<endl;
    cout<<"[4] Dashed - Dotted Line"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Masukan Pilihan = ";
    cin >> pilih;
    switch(pilih){
        case 1:
            cout<<"Enter x1,y1,x2,y2"<<endl;
            cin>>x1>>y1>>x2>>y2;
            cout<<"Ketebalan : ";
            cin>>tebal;
            cout<<"Mode Ketebalan (in/out) : ";
            cin>>mode;
            DDALine(x1, y1, x2, y2, 1, tebal, mode, colors);
            back();
            break;
        case 2:
            cout<<"Enter x1,y1,x2,y2"<<endl;
            cin>>x1>>y1>>x2>>y2;
            cout<<"Ketebalan : ";
            cin>>tebal;
            cout<<"Mode Ketebalan (in/out) : ";
            cin>>mode;
            DDALine(x1, y1, x2, y2, 2, tebal, mode, colors);
            back();
            break;
        case 3:
            cout<<"Enter x1,y1,x2,y2"<<endl;
            cin>>x1>>y1>>x2>>y2;
            cout<<"Ketebalan : ";
            cin>>tebal;
            cout<<"Mode Ketebalan (in/out) : ";
            cin>>mode;
            DDALine(x1, y1, x2, y2, 3, tebal, mode, colors);
            back();
            break;
        case 4:
            cout<<"Enter x1,y1,x2,y2"<<endl;
            cin>>x1>>y1>>x2>>y2;
            cout<<"Ketebalan : ";
            cin>>tebal;
            cout<<"Mode Ketebalan (in/out) : ";
            cin>>mode;
            DDALine(x1, y1, x2, y2, 4, tebal, mode, colors);
            back();
            break;
        default:
            mainMenu();
    }
}
void midpointMenu(int x, int y, int radius){
    int pilih;
    int tebal;
    string mode;
    system("clear");
    cout<<"*********Jenis Line***********"<<endl;
    cout<<"[1] Solid Line"<<endl;
    cout<<"[2] Dashed Line"<<endl;
    cout<<"[3] Dotted Line"<<endl;
    cout<<"[4] Dashed - Dotted Line"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Masukan Pilihan = ";
    cin >> pilih;
    cout<<"Ketebalan : ";
    cin>>tebal;
    switch(pilih){
        case 1:
            for (int i = 0; i < tebal; ++i) {
//                drawLingkaran(x, y, radius - i);
            }
            back();
            break;
        case 2:
            for (int i = 0; i < tebal; ++i) {
//                drawLingkaran(x, y, radius - i, 2);
            }
            back();
            break;
        case 3:
            for (int i = 0; i < tebal; ++i) {
//                drawLingkaran(x, y, radius - i, 2);
            }
            back();
            break;
        case 4:
            for (int i = 0; i < tebal; ++i) {
//                drawLingkaran(x, y, radius - i, 2);
            }
            back();
            break;
        default:
            mainMenu();
    }
}
void shapeMenu(){
    int pilih, panjang,lebar,x,y, a, b, tinggi, d1, d2, alas;
    string mode;
    system("clear");
    cout<<"*********SHAPE***********"<<endl;
    cout<<"[1] Persegi"<<endl;
    cout<<"[2] Persegi Panjang"<<endl;
    cout<<"[3] Jajar Genjang"<<endl;
    cout<<"[4] Belah Ketupat"<<endl;
    cout<<"[5] Trapesium Siku"<<endl;
    cout<<"[6] Segitiga Siku-Siku"<<endl;
    cout<<"[7] Lingkaran (Midpoint Algorithm)"<<endl;
    cout<<"[8] Ellipsee"<<endl;
    cout<<"[9] Segitiga Sama Sisi (Menggunakan rotasi)"<<endl;
    cout<<"[10] Belah Ketupat (2 Segitiga di rotasi)"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Masukan Pilihan = ";
    cin >> pilih;
    switch(pilih){
        case 1:
        {
            cout<<"Titik Awal"<<endl;
            cout<<"Titik x : ";
            cin>>x;
            cout<<"Titik y : ";
            cin>>y;
            cout<<endl<<"Panjang Sisi : ";
            cin>>panjang;
            Persegi rec(x,y,panjang,panjang);
            rec.draw();
            back();
            break;
        }
        case 2:
        {
            cout<<"Titik Awal"<<endl;
            cout<<"Titik x : ";
            cin>>x;
            cout<<"Titik y : ";
            cin>>y;
            cout<<endl<<"Panjang  : ";
            cin>>panjang;
            cout<<"Lebar  : ";
            cin>>lebar;
            Persegi rec(x,y,panjang,lebar);
            rec.draw();
            back();
            break;
        }
        case 3:
        {
            cout<<"Titik Awal"<<endl;
            cout<<"Titik x : ";
            cin>>x;
            cout<<"Titik y : ";
            cin>>y;
            cout<<"Enter panjang : "<<endl;
            cin>>panjang;
            cout<<"Enter tinggi : "<<endl;
            cin>>tinggi;
            JajarGenjang rec(x,y,panjang,tinggi);
            rec.draw();
            back();
            break;
        }
        case 4:
        {
            cout<<"Titik Awal"<<endl;
            cout<<"Titik x : ";
            cin>>x;
            cout<<"Titik y : ";
            cin>>y;
            cout<<"Enter diagonal 1 : ";
            cin>>d1;
            cout<<"Enter diagonal 2 : ";
            cin>>d2;
            //drawBelahKetupat((getmaxx()/2) - (100),250,100,50,true);
//            drawBelahKetupat(x,y,d1,d2,false);
            BelahKetupat rec(x,y,d1,d2);
            rec.draw();
            back();
            break;
        }
        case 5:
        {
            cout<<"Titik Awal"<<endl;
            cout<<"Titik x : ";
            cin>>x;
            cout<<"Titik y : ";
            cin>>y;
            cout<<"Enter sisi atas :";
            cin>>a;
            cout<<"Enter sisi bawah : ";
            cin>>b;
            cout<<"Enter tinggi : ";
            cin>>tinggi;
//            drawTrapesiumSiku(x,y,a,b,tinggi, false);
            TrapesiumSiku rec(x,y,a,b,tinggi);
            rec.draw();
            back();
            break;
        }
        case 6:
        {
            cout<<"Titik Awal"<<endl;
            cout<<"Titik x : ";
            cin>>x;
            cout<<"Titik y : ";
            cin>>y;
            cout<<"Enter alas : ";
            cin>>alas;
            cout<<"Enter tinggi : ";
            cin>>tinggi;
//            drawSegitigaSiku(x,y,alas,tinggi,false);
            back();
            break;
        }
        case 7:
        {
            int radius;
            cout<<"Titik Awal"<<endl;
            cout<<"Titik x : ";
            cin>>x;
            cout<<"Titik y : ";
            cin>>y;
            cout<<"Enter jari-jari : ";
            cin>>radius;
            midpointMenu(x,y,radius);
            back();
            break;
        }
        case 8:
        {
            int rx,ry;
            cout<<"Titik Awal"<<endl;
            cout<<"Titik x : ";
            cin>>x;
            cout<<"Titik y : ";
            cin>>y;
            cout<<"Enter panjang rx : "<<endl;
            cin>>rx;
            cout<<"Enter panjang ry : "<<endl;
            cin>>ry;
//            drawEllipse(x,y,rx,ry);
            Ellipsee ellipse1(x, y, rx, ry);
            ellipse1.draw();
            back();
            break;
        }
        case 9:
        {
            cout<<"Titik Awal"<<endl;
            cout<<"Titik x : ";
            cin>>x;
            cout<<"Titik y : ";
            cin>>y;
            cout<<"Enter sisi : ";
            cin>>panjang;
//            drawSegitigaSamaSisi(x,y,panjang);
            back();
            break;
        }
        case 10:
        {
            cout<<"Enter panjang"<<endl;
//            cin>>sisi;
//            belahKetupat2(20,250,sisi);
            back();
            break;
        }
        default:
            mainMenu();
    }
}
void karyaMenu(){
    int pilih;
    string mode;
    system("clear");
    cout<<"*********Karya Grafika***********"<<endl;
    cout<<"[1] Looping Persegi (Piramida Warna Warni)"<<endl;
    cout<<"[2] Google Drive"<<endl;
    cout<<"[3] Smile"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Masukan Pilihan = ";
    cin >> pilih;
    switch(pilih){
        case 1:
//            loopingPersegi();
            back();
            break;
        case 2:
//            logoGoogleDrive();
            back();
            break;
        case 3:
//            gambarSmile();
            back();
            break;
        default:
            mainMenu();
    }
}

void transformasiMenu(){
    int pilih;
    string mode;
    system("clear");
    cout<<"*********Transformasi (On Progress) ***********"<<endl;
    cout<<"[1] Translasi"<<endl;
    cout<<"[2] Rotasi"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Masukan Pilihan = ";
    cin >> pilih;
    switch(pilih){
        case 1:
            translasiMenu();
            back();
            break;
        case 2:
            rotasiMenu();
            back();
            break;
        default:
            mainMenu();
    }
}
void translasiMenu(){
    int pilih;
    string mode;
    system("clear");
    cout<<"*********Translasi (On Progress) ***********"<<endl;
    cout<<"[1] Titik"<<endl;
    cout<<"[2] Garis"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Masukan Pilihan = ";
    cin >> pilih;
    switch(pilih){
        case 1:
        {
            int x0,y0,tx,ty, P[2];
            cout<<"Enter x and y : ";
            cin>>x0>>y0;
            cout<<"Enter Tx and Ty : ";
            cin>>tx>>ty;

            P[0] = x0;
            P[1] = y0;

            int T[] = {tx, ty};

            putpixel(P[0],P[1],1); //Awal
            outtextxy(P[0]+10,P[1]-5,(char *)"Before");

            //Melakukan proses translasi, dan mengembalikan koordinat
            //yang baru
//            translasiTitik(P, T);

            putpixel(P[0],P[1],1); //Setelah Translasi
            outtextxy(P[0]+10,P[1]-5,(char *)"After");

            back();
            break;
        }
        case 2:
        {
            float x1,y1,x2,y2,tx,ty;
            cout<<"Enter x1,y1,x2,y2 : ";
            cin>>x1>>y1>>x2>>y2;
            cout<<"Enter Tx and Ty : ";
            cin>>tx>>ty;
            float P[2][2] = {
                    {x1,y1},
                    {x2,y2}
            }; // coordinates of point (matrix)
            int T[] = {(int)tx,(int) ty};
            outtextxy(P[0][0],P[0][1]-15,(char *)"Before");
            DDALine(P[0][0], P[0][1], P[1][0], P[1][1], 1, 1, "in", 1);

//            translasiGaris(P, T);

            outtextxy(P[0][0],P[0][1]-15,(char *)"After");
            DDALine(P[0][0], P[0][1], P[1][0], P[1][1], 1, 1, "in", 1);

            back();
            break;
        }
        default:
            mainMenu();
    }
}
void rotasiMenu(){
    int pilih;
    string mode;
    system("clear");
    cout<<"*********Rotasi (On Progress) ***********"<<endl;
    cout<<"[1] Garis"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Masukan Pilihan = ";
    cin >> pilih;
    switch(pilih){
        case 1:
        {
            float x1,y1,x2,y2;
            int angle,tx,ty,ask;
            bool clockwise = false;
            cout<<"Enter x1,y1,x2,y2 : ";
            cin>>x1>>y1>>x2>>y2;
            cout<<"Enter sudut : ";
            cin>>angle;
            cout<<"[1]Clockwise or [2]Anti-Clockwise ? ";
            cin>>ask;
            if (ask==2)
                clockwise = true;
            cout<<"Enter tx dan ty (titik translasi) : ";
            cin>>tx>>ty;
            float P[2][2] = {
                    {x1,y1},
                    {x2,y2}
            }; // coordinates of point (matrix)

            DDALine(P[0][0], P[0][1], P[1][0], P[1][1], 1, 1, "in", 1);
//            rotasiGaris(P,tx,ty,angle,clockwise);
            DDALine(P[0][0], P[0][1], P[1][0], P[1][1], 1, 1, "in", 1);

            back();
            break;
        }
        default:
            mainMenu();
    }
}
void mainMenu(){
    int pilih;
    system("clear");
    cout<<"*********MENU***********"<<endl;
    cout<<"[1] Garis"<<endl;
    cout<<"[2] Shape"<<endl;
    cout<<"[3] Karya Grafika"<<endl;
    cout<<"[4] Transformasi"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Masukan Pilihan = ";
    cin >> pilih;

    switch(pilih){
        case 1:
            lineMenu();
            break;
        case 2:
            shapeMenu();
            break;
        case 3:
            karyaMenu();
            break;
        case 4:
            transformasiMenu();
            break;
        default:
            exit(0);
    }
}
void back()
{
    int pilih;
    cout<<"[1] Main Menu"<<endl;
    cout<<"[2] Close"<<endl;
    cin>>pilih;
    if (pilih==1){
        clearviewport();
        mainMenu();
    }
    else{
        system("clear");
        exit(0);
    }
}
int transformasiMenuSub()
{
    int pilih;
    cout<<"Option Transformasi"<<endl;
    cout<<"[1] Translasi"<<endl;
    cout<<"[2] Rotasi"<<endl;
    cout<<"Pilihan : ";
    cin>>pilih;
    return pilih;
}