#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int data;
    node*right;
    node*left;
};

class BST
{
private:
    int length;
    node*root;
    void preOrder(node*n);
    void inOrder(node*n);
    void postOrder(node*n);
public:
    BST();
    bool isEmpty();
    void add(int val);
    void getMixValue(int&item);
    void getMinValue(int&item);
    void preorderTraversal();
    void inorderTraversal();
    void postorderTraversal();
    void levelorderTraversal();
};


BST::BST()
{
    root = nullptr;
}
bool BST::isEmpty()
{
    return root == nullptr;
}

void BST::add(int val)
{
    length++;
    node*newNode = new node;
    newNode->data = val;
    newNode->left = newNode->right = nullptr;

    if(isEmpty())
    {
        root = newNode;
        return;
    }

    node*temp = root;
    node*pre = nullptr;
    while(temp != nullptr)
    {
        pre = temp;
        if(val <= temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if(val <= pre->data)
        pre->left = newNode;
    else
        pre->right = newNode;

}

void BST::getMixValue(int&item)
{
    if(root == nullptr)
    {
        cout << "Empty BST\n";
        return;
    }
    node*temp = root;
    while(temp->right != nullptr)
    {
        temp = temp->right;
    }
    item = temp->data;
}

void BST::getMinValue(int&item)
{
    if(root == nullptr)
    {
        cout << "Empty BST\n";
        return;
    }
    node*temp = root;
    while(temp->left != nullptr)
    {
        temp = temp->left;
    }
    item = temp->data;
}

void BST::preorderTraversal()
{
    preOrder(root);
}

void BST::preOrder(node*n)
{
    if(n != nullptr)
    {
        cout << n->data << " ";
        preOrder(n->left);
        preOrder(n->right);
    }
}

void BST::inorderTraversal()
{
    inOrder(root);
}

void BST::inOrder(node*n)
{
    if(n != nullptr)
    {
        inOrder(n->left);
        cout << n->data << " ";
        inOrder(n->right);
    }
}

void BST::postorderTraversal()
{
    postOrder(root);
}

void BST::postOrder(node*n)
{
    if(n != nullptr)
    {
        postOrder(n->left);
        postOrder(n->right);
        cout << n->data << " ";

    }
}

void BST::levelorderTraversal()
{
    if(root == nullptr)
        return;
    queue<node*> q;
    q.push(root);
    while( !q.empty() )
    {
        node*temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if(temp->left != nullptr)
            q.push(temp->left);
        if(temp->right != nullptr)
            q.push(temp->right);
    }
}

int main()
{
    BST a;
    a.add(5);
    a.add(4);
    a.add(3);
    a.add(2);
    a.add(1);
    a.add(6);
    a.add(7);
    a.add(8);
    a.add(9);

    int x;
    a.getMinValue(x);
    cout << x << "\n";
    a.getMixValue(x);
    cout << x << "\n";

    a.inorderTraversal();
    cout << "\n";
    a.levelorderTraversal();
    cout << "\n";
    a.postorderTraversal();
    cout << "\n";
    a.preorderTraversal();

    return 0;
}
