#include<iostream>
using namespace std;
const int N = 100010;

int e[N],ne[N],head,idx;

void init()
{
	head = -1;
	idx = 0;
}

void add_to_head(int x)
{
	e[idx] = x;
	ne[idx] = head;
	head = idx++;
}

void insert(int k,int x)
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx++;	
}

void remove(int k)
{
	ne[k] = ne[ne[k]];
}

int main()
{
	init();
	int m;
	cin>>m;
	while(m--)
	{
		char c;
		cin>>c;
		if(c=='H')
		{
			int x;
			cin>>x;
			add_to_head(x);
		}
		if(c=='D')
		{
			int k;
			cin>>k;
			if(k==0) head = ne[head];
			else remove(k-1);
		}
		if(c=='I')
		{
			int k,x;
			cin>>k>>x;
			insert(k-1,x);
		}
	}
	
	for(int i=head;i!=-1;i = ne[i])
		cout<<e[i]<<' ';
} 
