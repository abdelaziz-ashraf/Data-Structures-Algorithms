#include <iostream>

using namespace std;

class doublyLinkedList
{
private:
    struct node
    {
        int val;
        node*next;
        node*prv;
    };
    node*first;
    node*last;
    int length;
public:
    doublyLinkedList();
    ~doublyLinkedList();
    bool isEmpty();
    int getSize();
    void Clear();
    void insertEnd(int);
    void insertFirst(int);
    void insertAt(int, int);
    void removeFirst();
    void removeEnd();
    void removeNthNode(int);
    void disPlay();
    void reverseDisPlay();
};

doublyLinkedList::doublyLinkedList()
{
    first = last = NULL;
    length = 0;
}

bool doublyLinkedList::isEmpty()
{
    return (first == NULL);
}

int doublyLinkedList::getSize()
{
    return length;
}

void doublyLinkedList::Clear()
{
    node*cur;
    while(first != NULL)
    {
        cur = first;
        first = first->next;
        delete cur;
    }
    last = NULL;
    length = 0;
}

doublyLinkedList::~doublyLinkedList()
{
    Clear();
}

void doublyLinkedList::insertEnd(int item)
{
    node*newNode = new node;
    newNode->val = item;
    newNode->next = NULL;
    if(length == 0)
    {
        newNode->prv = NULL;
        first = last = newNode;
    }
    else
    {
        newNode->prv = last;
        last->next = newNode;
        last = newNode;
    }
    length++;
}

void doublyLinkedList::insertFirst(int item)
{
    node*newNode = new node;
    newNode->val = item;
    newNode->prv = NULL;
    if(length == 0)
    {
        newNode->next = NULL;
        first = last = newNode;
    }
    else
    {
        newNode->next = first;
        first->prv = newNode;
        first = newNode;
    }
    length++;
}

void doublyLinkedList::insertAt(int pos, int item)
{
    if(pos < 0 || pos > length)
        cout << "Pos out of range\n";
    else if(pos == 0)
        insertFirst(item);
    else if(pos == length)
        insertEnd(item);
    else
    {
        node*newNode = new node;
        node*temp = first;
        for(int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        newNode->val = item;
        newNode->next = temp->next;
        newNode->prv = temp;
        temp->next->prv = newNode;
        temp->next = newNode;
        length++;
    }
}

void doublyLinkedList::removeFirst()
{
    if(length == 0)
        cout << "Empty linked list\n";
    else if(length == 1)
    {
        delete first;
        first = last = NULL;
        length--;
    }
    else
    {
        node*cur = first;
        first = first->next;
        first->prv = NULL;
        delete cur;
        length--;
    }
}

void doublyLinkedList::removeEnd()
{
    if(length == 0)
        cout << "Empty linked list\n";
    else if(length == 1)
    {
        delete first;
        first = last = NULL;
        length--;
    }
    else
    {
        node*cur = last;
        last = last->prv;
        last->next = NULL;
        delete cur;
        length--;
    }
}

void doublyLinkedList::removeNthNode(int pos)
{
    if(pos < 0 || pos > length-1)
        cout << "Out of range";
    else if(pos == 0)
        removeFirst();
    else if(pos == length+1)
        removeEnd();
    else
    {
        node*cur = first->next;
        for(int i = 1; i < pos; i++)
        {
            cur = cur->next;
        }
        cur->next->prv = cur->prv;
        cur->prv->next = cur->next;
        delete cur;
        length++;
    }
}

void doublyLinkedList::disPlay()
{
    node*cur = first;
    cout << "[ ";
    while(cur != NULL)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "]\n";
}

void doublyLinkedList::reverseDisPlay()
{
    node*cur = last;
    cout << "[ ";
    while(cur != NULL)
    {
        cout << cur->val << " ";
        cur = cur->prv;
    }
    cout << "]\n";
}

int main()
{

    return 0;
}
