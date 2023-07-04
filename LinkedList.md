## 链表

### 【21】合并两个有序链表

将两个升序链表合并为一个新的升序链表并返回，新链表通过给定链表的所有节点组成



<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202211271947568.png" alt="image-20221127194734525" style="zoom:50%;" />

```C++
/*Definition of single-linked list
struct ListNode
{
	int val;
	ListNode *next;
	ListNode():val(0),next(nullptr){}
	ListNode(int x):val(x),next(nullptr){}
	ListNode(int x,ListNode *next):val(0),next(next){}
};
*/

ListNode* mergeTwoLists(ListNode *list1,ListNode *list2)
{
    //使用带头结点的链表方案
    
    ListNode *list = new ListNode;  //声明一个新链表作为结果返回
    ListNode *temp = list；  //用于新链表生成，会变
    
    while(list1 != nullptr && list2 != nullptr)
    {        
        if(list1.val <= list2.val) 
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    
    return list->next;  //因为采用的是带头结点的链表，所以返回首节点需要指向下一个位置
}
```



### 【2】两数相加

两个非空链表，表示两个非负整数，它们的每位数字按逆序存储，将两数相加并按相同形式链表返回。

输入：L1=[2,4,3]，L2=[5,6,4]

输出：L=[7,0,8]

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202211281653113.png" alt="image-20221128165316005" style="zoom:67%;" />

```C++
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode *L = new ListNode;  //新链表头结点，之后返回头结点的下一个结点
    ListNode *temp = L;  //临时节点，用来链接新创建的节点
    
    int carry = 0; //用于进位
    
    while(l1 != nullptr && l2 != nullptr)
    {
        ListNode *born = new ListNode;
        int ans = l1->val + l2->val + carry;
        if(ans > 9)
        {
            born->val = ans % 10;
            carry = ans / 10;
        }
        else
        {
            born->val = ans;
            carry = ans / 10;
        }
        born->next = nullptr;
        temp->next = born;
        temp = temp->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    if(!l1 && !l2)    //两个链表长度相等
    {
        if(carry) //处理进位
        {
            ListNode *born = new ListNode;
            born->val = carry;
            born->next = nullptr;
            temp->next = born;
        }
        else
        {
            return L->next;  //此处可以省略
        }
    }

    if(!l2)      //l1比l2长，l2先遍历完
    {
        while(l1)
        {
            ListNode *born = new ListNode;
            int ans = l1->val + carry;
            if(ans > 9)
            {
                born->val = ans % 10;
                carry = ans / 10;
            }
            else
            {
                born->val = ans;
                carry = ans / 10;
            }         
            born->next = nullptr;
            temp->next = born;
            temp = temp->next;
            l1 = l1->next;
        }
        if(carry)  //处理进位
        {
            ListNode *born = new ListNode;
            temp->next = born;
            born->val = carry;
            born->next = nullptr;
        }
    }
    
    if(!l1)    //l2比l1长，l1先遍历完
    {
        while(l2)  
        {
            ListNode *born = new ListNode;
            int ans = l2->val + carry;
            if(ans > 9)
            {
                born->val = ans % 10;
                carry = ans / 10;
            }
            else
            {
                born->val = ans;
                carry = ans / 10;
            }
            born->next = nullptr;
            temp->next = born;
            temp = temp->next;
            l2= l2->next;
        }
        if(carry)  //处理进位
        {
            ListNode *born = new ListNode;
            temp->next = born;
            born->val = carry;
            born->next = nullptr;
        }
    }
    
    return L->next;
}
```



### 【19】删除链表的倒数第N个节点

给定一个链表，删除链表倒数第n个节点，并返回链表头结点。

已知：

* 节点数为：`sz`，且`1 <= sz <= 30`
* n满足：`1 <= n <= sz`

```C++
ListNode* removeNthFromEnd(ListNode *head,int n)
{
    int sz = 1;              //存储链表元素个数
    ListNode *temp = head;   //用于遍历链表来计算链表元素个数
    while(temp->next != nullptr)
    {
        ++sz;
        temp = temp->next;
    }
    
    if(n <= sz)   //如果输入n超出元素总个数则无意义
    {
        int m = sz - n + 1;   //倒数第n个节点就是正数第m个节点
        ListNode *dummy = new ListNode;  //新建哑结点
        dummy->next = head;   //哑结点链接到现在的头结点
        ListNode *pre = dummy;   //用来记录要删除节点的前一个节点，初始化为哑结点
        for(int i = 1; i < m ; i++)  
        {
            pre = pre->next;    //找到要删除节点的前一个位置
            head = head->next;  //找到要删除的节点
        }
        pre->next = head->next; //删除节点
        delete head;
        return dummy->next;
    }
    return head;
}
```



