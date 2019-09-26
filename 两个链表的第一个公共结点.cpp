// 输入两个链表，找出它们的第一个公共结点。
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* p1, ListNode* p2) {
    stack<ListNode*> L2;
    stack<ListNode*> L1;
    ListNode *first = NULL;
    while(p2)
    {
        L2.push(p2);
        p2 = p2->next;

    }
    while(p1)
    {
        L1.push(p1);
        p1 = p1->next;
    }

    while(!L1.empty() && !L2.empty() && L1.top() == L2.top())
    {
        first = L1.top();
        L1.pop();
        L2.pop();
    }
    return first;
    }
};