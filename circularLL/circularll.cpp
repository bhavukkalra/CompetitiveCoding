#include <iostream>
using namespace std;

class Node
{
    public:
    int value;
    Node *next;
};

void push(Node **head_ref, int data)
{
    Node *new_node = new Node();
    new_node -> value = data;
    // new node pointing to first node
    new_node -> next = *head_ref;
    Node *itr = *head_ref;

    

    if(*head_ref != NULL)
    {
        while(itr -> next != *head_ref)
        {
            itr = itr -> next;
        }
        // itr at last node
        // attach new node to last node
        itr -> next = new_node;
    }
    else
    {
        new_node -> next = new_node;
        // pointing to itself i.e 
        // first node
        *head_ref = new_node;

        
    }
    




}

void cprintlist(Node **head_ref)
{
    Node *itr = *head_ref;
    if(*head_ref == NULL)
    cout << "list is empty";
    else
    {
        while(itr -> next != *head_ref)
        {
            cout << itr -> value << " ";
            itr = itr -> next;
        }
        
        cout << itr -> value; 
    }
}

void deleteNode(Node **head_ref,int key)
{
    // conditions to check 

    // if list is empty
    if(*head_ref == NULL)
        return;
    // if node is first node 
    if((*head_ref)->value == key && (*head_ref)->next == *head_ref)
    {
        free(*head_ref);
        *head_ref = NULL;
        return;
    } 
    // we want to delete the head but there are subsequent elements in it

    
    if((*head_ref) -> value == key)
    {
        Node *last = *head_ref;
        while(last -> next != *head_ref)
        {
            last = last -> next;
        }
        // linking last to second element
        last -> next = (*head_ref) -> next;
        free(*head_ref);
        // updating head ie linking it to second
        (*head_ref) = last -> next;
        free(last);
        return;
        
    }
    
    Node *itr = *head_ref;
    // regular node to be deleted
    // check if node is present and find out its position
    while(itr -> next != *head_ref && itr->next->value != key)
    {
        itr = itr -> next;
    }
    // either itr is at last of node if key is not found
    // or is at one node previous to where key is found
    // that node hast to be deleted


    // if key is found
    if(itr->next->value == key)
    {
        Node *temp_ref = itr -> next;
        itr -> next = temp_ref -> next;
        free(temp_ref);
        return;
    }
    // if key is not found
    else
    {
        cout << "key is not found";
        return;
        
    }
}

int countnodes(Node **head_ref)
{
    if(*head_ref == NULL)
    return 0;
    else
    {
        int count = 0;
        Node *itr = *head_ref;
        while(itr -> next != *head_ref)
        {
            count++;
            itr = itr -> next;
        }
        return count;
    }
}

Node *tocircular(Node **head_ref)
{
    Node *itr = *head_ref;
    while(itr->next != NULL)
    {
        itr = itr -> next;
    }
    itr -> next = *head_ref;
    return *head_ref;
}

int main()
{
    Node *head = NULL;
    push(&head,6);
    push(&head,7);
    push(&head,8);
    cprintlist(&head);



}


