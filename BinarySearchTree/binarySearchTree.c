#include "binarySearchTree.h"
#include <stdlib.h>
#include "DoubleLinkListQueue.h"
/* 状态码 */
enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 静态函数前置声明 */
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);

/* 创建结点 */
static BSTreeNode * createBSTreNewNode(ELEMENTTYPE val,BSTreeNode * parentNode);
/* 根据指定的值获取二叉搜索树的结点 */
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val);

/* 二叉搜索树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBstree,  int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
{
    int ret = 0;
    BinarySearchTree *bstree =(BinarySearchTree *) malloc(sizeof(BinarySearchTree) * 1);
    if(bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清楚脏数据 */
    memset(bstree, 0, sizeof(BinarySearchTree) * 1);
    /* 初始化树 */
    {
        bstree->root = NULL;
        bstree->size = 0;
        bstree->compareFunc = compareFunc;
    }

#if 0
    /* 分配根结点 */
    bstree->root = (BSTreeNode *) malloc(sizeof(BSTreeNode) * 1);
    if(bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清楚脏数据 */
    memset(bstree->root, 0, sizeof(BSTreeNode) * 1);
    /* 初始化根结点 */
    {
        bstree->root->data = 0;
        bstree->root->left = NULL;
        bstree->root->right = NULL;
        bstree->root->parent = NULL;
    }
#else
    bstree->root = createBSTreNewNode(0,NULL);
    if(bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }
#endif
    *pBstree = bstree;
    return ret;
}
/* 创建节点 */
static BSTreeNode * createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode * parentNode)
{
     BSTreeNode * newBstNode = (BSTreeNode*)malloc(sizeof(BSTreeNode) * 1);
     if (newBstNode == NULL)
    {
        return MALLOC_ERROR;
    }
      memset(newBstNode, 0, sizeof(BSTreeNode) * 1);
    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->parent = NULL;
        newBstNode->right = NULL;
    }
 
    /* 新节点赋值 */
    newBstNode->data = val;

     /* 给父节点赋值 */
    newBstNode->parent = parentNode;

    return newBstNode;
}
#if 0
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    #if 0
    if(val1 < val2)
    {
        return -1;
    }
    else if (val1 > val2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    #endif
    return val1 - val2;
}
#endif
/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
{
    int ret = 0;

    /* 空树 */
    if(pBstree->size == 0)
    {
        /* 更新树的结点 */
        (pBstree->size) ++;


        pBstree->root->data = val;
        return ret;

    }
    /* travelNode 指向根结点 */
    BSTreeNode * travelNode = pBstree->root;
    BSTreeNode * parentNode = pBstree->root;

    /* 确定符号： 到底放在左边还是右边 */
    int cmp = 0;
    while(travelNode != NULL)
    {
        parentNode = travelNode;
        cmp = pBstree->compareFunc(val, travelNode->data);
        /* 插入元素 < 遍历到的结点 */
        if(cmp < 0)
        {
           
            travelNode = travelNode->left;
        }
        else if (cmp > 0)    /* 插入元素 > 遍历到的结点 */
        {
            travelNode = travelNode->right;
        }
        else
        { /* 插入元素 = 遍历到的结点 */
            return ret;
        }
    }

    /* 分配根结点 */
    #if 0
   BSTreeNode *newBstNode = (BSTreeNode *) malloc(sizeof(BSTreeNode) * 1);
    if(newBstNode == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清楚脏数据 */
    memset(newBstNode, 0, sizeof(BSTreeNode) * 1);
    /* 初始化根结点 */
    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL;
    }
    /* 新结点赋值 */
    newBstNode->data = val;
#endif
    BSTreeNode * newBstNode = createBSTreNewNode(val, parentNode);
    /* 挂在左子树 */
    if (cmp < 0)
    {
        parentNode->left = newBstNode;
    }
    else
    {   /* 挂在右子树 */
        parentNode->right = newBstNode;
    }
    /* 新节点的parent指针赋值 */
    newBstNode->parent = parentNode;


/* 二叉搜索树的前序遍历 */
    int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree)
    {
        int ret = 0;
        return ret;
    }

/* 二叉搜索树的中序遍历 */
    int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree)
    {
        int ret = 0;
        return ret;
    }

/* 二叉搜索树的后序遍历 */
    int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree)
    {
        int ret = 0;
        return ret;
    }

/* 二叉搜索树的层序遍历 */
    int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree)
    {
        int ret = 0;
        DoubleLinkListQueue * pQueue = NULL;
        doubleLinkListQueueInit(&pQueue);
       
        /* 根结点入队 */
        doubleLinkListQueuePush(pQueue, pBstree->root); 

        /* 判断队列是否为空 */
        BSTreeNode *nodeVal = NULL;
        while(!doubleLinkListQueueIsEmpty(pQueue))
        {
            doubleLinkListQueueTop(pQueue, (void **)&nodeVal);
            printf("data:%d\n", nodeVal->data);
            doubleLinkListQueuePop(pQueue);
            if(nodeVal->left != NULL)
            {
                doubleLinkListQueuePush(pQueue, nodeVal->left);
            }    
            if(nodeVal->right != NULL)
            {
                doubleLinkListQueuePush(pQueue, nodeVal->right);
            }    
        }

        /* 释放队列 */
        doubleLinkListQueueDestory(pQueue);
        return ret;
    }

    static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val)
    {
        BSTreeNode *travelNode = pBstree->root;

        while(travelNode != NULL)
        {

        }
    }
    /* 二叉搜索树是否包含指定元素 */
    int binarySearchTreeIsContainAppointVal(BinarySearchTree *pBstree, ELEMENTTYPE val)
    {
        baseAppointValGetBSTreeNode()
    }
}