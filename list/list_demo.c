#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;          // 节点的数据部分
    struct Node *next; // 指向下一个节点的指针
};

// 创建新节点
struct Node *
createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // 分配内存
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data; // 设置数据
    newNode->next = NULL; // 初始化next指针为NULL

    return newNode;
}

// 向链表头部插入新节点
void insertAtHead(struct Node **head, int data)
{
    struct Node *newNode = createNode(data); // 创建新节点
    newNode->next = *head;                   // 将新节点的next指针指向原来的头节点
    *head = newNode;                         // 更新头指针为新节点
}

// 向链表尾部插入新节点
void insertAtTail(struct Node **head, int data)
{
    struct Node *newNode = createNode(data); // 创建新节点
    if (*head == NULL)
    {
        // 如果链表为空，直接把新节点作为头节点
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    // 找到链表的最后一个节点
    while (current->next != NULL)
    {
        current = current->next;
    }
    // 把最后一个节点的next指针指向新节点
    current->next = newNode;
}

// 遍历链表并打印数据
void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 释放链表
void freeList(struct Node *head)
{
    struct Node *current = head;
    struct Node *nextNode;
    while (current != NULL)
    {
        nextNode = current->next;
        free(current);      // 释放当前节点
        current = nextNode; // 移动到下一个节点
    }
}

int main()
{
    struct Node *head = NULL; // 初始化链表为空

    // 向链表头部插入元素
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);

    // 向链表头部插入元素
    insertAtTail(&head, 9);
    insertAtTail(&head, 8);
    insertAtTail(&head, 7);

    // 打印链表
    printf("链表内容: ");
    printList(head);

    // 释放链表
    freeList(head);

    return 0;
}