#include <stdlib.h> 
#include <stdio.h>
#include <math.h>

const long int MAX = 4 * pow(10, 6);
int *fib;

int main(){
    // Intialize sequence with first two terms
    fib = (int *) malloc (2 * sizeof(int));
    fib[0] = 1;
    fib[1] = 1;
    
    // loop counter
    int k = 1;
    // sum of even terms
    int sum = 0;
    //next term in sequence
    int next;
    while(1){
        next = fib[k] + fib[k - 1];
        printf("%d\n", next);
        if(next > MAX)
            break;
        if(next % 2 == 0)
            sum += next;
        k++;
        fib = (int *) realloc (fib, (k + 1) * sizeof(int));
        fib[k] = next;
    }
    printf("The sum of the even terms is %d\n", sum);
    return 0;
}
