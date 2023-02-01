/**
 * @file list.h
 * @author Yan
 * @brief 链表
 * @version 0.1
 * @date 2023-01-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

// 修改

#define TSIZE 45
typedef struct film {
    char title[TSIZE];
    int rating;
} Item;

// 链表

typedef struct node {
    Item item;
    struct node * next;
} Node;
typedef Node * List;

// 初始化链表
void InitializeList(List * plist);
// 判断链表是否为空
bool ListIsEmpty(const List * plist);
// 判断链表是否为满
bool ListIsFull(const List * plist);
// 求链表中的项数
unsigned int ListItemCount(const List * plist);
// 在链表末尾添加项
bool AddItem(Item item, List * plist);
// 在链表的任意位置插入一个项
// 移除链表中某一项
// 检索链表中某一项
// 修改链表中某一项
// 遍历链表，对链表中的每一项都执行某一操作
void Traverse(const List * plist, void(*pfun)(Item item));
// 清空链表
void EmptyTheList(List * plist);


