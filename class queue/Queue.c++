#include<iostream>

#include<stack>
using namespace std;
const int maxSize=20;
template<class T>
class queue{
int count,front,rear;
T entry[maxSize];
public:
queue(){
front,count=0;
rear=maxSize-1;
}
// check if it is empty ot not 
bool Empty(){
return count==0;
}
// push a value to the rear 
bool append(T item)
{
    if (count==maxSize)
    return false;
    // rear++;
    // if (rear==maxSize)
    // rear=0;
    // line 26 insted of 22-24
    rear=(rear+1)%maxSize;
    entry[rear]=item;
    count++;
    return true;
}
//delete values
bool serve(){
    if(Empty())
     return 0;
     front =(front+1)%maxSize;
     count--;
     return true;
}
//assign the front value to an item
bool retrieve(T&item)
{
    if(Empty())
    return 0;
    item=entry[front];
    return true;
}
};
// functions 
template<class T>
void print (queue<T> a){
      int o=0;
    while (!a.Empty())
    {      
       T item;
        a.retrieve(item);
        cout <<"value # "<<o++<<"--> "<<item << endl;
        a.serve();
    }
 }
template<class T>
void fill(queue <T>& q,int n){
for (int i = 0; i < n; i++)
{
  q.append(rand()%100);
}
}
void removeMin(queue <int> &q){
    if(!q.Empty()){
    queue<int> t;
    int min,item;
    q.retrieve(min);

    while (!q.Empty())
    {
         q.serve();  
       q.retrieve(item);          
       if (item<=min){
        t.append(min); 
        min=item; 
       }
       else if(item>min)
       t.append(item);  
      
    }   
    while (!t.Empty())
    {
       t.retrieve(item);
       t.serve();
       q.append(item);  
    }  
    } 
}
int main(){
queue <int> q;
stack<int>s;
s.top();
fill(q,6);
print(q); 
removeMin(q);
cout<<"----------\n\n\n";
print(q);
// int teger;
// q.append(0);
// q.append(1);
// q.append(2);
// q.append(3);
// q.retrieve(teger);
// cout<<teger<<endl;
// q.serve();
// q.serve();
// q.serve();
// q.retrieve(teger);
// cout<<teger<<endl;
cout<<"\n\ndn\n";
}
