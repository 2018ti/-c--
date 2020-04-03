#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    Node* next;
    /* data */
}Node,*pNode;

typedef struct Stack
{
    pNode top;
    pNode bottom;

    /* data */
}Stack,*pStack;

void init(pStack);
void push(pStack,int);
void pop(pStack);
void show(pStack s);

int main(){
    Stack s;
    int value;
    init(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    show(&s);
    pop(&s);
    printf("�������ջ�ǣ�");
    show(&s);
    return 0;
}
void init(pStack ps){
    ps->top=(pNode)malloc(sizeof(Node));
    if(ps->top==NULL){
        printf("��̬�ڴ����ʧ��\n");
        exit(-1);
    }
    ps->bottom=ps->top;
    ps->top->next=NULL;
}

void push(pStack ps,int data){
    pNode pnew=(pNode)malloc(sizeof(Node));
    if(pnew==NULL){
        printf("��̬�ڴ����ʧ��\n");
        exit(-1);
    }
    pnew->next=ps->top;
    pnew->data=data;
    ps->top=pnew;
}

void show(pStack ps){
    pNode p =ps->top;
    
    while(p!=ps->bottom)
    {
        printf("%d ",p->data);
        p=p->next;
        /* code */
    }
}

void pop(pStack ps){
    pStack p=ps;
    if(p->bottom==p->top){
        printf("ջΪ�գ����ȷ���Ԫ��");
    }
    else
    {
        pNode temp=p->top;
        printf("������Ԫ����%d\n",temp->data);
        p->top=p->top->next;
        free(temp);
        temp->next=NULL;
        return;
        /* code */
    }

}
