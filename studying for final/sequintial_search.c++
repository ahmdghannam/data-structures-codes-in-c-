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
        return q;
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
            node<T>* p = setpos(pos-1), *f = p->next;
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
template<class T>
class orderedList:public list<T>
{
//      bool empty(){
//        return count==0;
//    }
public: 
bool insert(T item)
{
    T data;
    int pos;
    for (pos = 0; pos <list<T>::size (); pos++)
    {
      list<T>:: retrive(pos,data);
       if(data>=item)
       break;

    }
    return list<T>::insert(pos,item);
}
};
template<class T>
void filloredered(orderedList<T>&L,int n){
    for (int i = 0; i < n; i++)
    {
        L.insert(rand()%101);
    }
    
}
template<class T>
void print(orderedList<T>L){
    int item;
    int pos=0;
while(!(L.empty()))
{
    L.list<T>::retrive(pos,item);
    cout<<item<<endl;
pos++;
    
}



}
int main(){
orderedList<int>L;
filloredered(L,100);
print(L);

}