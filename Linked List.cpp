#include <iostream>

using namespace std;

struct node
{
    int item;
    node*next;
};

class linkedList
{

private:
    node*head;
    node*rear;
    int length;

public:
    linkedList();
    ~linkedList();
    int getSize();
    bool isEmpty();
    void insertFirst(int);
    void insertEnd(int);
    void insertAt(int, int);
    void print();
    void removeValue(int);
    void removeFirst();
    void removeEnd();
    int Search(int);
    void clearList();
    void Reverse();
};

linkedList::linkedList(): head(NULL), rear(NULL), length(0)
{}

int linkedList::getSize()
{
    return length;
}

bool linkedList::isEmpty()
{
    return length == 0;
}

void linkedList::insertFirst(int val)
{
    node*newNode = new node;
    newNode->item = val;
    if(isEmpty())
    {
        head = rear = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    length++;
}

void linkedList::insertEnd(int val)
{
    node*newNode = new node;
    newNode->item = val;
    if(isEmpty())
    {
        head = rear = newNode;
        newNode->next = NULL;
    }
    else
    {
        rear->next = newNode;
        newNode->next = NULL;
        rear = newNode;
    }
    length++;
}

void linkedList::insertAt(int pos,int val)
{
    if(pos < 0 || pos >length)
        cout << "Your position out of range\n";
    else if(pos == 0)
        insertFirst(val);
    else if(pos == length)
        insertEnd(val);
    else
    {
        node*newNode = new node;
        newNode->item = val;
        node*cur = head;
        for(int i = 1; i < pos; i++)
            cur = cur->next;

        newNode->next = cur->next;
        cur->next = newNode;
        length++;
    }
}

void linkedList::print()
{
    cout << "[ ";
    node*cur = head;
    while(cur != NULL)
    {
        cout << cur->item << " ";
        cur = cur->next;
    }
    cout << "]\n";
}

void linkedList::removeValue(int val)
{
    if(isEmpty())
        cout << "Linked list is empty\n";
    else if(val == head->item)
    {
        node*newNode = head;
        head = head->next;
        delete newNode;
        length--;
        if(length == 0)
            rear = NULL;
    }
    else
    {
        node*cur = head->next;
        node*prv = head;
        while(cur != NULL)
        {
            if(val == cur->item)
                break;
            prv = cur;
            cur = cur->next;
        }
        if(cur == NULL)
            cout << "Item not found\n";
        else
        {
            prv->next = cur->next;
            if(rear == cur)
                rear = prv;
            delete cur;
            length--;
        }
    }
}

void linkedList::removeFirst()
{
    if(isEmpty())
        cout << "Empty linked list\n";
    else if(length == 1)
    {
        head = rear = NULL;
        length--;
    }
    else
    {
        node*newNode = head;
        head = head->next;
        delete newNode;
        length--;
    }
}

void linkedList::removeEnd()
{
    if(isEmpty())
        cout << "Empty linked list\n";
    else if(length == 1)
    {
        head = rear = NULL;
        length--;
    }
    else
    {
        removeValue(rear->item);
    }
}

int linkedList::Search(int val)
{
    int pos = 0;
    node*cur = head;
    while(cur != NULL)
    {
        if(cur->item == val)
            return pos;
        cur = cur->next;
        pos++;
    }
    return -1;
}

void linkedList::Reverse()
{
    node *prev, *next, *curr;
    prev = NULL;
    curr = head;
    next = curr->next;
    while (next != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void linkedList::clearList()
{
    node*cur;
    while(head != NULL)
    {
        cur = head;
        head = head->next;
        delete cur;
    }
    rear = NULL;
    length = 0;
}


linkedList::~linkedList()
{
    clearList();
}



int main()
{

    return 0;
}
