#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define BOARD_HEIGHT 40
#define BOARD_WIDTH 40
#define TAU 2 * 3.14159265358979323846
#define URANGE 100
#define VRANGE 100
#define TAU_U TAU / URANGE
#define TAU_V TAU / VRANGE
char luminance_index[] = ".,-~:;=!*#$@";
void render_donut(double a, double b) {
    double zbuf[BOARD_WIDTH][BOARD_HEIGHT];
    char scrn[BOARD_WIDTH][BOARD_HEIGHT];
    memset(scrn, ' ', sizeof(scrn));
    for(int i=0;i<BOARD_WIDTH;i++){
        for(int j=0;j<BOARD_HEIGHT;j++){
            zbuf[i][j] = -INFINITY;
        }
    }
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
            x = -ca * sb * cv * (su+2) + ca * cb * cu - sa * sv * (su+2);
            y = -sa * sb * cv * (su+2) + sa * cb * cu + ca * sv * (su+2);
            z = cb * cv * (su+2) + sb * cu;
            L = sa * cb * cu + sa * sb * su * cv - ca * su * sv - sb * cu + cb * su * cv;
            if (L > 0){
                //note! L has a range from -sqrt(2) to sqrt(2)
                int xind = (int)floor((x+3) * BOARD_WIDTH * 0.167);
                int yind = (int)floor((y+3) * BOARD_HEIGHT * 0.167);
                if (xind >= 0 && yind >= 0 && BOARD_WIDTH > xind && BOARD_HEIGHT > yind) {
                    if (zbuf[yind][xind] < z) {
                        zbuf[yind][xind] = z;
                        int li = (int)(L*4.2 + 6);
                        li = li < 0 ? 0 : li;
                        li = li > 12 ? 12 : li;
                        scrn[xind][yind] = luminance_index[li];
                    }
                }
            }
        }
    }
    for(int i=0;i<BOARD_HEIGHT;i++){
        for(int j=0;j<BOARD_WIDTH;j++){
            printf("%c", scrn[j][i]);
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
        system("cls");
        render_donut(0.03 * i, 0.05 * i);
        Sleep(10);
    }
    getchar();
    return 0;
}