### 【24】两两交换链表中的节点

> 节点数目范围：`[0,100]`



```c++
ListNode* swapPairs(ListNode *head)
{
    int sz;  //用来记录链表元素个数
    while(head != nullptr)
    {
        ++sz;
        head = head->next;
    }
    
    if(sz <= 1)   //链表中没有元素或只有一个元素
        return head;
    
    ListNode *ans = head;  //用于返回交换后的链表
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    while(fast != nullptr)
    {
        //交换两个节点
        ListNode *temp = fast->next;
        fast->next = slow;
        slow->next = temp;
        //移动两个定位指针，移动距离为2，此时slow在前，fast反而在后，需要调换一次
        temp = fast;
        fast = slow;
        slow = temp;
        //移动
        slow = slow->next->next;
        fast = fast->next->next;
    }
    return ans;
}
```

官方题解：

```C++
ListNode* swapPairs(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *temp = dummy;
    while(temp->next != nullptr && temp->next->next != nullptr)
    {
        ListNode *slow = temp->next;
        ListNode *fast = temp->next->next;
        temp->next = fast;
        slow->next = fast->next;
        fast->next = slow;
        temp = slow;
    }
    return dummy->next;
}
```



### 【61】旋转链表

> 将链表的每个节点向右移动`k`个位置

![image-20221203164428476](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212031644632.png)

![image-20221203164524684](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212031645726.png)

设链表长度为`n`

如果旋转次数为`n` 的整数倍则还原，即实际旋转长度为`m = k % n`

实际上旋转`m`个位置，就是将最后的`m`个元素组成的链表拼接到开头。

```c++
ListNode* rotateRight(ListNode* head,int k)
{   
    int n = 0;  //存储链表长度
    ListNode *temp = new ListNode;//用于遍历链表来计算表长
    temp = head;
    while(temp)  //计算链表长度
    {
        ++n;
        temp = temp->next;
    }
    
    int m; //存储实际旋转长度
    if(n != 0)  //防止除数为0报错
        m = k % n;
    else
        return head;
    
    if(k == 0 || m == 0 || head == nullptr || head->next == nullptr) //边界条件
        return head;
    
    ListNode *newStart = new ListNode;
    ListNode *oldEnd = new ListNode;
    ListNode *newEnd = new ListNode;
    newStart = oldEnd = newEnd = head;
    
    //移动m次找到新的表头节点
    int movTimes = n - m;
    while(movTimes-- && newStart->next != nullptr)
        newStart = newStart->next;
    //找到新的链表结尾
    while(newEnd->next != newStart)
        newEnd = newEnd->next;
    //移动n-1次找到原链表尾部节点
    while(oldEnd->next != nullptr)
        oldEnd = oldEnd->next;
    
    newEnd->next = nullptr;  //断开新表尾部与新表头部
    oldEnd->next = head;     //拼接
    
    return newStart;         //返回新表头
}
```





### 【83】删除已排序链表中的重复值

给定链表默认按升序排列：

![image-20221205145927617](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212051459678.png)

```C++
ListNode* deleteDuplicates(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)  //边界条件
        return head;

 	ListNode *slow = new ListNode;
    ListNode *fast = new ListNode;
    slow = head;
    fast = slow->next;
    while(fast != nullptr)
    {
        if(slow->val < fast->val) //依然有序，且不重复
        {
            slow = slow->next;
            fast = fast->next;
        }
        else  //存在重复项情况（前提是链表有序，所以只剩下相等的情况），删除重复项
        {
            slow->next = fast->next;
            fast = slow->next;
        }
    }
    return head;       
}
```

执行结果：

![image-20221205151810113](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212051518158.png)





### 【82】删除已排序链表中的重复值2

> 和上题不同的是，此题需要删除出现重复的数值所对应的所有节点

![image-20221205153615251](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212051536308.png)

【**官方题解**】

> 因为重复元素可能出现在链表的开头，所以`head`可能会变，故而需要添加哑结点`dummy`

