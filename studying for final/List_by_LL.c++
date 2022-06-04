#include <iostream>
#define MAX 10
using namespace std;
template <class T>
struct node
{
    T data;
    node<T> *next;
    node()
    {
        data = 0, next = 0;
    }
    node(T item)
    {
        data = item;
        next = 0;
    }
};
template <class T>
class List
{
    int count;
    node<T> *head;
    node<T> *setpos(int pos)
    {
        node<T> *q = head;
        for (int i = 0; i < pos; i++)
        {
            q = q->next;
        }
        return q;
    }

public:
    List()
    {
        count = 0;
    }
    bool empty()
    {
        return count == 0;
    }
    bool insert(int pos, T item)
    {
        if (pos < 0 || pos > count)
            return 0;
        node<T> *temp = new node<T>(item);
        if (temp == 0)
            return 0;

        if (pos > 0)
        {
            node<T> *prev, *follow;
            prev = setpos(pos - 1);
            follow = prev->next;
            temp->next = follow;
            prev->next = temp;
            count++;
            return 1;
        }

        else
        {
            // follow = head;
            // temp->next = follow;
            head = temp;
            count++;
            return 1;
        }
    }
    bool retreive(int pos, T &item)
    {
        if (empty())
            return 0;
        if (pos < 0 || pos >= count)
            return 0;
        node<T> *q = setpos(pos);
        item = q->data;
        return 1;
    }
    bool replace(int pos, T item)
    {
        if (empty())
            return 0;
        if (pos < 0 || pos >= count)
            return 0;
        node<T> *q = setpos(pos);
        q->data = item;
        return 1;
    }
    bool remove(int pos)
    {
        if (empty())
            return 0;
        if (pos < 0 || pos > count)
            return 0;
        if (pos > 0)
        {
            node<T> *prev, *follow;
            prev = setpos(pos - 1);
            follow = prev->next;
            prev->next = prev->next->next;
            delete follow;
        }
        else
        {
            head = head->next;
        }
        count--;
        return 1;
    }
    // bool print()
    // {
    //     node<T> *h = head;
    //     for (int i = 0; i < count; i++)
    //     {
    //         cout << h->data << endl;
    //         h = h->next;
    //     }
    //     return 1;
    // }
    int size()
    {
        return count;
    }

    // operator overload
    void operator=(List<T> &l)
    {
        while (!empty())
        {
            remove(0);
        }

        if (!l.empty())
        {
            node<T> *newhead, *temp, *p;
            p = l.head;
            newhead = temp = new node<T>(p->data);
            while (p->next != 0)
            {
                p = p->next;
                temp->next = new node<T>(p->data);
                temp = temp->next;
            }
            head = newhead;
            count = l.count;
        }
    }
    // copy constructor
    List(List<T> &l2)
    {
        node<T> *q, *newhead, *temp = l2.head;
        if (l2.head != 0)
        {
            q = newhead = new node<T>(temp->data);
            while (temp->next != 0)
            {
                temp = temp->next;
                q->next = new node<T>(temp->data);
                q = q->next;
            }
            head = newhead;
            count = l2.count;
        }
    }
    ~List()
    {
        while (!empty())
        {
            remove(0);
        }
    }
};
template<class T>
class orderedlist : public List<T>{
public :
bool insert(T item){
T data;
int i = 0;
for (; i < List<T>::size();i++)
{
    List<T>::retreive(i,data);
    
    if(data>=item)break;
}

return List<T>:: insert(i,item);
}
};
//functions
void fill(List<int> &s, int a)
{
    for (int i = 0; i < a; i++)
    {
        s.insert(i, rand() % 101);
    }
}
void fill(orderedlist<int> &s, int a)
{
    for (int i = 0; i <= a; i++)
    {
        //  cout<<"hlo\n";
        s.insert(rand() % 101);
        // cout<<"hello\n";
    }
}
void print(List<int>s)
{
    int item;
    for (int i = 0; i < s.size(); i++)
    {
        s.retreive(i, item);
        cout << item << endl;
    }

}
void print(orderedlist<int>s)
{
    int item;
    for (int i = 0; i < s.size(); i++)
    {
        s.retreive(i, item);
        cout << item << endl;
    }

}
void reverse(List<int> &l)
{
    if (!l.empty())
    {
        int i = 0, j = l.size() - 1, first, last;
        while (i <= j)
        {
            l.retreive(i, first);
            l.retreive(j, last);
            l.replace(i, last);
            l.replace(j, first);
            i++;
            j--;
        }
    }
}
List <int>*oddItems (List<int> l1, List<int> l2)
{
    int item;
    List<int> *l=new List<int>;
    for (int i = 0; i < l1.size(); i++)
    {
        l1.retreive(i, item);
        if (item % 2 != 0){
        // cout<<item<<endl;
            l->insert(l->size(), item);}
    }
    for (int i = 0; i < l2.size(); i++)
    {
        l2.retreive(i, item);
        if (item % 2 != 0){
         // cout<<item<<endl;
            l->insert(l->size(), item);}
    }
    return l;
}
// sequintial search
int seqsearch(List<int>L,int item){
int x;
for (int i = 0; i < L.size(); i++)
{
    L.retreive(i,x);
    if(x==item)return i;

}
return -1;
}
//binary search 
int binsearch(orderedlist<int>l,int item){
int first=0,last=l.size()-1,x;
while (first<=last)
{
    int mid=(first+last)/2;
    l.retreive(mid,x);
    if(x==item)return mid;
    if(item>x)
    first=mid+1;
    else if(item<x)
    last=mid-1;
}
return -1;
}
//recursive
int factorial(int n){
    int f=1;
    for (int i = n; i > 0; i--)
    {
        f*=i;
    }
    return f;
}
int recfactorial(int n){

    if(n<=1)return n;
    return n*recfactorial(n-1);
}
int fib(int n){
    if(n<=1) return n;
    return fib(n-1)+fib(n-2);
}
int RBS(int fst,int lst,orderedlist<int>L,int item){
if(fst>lst)return -1;
int mid=(fst+lst)/2;
int data;
L.retreive(mid,data);
if(item=data)return mid;
if(item>data)fst=mid+1;
else
lst=mid-1;
return RBS(fst,lst,L,item);

}

int main()
{
//     List<int> a;
//     List<int> b;
//     List<int> c;
//     a.insert(0, 10);
//     a.insert(1, 30);
//     a.insert(2, 19);
//     a.insert(3, 7);
//     b.insert(0, 415);
//     b.insert(1, 514);
//     b.insert(2, 1514);
//     b.insert(3, 212);
//     print(a);
//     cout<<"-------\n";
//     //  print(b);`
//     // a.remove(1);
//     cout<<seqsearch(a,19)<<endl;
//     cout<<"--------\n";
//     // a.print();
//     // b=a;
//     // cout<<"------\n";
//     // reverse(a);
// //  print(*oddItems(a,b));
  
//     //  print(a);
//     // cout<<"------\n";
//     // print(b);`
// orderedlist<int> a;
// a.insert(1);
// a.insert(31);
// a.insert(7);
// a.insert(14);
// a.insert(4);
// a.insert(100);
//  a.insert(10);
// // fill(a,30);
// print (a);
// cout<<"--------\n";
// // a.insert(1);
// print (a);
// cout<<"--------\n";
// cout<<binsearch(a,10)<<endl;
// cout<<fib(10)<<endl;

    cout << "done\n";
}