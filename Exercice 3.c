#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int integer;
    struct node *next;
} node;

node *head = NULL;

void prepend(int integer) {
    node *newElem = malloc(sizeof(node));
    newElem->integer = integer;
    if(head != NULL) {
        newElem->next = head;
    } else {
        newElem->next = NULL;
    }
    head = newElem;
}

void show() {
    node *loopElem = head;
    for (int loopThroughNode = 0; loopElem != NULL; ++loopThroughNode) {
        printf("Elem %d : %d\n", loopThroughNode, loopElem->integer);

        loopElem = loopElem->next;
    }
}

void delete(int integer) {
    node *searchElem = head;
    node *searchElemPenultimate = NULL;
    while(searchElem != NULL && searchElem->integer != integer) {
        searchElemPenultimate = searchElem;
        searchElem = searchElem->next;
    }

    if(searchElem != NULL) {
        if(searchElemPenultimate != NULL && searchElem->next != NULL) {
            searchElemPenultimate->next = searchElem->next;
        } else if(searchElemPenultimate != NULL) {
            searchElemPenultimate->next = NULL;
        } else if(searchElemPenultimate == NULL && searchElem->next == NULL){
            head = NULL;
        } else {
            head = searchElem->next;
        }
        free(searchElem);
    }
}

int main(void) {
    prepend(2);
    prepend(12);
    prepend(24);
    show();
    delete(2);
    show();

    return 0;
}