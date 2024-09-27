#include <stdio.h>


int main(){
    
    int x_diff, y_diff, spend, move_iron, min = 0, i;

    scanf("%d %d", & x_diff, & y_diff);
    scanf("%d", & spend);
    
    
    for (i = 1; i <= spend; i++){

        if (x_diff == 0 && y_diff == 0)
            break;

       
        min += 1;
        scanf(" %d", & move_iron);



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

        // move ourselves
        if (x_diff > y_diff && x_diff != 0){
            
            if (x_diff > 0)
                x_diff -= 1;
            else if (x_diff < 0)
                x_diff += 1;
            
        } else if (y_diff != 0) {

            if (y_diff > 0)
                y_diff -= 1;
            else if (y_diff < 0)
                y_diff += 1;

        }


    }
    
    if (i-1 == spend && x_diff != 0 && y_diff != 0)
        printf("impossible\n");
    else printf("%d\n", min);

    return 0;

}
