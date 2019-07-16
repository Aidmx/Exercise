#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <iostream>
#include <random>
#include <queue>
 

template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree() : root{nullptr}
    {
    }

    BinarySearchTree(const BinarySearchTree &rhs) :root{nullptr}
    {
        root = clone(rhs.root);
    }

    BinarySearchTree(BinarySearchTree &&rhs)
    {
        root = clone(rhs.root);
    }

    ~BinarySearchTree()
    {
        makeEmpty(root);
    }

    const Comparable &findMin() const;
    const Comparable &findMax() const;
    bool contains(const Comparable &x) const
    {
        return contains(x, root);
    }

    bool isEmpty() const
    {
        return root == nullptr;
    }

    void isomorphis_insert(const Comparable &x)
    {
        isomorphis_insert(x, root);
    }

    void insert(const Comparable &x)
    {
        insert(x, root);
    }

    void insert(Comparable &&x)
    {
        insert(x, root);
    }

    void remove(const Comparable &x)
    {
        remove(x, root);
    }

    BinarySearchTree &operator=(const BinarySearchTree &rhs);
    BinarySearchTree &operator=(BinarySearchTree &&rhs);

public:
    typedef struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;
        int x;
        int y;

        BinaryNode(const Comparable &theElement, BinaryNode *pleft, BinaryNode *pRight)
            : element{theElement}, left{pleft}, right{pRight}
        {
            x = 0;
            y = 0;
        }

        BinaryNode(Comparable &&theElement, BinaryNode *pleft, BinaryNode *pRight)
            : element{std::move(theElement)}, left{pleft}, right{pRight}
        {
            x = 0;
            y = 0;
        }
    } BinaryNode;

    BinaryNode *root;

    void printNode(BinaryNode *pNode) const
    {
        if (pNode == nullptr)
        {
            return;
        }
        std::cout << pNode->element << ",(x, y)"<< pNode->x << pNode->y << std::endl;
    }
    
    //先序
    void Preorder(BinaryNode *pNode) const
    {
        if (pNode == nullptr)
        {
            return;
        }
        
        printNode(pNode);
        Preorder(pNode->left);
        Preorder(pNode->right);
    }
    //后序
    void Postorder(BinaryNode *pNode) const
    {
        if (pNode == nullptr)
        {
            return;
        }
        
        Postorder(pNode->left);
        Postorder(pNode->right);
        printNode(pNode);
    }
    //中序
    void Inorder(BinaryNode *pNode) const
    {
        if (pNode == nullptr)
        {
            return;
        }
        
        Inorder(pNode->left);
        printNode(pNode);
        Inorder(pNode->right);
    }
    //层序
    void LevelOrder(BinaryNode *pNode) const
    {
        if (pNode == nullptr)
        {
            return;
        }

        std::queue<BinaryNode*> que;
        que.push(pNode);
        BinaryNode *currentNode = nullptr;

        while (!que.empty())
        {
            currentNode = que.front();
            printNode(currentNode);
            que.pop();
            if (currentNode->left != NULL)
            {
                que.push(currentNode->left);
            }
            if (currentNode->right != NULL)
            {
                que.push(currentNode->right);
            }
        }
    }

    //4_38 
    //a  //b
    void InorderCoord(BinaryNode *pNode ,int x, int y, bool pleft)
    {
        if (pNode == nullptr)
        {
            return;
        }
        
        InorderCoord(pNode->left,x - 1,  y - 1, true);  
        if (pleft)
        {
            pNode->x = x - 1;
        }
        else
        {
            pNode->x = x + 1;
        }
        pNode->y = y - 1;
        printNode(pNode);
        InorderCoord(pNode->right, pNode->x,  pNode->y , false);
    }
    //b

    //4_38  

    Comparable randInt(Comparable lower, Comparable upper)
    {
        return (upper - lower ) / 2 + lower;
    }
 
 //4_34
    BinaryNode* makeRandomTree(Comparable lower, Comparable upper)
    {
        BinaryNode* pNode = nullptr;
        if (lower <= upper)
        {
            Comparable randomValue = randInt(lower, upper);
            pNode = new BinaryNode(randomValue,
                                   makeRandomTree(lower, randomValue - 1),
                                   makeRandomTree(randomValue + 1, upper));
        }
        return pNode;
    }
     
    void makeRandomBSTree(Comparable lower, Comparable upper)
    {
        if (upper <= lower)
        {
            return;
        }
        
        root=makeRandomTree( lower, upper); 
    }
 //4_34

    void insert(const Comparable &x, BinaryNode *&t)
    {
        if (t == nullptr)
        {
            t = new BinaryNode{x, nullptr, nullptr};
        }else if(x < t->element)
        {
            insert(x, t->left);
        }else if(x > t->element)
        {
            insert(x, t->right);
        }
        //相同则什么都不做 
    } 
    void insert(Comparable &&x, BinaryNode *&t)
    {
        if (t == nullptr)
        {
            t = new BinaryNode{x, nullptr, nullptr};
        }
        else if (x < t->element)
        {
            insert(std::move(x), t->left);
        }
        else if (x > t->element)
        {
            insert(std::move(x), t->right);
        }
        //相同则什么都不做
    }
 
    void isomorphis_insert(const Comparable &x, BinaryNode *&t)
    {
        if (t == nullptr)
        {
            t = new BinaryNode{x, nullptr, nullptr};
        }else if(x > t->element)
        {
            isomorphis_insert(x, t->left);
        }else if(x < t->element)
        {
            isomorphis_insert(x, t->right);
        }
    }

    void remove(const Comparable &x, BinaryNode *&t)
    {
        if (t == nullptr)
        {
            return;
        }
        else if (x < t->element)
        {
            remove(x, t->left);
        }
        else if (x > t->element)
        {
            remove(x, t->right);
        }
        else if ((t->left != nullptr) && (t->right != nullptr))
        {
            BinaryNode *min = findMin(t->right);
            if (min != nullptr)
            {
                t->element = min->element;
                remove(t->element, t->right);
            }
        }
        else
        {
            BinaryNode *old = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete old;
        }
    }

    BinaryNode *findMin(BinaryNode *t) const
    {
        if (t != nullptr)
        {
          while (t->left != nullptr)
          {
              t = t->left;
          }
        }
        return t;

        //递归
        // if (t == nullptr)
        // {
        //     return nullptr;
        // }
        // else if (t->left == nullptr)
        // {
        //     return t;
        // }else
        // {
        //     return findMin(t->left);
        // } 
    }
    BinaryNode *findMax(BinaryNode *t) const
    {
        if (t == nullptr)
        {
            return nullptr;
        }
        while (t->right != nullptr)
        {
             t=t->right;
        }
        return t;
    }

    bool contains(const Comparable &x, BinaryNode *&t)
    {
        if (t==nullptr)
        {
            return false;
        }
        else if (t->element < x)
        {
          return contains(t->right);
        }
        else if (t->element > x)
        {
          return contains(t->left);
        }
        else
        {
            return true;
        }
    }

    BinaryNode *clone(BinaryNode *t) const
    {
        if (t != nullptr)
        {
            return new BinaryNode(t->element, clone(t->left), clone(t->right));
        }
        else
        {
            return nullptr;
        }
    }

    void makeEmpty(BinaryNode* t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
            t = nullptr;
        }
    }

public:
    //4_46
    static bool isomorphis(BinaryNode* a, BinaryNode* b)
    {
        if ((a==nullptr) && (b==nullptr))
        {
           return true;
        }
        if ((a==nullptr) || (b==nullptr))
        {
            return false;
        }
        if (a->element != b->element)
        {
            return false;
        }

        return (isomorphis(a->left, b->left) && isomorphis(a->right, b->right)) 
            || (isomorphis(a->left, b->right) && isomorphis(a->right, b->left));
    }
    //4_46
};

#endif