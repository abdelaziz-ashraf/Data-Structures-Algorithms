#include <iostream>
using namespace std;

const int max_sz = 100; // max size >> array size

template<class t>
class Stack{
    int top;
    int sz; // num of elements inside the stack
    t stk[max_sz];

public:
    // constructor
    Stack(): top(-1), sz(0){

    }

    // check if stack do not have elements
    bool isEmpty(){
        return (sz == 0);
    }
    // check if stack is full >> u reach max size
    bool isFull(){
        return (sz == max_sz);
    }

    // to access the top (last element u entered)
    t getTop(){
        if(!isEmpty())
            return stk[top];
        else
            cout << "Your stack is empty\n";
    }

    // to remove the top (last element u entered)
    void pop(){
        if(!isEmpty()){
            top--;
            sz--;
        }
        else{
            cout << "Stuck is empty\n";
        }
    }

    // to remove and get the top (last element u entered)
    void pop(t& item){
        if(!isEmpty()){
            item = stk[top];
            top--;
            sz--;
        }
        else{
            cout << "Stuck is empty\n";
        }
    }

    // to add element
    void push(t item){
        if(!isFull()){
            top++;
            sz++;
            stk[top] = item;
        }
        else{
            cout << "Your stack is full\n";
        }
    }

    // get num of elements
    int getSize(){
        return sz;
    }

    // print all elements without pop(remove) any element
    void print(){
        cout << "[ ";
        for(int i = 0; i < sz; i++){
            cout << stk[i];
            if(i < sz-1)
                cout << ", ";
            else
                cout << " ";
        }
        cout << "]\n";
    }

};


int main()
{
    Stack<int>s;

    return 0;
}
