# Review

## 长度最小的子数组

输入：正整数数组`vector<int> nums(n);` 以及 `int target`；
返回：和大于等于 target 的子数组，要求子数组长度最小，返回长度，若不存在则返回 0；



【例】
输入：[2, 3, 1, 2, 4, 3]，target = 7
输出：2



> 思路：由连续子数组联想到——滑动窗口

1. 向右依次往窗口中添加元素，若和小于 7 ，则向右一直扩展窗口；
2. 若某一刻窗口内元素和大于等于 7 ，更新满足条件的窗口大小（ans）；
3. 右移左边界，尝试找到满足条件的更小窗口；
4. 若步骤 3 后发现窗口内元素和依旧满足条件，继续更新窗口大小；
5. 若步骤 3 后发现窗口内元素和不再满足条件，继续更右移右边界；
6. 持续以上步骤，直到窗口右边界达到数组最右端；

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
		int n = nums.size();
        int ans = n+1;   // 将 ans 初始化为超过数组长度的值，用于返回判断
        int winL = 0;    // 滑动窗口的左边界
        int sum = 0;     // 记录窗口内所有元素和
        for(int winR = 0; winR < n; winR++) {
            sum += nums[winR];  // 窗口内元素和利用 nums[winR] 逐次添加
            while(sum >= target){
                ans = min(ans,winR-winL+1);  // 若存在满足条件的更小窗口，更新 ans
                sum -= nums[winL++];         // 左边界右移，试图寻找更小窗口，同时更新 sum
            }
        }
        return ans == n+1 ? 0 : ans;
    }
};
```

执行结果：

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202409241141341.png" alt="image-20240924114105268" style="zoom: 33%;" />

> 【**注意**】
> 一开始，ans 初始化为一个超过数组长度的值，目的是为了在返回结果时判断 ans 是否被更新，如果没被更新，且滑动窗口的长度不可能为 ans，就代表不存在符合条件的子数组，需要返回 0 



## 最小覆盖子串

给定两个字符串`s`和`t`，返回`s`中包含`t`所有字符的最小子串，若不存在返回空字符串`""`。

【注意】

1. `t`中重复字符，寻找的子字符串必须不少于`t`中该字符数量
2. `s`中若存在符合条件的子串，保证它是唯一答案

> 思路

最核心的问题是弄清楚“**覆盖**”的含义，指的是子串中各个字母出现的次数都不小于`t`中每个字母出现次数。

类似于最小连续子数组，用滑动窗口，不断更新左右边界来判断窗口内的子串是否符合要求。

借助一个哈希表来记录字符串 `t` 中每个字符及其出现的次数。

借助一个哈希表来记录字符串`s`子串中每个字符及其出现的次数。

> 【注意】
>
> 这里存储字符的哈希表，使用容器还是数组更好？用一个长度 128 的整型数组是否可行，字符本身就是索引值，数组元素值是索引出现的次数。（ASCII 码的值是 0~127，共计 128 个字符）

```c++
class Solution {
public:
    // 判断 s 的子串是否覆盖 t
    bool isCovered(int hash_s[128],int hash_t[128]) {
        for(int i = 'A'; i <= 'Z'; i++) {  // 判断大写字母是否覆盖
            if(hash_s[i] < hash_t[i])
                return false;
        }
        for(int i = 'a'; i <= 'z'; i++) {  // 判断小写字母是否覆盖
            if(hash_s[i] < hash_t[i])
                return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        int ans_L = -1;
        int ans_R = s.length();
        // 1. 将 t 统计到哈希表 h1 中去
        int hash_t[128];
        for(char c : t)
            hash_t[c]++;
        // 2. 滑动窗口右边界遍历 s 并用哈希表 h2 统计遍历结果
        int L = 0;
        int hash_s[128];
        for(int R = 0; R < s.length(); R++) {
            hash_s[s[R]]++;           // 右边界加入子串
            while(isCovered(hash_s,hash_t)) { // h2 覆盖了 h1
                if(R-L < ans_R-ans_L) {  // 找到了更短，且新符合条件的子串左右边界
                    ans_L = L;
                    ans_R = R;
                }
                hash_s[s[L]]--;        // 缩短子串，通过右移左边界
                L++;
            }
        }
        return ans_L<0 ? "" : s.substr(ans_L, ans_R-ans_L+1);
    }
};
```

