#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Car and their data, for others comments see "Exercice 3.c"
typedef struct car {
    char brand[25];
    char model[25];
    int launchYear;
    struct car *next;
} car;

car *head = NULL;

void addCar(char brand[], char model[], int launchYear) {
    car *newCar = malloc(sizeof(car));
    strcpy(newCar->brand, brand);
    strcpy(newCar->model, model);
    newCar->launchYear = launchYear;
    if(head != NULL) {
        newCar->next = head;
    } else {
        newCar->next = NULL;
    }
    head = newCar;
}

void showAllCar() {
    car *loopCar = head;
    for (int loopThroughCar = 0; loopCar != NULL; ++loopThroughCar) {
        printf("La %s, modele %s est sortie en %d\n", loopCar->brand, loopCar->model, loopCar->launchYear);

        loopCar = loopCar->next;
    }
}

void deleteCar(char model[]) {
    car *searchCar = head;
    car *searchCarPenultimate = NULL;
    while(searchCar != NULL && strcmp(searchCar->model, model) != 0) {
        searchCarPenultimate = searchCar;
        searchCar = searchCar->next;
    }

    if(searchCar != NULL) {
        if(searchCarPenultimate != NULL && searchCar->next != NULL) {
            searchCarPenultimate->next = searchCar->next;
        } else if(searchCarPenultimate != NULL) {
            searchCarPenultimate->next = NULL;
        } else if(searchCarPenultimate == NULL && searchCar->next == NULL){
            head = NULL;
        } else {
            head = searchCar->next;
        }
        free(searchCar);
    }
}

int main(void) {
    addCar("Toyota", "Cactus", 2002);
    addCar("Dacia", "Sandero", 2022);
    addCar("Porch", "GTI", 2016);
    showAllCar();
    deleteCar("Cactuseu");
    showAllCar();

    return 0;
}