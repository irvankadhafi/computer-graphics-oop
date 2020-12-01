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
void back()
{
    int pilih;
    cout<<endl<<"[1] Main Menu"<<endl;
    cout<<"[2] Close"<<endl;
    cout<<"Pilih : ";
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