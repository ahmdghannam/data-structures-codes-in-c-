#include<iostream>
using namespace std;
//node it self
template <class T>
struct node{
T data;
node<T>*next;
node(){
    next=0,data=0;
}
node(T data){
    next=0;
    this->data=data;
}

};
//stack
template<class T>
class stack{
node<T>* topIndex;
stack(){topIndex=0;}
public:
bool empty(){
    return topIndex==0;
}
bool push(T item){
    node<T>*temp=new node<T>(item);
    if(temp==0)return 0;
    temp->next=topIndex;
    topIndex=temp;
    return 1;
}
bool pop(){
    if(empty())return 0;
     node<T>*temp=topIndex;
     topIndex=topIndex->next;
     delete temp;
    return 1;
}
bool top(T &item){
    if(empty())return 0;
    item=topIndex->data;
    return 1;
}
stack(stack<T>&s){
    node<T>*p=s.topIndex;
    stack<T>ss;

    while (!empty())
    {
        pop();
    }
    while (p!=0)
    {
        ss.push(p->data);
        p=p->next;
    }
    topIndex=ss.topIndex;
    
}
void operator=(stack<T>&s){
    if(!s.empty()){
        while (!empty())
        {
            pop();
        }
       node<T>*temp=s.topIndex;
       stack<T>ss;
        while (temp!=0)
        {
            ss.push(temp->data);
            temp=temp->next;
        }
        topIndex=ss.topIndex;
    }
}
~stack(){
    while (topIndex!=0)
    {
         node<T>*temp=topIndex;
         topIndex=topIndex->next;
         delete temp;
    }
    
}

};
template<class T>
class queue{
int count ;
node<T>*rear,*front;
public :
queue(){
    count=0;
    rear=0;
    front=0;
}
bool empty(){
    return count ==0;
}
bool append(int item){
    node<T>*temp=new node<T>(item);
    if(temp==0)return 0;
    if(rear==0){
        rear=front=temp;
    }
    else{
    rear->next=temp;
    rear=temp;
    }
    return 1;
}
bool serve(){
 if(empty())return 0;
 node<T>*p=front;
 front=front->next;
 if(front==0)rear=0;
 delete p;
 count --;
 return 1;   
}
bool retrive(T &item){
    if(empty())return 0;
    item=front->data;
    return 1;
}
int size(){
    return count;
}
void operator=(queue<T>&q)
{
    while (!empty())
    {
        serve();
    }
    if(!q.empty()){
        
    }

}
~queue(){
    while (!empty())
    {
        serve();
    }
    
}
};

//functions
template<class T> 
bool addFirst(node<T>*&head,T item){
node<T>*temp=new node<T>(item);
if(temp==0)return 0;
temp->next=head;
head=temp;
return 1;
}
template<class T>
bool addLast(node<T>*&head,T item){

node<T>*temp=new node<T>(item);
if(temp==0)return 0;
if(head==0){
    head=temp;
}    
else{
node<T>*h=head;
while (h->next!=0)
{
    h=h->next;
}
h->next=temp;
}
return 1;
}
template<class T>
bool print(node<T>*head){
    if(head==0)
    cout<<"it is empty\n";
while (head!=0)
{ 
    cout<<head->data<<endl;
    head=head->next;
}
return 1;
}
template<class T>
bool fill(node<T>*&head,int s){
for (int i = 0; i < s; i++)
{
  addFirst(head,rand()%101);
}
return 1;
}
template<class T>
bool add(node<T>*&head,T data,int pos){
node<T>*temp=new node<T>(data);
if(temp==0)return 0;
node<T>*h2,*h1=head;
if(head==0)head=temp;
else{
    if(pos==0)
    {
        temp->next=head;
        head=temp;
    }
    else{
for (int i = 0; i < pos-1; i++)
{
    h1=h1->next;
}
h2=h1->next;
h1->next=temp;
temp->next=h2;
}}
return 1;
}
template<class T>
bool delFirst(node<T>*&head){
    if(head==0)return 0;
    node<T>*h=head;
    head=head->next;
    delete h;
    return 1;
}
template<class T>
bool delLast(node<T>*&head){
    if(head==0)return 0;
    node<T>*h=head;
    node<T>*h2=head;
    if(head->next->next==0)
    head=0;
    else{
    while (h->next!=0)
    {
        h2=h;
        h=h->next;
    }
    h2->next=0;
    }
    delete h;
    return 1;
}
template<class T>
bool delItem(node<T>*&head,T item){
    node<T>*h1=head;
    node<T>*h2=head;
    while (h2->next!=0&&h2->data!=item)
    {
        h1=h2;
        h2=h2->next;
    }
    if(h2==0)return 0;
    else if(h1==h2)head=head->next;
    else h1->next=h2->next;
    h1=h2->next;
    delete h2;
    return 1;
}
template<class T>
bool destroy(node<T>*&head){
    if(head==0 )return 0;
    while (head!=0)
    {
        node<T>*h=head;
        head=head->next;
        delete h;
    }
    // head=0;
    return 1;
}
bool delodd(node<int>*&head){
if(head==0)return 0;
node<int>*h=head;
node<int>*newhead=new node<int>;
node<int>*nh=newhead;
while (h!=0)
{
   
    if(h->data%2==0){
    nh->next=new node<int>(h->data);
    nh=nh->next;
    }
     h=h->next;
}
h=newhead;
newhead=newhead->next;
delete h;
while (head!=0)
{
    h=head;
    head=head->next;
    delete h;
}
head=newhead;
return 1;


}
bool delmin(node<int>*&head){
if(head==0)return 0;
int min=head->data;
node<int>*p=head->next;
node<int>*p2=head;
while (p!=0)
{
    if(p->data<min)
    min=p->data;
    p=p->next;
}
if(head->data==min){
head=head->next;
delete p2;
}
else{
while (p2!=0)
{
    p=p2;
    p2=p2->next;
    if(p2->data=min){
    p->next=p2->next;
    delete p2;
    break;
    }
}
}
return 1;
}

int main(){
node<int>*a;
fill(a,10);
addFirst(a,100);
 addLast(a,1);    
print(a);

cout<<"------\n";
delmin(a);
print(a);
cout<<"done\n";
}