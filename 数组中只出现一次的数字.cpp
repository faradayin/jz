// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
// 请写程序找出这两个只出现一次的数字。
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    set<int> ns;
    for(auto n:data){
        auto it = ns.find(n);
        if(it == ns.end())
            ns.insert(n);
        else
        {
                ns.erase(n);
        }

    }
    auto nit = ns.begin();
    *num1 = *nit;
    nit++;
    *num2 = *nit;

    }
};