#include <iostream>
using namespace std;
const int maxSize = 10;
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
        item = entry[topIndex - 1];
        return true;
    }
};
template <class T>
void fill(Stack<T> &s, int n)
{
    for (int i = 1; i < n; i++)
    {
        s.push(rand() % 100);
    }
}
template <class T>
bool fill2(Stack<T> &s, int n)
{
    int c = 0;
    for (size_t i = 1; i <= n; i++)
    {
        if (!s.push(rand() % 100))
        {
            for (size_t i = 0; i <= c; i++)
            {
                s.pop();
                return 0;
            }
        }
        else
            c++;
    }
    return 1;
}
void print(Stack<int> s)
{
    int item,i=0;
    while (!s.Empty())
    {           
     i++;
        s.top(item);
        s.pop();
        cout << "#" << i << ":" << item << endl;          
    }
}
template <class T>
void removeMax(Stack<T> &s)
{
    Stack<T> b;
    T item;
    while (!s.Empty())
    {
        s.top(item);
        b.push(item);
        s.pop();
    }
    int max;
    b.top(max);
    while (!b.Empty())
    {

        b.top(item);
        if (item <= max)
            s.push(item);
        s.pop();
    }
}
template <class T>
bool concatenate(Stack<T> &s1, Stack<T> &s2)
{
    // Stack<T> concatenated;
    T item;
    int c = 0;
    Stack<T> temp;
    // we put stack s2 in temp stack for 
    // reversion purpuses
    while (!s2.Empty())
    {
        s2.top(item);
        temp.push(item);
        s2.pop();
    }
    while (!temp.Empty())
    {
        temp.top(item);
        // if it has NOT been added
        if(s1.push(item)==0)
        {
          for (int i = 1; i <=c; i++)
          {
              s1.top(item);
              temp.push(item);
              s1.pop();

        
          }
          while(!temp.Empty())
          {
              temp.top(item);
              s2.push(item);
              temp.pop();
              return false;                                       
          }
         }
         // if it has been added 
         else {
              temp.pop();
              c++;
          }                  
    }
    
    return true;
}
template<class T>
// I think this is not what we want .. 
bool swapx(Stack <T> &a,T x){
// T item;    
// Stack temp;
// T itemtemp;
// while(!a.Empty)
// {
// a.top(item);
// if (!(item==x))
// {
//     s.push(item);

// }

// }
return true;
}
bool a()
{
    cout << "dn\n";
    return true;
}
int main()
{
    cout<<"\n\n---------------\n";
    cout<<"THIS IS NEW RUN\n";
    cout<<"---------------\n";
    // Stack<int> a;
    // int item;
    // // a.push(1);
    // // a.push(2);
    // // a.push(3);
    // // a.push(4);
    // // a.push(5);
    // fill2(a,5);
    // print(a);
    //  removeMax(a);
    // cout<<"---------\n";
    // print(a);
    // // int x = 2;
    // // cout << "x is :" << x << endl;
    // // if (a.top(x))
    // //     cout << "x is :" << x << endl;
    // a.push(1);
    // cout << "x is :" << x << endl;
    // fill(a, 20);
    // if (a.top(x))
    //     cout << "x is :" << x << endl;
    // if(!a())
    //new
    // Stack<int> s1, s2;
    // fill2(s1, 5);
    // fill2(s2, 7);
    // cout << "s1:\n";
    // print(s1);
    // cout << "------\n";
    // cout << "s2:\n";
    // print(s2);
    // concatenate(s1, s2);
    // cout << "------\n";
    // cout << "------\n";
    // cout << "s1 con:\n";
    // print(s1);
     cout<<"\n---------------";
     cout <<endl<< "     DONE!\n";
     cout<<"---------------\n\n";
}