#include<iostream>
using namespace std;
const int maxsize= 10;
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
class queue{
 node<T>*rear,*front;
 int count;
 public:
 queue(){
     rear=front=0;
     count=0;
 }   
 bool empty(){
     return (rear==0&&front==0);
     //return count==0; 
 }
 bool append (T item){
     node<T>*temp=new node<T>(item);
     if(temp==0) return 0;
     if(rear==0)
     rear=front=temp;
     else
     {
         rear->next=temp;
         rear=temp;
     }
count++;
return 1;
 }
 bool serve()
 {
     if (empty())
         return 0;
     node<T> *temp = front;

     front = front->next;
     if (front==0)rear=0;
     delete temp;
     count --;
     return 1;
 }
 bool retrieve(T& item){
     if(empty())return 0;
     item=front->data;
     return 1;

 }
 int size(){
   return count;
 }
 // problem 3
 queue(queue<T>&q2){
    node<T>*t,*p=q2.front;
    if(p==0)
    rear=front=0;
    else{
    front=t=new node<T>(p->data);
    while (p->next!=0)
    {
        p=p->next;
        t->next=new node<T>(p->data);
        t=t->next;
    }
     rear=t;
     }
     count=q2.count;
 }
 //problem 2
 void operator=(queue<T>q2)
 {
   
     while (!empty())
     {
         serve();
     }
     if (!q2.empty())
     {
           node<T>*newF,*newR;
           node<T>*p=q2.front=newF=newR;
         newF=newR=new node<T>(p->data);
         while (p->next!=0)
         {
             p=p->next;
             newR->next=new node<T>(p->data);
             newR=newR->next;
         }
         front=newF;
         rear= newR;
         count=q2.count;
     }
   
 }
 // problem 1
 ~queue(){
     while (!empty())
     {
         serve();
     }
     
 }
};
int main(){
    cout<<"hello\b";
    queue<int>q1,q2;
    for (int i = 0; i < 6; i++)
    {
       q1.append(i);
       q2.append(i*4);
    }
    int x;
    q1.retrieve(x);
    cout<<x<<endl;
    q2.retrieve(x);
    cout<<x<<endl;
    q1=q2;
    q1.retrieve(x);
    cout<<x<<endl;
  
}