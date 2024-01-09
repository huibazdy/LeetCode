## 问题分析

> 用两个栈实现队列，主要实现两个函数：
>
> 从队尾插入节点——`appendTail`
>
> 从队头删除节点——`deleteHead`



## 预备知识

>  ***C++中的栈***

* 定义于头文件：`<stack>`
* 栈支持的操作：
    1. `empty()`：判断是否为空栈，空则返回true
    2. `size()`：返回栈内元素个数
    3. `push()`：压入（增加）新元素到栈顶
    4. `pop()`：弹出（删除）栈顶元素
    5. `top()`：访问栈顶元素，但不删除栈顶元素

【**代码示例**】

```C++
#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;
    for(int i = 0; i < 10; i++)    //将0~9按顺序压入栈
        s.push(i);
    while(!s.empty())   //若栈非空
    {
        cout<<s.top()<<endl;  //打印栈顶元素
        s.pop();              //删除栈顶元素
    }
    return 0;
}
```

运行效果：

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202211231135305.png" alt="image-20221123113543157" style="zoom: 67%;" />



> ***C++中的队列***

* 定义于头文件：`<queue>`
* 队列支持的操作：
    1. `empty()`：判断队列是否为空
    2. `size()`：返回队列元素个数
    3. `push()`：从队尾添加元素
    4. `pop()`：删除队首元素
    5. `front()`：返回队首，不删除元素
    6. `back()`：返回队尾，不删除元素

【**代码示例**】

```C++
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    for(int i = 0; i < 10; i++)
        q.push(i);
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}
```

执行结果：

<img src="https://raw.githubusercontent.com/huibazdy/TyporaPicture/main/202211231149151.png" alt="image-20221123114933110" style="zoom:67%;" />



## 剑指第9题

> ***用两个栈实现队列***

```C++
template<typename T>
class CQueue
{
    public:
        CQueue(void);
        ~CQueue(void);
        void appendTail(const T &node);
        T deleteHead();
    private:
        stack<T> stack1;
        stack<T> stack2;
};
```

入队列的实现：

```c++
template<typename T> T CQueue<T>::appendTail(const T &element)
{
    stack1.push(element);
}
```

出队列的实现：

```c++
template<typename T> T CQueue<T>::deleteHead()
{
    if(stack2.size() <= 0)
    {
        while(!stack1.empty())
        {
            T &data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    
    if(stack2.size() == 0)
        throw new exception("queue is empty");
    
    T head = stack2.top();
    stack2.pop();
    
    return head;
}
```



## LeetCode题型

### 225.用队列实现栈



### 232.用栈实现队列