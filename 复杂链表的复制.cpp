/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/
#include<iostream>
#include<vector>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* h)
    {
        //
        if(h == NULL) return NULL;
        RandomListNode* p = h;
        while(p)
        {
            RandomListNode* t = new RandomListNode(p->label);
            t->next = p->next;
            // t->random = p->random;
            p->next = t;
            p = t->next;
        }
        //复制random指针域
        p = h;
        while (p)
        {
            if(p->random)
                p->next->random = p->random->next;
            p = p->next->next;

        }
        //分离
        p = h;
        RandomListNode* nh = h->next;
        RandomListNode* q = nh;

        while(q)
        {
            p->next = q->next;
            //这里要判定是否已经是最后一个节点，如果是最后一个节点则不必继续往后找q->next->next,否则会发生段错误
            if(q->next) 
            {
                q->next = q->next->next;
                p = p->next;
            }

            q = q->next;
        }
        return nh;

    }
};