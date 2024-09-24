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