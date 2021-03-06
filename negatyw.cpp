//
// Created by Andrzej Baranski on 20/06/2022.
//

#include "negatyw.h"


void makeNegFile()
{
    FileHeader File;
    PictureHeader Picture;
    FILE* w = fopen("negative.bmp", "wb");
    if (w == nullptr)
    {
        printf("\n\n Can't open the file");
        exit;
    }
    else
    {
        printf("\n\n File w opened!");
    }
    FILE* f = fopen("test.bmp", "rb");

    if (f == nullptr)
    {
        printf("\n\n Can't open the file");
        exit;
    }
    else
    {
        printf("\n\n File f opened!");
    }

 fseek(w, 0, SEEK_SET);
    fwrite(&File.bfType, sizeof(File.bfType), 1, w);
    fwrite(&File.bfSize, sizeof(File.bfSize), 1, w);
    fwrite(&File.bfReserved1, sizeof(File.bfReserved1), 1, w);
    fwrite(&File.bfReserved2, sizeof(File.bfReserved2), 1, w);
    fwrite(&File.bfOffBits, sizeof(File.bfOffBits), 1, w);

    fseek(w, 14, SEEK_SET);
    fwrite(&Picture.biSize, sizeof(Picture.biSize), 1, w);
    fwrite(&Picture.biWidth, sizeof(Picture.biWidth), 1, w);
    fwrite(&Picture.biHeight, sizeof(Picture.biHeight), 1, w);
    fwrite(&Picture.biPlanes, sizeof(Picture.biPlanes), 1, w);
    fwrite(&Picture.biBitCount, sizeof(Picture.biBitCount), 1, w);
    fwrite(&Picture.biCompression, sizeof(Picture.biCompression), 1, w);
    fwrite(&Picture.biSizeImage, sizeof(Picture.biSizeImage), 1, w);
    fwrite(&Picture.biXPelsPerMeter, sizeof(Picture.biXPelsPerMeter), 1, w);
    fwrite(&Picture.biYPelsPerMeter, sizeof(Picture.biYPelsPerMeter), 1, w);
    fwrite(&Picture.biClrUsed, sizeof(Picture.biClrUsed), 1, w);
    fwrite(&Picture.biClrImportant, sizeof(Picture.biClrImportant), 1, w);

    fseek(w, sizeof(File.bfOffBits), SEEK_SET);

    int bmpImg;
    for (int i = File.bfOffBits; i < File.bfSize; i++)
    {
        fseek(f, i, SEEK_SET);
        fseek(w, i, SEEK_SET);
        fread(&bmpImg, 3, 1, f);
        bmpImg = INT_MAX - bmpImg; //Tworzymy negatyw
        fwrite(&bmpImg, 3, 1, w);
    }
    printf("\n");
    fclose(f);
    fclose(w);

}

