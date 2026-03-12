#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e5 + 10;
int arr[MAX];
int tem[MAX];


//合并两个有序数组，l为左边数组的起始位置，mid为左边数组的结束位置，r为右边数组的结束位置
void merge(int l,int mid,int r)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    while(i<=mid&&j<=r)
    {
        //当左边数组的当前元素小于等于右边数组的当前元素时，将左边数组的当前元素放入临时数组中，并将左边数组的指针向右移动一位
        if(arr[i]<=arr[j])
        {
         //存入临时数组中
         tem[k++] = arr[i++];
        }
        else{
            tem[k++] = arr[j++];
        }

        //如果有剩余元素，将剩下元素都放入临时数组中
        while(i<=mid)
        {
            tem[k++] = arr[i++];
        }

        while(j<=r)
        {
            tem[k++] = arr[j++];
        }
    }
    for(int i=l;i<=r;i++)
    {
        //将数字放回原数组
        arr[i] = tem[i];
    }
}

//归并排序
void merge_sort(int l,int r)
{
    //数组中只有一个元素时，直接返回
    if(l>=r) return;    

    int mid = (l+r)>>1;
    //递归排序左边数组
    merge_sort(l,mid);
    //递归排序右边数组
    merge_sort(mid+1,r);
    //合并两个有序数组
    merge(l,mid,r);
}

int main()
{
    return 0;
}
