#include <stdio.h>


int main(){
    
    int n, k, n_fac = 1, k_fac = 1, n_k_fac = 1, product = 1, answer;

    scanf("%d %d", & n, & k);

    for (int i = 1; i <= n; i++){

        product *= i;
        if (i == n)
            n_fac = product;

        if (i == k)
            k_fac = product;

        if (i == n-k)
            n_k_fac = product;

    }


    answer = n_fac / k_fac / n_k_fac;
    printf("%d\n", answer);
    return 0;

}
