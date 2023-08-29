# 46 permute

![image-20230823173230043](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/image-20230823173230043.png)

数组中所有元素都不同；且数组长度不为 0 。



> 回溯法

回溯三部曲：

1. 终止条件
2. 回溯函数的参数列表
3. 单层逻辑



终止条件：

从树的角度看，终止条件是到了叶子节点；从题意出发，是找到了一个全排列，也就是 path 的长度达到 n 。



参数列表：

首先是终止条件判断，肯定要带参数 n ，也就是数组长度；

后续还要用到数组元素；

综合考虑只需要数组本身作为参数即可。



```c++
void backtracking(vector<int> nums) {
    if(path.size() == nums.size()){
        res.push_back(path);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        path.push_back(nums[i]);
        backtracking();
        path.pop_back();
    }
}
```







```c++
vector<vector<int>> permute(vector<int> nums) {
    
}
```