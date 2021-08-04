#include<iostream>
using namespace std;
const int N = 1e5 + 5;

int son[N][26],idx=0,cnt[N];
char str[N];

void insert(char * str)
{
	int p = 0;
	for(int i = 0 ; str[i] ; i++)
	{
		int u = str[i] - 'a';
		if(!son[p][u])
			son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p]++;
}

int query(char * str)
{
	int p = 0;
	for(int i=0;str[i];i++)
	{
		int u = str[i] - 'a';
		if(!son[p][u]) 
			return 0;
		p = son[p][u];
	}
	return cnt[p];
}

int main()
{
	int n;
	char op[2];
	cin>>n;
	while(n--)
	{
		scanf("%s",op);
		if(op[0]=='I')
		{
			scanf("%s",str);
			insert(str);
		}
		else
		{
			scanf("%s",str);
			cout<<query(str)<<endl;
		}
	}
}
 
