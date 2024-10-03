#include <stdio.h>


int main(){
    
    int max_row;
    scanf("%d", & max_row);

    for (int row = 1; row <= max_row ; row++){

        for (int column = row; column <= row+max_row-1; column++){

            if (column == row + max_row -1)
                printf("%d\n", column);
            else printf("%d,", column);

        }
    }
    return 0;

}
