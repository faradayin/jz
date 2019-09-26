class Solution {
public:
	void replaceSpace(char *str,int length) 
    {
        int cnt = 0;
        for(int i=0; i<length; i++)
        {
            if(str[i] == ' ') cnt++;
        }
        int nl = cnt*2 + length;
        int i = nl-1;
        int j = length-1;
        while(j>=0)
        {
            while(j>=0 &&str[j] != ' ')
            {
                str[i--] = str[j--];

            }
            if(str[j] == ' ')
            {
                j--;
                str[i--] = '0';
                str[i--] = '2';
                str[i--] = '%';
            }
        }

	}
};