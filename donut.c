#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BOARD_HEIGHT 20
#define BOARD_WIDTH 20
#define TAU 2 * 3.14159265358979323846
#define URANGE 40
#define VRANGE 40
#define TAU_U TAU / URANGE
#define TAU_V TAU / VRANGE
char luminance_index[13] = ".,-~:;=!*#$@";
void render_donut(double a, double b) {
    double zbuf[BOARD_WIDTH][BOARD_HEIGHT];
    char scrn[BOARD_WIDTH][BOARD_HEIGHT];
    memset(zbuf, 0, sizeof(zbuf));
    memset(scrn, ' ', sizeof(scrn));
    double sa = sin(a), ca = cos(a);
    double sb = sin(b), cb = cos(b);
    double uang = 0, vang = 0;
    double su, cu, sw, sv, cv, x, y, z, ny, nz, L;
    for (double u = 0; u < URANGE; u++) {
        uang += TAU_U;
        su = sin(u);
        cu = cos(u);
        for (double v = 0; v < VRANGE; v++) {
            vang += TAU_V;
            sv = sin(v),
            cv = cos(v);
            sw = sv * su;
            x = -ca * sb * cv * (su+2) + ca * cb * cu - sa * sv * (su+2);
            y = -sa * sb * cv * (su+2) + sa * cb * cu + ca * sv * (su+2);
            z = cb * cv * (su+2) + sb * cu;
            L = sa * cb * cu + sa * sb * su * cv - ca * su * sv - sb * cu + cb * su * cv;
            //note! L has a range from -sqrt(2) to sqrt(2)
            int xind = floor((x*1.66) + 6.5);
            int yind = floor((y*1.66) + 6.5);
            if (zbuf[yind][xind] < z) {
                zbuf[yind][xind] = z;
                scrn[yind][xind] = luminance_index[(int)floor(L*4.2 + 6.5)];
            }
        }
    }
    for(int i=0;i<BOARD_HEIGHT;i++){
        for(int j=0;j<BOARD_WIDTH;j++){
            printf("%c", scrn[i][j]);
        }
        printf("\n");
    }
    return;
}
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("wrong number of args!");
    }
    int maxiters = atoi(argv[1]);
    for (int i = 0; i < maxiters; i++) {
        render_donut(0.01 * i, 0.02 * i);
    }
    return 0;
}