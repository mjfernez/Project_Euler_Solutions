#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Problem 17 - Number Letter Counts
// So I found the string approach to be a pain in the ass in C (see Python solution)
// But then I realized, hey, I just need the lengths, so you don't have to pass the string!
const char *ones[10] = {"","one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"};
const char *teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", 
    "sixteen", "seventeen", "eighteen", "nineteen"};
const char *tens[10] = {"","", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"};
const char nd[4] = "AND";


int lengthOfName(char *num) {
    char *word; 
    // minus 1 for null terminator
    int digits = strlen(num) - 1;
    int n = atoi(num);
    if(digits == 1) {
        word = (char *) ones[n];
        printf("%s\n", word);
        return strlen(word);
    } else if(digits == 2) {
        // if the first digit, ie. the tens column is 1
        if(num[0] == '1'){
            word = (char *) teens[n % 10];
            printf("%s\n", word);
            return strlen(word);
        }
        // assuming the first digit is not one, if the second digit is 0
        else if(num[1] == '0'){
            word = (char *) tens[n / 10];
            printf("%s\n", word);
            return strlen(word);
        } else {
            // since the input to the function expects a string, 
            // an extra '\n' is needed
            char o[2];
            int on;
            word = (char *) tens[n / 10];
            printf("%s", word);
            memcpy(o, &num[1], 2);
            on = lengthOfName(o);
            return (strlen(word) + on);
        }
    } else if(digits == 3) {
        word = (char *) ones[n / 100];
        printf("%shundred", word);
        if(num[1] == '0' && num[2] == '0') {
            printf("\n");
            return strlen(word) + strlen("hundred");
        } else {
            char t[3];
            int te;
            strncpy(t, &num[1], 3);
            printf("%s", nd);
            te = lengthOfName(t);
            // example: the user inputs, num = 121
            //      one            hundred              AND     twenty one
            return (strlen(word) + strlen("hundred") + strlen(nd) + te);
        }
    }  else if(digits == 4) {
        word = (char *) ones[n / 1000];
        printf("%sthousand", word);
        if(num[1] == '0' && num[2] == '0' && num[3] == '0') {
            printf("\n");
            return strlen(word) + strlen("thousand");
        } /*else {
            char h[4];
            int hu;
            strncpy(h, &num[1], 3);
            hu = lengthOfName(h);
            return (strlen(word) + strlen("thousand") + hu);
        }*/
    }

    // error condition for debugging, i.e. in case I messed up, return something
    return -1;
}

int main() {
    // 4 is the max for this example, +1 for null terminator or if user tries to cheat
    char n[5];
    int out = 0;
    printf("Number from 1 to 1000: ");
    fgets(n, 10, stdin);
    if(atoi(n) > 1000)
        return printf("only up to 1000 in this example, sorry :(\n");
    // Test code to make sure the function works
    //out = lengthOfName(n);
    //printf("%d Characters... wow you'll hurt your hands typing that!\n", out);
    
    for(int i = 1; i <= atoi(n); i++){
        char curr[5];        
        sprintf(curr, "%d\n", i);
        out += lengthOfName(curr);
    }
    printf("Sum of charachters: %d\n", out);
    return 0;
}
