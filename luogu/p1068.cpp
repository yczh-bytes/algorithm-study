#include <bits/stdc++.h>
using namespace std;
int MAX = 5001;
//将id和分数分开存储
vector<int> id(MAX);
vector<int> score(MAX);
vector<int> tem_id(MAX);
vector<int> tem_score(MAX);

//使用比较器
bool compare(int a,int b)
{
    //分数相同按照id排序
    if(score[a]==score[b])
    {
        return id[a]<id[b];
    }

    return score[a]>score[b];
}

void merge(int l,int mid,int r)
{
    int i = l;
    int j = mid+1;
    int k = l;
    while(i<=mid&&j<=r)
    {
        if(compare(i,j))
        {
            tem_id[k] = id[i];
            tem_score[k++] = score[i++];
        }
        else
        {
            tem_id[k] = id[j];
            tem_score[k++] = score[j++];
        }
    }

    while(i<=mid)
    {
        tem_id[k] = id[i];
        tem_score[k++] = score[i++];
    }

    while(j<=r)
    {
        tem_id[k] = id[j];
        tem_score[k++] = score[j++];
    }

    for(int m = l;m<=r;m++)
    {
        id[m] = tem_id[m];
        score[m] = tem_score[m];
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
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++)
    {
        cin>>id[i]>>score[i];
    }
    merge_sort(0,n-1);
    int ans = m*1.5;
    int score_num = score[ans-1];
    int count = 0;
    while(count<n&&score[count]>=score_num)
    {
        count++;
    }

    cout<<score_num<<' '<<count<<endl;

    for(int i = 0;i<count;i++)
    {
        cout<<id[i]<<' '<<score[i]<<endl;
    }

    return 0;
}