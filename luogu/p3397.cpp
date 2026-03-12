#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>sum;
vector<vector<int>>prefix;
//构建二维差分
void insert(int x1,int y1,int x2,int y2,int x)
{
  sum[x1][y1]+=x;
  sum[x1][y2+1]-=x;
  sum[x2+1][y1]-=x;
  sum[x2+1][y2+1]+=x;
}

int main()
{
    //定义长度
    int n,m;
    cin>>n>>m;//m为地毯个数
    int x1,x2,y1,y2;
    
    //差分数组
    sum.resize(n+2,vector<int>(n+2,0));
    prefix.resize(n+2,vector<int>(n+2,0));

    //初始化差分数组
    
    for(int i = 0;i<m;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        //矩阵相加操作
        insert(x1,y1,x2,y2,1);
    }
    //通过前缀和还原数组
    
    for(int i = 1;i<=n;i++)
    {
       for(int j = 1;j<=n;j++)
       {
        prefix[i][j] = sum[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
       }
    }

    //打印数组
    for(int i = 1;i<=n;i++)
    {
        
        for(int j = 1;j<=n;j++)
        {
        cout<<prefix[i][j]<<' ';
        }

        if(i<n)
        {
            cout<<endl;
        }
    }
    return 0;
}