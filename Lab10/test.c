#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


int two (int a, int *b);

void one (void)
{
int a = 10;
int b = 20;
int x;
x = two (b, &a);
printf ("%d, %d, %d\n", a, b, x);
}

int two (int a, int *b)
{
a -= 2;
*b += 4;
return (a + *b);

}