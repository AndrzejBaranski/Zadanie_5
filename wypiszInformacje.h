//
// Created by Andrzej Baranski on 20/06/2022.
//

#ifndef ZADANIE_5_WYPISZINFORMACJE_H
#define ZADANIE_5_WYPISZINFORMACJE_H


#include"negatyw.h"

struct FileHeader {
    short bfType;
    int bfSize;
    short bfReserved1;
    short bfReserved2;
    int bfOffBits;
};
struct PictureHeader {
    int biSize;
    int biWidth;
    int biHeight;
    short biPlanes;
    short biBitCount;
    int biCompression;
    int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    int biClrUsed;
    int biClrImportant;
};

void printInfo();

#endif //ZADANIE_5_WYPISZINFORMACJE_H
