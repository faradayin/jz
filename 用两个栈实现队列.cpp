class Solution
{
public:
    void push(int node) 
    {
        stack1.push(node);
    }

    int pop() 
    {
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                int top1 = stack1.top();//note that stack.top() has no return value
                stack1.pop();
                stack2.push(top1);
            }
            
        }
        int  top2 = stack2.top();
        stack2.pop();
        return top2;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};