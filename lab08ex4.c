#include <stdio.h>

int stress_free_way(int my_target, int oppo_target, int myself, int oppo){
// my_target and oppo_target should remains unchanged


    //printf("%d-%d\n", myself, oppo);
    // terminate case: both teams reach their target
    if (myself == my_target && oppo == oppo_target)
        return 1;


    // myself greater than oppo by 1 points so myself get 1 point
    // boundary case: oppo == oppo_target and myself < my_target
    else if (myself - 1 == oppo || oppo == oppo_target)
        return stress_free_way(my_target, oppo_target, myself + 1, oppo);



    // boundary case: myself reach target and oppo != oppo_target
    else if (myself == my_target)
        return stress_free_way(my_target, oppo_target, myself, oppo + 1);



    

    // myself > oppo so I can choose myself or oppo get points
    else 
        return stress_free_way(my_target, oppo_target, myself + 1, oppo) + stress_free_way(my_target, oppo_target, myself, oppo + 1);

}

int main(){

    int myself, oppo, stress_free;

    scanf("%d-%d", &myself, &oppo);


    stress_free = stress_free_way(myself, oppo, 1, 0);
    printf("%d", stress_free);
    return 0;

}
