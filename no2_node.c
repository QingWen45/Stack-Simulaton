#include <stdio.h>
#include <stdlib.h>

//����ڵ�ṹ��
typedef struct node
{
    int elem; //ջԪ�أ�Ϊ����
    struct node *next; //ָ����һ���ڵ��ָ��
}Node;

//��ջ����
Node *push(Node *front)
{
    int elem;
    Node *a = NULL;
    a = (Node*)malloc(sizeof(Node)); //�����ڴ�ռ�
    printf("������ջ��:");
    scanf("%d",&elem);
    a->elem = elem;
    a->next = NULL;
    if(front == NULL)
    {
        return a;  //��һ��ջ��Ԫ�ص�nextΪ��
    }
    else
    {
        a->next = front; //֮��������Ľڵ��next��ֵΪ��ʱָ����һ���ڵ��front
        return a; //Ȼ��ı�ջ����λ��
    }
}

//��ջ����
Node *pop(Node *front)
{
    if(front == NULL)
    {
        printf("ջΪ�գ��޷���ջ\n");
        return NULL;
    }
    else
    {
        return front->next; //ͨ����ջ��ָ����һ���ڵ���ʵ�ֳ�ջ
    }
}

//��ӡջ��Ԫ�غ���
void top(Node *front)
{
    if(front == NULL)
    {
        printf("ջΪ��\n");
    }
    else
    {
        printf("ջ��Ԫ��:%d\n",front->elem);
    }
}

//��ӡջԪ�غ���
void print(Node *front)
{
    if (front != NULL)
    {
        printf("ջ��Ԫ��:");
        while(front->next)
        {
            //ѭ����ջ��Ԫ��Ϊֹ
            printf("%d ",front->elem);
            front = front->next;
        }
        printf("%d \n",front->elem); //��ӡջ��Ԫ��
    }
}

//�ͷ��ڴ�
void mem_free(Node *front)
{
    Node *temp;
    while(front->next)
    {
        //ѭ����ջ��Ԫ��Ϊֹ
        temp = front->next;
        free(front);
        front = temp;
    }
    free(front); //�ͷ�ջ���ڴ�
}

int main()
{
    int i;
    Node *front;
    front = NULL; //���ĵĳ�ʼ��
    do
    {
        printf("������ָ�\n");
        printf("1.��ջ\n");
        printf("2.��ջ\n");
        printf("3.�鿴ջ��Ԫ��\n");
        printf("4.�˳�\n");
        scanf("%d", &i);
        switch(i)
        {
            case 1:
                front = push(front);
                break;
            case 2:
                front = pop(front);
                break;
            case 3:
                top(front);
                break;
            case 4:
                break;
            default:
                printf("��Ч���롣\n");
                break;
        }
        //ÿ��ָ�������չʾջ��Ԫ��
        print(front);
    }
    while(i != 4);
    mem_free(front); //�ͷ��ڴ�
    return 0;
}