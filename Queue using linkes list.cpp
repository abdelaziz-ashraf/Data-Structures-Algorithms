#include <iostream>

using namespace std;

template<class t>
class Queue{

    struct node{
        t value;
        node*next;
    };
    node*frontptr;
    node*rear;
    int length;

public:
    Queue():frontptr(NULL), rear(NULL), length(0){}

    bool isEmpty(){
        return rear == NULL;
    }

    void enqueu(t item){
        if(isEmpty()){
            frontptr = new node;
            frontptr->value = item;
            frontptr->next = NULL;
            rear = frontptr;
            length++;
        }
        else{
            node*newItem = new node;
            newItem->value = item;
            newItem->next = NULL;
            rear->next = newItem;
            rear = newItem;
            length++;
        }
    }

    void deleteItem(){
        if(isEmpty())
            cout << "Empty Queue\n";
        else{
            node *temp = frontptr;
            if(rear == frontptr){
                rear = NULL;
                frontptr = NULL;
            }
            else
            {
                frontptr = frontptr->next;
            }
            temp->next = NULL;
            delete temp;
            length--;
        }
    }

    void getFront(t&item){
        if(isEmpty())
            cout << "Empty Queue\n";
        else
            item = frontptr->value;
    }

    void getRear(t&item){
        if(isEmpty())
            cout << "Empty Queue\n";
        else
            item = rear->value;
    }

    void clearQueue(){
        node*cur;

        while(frontptr!=NULL){
            cur = frontptr;
            frontptr = frontptr->next;
            delete cur;
            length--;
        }
        rear = NULL;
    }

    int getSize(){
        return length;
    }

    void display(){
        cout << "[ ";
        node*cur = frontptr;
        while(cur != NULL){
            cout << cur->value << " ";
            cur = cur->next;
        }
        cout << "]\n";
    }

};

int main()
{

    Queue<int> q;
    q.enqueu(100);
    q.enqueu(200);
    q.enqueu(300);
    q.display();
    int x;
    q.getFront(x);
    cout << x << "\n";
    q.getRear(x);
    cout << x << "\n";
    q.deleteItem();
    q.display();
    q.clearQueue();
    q.display();

    return 0;
}
