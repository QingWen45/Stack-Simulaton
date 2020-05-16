#include <stdio.h>
#include <stdlib.h>

//入栈函数
int push(int *a, int n, int *len)
{
    if(n >= *len)
    {
        //扩充栈空间
        a = (int*)realloc(a, sizeof(int) * (++*len));
    }
    int b;
    printf("请输入栈值:");
    scanf("%d", &b);
    a[++n] = b;
    return n;
}

//出栈函数
int pop(int *a, int n)
{
    if (n == -1)
    {
        printf("栈为空，无法出栈。");
        return -1;
    }
    n--;
    return n;
}

//展示栈元素
void show_stack(int *a, int n)
{
    int i;
    printf("栈中元素: ");
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
        printf("请输入指令：\n");
        printf("1.入栈\n");
        printf("2.出栈\n");
        printf("3.查看栈顶元素\n");
        printf("4.退出\n");
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
                //展示栈顶的元素
                if(top == -1)
                {
                    printf("栈为空。\n");
                    break;
                }
                printf("栈顶元素: %d\n", stack[top]);
                break;
            case 4:
                break;
            default:
                printf("无效输入。\n");
                break;
        }
        //每次指令输入后展示栈中元素
        if(top != -1) show_stack(stack, top);
    }
    while(i != 4);
    free(stack);
    return 0;
}

