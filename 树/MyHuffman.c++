#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct HuffmanNode
{
    ElementType data;
    HuffmanNode* left;
    HuffmanNode* right;
    /* data */
}*PHuffmanNode,HuffmanNode;

PHuffmanNode createHuffmanTree(ElementType a[],int n){
    PHuffmanNode* b=(PHuffmanNode*)malloc(n*sizeof(HuffmanNode));
    PHuffmanNode* q;
    PHuffmanNode p;
    for(int i=0;i<n;i++){
        b[i]=(PHuffmanNode)malloc(sizeof(HuffmanNode));
        b[i]->data=a[i];
        b[i]->left=b[i]->right=NULL;
    }
    
    for(int i=1;i<n;i++){
        int k1=-1,k2;
       for(int j=0;j<n;j++){  //循环结束后k1为第一个节点的索引 k2为第二个节点的索引
           if(b[j]!=NULL && k1!=-1){
               k1=j;
               continue;
           }
           if(b[j]!=NULL){
               k2=j;
               break;
           }
       }
       for(int j=k2;j<n;j++){
           if(b[j]!=NULL){
               if(b[j]->data<b[k1]->data){
                   k2=k1;
                   k1=j;
               }else if (b[j]->data<b[k2]->data)
               {
                    k2=j;
               }

           }
       }
       p=(PHuffmanNode)malloc(sizeof(HuffmanNode));
       p->data=b[k1]->data+b[k2]->data;
       p->left=b[k1];
       p->right=b[k2];
       b[k1]=p;
       b[k2]=NULL;
    }

    }
    

