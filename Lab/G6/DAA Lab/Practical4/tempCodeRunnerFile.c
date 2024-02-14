#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node {
    int x,y;
    char name[50];
};

int totalNodes = 0;
struct Node cityDB[100];

void insertCity(char name[50], int x, int y) {
    
    if(totalNodes == 100) {
        printf("City Database is full\n");
        return;
    }

    strcpy(cityDB[totalNodes].name, name);
    cityDB[totalNodes].x = x;
    cityDB[totalNodes].y = y;
    totalNodes++;

}

void printCityDB() {
    
    for(int i = 0; i < totalNodes; i++) {
        printf("City: %s, XCoord: %d, YCoord: %d\n", cityDB[i].name, cityDB[i].x, cityDB[i].y);
    }

}

int findByName(char name[50]) {
    
    for(int i = 0; i < totalNodes; i++) {
        if(strcmp(cityDB[i].name, name) == 0) {
            printf("City: %s, XCoord: %d, YCoord: %d\n", cityDB[i].name, cityDB[i].x, cityDB[i].y);
            return i;
        }
    }

    return -1;

}

int findByCoord(int x, int y) {
    
    for(int i = 0; i < totalNodes; i++) {
        if(cityDB[i].x == x && cityDB[i].y == y) {
            printf("City: %s, XCoord: %d, YCoord: %d\n", cityDB[i].name, cityDB[i].x, cityDB[i].y);
            return i;
        }
    }

    return -1;

}

void deleteCityByName(char name[50]) {
    
    int index = findByName(name);

    if(index == -1) {
        printf("City not found\n");
        return;
    }

    for(int i = index; i < totalNodes - 1; i++) {
        cityDB[i] = cityDB[i + 1];
    }

    totalNodes--;

}

void deleteCityByCoord(int x, int y) {
    
    int index = findByCoord(x, y);

    if(index == -1) {
        printf("City not found\n");
        return;
    }

    for(int i = index; i < totalNodes - 1; i++) {
        cityDB[i] = cityDB[i + 1];
    }

    totalNodes--;

}

double getDistance(int x1, int y1, int x2, int y2) {
    
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

}

void printCityUnderDistance(int x, int y, double distance) {
    
    for(int i = 0; i < totalNodes; i++) {
        if(getDistance(x, y, cityDB[i].x, cityDB[i].y) <= distance) {
            printf("City: %s, XCoord: %d, YCoord: %d\n", cityDB[i].name, cityDB[i].x, cityDB[i].y);
        }
    }

}

int main() {
    
    int choice;
    char name[50];
    int x, y;
    double distance;

    printf("\n Enter your choice from the menu \n");

    while(1) {
        
        printf("1. Insert City\n");
        printf("2. Print City Database\n");
        printf("3. Find City by Name\n");
        printf("4. Find City by Coordinates\n");
        printf("5. Delete City by Name\n");
        printf("6. Delete City by Coordinates\n");
        printf("7. Print Cities under Distance\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the city: ");
                scanf("%s", name);
                printf("Enter the x coordinate of the city: ");
                scanf("%d", &x);
                printf("Enter the y coordinate of the city: ");
                scanf("%d", &y);
                insertCity(name, x, y);
                break;
            case 2:
                printCityDB();
                break;
            case 3:
                printf("Enter the name of the city: ");
                scanf("%s", name);
                findByName(name);
                break;
            case 4:
                printf("Enter the x coordinate of the city: ");
                scanf("%d", &x);
                printf("Enter the y coordinate of the city: ");
                scanf("%d", &y);
                findByCoord(x, y);
                break;
            case 5:
                printf("Enter the name of the city: ");
                scanf("%s", name);
                deleteCityByName(name);
                break;
            case 6:
                printf("Enter the x coordinate of the city: ");
                scanf("%d", &x);
                printf("Enter the y coordinate of the city: ");
                scanf("%d", &y);
                deleteCityByCoord(x, y);
                break;
            case 7:
                printf("Enter the x coordinate of the city: ");
                scanf("%d", &x);
                printf("Enter the y coordinate of the city: ");
                scanf("%d", &y);
                printf("Enter the distance: ");
                scanf("%lf", &distance);
                printCityUnderDistance(x, y, distance);
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}