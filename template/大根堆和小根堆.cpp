#include <iostream>
#include <functional>
#include <stdio.h>
#include <time.h>
using namespace std;

//优先级队列实现堆
class PriorityQueue
{
public:
       using Comp = function<bool(int,int)>;//比较器

       PriorityQueue(int size = 20,Comp com=greater<int>()):size(0),cap(cap),com(com)
       {
        arr = new int[cap];
       }
       ~PriorityQueue()
       {
        delete []arr;
        arr=nullptr;
       }

       //入堆操作
       void push(int val)
       {
      
        if(size==cap)//数组满了，需要扩容
        {
            int* arr1 = new int[2*cap];
            memcpy(arr1,arr,cap*sizeof(int));
            delete []arr;
            arr = arr1;
            cap*=2;
        }
            siftup(val,size);//定义一个上浮函数比较大小
        size++;
       }
//从堆中删除元素
void pop()
{
if(size==0)
{
    throw"数组为空，无法删除元素";
}
size--;
if(size>0)siftdown(arr[size],0);
}
//取出堆顶元素
int top()
{
return arr[0];
}
//检验是否为空
bool isEmpty()const
{
    return size==0;
}
private:
void siftup(int val,int i)
{
    while(i>0)//在根节点之下，因为根节点上面已经没有元素了
    {
        int father = (i-1)/2;
        if(com(val,arr[father]))//如果子节点大于父节点
        {
            arr[i]=arr[father];//父节点下沉
            i=father;//子节点下标变为父节点下标
        }
        else
        {
            break;//没有的话直接返回
        }
        
    }
arr[i]=val;
}
//下沉函数
void siftdown(int val,int i)
{
    while(i<size/2)//不能下沉到最后一个有孩子节点下面，否则该二叉树非完全二叉树
    {
        int child = 2*i+1;//左孩子节点
        if(child+1<size&&com(arr[child+1],arr[child]))//比较左右孩子大小
        {
          child = child+1;
        }

        if(com(arr[child],val))//比较器比出左边更小
        {
            arr[i]=arr[child];
            i=child;
        }
        else
        {
            break;
        }
    }
    arr[i]=val;
}
private:
int* arr;//动态数组大小
int cap;//数组大小
int size;//元素个数
Comp com;
};

int main()
{
    PriorityQueue p;
    srand(time(NULL));

    for(int i = 0;i<10;i++)
    {
        int x = rand()%100;
        p.push(x);

    }
    while(!p.isEmpty())
    {
        cout<<p.top()<<' ';
        p.pop();
    }
    cout<<endl;
    PriorityQueue p1(20,less<int>());//less<int>表示从小到大
    srand(time(NULL));

    for(int i = 0;i<10;i++)
    {
        int x = rand()%100;
        p1.push(x);

    }
    while(!p1.isEmpty())
    {
        cout<<p1.top()<<' ';
        p1.pop();
    }
}


