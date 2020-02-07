#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct bigint bigint;

struct bigint{
    char digit;
    bigint *nextdigit;
};

// struct methods
int length();

// struct globals
bigint *end = NULL;
bigint *current = { .digit = '0', .nextdigit = end};

int length(bigint num){
    num->digits
}
