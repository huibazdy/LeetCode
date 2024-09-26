# Review-Array

## 删除有序数组中的重复项

给定有序数组`sum`，原地删除重复元素，使每个元素只出现一次，返回删除后数组的新长度。只需要考虑数组的前 k 个元素即可，后面的元素无需考虑。

【例 1】
输入：nums = [1,1,2]
输出：2, nums = [1,2,_]

【例 2】
输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]

> 思路：双指针

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int fast = slow + 1;
        while(fast < nums.size()) {
            if(nums[fast] != nums[slow])   // 找到了非重复元素
                nums[++slow] = nums[fast]; // 更新slow之后位置为新元素，并移动slow
            fast++;                        // 继续移动fast，找下一个非重复元素
        }
        return slow+1; // 返回的是长度，所以需要将非重复部分尾部元素的索引slow加1
    }
};
```

执行结果：

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202409261718160.png" alt="image-20240926171759972" style="zoom: 50%;" />



## 删除有序数组中的重复项 II

给定有序数组`sum`，原地删除重复元素，使出现次数超过两次的元素只出现两次，返回删除后数组长度。要求：不使用额外数组空间，原地修改数组，且只使用`O(1)`额外空间完成。

【例 1】
输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]

【例 2】
输入：nums = [0,0,1,1,1,1,2,3,3]
输出：7, nums = [0,0,1,1,2,3,3]

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2)
            return nums.size();
        int slow = 2;
        int fast = 2;
        while(fast < nums.size()) {
            if(nums[fast] != nums[slow-2])  // 遇到重复次数不超过 2 的元素需要保留
                nums[slow++] = nums[fast];
            fast++;
        }
        return slow;
    }
};
```