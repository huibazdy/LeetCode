# LinkedList Review



| 题号 | 描述                      | 难度 | LeetCode链接 | 题解链接 |
| ---- | ------------------------- | ---- | ------------ | -------- |
| 19   | 删除链表的倒数第 N 个节点 | M    |              |          |
| 21   | 合并两个有序链表          | E    |              |          |
| 23   | 合并 K 个升序链表         | H    |              |          |
| 114  | 将二叉树展开为链表        | M    |              |          |
| 141  | 环形链表 1                | E    |              |          |
| 142  | 环形链表 2                | M    |              |          |
| 148  | 排序链表                  | M    |              |          |
| 160  | 相交链表                  | E    |              |          |
| 206  | 反转链表                  | E    |              |          |
| 234  | 回文链表                  | E    |              |          |



**链表定义**

```c++
struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode* next):val(x),next(next){}
};
```



**反转链表**

```c++
/*
**   头插法反转链表
*/
ListNode* reverseList(ListNode* head)
{
    if(head == nullptr || head->next == nullptr) //头指针为空或只有一个节点
        return head;
    
    ListNode* dummy = new ListNode(0,head); //用于找到反转后链表头结点的哑结点
    ListNide* tmp = new ListNode;  //辅助指针，用于记录反转进度（或者说新链表的插入位置）；
    tmp = nullptr;  //第一个被反转的节点应该插在dummy之后，nullptr之前，所以需要将tmp记为nullptr
    
    while(head != nullptr){
        dummy->next = head;      //插入节点到新链表（即：反转后的链表）
        head = head->next;       //更新 head，head 始终指向未反转部分的头结点
        dummy->next->next = tmp; //断开以插入新链表节点和之前链表的联系，借助 tmp
        tmp = dummy->next;       //更新原链表下一节点在新链表中的插入位置
    }
    return dummy->next;
}
```



