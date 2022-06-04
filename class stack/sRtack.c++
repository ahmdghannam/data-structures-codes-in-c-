#include <iostream>
using namespace std;
const int maxSize = 20;
template <class T>
class Stack
{
    int topIndex;
    T entry[maxSize];

public:
    Stack()
    {
        topIndex = 0;
    }
    // is it Empty or not ?
    bool Empty()
    {
        return (topIndex == 0);
    }
    // inserting an item
    bool push(T item)
    {
        if (topIndex == maxSize)
            return false;
        entry[topIndex++] = item;
        return true;
    }
    // deleting the topIndex item
    bool pop()
    {
        if (Empty())
            return false;
        topIndex--;
        return !false;
    }
    // makes an object have top index value
    bool top(T &item)
    {
        if (Empty())
            return false;
        item = entry[topIndex-1];
        return true;
    }
    
};
template<class T>
void fill(Stack <int>& s, int n)
{
 for (int i = 1; i < n; i++)
 {
   s.push(rand()%100);
 }  
}
int main()
{
    Stack<int> a ;
    Stack <int> cx;
int s=20;
// fill(a,s);
cout<<"dn";
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);

    int x=2;
      cout<<"x is :"<<x<<endl;
    if(a.top(x))
     cout<<"x is :"<<x<<endl;
     a.push(1);
     cout<<"x is :"<<x<<endl;

    cout << "OK";
}