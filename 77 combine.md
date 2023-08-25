# 77 combine

组合问题

> 回溯法

---





> **怎样记录组合（路径）？**

---

声明一个数组 `vector<int> path;` 来记录得到的组合。



> **怎样判断终止条件？**

---

终止一般就是遍历到叶子节点。那么怎样说明到了叶子节点不再继续向下了呢？

可以利用已经得到路径的长度，如果该长度已经达到题目给出的要求 k ，则无需在向下遍历，代码如下：

```c++
if(path.size() == k){
    //终止继续向下递归
}
```



> **怎样遍历避免重复？**

---

从当前选取数字的下一个数字开始，怎样标记下一个位置，可以选取一个值来标记，例如：`start_index`。

例如：第一个节点选 **1** ，那么下一层的节点只能在 ${2,3,4}$ 中选取 ，其中 **2** 就是 start_index 。

  

那么选取的代码块应该是：

```c++
//单层递归逻辑
for(int i = start_index; i <= n; i++){  //选取下一层的节点加入路径
    path.push_back(i);
    backtracking(n,k,i+1);  // 需要告知下一次递归的起始位置
    path.pop_back();        // 弹出，撤销已经遍历过的值
}
```



> **最终代码**

---



```c++
vector<vector<int>> res;   // 结果
vector<int> path;          // 某一个符合条件的组合

void backtracking(n, k, start_index) {
    if(path.size() == k){     //终止递归
        res.push_back(path);  //收集一个组合
        return;
    }
    for(int i = start_index; i<= n; i++){
        path.push_back(i);
        backtracking(n, k, i+1);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    backtracking(n, k, 1);
    return res;
}
```

