//
// Created by irvan on 11/23/20.
//

#ifndef SHAPE_UTIL_H
#define SHAPE_UTIL_H
#include <iostream>
#include <graphics.h>
using namespace std;
#define SIN(x) sin(x * 3.141592653589 / 180)
#define COS(x) cos(x * 3.141592653589 / 180)
void makeWindow(int, int, char*);
int lineOptions();
void mainMenu();
void shapeMenu();
void lineMenu();
void karyaMenu();
void transformasiMenu();
void translasiMenu();
void rotasiMenu();
void back();
int transformasiMenuSub();

#endif //SHAPE_UTIL_H
