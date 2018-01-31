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
#define MAXVEX 8
#define INFINITY 65535
class MGraph{
public:
	int numVex;
	int arc[MAXVEX][MAXVEX];
	void show(MGraph G){
		for(int i=0;i<G.numVex;i++)
		{
			for(int j=0;j<G.numVex;j++)
			{
				cout<<G.arc[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};
void MiniSpanTree_Prime(MGraph G){
	int i,j,k,min;
	int adjvex[MAXVEX];
	int lowcost[MAXVEX];

	adjvex[0]=0;
	lowcost[0]=0;

	for(i=1;i<G.numVex;i++)
	{
		lowcost[i]=G.arc[0][i];
		adjvex[i]=0;
	}
	for(i=1;i<G.numVex;i++)
	{
		min=INFINITY;
		j=0;
		k=0;
		while(j<G.numVex)
		{
			
			if(lowcost[j]!=0&&lowcost[j]<min)
			{
				min=lowcost[j];
				k=j;
			}
			j++;
		}
		cout<<"("<<adjvex[k]<<","<<k<<")"<<endl;
		lowcost[k]=0;
		for(j=0;j<G.numVex;j++)
		{
			if(lowcost[j]!=0 && G.arc[k][j]<lowcost[j])
			{
				lowcost[j]=G.arc[k][j];
				adjvex[j]=k;
			}
		}

	}

}
int main()
{
	MGraph G;
	cin>>G.numVex;
	for(int i=0;i<G.numVex;i++)
		for(int j=0;j<G.numVex;j++)
			cin>>G.arc[i][j];
	G.show(G);
	MiniSpanTree_Prime(G);
	int endnum;
	cin>>endnum;
	return 0;
}
