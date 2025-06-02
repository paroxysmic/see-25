#include <stdio.h>
#include <string.h>
#include "foo.h"

int main(){
    int npt;
    int arr[5] = {0, 1, 2, 3, 4};
    while(npt != 'q'){
        for(int i=0;i<5;i++){
            printf("%d ", arr[i]);
        }
        printf("\nwhat number next?");
        npt = getchar();
        while (npt < '0' || npt > '4'){
            printf("hey try again you need to actually put in a number between 0 and 4");
            npt = getchar();
        }
        foo(npt - '0', &arr[0]);
    }
    return 0;
}