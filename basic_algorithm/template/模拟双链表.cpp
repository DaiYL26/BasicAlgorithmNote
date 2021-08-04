#include<iostream>
#include<string>
using namespace std;

const int N = 100010;
int e[N],l[N],r[N];
int m,idx;

void inti()
{
	r[0] = 1,l[1] = 0,idx = 2; //0表示左端点 1右端点 下标从2开始 
}

void add(int k,int x)
{
	e[idx] = x;
	r[idx] = r[k];
	l[idx] = k;
	l[r[k]] = idx; //和下面那部不能反 
	r[k] = idx ++;
}

void remove(int k)
{
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}

int main()
{
	inti();
	cin>>m;
	while(m--)
	{
		string op;
		int x,k;
		cin>>op;
		if(op=="L")
		{
			cin>>x;
			add(0,x);
		}
		else if(op=="R")
		{
			cin>>x;
			add(l[1],x);
		}
		else if(op=="D")
		{
			cin>>k;
			remove(k+1); //下标从2开始计数，所以要 + 1 
		}
		else if(op=="IL")
		{
			cin>>k>>x;
			add(l[k+1],x);
		}
		else if(op=="IR")
		{
			cin>>k>>x;
			add(k+1,x);
		}
	}
	
	for(int i=r[0];i!=1;i = r[i])
		cout<<e[i]<<' ';
} 
