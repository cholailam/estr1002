#include <stdio.h>

unsigned long long sum_pyra_ball(int layer, unsigned long long sum){

    if (layer == 1)
        return (sum + 1);
    
    sum += layer * layer;
    return (sum_pyra_ball(layer - 1, sum));
}


int main(){

    int level;
    unsigned long long sum = 0;

    scanf("%d", &level);
    sum = sum_pyra_ball(level, sum);
    printf("%llu", sum);
    return 0;

}
