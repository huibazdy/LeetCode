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

>思路：反向遍历



```c++
class Solution {
public:
    int lengthOfLastWord(string s) {
		int slow = s.length() - 1;
        while(s[slow] == ' ')      // 从字符串尾部找到第一个非空字符位置 slow
            slow--;
        int fast = slow;  
        while(s[fast] != ' ') {    // 从位置 slow 开始向前搜索当前单词的开头 fast
            fast--;
            if(fast < 0)           // 搜索到头，意味着只包含一个单词，s[0] 开始
                break;             // 也可以写成：return slow - fast;
        }
        return slow - fast;
    }
};
```

执行结果：
<img src="C:\Users\zdy\AppData\Roaming\Typora\typora-user-images\image-20241012095636440.png" alt="image-20241012095636440" style="zoom:33%;" />



## 反转字符串中的单词

【例 1】
输入：s = "the sky is blue"
输出："blue is sky the"

【例 2】
输入：s = "  hello world  "
输出："world hello"

> 思路：
>
> 1. 对原字符串去除多余空格；
> 2. 反转字符串；
> 3. 反转字符串中的单词；

1. 去除空格

   ```c++
   void removeSpace(string s) {
       // 1.去除开头空格
       int idx = 0;
       while(s[idx++] == ' ')
           s.erase(idx,1);
       
       // 2.去除尾部空格
       idx = s.length() - 1;
       while(s[idx--] == ' ')
           s.pop_back();
       
       // 3.去掉中间多余空格
       idx = 0;
       while(idx != (s.length()-1)) {
           if(s[idx] == ' ' && s[idx+1] == ' ')
               s.erase(idx,1);
           idx++;
       }
   }

2. 翻转每个单词

   ```c++
   void reverseEachWords(string s) {
       string::iterator iter1 = s.begin();
       string::iterator iter2 = s.begin();
       while(iter1 != s.end()) {
           while((*iter2) != ' ')
               iter2++;
           reverse(iter1, iter2);
           iter1 = iter2 + 1;
           iter2 = iter1;
       }
   }
   ```

   

```c++
class Solution {
public:
    string reverseWords(string s) {
		removeSpace(s);
        reverse(s.begin(),s.end());
        reverseEachWords(s);
        return s;
    }
};
```

