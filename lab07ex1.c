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

    int digit[21], index = 0, estr = 0, flag = 1;
    unsigned long long num, ans, degree = 0, before = 0, check = 1, value;

    scanf("%llu", & num);
    ans = num;

    //printf("%llu\n", num);
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


    // printf("index: %d\n", index);
    // check power 1 by 1 to see if it is an estr number

    
    while (check > 0 && before != check){
        
        before = check;
        check = ans;
        
        estr += 1;
        // calculate sum of digit ^ estr;
        for (int j = 0; j <= index-1; j++){

            value = cal_large_pow(digit[j], estr);
            if (check >= value)
                check -= value;
            else flag = 0;

        }
            
        if (!flag)
            break; 
        //printf("check %d: %llu\n", estr, check);        
    }
    
    if (check == 0)
        printf("%d", estr);
    else printf("no");

    
    return 0;

}
