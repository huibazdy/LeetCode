# 121 maxProfit

买卖股票的最佳时机

题目描述：

![image-20230822151310798](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230822151310798.png)

示例 1 ：

###### ![image-20230822151329550](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230822151329550.png)

示例 2 ：

![image-20230822151351125](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230822151351125.png)



> **暴力法**：时间复杂度 $\bold{O(n^2)}$ ，空间复杂度 $\bold{O(1)}$

暴力法找最优间距：

```c++
int maxProfit(vector<int>& prices){
    int res = 0;
    for(int i = 0; i < prices.size(); i++){
        for(int j = i+1; j < prices.size(); j++){
            res = max(res, prices[j]-prices[i]);
        }
    }
    return res;
}
```

执行结果：超时

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230822163614876.png" alt="image-20230822163614876" style="zoom: 50%;" />



> **贪心**：时间复杂度 $\bold{O(n)}$ ，空间复杂度 $\bold{O(1)}$

因为只买卖一次，所以自然想到买入最低（取最左最小值），卖出最高（取最右最大值），差值即利润。

```c++
int maxProfit(vector<int>& prices) {
    if(prices.size() == 0)return 0;
    int low = prices[0];
    int res = 0;
    for(int i = 0; i < prices.size(); i++){
        low = min(low, prices[i]);        //找到左边最小值
        res = max(res, prices[i] - low);  //找到最大利润差值
    }
    return res;
}
```

执行结果：

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230822165242290.png" alt="image-20230822165242290" style="zoom:50%;" />



## 子问题

以 nums[i] 为结尾的子数组的最大利润



## 递推关系





## DP 数组







```c++
int maxProfit(vector<int> prices){
    
}
```