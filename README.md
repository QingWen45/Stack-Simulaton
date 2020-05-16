# Stack-Simulaton
用C的整型数组，结构体和Python的list模拟栈。
栈是只能在一端插入和删除数据的序列，它按照先进后出的原则存储数据，先进入的数据被压入栈底，最后的数据在栈顶。
需要读数据的时候从栈顶开始弹出数据，最后一个数据被第一个读出来。
编写一个程序模拟堆栈，要求能够模拟、入栈、出栈、返回栈顶元素等基本操作。栈中元素可用整数代替。

no2.c:初版，用数组模拟堆栈。
no2_struct:用数组和栈顶索引组成的结构体模拟堆栈。
no2_node:用链表模拟堆栈。
test1.py:用list模拟堆栈。
