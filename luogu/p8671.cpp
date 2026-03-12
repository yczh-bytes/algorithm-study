#include <bits/stdc++.h>
using namespace std;
  struct Node
    {

        int val;
        Node* next;
         Node(int val = 0) : val(val), next(nullptr) {}
    };
class LinkedList
{
 
private:
Node* head;
Node* tail;
public:
 
LinkedList()
{
    head = new Node();
    tail = head;
    head->next = head;
}
~LinkedList()
{
    Node* p = head->next;
    while(p!=nullptr)
    {
head->next = p->next;
delete(p);
p = head->next;
    }
    delete(p);
}


void Insert(int val)
{

    Node* newNode = new Node(val);
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

void show()
{
    Node*p=head;
    while(p->next!=head)
    {p = p->next;
        cout<<p->val<<' ';
        
    }
}
void Josenor(int k)
{
    Node*p = head->next;
    Node*q = head;
    //一个死循环直至全部离开
    while(p->next!=head)
    {
        for(int i = 1;i<k;i++)
        {
            q = p;
            p = p->next;
        }
        //cout<<p->val<<' ';
       
       q->next = p->next;
            Node* temp = p;
            p = p->next;
            delete temp;

    }
    cout<<p->val;
    head->next = head;
    delete(p);
    
}
};



int main()
{
    LinkedList list;
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;i++)
    {
        list.Insert(i);
    }
   // list.show();
   list.Josenor(k);
    return 0;
}