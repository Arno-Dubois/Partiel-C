#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Personne and their attribute
typedef struct Personne{
    char name[25];
    int age;
    int size_cm;
}Personne;

Personne *list[4];

void createFourPersonne(){
    Personne *allain = malloc(sizeof(Personne));
    list[0] = allain;
    allain->age = 12;
    strcpy(allain->name, "Allain");
    allain->size_cm = 240;

    Personne *polin = malloc(sizeof(Personne));
    list[1] = polin;
    polin->age = 35;
    strcpy(polin->name, "Polin");
    polin->size_cm = 124;

    Personne *remis = malloc(sizeof(Personne));
    list[2] = remis;
    remis->age = 84;
    strcpy(remis->name, "Remis");
    remis->size_cm = 320;

    Personne *carmen = malloc(sizeof(Personne));
    list[3] = carmen;
    carmen->age = 2;
    strcpy(carmen->name, "Carmen");
    carmen->size_cm = 23;
}

void showAllPersonne() {
    for (int loopThroughPersonne = 0; loopThroughPersonne < 4; ++loopThroughPersonne) {
        printf("%s, %dans pour %dcm\n", list[loopThroughPersonne]->name, list[loopThroughPersonne]->age, list[loopThroughPersonne]->size_cm);

    }
}

int main(void) {
    createFourPersonne();
    showAllPersonne();

    return 0;
}
