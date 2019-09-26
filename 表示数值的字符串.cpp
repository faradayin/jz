// 只能有一个e/E
// 只能有一个+/-
// e前允许有.
// 好复杂
class Solution {
public:
    bool isNumeric(char* str)
    {
        
        bool sign1 = false;//befor e
        bool sign2 = false;//after e
        bool e = false;//e
        bool dot = false;//.
        for(int i=0; str[i]!='\0';i++) 
        {
            if(str[i] == 'e' || str[i] == 'E')
            {
                if(e) return false;
                else e = true;
                if(str[i+1] )
            }
            if(str[i] == '+' || str[i] == '-')
            {
                if((!e && sign1) || (e && sign2) ) return false;
                else
                {
                    if(!e) sign1 = true;
                    else sign2 = true;

                }

            }
            if(str[i] == '.')
            {
                if(e || dot) return false;
                if(str[i+1] < '0' || str[i] > '9') return false;


            }
        }

    }

};