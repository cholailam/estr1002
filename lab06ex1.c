#include <stdio.h>

int main(){
    
    int i = 0, check_punc, check_up, check_low, check_num;
    check_punc = check_up = check_low = check_num = 0;
    char password[31], element;

    scanf("%s", password);
    while (password[i] != '\0' && check_punc + check_up + check_low +check_num != 4){
        element = password[i];
        //printf("%c\n", password[i]);

        // check if the element is a number
        if (element >= '0' && element <= '9')
            check_num = 1;


        // check if the element is a upper case letter
        if (element >= 'A' && element <= 'Z')
            check_up = 1;
            


        // check if the element is a lower case letter
        if (element >= 'a' && element <= 'z')
            check_low = 1;


        // check if the element has the punctuation
        if (element >= '!' && element <= '/' && !( element == '$' || element == '*' || element == '+' || element == '-'))
            check_punc = 1;

        if (element >= ':' && element <= '?' && !(element == '='))
            check_punc = 1;

        if (element >= '[' && element <= '`' && !(element == '^' || element == '_'))
            check_punc = 1;

        if (element >= '{' && element <= '~')
            check_punc = 1;
            
        i++;
    }

    if (check_punc + check_up + check_low +check_num == 4)
        printf("yes");
    else printf("no");
    return 0;
}
