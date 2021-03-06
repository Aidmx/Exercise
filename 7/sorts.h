#ifndef _INSERTIOM_SORT_H_
#define _INSERTIOM_SORT_H_

#include<iostream>
#include<vector>

//插入
template<typename Comparable>
void insertionSort(std::vector<Comparable> a)
{
    for (int p = 0; p < a.size(); p++)
    {
        Comparable tmp = std::move(a[p]);
        int j = p;
        for (; j > 0 && tmp< a[j - 1]; --j)
        {
            a[j] = std::move(a[j -1]);
        }
        a[j] = std::move(tmp);
    }
    
}


template<typename Iterator, typename Comparator>
void insertionSort(const Iterator& begin, const Iterator& end, Comparator lessThan)
{
    if (begin == end)
    {
        return;
    }
    Iterator j;
    for (Iterator p = begin +1; p != end; p++)
    {
        auto tmp = std::move(*p);
        for (j = p; j!=begin &&lessThan(tmp, *(j -1)); --j)
        {
            *j = std::move(*(j -1));
        }
        *j = std::move(tmp);
    }
}

template<typename Iterator>
void insertionSort(const Iterator& begin, const Iterator& end)
{
    insertionSort(begin, end, less<decltype(*begin)>{});
}

//shell
template<typename Comparable>
void shellsort(std::vector<Comparable> a)
{
    for (int gap = a.size() /2; gap > 0; gap /= 2 )
    {
        for (int i = gap; i < a.size(); i++)
        {
            Comparable tmp = std::move(a[i]);
            int j = i;
            
            for (; j >= gap && tmp < a[j - gap]; j-=gap)
            {
                a[j] = std::move(a[j - gap]);
            }
            a[j] = std::move(tmp);
        }
        
    }
    
}

//heap sort

int leftChild(int i)
{
    return 2*i+1;
}

template<typename Comparable>
void percDown(std::vector<Comparable> a, int i, int n)
{
    int child;
    Comparable tmp;
    for (tmp = std::move(a[i]); leftChild(i) < n; i = child)
    {
        child = leftChild(i);
        if ((child != n -1 )&&(a[child] < a[child +1]))
        {
            ++child;
        }
        if (tmp < a[child])
        {
            a[i] = std::move(a[child]);
        }else
        {
            break;
        }
        a[i] = std::move(tmp);
    }
    
}

template<typename Comparable>
void heapsort(std::vector<Comparable>& a)
{
    for (int i = a.size()/2 - 1; i >= 0; i++)
    {
        percDown(a, i , a.size());
    }
    for (int j = a.size() - 1; j > 0; --j)
    {
        std::move(a[0], a[j]);
        percDown(a, 0 , j);
    }
    
}

//4_14
template<typename Comparable>
void heapsort(std::vector<Comparable>& a, int low, int high)
{
    for (int i = high/2 - 1; i >= low; i++)
    {
        percDown(a, i , high - low);
    }
    for (int j = high; j > low; --j)
    {
        std::move(a[low], a[j]);
        percDown(a, low , j);
    } 
}



//归并
template<typename Comparable>
void mergesort(std::vector<Comparable>& a,std::vector<Comparable>& tmp, int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos -1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftEnd + 1;
    while (leftPos <= leftEnd && rightPos <= rightEnd)
    {
        if (a[leftPos] <= a[rightPos])
        {
            tmp[tmpPos++] = std::move(a[leftPos++]);
        }
        else
        {
            tm[tmpPos++] = std::move(a[rightPos++]);
        }
    }

    while (leftPos <= leftEnd)
    {
        tmp[tmpPos++] = std::move(a[leftPos++]);
    }

    while (rightPos <= rightEnd)
    {
        tmp[tmpPos++] = std::move(a[rightPos++]);
    }
    for (int i = 0; i < numElements; i++, --rightEnd)
    {
        a[rightEnd] = std::move(tmp[rightEnd]);
    }
    
}

template<typename Comparable>
void mergesort(std::vector<Comparable>& a,std::vector<Comparable>& tmp, int left, int right)
{ 
    if (left < right)
    {
        int center = (left +right) / 2;
        mergesort(a, tmp, left , center);
        mergesort(a, tmp, center + 1 ,right);
        mergesort(a, tmp,left, center + 1 ,right);
    }
    
}

template<typename Comparable>
void mergesort(std::vector<Comparable>& a)
{
    std::vector<Comparable>& tmp(a.size());
    mergesort(a, tmp, 0 ,a.size() - 1);
}


//快排
//递归
template<typename Comparable>
void easyquicksort(std::vector<Comparable>& a)
{
    std::vector<Comparable> smaller;
    std::vector<Comparable> same;
    std::vector<Comparable> larger;

    auto chosenItem = items[item.size() / 2];
    for (auto& i : items)
    {
        if (i < chosenItem)
        {
           smaller.push_back(i);
        }else if(chosenItem < i)
        {
           larger.push_back(i);
        }else
        {
            same.push_back(i);
        }
        
        easyquicksort(smaller);
        easyquicksort(larger);
        
        std::move(begin(smaller), end(smaller), begin(items));
        std::move(begin(same), end(same), begin(items) + smaller.size());
        std::move(begin(larger), end(larger), end(items) - larger.size());
    }  
}



template <typename Comparable>
const Comparable& median3(std::vector<Comparable>& a, int left, int right)
{
    int center = (left +right) / 2;
    if (a[center] < a [left])
    {
        std::swap(a[left], a[center]);
    }
       if (a[right] < a [left])
    {
        std::swap(a[left], a[right]);
    }
       if (a[right] < a [center])
    {
        std::swap(a[right], a[center]);
    }
    
    std::swap(a[center], a[right -1]);
    return a[right -1];
}


template <typename Comparable>
void quickselect(std::vector<Comparable> &a, int left, int right, int k)
{
    if (left + 10 <= right )
    {
        const Comparable &pivot = median3(a, left, right);
        //分割
        int i = left, j = right - 1;
        while (true)
        {
            while (a[++i] < pivot){}
            while (pivot < a[--j]){}

            if (i < j)
            {
                std::swap(a[i], a[--j]);
            }
            else
            {
                break;
            }

            std::swap(a[i], a[right - 1]);

            if (k <= i)
            {
                quickselect(a, left, i - 1, k);
            }
            else
            {
                quickselect(a, i + 1, right, k);
            }
        }
    }else
    {
        insertionSort(a, left ,right);
    }
}


template <typename Comparable>
void quicksort(std::vector<Comparable>& a, int left, int right)
{

    if (left + 10 <= right )
    {
        const Comparable& pivot = median3(a, left, right);
        //分割
        int i =left, j = right -1;
        while (true)
        {
            while (a[++i] < pivot){}
            while (pivot < a[--j]){}

            if (i < j)
            {
                std::swap(a[i], a[--j]);
            }
            else
            {
                break;
            }

            std::swap(a[i], a[right - 1]);

            quicksort(a, left, i - 1);
            quicksort(a, i + 1, right);         
        }
    }else
    {
        insertionSort(a, left ,right);
    }
}



template <typename Comparable>
void quicksort(std::vector<Comparable> &a)
{
    quicksort(a, 0, a, size() - 1);
}

#endif
