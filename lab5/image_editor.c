#include "lab5.h"

unsigned char* executor(unsigned char* img, unsigned char* gray_img, int width, int height, int channels)
{
    int img_size = width * height * channels;
    int gray_channels = channels == 4 ? 2 : 1;
    for(unsigned char *p = img, *pg = gray_img; p != img + img_size; p += channels, pg += gray_channels) {
        *pg = (*p*0.3 + *(p + 1)*0.59 + *(p + 2)*0.11);
        if(channels == 4) {
            *(pg + 1) = *(p + 3);
        }
    }
    return(gray_img);
}