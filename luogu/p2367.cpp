#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,p;
    cin>>n>>p;
    vector<int>score(n+1);
    vector<int>diff(n+2);
    for(int i = 1;i<=n;i++)
    {
        cin>>score[i];
    }

    //构建差分数组
    //1-based,直接从1开始
    diff[1] = score[1];
    for(int i = 2;i<=n;i++)
    {
        diff[i] = score[i] - score[i-1];
    }

    //区间修改，对x y区间内修改z
    int x,y,z;
    for(int i = 0;i<p;i++)
    {
        cin>>x>>y>>z;
        diff[x] += z;
            diff[y+1]-=z;
        

    }

    //将数组还原
    vector<int>new_score(n+1);
    new_score[1] = diff[1];
    for(int i = 2;i<=n;i++)
    {
        new_score[i] = new_score[i-1] + diff[i];
    }

    int min = *min_element(new_score.begin()+1,new_score.end());
    cout<<min;
    return 0;
}