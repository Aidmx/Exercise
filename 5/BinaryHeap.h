
/* 堆序性质: 结构性和堆序性 */
#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_

#include <vector>
#include <iostream>

static int time;
class BinaryHeap
{
public:
    /* data */
    explicit BinaryHeap(int capacity = 100)
        : array(capacity),
          currentSize{0}
    {
    }
    explicit BinaryHeap(const std::vector<int>& items)
            :array(items.size() + 10),
            currentSize{(int)(items.size())}
    {
        for (int i = 0; i < items.size(); i++)
        {
            array[i + 1] = items[i];
        }
        buildHeap();
    }

    ~BinaryHeap()
    {

    }

    bool isEmpty() const {return currentSize <= 0;}
    const int& findMin() const;

    /*
    * 将项x插入，允许重复元  上滤
    */
    void insert(const int& x)
    {
        if (currentSize == (array.size() -1 ))
        {
            array.resize(array.size() * 2);
        }

        int hole = ++currentSize;
        int copy = x;
        array[0] = std::move(copy);
        for (; x < array[hole/2 ]; hole /= 2)
        {
            array[hole] = std::move(array[hole / 2]);
        }
        array[hole] = std::move(array[0]);
    }
    
    /*
    * 将项x插入，允许重复元  上滤
    */
    void insert1(const int& x)
    {
        if (currentSize == (array.size() - 1))
        {
            array.resize(array.size() * 2);
        }

        int hole = ++currentSize; 
        array[hole] = x;
        percolateUp(hole);
    }

    void deleteMin()
    {
        if (isEmpty())
        {
           return;
        }
        array[1] = std::move(array[currentSize--]);
        percolateDown(1);
    }

    void deleteMin(int& minItem)
    {
        if (isEmpty())
        {
           return;
        }
        minItem = std::move(array[1]);
        array[1] = std::move(array[currentSize--]);
        percolateDown(1);
    }
    void makeEmpty()
    {

    }

    //6_10 a   
    void preorder(const int& x )
    {
        time = 0;
        preorder(x , 1); 
    }

    void preorder(const int& x, int hole)
    {
        if (hole > currentSize)
        {
            return;
        }

        if (array[hole] < x)
        {
            std::cout << array[hole]<<" ,time = "<<++time<<std::endl;
          
            preorder(x, hole*2);
            preorder(x, hole*2 + 1);
        }
    } 
    //6_10 a  
private:
    int currentSize;
    std::vector<int> array;
    void buildHeap()
    {
        for (int i = currentSize / 2 ; i > 0; i--)
        {
            percolateDown(i);
        }
    }
    void percolateDown(int hole)
    {
        int child; 
        int tmp = std::move(array[hole]);
        for (; hole * 2 <= currentSize ; hole = child)
        {
            child = hole * 2;
            if (child != currentSize && array[child + 1] < array[child])
            {
                ++child;
            }
            if (array[child] < tmp)
            {
                array[hole] = std::move(array[child]);
            }
            else
            {
                break;
            }
        }
        array[hole] = std::move(tmp);
    }

    
    void percolateUp(int hole)
    {
        for (; hole  > 1; hole/=2)
        {
            //如果array[hole]比父节点的优先级大，将其上浮
            if (array[hole] < array[hole / 2])
            {
                std::swap(array[hole] ,array[hole / 2]);
            }
        } 
    }
  
};   

#endif