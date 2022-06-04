#include <iostream>
using namespace std;
template<class T>
struct node{
T data;
node<T>*left,*right;
node(){
    left=right=0;
}
node(T item){
  left=right=0;
    data=item;
}
};
int main(){

node<int>*s=new node<int>(10);
cout<<s->data;
cout<<endl<<s->left<<endl<<s->right<<endl;
cout<<"done\n";
}