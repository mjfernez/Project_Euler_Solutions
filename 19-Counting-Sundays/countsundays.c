#include <stdio.h>
#include <time.h>

// Implemented a timing routine for fun :)

int main(){
    clock_t now, then;
    int c = 0;
    struct tm time = {0};

    then = clock();
    time.tm_mday = 1;

    // Starting from 1-1-1901
    for(int y = 1; y <= 100; y++){
	for(int m = 0; m < 12; m++){ // Apparently January is the 0th month, 
            time.tm_mon = m;        // even though there's no 0th day.... wtf K&R??
	    time.tm_year = y;
	    time_t inttime = mktime(&time);
	    struct tm *t = localtime(&inttime);
	    if(t->tm_wday == 0)
		c++;
	}
    }
    printf("%d\n", c);
    now = clock();
    printf("Only took %f ms\n", (double)(now - then) / (CLOCKS_PER_SEC / 1000));
    return 0;
}
