//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
class Solution
{
public:
    void push(int val)
    {
        s.push(val);
        if (sm.empty())
            sm.push(val);
        else if (val <= sm.top())
            sm.push(val);
    }
    void pop()
    {
        if (s.top() == sm.top())
            sm.pop();
        s.pop();
    }
    int top()
    {
        return s.top();
    }
    int min()
    {
        return sm.top();
    }

private:
    stack<int> s;
    stack<int> sm;
};

