#include<iostream>
#include<string.h>
using namespace std;

const int N = 200003,null = 0x3f3f3f3f;

int hash_[N];

int insert_hash(int x)
{
	int k = (x % N + N) % N;
	while(hash_[k]!=null && hash_[k]!=x)
	{
		k++;
		if(k==N)
			k = 0;
	}
	
	return k;
}

int main()
{
	int n,x;
	cin>>n;
	
	memset(hash_,0x3f,sizeof(hash_));
	
	while(n--)
	{
		char op[2];
		cin>>op>>x;
		
		if(op[0]=='I')
		{
			int k = insert_hash(x);
			hash_[k] = x;
		}
		else
		{
			int k = insert_hash(x);
			if(hash_[k]!=null)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
		
	}
}
