### 27.移出元素



### 26.移除重复元素



```C++
int removeDuplicates(vector<int>& nums)
{
    if(nums.size() == 0 || nums.size() == 1)
    {
        return nums.size();
    }
    int slow = 0;
    int fast = 1;
    while(fast < nums.size())
    {
        if(nums[fast] == nums[slow])
        {
            ++fast;
        }
        else
        {
            nums[++slow] = nums[fast];
        }
    }
    return slow
}
```

