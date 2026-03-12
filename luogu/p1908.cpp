#include <bits/stdc++.h>
using namespace std;
const int MAX = 500001;
long long arr[MAX];
long long tem[MAX];
long long val_count = 0;

void merge(int l,int mid,int r)
{
    int i = l;
    int j = mid+1;
    int k = l;
    while(i<=mid&&j<=r)
    {
        if(arr[i]<=arr[j])
        {
            tem[k++] = arr[i++];
        }
        else{
            tem[k++] = arr[j++];
            //此处的val_count是为了统计逆序对的数量，当右边数组的当前元素小于左边数组的当前元素时，说明左边数组中从i到mid的所有元素都大于右边数组的当前元素，因此逆序对的数量增加mid - i + 1
            val_count += mid -i + 1;;
        }
    }
    while(i<=mid)
    {
       
        tem[k++] = arr[i++];
    }

    while(j<=r)
    {
        tem[k++] = arr[j++];
    }

    for(int i=l;i<=r;i++)
    {
        arr[i] = tem[i];
    }
}
    void merge_sort(int l,int r)
    {
        if(l>=r) return;
        int mid = (l+r)>>1;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        merge(l,mid,r);

}


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    merge_sort(0,n-1);

    cout<<val_count<<endl;
    return 0;
}