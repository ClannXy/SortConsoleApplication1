// SortDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
#include <queue>

void bubble_sort(int a[], int l) 
{
    int i, j, temp;
    for (i = 0; i < l - 1; i++) 
        for (j = 0; j < l - 1 - i; j++)
            if (a[j] > a[j + 1]) 
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

}

void selection_sort(int a[], int l) 
{
    int i, j, temp, min;
    for (i = 0; i < l - 1; i++)
    {
        min = i;
        for (j = i + 1; j < l; j++)
            if (a[j] < a[min]) min = j;
        if (min!=i)
        {
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}

void insertion_sort(int a[], int l) 
{
    int i, j, temp;
    for (i = 1; i < l; i++)
    {
        temp = a[i];
        for (j = i; j > 0 && a[j - 1] > temp; j--)
            a[j] = a[j - 1];
        a[j] = temp;
    }
}

void quick_sort(int a[], int low, int high) 
{
    if (low >= high) return;
    int i, j, k;
    i = low; j = high; k = a[i];
    while (i<j)
    {
        while (i < j && a[j] >= k)j--;
        a[i] = a[j];
        while (i < j && a[i] < k)i++;
        a[j] = a[i];
    }
    a[i] = k;
    quick_sort(a, low, i - 1);
    quick_sort(a, i + 1, high);
}

int _partition(int a[], int low, int high)
{
    if (low >= high) return -1;
    int i, j, k;
    i = low; j = high; k = a[i];
    while (i < j)
    {
        while (i < j && a[j] >= k)j--;
        a[i] = a[j];
        while (i < j && a[i] < k)i++;
        a[j] = a[i];
    }
    a[i] = k;
    return i;
}

void un_quick_sort(int a[], int low, int high)
{
    if (low >= high) return;
    std::stack<int> stk;
    int i = low, j = high, k = a[i], m = 0;
    stk.push(j);
    stk.push(i);
    while (!stk.empty())
    {
        int i = stk.top();
        stk.pop();
        int j = stk.top();
        stk.pop();

        m = _partition(a, i, j);

        if (i<m-1) 
        {
            stk.push(m - 1);
            stk.push(i);
        }
        if (j > m + 1) 
        {
            stk.push(j);
            stk.push(m + 1);
        }

    }
    
}




void print(int a[],int l) 
{
    int i = 0;
    for (i = 0; i < l; i++) 
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n \tprint array[int]\t \n" << std::endl;
    
}


int main()
{
    int arr[] = { 5,4,2,1,3 };
    print(arr, 5);
    un_quick_sort(arr, 0, 4);
    print(arr, 5);

}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
