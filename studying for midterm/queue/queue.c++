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
template <class T>
class queue
{
    int front, rear, count;
    T entry[maxSize];

public:
    queue()
    {
        count = 0;
        front = 0;
        rear = maxSize - 1;
    }
    bool empty()
    {
        return (count == 0);
    }
    bool append(T item)
    {
        if (count == maxSize)
            return 0;
        // using if statment
        // rear++;
        // if (rear==maxSize) rear=0;
        // to not use the if becuase it is slower
        rear = (rear + 1) % maxSize;
        entry[rear] = item;
        count++;
        return 1;
    }
    bool serve()
    {
        if (count == 0)
            return 0;
        front = (front + 1) % maxSize;
        count--;
        return 1;
    }
    bool retrive(T &item)
    {
        if (empty())
            return 0;
        item = entry[front];
        return 1;
    }
};
void fill(queue<int> &q, int c)
{
    for (int i = 0; i < c; i++)
    {
        q.append(rand() % 100);
    }
}
template <class T>
void print(queue<T> q)
{
    while (!q.empty())
    {
        T item;
        q.retrive(item);
        cout << item << "  ";
        q.serve();
    }
    cout << endl;
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
void removemin(queue<int> &q)
{
    if (!q.empty())
    {
        queue<int> s;
        int item, min;
        q.retrive(min);
        s.append(min);
        q.serve();
        while (!q.empty())
        {
            q.retrive(item);
            if (item < min)
                min = item;
            s.append(item);
            q.serve();
        }
        while (!s.empty())
        {
            s.retrive(item);
            if (item != min)
                q.append(item);
            s.serve();
        }
    }
}
void reverseQ(queue<int> &q)
{
    if (!q.empty())
    {
        stack<int> s;
        int item;
        while (!q.empty())
        {
            q.retrive(item);
            q.serve();
            s.push(item);
        }
        while (!s.empty())
        {
            s.top(item);
            s.pop();
            q.append(item);
        }
    }
}
// more than 4 hours omg
void concate(queue<int> &q1, queue<int> &q2)
{
    int item, c = 0, i = 0, j = 0;
    stack<int> s, s2, s3, s4, s5, s400;
    queue<int> q3;
    int a[maxSize];
    while (!q1.empty())
    {
        q1.retrive(item);
        if (!q2.append(item))
        {
            while (!q2.empty())
            {
                q2.retrive(item);
                q2.serve();
                s.push(item);
            }
            for (int i = 0; i < c; i++)
            {
                s.top(item);
                s.pop();
                s3.push(item);
            }
            while (!q1.empty())
            {
                q1.retrive(item);
                q1.serve();
                q2.append(item);
            }
            while (!s3.empty())
            {
                s3.top(item);
                s3.pop();
                q1.append(item);
            }

            while (!q2.empty())
            {
                q2.retrive(item);
                q2.serve();
                q1.append(item);
            }
            ///q2
            while (!s.empty())
            {
                s.top(item);
                s.pop();
                s5.push(item);
            }
            while (!s5.empty())
            {
                s5.top(item);
                s5.pop();
                q2.append(item);
            }

            break;
        }
        q1.serve();
        c++;
    }
}
int main()
{
    queue<int> q1, q2;
        fill(q1,10);
        print(q1);
        cout<<"------\n";
    //     cout<<q1.front<<"\t";
    //     cout<<q1.rear<<"\t";
    //    cout<<q1.count<<"\t";
    // for (int i = 0; i < 3; i++)
    // {
    //     cout<<c[i]<<endl;
    // }

    // cout<<"is it empty "<<q.empty()<<endl;
    // fill(q1,55);
    // print(q1);
    // cout<<"\n----------\n\n";
    // // cout<<"is it empty "<<q.empty()<<"\n--------\n";
    // reverseQ(q1);
    // fill(q2,100);
    // print(q2);
    // cout<<"\n----------\n\n";
    // concate(q1,q2);

    //   print(q1);
    //   cout<<"\n----------\n\n";
    //   print(q2);
    // // cout<<"is it empty "<<q.empty()<<"\n--------\n";
}