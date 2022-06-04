#include <iostream>
using namespace std;
class point{
int x,y;
public :
point(int x1,int y1){
   x=x1;
   y=y1;
}
 point(){
     x=y=0;
}
void set1(int x1,int y1){
    x=x1;
    y=y1;
}
int getx() {return x;}
int gety() {return y;}
void operator ++(){
    x++;
    y++;
}
void operator +(int a){
    x+=a;
}
point operator +(point a){
    point temp;
    temp.x=x+a.x;
    temp.y=y+a.y;
    return temp;
}
void operator =(point& p){
this->x=2*p.x;
this->y=2*p.y;
}
};

int main(){
point p1 (6,5);
point p2;
point p3(2,4);
cout<<p2.getx()<<"\t"<<p2.gety()<<endl;
 ++p2;
cout<<p2.getx()<<"\t"<<p2.gety()<<endl;
p2+9;
cout<<p2.getx()<<"\t"<<p2.gety()<<endl;
// p2=p1+p3;
p2=p1;
cout<<p2.getx()<<"\t"<<p2.gety()<<endl;
}