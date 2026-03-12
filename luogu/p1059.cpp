#include <bits/stdc++.h>
using namespace std;
const int MAX = 101;
vector<int> num(MAX);
vector<int> tem(MAX);

void merge(int l,int mid,int r)
{
    int i = l;
    int j = mid+1;
    int k = l;
    while(i<=mid&&j<=r)
    {
        if(tem[i]<=num[j])
        {
            tem[k++] = num[i++];
        }
        else{
            tem[k++] = num[j++];
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
    int n = 0;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>num[i];
        tem[i] = num[i];
    }

    merge_sort(0,n-1);
    num.erase(unique(num.begin(),num.begin()+n),num.end());
    cout<<num.size()<<endl;
    for(int i = 0;i<num.size();i++)
    {
        cout<<num[i]<<' ';
    }

    return 0;
}