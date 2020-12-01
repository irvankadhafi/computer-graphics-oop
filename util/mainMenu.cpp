//
// Created by irvan on 12/1/20.
//

#include "util.h"
#include "../shape/shape.h"
#include "../karya/karya.h"
void mainMenu(){
    int pilih;
    system("clear");
    cout<<"*********MENU***********"<<endl;
    cout<<"[1] Garis"<<endl;
    cout<<"[2] Shape"<<endl;
    cout<<"[3] Karya Grafika"<<endl;
    cout<<"[4] Transformasi"<<endl;
    cout<<"[5] UTS (Batik Pattern 2D)"<<endl;
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
        case 5:
            batikUTS();
            back();
            break;
        default:
            exit(0);
    }
}