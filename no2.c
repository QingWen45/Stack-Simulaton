#include <stdio.h>
#include <stdlib.h>

//��ջ����
int push(int *a, int n, int *len)
{
    if(n >= *len)
    {
        //����ջ�ռ�
        a = (int*)realloc(a, sizeof(int) * (++*len));
    }
    int b;
    printf("������ջֵ:");
    scanf("%d", &b);
    a[++n] = b;
    return n;
}

//��ջ����
int pop(int *a, int n)
{
    if (n == -1)
    {
        printf("ջΪ�գ��޷���ջ��");
        return -1;
    }
    n--;
    return n;
}

//չʾջԪ��
void show_stack(int *a, int n)
{
    int i;
    printf("ջ��Ԫ��: ");
    for(i=0;i<=n;i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int i, top=-1, len = 2;
    int *stack = (int*)malloc(len * sizeof(int));

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
                top = push(stack, top, &len);
                break;
            case 2:
                top = pop(stack, top);
                break;
            case 3:
                //չʾջ����Ԫ��
                if(top == -1)
                {
                    printf("ջΪ�ա�\n");
                    break;
                }
                printf("ջ��Ԫ��: %d\n", stack[top]);
                break;
            case 4:
                break;
            default:
                printf("��Ч���롣\n");
                break;
        }
        //ÿ��ָ�������չʾջ��Ԫ��
        if(top != -1) show_stack(stack, top);
    }
    while(i != 4);
    return 0;
}

