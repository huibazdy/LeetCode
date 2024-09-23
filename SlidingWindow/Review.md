# Review

## 长度最小的子数组

输入：正整数数组`vector<int> nums(n);` 以及 `int target`；
返回：和大于等于 target 的子数组，要求子数组长度最小，返回长度，若不存在则返回 0；



【例 1】
输入：[2, 3, 1, 2, 4, 3]，target = 7
输出：2



【例 2】
输入：[1, 4, 4]，target = 4
输出：1



> 思路：滑动窗口

1. 向右枚举窗口右端点，若和小于 7 ，则向右一直扩展窗口；
2. 若某一刻大于 7 ，则缩小左端点（因为由于是正整数数组，继续右扩只会增大窗口和）；
3. 持续缩小左端点会有两种情况：
   * 窗口和小于 7 ，此时继续向右扩展右端点；
   * 窗口和等于 7 ，此时保存长度为最短长度；
4. 若左端点还没到最后元素，继续右端点右扩，并持续更新保存的满足条件的最短长度

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
		int n = nums.size();
        if(n == 1)
            return nums[0] == target ? 1 : 0;
        int ans = 0;
        int winL = 0;
        int winR = 1;
        while(winL < n && winR < n){
            if(winL == winR) {
                return nums[winL] == target ? 1 : 0;
            }
            int sum = 0;
            for(int i = winL; i <= winR; i++)
                sum += nums[i];
            if(sum < target)
                winR++;
            else {
                int tmp = winR - winL + 1;
                if(ans == 0)
                    ans = tmp;
                ans = min(ans,
                if(sum > target)
                    winL++;
                else
                	winR++;
            }
        }
        return ans;
    }
};
```

