#include <stdio.h>
#include <string.h>
#include <math.h>


int main(){

    int target, max_possible;   
    unsigned long sum = 0; 
    char all_num[2000001];

    scanf("%d", & target);
    memset(all_num, 1, 2000001);

    max_possible = (int) target;//(sqrt(target)+0.5);
    //printf("max: %d\n", max_possible);
    for (int i = 2; i <= max_possible; i++){

        if (all_num[i] == 1){
            //printf("prime: %d\n", i);
            for (int j = i+i; j <= max_possible; j += i)
                all_num[j] = 0;

        }
    }

    for (int k = 2; k <= max_possible; k++){

        //printf("%d: %d\n", k, all_num[k]);
        if (all_num[k] == 1){
            sum += k;
        }
    }
    printf("%lu", sum);
    return 0;

}
