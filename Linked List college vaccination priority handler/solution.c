#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
// Declaration of enum
// typedef enum { F, T } boolean;

struct Node{
    char instituteName[10];
    int YOB;
    char name[10];
    char relationship[10];
    struct Node *next;
};

void addPerson(struct Node** head, char *instituteName, int YOB, char *name, char *relationship){
    struct Node *newPersonNodePtr= (struct Node*)malloc(sizeof(struct Node));
    // printf("%s %d %s %s\n", instituteName, YOB, name, relationship);

    strcpy(newPersonNodePtr->instituteName, instituteName);
    newPersonNodePtr->YOB = YOB;
    strcpy(newPersonNodePtr->name, name);
    strcpy(newPersonNodePtr->relationship, relationship);

    newPersonNodePtr->next = NULL;

    if(*head == NULL){
        *head = newPersonNodePtr;
        printf("New person added to linked list\n");
        return;
    }

    struct Node *runningPtr=*head;
    while(runningPtr->next){
        runningPtr= runningPtr->next;
    }
    runningPtr->next = newPersonNodePtr;
    printf("New person added to linked list\n");
}

void dispResult(struct Node **head){
    struct Node *runningPtr=*head;

    // KLETU staff
    while(runningPtr){
        if(strcmp(runningPtr->instituteName, "KLETU")){
            printf("%s, %d, %s, %s", runningPtr->instituteName, runningPtr->YOB, runningPtr->name, runningPtr->relationship);
        }
        runningPtr= runningPtr->next;
    }

    // Relative of KLETU staff
    runningPtr=*head;
    while(runningPtr){
        if(strcmp(runningPtr->relationship, "YES")){
            printf("%s, %d, %s, %s\n", runningPtr->instituteName, runningPtr->YOB, runningPtr->name, runningPtr->relationship);
        }
        runningPtr= runningPtr->next;
    }

    // Others
    runningPtr=*head;
    while(runningPtr){
        if(strcmp(runningPtr->instituteName, "KLETU") && strcmp(runningPtr->relationship, "NO")){
            printf("%s, %d, %s, %s \n", runningPtr->instituteName, runningPtr->YOB, runningPtr->name, runningPtr->relationship);
        }
        runningPtr= runningPtr->next;
    }
}

void main()
{
    struct Node *head = NULL;
    int n;
    int i;
    char instituteName[10];
    int YOB;
    char name[10];
    char relationship[10];
    struct Node *next;

    printf("Enter Number os registration ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      printf("Enter details of student\n");
        scanf("%s %d %s %s", instituteName, &YOB, name, relationship);
        addPerson(&head, instituteName, YOB, name, relationship);
    }
    dispResult(&head);
}
