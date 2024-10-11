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



## 最长公共前缀

找出字符串数组中的最长公共前缀，若不存在，则返回空字符串。数组元素中只包含小写字母。

【例】
输入：strs = ["flower","flow","flight"]
输出："fl"

> 思路

1. 将整个字符串数组看成一个矩阵（行数为：`strs.size()`，列数为其中数组中元素的最大长度）；
2. 从左至右遍历矩阵中每一列；
3. 设遍历到第**`j`**列，从上至下遍历这一列的字母；
4. 设遍历该列字母到第**`i`**行，此时遍历到的字母是`strs[i][j]`；
5. 如果`j`已经是`strs[i]`的长度（这一行已经遍历完），或者出现了不同的字符（`strs[i][j]`不等于`strs[0][j]`），返回的最长子公共前缀就是`strs[0]`的前`j`个字符组成的前缀；
6. 若中途未返回，说明最长公共前缀就是`strs[0]`

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		int rows = strs.size();  //矩阵行数
        
    }
};
```





```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		sort(strs.begin(), strs.end());  // 对字符串数组排序
        for(int j = 0; j < strs[0].length(); j++){ // 遍历矩阵的有效列
            for(int i = 0; i < strs.size(); i++) { // 遍历行
                if(strs[i][j] != strs[0][j])
                    return strs[0].substr(0,j);
                continue;
            }
        }
        return strs[0];
    }
};
```

运行结果：

<img src="C:\Users\zdy\AppData\Roaming\Typora\typora-user-images\image-20241011174427473.png" alt="image-20241011174427473" style="zoom: 50%;" />

> 字符串常用函数之：`substr()` 的两种使用方法：
>
> 1. `str.substr(start_index, cnt)`，起始位置加复制数量
> 2. `str.substr(start_index)`，复制起始位置到字符串结束位置

