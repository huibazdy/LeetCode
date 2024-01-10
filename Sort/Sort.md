## 0. 辅助函数

* 生成随机数组

* 打印数组

    ```C++
    void printArray(vector<int> &nums)
    {
        for(int i = 0; i < nums.size(); i++)
            std::cout<<nums[i]<<" ";
    }
    ```

* 测试是否有序

    ```C++
    bool isSorted(vector<int> &nums)
    {
        if(nums.size() == 1)
            return true;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < nums[i+1])
                return false;
        }
        return true;
    }
    ```

* 测试运行时间

* 比较大小

* 交换位置



## 1. 冒泡





## 2. 选择

> 首先，找到数组中最小的那个元素
>
> 其次，将它与数组的第一个元素交换位置（若第一个就最小，则和自己交换）
>
> 再次，在剩下的元素中找到最小的元素，与数组的第二个元素（即剩下数组的第一个元素）交换
>
> 如此反复，直到将整个数组排序。
>
> ***因为不断在选择余下数组的最小者，所以称为选择排序。***



```c++
#include<iostream>
#include<vector>

void selectionSort(vector<int> &nums)
{
    //外循环：进行n-1次最小元素的选择就可以完成排序
    for(int i = 0; i < nums.size()-1; i++)  
    {
        int minIndex = i;    //将最小元素暂定为当前“未排序”数组的第一个元素
        for(int j = i + 1; j <  nums.size(); j++)//内层循环用来找当前“未排序”数组的最小元素的位置
        {
            if(nums[j] < nums[minIndex])  
                minIndex = j;
        }
        swap(nums[i],nums[minIndex]); //将在当前“未排序”数组找到的最小元素换至第一个位置
    }
}
```



## 3. 插入

> 可以将这种排序看作手上乱序的扑克牌，首位元素可以被看作是有序的序列，后续元素依次插入有序序列中，这个过程中“有序序列”不断在增长，“无序序列”不断在缩减。
>
> 插入排序的优化：将内层循环的交换改为将较大的元素向右移动（这样可以使访问数组的次数减半）。
>
> 插入排序适合部分有序的数组，也适合小规模数组。

```c++
#include<iostream>
#include<vector>

void insertionSort(vector<int> &nums)
{
    //外层循环：只需要进行n-1次插入，且是从第二个元素开始
    for(int i = 1; i < nums.size(); i++)
    {
        for(int j = i;)
    }
}
```







## 4. 希尔

> 希尔排序也称“缩小增量排序”，是插入排序的一种改进版本。插入排序对大规模的乱序数组时比较慢的，因为它每次只能将数据移动一位，希尔排序为了加快插入，让数据移动的时候可以跳跃移动，从而节省了一部分时间消耗。





## 5. 归并

> 归并排序的核心思想是***分治***。不断地***“切”***数组，最后再***“重组”***。





## 6. 快排

>归并排序的核心思想也是***分治***。





## 7. 堆

> 利用堆数据结构来进行排序





## 8. 计数

> 一种不基于比较的排序算法





## 9. 桶





## 10. 基数

> 非比较型的整数排序算法。其原理是按位切割成不同数字，然后按位比较。例如：对100万个手机号进行排序，归并、快排时间复杂度都是`O(nlogn)`，计数和桶排序需要的内存太多。这种情况下，基数排序就是最好的选择。



## 参考资料

https://www.cxyxiaowu.com/725.html

https://xoax.net/sub_comp_sci/

https://xoax.net/sub_comp_sci/crs_algo/