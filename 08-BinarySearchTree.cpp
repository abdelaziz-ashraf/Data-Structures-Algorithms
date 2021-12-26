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
    int height(node*N);
    node* deleteNode(node*N, int data);
    node* minNodeToUseInDeleting(node* N);

public:
    BST();
    bool isEmpty();
    void add(int val);
    void getMixValue(int&item);
    void getMinValue(int&item);
    void preorderTraversal();   // Depth First Search
    void inorderTraversal();    // Depth First Search
    void postorderTraversal();  // Depth First Search
    void levelorderTraversal(); // Breadth First Search
    int findHeight();
    void Delete(int data);
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

int BST::findHeight()
{
    if(root == nullptr)
        return -1;

    height(root);
}

int BST::height(node*N)
{
    if(N == nullptr)
        return 0;

    return 1+max(height(N->left), height(N->right));
}

node* BST::minNodeToUseInDeleting(node* N){
    if(N->right != nullptr)
        minNodeToUseInDeleting(N->right);

    return N;
}

void BST::Delete(int data){
    if(root == nullptr)
        return;

    deleteNode(root, data);
}

node* BST::deleteNode(node*N, int data){
    if(N == nullptr)
        return N;

    if(data < N->data){
        N->left = deleteNode(N->left, data);
    }
    else if(data > N->data){
        N->right = deleteNode(N->right, data);
    }
    else{
        if(N->left == nullptr && N->right == nullptr){
            delete N;
            N = nullptr;
        }
        else if(N->left == nullptr){
            node* temp = N;
            N = N->right;
            delete temp;
        }
        else if(N->right == nullptr){
            node* temp = N;
            N = N->left;
            delete temp;
        }
        else {
            node* temp = minNodeToUseInDeleting(N->left);
            N->data = temp->data;
            N->left = deleteNode(N->left, temp->data);
        }
    }
    return N;
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

    a.Delete(7);

    a.postorderTraversal();
    cout << "\n";

    a.preorderTraversal();
    cout << "\n";


    cout << a.findHeight() << "\n";


    return 0;
}
