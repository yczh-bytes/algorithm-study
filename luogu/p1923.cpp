#include <bits/stdc++.h>
using namespace std;
const int N = 5000001;
vector <int> a(N);

int quick_select(vector <int>& a,int l,int r,int k)
{
if(l>=r) return a[l];
int x = a[(l+r)>>1];
int i = l-1,j = r+1;
while(i<j)
{
    do i++;while(a[i]<x);
    do j--;while(a[j]>x);
    if(i<j) swap(a[i],a[j]);
}

if(k<=j) return quick_select(a,l,j,k);
else return quick_select(a,j+1,r,k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 0;
     int k;
    cin>>n;
    cin>>k;
    for(int i=0;i<n;i++) cin>>a[i];
   
    quick_select(a,0,n-1,k);
    cout<<a[k]<<endl;
    return 0;
}