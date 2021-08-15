#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 510,M = 1e5 + 10;

int h[N],e[M],ne[M],idx;
int n1,n2,m;
bool st[N];
int match[N]; //�����ӣ�n2���ɹ�ƥ�����

void add(int a,int b)
{
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

bool find(int u)
{
	for(int i=h[u]; ~i ;i = ne[i]) //ɨ��n1��ÿ���������ӣ�
	{
		int j = e[i];
		if(!st[j]) //ûɨ����������ƥ�䣨�кøУ�
		{
			st[j] = true; //���һ�£��ⲻ��ǶԺ���� n1 ��ǰ��Ķ���ʮ����Ҫ
			if(match[j] == 0 || find(match[j])) //n2û��������û���󣩻��� 
			{									//���ӵĶ����б�̥�����ӷ��ֺ�����ԭ����� u ƥ���ˣ�
				match[j] = u; //������ j �Ķ����ó� u
 				return true; //�õ� u ƥ��ɹ�
			}
		}
	}
	return false;
}

int hungary()
{
	int res = 0;
	for(int i=1;i<=n1;i++)
	{
		memset(st,0,sizeof st); //�ⲽ����n1�������ֵ���ǽ�ŵ�����~~
		if(find(i))	res ++; // ƥ�䵽һ��~~ ���ƥ��res ++
	}
	return res;
}

int main()
{
	cin>>n1>>n2>>m;
	
	memset(h,-1,sizeof h);
	
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
	}
	
	cout<<hungary();
}
