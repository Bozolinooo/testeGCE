#include <stdio.h>

char t114[7][7];

int NISOT7[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,1,
        0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,
        0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,1,
        0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,1,1,1,0,
        0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,1,0,1,
        0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,
        0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,
        0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1,
        0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,1,0,1,
        0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,1,
        0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,1,1,1,
        0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,1,0,1,
        0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,
        0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1,
        0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,0,0,
        0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0,1,0,1,
        0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,0,1,
        0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,1,0,0,
        0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,1,0,1,
        0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,
        0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,
        0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,
        0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,
        0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,1,
        0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,
        0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,1,
        0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,
        0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,1,0,1,
        0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,1,0,
        0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,1,0,0,1,0,0,
        0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,1,0,1,1,1,0,
        0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,0,
        0,0,0,0,0,0,1,0,0,1,0,1,1,0,0,1,0,0,0,1,0,
        0,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1,
        0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,1,0,1,
        0,0,0,0,0,0,1,0,1,0,0,1,1,0,0,0,1,0,1,0,1,
        0,0,0,0,0,0,1,0,1,0,0,1,1,0,0,1,0,0,1,1,0,
        0,0,0,0,0,0,1,1,0,0,0,1,0,0,1,0,1,1,0,0,0,
        0,0,0,0,0,0,1,1,0,0,0,1,0,0,1,1,1,0,1,0,1,
        0,0,0,0,0,0,1,1,0,0,0,1,0,1,0,1,1,0,0,0,0,
        0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,1,0,
        0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,
        0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,
        0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,1,0,0,
        0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
        0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,
        0,0,0,0,0,1,1,0,0,0,0,1,0,0,1,1,0,0,1,0,0,
        0,0,0,0,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,0,
        0,0,0,0,0,1,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,
        0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,0,0,1,0,0,
        0,0,0,0,0,1,1,1,0,0,0,1,0,1,0,1,1,0,0,0,0,
        0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,
        0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,
        0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,
        0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1,
        0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,1,0,1,
        0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,
        0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,1,
        0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
        0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
        0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
        0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
        0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,
        0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,
        0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,1,
        0,0,0,0,1,0,1,0,0,0,0,1,0,0,1,1,0,0,1,0,1,
        0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,
        0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,1,0,0,0,1,0,
        0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,1,0,0,1,0,1,
        0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,1,0,0,1,1,1,
        0,0,0,0,1,0,1,0,0,1,0,1,1,0,0,1,0,0,0,1,1,
        0,0,0,0,1,0,1,0,1,0,0,1,1,0,0,0,0,1,0,1,0,
        0,0,0,0,1,0,1,0,1,0,0,1,1,0,0,0,1,0,1,0,1,
        0,0,0,0,1,0,1,0,1,0,0,1,1,0,0,1,0,0,1,1,1,
        0,0,0,0,1,0,1,1,0,0,0,1,1,0,0,1,1,0,0,1,1,
        0,0,0,0,1,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1,
        0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,1,0,0,1,0,1,
        0,0,0,0,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,
        0,0,0,0,1,1,1,0,0,0,0,1,1,0,0,1,0,0,0,1,0,
        0,0,0,0,1,1,1,0,1,0,0,1,1,0,0,0,1,0,1,0,1,
        0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,1,1,
        0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,
        0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,
        0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,
        0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,0,
        0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,
        0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,1,0,
        0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,
        0,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,0,0,1,0,1,
        0,0,0,1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,1,1,1,
        0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
        0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,
        0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,
        0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,1,0,0,
        0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,1,
        0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,
        0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1,1,1,
        0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,1,1,0,
        0,0,0,1,0,0,1,1,0,0,0,1,0,1,0,1,1,0,1,0,1,
        0,0,0,1,0,1,1,0,0,0,0,1,0,0,0,1,0,0,1,1,0,
        0,0,0,1,0,1,1,1,0,0,0,1,0,1,0,1,1,0,1,0,1,
        0,0,0,1,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
        0,0,0,1,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,1,1,
        0,0,0,1,1,0,1,1,0,0,0,1,0,1,0,1,1,0,0,1,1,
        0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,
        0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,1,1,1,
        0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,0,1,
        0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,
        0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,1,1,
        0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,1,0,1,
        0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,0,1,0,
        0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,1,1,1,
        0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,1,0,
        0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,
        0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,1,0,0,
        0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,1,
        0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,
        0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,1,
        0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,
        0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,1,0,1,
        0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,1,0,1,
        0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,
        0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,
        0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,
        0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,
        0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,1,
        0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,0,0,1,1,1,
        0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,
        0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,1,
        0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,
        0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,1,0,0,
        0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,1,0,0,0,0,
        0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,1,0,1,0,1,
        0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,1,1,1,0,1,
        0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,1,1,0,1,0,1,
        0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,1,1,0,0,1,0,
        0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,1,1,0,1,1,1,
        0,0,1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0,
        0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,
        0,0,1,0,1,0,1,0,0,0,0,0,1,1,0,0,0,1,0,0,1,
        0,0,1,0,1,0,1,0,0,0,0,0,1,1,0,1,0,0,0,1,1,
        0,0,1,0,1,0,1,0,0,0,0,1,0,0,1,1,0,1,0,0,0,
        0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,1,
        0,0,1,0,1,0,1,0,0,0,0,1,1,0,0,0,1,1,0,0,1,
        0,0,1,0,1,0,1,0,0,0,0,1,1,0,0,1,0,1,0,1,0,
        0,0,1,0,1,0,1,0,0,0,0,1,1,0,0,1,0,1,1,0,1,
        0,0,1,0,1,0,1,0,0,0,0,1,1,0,0,1,1,0,0,1,1,
        0,0,1,1,0,0,0,0,0,1,0,1,0,0,0,1,1,0,1,0,1,
        0,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,
        0,0,1,1,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,1,0,
        0,0,1,1,0,0,1,0,0,0,0,1,0,1,0,0,1,1,0,0,1,
        0,0,1,1,0,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,
        0,0,1,1,0,0,1,0,0,0,0,1,0,1,0,1,0,1,1,0,1,
        0,0,1,1,0,0,1,0,0,0,0,1,0,1,0,1,1,0,0,1,1,
        0,0,1,1,0,0,1,0,0,0,0,1,0,1,0,1,1,0,1,0,1,
        0,0,1,1,0,0,1,0,0,0,0,1,1,0,0,1,0,1,1,1,0,
        0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,
        0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,1,
        0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,
        0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,1,
        0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,
        0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,1,
        0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,
        0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,0,
        0,1,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,0,0,0,
        0,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,1,0,0,
        0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,
        0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,1,
        0,1,0,0,0,0,0,0,0,1,0,1,1,0,0,1,0,0,0,1,0,
        0,1,0,0,0,0,0,0,0,1,0,1,1,0,0,1,0,0,1,0,0,
        0,1,0,0,0,0,0,0,0,1,0,1,1,0,0,1,0,0,1,0,1,
        0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,
        0,1,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,1,0,0,
        0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,1,0,1,
        0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0,1,
        0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,0,1,0,
        0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,
        0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,1,1,1,
        0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,1,1,0,
        0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,0,0,
        0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,
        0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,1,0,1,
        0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,1,0,0,0,1,
        0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,1,1,0,0,1,0,
        0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,1,1,0,1,0,0,
        0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,1,1,0,1,0,1,
        0,1,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,
        0,1,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,1,0,1,
        0,1,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,1,0,1,
        0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,1,0,0,
        0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,1,
        0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,
        0,1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,0,0,1,0,1,
        0,1,0,0,0,0,1,0,0,0,0,1,1,1,0,1,0,0,1,0,0,
        0,1,0,0,0,0,1,0,0,0,0,1,1,1,0,1,0,0,1,0,1,
        0,1,0,0,0,0,1,0,0,0,0,1,1,1,0,1,0,0,1,1,1,
        0,1,0,0,0,0,1,1,0,0,0,1,1,1,0,1,1,0,1,0,1,
        0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,1,0,0,0,0,0,
        0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,1,
        0,1,0,0,0,1,0,0,0,1,0,1,1,0,0,1,0,0,0,1,0,
        0,1,0,0,0,1,0,0,0,1,0,1,1,0,0,1,0,0,1,0,1,
        0,1,0,0,0,1,1,1,0,0,0,1,1,1,0,1,1,0,1,0,1,
        0,1,0,0,1,0,0,0,0,1,0,1,0,0,1,1,0,0,0,0,1,
        0,1,0,0,1,0,0,0,0,1,0,1,1,0,0,1,0,0,0,1,1,
        0,1,0,0,1,0,0,0,0,1,0,1,1,0,0,1,0,0,1,0,1,
        0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,
        0,1,0,0,1,0,0,1,0,0,0,0,1,1,0,0,0,1,0,0,1,
        0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1,
        0,1,0,0,1,0,0,1,0,0,0,1,1,0,0,0,1,1,0,0,1,
        0,1,0,0,1,0,0,1,0,0,0,1,1,0,0,1,0,1,0,1,0,
        0,1,0,0,1,0,0,1,0,0,0,1,1,0,0,1,0,1,1,0,1,
        0,1,0,0,1,0,1,0,0,0,0,1,0,1,1,1,0,0,0,0,1,
        0,1,0,0,1,0,1,0,0,0,0,1,1,0,1,1,0,0,0,1,0,
        0,1,0,0,1,0,1,0,0,0,0,1,1,0,1,1,0,0,1,0,1,
        0,1,0,0,1,0,1,0,0,0,0,1,1,1,0,1,0,0,0,1,1,
        0,1,1,0,0,0,0,0,0,0,1,1,0,1,0,1,1,0,0,0,0,
        0,1,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,
        0,1,1,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,0,0,0,
        0,1,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,1,
        0,1,1,0,0,0,0,0,0,1,0,1,1,0,0,0,1,1,0,0,1,
        0,1,1,0,0,0,0,0,0,1,0,1,1,0,0,1,0,1,0,1,0,
        0,1,1,0,0,0,0,0,0,1,0,1,1,0,0,1,0,1,1,0,1,
        0,1,1,0,0,0,0,0,0,1,0,1,1,0,0,1,1,0,0,1,1,
        0,1,1,0,0,0,0,0,0,1,0,1,1,0,0,1,1,0,1,0,1,
        0,1,1,0,0,0,1,0,0,0,0,0,1,1,1,0,0,1,0,0,0,
        0,1,1,0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,1,0,1,
        0,1,1,0,0,0,1,0,0,0,0,1,0,1,1,1,0,1,0,0,0,
        0,1,1,0,0,0,1,0,0,0,0,1,1,0,1,0,1,1,0,0,0,
        0,1,1,0,0,0,1,0,0,0,0,1,1,0,1,1,0,1,1,0,0,
        0,1,1,0,0,0,1,0,0,0,0,1,1,0,1,1,1,0,1,0,1,
        0,1,1,0,0,0,1,0,0,0,0,1,1,1,0,1,0,1,1,0,1,
        0,1,1,0,0,0,1,0,0,0,0,1,1,1,0,1,1,0,1,0,1,
        1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,
        1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,
        1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,1,0,1,
        1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,1,
        1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,
        1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,
        1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,
        1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,
        1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,
        1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,1,
        1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,1,1,1,
        1,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,1,1,0,1,
        1,0,0,0,0,0,0,0,1,1,0,1,0,0,0,1,0,0,0,1,0,
        1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,
        1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,
        1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,
        1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,
        1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,0,
        1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1,
        1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,0,0,
        1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0,1,0,1,
        1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,0,1,
        1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,
        1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,
        1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,1,
        1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,1,0,1,
        1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,1,1,0,
        1,0,0,0,0,0,0,1,1,0,0,0,0,1,0,1,0,0,0,1,0,
        1,0,0,0,0,0,0,1,1,0,0,1,0,0,0,1,1,0,0,1,0,
        1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
        1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
        1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,
        1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
        1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,
        1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,
        1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,
        1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,
        1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,
        1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,1,
        1,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,
        1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,1,0,1,
        1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,1,0,1,1,1,0,
        1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,
        1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,1,0,1,0,1,
        1,0,0,0,0,0,1,0,0,0,1,1,0,1,0,1,0,0,0,0,0,
        1,0,0,0,0,0,1,0,0,0,1,1,1,0,0,1,0,0,1,0,0,
        1,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,
        1,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,
        1,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,0,0,
        1,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,0,
        1,0,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,1,
        1,0,0,0,0,0,1,0,0,1,0,1,1,0,0,1,0,0,0,1,0,
        1,0,0,0,0,0,1,0,0,1,0,1,1,0,0,1,0,0,1,0,1,
        1,0,0,0,0,0,1,0,0,1,1,1,0,1,0,1,0,0,0,0,1,
        1,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,0,0,0,1,0,
        1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,
        1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,
        1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,1,
        1,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,1,0,1,
        1,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,1,1,1,
        1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,
        1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,0,
        1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,0,
        1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,0,
        1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1,
        1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,
        1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,
        1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,1,1,0,1,1,1,
        1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,0,1,1,0,0,
        1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1,
        1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,1,0,1,
        1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,
        1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,1,1,
        1,0,0,0,0,0,1,0,1,0,0,1,1,0,0,0,1,0,1,1,1,
        1,0,0,0,0,0,1,0,1,0,0,1,1,0,0,1,0,0,1,1,0,
        1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,0,0,
        1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,1,0,0,0,1,
        1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1,0,0,1,0,1,
        1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,1,0,1,
        1,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,1,0,0,
        1,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,1,0,1,
        1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,1,0,0,1,1,1,
        1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,
        1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,0,0,
        1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,
        1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0,1,0,1,
        1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,1,0,0,0,
        1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,1,1,0,0,
        1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,1,0,0,0,0,
        1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,1,0,1,0,1,
        1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,1,1,1,0,1,
        1,0,0,0,0,0,1,1,0,0,0,1,0,1,0,1,1,0,0,0,0,
        1,0,0,0,0,0,1,1,0,0,0,1,0,1,0,1,1,0,0,0,1,
        1,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,1,0,
        1,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,1,0,1,
        1,0,0,0,0,0,1,1,0,1,0,0,1,1,0,0,0,1,0,0,1,
        1,0,0,0,0,0,1,1,0,1,0,1,0,0,1,1,0,1,0,0,0,
        1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,
        1,0,0,0,0,0,1,1,0,1,0,1,1,0,0,0,1,1,0,0,1,
        1,0,0,0,0,0,1,1,0,1,0,1,1,0,0,1,0,1,0,1,0,
        1,0,0,0,0,0,1,1,0,1,0,1,1,0,0,1,0,1,1,0,1,
        1,0,0,0,0,0,1,1,0,1,0,1,1,0,0,1,1,0,0,1,1,
        1,0,0,0,0,0,1,1,1,0,0,1,0,1,0,1,0,1,0,1,0,
        1,0,0,0,0,0,1,1,1,0,0,1,0,1,0,1,1,0,1,0,1,
        1,0,0,0,0,0,1,1,1,0,0,1,1,0,0,1,0,1,1,1,0,
        1,0,0,0,0,1,1,0,0,1,0,1,0,0,0,1,0,0,0,1,0,
        1,0,0,0,0,1,1,0,0,1,0,1,0,0,0,1,0,0,1,0,1,
        1,0,0,0,0,1,1,0,1,0,0,1,0,0,0,1,0,0,1,1,0,
        1,0,0,0,0,1,1,1,0,0,0,1,0,0,0,1,1,0,1,0,1,
        1,0,0,0,0,1,1,1,1,0,0,1,0,1,0,1,1,0,1,0,1,
        1,0,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,0,1,0,1,
        1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,
        1,0,0,0,1,0,1,0,0,0,1,1,1,0,0,1,0,0,1,0,0,
        1,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,1,
        1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1,1,
        1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,1,0,
        1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,
        1,0,0,0,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,
        1,0,0,0,1,0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,1,
        1,0,0,0,1,0,1,1,0,0,0,0,1,0,0,1,0,0,0,1,0,
        1,0,0,0,1,0,1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,
        1,0,0,0,1,0,1,1,0,0,0,1,0,0,0,1,0,0,0,0,1,
        1,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,0,1,0,1,
        1,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,0,1,0,1,
        1,0,0,1,0,0,0,1,1,1,0,0,1,0,0,0,1,0,1,1,1,
        1,0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,1,0,1,1,1,
        1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,1,
        1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,
        1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,
        1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,
        1,0,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,1,1,1,
        1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,1,0,
        1,0,0,1,0,0,1,0,1,1,0,1,0,1,0,0,1,0,0,1,1,
        1,0,0,1,0,0,1,0,1,1,0,1,1,0,0,0,1,0,1,1,1,
        1,0,0,1,0,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,0,
        1,0,0,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,0,0,
        1,0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,1,1,0,0,
        1,0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,1,0,1,0,1,
        1,0,0,1,0,0,1,1,0,0,0,1,0,0,0,1,1,0,1,1,1,
        1,0,0,1,0,0,1,1,0,1,0,1,0,1,0,1,1,0,0,1,1,
        1,0,0,1,0,0,1,1,0,1,0,1,1,0,0,1,1,0,1,1,1,
        1,0,0,1,0,0,1,1,1,0,0,1,0,1,0,1,1,0,1,1,1,
        1,0,1,0,0,0,0,0,1,1,0,1,0,0,0,1,1,0,1,0,1,
        1,0,1,0,0,0,1,0,0,0,1,1,1,0,0,1,1,0,1,0,0,
        1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,
        1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,
        1,0,1,0,0,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,1,
        1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,0,
        1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,
        1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,
        1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,0,0,1,1,0,
        1,0,1,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,
        1,0,1,0,0,0,1,1,0,0,0,0,0,1,0,0,1,0,0,0,1,
        1,0,1,0,0,0,1,1,0,0,0,0,1,0,0,1,0,0,1,0,0,
        1,0,1,0,0,0,1,1,0,0,0,0,1,0,0,1,0,0,1,0,1,
        1,0,1,0,0,0,1,1,0,0,0,0,1,0,0,1,1,0,0,1,0,
        1,0,1,0,0,0,1,1,0,0,0,1,0,0,0,1,0,1,1,0,0,
        1,0,1,0,0,0,1,1,0,0,0,1,0,0,0,1,1,0,0,0,0,
        1,0,1,0,0,0,1,1,0,0,0,1,0,0,0,1,1,0,0,0,1,
        1,0,1,0,0,0,1,1,0,0,0,1,0,0,0,1,1,0,1,0,1,
        1,0,1,0,0,0,1,1,0,0,0,1,0,0,0,1,1,1,1,0,1,
        1,1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,0,1,
        1,1,0,0,0,0,0,1,0,1,0,1,1,0,0,1,1,0,1,0,1,
        1,1,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,
        1,1,0,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,1,0,1,
        1,1,0,0,0,0,1,0,0,0,1,1,0,1,0,1,0,0,0,1,0,
        1,1,0,0,0,0,1,0,0,0,1,1,0,1,0,1,0,0,1,0,1,
        1,1,0,0,0,0,1,0,0,0,1,1,1,0,0,1,0,0,1,1,0,
        1,1,0,0,0,0,1,0,0,0,1,1,1,1,0,1,0,0,1,0,0,
        1,1,0,0,0,0,1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,
        1,1,0,0,0,0,1,0,0,1,0,0,1,1,0,0,0,0,0,0,1,
        1,1,0,0,0,0,1,0,0,1,0,1,0,0,1,1,0,0,0,0,0,
        1,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,1,1,
        1,1,0,0,0,0,1,0,0,1,0,1,1,0,0,0,1,0,0,0,1,
        1,1,0,0,0,0,1,0,0,1,0,1,1,0,0,1,0,0,0,1,0,
        1,1,0,0,0,0,1,0,0,1,0,1,1,0,0,1,0,0,1,0,0,
        1,1,0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,
        1,1,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,0,1,0,
        1,1,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0,1,
        1,1,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,
        1,1,0,0,0,0,1,0,1,0,0,1,0,0,1,1,0,0,1,0,0,
        1,1,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,1,1,
        1,1,0,0,0,0,1,0,1,0,0,1,1,0,0,0,0,0,0,0,0,
        1,1,0,0,0,0,1,0,1,0,0,1,1,0,0,0,1,0,0,1,0,
        1,1,0,0,0,0,1,0,1,0,0,1,1,0,0,0,1,0,1,0,1,
        1,1,0,0,0,0,1,0,1,0,0,1,1,0,0,1,0,0,1,1,0,
        1,1,0,0,0,0,1,0,1,1,0,1,1,1,0,1,0,0,1,1,1,
        1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,0,0,0,1,
        1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,1,0,0,0,1,0,
        1,1,0,0,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,0,0,
        1,1,0,0,0,0,1,1,0,0,0,1,0,0,1,1,1,0,0,0,0,
        1,1,0,0,0,0,1,1,0,0,0,1,0,0,1,1,1,0,1,0,1,
        1,1,0,0,0,0,1,1,0,0,0,1,0,1,0,0,0,1,0,0,0,
        1,1,0,0,0,0,1,1,0,0,0,1,0,1,0,1,0,0,0,0,0,
        1,1,0,0,0,0,1,1,0,0,0,1,0,1,0,1,1,0,0,1,1,
        1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,0,1,
        1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,1,0,
        1,1,0,0,0,0,1,1,0,1,0,1,1,1,0,1,1,0,0,1,1,
        1,1,1,0,0,0,1,0,1,1,0,1,0,1,1,1,0,1,1,0,1,
        1,1,1,0,0,0,1,0,1,1,0,1,1,0,1,0,1,1,1,0,1,
        1,1,1,0,0,0,1,1,0,0,1,1,0,1,1,1,1,1,0,0,0};
        
