#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *arr;
    int top;
}stack;

//入栈函数
void push(stack *a, int *len)
{
    if(a->top >= *len)
    {
        //扩充栈空间
        a->arr = (int*)realloc(a, sizeof(int) * (++*len));
    }
    int b;
    printf("请输入栈值:");
    scanf("%d", &b);
    a->arr[++a->top] = b;
    //return a->top;
}

//出栈函数
void pop(stack *a)
{
    if (a->top == -1)
    {
        printf("栈为空，无法出栈。");
        return -1;
    }
    a->top--;
}

//展示栈顶的元素
void show_top(stack *a)
{
    if(a->top == -1)
    {
        printf("栈为空。\n");
    }
    else
        printf("栈顶元素: %d\n", a->arr[a->top]);
}

//展示栈元素
void show_stack(stack *a)
{
    int i;
    printf("栈中元素: ");
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
        printf("请输入指令：\n");
        printf("1.入栈\n");
        printf("2.出栈\n");
        printf("3.查看栈顶元素\n");
        printf("4.退出\n");
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
                show_top(&stack1);
                break;
            case 4:
                break;
            default:
                printf("无效输入。\n");
                break;
        }
        //每次指令输入后展示栈中元素
        if(stack1.top != -1) show_stack(&stack1);
    }
    while(i != 4);
    free(stack1.arr);
    return 0;
}

