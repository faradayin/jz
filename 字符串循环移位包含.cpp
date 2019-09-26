/*
给定两个字符串s1，s2，要求判定s2是否能够被s1做循环移位得到的字符串包含。
*/
//C代码
#include <stdio.h>
#include <string.h>
int main()
{
    char s1[] = "AABCDEF";
    char s2[] = "CDEFA";

    int len = strlen(s1);
    int i, j;
    char temp;

    for (i = 0; i < len; i++)
    {
        temp = s1[0];
        for (j = 0; j < len - 1; j++)
        {
            s1[j] = s1[j + 1];
        }
        s1[len - 1] = temp;

        if (strstr(s1, s2) != 0)
        {
            printf("TRUE\n");
            return 0;
        }
    }

    printf("FALSE\n");

    return 0;
}

//C++代码
#include <iostream>
 
using namespace std;
 
bool find(char* src, char* dst)
{
	int lens = 0, lend = 0;
	char* p2src = NULL;
	bool find = false;
 
	if ((NULL == src) || (NULL == dst))
		return false;
 
	lens = strlen(src);
	lend = strlen(dst);
 
	if (lend > lens) return false;
 
	p2src = new char[lens*2+1];
	memcpy(p2src, src, lens);
	memcpy(p2src+lens, src, lens);
	p2src[lens*2] = '\0';
 
	if (NULL == strstr(p2src, dst))
	{
		find = false;
		cout << dst << " Not exist in " << src << endl;
	}
	else
	{
		find = true;
		cout << dst << " exist in " << src << endl;
	}
	delete[] p2src;
	p2src = NULL;
 
	return find;
}
 
 
void main()
{
	int i = 0;
	//char* str = "ABCDE";
	//char* dst = "DEAB";
 
	char* str = "ABCDEF";
	char* dst = "DEAB";
 
	find(str, dst);
	
}
