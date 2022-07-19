### 27.移出元素

```C++
int removeElement(vector<int>& nums,int val)
{
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right)
    {
        if(nums[letf] == val)
        {
            nums[left] == nums[right--];
        }
        else
        {
            left++;
        }
    }
    retur
}
```



### 26.移除有序数组重复元素

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
    return slow + 1;
}
```



### 80.移除有序数组重复元素