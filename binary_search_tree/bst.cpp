#include <iostream>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
};

node *newnode(int data)
{
    node *temp = new node;
    temp -> key = data;
    temp -> left = temp -> right = NULL;
    return temp;

    // other implementation using malloc
    /*
    struct node *temp = (node *)malloc(sizeof(node));
    temp -> key = data;
    temp -> left = temp -> right = NULL;
    return temp;
    */
}


node *insert(node *node, int data)
{
    // base case
    if(node == NULL)
    {
        return newnode(data);
    }

    if(data <= node -> key)
    {
        node -> left = insert(node -> left,data);
    }
    else
    {
        node -> right = insert(node -> right,data);
    }
}


// in order successor or
// in order predecessor

// assumed we are being sent the right side node of the node
// to be deleted 
// find the smallest from right node
node *inorder_successor(node *right_node)
{
    node *temp = right_node;
    while(temp -> left != NULL)
    {
        temp = temp -> left;
    }
    return temp;
    
}

// NOTE - SHORTEST IN RIGHT SUBTREE WILL NOT HAVE ANY left node
// NOTE - LARGEST IN LEFT SUBTREE WILL NOT HAVE ANY right node


node *deletenode(node *root, int data)
{
    if(root == NULL)
    return root;
    else if(data < root -> key)
    {
        // when recursion unfolds the links are coorected here
        root -> left = deletenode(root -> left,data);
    }
    else if(data > root -> key)
    {
        root -> right = deletenode(root-> right, data);
    }
    // wohoo....found you now get ready to be deleted!!!
    else
    {
        // case 1 -  no child
        if(root -> left == NULL && root -> right == NULL)
        {
            free (root);
            // now root is a dangling pointer
            root = NULL;
            return root;
        } 
        // case 2 - one child
        if(root -> left == NULL)
        {
            // store the data to be deleted
            node *temp = root;
            root = root -> right;
            free (temp);
            return root;
        }
        else if(root -> right == NULL)
        {
            node *temp = root;
            root = root -> left;
            free (temp);
            return root;
        }
        // case 2 - two childs  
        // in order predecessor used
        else
        {
            node *temp = inorder_successor(root -> right);
            root -> key = temp -> key;
            // replacing the node to be deleted with smallest from right

            root -> right = deletenode(root -> right,temp ->key);
            // delete the repetition node and store the address of next node
            // of minimum in right
            return root;

        }   
       //  return root;
       // could be written outside
    }
}

void inorder_traversal(node *root)
{
    if(root != NULL)
    {
        // print the left for me
        inorder_traversal(root -> left);
        cout << root -> key << endl;
        // i can print the center key
        inorder_traversal(root -> right);
        // also print the right for me
    }

}
void preorder_traversal(node *root)
{
    if(root != NULL)
    {

        cout << root -> key << endl;
       
        preorder_traversal(root -> left);
        preorder_traversal(root -> right);
        
    }
    
}
void postorder_traversal(node *root)
{
    if(root != NULL)
    {
        
        
        
        post_traversal(root -> left);
        post_traversal(root -> right);
        cout << root -> key << endl;
       
    }
    
}



// in order traversal
int main()
{
   




}