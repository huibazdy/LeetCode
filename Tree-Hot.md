# 树合集

> 树节点的定义



```c++
typedef struct BinaryTreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
    TreeNode(int x,struct TreeNode* le,struct TreeNode* ri):
    	val(x), left(le), right(ri) {}
}TreeNode;
```



## 相同的树

灵活使用递归，深度优先搜索

```c++

```

