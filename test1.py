class Stack(object):
    def __init__(self):
        self.stack = []
        print("""请输入指令:
1.入栈
2.出栈
3.查看栈顶元素
4.读取栈
5.查找元素
6.退出 """)

    def main(self):
        while True:
            order = input(">")
            if order == '1':
                print("请输入栈元素:")
                self.push(int(input()))
            elif order == '2':
                self.pop()
            elif order == '3':
                self.top()
            elif order == '4':
                self.show()
            elif order == '5':
                print("请输入栈元素:")
                self.search(int(input()))
            elif order == '6':
                break
            else:
                print("错误指令")

    def push(self, a):
        """将对象压入栈顶"""
        self.stack.append(a)

    def pop(self):
        """移除栈顶对象"""
        if len(self.stack) == 0:
            print("栈为空!")
        else:
            self.stack.pop()

    def top(self):
        """查看栈顶对象的值"""
        if len(self.stack) == 0:
            print("栈为空!")
        else:
            print(self.stack[-1])

    def search(self, a):
        """查找对象在栈中的位置，以1为开始"""
        if a in self.stack:
            print(self.stack.index(a) + 1)
        else:
            print("该项不存在")

    def show(self):
        """倒序打印栈中元素"""
        arr = self.stack[::-1]
        for i in arr:
            print(i, end=' ')
        print()


if __name__ == '__main__':
    stack = Stack()
    stack.main()
