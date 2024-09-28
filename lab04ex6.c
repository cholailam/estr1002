#include <stdio.h>
#include <stdlib.h>


int main(){
    
    int x_diff, y_diff, spend, move_iron, min = 0, i, next;

    scanf("%d %d", & x_diff, & y_diff);
    scanf("%d", & spend);
    scanf(" %d", & move_iron);
    
    
    for (i = 1; i <= spend; i++){

        if (x_diff == 0 && y_diff == 0)
            break;

        min += 1;
        
        if (i != spend)
            scanf(" %d", & next);



        //move iron man
        switch (move_iron){

            case 1:
                x_diff += 1;
                break;
            case 2:
                x_diff -= 1;
                break;
            case 3:
                y_diff -= 1;
                break;
            case 4:
                y_diff += 1;
                break;

        }

        
        
        if (x_diff == 0 && y_diff == 0)
            break;

        
        //printf("%d  iron: %d, %d\n", i, x_diff, y_diff);

        // move ourselves
        
        if ( abs(x_diff) == abs(y_diff) ){

            //printf("zero: %d\n", next);
            if ( (next == 1 && y_diff > 0) || (next == 2 && y_diff < 0) || (next == 3 && y_diff < 0) || (next == 4 && y_diff > 0) ){
                
                if (y_diff > 0)
                    y_diff -= 1;
                else y_diff += 1;
            
            } else{

                if (x_diff > 0)
                    x_diff -= 1;
                else x_diff += 1;

            }

        } else if ( abs(x_diff) > abs(y_diff) ){
            
            //printf("first: %d\n", next);
            if (x_diff > 0)
                x_diff -= 1;
            else if (x_diff < 0)
                x_diff += 1;
            
        } else{

            //printf("second: %d\n", next);
            if (y_diff > 0)
                y_diff -= 1;
            else if (y_diff < 0)
                y_diff += 1;

        } 

        //printf("%d    me: %d, %d\n\n", i, x_diff, y_diff);

        move_iron = next;

        if (x_diff == 0 && y_diff == 0)
            break;
    }
    
    if (i-1 == spend && (x_diff != 0 || y_diff != 0 ))
        printf("impossible\n");
    else printf("%d\n", min);



    return 0;

}
