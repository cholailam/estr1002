#include <stdio.h>

int sum_possi_path(int row, int column, int sum){

    //printf("row, column: (%d, %d)\nsum: %d\n\n", row, column, sum);
    // terminate case: reach the bottom of triangle 
    if (row == 0 && column == 0)
        return (1);


    // special case: reach the hypoteneuos of triangle, only vertic way can go to there 
    else if (column == row)
        return sum_possi_path(row - 1, column, sum);


    // special case: can only go from horizontal
    else if (row == 0)
        return sum_possi_path(row, column - 1, sum);


    // trivial case: can go from hori and vertic
    else
        return ( sum_possi_path(row, column - 1, sum) + sum_possi_path(row - 1, column, sum) );
}

int main(){


    int row, column, sum = 0, size;

    scanf("%d", &size);

    sum = sum_possi_path(size, size, sum);
    printf("%d", sum);

    return 0;

}
