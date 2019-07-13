

#ifndef _4_30_H_
#define _4_30_H_

#include <iostream>
using namespace std;

class SplayTreeNode
{
public:
    SplayTreeNode *left;
    SplayTreeNode *right;
    SplayTreeNode *parent;
    int key;
    SplayTreeNode(int key)
    {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};

class SplayTree
{
private:
    SplayTreeNode *root;
    int splay_time;
    void LeftRotate(SplayTreeNode *);
    void RightRotate(SplayTreeNode *);
    void Splay(SplayTreeNode *);
    void PreOrderSTPrint(SplayTreeNode *);
    void InOrderSTPrint(SplayTreeNode *);
    void RotateSTPrint(SplayTreeNode *, int);
    void PostOrderSTPrint(SplayTreeNode *);
    void DeleteNoOrOneChildSTNode(SplayTreeNode *, SplayTreeNode *);
    void makeEmpty(SplayTreeNode *t);

public:
    SplayTree();
    ~SplayTree();
    void InsertSplayTree(int);
    int SplayTimes() const {return splay_time;}
    bool DeleteSplayTree(int);
    bool UpdateSplayTree(int, int);
    SplayTreeNode *FindSplayTree(int);
    void PreOrderSTPrint();
    void InOrderSTPrint();
    void RotateSTPrint();
    void PostOrderSTPrint();
};

SplayTree::SplayTree() : splay_time{0}
{
    this->root = nullptr;
}
SplayTree::~SplayTree()
{
   makeEmpty(root);
}

void SplayTree::makeEmpty(SplayTreeNode *pSTNode)
{
    if (pSTNode != nullptr)
    {
        makeEmpty(pSTNode->left);
        makeEmpty(pSTNode->right);
        delete pSTNode;
        pSTNode = nullptr;
    }
}

/**************************************************************
*参数：待左旋的节点
*返回值：空
*功能：左旋
***************************************************************/
void SplayTree::LeftRotate(SplayTreeNode *pSTNode)
{
    SplayTreeNode *rChild = pSTNode->right;
    if (NULL != pSTNode->parent) //不为根节点
    {
        if (pSTNode->parent->left == pSTNode)
            pSTNode->parent->left = rChild;
        else
            pSTNode->parent->right = rChild;
    }
    rChild->parent = pSTNode->parent;
    pSTNode->parent = rChild;
    if (rChild->left != NULL)
        rChild->left->parent = pSTNode;
    pSTNode->right = rChild->left;
    rChild->left = pSTNode;
    if (NULL == rChild->parent)
        this->root = rChild;
}

/**************************************************************
*参数：待右旋的节点
*返回值：空
*功能：右旋
***************************************************************/
void SplayTree::RightRotate(SplayTreeNode *pSTNode)
{
    SplayTreeNode *lChild = pSTNode->left;
    if (NULL != pSTNode->parent) //不为根节点
    {
        if (pSTNode->parent->right == pSTNode)
            pSTNode->parent->right = lChild;
        else
            pSTNode->parent->left = lChild;
    }
    lChild->parent = pSTNode->parent;
    pSTNode->parent = lChild;
    if (lChild->right != NULL)
        lChild->right->parent = pSTNode;
    pSTNode->left = lChild->right;
    lChild->right = pSTNode;
    if (NULL == lChild->parent)
        this->root = lChild;
}

/**************************************************************
*参数：待伸展的节点
*返回值：空
*功能：将当前节点伸展的根节点
***************************************************************/
void SplayTree::Splay(SplayTreeNode *pSTNode)
{
    while (NULL != pSTNode && NULL != pSTNode->parent)
    {
        if (pSTNode->parent->left == pSTNode) //父亲节点右旋
        {
            RightRotate(pSTNode->parent);
        }
        else
        {
            LeftRotate(pSTNode->parent);
        }
        splay_time++;
    }
}

/**************************************************************
*参数：带插入元素
*返回值：空
*功能：将当前元素插入伸展树
***************************************************************/
void SplayTree::InsertSplayTree(int pKey)
{
    SplayTreeNode *pre = NULL, *cur = this->root;
    while (cur != NULL)
    {
        pre = cur;
        if (cur->key > pKey) //tempKey插到左子树
            cur = cur->left;
        else
            cur = cur->right; //插到左子树
    }
    SplayTreeNode *pSTNode = new SplayTreeNode(pKey);
    pSTNode->parent = pre;
    if (pre == NULL) //若插入的为根节点
    {
        this->root = pSTNode;
    }
    else if (pre->key > pSTNode->key)
        pre->left = pSTNode;
    else
        pre->right = pSTNode;
    Splay(pSTNode);
}

/**************************************************************
*参数：带查找元素
*返回值：返回查找元素在伸展树中的位置
*功能：查找当前元素是否在伸展树
***************************************************************/
SplayTreeNode *SplayTree::FindSplayTree(int pKey)
{
    SplayTreeNode *cur = this->root;
    while (cur != NULL)
    {
        if (cur->key == pKey)
            break;
        else if (cur->key > pKey)
            cur = cur->left;
        else
            cur = cur->right;
    }
    Splay(cur);
    return cur;
}

/**********************************************************
*参数：pre待删除节点的父节点，cur待删除节点
*返回值：空
*功能：删除左右孩子有为空的情况
************************************************************/
void SplayTree::DeleteNoOrOneChildSTNode(SplayTreeNode *pre, SplayTreeNode *cur)
{
    if (NULL == cur->left && NULL == cur->right) //左右孩子为空
    {
        if (NULL == pre)
            this->root = NULL;
        else if (pre->left == cur)
            pre->left = NULL;
        else
            pre->right = NULL;
        delete cur;
    }
    else if (cur->right != NULL) //若右子树不为空
    {
        if (NULL == pre)
        {
            this->root = cur->right;
            cur->right->parent = NULL;
        }
        else if (pre->left == cur)
        {
            pre->left = cur->right;
            cur->right->parent = pre;
        }
        else
        {
            pre->right = cur->right;
            cur->right->parent = pre;
        }
        delete cur;
    }
    else if (cur->left != NULL) //若左子树不为空
    {
        if (NULL == pre)
        {
            this->root = cur->left;
            cur->left->parent = NULL;
        }
        else if (pre->left == cur)
        {
            pre->left = cur->left;
            cur->left->parent = pre;
        }
        else
        {
            pre->right = cur->left;
            cur->left->parent = pre;
        }
        delete cur;
    }
}

/**********************************************************
*参数：待删除节点元素
*返回值：空
*功能：删除元素主函数
************************************************************/
bool SplayTree::DeleteSplayTree(int pKey)
{
    SplayTreeNode *pre = NULL, *cur = root;
    while (cur != NULL) //寻找待删除元素
    {
        if (cur->key == pKey)
            break;
        else
        {
            pre = cur;
            if (cur->key > pKey)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }
    if (NULL == cur)
        return false;
    if (NULL == cur->left || NULL == cur->right)
    {
        DeleteNoOrOneChildSTNode(pre, cur);
        Splay(pre);
    }
    else //左右子树都不为空
    {
        SplayTreeNode *rPre = cur, *rCur = cur->right; //找到右子树最小元素
        while (rCur->left != NULL)
        {
            rPre = rCur;
            rCur = rCur->left;
        }
        cur->key = rCur->key;
        DeleteNoOrOneChildSTNode(rPre, rCur);
        Splay(rPre);
    }
    return true;
}

/**********************************************************
*参数：待修改节点元素、修改后的元素
*返回值：返回修改是否成功
*功能：修改函数
************************************************************/
bool SplayTree::UpdateSplayTree(int oldKey, int newKey)
{
    if (DeleteSplayTree(oldKey))
    {
        InsertSplayTree(newKey);
        return true;
    }
    return false;
}

/**********************************************************
*参数：当前子树根节点
*返回值：空
*功能：前序遍历二叉查找树
************************************************************/
void SplayTree::PreOrderSTPrint(SplayTreeNode *pSTNode)
{
    if (NULL == pSTNode)
        return;
    cout << pSTNode->key << "    ";
    PreOrderSTPrint(pSTNode->left);
    PreOrderSTPrint(pSTNode->right);
}
void SplayTree::PreOrderSTPrint()
{
    PreOrderSTPrint(this->root);
}

/**********************************************************
*参数：当前子树根节点
*返回值：空
*功能：中序遍历二叉查找树
************************************************************/
void SplayTree::InOrderSTPrint(SplayTreeNode *pSTNode)
{
    if (NULL == pSTNode)
        return;
    InOrderSTPrint(pSTNode->left);
    cout << pSTNode->key << "   ";
    InOrderSTPrint(pSTNode->right);
}
void SplayTree::InOrderSTPrint()
{
    InOrderSTPrint(this->root);
}

/**********************************************************
*参数：当前子树根节点
*返回值：空
*功能：后序遍历二叉查找树树
************************************************************/
void SplayTree::PostOrderSTPrint(SplayTreeNode *pSTNode)
{
    if (NULL == pSTNode)
        return;
    PostOrderSTPrint(pSTNode->left);
    PostOrderSTPrint(pSTNode->right);
    cout << pSTNode->key << "    ";
}
void SplayTree::PostOrderSTPrint()
{
    PostOrderSTPrint(this->root);
}

/**********************************************************
*参数：当前子树根节点，缩进列数
*返回值：空
*功能：翻转打印伸展树
************************************************************/
void SplayTree::RotateSTPrint(SplayTreeNode *pSTNode, int pColumn)
{
    if (NULL == pSTNode)
        return;
    RotateSTPrint(pSTNode->left, pColumn + 1);
    for (int i = 0; i < pColumn; i++)
        cout << "    ";
    cout << "---" << pSTNode->key << endl;
    RotateSTPrint(pSTNode->right, pColumn + 1);
}
void SplayTree::RotateSTPrint()
{
    RotateSTPrint(this->root, 0);
}

void Menu()
{
    int val, choice, newVal;
    SplayTree mySplayTree;
    while (true)
    {
        do
        {
            cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
            cout << "       1.insert" << endl;
            cout << "       2.del" << endl;
            cout << "       3.change" << endl;
            cout << "       4.find" << endl;
            cout << "       5.show" << endl;
            cout << "       6.back" << endl;
            cout << "input ur option[ ]\b\b";
            cin >> choice;
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);
        if (1 == choice)
        {
            cin >> val;
            mySplayTree.InsertSplayTree(val);
        }
        else if (2 == choice)
        {
            cin >> val;
            if (mySplayTree.DeleteSplayTree(val))
                cout << "success!" << endl;
            else
                cout << "failed!" << endl;
        }
        else if (3 == choice)
        {
            cin >> val >> newVal;
            if (mySplayTree.UpdateSplayTree(val, newVal))
                cout << "success!" << endl;
            else
                cout << "failed!" << endl;
        }
        else if (4 == choice)
        {
            cin >> val;
            if (NULL != mySplayTree.FindSplayTree(val))
                cout << "find success!" << endl;
            else
                cout << "find failed!" << endl;
        }
        else if (5 == choice)
        {
            cout << endl
                 << "*****************************" << endl;
            cout << endl
                 << "==========pre order==============" << endl;
            mySplayTree.PreOrderSTPrint();
            cout << endl
                 << "==========In order================" << endl;
            mySplayTree.InOrderSTPrint();
            cout << endl
                 << "==========Post order===============" << endl;
            mySplayTree.PostOrderSTPrint();
            cout << endl
                 << "==========duichen+rotate===============" << endl;
            mySplayTree.RotateSTPrint();
            cout << endl
                 << "*****************************" << endl;
        }
        else
            return;
    }
}

#endif