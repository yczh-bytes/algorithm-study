#include <iostream>
#include <vector>
using namespace std;
vector<int>arr;
const int l,r,n;
//一维前缀和 0-based索引
void sums1()
{
    vector<int>prefix(n+1,0);
    for(int i = 0;i<n;i++)
    {
        prefix[i+1] = prefix[i] + arr[i];
    }

    //查询l r区间和
    int query_sum = prefix[r+1]-prefix[l];
}

//一维差分 0-based索引
void diff1()
{
    vector<int>diff(n+1,0);
    //构建差分数组
    diff[0] = arr[0];
    for(int i = 1;i<n;i++)
    {
        diff[i] = arr[i] - arr[i-1];
    }
    //区间修改，在l r区间每个元素增加val
    int val;
    diff[l]+=val;
    if(r+1<n)
    {
        diff[r+1]-=val;
    }
    //通过前缀和修复修改后的数组
    vector<int>result(n);
    for(int i = 1;i<n;i++)
    {
        result[i] = result[i-1]+diff[i];
    }

}

//二维前缀和模板 1-based索引
void sums2()
{
    int m,n;
    cin>>n>>m;
    int num[n][m];
    int sum[n][m];

    //输入矩阵
    for(int i = 1;i<n;i++)
    {
        for(int j = 1;j<n;j++)
        {
            cin>>num[i][j];
        }
    }

    //构建二维前缀和数组
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            sum[i][j] =sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+num[i][j];
        }
    }

    //查询，以x1，y1为左上角，x2，y2为右下角查询子矩阵和
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    int sum = sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];

}

void insert(int x1,int x2,int y1,int y2,int x)
{
 int m,n;
    cin>>n>>m;
    int num[n][m];
    int sum[n][m];
    num[x1][y1]+=x;
    num[x1][y2+1]-=x;
    num[x2+1][y1]-=x;
    num[x2+1][y2+1]+=x;

}
//二维差分，1-based索引
void diff2()
{
    //构建差分数组核心
    int x1,x2,y1,y2,x;
    cin>>x1>>y1>>x2>>y2>>x;
     int m,n;
    cin>>n>>m;
    int num[n][m];
    int sum[n][m];
   
   
    //初始化差分矩阵,相当于每个格子自己加自己
    for(int i =1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            insert(i,j,i,j,num[i][j]);
        }
    }
    //矩阵相加操作
    insert(x1,y1,x2,y2,x);
    //二维前缀和还原最终矩阵
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            sum[i][j] =sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+num[i][j];
        }
    }
}