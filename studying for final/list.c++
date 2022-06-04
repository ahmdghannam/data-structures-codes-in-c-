#include<iostream>
#include<stack>
using namespace std;
#define max 20
template<class T>
class List{
protected:
int count ;
T entry[max];
public: 
List(){
    count=0;
}
// methods
bool empty(){
    return count==0;

}
int size (){
    return count ;
}
bool insert(int pos,T item){
    if (count>max)return 0;
    if(pos<0||pos>count)return 0;
    for (int i = count; i > pos; i--)
    {
      entry[i]=entry[i-1];
    }
    entry[pos]=item;
    count ++;
    return 1;
}
bool remove (int pos){
    if (pos>max)return 0;
    if (pos<0||pos>=count)return 0;
    for (int i = pos; i < count-1; i++)
    {
        entry[i]=entry[i+1];
    }
    count --;
    return 1;
}
bool retrive (int pos, T &item){
    if(empty())return 0;
    if(pos> max)return 0;
    if(pos<0||pos>=count)return 0;
   item= entry[pos];
   return 1;


}
bool replace(int pos, T item){
    if(empty())return 0;
    if (pos>max)return 0;
    if(pos<0||pos>=count)return 0;
    entry[pos]=item;
    return 1;
}
// bool print ()
// {
// for (int i = 0; i < count; i++)
// {
//     cout<<entry[i]<<endl;
// }

//     return 1;
// }

};
// functions 
bool print (List <int>l)
{
    if(l.empty())return 0;
    int item;
  for (int i = 0; i < l.size(); i++)
  {
     l.retrive(i,item);
     cout<<item<<endl;
  }
  return 1;
    
}
bool fill (List <int>&l,int s)
{
 for (int i = 0; i < s; i++)
 {
     l.insert(i,rand()%101);
 }
    return 1;
}
bool removemax(List<int>&l){
int pos;
int mx;
int item;
l.retrive(0,mx);
for (int i = 0; i < l.size(); i++)
{
    l.retrive(i,item);
    if(item>mx){
        pos=i;
        mx=item;
    }

}
l.remove (pos);
return 1;
}
bool removeeven(List<int>&l){
int item;
for (int i = 0; i < l.size(); )
{
    l.retrive(i,item);
    if(item%2==0)
    l.remove(i);   
    else i++; 
}

return 1;
}
bool removeodd(List<int>&l){
int item;
for (int i = l.size()-1; i >=0;i-- )
{
    l.retrive(i,item);
    if(item%2!=0)
    l.remove(i);   
    
}

return 1;
}
bool reverselist(List<int>&l){
stack<int>s;
int item;
for (int i = 0; i < l.size(); i++)
{
    l.retrive(i,item);
    s.push(item);
}
for (int i = 0; i < l.size(); i++)
{
    item=s.top();
    l.replace(i,item);
    s.pop();
}

return 1;
}
int main(){
List<int> a;
// a.insert(0,13);
// a.insert(1,8);
// a.insert(2,23);
// a.insert(3,288);
// a.remove(4);
fill(a,6);
// a.remove(4);
a.insert(0,288);
print(a);
reverselist(a);
cout<<"---------\n";
print(a);
// int item =1;
// a.retrive(4,item);
// cout<<"item:"<<item<<endl;
}