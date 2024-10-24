#include <stdio.h>

int sum_possi_path(int grid[11][11], int row, int column){

    int sum1 = 0, sum2 = 0;
    //printf("row, column: (%d, %d)\n\n", row, column);


    // terminate case: reach the upper left corner 
    if (row == 0 && column == 0)
        return (grid[0][0]);


    // special case: can only go from vertical
    else if (column == 0)
        return grid[row][0] + sum_possi_path(grid, row - 1, 0);


    // special case: can only go from horizontal
    else if (row == 0)
        return grid[0][column] + sum_possi_path(grid, 0, column - 1);


    // trivial case: can go from hori and vertic
    else{

        sum1 = sum_possi_path(grid, row - 1, column);
        sum2 = sum_possi_path(grid, row, column - 1);
        

        //printf("1:%d 2:%d\n", sum1, sum2);
        if (sum1 > sum2)
            return grid[row][column] + sum1;//sum_possi_path(grid, row - 1, column);
        return grid[row][column] + sum2;//sum_possi_path(grid, row, column - 1);

    }

    
}

int main(){


    int row, column, sum = 0, size, grid[11][11];

    scanf("%d", &size);


    // read the score in each block
    for (int i = 0; i <= size; i++){

        for (int j = 0; j <= size; j++){

            scanf("%d", &grid[i][j]);

        }
    }

    sum = sum_possi_path(grid, size, size);
    printf("%d", sum);

    return 0;

}
