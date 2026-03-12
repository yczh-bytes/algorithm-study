#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    long long C;
    cin>>N>>C;
    vector<long long> nums(N);
    for(int i = 0;i<N;i++)
    {
    cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    long long ans = 0;
    //二分法
    for(int i = 0;i<N;i++)
    {
        //使用lower_bound找到第一个大于等于
        //使用upper_bound找到第一个大于
        //因此数对的个数为upper_bound-lower_bound
        auto left = lower_bound(nums.begin(),nums.end(),C+nums[i])-nums.begin();
        auto right = upper_bound(nums.begin(),nums.end(),C+nums[i])-nums.begin();
        ans += right-left;
    }
    cout<<ans<<endl;
    return 0;
}