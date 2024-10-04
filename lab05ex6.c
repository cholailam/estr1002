#include <stdio.h>
#include <string.h>
#include <math.h>


int main(){

    int smallest, largest, max_possible, count = -1, happy_num, happy = 1, sum = 0; 
    char find_divisor[3000001];
    int all_divisor[1734];

    scanf("%d %d", & smallest, & largest);
    

    
    // loop for checking each number between the given range
    for (int current = smallest; current <= largest ; current++){
        
        
        printf("current: %d\n", current);


        // find all divisor of the current number
        memset(find_divisor, 1, 3000001);
        max_possible = (int) (sqrt(current)+0.5);

        //printf("Max_possible: %d\n", max_possible);
        for (int check_divisor = 2; check_divisor <= max_possible; check_divisor++){

            //printf("Check divisor ing: %d\n", check_divisor);
            if (current % check_divisor == 0 && find_divisor[check_divisor] == 1){
                
                //Sieve
                for (int j = check_divisor * 2; j <= current; j += check_divisor)
                    find_divisor[j] = 0;
           
            }


        }
        

        // gather all prime factor of current number
        for (int k = 2; k <= current; k++){

            if (find_divisor[k] == 1){
                count += 1;
                printf("%d\n", k);
                all_divisor[count] = k;
            }

        }

        //find if the current number has any happy divisor
        //printf("count: %d\n", count);
        if (count > 1){
            
            for (int check_happy = 0; check_happy <= count; check_happy++){
                
                
                // check if the number is divisable for all prime divisor
                happy_num = current / all_divisor[check_happy];
                //printf("check happy: %d\n", happy_num);
                for (happy = check_happy + 1; happy <= count; happy++){

                    //printf("%d compare: %d\n", happy, all_divisor[happy]);
                    if (happy_num % all_divisor[happy] != 0);
                        break;
                    }
                    
                }
                printf("happy: %d\n", happy);
                if (happy-1 == count){
                    sum += 1;
                    printf("happy %d\n", current);
                    break;
                }
                 
            
            

        } else if (count == 0){
            sum += 1;
            printf("happy 0\n");

        } else if (count == 1){

            if (all_divisor[0] * all_divisor[1] != current){
                sum += 1;
                printf("happy 1\n");
            }
        }



        printf("\n");
        count = -1;
    }

    printf("%d\n", sum);
    
    return 0;

}
