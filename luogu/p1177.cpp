#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
 int n [N];

void quick_sort(int a[],int l,int r)
{
if(l>=r) return;

    int x = a[(l+r)>>1];
    int i = l-1;
    int j = r+1;
while(i<j)
{
    do i++;while(a[i]<x);
    do j--;while(a[j]>x);

    if(i<j) swap(a[i],a[j]);
}

quick_sort(a,l,j);
quick_sort(a,j+1,r);

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a = 0;
    cin>>a;
    for(int i = 0;i<a;i++)
    {
        cin>>n[i];
    }

    quick_sort(n,0,a-1);

    for(int i = 0;i<a;i++)
    {
        cout<<n[i]<<' ';
    }


    return 0;
}