#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include<iostream>

template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree &rhs);
    BinarySearchTree(BinarySearchTree &&rhs);
    ~BinarySearchTree();

    const Comparable &findMin() const;
    const Comparable &findMax() const;
    bool contains(const Comparable &x) const
    {
        return contains(x, root);
    }

    bool isEmpty() const;
    void printTree(std::ostream &out = std::cout) const;

    void makeEmpty();
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

private:
    typedef struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Comparable &theElement, BinaryNode *pleft, BinaryNode *pRight)
            : element{theElement}, left{pleft}, right{pRight}
        {
        }

        BinaryNode(Comparable &&theElement, BinaryNode *pleft, BinaryNode *pRight)
            : element{theElement}, left{pleft}, right{pRight}
        {
        }
    } BinaryNode;

    BinaryNode *root;

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
    BinaryNode *clone(BinaryNode *t) const;
};

#endif