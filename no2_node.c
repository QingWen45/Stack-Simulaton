#include <stdio.h>
#include <stdlib.h>

//定义节点结构体
typedef struct node
{
    int elem; //栈元素，为整数
    struct node *next; //指向下一个节点的指针
}Node;

//入栈函数
Node *push(Node *front)
{
    int elem;
    Node *a = NULL;
    a = (Node*)malloc(sizeof(Node)); //申请内存空间
    printf("请输入栈项:");
    scanf("%d",&elem);
    a->elem = elem;
    a->next = NULL;
    if(front == NULL)
    {
        return a;  //第一个栈底元素的next为空
    }
    else
    {
        a->next = front; //之后新申请的节点的next赋值为此时指向上一个节点的front
        return a; //然后改变栈顶的位置
    }
}

//出栈函数
Node *pop(Node *front)
{
    if(front == NULL)
    {
        printf("栈为空，无法出栈\n");
        return NULL;
    }
    else
    {
        return front->next; //通过将栈顶指向上一个节点来实现出栈
    }
}

//打印栈顶元素函数
void top(Node *front)
{
    if(front == NULL)
    {
        printf("栈为空\n");
    }
    else
    {
        printf("栈顶元素:%d\n",front->elem);
    }
}

//打印栈元素函数
void print(Node *front)
{
    if (front != NULL)
    {
        printf("栈中元素:");
        while(front->next)
        {
            //循环到栈底元素为止
            printf("%d ",front->elem);
            front = front->next;
        }
        printf("%d \n",front->elem); //打印栈底元素
    }
}

//释放内存
void mem_free(Node *front)
{
    Node *temp;
    while(front->next)
    {
        //循环到栈底元素为止
        temp = front->next;
        free(front);
        front = temp;
    }
    free(front); //释放栈底内存
}

int main()
{
    int i;
    Node *front;
    front = NULL; //安心的初始化
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
                printf("无效输入。\n");
                break;
        }
        //每次指令输入后展示栈中元素
        print(front);
    }
    while(i != 4);
    mem_free(front); //释放内存
    return 0;
}