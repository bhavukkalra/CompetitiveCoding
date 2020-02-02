#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



struct node
{
	int value;
	node *next;
};

node *head = NULL;

node *insert(int n)
{
	if(head == NULL)
	{
		node *temp = new node;
		temp -> value = n;
		temp->next = NULL;
		head = temp;
		
		
	}
	else
	{
		node *temp = new node;
		temp -> value = n;
		temp->next = NULL;
		node *itr = head;
		while(itr -> next != NULL)
		{
			itr = itr->next;
		}
		itr ->next = temp; 
		
	}
}

void show()
{
	node *itr = head;
	while(itr -> next != NULL)
	{
		cout << itr -> value;
		itr = itr -> next;	
	}
	cout << itr->value;
}

//seperate for first and last

node *insert(int n,int position)
{
	if(position == 1)
	{
		node *temp = new node;
		temp->value = n;
		temp->next = head;
		head = temp;
		
		
	}
	else
	{
	node *itr = head;
	int count = position-2;
	while(count--)
	{
		itr = itr->next;
	}
	
	node *temp = new node;
	temp->value = n;
	temp ->next = itr->next;
	itr ->next = temp;
	}

}

node *delete1(int position)
{
	if(position == 1)
	{
		head = head->next;
		
		
		
	}
	else
	{
	node *itr = head;
	int count = position-2;
	while(count--)
	{
		itr = itr->next;
	}
	itr->next = (itr->next)->next;	
	}
	
	
}
bool search1(int number)
{
	node *itr = head;
	while(itr -> next != NULL)
	{
		if(itr->value == number)
		return 1;
		itr = itr->next;	
	}
	
	if(itr->value == number)
	return 1;
//  else
	return 0;	
}
// linked list in a class 
// pass pointer to pointer for head
// pointer defined in main not in global
node* reverse_linked_list()
{
    node *prev = NULL;
    node *next = NULL;
    node *current_iterator = head;
    while(current_iterator != NULL)
    {
        next = current_iterator -> next;
        current_iterator -> next = prev;
        prev = current_iterator;
        current_iterator = next;
    }

    return prev;




}
int main() 
{
	insert(1);
	insert(2);
	insert(3);
    insert(6);
    show();
    cout << endl;
    head = reverse_linked_list();
    cout << endl;
	
	show();
	
	
	
	

	
}