void orienta_torneio (int n_torneio) {
	int i, j, cont = 0;
	
	for(i = 0; i < 7; i++){
		for(j = i + 1; j < 7; j++){
            if(NISOT7[cont + (21 * n_torneio)] == 0){
                t114[i][j]= 1;
                t114[j][i]= -1;
            }
            else{
                t114[i][j] = -1;
                t114[j][i] = 1;
            }
            
            cont++;
        }
    }	
}

int main () {
	int i , l, m, n_torneio;
	int mat_adj[4][4];
	
	for(i = 0; i < 37; i++){
		scanf("%d", &n_torneio);
		
		for(l = 0; l < 4; l++)
			for(m = 0; m < 4; m++)
				scanf("%d", &mat_adj[l][m]);
		
		printf("\\begin{figure}[!htb]\n");
		printf("  \\centering\n");
		printf("   \\begin{tikzpicture}[>=stealth',shorten >= 1pt,auto,node distance=1.8cm,semithick, state/.style={circle,draw,minimum size=0.3cm,inner sep=0pt, fill = black!70}]\n");
		printf("\n");
		printf("    \\node[state][label=above:0]	        (q0)										{};\n");
		printf("    \\node								(q0a)	[below of=q0]					    {};\n");
		printf("    \\node[state][label=right:1]			(q1)	[right of=q0a]				        {};\n");
		printf("    \\node[state][label=left:6]			(q6)	[left of=q0a]				        {};\n");
		printf("    \\node[state][label=right:2]			(q2)	[below of=q1]				        {};\n");
		printf("    \\node[state][label=left:5]			(q5)	[below of=q6]				        {};\n");
		printf("    \\node								(q5a)	[below of=q0a]				        {};\n");
		printf("    \\node[state][label=right:3]			(q3)	[below right=1.2cm of q5a]			{};\n");
		printf("    \\node[state][label=left:4]			(q4)	[below left=1.2cm of q5a]			{};\n");
		printf("\n");
		
		printf("    \\path[->]\n");
		
		orienta_torneio(n_torneio);
		
		for(l = 0; l < 7; l++)
			for(m = 0; m < 7; m++)
				if(t114[l][m] == 1)
					printf("                (q%d) edge [sloped, above]	    node [align=center]	{}	(q%d)\n", l, m);
		
		printf("                ;\n");
		printf("    \\end{tikzpicture}\n");
		
		printf("    \\begin{tikzpicture}[>=stealth',shorten >= 1pt,auto,node distance=1.8cm,semithick, state/.style={circle,draw,minimum size=0.3cm,inner sep=0pt, fill = black!70}]\n");
		printf("\n");
		printf("    \\node[state][label=above:0]	        (q0)										{};\n");
		printf("    \\node[state][label=above:1]         (q1)    [right of=q0]                       {};\n");
		printf("    \\node[state][label=below:2]         (q2)    [below of=q0]                       {};\n");
		printf("    \\node[state][label=below:3]         (q3)    [below of=q1]                       {};\n");
		printf("\n");
		
		printf("    \\path[->]\n");
		
		for(l = 0; l < 4; l++)
			for(m = 0; m < 4; m++)
				if(mat_adj[l][m] == 1)
					printf("                (q%d) edge [sloped, above]		node [align=center]	{}	(q%d)\n", l, m);
		
		printf("                ;\n");
		printf("    \\end{tikzpicture}\n");
		printf("  \\caption{T%d}\n", n_torneio);
		printf("\\end{figure}\n");
	}
	
	return 0;
}