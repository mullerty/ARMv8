 #include <time.h>
 #include "lab5.h"
 #define STB_IMAGE_IMPLEMENTATION
 #include "stb_image\stb_image.h"
 #define STB_IMAGE_WRITE_IMPLEMENTATION
 #include "stb_image\stb_image_write.h"

int main(void) {
    int width, height, channels;

    unsigned char *img = stbi_load("3.jpg", &width, &height, &channels, 0);
    if(img == NULL) {
       printf("Error in loading the image\n");
       return(1);
    }
    printf("width %dpx height %dpx  channels %d\n", width, height, channels);

    int gray_channels = channels == 4 ? 2 : 1;
    int gray_img_size = width * height * gray_channels;
    unsigned char *gray_img = malloc(gray_img_size*sizeof(unsigned char*));
    printf("gch %d\n", gray_channels);
    if(gray_img == NULL) {
        printf("Unable to allocate memory for the gray image.\n");
        return(1);
    }

    int t = clock();
    gray_img = executor(img, gray_img, width, height, channels);
    t = clock() - t;
    printf("c: %d ms\n", t);

    int t = clock();
    gray_img = executorasm(img, gray_img, width, height, channels);
    t = clock() - t;
    printf("asm: %d ms\n", t);

    stbi_write_jpg("gray.jpg", width, height, gray_channels, gray_img, 100);
    stbi_image_free(img);
    free(gray_img);
    return(0);
}