## 回文数（27）

### 问题描述



### 问题分析



### 问题解法

```C++
bool isPalindNumber(int x)
{
    if(x < 0 || (x % 10 == 0 && x != 0)) //两种特殊情况肯定不是回文数
    {
        return false;
    }
    int trans = 0; //变量trans存储翻转x之后的数字
    int tmp = x;   //变量tmp存储x的值，用来进行翻转
    while(tmp > 0)  //翻转过程
    {
        trans = tmp % 10 + trans * 10;
        tmp /= 10;
    }
    return trans == x;
}
```

