#include<bits/stdc++.h>
using namespace std;
int S;
int maxServ=0,D=201;
vector<int> num;//用数组存分解出的序列，从小到大排序，这样最大值也好去除一点 
void dfs(){
	int divide=0;
	sort(num.begin(),num.end());
	vector<int> repeat=num;
	int L=num.size();
	int M=num[L-1];//找最大的分解 
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
			dfs();//继续对新分解得到的序列dfs 
			num=repeat;//非常关键，因为还在循环里，所以num要恢复到原来 
		}
	}
	if(!divide){//分到头了，没法再分了 
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
