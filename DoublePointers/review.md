# 125. 验证回文串

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



# 392 判断子序列

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