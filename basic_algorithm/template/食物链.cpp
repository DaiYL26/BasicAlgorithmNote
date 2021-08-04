#include<iostream>
using namespace std;
const int N = 50010;
int p[N],d[N];

int find(int x)
{
	if(p[x] != x)
	{
		int t = find(p[x]);
		d[x] += d[p[x]];
		p[x] = t;
	}
	return p[x];
}

int main()
{
	int n,k,q,x,y,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		p[i] = i;
	
	while(k--)
	{
		cin>>q>>x>>y;
		if(x>n || y>n)
		{
			ans++;
			continue;
		}
		int px = find(x),py = find(y);
		if(q==1)
		{
			
			if(px==py && (d[x]-d[y])%3 != 0)
				ans++;
			else if(px!=py)
			{
				p[px] = py;
				d[px] = d[y] - d[x];
			}
		}
		else
		{
			if(px==py && (d[x]-d[y]-1)%3!=0)
				ans++;
			else if(px!=py)
			{
				p[px] = py;
				d[px] = d[y] + 1 - d[x];
			}
		}
		
	}
} 
