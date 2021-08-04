#include<iostream>
using namespace std;

char s[100010],p[10010];
int ne[10010];
int n,m;

int main()
{
	cin>>n;
	cin.get();
	cin.getline(p+1,n+1);
	cin>>m;
	cin.get();
	cin.getline(s+1,m+1);
	
	for(int i=2,j=0;i <= n;i++)
	{
		while(j && p[i] != p[j+1]) j = ne[j];
		if(p[i] == p[j+1])	j++;
		ne[i] = j;	
	}
	
	for(int i=1,j=0;i <= m;i++)
	{
		while(j && s[i] != p[j+1]) j = ne[j];
		if(s[i] == p[j+1])	j++;
		if(j == n)
		{
			cout<<i-n<<' ';
			j = ne[j];
		}
	}
	return 0;
} 
