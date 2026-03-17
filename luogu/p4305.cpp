#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    vector<int>sum;
    int n = 0;
    cin>>n;
    while(n--)
    {
        unordered_set<long long>num;
        vector<long long>sum;
        int nums;
        bool chect = true;
        cin>>nums;
        while(nums--)
        {
            long long x;
            cin>>x;
            
            if(num.count(x)==0)
            {
               num.insert(x);
               sum.push_back(x);
            }
        }
        for(int i = 0;i<sum.size();i++)
        {
            cout<<sum[i]<<' ';
        }

    cout<<endl;
   
}
 return 0;
}