#include <stdio.h>

int main(void) {
    int variableA = 3;
    int variableB = 6;
    int *ptrToA = &variableA;
    int *ptrToB = &variableB;

    *ptrToA = *ptrToA + *ptrToB;
    *ptrToB = *ptrToA - *ptrToB;
    *ptrToA = *ptrToA - *ptrToB;

    printf("%d %d", variableA, variableB);
}