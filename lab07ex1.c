#include <stdio.h>
#include <math.h>



//calculate a very large power
unsigned long long cal_large_pow(int x, int y){

    unsigned long long product = 1;
    for (int i = 1; i <= y; i++){
        product *= x;
    }
    return product;
}









int main(){

    int digit[21], index = 0, estr = 0;
    unsigned long long num, ans, check = 0, degree = 0, before = -1;

    scanf("%llu", & num);
    ans = num;

    // Convert num to digits and append the digits in the array digit
    for (int i = 20; i >= 0; i--){

        //printf("%d\n", i);
        degree = cal_large_pow(10, i);
        //printf("degree: %llu\n", degree);
        if (degree <= num && num > 0){
       
            digit[index] = num/ degree;
            num -= digit[index] * degree;
            //printf("i: %d\nDigit: %d\nleft: %llu\n\n", i, digit[index], num);
            index += 1;

        }
    } 


    //printf("index: %d\n", index);
    // check power 1 by 1 to see if it is an estr number
    while (check < ans && before != check){
        
        before = check;
        check = 0;
        
        estr += 1;
        // calculate sum of digit ^ estr;
        for (int j = 0; j <= index-1; j++)
            check += cal_large_pow(digit[j], estr);
            
         
        //printf("check %d: %llu\n", estr, check);        
    }
    
    if (check == ans)
        printf("%d", estr);
    else printf("no");

    
    return 0;

}