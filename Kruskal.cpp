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
class Edge{
public:
	int start;
	int end;
	int weight;
	static void show(Edge E[],int len){
		for(int i=0;i<len;i++)
		{
			cout<<E[i].start<<" "<<E[i].end<<" "<<E[i].weight<<endl;
		}
	}
}; 
int Find(int *parent,int f)
{
	while(parent[f]>0)
	{
		f=parent[f];
	}
	return f;
} 
void MiniSpanTree_Kruskal(Edge E[],int vex,int edges)
{
	int n,m;
	int parent[1000]={0};
	for(int i=0;i<vex;i++)
	{
		parent[i]=0;
	}
	for(int i=0;i<edges;i++)
	{
		n=Find(parent,E[i].start);
		m=Find(parent,E[i].end);
		if(n!=m)
		{
			parent[n]=m;
			cout<<"("<<E[i].start<<","<<E[i].end<<")"<<endl;
		}
	}

}
int main()
{
	int len;
	int vex;
	cin>>len>>vex;
	Edge E[1000];
	for(int i=0;i<len;i++)
	{
		cin>>E[i].start>>E[i].end>>E[i].weight;
	}
	Edge::show(E,len);
	MiniSpanTree_Kruskal(E,vex,len);
	int endnum;
	cin>>endnum;
	return 0;
}
