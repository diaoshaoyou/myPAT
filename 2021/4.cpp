#include<bits/stdc++.h>
using namespace std;
int S;
int maxServ=0,D=201;
vector<int> num;//�������ֽ�������У���С���������������ֵҲ��ȥ��һ�� 
void dfs(){
	int divide=0;
	sort(num.begin(),num.end());
	vector<int> repeat=num;
	int L=num.size();
	int M=num[L-1];//�����ķֽ� 
	for(int i=M/3+1;i<=(M>>1);i++){
		int newM;
		if(L>1) newM=max(M-i,num[L-2]);
		else newM=M-i;
		int newm=min(i,num[0]);
		if(newm*2>newM){
			divide=1;
			num.pop_back();
			num.emplace_back(i);
			num.emplace_back(M-i);
			dfs();//�������·ֽ�õ�������dfs 
			num=repeat;//�ǳ��ؼ�����Ϊ����ѭ�������numҪ�ָ���ԭ�� 
		}
	}
	if(!divide){//�ֵ�ͷ�ˣ�û���ٷ��� 
		if(num.size()>maxServ){
			maxServ=num.size();
			D=num[L-1]-num[0];
		} 
		else if(num.size()==maxServ&&D>(num[L-1]-num[0])){
			D=num[L-1]-num[0];
		}
	}
} 
int main(){
	cin>>S;
	num.emplace_back(S);
	dfs();
	cout<<maxServ<<" "<<D;
} 
