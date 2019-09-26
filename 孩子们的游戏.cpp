/*
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:
首先,让小朋友们围成一个大圈。
然后,他随机指定一个数m,
让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,
然后可以在礼品箱中任意的挑选礼物,
并且不再回到圈中,
从他的下一个小朋友开始,继续0...m-1报数....
这样下去....直到剩下最后一个小朋友,
可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版
(名额有限哦!!^_^)。
请你试着想下,哪个小朋友会得到这份礼品呢？
(注：小朋友的编号是从0到n-1)

*/
class Solution {
public:
//模拟整个过程，未通过
    int LastRemaining_Solution(int n, int m)
    {
        //m > 0

        vector<int> f(n,0);
        int cur = -1;
        while(next(f, cur, n, m) != -1)
        {
            f[next(f, cur, n, m)] = -1;
            cur = next(f, cur, n, m);

        }
        return cur;

    }
    int next(vector<int> &f, int cur, int n, int m)
    {
        //return -1, if there's 0 child left
        //f[cur] == -1
        while(m > 0)
        {
            int s = 0;
            while(f[(cur+1)%n] == -1 && s != n)
            {

                cur = (cur+1)%n;
                ++s;

            }
            if(s == n) return -1;

            cur = (cur+1)%n;//1 step 
            --m;
            
        }// m steps
        return cur;
    }



//递归的方法，通过
    // f(n) = (f(n-1)+m)%n
    // f(1) = 0;
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        if(n < 1 || m < 1)
        {
            return -1;
        }
        else if(n == 1)
        {
            return 0;
        }
        else
        {
            // F[n] = (F[n - 1] + m) % n
            return (LastRemaining_Solution(n-1,m)+m)%n;
        }
    }
};