# 字符串

## 常用函数

### 子串

* #### **substr( )**

  * `str.substr(start_index, n)`，从起始位置开始复制 n 个字符
  * `str.substr(start_index)`，复制起始位置到字符串结束位置



### 字符判断



## 最后一个单词长度

给定字符串由若干单词组成，单词前后用一些空格字符隔开，返回最后一个单词的长度。

【例】
输入：s = "   fly me   to   the moon  "
输出：4

>思路：双指针

```c++
class Solution {
public:
    int lengthOfLastWord(string s) {
		int slow = 0;
        int fast = 0;
        vector<string> strs;
        for(int i = slow; i < s.length(); i++) {
            while(s[i] == 0)
                ++i;
            slow = i;
            fast = slow;
            while(s[fast] != ' '){
                ++fast;
                if(fast == s.length())
                    return strs.back().length();
            }    
            strs.push_back(s.substr(slow,fast-slow));
            slow = fast;
        }
        return strs.back().length();
    }
};
```