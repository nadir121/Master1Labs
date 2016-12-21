#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( int argc, char * argv[] )
{
int choice;
char * na;
typedef struct names {
	char * name ;
	struct names * next;
}names_t;
names_t * a=NULL;
/*printf("enter a list of namess it stops when you write end: \n");
scanf("%s", &na);
while( strcmp ( na, end )!=0){
	add_names(&a ,na);
}
*/
do{
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
	char * new;
	scanf("%s", &new);
	names_t * new_names = newname(&new);
	sortedInsert(&a, new_names);
}
else if(choice ==2)
{
	int p;
	printf("enter a position p \n");
	scanf("%d", &p);
	remove_by_index(&a, p);
}
else if(choice ==3)
{
	search(a);
}
else if(choice ==4)
{
	print_list(a);
}
else if(choice ==5)
{
	print_list_back(a);
}
else if(choice ==6)
{
	goto endd;
}
else goto start;
}while(1);
endd: return 0;
}
/*void add_names(names_t ** head,char * names){
	names_t * new_names;
	new_names = malloc(sizeof(names_t));

    new_names->names = names;
    new_names->next = *head;
    names_t *head = new_names;
}*/
/*void sortedInsert(names_t ** head_ref, names_t* new_names)
{
    names_t* current;
    /* Special case for the head end
    if (*head_ref == NULL || (*head_ref)->name >= new_names->name)
    {
        new_names->next = *head_ref;
        names_t *head_ref = new_names;
    }
    else
    {
        /* Locate the names before the point of insertion
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->name < new_names->name)
        {
            current = current->next;
        }
        new_names->next = current->next;
        current->next = new_names;
    }
}*/
void sortedInsert(struct node** head_ref, struct node* new_node)
{
    struct node* current;
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}
int remove_by_index(names_t ** head, int n) {
    int i = 0;
    int retname = -1;
    names_t * current = *head;
    names_t * temp_names = NULL;

    if (n == 0) {
        return pop(head);
    }

    for (int i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    temp_names = current->next;
    retname = temp_names->name;
    current->next = temp_names->next;
    free(temp_names);

    return retname;

}
int pop(names_t ** head) {
    int retname = -1;
    names_t * next_names = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_names = (*head)->next;
    retname = (*head)->name;
    free(*head);
    *head = next_names;

    return retname;
}
void print_list(names_t * head) {
    names_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->name);
        current = current->next;
    }
}
int search(names_t * head) {
    names_t * current = head;
	int i=0;
    while (current != NULL) {
        while{(strcmp(current->name, current->next->name)!=0)
        current = current->next;
		i++;}
    }
	return i;
}
names_t *newnames(char *new)
{
    /* allocate names */
    names_t* new_names = (names_t*) malloc(sizeof(struct names));

    /* put in the name  */
    new_names->name  = new;
    new_names->next =  NULL;

    return new_names;
}
