#include <iostream>
using namespace std;
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
void print(node<int>*head)
{
    while (head != 0)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
bool addFirst(node<int> *&head, int item)
{
    node<int> *t = new node<int>(item);
    if (t == 0)
        return 0;
    t->next = head;
    head = t;
    return 1;
}
bool addLast(node<int> *&head, int item)
{
    node<int> *t = new node<int>(item);
    if (t == 0)
        return 0;
    if (head == 0)
        head = t;
    else
    {
        node<int> *p = head;
        while (p->next != 0)
        {
            p = p->next;
        }
        p->next = t;
    }
    return 1;
}
bool add(node<int> *&head, int item)
{
    node<int> *temp = new node<int>(item);
    if (temp == 0)
        return 0;
    node<int> *p, *f;
    p = f = head;
    while ( f != 0 && f->data < item)
    {
        p = f;
        f = f->next;
    }
    temp->next = f;
    if (p == f)
        head = temp;
    else
        p->next = temp;
    return 1;
}
void fill(node<int> *&head, int n)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        x = rand() % 100;
        addFirst(head, x);
    }
}
bool delFirst(node<int> *&head)
{
    if (head == 0)
        return 0;
    node<int> *h = head;
    head = head->next;
    delete h;
    return 1;
}
bool delLast(node<int> *&head)
{
    if (head == 0)
        return 0;
    node<int> *a, *b;
    a = b = head;
    while (b->next != 0)
    {
        a = b;
        b = b->next;
    }
    if (a == b)
        head = 0;
    else
        a->next = 0;
    delete b;
    return 1;
}
bool delItem(node<int> *&head, int item)
{
    if (head == 0)
        return 0;
    int c = 0, s = 0;
    node<int> *a;
    node<int> *b;
    a = b = head;
    while (b->next != 0)
    {
        a = b;
        b = b->next;
        if (s == 0)
        {
            if ((item) == (a->data))
            {
                head = b;
                delete a;
                c++;
                break;
            }
            s++;
        }
        if ((item) == (b->data))
        {
            a->next = b->next;
            delete b;
            c++;
            break;
        }
    }

    if ((a == b) && item == head->data)
        head = head->next;
    return c;
}
bool destroy(node<int> *&head)
{
    node<int> *a;
    node<int> *b;
    a = head;
    head = 0;
    while (b != 0)
    {
        a = b;
        b = b->next;
        delete a;
    }
    cout << "it is empty now\n";
    return 1;
}
void empty(node<int> *&head)
{
    while (head != 0)
    {
        delFirst(head);
    }
    // cout<<"it is emptyy now \n";
}
void delodd(node<int> *&head)
{
    if (head != 0)
    {
        node<int> *h2 = head;
        node<int> *h3 = 0;
        while (h2 != 0)
        {
            if (((h2->data) % 2) == 0)
            {
                addLast(h3, h2->data);
            }
            h2 = h2->next;
        }
        empty(head);
        head = h3;
        // cout<<"dn\n";
    }
}
void delodd2(node<int> *&head)
{
    if (head != 0)
    {
        node<int> *a = head, *b = new node<int>(0), *add = b;
        while (a != 0)
        {
            if (a->data % 2 == 0)
            {
                add->next = new node<int>(a->data);
                add = add->next;
            }
            a = a->next;
        }
        add = b;
        b = b->next;
        delete add;
        while (head != 0)
        {
            a = head;
            head = head->next;
            delete a;
        }
        head = b;
    }
}
bool delmin(node<int> *&head)
{
    if (head == 0)
        return 0;
    node<int> *s = head->next;
    int min = head->data;
    while (s != 0)
    {
        if (s->data < min)
        {
            min = s->data;
        }
        s = s->next;
    }
    delItem(head, min);
    // s = head;
    // node<int> *c = s;
    // int f = 0;
    // while (s != 0)
    // {
    //     c = s;
    //     s = s->next;
    //     if (f == 0)
    //     {
    //         if (c->data == min)
    //         {
    //             head = s;
    //             delete c;
    //             break;
    //         }
    //     }
    //     if (s->data == min)
    //     {
    //         c->next = s->next;
    //         delete s;
    //         break;
    //     }
    // }
    // if ((s == c) && min == head->data)
    //     head = head->next;
    return 1;
}
bool merge(node<int> *&head, node<int> *&head2)
{
    node<int> *h = head;
    while (h->next != 0)
    {
        h = h->next;
    }
    h->next = head2;
    return 1;
}
bool mergeeven(node<int> *&head, node<int> *&head2)
{
    merge(head, head2);
    delodd(head);
    return 1;
}
bool delfromAtoB(node<int> *&head, int a, int b)
{
    if (head == 0)
    {
        cout << "the linked list is empty !\n";
        return 0;
    }
    node<int> *after1;
    node<int> *before2;
    node<int> *before1;
    node<int> *before3;
    after1 = before1 = head;

    while (before1->data != a)
    {
        before1 = before1->next;
        if (before1 == 0)
        {
            cout << "error: first number not found!\n";
            return 0;
        }
    }
    // cout << "s\n";
    while (after1->data != b)
    {
        after1 = after1->next;
        if (after1 == 0)
        {
            cout << "error: second number not found!\n";
            return 0;
        }
    }
    before2 = before1->next;
    before3 = before2;
    int c = 0;
    while (before2->data != b)
    {
        before3 = before2;
        before2 = before2->next;
        delete before3;
        c++;
    }
    if (c == 0)
        cout << "hey there is no numbers between" << a << "and" << b << endl;
    // delete before2;
    before1->next = after1;
    return 1;
}
bool addAfterX(node<int> *&head, int x, int item)
{
    if (head == 0)return 0;
    node<int> *p = head;
    node<int> *f = head;
    node<int> *temp2 = new node<int>(item);
     p = f;
    f = f->next;
    if(p->data==x){
         p->next = temp2;
    temp2->next = f;
    }

    while (p->data != x)
    {
       
        p = f;
        f = f->next;
        if (p == 0)
        {
            return 0;
        }
    }
    p->next = temp2;
    temp2->next = f;
    return 1;
}
//  bool returnfromAtoB(node<int> *&head, int a, int b)
// {
//     // need to change
//     if (head == 0)
//     {
//         cout << "the linked list is empty !\n";
//         return 0;
//     }
//     node<int> *newhead=new node<int>();
//     node<int> *after1;
//     node<int> *after2;
//     node<int> *before1;
//     node<int> *before2;      
//     after1 = before1 = head;
//     while (before1->data != a)
//     {
//         before2=before1;
//         before1 = before1->next;
//         delete before2;
//         if (before1 == 0)
//         {
//             cout << "error: first number not found!\n";
//             return 0;
//         }
//     }
//     // cout << "s\n";
//      int c = 0;
//     while (after1->data != b)
//     {
//         addLast(newhead,after1->data);
//         after1 = after1->next;
//         c++;
//         if (after1 == 0)
//         {
//             cout << "error: second number not found!\n";
//             return 0;
//         }
//     }
   
