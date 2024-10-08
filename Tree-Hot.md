# 树合集

## 树节点的定义

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



## 二叉树的最大深度

> 【**递归**】经典递归问题，学习递归思想

```c++
int maxDepth(TreeNode* root)
{
    if(!root)
        return 0;
    //求出左子树的最大深度
    int leftDepth = maxDepth(root->left);
    //求出右子树的最大深度
    int rightDepth = maxDepth(root->right);
    //熟的最大深度为左右子树最大深度的较大值加1
    return max(leftDepth, rightDepth) + 1;
}
```

通过网站：https://pythontutor.com/ 来可视化递归过程。



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
    return checkSame(root,root);
}
```



```c++
bool isSameTree(TreeNode* p, TreeNode* q)
{
    if(!p && !q)
        return true;
    else if(!p || !q)
        return flase;
    else
        return p->val==q->val && isSameTree(p->left,q->right && isSameTree(p->right,q->left);
}
//注意此处的“same”是左子树等于右子树（因为是在同一棵树中比较子树），而不是左右分别相等（不同的两棵树比较）
bool isSymmetric(TreeNode* root)
{
    return isSameTree(root->left,root->right); 
}
```



## 翻转二叉树

> 递归思路：
>
> 1. 对整颗树作镜像，就是对根节点的的左右子树作镜像；
> 2. 接着继续向下，分别对 `root->left` 和`root->right`作镜像翻转；
> 3. ...
> 4. 直到最后一层叶子节点分别作镜像反转（交换）；



```c++
TreeNode* invertTree(TreeNode* root)
{
    if(!root || !(root->left) && !(root->right)) //没有节点或只有一个节点
        return root;
    
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    
    invertTree(root->left);  // 翻转左子树
    invertTree(root->right); // 翻转右子树
    
    return root;
}
```

执行结果：

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202409131041875.png" alt="image-20240913104118639" style="zoom: 50%;" />

图解：

```mermaid
flowchart TB
	A1((1))
	
	A1---A2((2))
	A1---A3((3))
	
	A2---A4((4))
	A2---A5((5))
	A3---A6((6))
	A3---A7((7))
```

第一次递归后：

```mermaid
flowchart TB
	A1((1))
	
	A1---A2((3))
	A1---A3((2))
	style A2 fill:#f96
	style A3 fill:#09f
	
	A2---A4((4))
	A2---A5((5))
	A3---A6((6))
	A3---A7((7))
```

第二次递归后

```mermaid
flowchart TB
	A1((1))
	
	A1---A2((3))
	A1---A3((2))
	
	
	A2---A4((5))
	A2---A5((4))
	style A4 fill:#f96
	style A5 fill:#09f
	A3---A6((7))
	A3---A7((6))
	style A6 fill:#f96
	style A7 fill:#09f
```

最后一次递归，以root为对称轴

```mermaid
flowchart TB
	A1((1))
	
	A1---A2((3))
	A1---A3((2))
	
	
	A2---A4((5))
	A2---A5((4))
	style A4 fill:#f96
	style A5 fill:#09f
	A3---A6((7))
	A3---A7((6))
	style A6 fill:#f96
	style A7 fill:#09f
```



