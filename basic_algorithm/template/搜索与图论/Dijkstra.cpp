#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 510;
int n,m;
bool st[N];
int g[N][N];//邻接矩阵 
int dist[N];// 1 到 N 的距离 

int dijkstra()
{
	memset(dist,0x3f,sizeof dist);
	
	dist[1] = 0;
	
	for(int i=0;i<n;i++)
	{
		int t = -1;
		for(int j=1;j<=n;j++)
		{
			if(!st[j] && (t == -1 ||dist[t] > dist[j]))
				t = j; //离起点最近的点 
		}
		
		st[t] = true;
		
		for(int j=1;j<=n;j++) //更新当前最短路 (每次保证与集合st里的点联通的最短) 
			dist[j] = min(dist[j],dist[t] + g[t][j]);
	}
	if(dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];
}

int main()
{
	cin>>n>>m;
	
	memset(g,0x3f,sizeof g);
	
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b] = min(g[a][b],c);
	} 
	
	int t = dijkstra();
	
	cout<<t;
} 
