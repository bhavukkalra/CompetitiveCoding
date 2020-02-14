/*
COMMON MISTAKE -
next node has a prev too 
which needs to be taken care of
*/


#include <iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
};

void push(Node **head_ref, int new_data)
{
    // new node added in front and first node's
    //prev is always null
    // could also be written like this
    /*
    Node *new_node = new Node();
        new_node -> data = new_data;
        new_node -> next = *head_ref;
        new_node -> prev = NULL;
    */
    if(*head_ref == NULL)
    {
        
        Node *new_node = new Node();
        new_node -> data = new_data;
        new_node -> next = *head_ref;
        new_node -> prev = NULL;
        (*head_ref) = new_node;
    }
    else
    {
        Node *new_node = new Node();
        new_node -> data = new_data;
        new_node -> next = *head_ref;
        new_node -> prev = NULL;
        (*head_ref) -> prev = new_node;
        (*head_ref) = new_node;
    }

    // (*head_ref) = new_node;(possibility)
}


void insertAfter(Node *prev_node, int value)
{
    if(prev_node == NULL)
    {
        cout << "prev node can't be empty use push method instead";
        return;
    }

    Node *new_node = new Node();
    new_node -> next = prev_node -> next;
    new_node -> prev = prev_node;
    new_node -> data = value;
    prev_node -> next = new_node;


    // most importtant bit
    if(new_node -> next != NULL)
    {
        (new_node -> next) ->prev = new_node;
    }
    return;
} 

void addToEnd(Node **head_ref, int value)
{
    Node* new_node = new Node();
    new_node -> next = NULL;
    new_node -> data = value;
    
    if(*head_ref == NULL)
    {
        new_node -> prev = NULL;
        *head_ref = new_node;
        return;
    }
    // if ll is not empty

    Node *itr = *head_ref;
    while(itr -> next != NULL)
    {
        itr = itr -> next;
    }
    // itr is at last now

    itr -> next = new_node;

    // VV IMPT IN doubly LL
    new_node -> prev = itr;
    return;

}

void printlist(Node *head)
{
    // head is a temp variable
    // don't use head as a global variable

    if(head == NULL)
    {
        cout << "list is empty";
        return;
    }
    while(head -> next != NULL)
    {
        cout << head -> data << " ";
        head = head -> next;
    }
    // print the last node as well
    cout << head -> data << endl;
    return;



}

void deleteNode(Node **head_ref, Node *key)
{
    if(*head_ref == NULL || key == NULL)
    {
        cout << "invalid input";
        return;
        
    }
    if(*head_ref == key)
    {
        head_ref = key -> next;
    }

    // IF IN THE MIDDLE THEN
    // BOTH IF CONDITIONS RUN
    if(key->next != NULL)
    {
        (key->next)->prev = key -> prev;
    }
    // if it is the last node
    if(key -> prev != NULL)
    {
        key->prev->next = key -> next;
    }


    free(key);
    return;
}


int main()
{
    // create a Node object
    Node *head = new Node();

    // push is in front of the node
    push(&head,5);
    push(&head,1);
    push(&head,2);
    addToEnd(&head,7);
    addToEnd(&head,1);
    addToEnd(&head,6);
    printlist(head);

    



}