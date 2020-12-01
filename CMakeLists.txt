cmake_minimum_required(VERSION 3.17)
project(Shape)

set(CMAKE_CXX_STANDARD 14)

add_executable(Shape main.cpp shape/shape.cpp shape/shape.h shape/persegi.cpp util/util.cpp util/util.h stroke/stroke.cpp stroke/stroke.h transformation/transformation.h transformation/rotasi.cpp transformation/translasi.cpp shape/jajargenjang.cpp shape/belahketupat.cpp shape/trapesiumsiku.cpp shape/lingkaran.cpp karya/karya.h karya/bunga.cpp shape/ellipse.cpp karya/batikUTS.cpp transformation/skalasi.cpp util/mainMenu.cpp util/shapeMenu.cpp shape/segitiga.cpp util/karyaMenu.cpp karya/piramidaPersegi.cpp karya/googleDrive.cpp karya/smileEmoticon.cpp)
target_link_libraries(${PROJECT_NAME} Xbgi X11 m pthread)
target_compile_options(${PROJECT_NAME} PRIVATE -Wno-everything)