//     while (after1!=0)
//     {
//         after2=after1;
//         after1 = after1->next;
//         delete after2;
//     }
//     if (c == 0)
//         cout << "hey there is no numbers between" << a << "and" << b << endl;
//     // delete before2;
//    empty(head);
//    head=newhead;
//     return 1;
// }
int main()
{
    // int s;
    node<int> *head = NULL;
    // node<string> *t = new node<string>(item);
    // t->next=head;
    fill(head, 7);
    // print(t);
    cout << "------\n";
    // addLast(head,1);
//    returnfromAtoB(head, 0, 67);
    print(head);
    cout << "------\n";
    addAfterX(head,41,2);
    // delItem(head,78);
      print(head);

    cout << "done\n";
    // node<int>n1,n2(10);
    // node<int> *head2 = NULL;
    // head=&n1;
    // head->data=10;
    // // n1.next=&n2;
    // head->next=&n2;
    // head->next->data=5;
    // addFirst(head,6);R
    // addLast(head,8);
    // addLast(head,776);
    // add(head,55);
    // add(head,12);
    // fill(head2, 4);`
    // add(head,8);
    // cout<<"sdafa\n";`
    // delFirst(head);`
    //  print(head2);
    // cout<<"------\n";
    // delItem(head,0);
    // print(head);
    // cout<<"------\n";
    // delItem(head,24);
    // print(head);
    // // // delLast(head);
    // // // delLast(head);
    // // // empty(head);
    // delodd2(head);
    // delmin(head);
    // print(head);
    // cout << "------\n";
    // delmin(head);
    // print(head);
    // cout << "------\n";
    // delmin(head);
    // print(head);`
    // mergeeven(head,head2);`
}