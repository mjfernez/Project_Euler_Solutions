#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Actually found a neat math solution to make this one quicker
 * since (a + b + c) = 1000
 * and a^2 + b^2 = c^2
 *
 * We can say:
 * c = 1000 - (a + b)
 * c^2 = (1000 - (a + b))^2
 * and
 * a^2 + b^2 = (1000 - (a + b))^2
 * So you need to find an a and b that satisfy this
 * We know a and b are less than 500 since c must be larger 
*/

int main(){
    for(long a = 1; a < 500; a++)
        for(long b = 1; b < 500; b++)
            if(pow(a, 2) + pow(b, 2) == pow((1000 - (a + b)), 2))
                return printf("%d\n", a * b * (long) sqrt(pow(a, 2) + pow(b, 2)));
    return 1;
}
