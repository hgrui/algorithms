#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<time.h>
#include<list> 
using namespace std; 
#define X 8
#define Y 8
int chess[X][Y]={0}; 
int nextxy(int *x,int *y,int count)
{
	switch(count)
	{
		case 0:
			if(*x+2<=X-1 && *y-1>=0 && chess[*x+2][*y-1]==0)
			{
				*x+=2;
				*y-=1;
				return 1;
			}
			break;		
		case 1:
			if(*x-2>=0 && *y-1>=0 && chess[*x-2][*y-1]==0)
			{
				*x-=2;
				*y-=1;
				return 1;
			}
			break;		
		case 2:
			if(*x+2<=X-1 && *y+1<=Y-1 && chess[*x+2][*y+1]==0)
			{
				*x+=2;
				*y+=1;
				return 1;
			}
			break;		
		case 3:
			if(*x-2>=0 && *y+1<=Y-1 && chess[*x-2][*y+1]==0)
			{
				*x-=2;
				*y+=1;
				return 1;
			}
			break;		
		case 4:
			if(*x+1<=X-1 && *y-2>=0 && chess[*x+1][*y-2]==0)
			{
				*x+=1;
				*y-=2;
				return 1;
			}
			break;		
		case 5:
			if(*x-1>=0 && *y-2>=0 && chess[*x-1][*y-2]==0)
			{
				*x-=1;
				*y-=2;
				return 1;
			}
			break;		
		case 6:
			if(*x+1<=X-1 && *y+2<=Y-1 && chess[*x+1][*y+2]==0)
			{
				*x+=1;
				*y+=2;
				return 1;
			}
			break;		
		case 7:
			if(*x-1>=0 && *y+2<=Y-1 && chess[*x-1][*y+2]==0)
			{
				*x-=1;
				*y+=2;
				return 1;
			}
			break;		

		default:
			break;
	}
	return 0;
}

void printchess()
{
	for(int i=0;i<X;i++)
	{
		for(int j=0;j<Y;j++)
		{
			if(chess[i][j]<=9)
			{
				cout<<" "<<chess[i][j]<<" ";
			}
			else
				cout<<chess[i][j]<<" ";

		}
		cout<<endl;
	}
}
 
int TravelChess(int x,int y,int tag)
{
	int x1=x,y1=y,flag=0,count=0;
	chess[x][y]=tag;

	if(tag==X*Y)
	{ 
		printchess();
		return 1;
	}
	else 
	{	
	}
	flag=nextxy(&x1,&y1,count);
	while(flag==0&& count<7)
	{
		count++;
		flag=nextxy(&x1,&y1,count);
	}


	while(flag)
	{
		if( TravelChess(x1,y1,tag+1) ) 
		{
			return 1;
		} 
		x1=x;
		y1=y;
		count++;
		flag=nextxy(&x1,&y1,count);
		while(flag==0&& count<7)
		{
			count++;
			flag=nextxy(&x1,&y1,count);
		}


	}
	if(0==flag)
	{
		chess[x][y]=0;
	}
	return 0;
}


int main() 
{ 
	int i,j;
	clock_t start,finish;
	start =clock();
	if(!(TravelChess(2,0,1)))
	{
		cout<<"sorry failed"<<endl;
	}
	finish=clock();
	cout<<endl<<"time cost:"<<(double)(finish-start)/CLOCKS_PER_SEC<<endl;
	int endnum;
	cin>>endnum;
	return 0;
}