```c++
ListNode* deleteDuplicates(ListNode* head)
{
    //边界条件：无节点或只有一个节点
    if(head == nullptr || head->next == nullptr)
        return head;
    
    //添加哑结点，并链接到当前head元素
    ListNode *dummy = new ListNode(0,head);
    
    ListNode *cur = new ListNode;      //声明一个用来遍历链表的节点指针：cur
    cur = dummy;                       //为什么初始化为dummy而不是head？？？             
    
    //为了适用while中的条件，才将cur初始化为dummy而不是head
    while(cur->next != nullptr && cur->next->next != nullptr)
    {
        if(cur->next->val == cur->next->next->val)
        {
            int temp = cur->next->val;                   //记录重复的值
            while(cur->next && cur->next->val == temp)     //继续向后遍历直到出现不同的值
                cur->next = cur->next->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    return dummy->next;
}
```

















### 【206】反转链表

【方法一】==***三指针迭代***==

```C++
ListNode* reverseList(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)  //边界条件：无节点或只有一个节点
        return head;
    else
    {
        ListNode *start = new ListNode;  
        ListNode *mid = new ListNode;
        ListNode *end = new ListNode;
        start->next = head;
        mid = head;
        end = head->next;
        while(end != nullptr)
        {
            mid->next = start;  //反转节点
            //三个节点整体后移一个位置
            start = mid;
            mid = end;
            end = end->next;
        }
        mid->next = start;  //最后一次end已经为null但是还差尾部元素的一次反转
        head->next = nullptr; //将之前的头节点接“接地”，第一次反转到了初始start
        return mid;
    }
}
```

执行结果：

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212101417299.png" alt="image-20221210141742192"  />

【方法二】==***头插法***==

```C++
ListNode* reverseList(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)  //边界条件：无节点或只有一个节点
        return head;
    else
    {
        ListNode *dummy = new ListNode(0,head);  //头插法起始哑结点
        ListNode *temp = new ListNode();  //用来记录上一次插入的节点
        temp = nullptr;
        
        while(head != nullptr)
        {
            dummy->next = head; //头插连接新节点
            head = head->next;    //更新head
            dummy->next->next = temp;  //断开旧head
            temp = dummy->next;  //更新temp为这一次插入的节点以便下次再插入新节点
        }
        return dummy->next;
    }
}
```

提交结果：

![image-20221210233723478](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212102337532.png)





### 【92】反转链表2

![image-20221211131042123](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212111310244.png)



```C++
ListNode* reverseBetween(ListNode* head, int left, int right)
{
    if(head == nullptr || head->next == nullptr || left == right)
        return head;
    
    //头结点可能变化，多以需要加入哑结点
    ListNode *dummy = new ListNode(0,head);
    
    //分析问题关键在于找到需要反转的起止点,来反转中间部分，即：(start,end)
    ListNode *start = new ListNode;       //左开区间（待反转部分的前一个元素）
    ListNode *end = new ListNode(0,head); //右开区间（待反转部分的后一个元素）
    
    start = dummy;  //找到第left个元素的前一个元素位置
    while(--left)   //start需要移动left - 1次
    {
        if(start->next != nullptr)
        	start = start->next;
        else
            return head; //第left个元素就是最后一个元素，无需反转
    }      
    
    int mov = right + 1;
    while(mov--)  //需要移动right + 1次
    {
        end = end->next;
    }
    
    ListNode *H = new ListNode;
    ListNode *temp = new ListNode;
    H = start->next;  //头插法链表部分head元素
    temp = end; //头插法临时元素，反转全部链表初始化为nullptr，因为nullptr就是边界，此时边界为end
    while(H != end) //执行头插法反转
    {
        start->next = H; //头插
        H = H->next;  //更新‘head’
        start->next->next = temp; //断开头插元素原链接
        temp = start->next; //更新下一个头插位置
    }
    return dummy->next;
}
```

执行结果：

![image-20221212143111174](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212121431230.png)





### 【203】移除链表元素

![image-20221211213257209](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212112132285.png)



```C++
ListNode* removeElements(ListNode* head, int val)
{
    if(head == nullptr)
        return head;
    ListNode *dummy = new ListNode(0,head);//由于头结点可能改变，所以需要声明一个哑结点
    ListNode *cur = new ListNode;//声明一个用于遍历链表的指针cur，初始化为dummy
    cur = dummy;
    while(cur->next != nullptr)
    {
        if(cur->next->val != val)
            cur = cur->next; //继续遍历
        else
            cur->next = cur->next->next; //删除节点
    }
    return dummy->next;
}
```

