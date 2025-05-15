#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <wchar.h>
#define BOARD_HEIGHT 10
#define BOARD_WIDTH 40
void init_board(int board[BOARD_HEIGHT][BOARD_WIDTH]){
    for (int i=0; i<BOARD_HEIGHT; i++){
        for (int j=0; j<BOARD_WIDTH; j++){
            board[i][j] = rand() % 2;
        }
    }
}
int xadd(int a, int x){
    int ans = (a + x)%BOARD_WIDTH;
    if (ans < 0){
        ans += BOARD_WIDTH;
    }
    return ans;
}
int yadd(int a, int y){
    int ans = (a + y)%BOARD_HEIGHT;
    if (ans < 0){
        ans += BOARD_HEIGHT;
    }
    return ans;
}
int adjacent_to(int board[BOARD_HEIGHT][BOARD_WIDTH], int i, int j){
    int a = 0;
    for (int k = -1; k < 2; k++){
        for (int l = -1; l < 2; l++){
            if (board[yadd(i, k)][xadd(j, l)] == 1 &&( k != 0 || l != 0)){
                a++;
            }
        }
    }
    return a;
}
void update_board(int board[BOARD_HEIGHT][BOARD_WIDTH]){
    int updated_state[BOARD_HEIGHT][BOARD_WIDTH];
    for (int i=0; i < BOARD_HEIGHT; i++){
        for (int j=0; j < BOARD_WIDTH; j++){
            int a = adjacent_to(board, i, j);
            int focus = board[i][j];
            if (a==3){
                updated_state[i][j] = 1;
            }
            if (((a < 2) || (3 < a))){
                updated_state[i][j] = 0;
            }
            if (a==2){
                updated_state[i][j] = board[i][j];
            }
        }   
    }
    for (int i=0; i < BOARD_HEIGHT; i++){
        for (int j=0; j < BOARD_WIDTH; j++){
            board[i][j] = updated_state[i][j];
        }
    }
}
int main(){
    int board[BOARD_HEIGHT][BOARD_WIDTH];
    init_board(board);
    for (int reps=0; reps < 100; reps++){
        update_board(board);
        for (int i=0; i < BOARD_HEIGHT; i++){
            for (int j=0; j < BOARD_WIDTH; j++){
                //find actual unicode char to put here 
                //find carriage clear char
                wchar_t car = board[i][j] == 1 ? (wchar_t) 0x2588 : (wchar_t) 0x0020;
                wprintf(L"%c", car);
            }
            printf("\n");
        }
        Sleep(200);
        printf("\033[2J");
    }
    return 0;
}