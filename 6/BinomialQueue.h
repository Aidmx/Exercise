
/*   */
#ifndef _BINOMIAL_QUEUE_H_
#define _BINOMIAL_QUEUE_H_

#include <vector>
#include <iostream>
template<typename Comparable>
class BinomialQueue
{
public:
    BinomialQueue()
    {
        currentSize = DEFAULT_TREES;
    }
    explicit BinomialQueue(const Comparable &item)
    {
        
    }
    explicit BinomialQueue(Comparable &&rhs)
    {
        merge(rhs);
    }

    ~BinomialQueue()
    {
        makeEmpty();
    }

    BinomialQueue &operator=(const BinomialQueue &rhs)
    {
        currentSize = rhs.currentSize;
        if (currentSize > capacity())
        {
            //扩容 this 二项队列
            int oldTrees = theTrees.size();
            int newTress = currentSize + 1;
            theTrees.resize(newTress);
        }
        //copy
        for (int i = 0; i < rhs.theTrees.size(); i++) 
        {
            theTrees[i] = clone(rhs.theTrees[i]);
        } 
    }

    BinomialQueue &operator=(BinomialQueue &&rhs)
    {
        currentSize = rhs.currentSize;
        if (currentSize > capacity())
        {
            //扩容 this 二项队列
            int oldTrees = theTrees.size();
            int newTress = currentSize + 1;
            theTrees.resize(newTress);
        }
        //copy
        for (int i = 0; i < rhs.theTrees.size(); i++) 
        {
            theTrees[i] = clone(rhs.theTrees[i]);
        } 
    }


    bool isEmpty() const{ return currentSize == 0;}
    const Comparable &findMin() const
    {
        int min = findMinIndex();
        return theTrees[min];
    }
    void insert(const Comparable &rhs);
    void insert(Comparable&& minltem);
    
    void deleteMin();
    void deleteMin(Comparable & minltem)
    {
        if (isEmpty())
        {
            std::cout<<"null"<<std::endl;
           return;
        }
        int minIndex = findMinIndex();
        minltem = theTrees[minIndex]->element;
        BinomialNode *oldRoot = theTrees[minIndex];
        BinomialNode *deletedTree = oldRoot->leftChild;
        delete oldRoot;
        oldRoot = theTrees[minIndex] = nullptr;

        //构建H''
        BinomialQueue deletedQueue;
        deletedQueue.theTrees.resize(minIndex + 1);
        deletedQueue.currentSize = (1 << minIndex) -1;
        for (int j = minIndex -1 ; j >= 0; --j)
        {
            deletedQueue.theTrees[j] = deletedTree;
            deletedTree = deletedTree->nextSibling;
        }
        
        //构建H'
        currentSize -= deletedQueue.currentSize + 1;
        merge(deletedQueue);
    }

    void makeEmpty()
    {
        for (int i = 0; i < theTrees.size(); i++)
        {
           makeEmpty(theTrees[i]);
        }
        currentSize = DEFAULT_TREES;
    }
    void merge(BinomialQueue &rhs)
    {
        if (this == &rhs)
        {
            return;
        }
        //计算两个二项队列的总高度
        currentSize +=rhs.currentSize;
        if (currentSize > capacity())
        {
            //扩容 this 二项队列
            int oldTrees = theTrees.size();
            int newTress = std::max(theTrees.size(), rhs.theTrees.size() ) + 1;
            theTrees.resize(newTress);
            for (int i = oldTrees; i < newTress; i++)
            {
                theTrees[i] = nullptr;
            }
        }
        BinomialNode* carry = nullptr;  //上一步合并得来的树
        for (int i = 0, j = 1; i < currentSize; i++, j*=2)
        {
            //i 高度下的树 h1 h2
            BinomialNode* t1 = theTrees[i]; 
            BinomialNode* t2 = i < rhs.theTrees.size() ? rhs.theTrees[i]: nullptr;
            int whichCase = t1 == nullptr ? 0 : 1;
            whichCase += t2 == nullptr ? 0 : 2;
            whichCase += carry == nullptr ? 0 : 4;
            switch (whichCase)
            {
            case 0: /* 空树 */
            case 1: /* 只有this的情形 */
                break;
            case 2: /* 只有rhs的情形 */
                theTrees[i] = t2;
                rhs.theTrees[i] = nullptr;
                break;
            case 4: /* 只有carry的情形 */
                theTrees[i] = carry;
                carry = nullptr;
                break;
            case 3: /* 只有carry的情形 */
                carry = combineTrees(t1, t2);
                theTrees[i] = rhs.theTrees[i] = nullptr;
                break;
            case 5: /* this carry*/
                carry = combineTrees(t1, carry);
                rhs.theTrees[i] = nullptr;
                break;
            case 6: /* rhs carry */
                carry = combineTrees(t2, carry);
                rhs.theTrees[i] = nullptr;
                break;
            case 7: /* all tree*/
                theTrees[i] = carry;
                carry = combineTrees(t1, t2);
                rhs.theTrees[i] = nullptr;
                break;
            default:
                break;
            }
        }
        //销毁 rhs
        for (auto& root : rhs.theTrees)
        {
            root = nullptr;
        }
        rhs.currentSize = 0;
    }

private:
    struct BinomialNode
    {
        Comparable element;
        BinomialNode* leftChild;
        BinomialNode* nextSibling;

        BinomialNode(const Comparable& e, BinomialNode* lt, BinomialNode* rt)
        : element{e},leftChild{lt},nextSibling{rt}
        {

        }

        BinomialNode(Comparable&& e, BinomialNode* lt, BinomialNode* rt)
        : element{std::move(e)},leftChild{lt},nextSibling{rt}
        {

        }
    };


        int findMinIndex() const
        {
            int i = 0;
            int miniIdnex = 0;
            while (theTrees[i] == nullptr)
            {
                i++;
            }
            for (miniIdnex = 1; i < theTrees.size(); i++)
            {
                if ((theTrees[i] != nullptr) && (theTrees[i]->element < theTrees[miniIdnex]->element))
                {
                    miniIdnex = i;
                }
            }
            return miniIdnex;
        }

        int capacity() const{ return theTrees.size();}
        
        BinomialNode* combineTrees(BinomialNode* t1, BinomialNode* t2)
        {
            if (t2->element < t1->element)
            {
                return combineTrees(t2, t1);
            }
            t2->nextSibling = t1->leftChild;
            t1->leftChild = t2;
            return t1;
        }
        void makeEmpty(BinomialNode*& t)
        {
            //遍历树
            if (t == nullptr)
            {
                return;
            }
            
            //清空
            makeEmpty(t->leftChild);
            makeEmpty(t->nextSibling);
            delete t;
            t = nullptr;
        }

        BinomialNode* clone(BinomialNode* t) const
        {
            if (t == nullptr)
            {
               return nullptr;
            }
            
            BinomialNode *newNode = new BinomialNode(t->element ,clone(t->leftChild), clone(t->nextSibling)); 
            return newNode;
        }

        const static int DEFAULT_TREES = 1;
        std::vector<BinomialNode*> theTrees;
        int currentSize; //二项队列总的项数

};  

#endif