运行结果：

![image-20221211214856473](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212112148523.png)





### 【141】判断链表是否有环

> 怎么定义有环？
>
> 如果链表中某个节点，可以通过next指针再次到达，则链表中有环。

![image-20221212153423669](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212121534740.png)



![image-20221212153727646](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212121537719.png)

```c++
bool hasCycle(ListNode *head)
{
    //快慢指针
    ListNode *slow = new ListNode;
    ListNode *fast = new ListNode;
    slow = fast = head;
    //两个指针开始遍历
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;        //慢指针一次走一步
        fast = fast->next->next;  //快指针一次走两步
        if(slow == fast)          //快慢指针相遇，说明有环
            return true;
    }
    return false;
}
```

执行结果：

![image-20221212160742306](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212121607356.png)





### 【142】环形链表环入口

* 设快指针走过的路程为：`2m`，慢指针走过的路程为：`m`
* 设环的长度为`n`，当两个指针相遇时，快指针比慢指针多走环长度的整数倍：`2m = m + N * n`
* 可以得出：`m = n * N`，也就是说慢指针走的也是环长的整数倍

> ***关键***：slow与fast相遇后，slow从相遇点开始，新指针从head开始，步长为1，相遇点即入口节点

```c++
ListNode *detectCycle(ListNode *head)
{
    if(head == nullptr || head->next == nullptr)
        return nullptr;
    //1.判断是否存在环
    bool isCycle = false;
    ListNode *slow = new ListNode;
    ListNode *fast = new ListNode;
    slow = fast = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
        {
            isCycle = true;
            break;
        }
    }
    if(!isCycle)
        return nullptr;
    //2.找到环的入口：slow从相遇点开始，new一个节点从head开始，步长都为1，相遇点即入口
    ListNode *temp = new ListNode;
    temp = head;
    if(isCycle)
    {
        while(temp != slow)
        {
            temp = temp->next;
            slow = slow->next;
        }
    }
    return slow;
}
```

执行结果：

![image-20221212204121611](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212122041667.png)





### 【160】相交链表

思路：

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212131437279.png" alt="image-20221213143718178" style="zoom: 50%;" />

如上图，若两个链表有交点，设链表A的节点数为`a`，链表B的节点数为`b`，公共链表的节点数为`c`（从交点到链表尾部的元素）。

令`Pa`指向A首元素，`Pb`指向B首元素，Pa遍历（步长为1）完A链表走了`a`个节点，Pb遍历（步长为1）完A链表走了`b`个节点。

此时，再令Pa指向`headB`，Pb指向`headA`，再次同时开始遍历，直到都走到交点处，此时两个指针遍历过的节点数分别为：

Pa遍历的节点数：`a + (b - c)`

Pb遍历的节点数：`b + (a - c)`

可以容易得出上面两个式子相等，即再次开始遍历后，若这两个指针相等，则存在交点。



```C++
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if(headA == nullptr || headB == nullptr)
        return nullptr;
    ListNode *pa = new ListNode;
    ListNode *pb = new ListNode;
    pa = headA;
    pb = headB;
    while(pa != pb)
    {
        if(pa != nullptr)
            pa = pa->next;
        else             //pa已经遍历到ListA尾部
            pa = headB;      
        if(pb != nullptr)
            pb = pb->next;
        else             //pb已经遍历到ListB尾部
            pb = headA;      
    }
    return pa;  //包括了相交点，以及无相交都指向nullptr的情况
}
```

执行结果：

![image-20221213172623826](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212131726887.png)





### 【234】回文链表

![image-20221213172913847](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212131729918.png)

> 思路一：***反转链表***后半部分比较是否与链表前半部分相同

