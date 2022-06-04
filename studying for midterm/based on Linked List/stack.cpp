#include <iostream>
using namespace std;
template <class T>
struct node
{
    T data;
    node<T> *next;
    node() { next = 0; }
    node(T item)
    {
        data = item;
        next = 0;
    }
};
template <class T>
class stack
{
    node<int> *topIndex;

public:
    stack()
    {
        topIndex = 0;
    }
    stack(stack<T> &ss)
    {
        cout << "copy constructure called\n";
        node<T> *q;
        node<T> *temp = ss.topIndex;
        if (temp == 0)
        {
            this->topIndex = 0;
        }
        else
        {
            topIndex = q = new node<T>(temp->data);
            while (temp->next != 0)
            {
                temp = temp->next;
                q->next = new node<T>(temp->data);
                q = q->next;
            }
        }
    }
    bool empty()
    {
        return topIndex == 0;
    }
    bool push(T item)
    {
        node<T> *a = new node<T>(item);
        if (a == 0)
            return 0;
        a->next = topIndex;
        topIndex = a;
        return 1;
    }
    bool pop()
    {
        if (empty())
            return 0;

        node<int> *a = topIndex;
        topIndex = topIndex->next;
        delete a;
        return 1;
    }
    bool top(T &item)
    {
        if (empty())
            return 0;
        item = topIndex->data;
        return 1;
    }

    void operator=(stack<T> &s)
    {
        //due to problem #2
        cout << "op overload is called\n";
        node<T> *newTop = 0;
        if (!s.empty())
        {
            node<T> *p = s.topIndex;
            node<T> *ptr = newTop = new node<T>(p->data);
            while (p->next != 0)
            {
                p = p->next;
                ptr->next = new node<T>(p->data);
                ptr = ptr->next;
            }
        }
        while (!this->empty())
        {
            this->pop();
        }
        this->topIndex = newTop;
    }
    ~stack()
    {
        // due to problem #1 (memory)
        // so memory will be released عناصر الستاك صارت منفصلة عن الهيد فيجب حدفها كل على حدا
        while (!empty())
        {
            pop();
        }
    }
};
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
void F(stack<int> s)
{
}
int main()
{
    int x = 88, y;
    stack<int> outer;
    outer.push(10);
    outer.push(20);
    outer.push(30);
    print(outer);
    outer.pop();
    print(outer);
    // cout << x << endl; //30
    // F(outer);
    // outer.top(x);
    // cout << x << endl; //30
    // {
    //     stack<int> inner;
    //     for (int i = 0; i <= 1000; i++)
    //     {
    //         inner.push(i);
    //     }
    //     inner.top(x);
    //     cout << x << endl; //1000
    //     inner = outer;
    //     inner.top(x);
    //     cout << x << endl;
    // } // inner dead
    // outer.top(y);
    // cout << y << endl;
}
