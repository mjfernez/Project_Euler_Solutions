#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

// Compile Notes: use `gcc <program>.c -lgmp`


int main(){
    mpz_t num, remainder;
    unsigned long sum = 0;
    mpz_init(num);
    mpz_init(remainder);
    // From docs, this assigns the value num to the value 2^1000
    mpz_ui_pow_ui(num, 2, 1000);
    
    // mpz_sgn returns 1 if positive, 0 if 0, -1 if negative
    while(mpz_sgn(num)){
        sum += mpz_mod_ui(remainder, num, 10);
        mpz_fdiv_q_ui(num, num, 10);
    }
    printf("%lu\n", sum);
    return 0;
}

