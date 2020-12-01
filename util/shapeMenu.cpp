//
// Created by irvan on 12/1/20.
//

#include "util.h"
#include "../shape/shape.h"
void midpointMenu(int x, int y, int radius);
int lineOptions(){
    int pilih;
    system("clear");
    cout<<"*********Jenis Line***********"<<endl;
    cout<<"[1] Solid Line"<<endl;
    cout<<"[2] Dashed Line"<<endl;
    cout<<"[3] Dotted Line"<<endl;
    cout<<"[4] Dashed - Dotted Line"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Masukan Pilihan = ";
    cin >> pilih;
    return pilih;
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
            Segitiga siku(x,y,alas,tinggi);
            siku.setSiku(true);
            siku.draw();
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
            cin>>y;cout<<"Titik Awal"<<endl;
            cout<<"Titik x : ";
            cin>>x;
            cout<<"Titik y : ";
            cin>>y;
            cout<<"Enter sisi : ";
            cin>>panjang;
            cout<<"Enter panjang"<<endl;
//            cin>>sisi;
//            belahKetupat2(20,250,sisi);
            BelahKetupat rec(x,y,d1,d2);
            cout<<"Enter panjang rx : "<<endl;
            cin>>rx;
            cout<<"Enter panjang ry : "<<endl;
            cin>>ry;
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
            Segitiga sisi(x,y,panjang,panjang);
            sisi.setRotate(30,false);
            sisi.setSiku(false);
            sisi.draw();
            back();
            break;
        }
        case 10:
        {
            Segitiga siku(400,20,100,250);
            siku.setRotate(30,false);
            siku.setX(450);
            siku.setSiku(false);
            siku.draw();
            siku.setRotate(180,false);
            siku.setTranslation(0,433);
            siku.draw();
            back();
            break;
        }
        default:
            mainMenu();
    }
}
void loopingLingkaran(Lingkaran lingkaran, int tebal, int radius){
    for (int i = 0; i < tebal; ++i) {
        lingkaran.setRadius(radius-i);
        lingkaran.draw();
    }
}
void midpointMenu(int x, int y, int radius){
    int tebal;
    string mode;
    cout<<"Ketebalan : ";
    cin>>tebal;
    Lingkaran cir(x,y,radius);
    switch(lineOptions()){
        case 1:
        {
            cir.setJenisGaris(1);
            loopingLingkaran(cir, tebal, radius);
            back();
            break;
        }
        case 2:
        {
            cir.setJenisGaris(2);
            loopingLingkaran(cir, tebal, radius);
            back();
            break;
        }
        case 3:
        {
            cir.setJenisGaris(3);
            loopingLingkaran(cir, tebal, radius);
            back();
            break;
        }
        case 4:
        {
            cir.setJenisGaris(4);
            loopingLingkaran(cir, tebal, radius);
            back();
            break;
        }
        default:
            mainMenu();
    }
}
void userInputLine(int jenis){
    int colors;
    colors = 4;
    int x1,x2,y1,y2,tebal;
    string mode;
    cout<<"Enter x1,y1,x2,y2"<<endl;
    cin>>x1>>y1>>x2>>y2;
    cout<<"Ketebalan : ";
    cin>>tebal;
    cout<<"Mode Ketebalan (in/out) : ";
    cin>>mode;
    DDALine(x1, y1, x2, y2, jenis, tebal, mode, colors);
}
void lineMenu()
{
    switch(lineOptions()){
        case 1:
            userInputLine(1);
            back();
            break;
        case 2:
            userInputLine(2);
            back();
            break;
        case 3:
            userInputLine(3);
            back();
            break;
        case 4:
            userInputLine(4);
            back();
            break;
        default:
            mainMenu();
    }
}