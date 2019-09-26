适配器(adaptor)是一个通用概念，容器、迭代器、函数都有适配器
C++标准库定义了三个顺序容器适配器：stack、 queue和priority_queue

stack
#include <stack>
默认是通过deque实现，也可以通过list、vector实现。
关于deque

双端队列，一种连续空间（实际上是一段一段的连续空间，并由一个map结构统一管理）容器，类似于vector、string。deque能够支持快速的随机访问；在头部和尾部添加、删除元素非常快速；但在中间删除和添加元素比较费时。

stack支持的操作
s.pop()
s.push()
s.emplace()
s.top()


queue、priority_queue
#include <queue>
queue默认是通过deque实现；priority_queue默认是通过vector实现

queue支持的操作

q.pop()
q.front()
q.back()//仅适用于queue
q.top()//仅适用于priority_queue

q.push()
q.emplace()



