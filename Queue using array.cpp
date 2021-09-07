#include <iostream>
using namespace std;


template<class t>
class Queue{
public:
    t*que;
    int first;
    int rear;
    int sz;
    int max_size;
private:
    Queue(int x){
        first = 0;
        sz = 0;
        max_size = abs(x);
        que = new t[max_size];
        rear = max_size-1;
    }

    bool isEmpty(){
        return (sz == 0);
    }
    bool isFull(){
        return (sz == max_size);
    }

    int getSize(){
        return sz;
    }

    void addQueue(t item){
        if(!isFull()){
            rear = (rear+1)%max_size;
            que[rear] = item;
            sz++;
        }
        else{
            cout << "Your queue is full\n";
        }
    }

    void deleteQueue(){
        if(isEmpty())
            cout << "Your queue is empty\n";
        else{
            first = (first+1)%max_size;
            sz--;
        }
    }

    void deleteQueue(t&item){
        if(isEmpty())
            cout << "Your queue is empty\n";
        else{
            item = que[first];
            first = (first+1)%max_size;
            sz--;
        }
    }

    void getFront(t&item){
        if(isEmpty())
            cout << "Your queue is empty\n";
        else
            item = que[first];
    }

    void getRear(t&item){
        if(isEmpty())
            cout << "Your queue is empty\n";
        else
            item = que[rear];
    }

    void display(){
        cout << "[ ";
        for(int i = first; i != rear+1 && sz!=0; i = (i+1)%max_size){
            cout << que[i] << " ";
        }
        cout << "]\n";
    }

    int searchQueue(t item){
        int pos = -1;
        if(isEmpty())
            return pos;
        else{
            for(int i = first; i != rear+1 && sz!=0; i = (i+1)%max_size){
                pos++;
                if(item == que[first])
                    return pos;
            }
        }
        return -1;
    }

};


int main()
{
    Queue<int>q(100);
    q.addQueue(5);
    q.addQueue(8);
    q.addQueue(84);
    q.addQueue(52);
    q.deleteQueue();
    int x;
    q.deleteQueue(x);
    cout << x << "\n";
    q.addQueue(55);
    q.addQueue(50);
    q.addQueue(53);
    q.addQueue(51);
    q.display();

    q.getFront(x);
    cout << x << "\n";

    q.getRear(x);
    cout << x << "\n";

    cout << q.searchQueue(50) << "\n";

    return 0;
}
