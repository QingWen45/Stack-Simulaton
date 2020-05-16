#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *arr;
    int top;
}stack;

//��ջ����
void push(stack *a, int *len)
{
    if(a->top >= *len)
    {
        //����ջ�ռ�
        a->arr = (int*)realloc(a, sizeof(int) * (++*len));
    }
    int b;
    printf("������ջֵ:");
    scanf("%d", &b);
    a->arr[++a->top] = b;
    //return a->top;
}

//��ջ����
void pop(stack *a)
{
    if (a->top == -1)
    {
        printf("ջΪ�գ��޷���ջ��");
        return -1;
    }
    a->top--;
}

//չʾջ����Ԫ��
void show_top(stack *a)
{
    if(a->top == -1)
    {
        printf("ջΪ�ա�\n");
    }
    else
        printf("ջ��Ԫ��: %d\n", a->arr[a->top]);
}

//չʾջԪ��
void show_stack(stack *a)
{
    int i;
    printf("ջ��Ԫ��: ");
    for(i=0;i<=a->top;i++)
        printf("%d ", a->arr[i]);
    printf("\n");
}

int main()
{
    int i, len = 2;
    stack stack1;
    stack1.top = -1;
    stack1.arr = (int*)malloc(len * sizeof(int));

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
                push(&stack1, &len);
                break;
            case 2:
                pop(&stack1);
                break;
            case 3:
                show_top(&stack1)
                break;
            case 4:
                break;
            default:
                printf("��Ч���롣\n");
                break;
        }
        //ÿ��ָ�������չʾջ��Ԫ��
        if(stack1.top != -1) show_stack(&stack1);
    }
    while(i != 4);
    return 0;
}

