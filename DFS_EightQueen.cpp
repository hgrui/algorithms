#include<iostream>
using namespace::std;
#include<math.h>
#include <stdlib.h>
#include<conio.h>
#define NUM 12
void showQueens(int queenArr[],int nlen,int &nums)
{
	nums++;
/*	cout<<nums<<endl;
    for(int i=0;i<nlen;i++)
    {
		for(int j=0;j<queenArr[i];j++)
		{
			cout<<"0 ";
		}

        cout<<"1 ";
        for(int j=0;j<nlen-1-queenArr[i];j++)
		{
			cout<<"0 ";
		}
		cout<<""<<endl;
    }*/
}
bool isClash(int queenArr[])
{
    for(int i=1;i<=NUM;i++)
    {
		for(int j=0;j<=i-1;j++)
		{
			if(queenArr[i]==queenArr[j])
			{
				return true;
			}
			if(abs(queenArr[i]-queenArr[j])==abs(i-j))
			{
				return true;
			}

		}
    }
    return false;      
}

 
void enumQueenPosition(int queenArr[],int& nums)
{
    for(queenArr[0]=0;queenArr[0]<8;queenArr[0]++)
    {
		for(queenArr[1]=0;queenArr[1]<8;queenArr[1]++)
		{
			for(queenArr[2]=0;queenArr[2]<8;queenArr[2]++)
			{
				for(queenArr[3]=0;queenArr[3]<8;queenArr[3]++)
				{
					for(queenArr[4]=0;queenArr[4]<8;queenArr[4]++)
					{
						for(queenArr[5]=0;queenArr[5]<8;queenArr[5]++)
						{
							for(queenArr[6]=0;queenArr[6]<8;queenArr[6]++)
							{
								for(queenArr[7]=0;queenArr[7]<8;queenArr[7]++)
								{
							 
									if(isClash(queenArr))
									{
										continue;
									}
									else
									{
				
										showQueens(queenArr,8,nums);
									
										//_getch();  
									}
								}
							}
						}
					}
				}
			}
		}
    }
}
bool isClash2(int queenArr[],int nRow)
{
	for(int i=0;i<nRow;i++)
	{
		if(queenArr[i]==queenArr[nRow])
		{
			return false;
		}
		if(abs(queenArr[i]-queenArr[nRow])==abs(i-nRow))
		{
			return false;
		}
	}
	return true;
} 
void putQueen(int queenArr[],int nRow,int &nums)
{
	for(int i=0;i<NUM;i++)
	{
		queenArr[nRow]=i;
		//¼ì²é³åÍ»
		if(isClash2(queenArr,nRow))
		{
			
			if(nRow==NUM-1)
			{
				showQueens(queenArr,NUM,nums);
			}
			else
			{
				putQueen(queenArr,nRow+1,nums);
			}
		}
 
	}
}
int main()
{
    int n;
    int nums=0;
    cout<<"hello,my queens"<<endl;
    int queenArr[NUM];//queens' location
//  enumQueenPosition(queenArr,nums);
    putQueen(queenArr,0,nums);
    cout<<nums<<endl;
    cin>>n;
    return 0;
}
