#include <stdio.h>

struct node
{
    struct person* per;
    struct node* next;
};
struct person
{
    char* firstName;
    char* lastName;
    int age;
};

/*
    init the stack
*/
void init(struct node* head)
{
    head = NULL;
}

/*
    push an element into stack
*/
struct node* push(struct node* head, char* firstName, char*lastName, int age)
{
    printf("enter push\n");
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    printf("node\n");
    if(tmp == NULL)
    {
        printf("if\n");
        exit(0);
    }
    printf("enter variables\n");
    tmp->per->firstName = firstName;
    tmp->per->lastName = lastName;
    tmp->per->age = age;
    printf("vars\n");
    tmp->next = head;
    head = tmp;
    free(tmp);
    printf("exit push\n");
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
            printf("%s %s age:%d\n",current->per->firstName, current->per->lastName, current->per->age );
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
    printf("%s %s age:%d\n",head->per->firstName, head->per->lastName, head->per->age );
}
int main()
{
    struct node* head = NULL;
    int age, choice;
    char first[15];
    char last[15];
restart: init(head);
start:   printf("MENU:\n");
    printf("1)initialize stack (careful!)\n");
    printf("2) Add a person to the stack\n");
    printf("3) Remove the top item\n");
    printf("4) Read from first to last\n");
    printf("5) Read from last to first\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
          goto restart;
          break;
      case 2:
          printf("--- Pushing elements into the linked stack ---\n");
          printf("Enter the first name: ");
          scanf("%s",&first);
          printf("Enter the last name: ");
          scanf("%s",&last);
          printf("Enter the age: ");
          scanf("%d",&age);
          head = push(head,first,last,age);
          break;
      case 3:
          printf("--- Poping elements from the stack --- \n");
          printf("Poping %s %s age:%d stack\n",head->per->firstName, head->per->lastName, head->per->age);
          head = pop(head);
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
