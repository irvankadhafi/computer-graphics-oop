#include "util/util.h"
#include "shape/shape.h"
#include "karya/karya.h"
#include <future>

int main() {
    makeWindow(1000,700,(char*)"Irvan Kadhafi Canvas");
    Loading();
    animasiBunga1();
    animasiBunga2();
    animasiEllipse();
    animasiBunga3();
    batik(RED);
    getch();
    return 0;
}