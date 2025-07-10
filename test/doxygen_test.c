/**
 * @file doxygen_test.c
 * @brief 使用doxygen注释风格,用c语言写出二叉平衡树的实现，包括插入、删除、查找、打印等操作
 * @details
 * @author luorenwei
 * @version A.0.0.1
 * @date 2025.3.26
 * @copyright PANTUM
 */
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

/**
 * @brief 二叉平衡树节点结构体
 * @details Binary balanced tree node structure
 */
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

/**
 * @brief 二叉平衡树结构体
 * @details Binary balanced tree structure body
 */
typedef struct tree {
    Node *root;
} Tree;

/**
 * @brief 定义函数指针类型
 */
typedef int (*CompareFunc)(const void *a, const void *b);

/**
  * @brief    二叉平衡树插入函数
  * @details  This is a insertion function of binary balanced tree
  * @param    node  二叉平衡树的根节点。The root node of a binary balanced tree
  * @param    data  待插入的数据。      The data to be inserted
  * @return   返回插入后的二叉平衡树的根节点。
  *           Return the root node of the binary balanced tree after insertion.
  */
Node *insert(Node *node, int data) {
    if (node == NULL) {
        node = (Node *)malloc(sizeof(Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    } else if (data < node->data) {
        node->left = insert(node->left, data);
        if (height(node->left) - height(node->right) > 1) {
            if (data < node->left->data) {
                node = rotateRight(node);
            } else {
                node = rotateLeftRight(node);
            }
        }
    } else if (data > node->data) {
        node->right = insert(node->right, data);
        if (height(node->right) - height(node->left) > 1) {
            if (data > node->right->data) {
                node = rotateLeft(node);
            } else {
                node = rotateRightLeft(node);
            }
        }
    }
    return node;
}

/**
  * @brief    二叉平衡树删除函数
  * @details  This is a deletion function of binary balanced tree
  * @param    node  二叉平衡树的根节点。The root node of a binary balanced tree.
  * @param    data  待删除的数据。The data to be deleted
  * @return   返回删除后的二叉平衡树的根节点。
  *           Return the root node of the binary balanced tree after deletion.
  */
Node *remove(Node *node, int data) {
    if (node == NULL) {
        return node;
    }
    if (data < node->data) {
        node->left = remove(node->left, data);
    } else if (data > node->data) {
        node->right = remove(node->right, data);
    } else {
        if (node->left == NULL || node->right == NULL) {
            Node *temp = node->left? node->left : node->right;
            if (temp == NULL) {
                temp = node;
                node = NULL;
            } else {
                *node = *temp;
            }
            free(temp);
        } else {
            Node *temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }
    if (node == NULL) {
        return node;
    }
    if (height(node->left) - height(node->right) > 1) {
        if (height(node->left->left) >= height(node->left->right)) {
            node = rotateRight(node);
        } else {
            node = rotateLeftRight(node);
        }
    }
    if (height(node->right) - height(node->left) > 1) {
        if (height(node->right->right) >= height(node->right->left)) {
            node = rotateLeft(node);
        } else {
            node = rotateRightLeft(node);
        }
    }
    return node;
}

/**
  * @brief    二叉平衡树查找函数
  * @details  This is a search function of binary balanced tree
  * @param    node  二叉平衡树的根节点。The root node of a binary balanced tree.
  * @param    data  待查找的数据。The data to be searched.
  * @return   返回查找的节点。Return the node searched.
  */
Node *search(Node *node, int data) {
    if (node == NULL || node->data == data) {
        return node;
    }
    if (data < node->data) {
        return search(node->left, data);
    } else {
        return search(node->right, data);
    }
}

/**
  * @brief    二叉平衡树打印函数
  * @details  This is a print function of binary balanced tree
  * @param    node  二叉平衡树的根节点。The root node of a binary balanced tree.
  * @return   void
  */
void print(Node *node) {
    if (node == NULL) {
        return;
    }
    print(node->left);
    printf("%d ", node->data);
    print(node->right);
}

/**
  * @brief    二叉平衡树获取高度函数
  * @details  This is a height function of binary balanced tree
  * @param    node  二叉平衡树的根节点。The root node of a binary balanced tree.
  * @return   返回二叉平衡树的高度。
  *           Return the height of the binary balanced tree.
  */
int height(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + max(height(node->left), height(node->right));
}

/**
  * @brief    二叉平衡树获取最小值节点函数
  * @details  This is a minimum value node function of binary balanced tree
  * @param    node  二叉平衡树的根节点。The root node of a binary balanced tree.
  * @return   返回最小值节点。Return the minimum value node.
  */
Node *minValueNode(Node *node) {
    Node *current = node;
    while (current->left!= NULL) {
        current = current->left;
    }
    return current;
}

/**
  * @brief    二叉平衡树旋转右函数
  * @details  This is a rotation right function of binary balanced tree
  * @param    node  平衡二叉树中旋转的节点。
  *                 The node to be rotated in a balanced binary tree.
  * @return   返回旋转后的二叉平衡树节点。
  *           Return the rotated binary balanced tree node.
  */
Node *rotateRight(Node *node) {
    Node *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
}

/**
  * @brief    二叉平衡树旋转左函数
  * @details  This is a rotation left function of binary balanced tree
  * @param    node  平衡二叉树中旋转的节点。
  *                 The node to be rotated in a balanced binary tree.
  * @return   返回旋转后的二叉平衡树节点。
  *           Return the rotated binary balanced tree node.
  */
Node *rotateLeft(Node *node) {
    Node *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
}

/**
  * @brief    二叉平衡树旋转右左函数
  * @details  This is a rotation right left function of binary balanced tree
  * @param    node  平衡二叉树中旋转的节点。
  *                 The node to be rotated in a balanced binary tree.
  * @return   返回旋转后的二叉平衡树节点。
  *           Return the rotated binary balanced tree node.
  */
Node *rotateRightLeft(Node *node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

/**
  * @brief    二叉平衡树旋转左右函数
  * @details  This is a rotation left right function of binary balanced tree
  * @param    node  平衡二叉树中旋转的节点。
  *                 The node to be rotated in a balanced binary tree.
  * @return   返回旋转后的二叉平衡树节点。
  *           Return the rotated binary balanced tree node.
  */
Node *rotateLeftRight(Node *node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

/**
  * @brief    获取最大值函数
  * @details  This is a function to get the maximum value
  * @param    a  整数a。The integer a.
  * @param    b  整数b。The integer b.
  * @return   返回最大值。Return the maximum value.
  */
int max(int a, int b) {
    return a > b? a : b;
}

/**
  * @brief    创建二叉平衡树函数
  * @details  This is a function to create a binary balanced tree
  * @return   返回创建的二叉平衡树。Return the created binary balanced tree.
  */
Tree *createTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

/**
  * @brief    销毁二叉平衡树函数
  * @details  This is a function to destroy a binary balanced tree
  * @param    tree  二叉平衡树。The binary balanced tree.
  * @return   void
  */
void destroyTree(Tree *tree) {
    if (tree == NULL) {
        return;
    }
    destroyTree(tree->root);
    free(tree);
}

/**
  * @brief    插入元素函数
  * @details  This is a function to insert an element
  * @param    tree  二叉平衡树。The binary balanced tree.
  * @param    data  待插入的数据。The data to be inserted.
  * @return   void
  */
void insertElement(Tree *tree, int data) {
    tree->root = insert(tree->root, data);
}

/**
  * @brief    删除元素函数
  * @details  This is a function to delete an element
  * @param    tree  二叉平衡树。The binary balanced tree.
  * @param    data  待删除的数据。The data to be deleted.
  * @return   void
  */
void removeElement(Tree *tree, int data) {
    tree->root = remove(tree->root, data);
}

/**
  * @brief    查找元素函数
  * @details  This is a function to find an element
  * @param    tree  二叉平衡树。The binary balanced tree.
  * @param    data  待查找的数据。The data to be searched.
  * @return   返回查找的节点。Return the node searched.
  */
Node *findElement(Tree *tree, int data) {
    return search(tree->root, data);
}

/**
  * @brief    打印二叉平衡树函数
  * @details  This is a function to print a binary balanced tree
  * @param    tree  二叉平衡树。The binary balanced tree.
  * @return   void
  */
void printTree(Tree *tree) {
    print(tree->root);
}

/**
  * @brief    测试函数
  * @details  This is a test function
  * @return   void
  */
void test() {
    Tree *tree = createTree();
    insertElement(tree, 50);
    insertElement(tree, 30);
    insertElement(tree, 20);
    insertElement(tree, 40);
    insertElement(tree, 70);
    insertElement(tree, 60);
    insertElement(tree, 80);
    printf("Before remove: ");
    printTree(tree);
    removeElement(tree, 20);
    printf("After remove: ");
    printTree(tree);
    Node *node = findElement(tree, 50);
    if (node!= NULL) {
        printf("Find element: %d\n", node->data);
    } else {
        printf("Not find element.\n");
    }
    destroyTree(tree);
}

/**
  * @brief    主函数
  * @details  This is the main function
  * @return   返回0。Return 0.
  */
int main() {
    test();
    return 0;
}