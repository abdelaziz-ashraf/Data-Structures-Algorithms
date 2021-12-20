#include <iostream>
using namespace std;

template<class t>
class Stack{
private:
    struct node{
        t item;
        node*next;
    };
    int sz; // size >> num of elements
    node*top;

public:
    Stack(){
        sz = 0;
        top = NULL;
    }

    bool isEmpty(){
        return (sz == 0);
    }

    void push(t element){
       node*newItem = new  node;
       if(newItem == NULL){
            cout << "Stack push cannot allocate memory\n";
       }
       else{
            newItem->item = element;
            newItem->next = top;
            top = newItem;
            sz++;
       }
    }

    void pop(){
        if(isEmpty())
            cout << "Stack is empty\n";
        else{
            node*temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
            sz--;
        }
    }

    void pop(t&stkTop){
        if(isEmpty)
            cout << "Stack is empty\n";
        else{
            stkTop = top->item;
            node*temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
            sz--;
        }
    }

    void getTop(t&stkTop){
        if(isEmpty())
            cout << "Stack is empty\n";
        else{
            stkTop = top->item ;
        }
    }

    void display(){
        node*temp = top;
        cout << "[ ";
        while(temp!=NULL){
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << "]";
        delete temp;
    }

};


int main()
{
    Stack<int> s;

    s.push(5);
    s.push(50);
    s.push(55);
    s.push(52);
    int x;
    s.getTop(x);
    cout << x << "\n";
    s.pop();
    s.display();

    return 0;
}
