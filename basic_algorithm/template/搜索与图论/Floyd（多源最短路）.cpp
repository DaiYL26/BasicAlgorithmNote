#include<iostream>
using namespace std;

const int INF = 1e9,N  = 210;

int n,m,k;
int g[N][N];

void floyd() //dp
{
	for(int k = 1;k <= n; k++ )
		for(int i = 1;i <= n; i++ )
			for(int j = 1;j <= n; j++ )
				g[i][j] = min(g[i][k] + g[k][j],g[i][j]);
}

int main()
{
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				g[i][j] = INF;
	
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b] = min(g[a][b],c);
	}
	
	floyd();
	
	while(k--)
	{
		int x,y;
		cin>>x>>y;
		if(g[x][y] > INF>>1)	puts("impossible");
		else	cout<<g[x][y]<<endl;
	}
}
