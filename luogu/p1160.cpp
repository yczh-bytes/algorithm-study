#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int x=0):data(x),next(nullptr){}
};

class LinkedList
{
    private:
    Node* head;
    public:
    LinkedList()
    {
        head = new Node();
    }
    ~LinkedList()
    {
        Node* p = head;
        while(p!=nullptr)
        {
            Node*q = p->next;
            delete(p);
            p = q;
        }
    }

    void LeftInsert(int index,int val)
    {
         Node* newNode=new Node(val);
        if(head->next==nullptr)
        {
            head->next = newNode;
            return ;
        }
        Node* p = head->next;
        Node* q = head;
        while(p!=nullptr&&p->data!=index)
        {
            p=p->next;
            q=q->next;
        }
       
        q->next = newNode;
        newNode->next = p;

    }
    void RightInsert(int index,int val)
    {
        Node* newNode=new Node(val);
        if(head->next==nullptr)
        {
            head->next = newNode;
            return ;
        }
        Node* p = head->next;
        
        while(p!=nullptr&&p->data!=index)
        {
            p=p->next;
            
        }
        
       newNode->next = p->next;
       p->next=newNode;

    }
    void Delete(int val)
    {
        Node* p = head->next;
        Node* q = head;
        while(p!=nullptr&&p->data!=val)
        {
            p = p->next;
            q=q->next;
        }
        if(p!=nullptr)
        {
        q->next = p->next;
        delete(p);//注意重复删除的边界问题
        }
    }
    void show()
    {
        Node* p = head->next;
        while(p!=nullptr)
        {
            cout<<p->data<<' ';
            p=p->next;
        }
    }
};
int main()
{
    LinkedList list;
    int N;
    //有多少人
    cin>>N;

    int k = 1;
    list.LeftInsert(-1,k++);
    //插入人以及插入地点
    for(int i = 1;i<N;i++)
    {
        int Insertindex = 0;//插入谁旁边
        int toward = 0;//插入方向
        cin>>Insertindex>>toward;
        if(toward==0)
        {
            list.LeftInsert(Insertindex,k++);
        }
        if(toward==1)
        {
            list.RightInsert(Insertindex,k++);
        }
    }
    int m = 0;
    cin>>m;
    for(int i = 0;i<m;i++)
    {
        int d = 0;
        cin>>d;
        list.Delete(d);
    }
    list.show();
    return 0;
}