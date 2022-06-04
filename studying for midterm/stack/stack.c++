#include <iostream>
using namespace std;
const int maxSize = 10;
template <class T>
class stack
{
    int topIndex;
    T entry[maxSize];

public:
    stack()
    {
        topIndex = 0;
    }
    bool empty()
    {
        return topIndex == 0;
    }
    bool push(T item)
    {
        if (topIndex == maxSize)
            return 0;
        entry[topIndex++] = item;
        return 1;
    }
    bool pop()
    {
        if (empty())
            return 0;
        topIndex--;
        // delete entry[maxSize];
        return 1;
    }
    bool top(T &item)
    {
        if (empty())
            return 0;
        item = entry[topIndex - 1];
        return 1;
    }
};
void fill(stack<int> &s, int n)
{
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
}
void fill2(stack<int> &s, int n)
{
    for (int i = 0; i < n; i++)
    {
        s.push(rand() % n);
    }
}
bool fill3(stack<int> &s, int n)
{
    int c = 0, r = 1;
    for (int i = 0; i < n; i++)
    {
        if (s.push(rand() % 100))
            c++;
        else
        {
            r = -1;
            break;
        }
    }
    if (r == -1)
    {
        for (int i = 0; i < c; i++)
        {
            s.pop();
        }
        return 0;
    }
    return 1;
}
bool fill4(stack<int> &s, int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (!(s.push(rand() % 100)))
        {
            for (int i = 0; i < c; i++)
            {
                s.pop();
            }
            return 0;
        }
        else
            c++;
    }
    return 1;
}
void print(stack<int> s)
{
    int item;
    while (!s.empty())
    {

        s.top(item);
        cout << item << endl;
        s.pop();
    }
}
bool removeMax(stack<int> &s)
{
    if (s.empty())
        return 0;
    int max;
    s.top(max);
    stack<int> temp;
    int item;
    while (!s.empty())
    {
        s.top(item);
        if (item > max)
            max = item;
        temp.push(item);
        s.pop();
    }
    while (!temp.empty())
    {
        temp.top(item);
        if (item != max)
            s.push(item);
        temp.pop();
    }
    return 1;
}
bool concat(stack<int> &s1, stack<int> &s2)
{
    stack<int> t;
    int item, c = 0, r = 1;
    // to reverse the stack so when add it to s2 it return to native order
    while (!s1.empty())
    {
        s1.top(item);
        t.push(item);
        s1.pop();
    }
    while (!t.empty())
    {
        t.top(item);
        t.pop();
        if (!s2.push(item))
        {
            for (int i = 0; i < c; i++)
            {
                s2.top(item);
                t.push(item);
                s2.pop();
            }
            while (!t.empty())
            {
                t.top(item);
                s1.push(item);
                t.pop();
            }
            return 0;
        }

        else
        {

            c++;
        }
    }

    return 1;
}
//it works
bool swap(stack<int> &s, int item)
{
    stack<int> t1, t2;
    int it, c = 0;
    while (!s.empty())
    {
        s.top(it);
        s.pop();

        if (it == item)
        {
            c++;
            break;
        }
        else
            t1.push(it);
    }
    if (c == 0)
    {
        while (!t1.empty())
        {
            t1.top(it);
            t1.pop();
            s.push(it);
        }
        cout << "error: item not found !\n\n";
        return 0;
    }
    while (!s.empty())
    {
        s.top(it);
        s.pop();
        t2.push(it);
    }
    while (!t1.empty())
    {
        t1.top(it);
        t1.pop();
        s.push(it);
    }
    s.push(item);
    while (!t2.empty())
    {
        t2.top(it);
        t2.pop();
        s.push(it);
    }

    return 1;
}
// if the item is not exist you will get an error
void swap_alpha(stack<int> &s, int item)
{
    stack<int> t1;
    stack<int> t2;
    int item2, it;
    s.top(item2);
    s.pop();
    while (item2 != item)
    {
        t1.push(item2);
        s.top(item2);
        s.pop();
    }
    // s.pop();
    while (!s.empty())
    {
        s.top(item2);
        t2.push(item2);
        s.pop();
    }
    while ((!t1.empty()))
    {
        t1.top(it);
        t1.pop();
        s.push(it);
    }
    s.push(item);
    while ((!t2.empty()))
    {
        t2.top(it);
        t2.pop();
        s.push(it);
    }
}
template <class T>
bool checkFull(stack<T>&s){

    if(s.empty())return 0;
    stack<T>a=s;
    int c=0;
    while (!a.empty())
     {
       a.pop();
       c++;
     }
   return (c==maxSize);
}
int main()
{
    stack<int> s1, s2;
    // fill(s,9);
    // print(s);
    cout << "\n-----\n";
    fill4(s1, 10);
    print(s1);
    cout << "\n-----\n";
    // cout<<checkFull(s1)<<endl;
    // swap(s1,62);
    // print(s1);`
    //  fill4(s2,4);
    //   print(s2);
    //   concat(s1,s2);
    //   cout<<"\n-----\n";
    //    print(s1);
    //    cout<<"\n-----\n";
    //    print(s2);
    //    cout<<"\n-----\n";
    //   removeMax(s);
    //   print(s);
    //  cout<<"\ndone\n";
}