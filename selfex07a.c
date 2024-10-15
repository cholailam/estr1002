#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int is_palindrome( const char str[103], int i, int j ){

    while (i < j){

        if (str[i] != str[j])
            return 0;
        i += 1;
        j -= 1;

    }
    return 1;
}


// hold the beginning at str[i], check how many substring it can form
int check_sub_palindrome( const char str[103], int i, int j, int n ){

    int sum = 0;
    while (j <= n){

        if ( is_palindrome(str, i, j) )
            sum += 1;
        j += 1;

    }
    return sum;

}


int main(){

    char str[103];
    int pos, start = 0, sum = 0;

    while ( fgets(str, 102, stdin) != NULL ){

        // remove new line symbol at the end
        pos = strlen(str) - 1;
        while ( pos >= 0 && (str[pos] == 10 || str[pos] == 13) )
            str[pos--] = '\0';


        // check sub palindrome
        while (start <= pos){
            
            sum += check_sub_palindrome(str, start, start + 1, pos);
            //printf("Start: %d\nsum: %d\n\n", start, sum);    
            start += 1;

        }

        printf("%d", sum);
    }   
    return 0;

}
