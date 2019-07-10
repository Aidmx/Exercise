#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

#include<iostream>

template <typename Comparable>
class AvlTree
{
public:
    AvlTree() : root{nullptr}
    {
    }

    AvlTree(const AvlTree &rhs) :root{nullptr}
    {
        root = clone(rhs.root);
    }

    AvlTree(AvlTree &&rhs);
    ~AvlTree();

    const Comparable &findMin() const;
    const Comparable &findMax() const;
    bool contains(const Comparable &x) const
    {
        return contains(x, root);
    }

    bool isEmpty() const;
    void printTree(std::ostream &out = std::cout) const;

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

    AvlTree &operator=(const AvlTree &rhs);
    AvlTree &operator=(AvlTree &&rhs);

private:
static const int ALLOW_IMBALANCE = 1;
    typedef struct AvlNode
    {
        Comparable element;
        AvlNode *left;
        AvlNode *right;
        int height;

        AvlNode(const Comparable &theElement, AvlNode *pleft, AvlNode *pRight, int pHeight = 0)
            : element{theElement}, left{pleft}, right{pRight},height(pHeight)
        {
        }

        AvlNode(Comparable &&theElement, AvlNode *pleft, AvlNode *pRight, int pHeight = 0)
            : element{std::move(theElement)}, left{pleft}, right{pRight},height(pHeight)
        {
        }

    } AvlNode;

    AvlNode *root;

    void insert(const Comparable &x, AvlNode *&t)
    {
        if (t == nullptr)
        {
            t = new AvlNode{x, nullptr, nullptr};
        }else if(x < t->element)
        {
            insert(x, t->left);
        }else if(x > t->element)
        {
            insert(x, t->right);
        }
        balance(t);
        //相同则什么都不做 
    }
    void insert(Comparable &&x, AvlNode *&t)
    {
        if (t == nullptr)
        {
            t = new AvlNode{x, nullptr, nullptr};
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
        balance(t);
    }

    void remove(const Comparable &x, AvlNode *&t)
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
            AvlNode *min = findMin(t->right);
            if (min != nullptr)
            {
                t->element = min->element;
                remove(t->element, t->right);
            }
        }
        else
        {
            AvlNode *old = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete old;
        }

        balance(t);
    }

    AvlNode *findMin(AvlNode *t) const
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
    AvlNode *findMax(AvlNode *t) const
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

    bool contains(const Comparable &x, AvlNode *&t)
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

    AvlNode *clone(AvlNode *t) const
    {
        if (t != nullptr)
        {
            return new AvlNode(t->element, clone(t->left), clone(t->right));
        }
        else
        {
            return nullptr;
        }
    }

    void makeEmpty(AvlNode* t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
            t = nullptr;
        }
    }

    void height(AvlNode* t) const
    {
          return (t == nullptr ) ? -1 : t->height;
    }

    void rotateWithRightChild(AvlNode*& k2)
    {
        AvlNode* k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->height = max(height(k2->left), height(k2->right)) +1;
        k1->height = max(height(k1->right), k2->height) +1;
        k2 = k1;
    }

    void rotateWithLeftChild(AvlNode*& k2)
    {
        AvlNode* k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) +1;
        k1->height = max(height(k1->left), k2->height) +1;
        k2 = k1;
    }
    void doubleWithLeftChild(AvlNode *&k3)
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }
    void doubleWithRightChild(AvlNode *&k3)
    {
        rotateWithLeftChild(k3->left);
        rotateWithRightChild(k3);
    }


    void balance(AvlNode* t)
    {
        if (t == nullptr)
        {
            return;
        }

        if ((height(t->left)-height(t->right)) > ALLOW_IMBALANCE)
        {
            if (height(t->left->left) >= height(t->left->right))
            {
                //左单旋
                rotateWithLeftChild(t);
            }
            else
            {
                //左双旋
                doubleWithLeftChild(t);
            }
        }
        else
        {
            if (height(t->right->right) >= height(t->right->left))
            {
                //右单旋 
                rotateWithRightChild(t);
            }else
            {
                //右双旋 
                doubleWithRightChild(t);
            }
        }
        t->height = max(height(t->left), height(t->right)) + 1;
    }

    //4_22
    

};

#endif