#include<iostream>
#include<stack>
using namespace std;
#define max 100
#define maxSize 100
// const int maxsize= 10;
template <class T> 
struct node

{
    T data;
    node<T>* next;
    node() { next = 0; }
    node(T item)
    {
        data = item;
        next = 0;
    }
};
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
template <class T>
class list{
   T entry[max];
   int count;
   public:
   list(){count=0;}
   bool empty(){
       return count==0;
   }
   int size(){
       return count;
   }
   bool insert(int pos,T item)
   {
       if(pos>=max) return 0;
       if(pos<0||pos>count) return 0;
      for (int i = count-1; i>=pos; i--)
      {
          entry[i+1]=entry[i];
      }
       entry[pos]=item;
       count ++;
       return 1;
   }
   bool remove(int pos){
       if(empty())return 0;
       if(pos<0||pos>count) return 0;
       for (int i = pos; i <count-1; i++)
       {
           entry[i]=entry[i+1];
       }
       count --;
       return 1;
   }
   bool retrive(int pos,T & item ){
   if (empty())return 0;
   if(pos<0||pos>=count) return 0;
    item=entry[pos];
    return 1;

   }
   bool replace(int pos,T item){
       if(empty()||pos<0||pos>=count) return 0;
       entry[pos]=item;
       return 1;
   }
};
//functions 
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
bool removemax(list<int>&a){
if(a.empty())return 0;
int item,positi;
int mx;
a.retrive(0,mx);
for (int i = 1; i < a.size(); i++)
{
    a.retrive(i,item);
    if (item>mx){
        mx=item;
        positi=i;
    }
   
}
 a.remove(positi);
return 1;
}
bool removeven(list<int>&a){
    if(a.empty())return 0;
    int item;
    for (int i = a.size()-1; i > 0; i++)
    {
        a.retrive(i,item);
        if(item%2==0) a.remove(i);
    }
    return 1;
}
template<class T>
bool reverseusingstack(list<T>&a){
if(a.empty())return 0;
int item;
stack<T> s;
for (int i = 0; i < a.size(); i++)
{
    a.retrive(i,item);
    s.push(item);
}
for (int i = 0; i < a.size(); i++)
{
     s.top(item);
    a.replace(i,item);
    s.pop();
}
}

void dod (list<int>&L){

int item, x=L.size();

for(int i=0;i<x;i++)

{ 
    L.retrive(i,item);
    
     L.insert(L.size(),item);
      L.remove(i);
      }

}
int main(){
    list<int> s;
    //  fill(s,6);
    s.insert(0,10);
    s.insert(1,20);
    s.insert(2,30);
    dod(s);
    // cout<<"size:"<<s.size()<<endl;
    // // print (s);`
    // cout<<"size before : "<<s.size()<<endl;
    //  reverseusingstack(s);
    print (s);
    //  cout<<"size after :"<<s.size()<<endl;

}