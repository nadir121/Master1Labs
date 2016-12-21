#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct person {
  char * firstName;
  char * lastName;
  int age;
};
struct person *pers=NULL;
// Defining the stack structure
struct stack {
   struct person* head;
   int top;
   struct stack* next;
};
struct stack* st=NULL;

struct person *newPerson(char * first_name, char * last_name, int new_age)
{
    printf("entered new person\n");
    /* allocate node */
    struct person* new_person =
        (struct person*) malloc(sizeof(struct person));

    /* put in the data  */
    new_person->firstName  = first_name;
    new_person->lastName =  last_name;
    new_person->age = new_age;
    printf("exiting new person\n");
    return new_person;
}
// Initializing the stack(i.e., top=-1)
/*void init_stk(struct stack *st) {
   st->top = -1;
}*/

// Entering the elements into stack
/*void push(struct stack *st, struct person *per) {
   if (st->top == size - 1) {
      printf("\nStack overflow(i.e., stack full).");
      return;
   }
   st->top++;
   st->arr[st->top] = *per;
}*/
void push(struct stack ** st, struct person* per) {
    printf("entered push \n");
    struct stack * stt;
    stt = malloc(sizeof(struct stack));

    stt->head = per;
    stt->next = *st;
    *st = stt;
    printf("exiting push");
}

//Deleting an element from the stack.
/*void pop(struct stack *st) {
   struct person *per;
   if (st->top == -1) {
      printf("\nStack underflow(i.e., stack empty).");
      return NULL;
   }
   *per = st->arr[st->top];
   st->top--;
   printf("item deleted: first name: %s\t",per->firstName );
   printf("last name: %s\t",per->lastName );
   printf("age: %d\n",per->age );
}*/
void pop(struct stack ** st) {
    printf("entered pop\n");
    struct stack * next_s = NULL;

    if (*st == NULL) {
        printf("stack's empty bro!");
    }

    next_s = (*st)->next;
    //retval = (*head)->val;
    printf("item deleted: first name: %s\t",(*st)->head->firstName );
    printf("last name: %s\t",(*st)->head->lastName );
    printf("age: %d\n",(*st)->head->age );
    free(*st);
    *st = next_s;

}
void display(struct stack * st) {
    printf("entered display\n");
    struct stack * current = st;

    while (current != NULL) {
        printf("first name: %s\t",st->head->firstName );
        printf("last name: %s\t",st->head->lastName );
        printf("age: %d\n",st->head->age );
        current = current->next;
    }
}

/*void display(struct stack **st) {
   int i;
   struct person *per;
   for (i = st->top; i >= 0; i--){
      *per=st->arr[i];
      printf("first name: %s\t",per->firstName );
      printf("last name: %s\t",per->lastName );
      printf("age: %d\n",per->age );
    }

}*/

int main() {
   int  opt;
   char * ufname;
   char * ulname;
   int * uage;
  // struct stack* st;
   //person top;
   //init_stk(&ptr);
   while (1) {
      printf("\n\ntSTACK PRIMITIVE OPERATIONS");
      printf("\n1.PUSH");
      printf("\n2.POP");
      printf("\n3.DISPLAY");
      printf("\n4.QUIT");
      printf("\n");
      printf("\nEnter your option : ");
      scanf("%d", &opt);
      switch (opt) {
      case 1:

         printf("\nEnter the first name into stack:");
         scanf("%s", &ufname);
         printf("\nEnter the last name into stack:");
         scanf("%s", &ulname);
         printf("\nEnter the ageinto stack:");
         scanf("%d", &uage);
         struct person* perso = newPerson(ufname,ulname,uage);
         push(&st, perso);
         break;
      case 2:
         pop(&st);
         break;
      case 3:
         printf("\nThe current stack elements are:");
         display(st);
         break;
      case 4:
         exit(0);
      default:
         printf("\nEnter correct option!Try again.");
      }
   }
   return (0);
}
