#include <stdio.h>

int main(void) {
    // Declare variable and there pointer
    int variableA = 3;
    int variableB = 6;
    int *pointerToVariableA = &variableA;
    int *pointerToVariableB = &variableB;

    // TO swap the value we
    // Add A to B -> 3+6=9 and save to A
    // remove B from A -> 9-6=3 and save it to B
    // finally remove again B from A -> 9-3=6
    // and voilà we swap the value !
    *pointerToVariableA = *pointerToVariableA + *pointerToVariableB;
    *pointerToVariableB = *pointerToVariableA - *pointerToVariableB;
    *pointerToVariableA = *pointerToVariableA - *pointerToVariableB;

    printf("%d %d", variableA, variableB);
}