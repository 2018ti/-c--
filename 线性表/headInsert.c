#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

struct node //建立结构体
{
    int data;          //elementype表示一种数据类型，可能是int/char等等
    struct node *next; //next 指针，用于链表结构指向下一个节点
};

typedef struct node node; //重定义struct node类型为node

node *Creat(int Count) //创建链表
{
    node *p, *head;
    int n;
    srand(time(NULL)); //生成种子
    head = (node *)malloc(sizeof(node));
    head->data = Count;
    head->next = NULL; //头结点储存链表长度
    for (n = 0; n < Count; n++)
    {
        p = (node *)malloc(sizeof(node));
        p->data = rand() % 1000;
        p->next = head->next; //头插法单链表创建的关键两行代码
        head->next = p;
    }
    return (head);
}

void List(node *head) //打印链表
{
    node *p1;
    p1 = head;
    while (p1 != NULL)
    {
        printf("%4d", p1->data);
        p1 = p1->next;
    }
}

int main() //主函数
{
    node *head;
    int Num;

    printf("Enter the number of linked list nodes:\n");
    scanf("%d", &Num);
    head = Creat(Num);
    printf("\n");
    printf("List:\n");
    List(head);
    printf("\n");
}
