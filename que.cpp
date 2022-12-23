include <iostream>

using namespace std;
class node
{
    public:
        int data;
        node* next;
    node()
    {
    data = 0;
    next = nullptr;
    }
};
class que
{
    public:
       node* front;
       node* rear;
       que()
       {
           front = rear = nullptr;
       }
       bool isempty();
       int enqueue(int item);
       int dequeue();
       void display();
       int getfront();
       int getrear();
       int countitem();
       bool isfound(int item);
       void clean();
};
bool que::isempty()
{
    if((front == nullptr)&&(rear == nullptr))
        return true;
        else
        return false;

}
 int que::enqueue(int item)
 {
     node* p =new node();
     p->data = item;
     if(isempty())
     {
         front = rear = p;
     }
     else
     {
         rear->next = p;
         rear = p;
     }
 }
 void que::display()
 {
     if(isempty())
     {
         cout<< "q empty\n";
     }
     else{
   node* p = front;
  while(p!= nullptr)
  {
      cout << p->data << "\t";
      p = p->next;
  }
  cout << endl;
     }
 }
 int que::dequeue()
 {
     int delvalue = -1;
     if(isempty())
        cout<< "queue is empty \n";
     else if(front == rear){
        delete front ;
     front = rear = nullptr;
     }
     else
     {
         node* del = new node();
         front = front->next;
         delvalue = del->data;
         delete del;

     }
     return delvalue;
 }
 int que::getfront()
 {
     return front->data;
 }
int que::getrear()
 {
     return rear->data;
 }
 int que::countitem()
 {
     int counter;
 node* p = front;
  while(p!= nullptr)
  {
  counter++;
  p=p->next;
  }
  return counter;
 }
 bool que::isfound(int item)
 {
     bool found = false;
     node* p = front;
  while(p!= nullptr)
  {
  if(p->data == item)
    found = true;
    p=p->next;
  }
  return found;

 }
 void que::clean()
 {
     while(!isempty())
     {
         dequeue();
     }
 }
int main()
{
    cout << "Hello world!" << endl;
        que q;
    for(int i=0; i < 3; i++)
    {
        int item;
        cout<<"enter item\n";
        cin>>item;
        q.enqueue(item);
    }
    q.display();
   /* cout<< q.getfront() << endl;
      cout<< q.getrear() << endl;
    q.dequeue();
    cout<< "after dequeue\n";
    q.display();
     q.dequeue();
     cout<< "after dequeue again\n";
    q.display(); */
    cout<< "clear\n";
    q.clean();
    cout<< "display after clean\n";
    q.clean();
    q.display();

    return 0;
}
