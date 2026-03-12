#include <iostream>
#include <vector>
using namespace std;

//标准二分
int search(vector<int>& nums,int target)
{
    int l = 0;
    int r = nums.size()-1;
    
    while(l<=r)
    {
    int mid = (l+r)>>1;
    if(nums[mid] == target)
    {
        return mid;
    }
    else if(nums[mid]<target)
    {
        l = mid+1;
    }
    else{
        r = mid-1;
    }

    }
}

//找到第一个＞=target的位置（左边界）
int lower_bound(vector<int>& nums,int target)
{
    int l = 0;
    int r = nums.size()-1;
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(nums[mid]>=target)
        {
            r = mid-1;
        }

        else{
            l = mid+1;
        }
    }
    return l;
} 
//找到最后一个<=target的位置（右边界）
int upper_bound(vector<int>& num,int target)
{
    int l = 0;
    int r = num.size()-1;
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(num[mid]<=target)
        {
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return r+1;
}

int main()
{
    return 0;
}