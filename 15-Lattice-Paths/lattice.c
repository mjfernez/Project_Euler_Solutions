#include <stdio.h>
#include <gmp.h>

// Compile Notes: use `gcc <program>.c -lgmp`

// Starting in the top left corner of a 2×2 grid, 
// and only being able to move to the right and down, 
// there are exactly 6 routes to the bottom right corner.
// How many such routes are there through a 20×20 grid?

// This is another problem where pure math is the best solution
// Taking a look at the 2x2 grid, you notice all paths need 4 steps
// Check for a 3x3 and a 4x4, you'll notice the paths need 6 and
// 8 steps respectively. So a 20x20 will take 2*20 or 40 steps

// Another way of stating this problem: we have forty steps to take
// and each one will be either right or down AND they must be equal. 
// I couldn't traverse a 2 x 2 by going RRRD, 
// it must be RRDD, RDRD, DDRR, DRDR, RDDR, DRRD
// So of 40 steps we have to make, we have twenty choices to choose from.
// i.e. 40 nCr 20
// nCr = n!/r!(n-r)!
//      = 40!/(20! * 20!)
//      = 40*39*38*...*21 / 20*19*18...

int main(){
    mpz_t nCr;
    mpz_init_set_ui(nCr, 1);
    for(long i = 21; i <= 40; i++)
        mpz_mul_ui(nCr, nCr, i);
    for(long i = 20; i > 0; i--)
        mpz_fdiv_q_ui(nCr, nCr, i);
    gmp_printf("%Zd\n", nCr);
    return 0;
}
