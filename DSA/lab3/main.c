#include <stdio.h>

struct node
{
    char* firstName;
    char* lastName;
    int age;
    struct node* next;
};

/*
    init the stack
*/
void init(struct node* head)
{
    head = NULL;
    printf("stack initialized\n");
}

/*
    push an element into stack
*/
struct node* push(struct node* head, char* firstName, char*lastName, int age)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    if(tmp == NULL)
    {
        exit(0);
    }
    tmp->firstName = firstName;
    tmp->lastName = lastName;
    tmp->age = age;
    tmp->next = head;
    head = tmp;
    return head;
}
/*
    pop an element from the stack
*/
struct node* pop(struct node *head)
{
    struct node* tmp = head;
    head = head->next;
    free(tmp);
    return head;
}
/*
    returns 1 if the stack is empty, otherwise returns 0
*/
int empty(struct node* head)
{
    return head == NULL ? 1 : 0;
}

/*
    display the stack content
*/
void display(struct node* head)
{
    struct node *current;
    current = head;
    if(current!= NULL)
    {
        printf("Stack: ");
        do
        {
            /*printf("first name: %s ",current->firstName);
            printf("\t last name: %s ",current->lastName);
            printf("\t age: %d\n ",current->age);*/
            printf("%s %s age:%d\n",current->firstName, current->lastName, current->age );
            current = current->next;
        }
        while (current!= NULL);
        printf("\n");
    }
    else
    {
        printf("The Stack is empty\n");
    }

}
void displayReverse(struct node* head)
{
    // Base case
    if (head == NULL)
       return;

    // print the list after head node
    displayReverse(head->next);

    // After everything else is printed, print head
    printf("%s %s age:%d\n",head->firstName, head->lastName, head->age );
}
int main()
{
    struct node* head = NULL;
    int age, choice;
    char first[99][15];
    char last[99][15];
    int i=0,j=0;
    int size;
    printf("enter the size of the stack:");
    scanf("%d",&size);
//restart: init(head);
start:   printf("MENU:\n");
    printf("1)initialize stack\n");
    printf("2) Add a person to the stack\n");
    printf("3) Remove the top item\n");
    printf("4) Read from first to last\n");
    printf("5) Read from last to first\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
          //goto restart;
          init(head);
          break;
      case 2:
      if (j<size){
          printf("--- Pushing elements into the linked stack ---\n");
          printf("Enter the first name: ");
          scanf("%s",&first[i]);
          printf("Enter the last name: ");
          scanf("%s",&last[i]);
          printf("Enter the age: ");
          scanf("%d",&age);
          head = push(head,first[i],last[i],age);
          i++;
          j++;
      }
      printf("stack is full!\n");

          break;
      case 3:
          printf("--- Poping elements from the stack --- \n");
          printf("Poping %s %s age:%d stack\n",head->firstName, head->lastName, head->age);
          head = pop(head);
          j--;
          break;
      case 4:
          display(head);
          break;
      case 5:
          displayReverse(head);
          break;
      default:
          printf("Wrong choice");
    }
    goto start;
    return 0;
}
