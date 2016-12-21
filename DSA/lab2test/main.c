/* Program to insert in a sorted list */
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
    char * data;
    struct node* next;
};
struct node* head = NULL;

/* function to insert a new_node in a list. Note that this
  function expects a pointer to head_ref as this can modify the
  head of the input linked list (similar to push())*/
void sortedInsert(struct node** head_ref, struct node* new_node)
{
    struct node* current;
    /* Special case for the head end */
    if (*head_ref == NULL || strcmp((*head_ref)->data, new_node->data)>=0)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = *head_ref;
        while (current->next!=NULL &&
               strcmp(current->next->data , new_node->data)<0)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

/* BELOW FUNCTIONS ARE JUST UTILITY TO TEST sortedInsert */

/* A utility function to create a new node */
struct node *newNode(char * new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));

    /* put in the data  */
    new_node->data  = new_data;
    new_node->next =  NULL;

    return new_node;
}

/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%s  ", temp->data);
        temp = temp->next;
    }
}
int main( int argc, char * argv[] )
{

    int choice;
    char * user;
    int k=1;
do {
	start:
printf("choose an option: \n");
printf("1) insert a new name \n");
printf("2) delete a names from position p \n");
printf("3) search for a names \n");
printf("4) traverse the list from first to last \n");
printf("5) traverse the list from last to first \n");
printf("6) exit \n");
scanf("%d", &choice);
if (choice == 1)
{


    struct node *new_node = newNode("aa");
    sortedInsert(&head, new_node);

    new_node = newNode("rr");
    sortedInsert(&head, new_node);
    new_node = newNode("ab");
    sortedInsert(&head, new_node);
    new_node = newNode("ca");
    sortedInsert(&head, new_node);
    new_node = newNode("ff");
    sortedInsert(&head, new_node);
    /*new_node = newNode("cc");
    sortedInsert(&head, new_node);
    new_node = newNode("de");
    sortedInsert(&head, new_node);
    new_node = newNode("ff");
    sortedInsert(&head, new_node);
    new_node = newNode("rr");
    sortedInsert(&head, new_node);
    */
     /*printf("enter  names1: \n");
    scanf("%s", &user);

    struct node *new_node = newNode(&user);
    sortedInsert(&head, new_node);

    while(strcmp(&user,"end")!=0){
     printf("enter a name2: \n");
     scanf("%s", &user);
     printf("%s ---\n", user);
     struct node *new_node = newNode(&user);
    sortedInsert(&head, new_node);}*/
    /* struct node *new_node = newNode("bb\0");
    sortedInsert(&head, new_node);

    new_node = newNode("rr\0");
    sortedInsert(&head, new_node);
    new_node = newNode("ab\0");
    sortedInsert(&head, new_node);
    new_node = newNode("ca\0");
    sortedInsert(&head, new_node);
    new_node = newNode("ff\0");
    sortedInsert(&head, new_node);*/
}
else if(choice ==2)
{

}
else if(choice ==3)
{

}
else if(choice ==4)
{
	printList(head);
}
else if(choice ==5)
{

}
else if(choice ==6)
{
	goto endd;
}
else goto start;
}while(1);
endd: return 0;
}
/* Drier program to test count function*/
/*int main()
{
    // Start with the empty list
    struct node* head = NULL;
    struct node *new_node = newNode("ab");
    sortedInsert(&head, new_node);
    new_node = newNode("ba");
    sortedInsert(&head, new_node);
    new_node = newNode("cc");
    sortedInsert(&head, new_node);
    new_node = newNode("de");
    sortedInsert(&head, new_node);
    new_node = newNode("ff");
    sortedInsert(&head, new_node);
    new_node = newNode("rr");
    sortedInsert(&head, new_node);
    printf("\n Created Linked List\n");
    printList(head);

    return 0;
}*/
