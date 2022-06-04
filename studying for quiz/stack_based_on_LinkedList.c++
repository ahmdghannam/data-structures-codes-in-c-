#include<iostream>

#include<queue>
#include<stack>
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
// template<class T>
// class stack{
// node<T>* topIndex;
// public : 
// stack(){
//     topIndex=0;
// }
// bool empty(){
//     return topIndex==0;
// }
// bool push(T item){
//     node<T> *temp=new node<T>(item);
//     if(temp==0) return 0;
//     temp->next=topIndex;
//      topIndex=temp;
//      return 1; 
// }
// bool pop(){
//     if(empty())return 0;
//     node<T> *temp=topIndex;
//     topIndex=topIndex->next;
//     delete temp;
//     return 1;
// }
// bool top(T &item){
//     if(empty()) return 0;
//    item= topIndex->data;
//    return 1;
// }
//  //sol of problem # 3
// stack (stack<int>&s){
//     cout<<"inside copy constructure\n";
//     node<T>*q;
//     node<T>*temp=s.topIndex;
//     if (temp==0){
//         this->topIndex=0;
//     }
//     else {
//         topIndex=q=new node<T>(temp->data);
//         while (temp->next!=0)
//         {
//             temp=temp->next;
//             q->next=new node<T>(temp->data);
//             q=q->next;
//         }
        
//     }
// }
//  //sol of problem # 2
// void operator=(stack<T>&s){
   
// cout<<"inside op over load\n";
// node<T>* newtop=0;
// if(!s.empty()){
//     node<T>*p=s.topIndex;
//     node<T>*ptr=newtop=new node<T>(p->data);
//     while (p->next!=0)
//     {
//         p=p->next;
//         ptr->next=new node<T>(p->data);
//         ptr=ptr->next;

//     } 
// }
// while (!this->empty())
// {
//     this->pop();
// }
// this->topIndex=newtop;
// }
//  //sol of problem # 1
// ~stack(){
//     while (!empty())
//     {
//         pop();
//     } 
// }
// };
// `
// int x;
// while (!s.empty())
// {
//     s.top(x);
//     cout<<x<<endl;
//     s.pop();
// }

// }
template<class T>
void fill(stack<T> &s, int n)
{
    for (int i = 1; i < n; i++)
    {
        s.push(rand() % 100);
    }
}
stack <int>*g(){
    stack<int>*s;
    fill(*s,6);
    return s;
}
void do(queue<int>&q){

stack<int>temp;

while(!q.empty()){
    temp.push(q.front()); q.pop();
    
    }

while(!temp.empty()){
    
    q.push(temp.top()); temp.pop();
}
}


int main(){

    queue<int>a;
//    f(*g());`
// int a=9;
// a+1;
// cout<<a;
//     cout<<"sdasd";
// stack <int> outer;
//  outer.push(10);   
//   outer.push(20);
//    outer.push(60);
//    int x;
//    outer.top(x);
//     cout<<"0 :"<<x<<endl;
//    f(outer);
//    outer.top(x);
//     cout<<"0.1 :"<<x<<endl;
//    {
//        stack <int> inner;
//        for (int i = 0; i <= 1000; i++)
//        {
//            inner.push(i);

//        }
//        inner.top(x);
//        cout<<"1 :"<< x<<endl;
//        inner=outer;
//        inner.top(x);
//        cout<<"2 : "<<x<<endl;
//    }//inner dead
//    outer.top(x);
//    cout<<"3 : "<<x<<endl;
// cout<<"\ndone\n";`


}//outer dead
