#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct node
{
    ElementType num;
    node* next;
    /* data */
};
typedef struct node node;

node *LinkInit(){
    node *head=(node*)malloc(sizeof(node));
    head->next=NULL;
    node *p=head;
    ElementType length;
        printf("请输入约瑟夫环的长度\n");
        scanf("%d",&length);
        ElementType i=1;
        while(i<=length){
        node *newNode=(node*)malloc(sizeof(node));
        newNode->num=i;
        newNode->next=head->next;
        p->next=newNode;
        p=p->next;
        i++;
    }
    return head;
}


void showList(node* head){
    node*p =head->next;
    while(p!=NULL){
        printf("%d ",p->num);
        p=p->next;
    }
}
void yuesefuKill(node* head){
    node* p=head->next;
    ElementType i=1;
    while(p!=NULL){
        if(p->next==p){
            printf("%d ",p->num);
            return;  
        }
        while(i<=1){
            p=p->next;
            i++;
        }
        printf("%d ",p->next->num);
        p->next=p->next->next;
        p=p->next;
        i=1;  
    }

}



int main(){
    node* head=LinkInit();

    yuesefuKill(head);
}

