#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>
#define BOARD_HEIGHT 10
#define BOARD_WIDTH 10
#define TAU 2 * M_PI
#define TAU_40 TAU / 40
char luminance_index[] = ".,-~:;=!*#$@";
void render_donut(double a, double b){
    double zbuf[BOARD_WIDTH][BOARD_HEIGHT];
    memset(zbuf, 0, sizeof(int) * BOARD_HEIGHT * BOARD_WIDTH);
    /*
    #should be (cosu, (sinu+2)cosv, -(sinu+2)sinv) u is small ring, v is big ring
    */
    for (double u=0;u < TAU;u += TAU_40){
        for (double v=0;v < TAU;v += TAU_40){
            double x = cos(u);
            double y = (sin(u)+2) * cos(v);
            double z = (sin(u)+2) * sin(v);
            
        }
    }
    return;
}
void displ_board(double board[BOARD_WIDTH][BOARD_HEIGHT]){
    for (int i=0;i < BOARD_HEIGHT; i++){
        for (int j=0;j < BOARD_WIDTH; j++){
            printf("%d", luminance_index[(int)(board[j][i])]);
        }
        printf("\n");
    }
} 
int main(){
    double screen[BOARD_WIDTH][BOARD_HEIGHT];
    init_board(screen);
    displ_board(screen);
    return 0;
}    