```c++
bool isPalindrome(ListNode* head)
{
    //边界条件：无节点或只有一个节点，直接判为回文
    if(head == nullptr || head->next == nullptr)
        return true;
    
    //1. 快慢指针找到链表中点
    ListNode *slow = new ListNode;  //步长为1
    ListNode *fast = new ListNode;  //步长为2
    slow = fast = head;
    while(slow != nullptr && fast != nullptr)
    {
        slow = slow->next; 
        if(fast->next != nullptr)     
        	fast = fast->next->next;
        else                          
            fast = fast->next;
    }
    
    //2. 头插法反转后半部分链表
    ListNode *dummy = new ListNode;  //为待反转部分创建哑结点
    ListNode *temp = new ListNode;          //临时节点
    temp = nullptr;
    while(slow != nullptr)  //slow就是待反转部分的“head”节点
    {
        dummy->next = slow;  //头插
        slow = slow->next;   //更新“head”
        dummy->next->next = temp;  //断开原链接
        temp = dummy->next;  //更新temp
    }
    
    //3. 比较后半部分（可能会比前半少一个元素）与前半部分
    ListNode *start = new ListNode;
    start = dummy->next;
    while(start != nullptr)
    {
        if(head->val == start->val)
        {
            head = head->next;
            start = start->next;
        }
        else
            return false;
    }
    return true;
}
```

执行结果：

![image-20221214150001080](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212141500153.png)



> 思路二：使用***栈***，先将后半部分值入栈；再出栈与前半部分比较





### 【147】对链表进行插入排序

插入排序：

```c
void insertionSort(int *arr,int n)
{
    int i,j;
    for(i = 1; i < n; i++)      //首元素默认已排序完成，故需要n-1趟插入
    {
        int temp = arr[i];      //记录待插入的元素
        for(j = i; j > 0 && arr[j-1] > temp; j--)
            arr[j] = arr[j-1];  //大的元素后移
        arr[j] = temp;          //找到合适的位置了，插入待插入元素
    }
}
```



题解：

```c++
ListNode* insertionSortList(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)  //边界条件
        return head;
    //1. 将链表元素的值全部拷贝出来，存储在nums向量中
    vector<int> nums;
    ListNode *cur = new ListNode(0,head);
    while(cur->next != nullptr)
    {
        nums.push_back(cur->next->val);
        cur = cur->next;
    }
    //2. 对nums向量进行插入排序
    int i,j;
    for(int i = 1; i < nums.size(); i++)
    {
        int temp = nums[i];
        for(j = i; j > 0 && nums[j-1] > temp; j--)
            nums[j] = nums[j-1];
        nums[j] = temp;
    }
    //3. 将nums的值依次拷贝进链表
    ListNode *newCur = new ListNode(0,head);
    for(int index = 0; index < nums.size(); index++)
    {
        if(newCur->next != nullptr)
        {
            newCur->next->val = nums[index];
            newCur = newCur->next;
        }
    }
    return head;
}
```

运行结果：

![image-20221214174434724](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212141744810.png)





### 【237】删除链表中的节点

![image-20221215164201863](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212151642951.png)

```C++
void deleteNode(ListNode* node)
{
    ListNode *pre = new ListNode;
    ListNode *cur = new ListNode;
    ListNode *end = new ListNode;
    pre = head;
    cur = head->next;
    if(cur->next != nullptr)
        end = cur->next;
    else  
        return head;  //只有两个节点
    
    while(end->next != nullptr)  //cur遍历右边界是最后一个节点，因为不能删除尾节点
    {
        
    }
}
```





### 【238】奇偶链表

![image-20221215170548710](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212151705818.png)



```c++
ListNode* oddEvenList(ListNode* head)
{
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return head;    //n为0、1、2都不需要重排
    ListNode *dummy = new ListNode;  //新链表的哑结点
    ListNode *ansDummy = new ListNode; //用于返回结果
    ansDummy = dummy;  
    ListNode *cur = new ListNode;  //cur用于遍历原链表奇数节点
    cur = head;
    //1. 复制奇数链表
    while(cur != nullptr)
    {
        ListNode *odd = new ListNode; //创建复制的奇数节点
        odd->val = cur->val; //复制值
        dummy->next = odd;   //链接
        dummy = dummy->next;  //更新新链表的尾部
        if(cur->next != nullptr)
            cur = cur->next->next; 
        else
            break;
    }
    //2. 复制偶数链表
    cur = head->next;  //从原链表第二个元素开始遍历
    while(cur != nullptr)
    {
        ListNode *even =  new ListNode;  //创建复制的偶数节点
        even->val = cur->val; //复制值
        dummy->next = even;   //链接
        dummy = dummy->next;  //更新新链表尾部
        if(cur->next != nullptr)
            cur = cur->next->next;
        else
            break;
    }
    return ansDummy->next;  //返回新链表的头结点
}
```

执行结果：

![image-20221215175722432](https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202212151757504.png)





### 【445】两数相加 2



