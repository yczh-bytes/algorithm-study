#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,m;
    cin>>n;
    vector<int>nums(n);
    vector<int>prefixSum(n+1);
    for(int i = 0;i<n;i++)
    {
        cin>>nums[i];
    }

 
    //求前缀和
    for(int i = 1;i<=n;i++)
    {
        prefixSum[i] = prefixSum[i-1]+nums[i-1];
    }
       cin>>m;
    int l,r;
    //得出结果
    while(m--)
    {
        
        cin>>l>>r;
        cout<<prefixSum[r]-prefixSum[l-1]<<endl;
    }
    return 0;
}