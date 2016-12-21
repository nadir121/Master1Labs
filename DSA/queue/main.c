#include <stdio.h>
#include <stdlib.h>



#define MAXSIZE 100
int size=0;

struct Node {
	char* firstName;
    char* lastName;
	int age;	//stores the age
	struct Node* next;    //used to point to the next List
};

//typedef struct Node* mylist;

int main()
{
    struct Node *l = new Node;
	init(l);
	menu(l);
	return 0;
}


//initialize the list
void init(mylist *l){
	l=NULL;
}

//insert a given name on the top of the stack
void add(mylist *l,char* fName, char* lName, int _age){
	if (size >= MAXSIZE)
	{
		//cout<< "The Stack is full!"<<endl;
		printf("The Stack is full!\n");
		return;
	}

	//creating the new List
    mylist lst = new Node;   //creating the new List
    mylist temp = l;

	//initializing the new List
    lst->firstName = fName;
	lst->lastName = lName;
	lst->age = _age;

	lst->next = temp;
    l=lst;
	size++;
}

//delete the name on the top of the stack
void remove(mylist *l)
  {
        if ( size==0) {
			//cout<< "The stack is empty! \n";
			printf("The stack is empty! \n");
			return;
		}

        mylist temp = l;
		mylist pr=temp;
		temp= temp->next;
		while(temp->next!=NULL){
			temp= temp->next;
			pr=pr->next;
		}
		delete temp;
		pr->next=0;
		size--;
		//l = temp;
		return;

}//remove


//traverse the stack (forward)
void forward(mylist l){
	mylist temp = l;
	while(temp != NULL) {
		//cout << "Name: "<<temp->firstName <<" "<<temp->lastName <<" Age: "<<temp->age << endl;
		printf("%s %s age:%d",temp->firstName, temp->lastName, temp->age);
		temp = temp->next;
   }
}//forward


//traverse the stack (backward)
void backward(mylist l){
	mylist temp = l;
	if(temp == NULL) return;
	backward(temp->next);
	//cout << "Name: "<<temp->firstName <<" "<<temp->lastName <<" Age: "<<temp->age << endl;
	printf("%s %s age:%d",temp->firstName, temp->lastName, temp->age);
}//backward


void menu(mylist l)
{
   char choice;
   //string fname,lname; //store the entered names
   char fname [99][15];
   char lname [99][15];
   int age;//store the age
   int i=0;

   while(1)
   {
    cout <<"\nMENU\n";
    cout <<"1)Insert a new name\n";
    cout <<"2)Delete a name\n";
    cout <<"4)Forward listing\n";
    cout <<"5)Backward listing \n";
    cout <<"6)Exit\n";
	//get the choice
	//cout <<">> ";
    //cin >> choice;
	scanf("%d",&choice);
    switch(choice)
    {
		case '1':
            //cout <<"Enter the first name:";
			printf("Enter the first name:");
			scanf("%s",&fname[i]);
            //cin >> fname;
			//cout <<"Enter the first name:";
            //cin >> lname;
			printf("Enter the last name:");
			scanf("%s",&lname[i]);
            //cout <<"Enter the age:";
			//cin >> age;
			printf("Enter the age:");
			scanf("%d",&age);
			add(l, fname, lname, age);
        break;

		case '2':
           remove(l);
        break;

		case '4':
            forward(l);
        break;

        case '5':
            backward(l);
        break;

		case '6':
            exit(0);
        break;

        default :
                //cout <<"Wrong choice!"<<endl;
				printf("Wrong choice!");
        break;
    }
   }
}
