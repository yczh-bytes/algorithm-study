#include <bits/stdc++.h>
using namespace std;
const int MAX = 500001;
long long ans = 0;
int num[MAX];
int tem[MAX];

void merge(int l,int mid,int r)
{
    int i = l;
    int j = mid+1;
    int k = l;

    while(i<=mid&&j<=r)
    {
        if(num[i]<=num[j])
        {
            tem[k++] = num[i++];
            
        }
        else
        {
            tem[k++] = num[j++];
            ans = ans + mid-i+1;
        }
    }

    while(i<=mid)
    {
        tem[k++] = num[i++];
    }

    while(j<=r)
    {
        tem[k++] = num[j++];
    }

    for(int m = l;m<=r;m++)
    {
        num[m] = tem[m];
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
    for(int i = 0;i<n;i++)
    {
        cin>>num[i];
    }

    merge_sort(0,n-1);
    cout<<ans<<endl;
    return 0;
}