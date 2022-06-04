#include<iostream>
using namespace std;
template<class T>
struct node{
T data;
node<T>*next;
node(){ 
next=NULL;   
}
node(T item){
data =item;
next=NULL;
}

};
int size(node<int>*head){
    int s=0;
    while (head!=0)
    {
        head=head->next;
        s++;
    }
    return s;
}
bool addFirst(node<int>*&head,int value){
  node <int>*n=new node<int>(value);
  if (n==0)return 0;
  n->next=head;
  head=n;
return 1;
}
bool addLast(node<int>*&head,int value){
    node <int>*n=new node<int>(value);
    if(n==0)return 0;
    if(head==0) head=n;
    else{
    node <int>*h=head;
      while(h->next!=NULL){
       h=h->next;
      }
      h->next=n;
      }
return 1;
}
bool addAnywhere(node<int>*&head,int pst,int value)
{
    if(pst==0||head==NULL) addFirst(head,value);
   else if(pst==size(head)) addLast(head,value);
    else
    {
    node<int>* n=new node<int>(value);
    if(n==0)return 0;
    node <int>* h=head;
    for (int i = 0; i < pst-1; i++)
    {
       h=h->next;
    }
    node<int>*u=h->next;
    h->next=n;
    n->next=u;
    return 1;
    }
return 1;

}
void print(node<int>*p){
while (p!=0)
{
    cout<<p->data<<endl;
    p=p->next;
}
}
void fill(node<int>*&head,int n){
int x;
for (size_t i = 1; i <= n; i++)
{
    x=rand()%100;
    addAnywhere(head,i-1,x);   
}
}
bool delFirst(node<int>*&head){
  if(head==0)return 0;
  node<int>*h=head;
  head=head->next;
  delete h;
  return 1;
}
bool delLast(node<int>*&head){
  if(head==0)return 0;
  if(size(head)==1) head=0;
  node<int>*h1=head;
  node<int>*h2=head;
  int c=0;
  while (h2->next!=0)
  {
      h1=h2;
      h2=h2->next;
      c++;
  }
  // for (int i = 0; i <= c-2; i++)
  // {
  //    h1=h1->next;
  // }
  h1->next=NULL;
  delete h2;
  return 1;
}
bool delItem(node<int>*&head,int item){
node<int>*h1=head;
node<int>*h2=head;
while (h2!=NULL)
{
  // cout<<"SDA\n";
   if(h2->data==item)
  {
    h1->next=h2->next;
    delete h2;
    break;
  
  }
  h1=h2;
  h2=h2->next;
 
}

if(head==0)return 0;
else if(size(head)==1) head=head->next;
return 1;
}
void destroy(node<int>*& head){
node<int>* h;
while (head!=0)
{
  h=head;
  head=head->next;
  delete h;
}

cout<<"deleted whole\n";
}
void empty(node<int>*& head){
  while (head!=0)
  {
    delFirst(head);
  }
  // cout<<"it is empty\n";
}
void deleteodd1(node<int>*& head){
node<int>* p=head;
node<int>*temp=0;
while(p!=0)
{
  if ((p->data)%2==0)
  addLast(temp,p->data);
  p=p->next;
}
empty(head);
head=temp;
// cout<<"what?\n";
}
void deleteodd2(node<int>*& head){
if (head!=0)
{
  node<int>*head1=new node<int>();
  node<int>*p=head,*q=head1;
  while (p!=0)
  {
    if(p->data%2==0)
    {
      q->next=new node<int>(p->data);
      q=q->next;
    }
    p=p->next;
  }
  q=head1;
  head1=head1->next;
  delete q;
  while(head!=0)
  {
    p=head;
    head=head->next;
    delete p;
  }
  head=head1;
}
}
void deleteodd3(node<int>*& head){
node <int>*temp=new node<int>();
node<int>*h1=head,*h2=temp;
while (h1!=0)
{
  if(h1->data%2==0)
  {    
      h2->next= new node<int>((h1->data));
     
       h2=h2->next;
  }     
  h1=h1->next; 
}
  h2=temp;
  temp=temp->next;
  delete h2;
while (head!=0)
{
  h1=head;
  head=head->next;
  delete h1;
}
head=temp;

}
bool delmin(node<int>*&head){
if(head==0)return 0;
int min=head->data;
node<int>*h=head->next;

while (h!=0)
{
  
  if(min>(h->data))
  min=h->data;
  h=h->next;
}
delItem(head,min);
return 1;
}

int main(){
node <int> n1,n2,n3(30);
node <int>*head=0;
// head=& n1;
// n1.data=10; //head->data=10;
// n1.next=&n2; //head->next=&n2;
// n2.data=20; // head->next->data=20; // n1.next->data=20;
// n2.next=&n3; // head->next->next=&n3;
// n3.data=30;
// n3.next=0;
// head->next->next->next=new node<int>(40);
// addAnywhere(head,5,88);
// print(head);
cout<<"---------\n";
// addFirst(head,99);
// addLast(head,87);
fill(head,7);
print(head);
cout<<"----------\n";
delItem(head,41);
//  deleteodd3(head);
// delmin(head);
//  print(head);
//  cout<<"----------\n";
//  delmin(head);
 print(head);
// empty(head);
//  print(head);
// delFirst(head);
// print(head);
// cout<<"----------\n"; 
// delLast(head);
// print(head);
// cout<<"----------\n";
// delLast(head);
// print(head);
// cout<<"----------\n";
// delFirst(head);
// print(head);
// cout<<"size "<<size(head)<<endl;
// cout<<"-----------\n";
// cout<<"done\n";
cout<<"----------\ndn\n";
}