#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include <regex> 
#include<map>
#include<time.h>
#include<list> 
using namespace std;
//听说学了AC自动机更易理解？
//KMP算法
//i是后缀 j是前缀
//前缀的固定的  后缀是相对的

void get_next(char *T,int *next,int len)
{

	int j=0;
	int k=-1;
	next[0]=-1;
	while(j<=len)
	{
		if(k==-1||T[j]==T[k])
		{
			j++;
			k++;
			next[j]=k;
		}
		else
			k=next[k];
	}
}


/*
void get_next(string T,int *next)
{
	int i=0,j=0;
	next[1]=0;
	while(i<T[0])
	{
		if(j==0||T[i]==T[j])
		{
			i++;
			j++;
		//	next[i]=j;  优化
			if(T[i]!=T[j])
			{
				next[i]=j;
			}
			else
			{
				next[i]=next[j];
			}
		}
		else
		{
			j=next[j];
		}
	}
}
*/
//返回子串T在主串第pos个字符后位置
/*
int Index_KMP(char S[],char T[],int pos)
{
	int i =pos;
	int j=1;
	int next[255];
 
	get_next(T,next);
	while(i<=S[0]&&j<=T[0])
	{
		if(j==0||S[i]==T[j])
		{
			i++;
			j++;
		}
		else
		{
			j=next[j];
		}
	}

	if(j>T[0])//成功匹配
	{
		return i-T[0];
	}
	else
	{
		return 0;
	}
}
*/

//int kmp_seach  KMP模式匹配函数    
//输入：src, slen主串    
//输入：patn, plen模式串    
//输入：nextval KMP算法中的next函数值数组    
int kmp_search(char * src, int slen, char * patn, int plen, int pos)    
{    
    int i = pos;    
    int j = 0;    
    int nextval[255];
 
    get_next(patn,nextval,plen);
    while ( i < slen && j < plen )    
    {    
        if( j == -1 || src[i] == patn[j] )    
        {    
            ++i;    
            ++j;    
        }    
        else    
        {    
            j = nextval[j];              
            //当匹配失败的时候直接用p[j_next]与s[i]比较，    
            //下面阐述怎么求这个值，即匹配失效后下一次匹配的位置    
        }    
    }    
    if( j >= plen )    
        return i-plen;    
    else    
        return -1;    
}    

 
int main()
{
	char S[1000],T[1000];
	cin>>S;
	cin>>T;
	
	int slen=strlen(S);
	int plen=strlen(T);
	
	cout<<"KMP"<<endl;
	int k=kmp_search(S,slen,T,plen,0)+1;
	cout<<k<<endl;
	int endnum;
	cin>>endnum;
	return 0;
}

