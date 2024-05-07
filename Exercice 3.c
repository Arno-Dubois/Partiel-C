#include <stdio.h>
#include <stdlib.h>

// Define Node and their data
typedef struct node {
    int integer;
    struct node *next;
} node;

// Define head
node *head = NULL;

void prependToNode(int integer) {
    // Allocate memory to new element
    node *newElement = malloc(sizeof(node));
    
    // Store data to new element
    newElement->integer = integer;
    
    // Replace head by the new element and link the new element to the last element
    if(head != NULL) {
        newElement->next = head;
    } else {
        newElement->next = NULL;
    }
    head = newElement;
}

void showAllNode() {
    node *loopElement = head;
    for (int loopThroughNode = 0; loopElement != NULL; ++loopThroughNode) {
        printf("Element %d : %d\n", loopThroughNode, loopElement->integer);

        loopElement = loopElement->next;
    }
}

void deleteElement(int integer) {
    node *searchElement = head;
    node *searchElementPenultimate = NULL;
    while(searchElement != NULL && searchElement->integer != integer) {
        searchElementPenultimate = searchElement;
        searchElement = searchElement->next;
    }

    if(searchElement != NULL) {
        // If there is element before and after element to deleteElement, link them together
        if(searchElementPenultimate != NULL && searchElement->next != NULL) {
            searchElementPenultimate->next = searchElement->next;
        
        // If there is no element before remove the link
        } else if(searchElementPenultimate != NULL) {
            searchElementPenultimate->next = NULL;
            
        // If there is no more element nullify the head
        } else if(searchElementPenultimate == NULL && searchElement->next == NULL){
            head = NULL;
            
        // If the element to deleteElement is the head, change the head
        } else {
            head = searchElement->next;
        }
        free(searchElement);
    }
}

int main(void) {
    prependToNode(2);
    prependToNode(12);
    prependToNode(24);
    showAllNode();
    deleteElement(2);
    showAllNode();

    return 0;
}