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
void move(int n,char X,char Y,char Z)
{
	if(n==1)
		cout<<X<<"->"<<Z<<endl;
	else
	{
		move(n-1,X,Z,Y);// X->Y
		cout<<X<<"->"<<Z<<endl;//X->Z
		move(n-1,Y,X,Z);// Y->Z
	}
}
int main(){
	int n;
	cin>>n;
	move(n,'X','Y','Z');
	int endnums;
	cin>>endnums;
	return 0;
}
