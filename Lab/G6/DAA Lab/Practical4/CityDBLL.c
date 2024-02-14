#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

struct Node {
    int x,y;
    char name[50];
    struct Node*next;
};

float getDistance(int x1,int x2,int y1,int y2) {

    int p1 = x2-x1;
    int p2 = y2-y1;

    return sqrt(pow(p1,2)+pow(p2,2));

}

struct Node* createNode(int x, int y, char name[50]) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> x = x;
    newNode -> y = y;
    strcpy(newNode->name,name);
    newNode -> next = NULL;
    return newNode;

}

struct Node* addNode(int x, int y ,char name[50], struct Node* head) {

    struct Node* temp = createNode(x,y,name);

    if(head == NULL) {
        head = temp;
        return head;
    }

    temp -> next = head;
    head = temp;

    return head;
}

void printLL(struct Node* head){

    struct Node* temp = head;
    
    while (temp != NULL){
        
        printf("%s ->", head -> name);
        temp = temp -> next;
    }

    printf("\n");
} 

int findByName(struct Node* head, char name[50]) {
    
    int counter = 0;
    int f = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        
        if(strcmp(temp -> name, name) == 0) {
            printf("City: %s, XCoord: %d, YCoord: %d", temp -> name, temp -> x, temp -> y);
            return counter;
        }

        counter++;

        temp = temp -> next;
    }

    if (f == 0) {
        printf("No such city found");
    }

    return -1;
}

int findByCoords(struct Node* head, int x, int y) {
    
    int counter = 0;
    int f = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        
        if(x == temp -> x && y == temp -> y) {
            printf("City: %s, XCoord: %d, YCoord: %d", temp -> name, temp -> x, temp -> y);
            return counter;
        }

        counter++;

        temp = temp -> next;
    }

    if (f == 0) {
        printf("No such city found");
    }

    return -1;
}

struct Node* deleteCityFromCords (int x, int y, struct Node* head){

    struct Node* curr = head;

    if(curr -> x == x && curr -> y == y){
        curr = curr -> next;
        return curr;
    } 
    while(curr->next != NULL){
        if(curr->next->x == x && curr->next->y == y){
            curr->next = curr->next->next;
            break;
        }
        curr = curr->next;
    }
    return curr;
}

struct Node* deleteCityByName(char name[],struct Node* head){
    
    struct Node* curr = head;
    
    if(strcmp(curr -> name,name) == 1){
        curr = curr->next;
        return curr;
    }

    while(curr->next!=NULL){

        if(!strcmp(curr->next->name,name)){
            curr->next = curr->next->next;
            break;
        }

        curr = curr->next;
    }
    return curr;
}

void printCityUnderDistance(int x, int y, int distance,struct Node*head){
    
    printf("\nName of the city under this distance are:\n");
    struct Node* temp = head;

    while(temp != NULL){
       
        if(getDistance(x,temp->x,y,temp->y) <= distance){
            
            if(temp->x!=x && temp->y!=y){
                printf("%s ",temp->name);
            }

        }

        temp = temp->next;
    }

}


int main(){

    struct Node* head = NULL;

    printf("\n Enter the option you want to execute \n");

    while(1) {
        printf("\n1. Insert a city.\n");
        printf("\n2. Print all cities.\n");
        printf("\n3. Find By Name.\n");
        printf("\n4. Find By Coords.\n");
        printf("\n5. Delete By Name.\n");
        printf("\n6. Delete By Coords.\n");
        printf("\n7. Print Cities under distance.\n");
        printf("\n8. Exit.\n");

        char name[50];
        int x,y;

        clock_t start, end;


        int option;
        printf("\n Enter the option you want to execute: ");
        scanf("%d", &option);

        switch(option) {

            case 1:

                printf("Enter the name of the city: ");
                scanf("%s", name);

                printf("Enter the x coordinate of the city: ");
                scanf("%d", &x);

                printf("Enter the y coordinate of the city: ");
                scanf("%d", &y);

                start = clock();
                head = addNode(x, y, name, head);
                end = clock();

                printf("Time taken to add a city: %f\n", (double)(end - start)/CLOCKS_PER_SEC);

                break;

            case 2:

                printLL(head);
                break;

            case 3:

                printf("Enter the name of the city: ");
                scanf("%s", name);

                start = clock();
                findByName(head, name);
                end = clock();

                printf("Time taken to find a city: %f\n", (double)(end - start)/CLOCKS_PER_SEC);

                break;

            case 4:

                printf("Enter the x coordinate of the city: ");
                scanf("%d", &x);

                printf("Enter the y coordinate of the city: ");
                scanf("%d", &y);

                start = clock();
                findByCoords(head, x, y);
                end = clock();

                printf("Time taken to find a city: %f\n", (double)(end - start)/CLOCKS_PER_SEC);

                break;

            case 5:

                printf("Enter the name of the city: ");
                scanf("%s", name);
                
                start = clock();
                head = deleteCityByName(name, head);
                end = clock();

                printf("Time taken to delete a city: %f\n", (double)(end - start)/CLOCKS_PER_SEC);
                break;

            case 6:

                printf("Enter the x coordinate of the city: ");
                scanf("%d", &x);

                printf("Enter the y coordinate of the city: ");
                scanf("%d", &y);

                start = clock();
                head = deleteCityFromCords(x, y, head);
                end = clock();

                printf("Time taken to delete a city: %f\n", (double)(end - start)/CLOCKS_PER_SEC);

                break;

            case 7:

                printf("Enter the x coordinate of the city: ");
                scanf("%d", &x);

                printf("Enter the y coordinate of the city: ");
                scanf("%d", &y);

                printf("Enter the distance: ");
                int distance;
                scanf("%d", &distance);

                start = clock();
                printCityUnderDistance(x, y, distance, head);
                end = clock();

                printf("Time taken to print cities under distance: %f\n", (double)(end - start)/CLOCKS_PER_SEC);
                
                break;

            case 8:
                
                return 0;
                break;

            default:

                printf("Invalid option");
                break;

        }
    }

    return 0;
}