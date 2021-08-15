#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm> 
#include<queue>
#include<windows.h>
#include<unordered_map>
using namespace std;

typedef pair<int,int> P;

P path[500000];
int fact[10],pk[500000],num=0;
bool st[500000];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

struct MP{
	int x,y,k;
	char str[10];
	void set()  { x = k/3,y = k%3; } //һά����ת���ɶ�ά 
	void setk() { k = x*3 + y; } //��ά����ת����һά 
};
typedef pair<MP,int> PII;
int permutation_hash(char str[]) //ȫ���й�ϣ 
{
	int hash_val = 0;
	for(int i = 0;i<9;i++)
	{
		int cnt = 0;
		for(int j = 0;j<i;j++)
			if(str[j] > str[i]) //������ж� 
				cnt++;
		hash_val += cnt * fact[i]; //ȫ���й�ϣ���� 
	}
	return hash_val;
}
 
int bfs(PII start)
{
	queue<PII> q;
	q.push(start);
	st[permutation_hash(start.first.str)] = 1;
	int ans_hash = permutation_hash("12345678x"); //�𰸹�ϣֵ
	char s[10]; //��ʱ��ͼ 
	while(q.size())
	{
		auto t = q.front();
		int pre_step = t.second, step;
		int pre_key = permutation_hash(t.first.str);
		MP p = t.first;
		
		strcpy(s,t.first.str); //������ͼ 
		q.pop();				
	
		for(int i=0;i<4;i++)
		{
			int xx = t.first.x + dx[i];
			int yy = t.first.y + dy[i];
			if(xx>=0 && xx<3 && yy>=0 && yy<3) //�ж�Խ�� 
			{
				p.x = xx,p.y = yy,p.setk(); //���� p �ṹ�� 
				swap(s[p.k],s[t.first.k]); //�����ƶ���ĵ�ͼ 
				int key = permutation_hash(s);	//�����ƶ���Ĺ�ϣֵ 
				if(!st[key])	//û�г��Թ� 
				{
					step = pre_step + 1; //��ǰ���� 
					path[key] = {pre_key,p.k};
					if(key == ans_hash)	return step;
					st[key] = true;
					strcpy(p.str,s); //���µ�ͼ			
					q.push({p,step});
				}
				swap(s[p.k],s[t.first.k]); //��ԭ��ͼ 
			}
		}
	}
	return -1;
}

void printpath(int key)
{
	if(path[key].first != 0)	printpath(path[key].first);
	//cout<<path[key].second<<' ';
	pk[num++] = path[key].second;	
}

int main()
{
	MP start;
	fact[0] = 1;
	for(int i=1;i<=9;i++)	fact[i] = fact[i-1] * i; //Ԥ����׳�ֵ 
	
	for(int i=0;i<9;i++)
	{
		cin>>start.str[i];
		if(start.str[i] == 'x')	start.k =  i;
	}
	start.str[9] = '\0';
	start.set();
	int front_key = permutation_hash(start.str);
	path[front_key] = {0,start.k};
	
	int t = bfs({start,0});
	cout<<"����ԭ�����ٲ�����"<<t<<endl;
	printpath(0);
	char mp[10];
	strcpy(mp,start.str);
	if(t == -1)
	{
		cout<<"�޷���ԭ"<<endl;
		return 0;
	} 
	for(int i=0;i<=num;i++)
	{
		Sleep(500);
		system("cls");
		
		for(int i=0;mp[i];i++)
		{
			printf("%3c",mp[i]);
			if(i%3 == 2)	cout<<endl<<endl;
		}
		if(i)
		{
			swap(mp[pk[i]],mp[pk[i-1]]);
		}
		cout<<endl;
	}
} 
