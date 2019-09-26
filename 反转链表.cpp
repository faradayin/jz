/*
输入一个链表，反转链表后，输出新链表的表头。

*/
//用三个指针
#include <vector>
#include <string>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
//这是垃圾代码
class Solution {
public:
    ListNode* ReverseList(ListNode* h) {
    ListNode* l = h;
    if(l == NULL) return l;
    ListNode* c = l;
    ListNode* q = l->next;
    if(q != NULL)
    {
        l->next =NULL;

        c = q;//c指向第2个
        q = q->next;//q指向第3个
        c->next = l;//第2个指向第1个
        
        l = c;//l指向第2个
    }

    while( q!= NULL)//至少三个元素,q指向第3个，c指向第二个的指针域，l指向第二个
    
    {
        //
        c = q;//c指向第三个
        q = q->next;//q指向第四个
        c->next = l;//第三个指向第二个
        l = c;//指向第三个

    }
    return l;
    }

};
class Solution {
public:
    ListNode* ReverseList(ListNode* h)
    {
        if(h == nullptr)
            return h;
        if(h->next == nullptr)
            return h;
        ListNode* nt = h->next;
        ListNode* nh = ReverseList(nt);
        nt->next = h;//反转后nt所指向的正好是尾结点
        h->next = nullptr;
        return nh;

    }
};

//头插法
class Solution {
public:
    ListNode* ReverseList(ListNode* h)
    {
        ListNode* nh = new ListNode(-1);//nh->next 指向新链表的第一个节点
        while(h != nullptr)
        {
            ListNode* next = h->next;

            h->next = nh->next;
            nh->next = h;
            h = next;

        }
        return nh->next;
    }
};
