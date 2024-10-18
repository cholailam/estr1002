#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int binary_search(int target, int ordered_tm[10005], int size){

    int left = 0, right = size - 1, middle;

    while (left <= right){

        middle = (left + right) / 2;
        
        if (ordered_tm[middle] == target)
            return 1;
        else if (ordered_tm[middle] > target)
            right = middle - 1;
        else
            left = middle + 1;

    }
    return 0;
}


int main(){

    int size_m, size_k, value, ordered_tm[10005], pos = 0, current_min, tmp, target;

    scanf("%d", &size_m);


    // assign values to array ordered_tm
    for (pos = 0; pos <= size_m - 1; pos++){

        scanf("%d", &value);
        ordered_tm[pos] = value;

    }



    // sort the array ordered_tm by selection sort
    for (int i = 0; i <= size_m - 1; i++){

        current_min = i;
        for (int j = i+1; j <= size_m - 1; j++){

            if (ordered_tm[j] < ordered_tm[current_min])
                current_min = j;
            
        }

        tmp = ordered_tm[current_min];
        ordered_tm[current_min] = ordered_tm[i];
        ordered_tm[i] = tmp;

    
    }

    //for (int k = 0; k <= size_m-1; k++)
    //    printf("=> %d\n", ordered_tm[k]);


    scanf("%d", &size_k);

    for (int a = 1; a <= size_k; a++){

        scanf("%d", &target);
        if (binary_search(target, ordered_tm, size_m))
            printf("yes\n");
        else printf("no\n");
    }

    return 0;

}
