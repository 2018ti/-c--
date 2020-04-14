#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
struct BTreeNode
{
    ElemType data;
    struct BTreeNode* left;
    struct BTreeNode* right;
};
 
//1�����������������ǰ������Ļ������޸ġ����ù�����ʽ��Ԫ������Ϊint
void PrintBTree_int(struct BTreeNode* BT)
{
    if (BT != NULL)
    {
        printf("%d", BT->data); //���������ֵ
        if (BT->left != NULL || BT->right != NULL)
        {
            printf("(");
            PrintBTree_int(BT->left); //���������
            if (BT->right != NULL)
                printf(",");
            PrintBTree_int(BT->right); //���������
            printf(")");
        }
    }
}
 
//2���������� a �� n ��Ȩֵ����һ�ù�����������������ָ��
struct BTreeNode* CreateHuffman(ElemType a[], int n)
{
    int i, j;
    struct BTreeNode **b, *q;
    b = (BTreeNode**)malloc(n*sizeof(struct BTreeNode));
    for (i = 0; i < n; i++) //��ʼ��bָ�����飬ʹÿ��ָ��Ԫ��ָ��a�����ж�Ӧ��Ԫ�ؽ��
    {
        b[i] =(BTreeNode*)malloc(sizeof(struct BTreeNode));
        b[i]->data = a[i];
        b[i]->left = b[i]->right = NULL;
    }
    for (i = 1; i < n; i++)//���� n-1 ��ѭ��������������
    {
        //k1��ʾɭ���о�����СȨֵ�����������±꣬k2Ϊ����С���±�
        int k1 = -1, k2;
        for (j = 0; j < n; j++)//��k1��ʼָ��ɭ���е�һ������k2ָ��ڶ���
        {
            if (b[j] != NULL && k1 == -1)
            {
                k1 = j;
                continue;
            }
            if (b[j] != NULL)
            {
                k2 = j;
                break;
            }
        }
        for (j = k2; j < n; j++)//�ӵ�ǰɭ���������СȨֵ���ʹ���С
        {
            if (b[j] != NULL)
            {
                if (b[j]->data < b[k1]->data)
                {
                    k2 = k1;
                    k1 = j;
                }
                else if (b[j]->data < b[k2]->data)
                    k2 = j;
            }
        }
        //����СȨֵ���ʹ���СȨֵ������һ��������qָ���������
        q = (BTreeNode*)malloc(sizeof(struct BTreeNode));
        q->data = b[k1]->data + b[k2]->data;
        q->left = b[k1];
        q->right = b[k2];
 
        b[k1] = q;//��ָ��������ָ�븳��bָ��������k1λ��
        b[k2] = NULL;//k2λ��Ϊ��
    }
    free(b); //ɾ����̬����������b
    return q; //����������������������ָ��
}
 
//3������������Ĵ�Ȩ·������
ElemType WeightPathLength(struct BTreeNode* FBT, int len)//len��ʼΪ0
{
    if (FBT == NULL) //��������0
        return 0;
    else
    {
        if (FBT->left == NULL && FBT->right == NULL)//���ʵ�Ҷ�ӽ��
            return FBT->data * len;
        else //���ʵ���Ҷ�ӽ�㣬���еݹ���ã��������������Ĵ�Ȩ·������֮�ͣ�len����
            return WeightPathLength(FBT->left,len+1)+WeightPathLength(FBT->right,len+1);
    }
}
 
//4�����������루���Ը��ݹ���������Ȩ·�����ȵ��㷨�����Ͻ����޸ģ�
void HuffManCoding(struct BTreeNode* FBT, int len)//len��ʼֵΪ0
{
    static int a[10];//���徲̬����a������ÿ��Ҷ�ӵı��룬���鳤������������ȼ�һ
    if (FBT != NULL)//���ʵ�Ҷ�ӽ��ʱ����䱣��������a�е�0��1���б���
    {
        if (FBT->left == NULL && FBT->right == NULL)
        {
            int i;
            printf("���ȨֵΪ%d�ı��룺", FBT->data);
            for (i = 0; i < len; i++)
                printf("%d", a[i]);
            printf("\n");
        }
        else//���ʵ���Ҷ�ӽ��ʱ�ֱ������������ݹ���ã����ѷ�֧�ϵ�0��1���뱣�浽����a
        {   //�Ķ�ӦԪ���У���������һ��ʱlenֵ��1
            a[len] = 0;
            HuffManCoding(FBT->left, len + 1);
            a[len] = 1;
            HuffManCoding(FBT->right, len + 1);
        }
    }
}
 
//������
int main()
{
    int n, i;
    ElemType* a;
    struct BTreeNode* fbt;
    printf("�Ӽ������������Ĺ��������д�ȨҶ�ӽ����n��");
    while(1)
    {
        scanf("%d", &n);
        if (n > 1)
            break;
        else
            printf("����nֵ��");
    }
    a = (ElemType*)malloc(n*sizeof(ElemType));
    printf("�Ӽ�������%d��������ΪȨֵ��", n);
    for (i = 0; i < n; i++)
        scanf(" %d", &a[i]);
    fbt = CreateHuffman(a, n);
    printf("�������ʽ�Ĺ���������");
    PrintBTree_int(fbt);
    printf("\n");
    printf("���������Ĵ�Ȩ·�����ȣ�");
    printf("%d\n", WeightPathLength(fbt, 0));
    printf("����ÿ��Ҷ�ӽ��Ĺ��������룺\n");
    HuffManCoding(fbt, 0);
    return 0;
}
