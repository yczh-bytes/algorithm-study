#include <iostream>
using namespace std;
const int N = 100010;
int a[N];

void quick_sort(int a[],int l,int r)
{
    if(l>=r) return;//递归边界，当左右指针重合时停止递归

    int x = a[(r+l)>>1];//选择基准，中间位置元素
    int i = l-1; 
    int j = r+1;//双指针

    while(i<j)
    {
        do i++; while(a[i]<x);//从左找大于枢值的数
        do j--; while(a[i]>x);//从右找小于枢值的树
        if(i<j) swap(a[i],a[j]);//交换数字
    }

    //递归排序左右两边
    quick_sort(a,l,j);
    quick_sort(a,j+1,r);
}

int main()
{
    int n;
    cin>>n;

    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }

    quick_sort(a,0,n-1);

    for(int i = 0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}