#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int check_peak(const int square[205][205], int x, int y, int size){


    if (x != 0){

        if ( square[x-1][y] >= square[x][y])
            return 0;

    }

    if (y != 0){

        if ( square[x][y-1] >= square[x][y])
            return 0;

    }

    if (x != size -1 ){

        if ( square[x+1][y] >= square[x][y])
            return 0;

    }

    if (y != size - 1){

        if ( square[x][y+1] >= square[x][y])
            return 0;

    }

    return 1;
}



int main(){

    char grid[205];
    int size, value, square[205][205], x = 0, y = 0, flag = 0;
    char* token;

    scanf("%d\n", &size);
    //printf("size: %d\n", size);
    for (int i = 1; i <= size; i++){

        fgets(grid, 205, stdin);
        token = strtok(grid, " ");

        while (token != NULL){
            //printf("[%s]\n", token);
            value = atoi(token);
            
            //printf("value: %d\n", value);
            // assign value to each box
            square[x][y] = value;
            y += 1;
            token = strtok(NULL, " ");
        }

        x += 1;
        y = 0;

    
   
    
    
    }
    


    for (int a = 0; a <= size - 1; a++){

        for (int b = 0; b <= size - 1; b++){

            if (check_peak(square, a, b, size)){
                printf("%d %d\n", a, b);
                flag = 1;
            }

        }

    }
    //printf("%d\n", square[1][1]);


    if (!flag)
        printf("none");
    return 0;

}
