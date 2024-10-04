#include <stdio.h>
#include <string.h>
#include <math.h>


int main(){

    int smallest, largest, max_possible, count = -1, happy_num, happy = 1, sum = 0, flag; 
    char find_divisor[3000001];
    int all_divisor[1734];

    scanf("%d %d", & smallest, & largest);
    

    
    memset(find_divisor, 1, 3000001);
    max_possible = 3000001; //(int) (sqrt(current)+0.5);

        
    for (int check_divisor = 2; check_divisor <= max_possible; check_divisor++){

        if (find_divisor[check_divisor] == 1){
                
            //Sieve
            for (int j = check_divisor * 2; j <= max_possible; j += check_divisor)
                find_divisor[j] = 0;
       
        }
        
    }
    
    
    // loop for checking each number between the given range
    for (int current = smallest; current <= largest ; current++){
        
        

        // gather all factor of current number
        for (int k = 2; k <= current-1; k++){

            if (find_divisor[k] == 1 && current % k == 0){
                count += 1;
                //printf("%d\n", k);
                all_divisor[count] = k;
            }

        }
        
        //find if the current number has any happy divisor
        if (count > 1){
            
            for (int check_happy = 0; check_happy <= count; check_happy++){
                // check_happy: index refering to prime factors, helps generate happy_num
                
                
                
                
                // happy_num: the number checking if it is the happy divisor
                happy_num = current / all_divisor[check_happy];
                //printf("Suspected happy divisor: %d\n", happy_num);
                
                
                
                
                // check if the number is divisable for all prime divisor
                for (happy = 0; happy <= count; happy++){

                    flag = 1;
                    //printf("%d compare: %d\n", happy, all_divisor[happy]);
                    if (happy_num % all_divisor[happy] != 0){
                        //printf("%d is not divisable by %d\n\n", happy_num, all_divisor[happy]);
                        flag = 0;
                        break;
                    }
                    
                }
                //printf("happy: %d\n", happy);
                if (flag){
                    sum += 1;
                    //printf("happy %d\n", current);
                    break;
                }
                 
            
            }

        } else if (count == 0){
            sum += 1;
            //printf("happy 0\n");

        } else if (count == 1){

            if (all_divisor[0] * all_divisor[1] != current){
                sum += 1;
                //printf("happy 1\n");
            }
        }

        

        //printf("\n");
        count = -1;
    }

    printf("%d\n", sum);
    
    return 0;

}
