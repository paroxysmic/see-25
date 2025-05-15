#include <stdio.h>
#include <math.h>
#define BOARD_HEIGHT 10
#define BOARD_WIDTH 10
char luminance_index[] = ".,-~:;=!*#$@";
void init_board(double board[BOARD_WIDTH][BOARD_HEIGHT]){
    for (int i=0;i < BOARD_WIDTH;i++){
        for (int j=0; j < BOARD_HEIGHT; j++){
            board[i][j] = (double) ((i + j) % 12);
        }
    }
}
void displ_board(double board[BOARD_WIDTH][BOARD_HEIGHT]){
    for (int i=0;i < BOARD_HEIGHT; i++){
        for (int j=0;j < BOARD_WIDTH; j++){
            putchar(luminance_index[(int) board[j][i]]);
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