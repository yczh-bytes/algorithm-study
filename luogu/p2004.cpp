#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,M,C;
    cin>>N>>M>>C;
    //N行M列的地图
    vector<vector<int>>filed(N,vector<int>(M));
    //前缀和数组
    vector<vector<long long>>sum(N+1,vector<long long>(M+1));
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<M;j++)
        {
            cin>>filed[i][j];
        }
    }

    //构建前缀和数组
    for(int i = 1;i<=N;i++)
    {
        for(int j = 1;j<=M;j++)
        {
            sum[i][j] = filed[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }

    //计算每个矩阵的值
    long long max = -100000001;
    int ch,ce;
    for(int i = 0;i<N-C;i++)
    {
        for(int j = 0;j<M-C;j++)
        {
            int x1 = i+1;
            int y1 = j+1;
            int x2 = i+C;
            int y2 = j+C;

            int result = sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
           
            if(result>max)
            {
                max = result;
                ch = i;
                ce = j;
            }
        }
    } 
    cout<<ch+1<<' '<<ce+1;
    return 0;
}