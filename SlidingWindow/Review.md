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



## 找到字符串中所有字母异位词

给定字符串`s`和`p`，找到`s`中所有`p`的异位词的子串，返回这些子串的索引，不用考虑答案顺序。注意，两个字符串只包含小写字母。

【例 1】
输入：s = "cbaebabacd"， p = "abc"
输出：[0, 6]

【例 2】
输入：s = "abab"，p = "ab"
输出：[0, 1, 2]

> 【**思路**】
> 长度固定的滑动窗口来遍历`s`，一直判断窗口内子串是否为`p`的异位词，知道窗口右端点到达`s`的右边界。

```c++
class Solution {
public:
    // 编写判断是否为异位词的函数
    bool isAnagrams(int hash_s[],int hash_t[]) {
        for(int i = 'a'; i < 'z'; i++){
            if(hash_s[i] != hash_t[i])
                return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;     // 结果数组
		int m = p.length();  // 窗口长度
        int hash_p[128];       // 创建 p 的哈希表
        for(char c : p)
            hash_p[c]++;
        int winL = 0;        // 窗口左边界
        int winR = m -1;     // 窗口右边界
        int hash_s[128];     // 创建窗口内子串的哈希表
        for(int i = winL; i <= winR; i++)  // 窗口内子串放入 hash
                hash_s[s[i]]++;
        while(winR < s.length()){
            if(isAnagrams(hash_s,hash_p)){ // 子串是 p 的异位词
            	ans.push_back(winL);       // 记录当前子串起始索引 winL
                // 向后移动窗口
                hash_s[s[winL]]--;
                winL++;
                winR++;
                hash_s[s[winR]]++;
            }
            else {    // 向后移动窗口
                hash_s[s[winL]]--;
                winL++;
                winR++;
                hash_s[s[winR]]++;
            }
        }
        return ans;
    }
}；
```

执行结果：
![image-20240925160512432](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202409251605586.png)



## 串联所有单词的子串

给定一个字符串`s`和一个字符串数组`words`，数组中所有字符串**长度相同**。`s`中的串联子串指一个包含`words`中所有字符串以任意顺序排列起来的子串。返回串联子串在`s`中的起始索引。注意，`words[i]`和`s`都由小写字母组成。

【例】
输入：s = "barfoothefoobarman"， words = ["foo","bar"]
输出：[0, 9]



> 【思路】
> 借助一个滑动窗口来遍历`s`寻找子串，窗口大小为`words.size() * words[0].length()`。
>
> 1. 用 word 长度划分子串为多个word；
> 2. 比较子串中word和`words`中word的出现频次是否相同
> 3. 实际上就是判断窗口内子串是否为`words`的“异位词”，只不过词的元素从字符变成了word



```c++
class Solution {
public:
    bool isEqualHash(map<string,int> h1, map<string,int> h2) {
        if(h1.size() != h2.size())  // 比较哈希中出现的单词数
            return false;
        map<string,int>::iterator iter1 = h1.begin();
        while(iter1 != h1.end()){
            if(h2.find(iter1->first) == h2.end())
                return false;
            if(h2.find(iter1->first)->second != iter1->second)
                return false;
            iter1++;
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
		int word_l = words[0].length();           // 单词长度
        int word_n = words.size();                // 单词数量
        int window_l = word_n * word_l;           // 滑动窗口长度
        
        // 建立 words 的哈希表，统计各个单词及其出现频次
        map<string,int> h1;   // 利用 map 自动排序的性质，利于之后比较两个哈希
        for(int i = 0; i < word_n; i++) {
            if(h1.find(words[i]) == h1.end())
                h1.insert(make_pair(words[i],1));
            h1[words[i]]++;
        }
        
        // 滑动窗口遍历子串，并使用 word_l 对子串进行划分，同时用哈希表 h2 记录
        int L = 0;
        int R = window_l - 1;
        map<string,int> h2;   // 创建记录子串的哈希表 h2
        while(R < s.length()) {
            string win = s.substr(L,R);  // 窗口内子串
            string word;                 // 记录划分结果
            for(int i = 0; i < word_n; i++) { // 划分得到 word_n 个单词
                word = win.substr(i*word_l,i*word_l+word_l-1); // 划分得到的某个单词
                if(h2.find(word) == h2.end())  // 单词加入哈希
                	h2.insert(make_pair(word,1));
                else
                	h2[word]++;
            }
            if(isEqualHash(h2,h1))  // 判断子串划分的哈希表与 words 哈希是否相等
                ans.push_back(L);
            // 更新窗口
            L++;
            R++;
            // 清空哈希表 h2
            h2.clear();
        }
        return ans;
    }
};
```
