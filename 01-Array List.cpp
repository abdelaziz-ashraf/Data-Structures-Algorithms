#include <iostream>

using namespace std;

template<class t>
class arrayList
{
private:
    t*arr;
    int maxSize;
    int length;
public:
    arrayList(int s = 10)
    {
        maxSize = abs(s);
        length = 0;
        arr = new t[maxSize];
    }

    ~arrayList()
    {
        delete[]arr;
    }
    bool isEmpty()
    {
        return length == 0;
    }
    bool isFull()
    {
        return length == maxSize;
    }
    int getSize()
    {
        return length;
    }
    void display()
    {
        cout << "[ ";
        for(int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "]\n";
    }
    void insertAt(int pos, t item)
    {
        if(isFull())
            cout << "Full List\n";
        else if (pos < 0 || pos > length)
            cout << "Out Of Range\n";
        else
        {
            for(int i = length; i > pos; i--)
            {
                arr[i] = arr[i-1];
            }
            arr[pos] = item;
            length++;
        }
    }
    void insertAtEnd(t item)
    {
        if(isFull())
            cout << "Full List\n";
        else
        {
            arr[length] = item;
            length++;
        }
    }

    void insertAtFront(t item)
    {
        insertAt(0, item);
    }
    void removeAt(int pos)
    {
        if(isEmpty())
            cout << "Empty List\n";
        else if(pos < 0 || pos >= length)
            cout << "Out Of Range\n";
        else
        {
            for(int i = pos; i < length; i++)
            {
                arr[i] = arr[i+1];
            }
            length--;
        }
    }

    int Search(t item)
    {
        for(int i = 0; i < length; i++)
        {
            if(arr[i] == item)
            {
                cout << i << "\n";
                return 1;
            }
        }
        return -1;
    }
    void insertNoDouplicate(t item)
    {
        if(Search(item) == 1)
            cout << "The element is there\n";
        else
        {
            arr[length] = item;
            length++;
        }
    }
    void updateAt(int pos, t item)
    {
        if(pos < 0 || pos >= length)
            cout << "Out Of Range\n";
        else
            arr[pos] = item;
    }

    int getElement(int pos)
    {
        if(pos < 0 || pos >= length)
            cout << "Out Of Range\n";
        else
            return arr[pos];
    }
    int Clear()
    {
        length = 0;
    }

};


int main()
{

    return 0;
}
