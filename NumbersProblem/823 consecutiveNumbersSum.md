# 823 consecutiveNumbersSum

【困难】（HW 笔试题，找出数量最小的组合）

给定一个正整数 n ，返回连续正整数满足它们的和是 n 的组数。

![image-20231225163712933](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20231225163712933.png)

> 注意：数字 n 本身也算是一种连续正整数的情况

暴力法不可行。通过数学方法缩小遍历范围。



如果存在这样的连续整数序列，描述它们需要两个参数，分别是首项`s`以及数列长度`L`。那么这个

等差数列的尾项是`s + L - 1`，根据等差数列的求和公式可以得出它们的和可以表示为：`(2s+L-1)*L/2`

根据和为 n 可以得出：
$$
2s = \frac{2n}{L}\:-\:L\:+\:1
$$
可以看出***等式右边一定为偶数***；又因为 **s** 为正整数（大于等于 1 ），可以得出：
$$
2s = \frac{2n}{L}\:-\:L\:+\:1\:\geq\:2
$$
此处可以看出 ***L 必然是 2n 的约数***，		且进一步可以推出：
$$
\frac{2n}{L}\:\geq\:L\:+\:1
$$
等同于：
$$
\frac{2n}{L}\:>\:L\:\Leftrightarrow\:L\:<\:\sqrt{2n}
$$
由此可以得出满足和为 **n** 的连续正整数***长度不会超过 $\sqrt{2n}$*** 。



> 目前根据和为 n 这个条件得到的有效信息（约束条件）有：

1. 根据等式，得知 $2s\:=\:\frac{2n}{L}\:+\:L\:-\:1$ 一定是偶数
2. **L** 得是 **2n** 的约数；
3. **L** 大小不会超过 $\sqrt{2n}$



还需要有一个认知是：

一旦 **L** 找到，那么它对应的符合和为 **n** 的数列一定是**唯一**的。因此，找到是符合条件的 **L** ，就相当于找到了一组数列，返回的结果就可以加 **1** 了。查找符合条件的 L 的范围是：$[1,\sqrt{2n})$



> 综上，可以写出代码

```c++
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int res = 0;
        n = n * 2;     // 因为约束条件都只与 2n 相关，所以将 n 替换为 2n
        for(int L = 1; L * L < n; L++) {    // 满足条件 3
            if(n % L != 0)                  // 满足条件 2，若不满足继续遍历
                continue;
            if((n / L + L - 1) % 2 == 0)    // 需要满足条件 1
                res++;
        }
        return res;
    }
};
```



> 运行结果

![image-20231226112757781](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20231226112757781.png)



> 【拓展】华为笔试题，输入 n ，输出满足条件的最小 L

```c++
#include <iostream>
#include <set>

int main()
{
    std::set<int> res;
    
    int n;
    std::cin>>n;
    
    n *= 2;
    
    for(int L = 1; L * L < n; L++){    // 条件 3
        if(n % L != 0)                 // 条件 2
            continue;
        if((n/L + L - 1) % 2 == 0)     // 条件 1
            res.insert(L);             // 加入集合，并会自动排序
    }
    
    auto iter = res.begin();
    iter++;
    std::cout<<*iter<<std::endl;      // 输出第二个元素，也就是不包含本身的情况
    
    return 0;
}
```

输入：9
输出：2 （即：4+5）

输入：30
输出：3（即：9+10+11）