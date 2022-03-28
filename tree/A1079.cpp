#include<bits/stdc++.h>
using namespace std;
struct Node{
	int ID;
	vector<int> children;
	int product;
	int deep;//start from 0
};
Node List[100002];
double sum=0;
double P, r;
int N;
void dfs(int root){
	int L=List[root].children.size();
	if(L==0){//leaf
		double tmpSum=P;
		tmpSum*=pow(1+r/100, List[root].deep); //多用系统自带函数！！求乘方用pow就不超时，自己用循环算就超时 
//		for(int i=0;i<List[root].deep;i++){
//			tmpSum*=(1+r/100);
//		}
		sum+=tmpSum*List[root].product;
	}
	else{
		int c=0;
		for(int i=0;i<L;i++){
			c=List[root].children[i];
			List[c].deep=List[root].deep+1;//求deep和dfs求销售额可以同时进行 
			dfs(c);
		}
	}
}
int main(){
	int k, child, pro;
	cin>>N>>P>>r;
	for(int i=0;i<N;i++){
		cin>>k;
		List[i].ID=i;
		List[i].deep=0;
		if(k==0){
			cin>>pro;
			List[i].product=pro;
		}
		else{
			List[i].product=0;
			for(int j=0;j<k;j++){
				cin>>child;
				List[i].children.emplace_back(child);
			}
		}
	}
	
	dfs(0);
	printf("%.1f", sum);
}
