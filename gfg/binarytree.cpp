#include <iostream>
#include <queue>

using namespace std;

class BTNode
{
    public:
        int data;
        BTNode* Left;
        BTNode* Right;
};

BTNode* newNode (int data)
{
    BTNode* node = new BTNode();
    node->data = data;
    node->Left = NULL;
    node->Right = NULL;

    return node;
}

// Inorder (left->right) traversal
void inorder (BTNode* temp)
{
    if (!temp)
        return;
    
    inorder (temp->Left);
    cout << temp->data << " ";
    inorder (temp->Right);
}

void insert (BTNode* temp, int data)
{
    queue<BTNode*> q;
    q.push(temp);

    while(!q.empty())
    {
        BTNode* temp = q.front();
        
    }
}

int main ()
{
    BTNode* root = newNode(1);

    root->Left = newNode(2);
    root->Right = newNode(3);

    root->Left->Left = newNode(4);
    
    cout << root->data << '\t';
    cout << root->Left->data << '\t';
    cout << root->Right->data << '\t';
    cout << root->Left->Left->data << '\t';

    return 0;
}