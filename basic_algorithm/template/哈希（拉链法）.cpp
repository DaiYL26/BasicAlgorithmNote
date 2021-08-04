#include<iostream> 
#include<string.h>
using namespace std;
const int N = 100003;
int hash_[N],val[N],ne[N],idx;

void add(int x)
{
	int k = (x % N + N) % N;
	val[idx] = x;
	ne[idx] = hash_[k];
	hash_[k] = idx++;
}

bool query(int x)
{
	int k = (x%N + N)%N;
	for(int i=hash_[k];i!=-1;i = ne[i])
	{
		if(val[i]==x)
			return true;
	}
	return false;
}

int main()
{
	int n,x;
	cin>>n;
	memset(hash_,-1,sizeof(hash_));
	while(n--)
	{
		char op[2];
		cin>>op>>x;
		if(op[0]=='I')
		{
			add(x);
		}
		else
		{
			if(query(x))
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}
}
