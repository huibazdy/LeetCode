# 验证回文串

如果将字符串中所有字符转化为小写并剔除非字母数字字符后，正反读都一样的字符串称之为回文串。

> 双指针

```c++
bool isPalindrome(string s)
{
    //首先移出非字母或非数字字符
    string r;  // 用于存储筛选过后的字符串
    for(char ch : s){
        if(isalnum(ch)) // 判断是否为字母或数字
            r.push_back(tolower(ch));  // 转为小写字母并插入新字符串
    }
    
    int i = 0;
    int j = r.size() - 1;
    while(i < j) {
        if(s[i] == s[j]) {
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}
```

> 字符串常用函数（宏定义）：
>
> * `isalpha()`：字母
> * `islower()`：小写字母
> * `isupper()`：大写字母
> * `isalnum()`：字母或数字
> * `tolower()`：转小写
> * `toupper()`：转大写



# 判断子序列

给定字符串 s 和 t，判断 s 是否为 t 的子序列。

* 子序列：原字符串删除一些字符，不改变剩余字符相对位置形成的新的字符串

> 双指针加贪心一次遍历即可

```c++
bool isSubsequence(string s, string t)
{
    int s_length = s.size();
    int t_length = t.size();
    int i = 0; //用于遍历s
    int j = 0; //用于遍历t
    while(i < s_length && j < t_length) {
        if(s[i] == t[j]) {  // 当下t匹配当下s字符
            i++;
        }
        else
            j++;  // 当下字符不匹配，继续在 t 中向后寻找
    }
    if(i == s_length)
        return true;
    return false;
}
```



# 两数之和 II

给定非递减数组（下标从 1 开始），找出两数之和为 target 的两个数，并返回它们的下标。

> 思路

为了充分利用已排序这个条件，可以利用两个指针分别指向数组首位来相向遍历整个数组。当两者之和大于 target 时左移右指针，当两者之和小于 target 时，右移左指针。

```c++
vector<int> twoSum(vector<int>& numbers, int target)
{
    int n = numbers.size();
    int L = 0;     // 左指针
    int R = n-1;   // 右指针
    int sum = 0;   // 二者和
    while(L < R) {
        sum = numbers[L] + numbers[R];
        if(sum > target)
            R--;
        else if(sum < target)
            L++;
        else
            return {L+1,R+1};
    }
    return {};
}
```





# 三数之和

给定整数数组，返回所有三数之和为 0 的三元组，要求索引互不相同，且答案中不能包含重复三元组。

【例 1】
输入：nums = [-1, 0, 1, 2, -1, -4]
输出：[-1, 0, 1] 和 [-1, -1, 2]

>思路

1. 给数组排序；
2. 将三数之和转为两数之和的问题；
3. 双指针降低时间复杂度

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n-2; i++) { // 遍历到某个元素，在之后的区间中找到满足条件的另外两个数
            if(i > 0 && nums[i] == nums[i-1]) // 跳过重复的 nums[i]
                continue;
            int j = i+1;
            int k = n-1;
            while(j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if(sum > 0)            // 左移右指针
                    k--;
                else if(sum < 0)       // 右移左指针
                    j++;
                else {                 // 找到符合条件的三元组
                    ans.push_back({nums[i],nums[j],nums[k]});   // 保存结果
                    j++;                                        // 更新左指针
                    while(j < k && nums[j] == nums[j-1])        // 跳过 nums[j] 重复元素
                        j++;
                    k--;                                        // 更新左指针
                    while(j < k && nums[k] == nums[k+1])        // 跳过 nums[k] 重复元素
                        k--;
                }
            }
        }
        return ans;
    }
};
```



# 盛水最多的容器

> 双指针——分别指向左右柱子

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
		int left = 0;
        int right = n-1;
        int ans = 0;
        while(left < right){  // 左右指针未相遇才能构成面积
            // 1. 找出出左右两根柱子的较小者
            int M = height[left] < height[right] ? height[left] : height[right];
            // 2. 求出当前两根柱子围成的容器体积
            int area = (right - left) * M;
            // 3. 更新最大容积，和之前的最大值比较
            ans = area > ans ? area : ans;
            // 4. 移动较矮柱子寻求可能得更大容积
            if(height[left] < height[right])  
                left++;
            else
                right--;
        }
        return ans;
    }
};
```



# 接雨水

> 思路

* 每个位置都可能存在宽度为 1 的“桶”，也就是能接水的下凹结构；
* 这个桶能装多少水，取决于两个“边”，注意这个边在这里是虚拟的，也就是下凹结构的一个边；
* 左边，取决于该位置左边的最大高度；
* 右边，取决于该位置右边的最大高度；

>构造前缀数组与后缀数组来确定每个“桶”的左右“边”，从而计算出每个“桶”接雨水的容积

```c++
class Solution {
public:
    int trap(vector<int>& height) {
		int n = height.size();
        
        vector<int> pre_max(n);   // 前缀最大值数组        
        pre_max[0] = height[0];
        for(int i = 1; i < n; i++)
            pre_max[i] = max(pre_max[i-1], height[i]);
        
        vector<int> suf_max(n);  // 后缀最大值数组
        suf_max[n-1] = height[n-1];
        for(int j = n-2; j >= 0; j--)
            suf_max[j] = max(suf_max[j+1], height[j]);
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += min(pre_max[i], suf_max[j]) - height[i]; // “桶”高度即容积
        
        return ans;
    }
};
```

时间复杂度：`O(n)`
空间复杂度：`O(n)`