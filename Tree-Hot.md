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
bool isSameTree(TreeNode* p, TreeNode* q)
{
    if(p == nullptr && q == nullptr)   // 根节点都为空
        return true;
    else if(p == nullptr || q == nullptr) // 根节点只有一个为空
        return false;
    else if(p->val != q->val) // 根节点非空但值不相同
        return false;
    else     // 左子树和右子树都相同
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}
```



## 对称二叉树

> 【**递归**】实现这样一个比较节点的递归步骤：**同步移动**两个指针，遍历节点同时检查**节点指针**是否相同以及**节点值**是否相同。



```c++
bool checkSame(TreeNode* p, TreeNode* q)
{
    if(!p && !q)        // 两个节点都为空
        return true;
    else if(!p || !q)   // 两个节点一个为空另一个不为空
        return false;
    else                // 节点值相同且左节点和右节点都相同
        return p->val == q->val && checkSame(p->left,q->left) && checkSame(p->right,q->right);
}

bool isSymmetric(TreeNode* root)
{
    return checkSame(root);
}
```
