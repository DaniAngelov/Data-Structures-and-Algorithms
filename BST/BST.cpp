// github.com/DaniAngelov

#include <iostream>
using namespace std;

long long counter = 0;



struct Node
{
    Node *left;
    Node *right;
    long long value;
    Node(long long value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

struct BST
{
    Node* root = NULL;

    Node* getRoot()
    {
        return root;
    }

    
    Node* find(Node* curNode, long long value)
    {
        

        if (curNode == NULL)
            return NULL;

        if (curNode->value == value)
        {
            return curNode;
            
        }
         if (curNode->value < value)
        {
            
            counter++;
            return find(curNode->right, value);
        }
         if(curNode->value > value)
        {
            
            counter++;
            return find(curNode->left, value);
        }

        return curNode;
    }


    Node* insert(Node *curNode, long long value)
    {
        if (this->root == NULL)
        {
            this->root = new Node(value);
            return this->root;
        }
        if (curNode == NULL)
        {
            return new Node(value);
        }
        if (curNode->value < value)
        {
            curNode->right = insert(curNode->right, value);
        }
        else if(curNode->value > value) 
        {
            curNode->left = insert(curNode->left, value);
        }
        return curNode;
    }


    void printSorted(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        if(root->left != NULL)
        

        printSorted(root->left);
        cout << root->value << " " ;

        printSorted(root->right);
    }

    
};

int main()
{

    BST tree;

  
    int _;
    cin >> _;
    return 0;

}
