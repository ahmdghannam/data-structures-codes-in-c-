#include <iostream>
using namespace std;
#define max 100
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
class list
{
    protected:
    int count;
    node<T> *head;
    node<T> setpos(int pos)
    {
        node <T>*q = head;
        for (int i = 0; i < pos; i++)
        {
            q = q->next;
        }
    }

public:
    list()
    {
        head = NULL;
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
        node<T> *Item = new node<T>(item);
        if (Item == 0)
            return 0;
        node<T> *prev, *follow;
        if (pos > 0)
        {
            prev = setpos(pos - 1);
            follow = prev->next;
            Item->next = follow;
            prev->next = Item;
        }
        else
        {
            follow = head;
            Item->next = follow;
            head = Item;
        }
        count++;
        return 1;
    }
    bool retrive(int pos, T &item)
    {
        if (empty())
            return 0;
        if (pos < 0 || pos >= count)
            return 0;
        node<T> *s = setpos(pos);
        item = s->data;
        return 1;
    }
    bool replace(int pos, T item)
    {
        if (empty())
            return 0;
        if (pos < 0 || pos >= count)
            return 0;
        node<T> *p = setpos(pos);
        p->data = item;
        return 1;
    }
    bool remove(int pos)
    {
        node<T>*f;
        if (empty())
            return 0;
        if (pos < 0 || pos >= count)
            return 0;
        if (pos == 0)
        {
            f = head;
            head = head->next;
            delete f;
        }
        else
        {
            node<T> *p = setpos(pos - 1), *f = p->next;
            p->next = f->next;
            delete f;
        }
        count--;
        return 1;
    }
    bool size()
    {
        return count;
    }
    list(list<T>&s){
        node<T>*q2,*newhead,*temp=s.head;
        if(temp!=0){
            q2=newhead=new node<T>(temp->data);
            while (temp->next!=0)
            {
                temp=temp->next;
                q2->next=new node<T>(temp->data);
                q2=q2->next;
            }
            head=newhead;
            count=s.count;
               
        }
    }
    void operator=(list<T>&t){
     while (!empty())
     {
         remove(0);
     }
     if(!t.empty()){
     int item;
    
     t.retrive(0,item);
     list<T> *s=new list(item);
     for (int i = 0; i < t.size(); i++)
     {
         t.retrive(i,item);
         s->insert(i,item);
     }
    
     }
  }
    ~list()
    {
        while (!empty())
        {
            remove(0);
        }
    }


};
//functions 
template<class T>
bool reverse(list<T>&s){
if(s.empty())return 0;
int i=0,j=s.size()-1,first,last;
while (i<=j)
{
  s.retrive(i,first);
   s.retrive(j,last);
   s.replace(j,first);
   s.replace(i,last);
   i++;
   j++;

}
return 1;
}
template<class T>
void print(list <T>a){
    T item;
    for (int i = 0; i < a.size(); i++)
    {
       a.retrive(i,item);
       cout<<item<<endl;
    }
    
}
template<class T>
void fill(list <T>&a,int size){
    for (int i = 0; i < size; i++)
    {
       a.insert(a.size(),rand()%100);
    }
    
}
list<int>*odditems(list<int>l1,list<int>l2){
    int item;
    list<int>*l3=new list<int>();
    for (int i = 0; i < l1.size(); i++)
    {
        l1.retrive(i,item);
        if(item%2!=0)
        l3->insert(l3->size(),item);
    }
    for (int i = 0; i < l2.size(); i++)
    {
        l2.retrive(i,item);
        if(item%2!=0)
        l3->insert(l3->size(),item);
    }
    return l3;

}
int main(){
    list<int>a;
    a.insert(0,8);
    a.insert(1,4);
    a.insert(2,5);
    a.insert(3,6);
    print(a);

}