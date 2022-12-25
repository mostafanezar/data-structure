#include <iostream>

using namespace std;
class node
{
    public:
        int data;
        node* next;

};
class stack1
{
    node* head ;
    public:
        stack1()
        {
            head = nullptr;
        }
void push(int d);
int pop();
bool isempty();
void display();
int peek();
int countitem();
bool isfound(int item);
bool isfull();
};
bool stack1::isempty()
{
    if(head==nullptr)
        return true;
        else
            return false;

}
bool isfull()
{
    node* p = new node();
    if(p == nullptr)
        cout<< "stack is full\n";
}
void stack1::push(int d)
{
    node* p = new node();
    p->data = d;
    if(isempty())
    {
    p->next =nullptr;
    head = p;
    }
    else
    {
        p->next =head;
        head = p;

    }
}
int stack1::pop()
{   int value = head->data;
    node* q = head;
     head = head->next;
     delete q;
     return value;
}
void stack1::display()
{
    node* p = head;
    while(p!=nullptr)
    {
        cout<< p->data<<"\t";
        p = p->next;
    }
     cout << endl;
}
stack1::countitem()
{   int counter = 0;
    node* p = head;
    while(p!=nullptr)
    {
        counter++;
        p = p->next;
    }
    return counter;
}
int stack1::peek()
{
    return head->data;
}
bool stack1::isfound(int item)
{
    bool found = false;
     node* p = head;
    while(p!=nullptr)
    {
    if(p->data == item)
        found= true;
    p = p->next;
    }
    return found;
}
int main()
{
    cout << "Hello world!" << endl;
    int item;
    stack1 s;
    for(int i; i<3;i++)
    {
        cout<< "enter item\n";
        cin>>item;
        s.push(item);
        s.display();
    }
    //  cout<<s.pop()<<"was deleted \n";
   //  s.display();
  //   cout<<s.pop()<<"was deleted \n";
 //   s.display();
 cout<<s.countitem() <<endl;

cout << "enter item to search for\n";
cin>>item;
   if(s.isfound(item))
    cout << "is found\n";
   else
    cout << "not found\n";


    return 0;
}
