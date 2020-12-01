//
// Created by irvan on 12/1/20.
//
#include "util.h"
#include "../shape/shape.h"
#include "../karya/karya.h"
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
            piramidaPersegi();
            back();
            break;
        case 2:
            logoGoogleDrive();
            back();
            break;
        case 3:
            gambarSmile();
            back();
            break;
        default:
            mainMenu();
    }
}