#include <stdio.h>


int main(){
    
    int length, sum = 0, target[2000], increase = 0;

    scanf("%d", & length);

    for (int i = 1; i <= length; i++){
        scanf("%d", & target[i-1]);
    }


    if (target[0] < target[1])
        increase = 1;

    for (int j = 1; j <= length-2; j++){

        //printf("Inc: %d, target: %d, next: %d\n", increase, target[j], target[j+1]);
        if (target[j+1] < target[j]){

            if (increase && target[j+1] != target[j] && target[j-1] != target[j]){
                sum += target[j];
                //printf("1 turning: %d\n", target[j]);
            }
            increase = 0;

        } else if (target[j+1] > target[j]){

            if (!increase && target[j] != target[j+1] && target[j-1] != target[j]){
                sum += target[j];
                //printf("2 turning: %d\n", target[j]);
            }
            increase = 1;
        }
    }

    printf("%d", sum);
    return 0;

}
