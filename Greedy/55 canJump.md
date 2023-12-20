# 55 canJump

> **跳跃游戏**

**题目描述：**

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230822142438301.png" alt="image-20230822142438301"  />

**示例 1 ：**

![image-20230822142639058](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230822142639058.png)

**示例 2 ：**

###### ![image-20230822142654988](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230822142654988.png)



> **解题思路**

1. 贪心
2. 动态规划

注意：这里的能否跳到指的是“能力”，也就是最后大于距离即可，而不是一定要刚好等于距离。





> **贪心**

贪心思想：每一次跳跃跳到最远距离（例如：能力为 3 ，可以跳 1 或 2，但是就跳 3），确认最远覆盖范围。



```c++
bool canJump(vector<int>& nums){
    int n = nums.size();
    if(n == 1)return true;     // 只有一个元素，肯定可以到达
    int furthest = 0;          // 注意，这里是索引，或者说是可以到达的最远位置
    for(int i = 0; i <= furthest; i++){           // i 在能力范围内移动
        furthest = max(furthest, i + nums[i]);    // 更新可以到达的最远距离，跳到最远
        if(furthest >= n-1)return true;             // 最终可以到达的判断条件
    }
    return false;
}
```

执行结果：

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230822173027239.png" alt="image-20230822173027239" style="zoom:50%;" />