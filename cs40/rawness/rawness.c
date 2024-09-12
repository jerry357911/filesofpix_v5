#include <stdlib.h>
#include <stdio.h>
#include <pnmrdr.h>

extern int numPixels(FILE *fp);
// void convertToRaw(FILE *fp);

int main(int argc, char *argv[]) {
    if (argc == 1){
        printf("No file\n");
        return 1;
    } else {
        for (int i = 1; i < argc; i++){
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                fprintf(stderr, "%s: %s %s %s\n", argv[0], 
                        "Could not open file",
                        argv[1], "for reading");
                exit(1);
            }
            printf("Opened file\n");

            int num = numPixels(fp);
            printf("Size %d\n", num);

            // convertToRaw(fp);
            fclose(fp);
        }
    }
    return EXIT_SUCCESS;
}

int numPixels(FILE *fp) {
    Pnmrdr_T rdr = Pnmrdr_new(fp);
    Pnmrdr_mapdata map = Pnmrdr_data(rdr);
    printf("Width: %d Height: %d Maxval: %d\n", map.width, map.height, map.denominator);
    Pnmrdr_free(&rdr);
    // for (int i = 1; i < num, i++){
    //     Pnmrdr_get(rdr);
    // }
    return (map.width * map.height);
}
    

// void convertToRaw(FILE *fp){
//     Pnmrdr_T rdr = Pnmrdr_new(fp);
//     Pnmrdr_mapdata map = Pnmrdr_data(rdr);

//     printf("P5\n");
//     printf("%d %d\n", map.width, map.height);
//     printf("%d\n", map.denominator);

//     for (unsigned int i = 0; i < map.width * map.height; i++){
//         unsigned pixel = Pnmrdr_get(rdr);
//         putchar(pixel);
//     }

//     Pnmrdr_free(&rdr);
// }

