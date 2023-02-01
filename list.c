#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void copyToNode(Item item, Node * pnode);

// 初始化链表
void InitializeList(List * plist) {
    *plist = NULL;
}

// 判断链表是否为空
bool ListIsEmpty(const List * plist) {
    if (*plist == NULL) {
        return true;
    } else {
        return false;
    }
}

// 判断链表是否为满
bool ListIsFull(const List * plist) {
    Node * pt;
    bool full;
    pt = (Node *) malloc (sizeof(node));
    if (pt = NULL) full = true;
    else full = false;
    free(pt);
    return full;
}

// 求链表中的项数
unsigned int ListItemCount(const List * plist) {
    unsigned int count = 0;
    Node * pnode = *plist;
    while (pnode != NULL) {
        ++count;
        pnode = pnode->next;
    }
    return count;
}

// 在链表末尾添加项
bool AddItem(Item item, List * plist) {
    Node * pnode;
    Node * scan = *plist;
    pnew = (Node *) malloc(sizeof(Node));
    if (pnew = NULL) return false;
    CopyToNode(Item, pnew);
    pnew->next = NULL;
    if (scan == NULL) {
        *plist = pnew;
    } else {
        while (scan->next != NULL) {
            scan = scan->next;
        }
        scan->next = pnew;
    }
}

// 在链表的任意位置插入一个项
// 移除链表中某一项
// 检索链表中某一项
// 修改链表中某一项
// 遍历链表，对链表中的每一项都执行某一操作
void Traverse(const List * plist, void(*pfun)(Item item));
// 清空链表
void EmptyTheList(List * plist);