#include <iostream>

using namespace std;
class node
{
private:
     public:
         int data;
         node* next;
        node()
        {
            data = 0;
            next = nullptr;
        }
};
class linkedlist
{
    private:
        node* head=new node();
         public:
        linkedlist()
        {
            head = nullptr;
        }
        ~linkedlist()
        {
            node* p;
            while(p!=nullptr)
            {
                p=head;
                head=head->next;
                delete p;
            }
        }
        bool isempty();
        void addtohead(int item);
        void addtotail(int item);
        void displaylist();
        int countlist();
        int deletefromhead();
        int deletefromtail();
        int findnode(int x);

};
bool linkedlist::isempty()
{
    return head == nullptr;
}
void linkedlist::addtohead(int item)
{
node* p = new node();
p->data = item;
p->next =head;
head = p;
}
void linkedlist::addtotail(int item)
{
    node* p = new node();
    p->data =item;
    node* q = head;
    while(q->next!=nullptr)
        q=q->next;
    q->next=p;
}
void linkedlist::displaylist()
{
    if(isempty())
    {
        cout<< "empty list ";
    }
    else{
    node* p = head;
    while(p!=nullptr)
    {
        cout<<p->data << endl;
        p=p->next;
    }
    }
}
int linkedlist::deletefromhead()
{
    int x;
    if(head == nullptr)
    {
        cout<< "empty list\n";
        exit(0);
    }
    else if(head->next==nullptr)
    {
        x=head->data;
        delete head;
        return x;
    }
    else
    {
        node* p =head;
        head = head->next;
        x = p->data;
        delete p;
        return x;
    }
}
int linkedlist::deletefromtail()
{
 int x;
    if(head == nullptr)
    {
        cout<< "empty list\n";
        exit(0);
    }
    else if(head->next==nullptr)
    {
        x=head->data;
        delete head;
        return x;
    }
    else
    {
        node* p = head,*q;
        while(p->next!=nullptr)
        {
            q=p;
            p=p->next;
        }
        x=p->data;
        delete p;
        q->next=0;
        return x;
    }
}
int linkedlist::countlist()
{
    int counter;
    node* p =head;
    while(p!=nullptr)
    {
        counter++;
        p=p->next;
    }
    return counter;
}
int linkedlist::findnode(int x)
{
    node* p =head;
    while(p->next!=nullptr){
    {
    if(p->data=x)
    return x;
    }
     p=p->next;
    }
        cout<< "not found";
        return 0;

}
int main()
{
    cout << "Hello world!" << endl;
    linkedlist q;
    q.addtohead(3);
    q.addtohead(2);
    q.addtohead(1);
    q.addtotail(100);
    q.addtotail(200);
    q.addtotail(300);
    q.deletefromhead();
    q.deletefromtail();
    q.displaylist();
    cout<<q.countlist()<<endl;
    cout<<q.findnode(0);
    return 0;
}