```c++
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    if(l1->val == 0)
        return l2;
    if(l2->val == 0)
        return l1;
    
    //1. 头插法反转链表l1
    ListNode *dummy1 = new ListNode(0,l1);
    ListNode *temp1 = new ListNode;
    temp1 = nullptr;
    while(l1 != nullptr)
    {
        dummy1->next = l1;
        l1 = l1->next;
        dummy1->next->next = temp1;
        temp1 = dummy1->next;
    }
    //2. 头插法反转链表l2
    ListNode *dummy2 = new ListNode(0,l2);
    ListNode *temp2 = new ListNode;
    temp2 = nullptr;
    while(l2 != nullptr)
    {
        dummy2->next = l2;
        l2 = l2->next;
        dummy2->next->next = temp2;
        temp2 = dummy2->next;
    }
    //3. 反转后的链表相加
    ListNode *head1 = new ListNode;
    ListNode *head2 = new ListNode;
    head1 = dummy1->next;
    head2 = dummy2->next;
    int carry = 0;  //处理进位
    int sum  =0;    //处理和
    ListNode *last = new ListNode;  //记录最后一次的head1或者head2
    while(head1 != nullptr && head2 != nullptr) //先将等长部分都加到链表1上
    {
        sum = head1->val + head2->val + carry;
        if(sum > 9){
            carry = 1;
            head1->val = sum % 10;
        }
        else{
            carry = 0;
            head1->val = sum;
        }
        last = head1;  //记录最后一次不为nullptr的head1
        head1 = head1->next;
        head2 = head2->next;
    }

    if(head1 != nullptr)  //链表1更长，此时链表2已遍历完
    {
        while(head1 != nullptr){
            sum = head1->val + carry;
            if(sum >> 9)
                carry = 1;
            else 
                carry = 0;
            head1->val = sum % 10;
            last = head1;
            head1 = head1->next;
        }
        if(carry)  //此时遍历完但是有进位
        {
            ListNode *born = new ListNode(carry,nullptr);  //创建新节点
            last->next = born; // 链接新节点
            //反转此时的链表1
            head1 = dummy1->next;
            temp1 = nullptr;
            while(head1){
                dummy1->next = head1;
                head1 = head1->next;
                dummy1->next->next = temp1;
                temp1 = dummy1->next;
            }
        }
        else
        {
            //反转此时的链表1
            head1 = dummy1->next;
            temp1 = nullptr;
            while(head1){
                dummy1->next = head1;
                head1 = head1->next;
            	dummy1->next->next = temp1;
            	temp1 = dummy1->next;
        	}
        }
        return dummy1->next;
    }
    else if(head2 != nullptr) //链表2更长，此时链表1已遍历完
    {
        while(head2 != nullptr){
            sum = head2->val + carry;
            if(sum >> 9)
                carry = 1;
            else 
                carry = 0;
            head2->val = sum % 10;
            last = head2;
            head2 = head2->next;
        }
        if(carry)  //此时遍历完但是有进位
        {
            ListNode *born = new ListNode(carry,nullptr);  //创建新节点
            last->next = born; // 链接新节点
            //反转此时的链表2
            head2 = dummy2->next;
            temp2 = nullptr;
            while(head2){
                dummy2->next = head2;
                head2 = head2->next;
                dummy2->next->next = temp2;
                temp2 = dummy2->next;
            }
        }
        else
        {
            //反转此时的链表2
            head2 = dummy2->next;
            temp2 = nullptr;
            while(head2){
                dummy2->next = head2;
                head2 = head2->next;
            	dummy2->next->next = temp2;
            	temp2 = dummy2->next;
        	}
        }
        return dummy2->next;
    }
    else     //两个链表等长
    {
        if(carry == 0){   //反转链表1
            head1 = dummy1->next;
            temp1 = nullptr;
            while(head1){
                dummy1->next = head1;
                head1 = head1->next;
                dummy1->next->next = temp1;
                temp1 = dummy1->next;
            }
            return dummy1->next;
        }
        else
        {
            ListNode *born = new ListNode(1,nullptr);  //生成新节点
            last->next = born;  //链接新节点
            head1 = dummy1->next;
            temp1 = nullptr;
            while(head1){  //反转链表
                dummy1->next = head1;
                head1 = head1->next;
                dummy1->next->next = temp1;
                temp1 = dummy1->next;
            }
            return dummy1->next; 
        }
    }
}
```







