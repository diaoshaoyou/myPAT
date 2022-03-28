#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
//long long BIT[MAX];
//struct Node{
//	long long val;
//	int ID;
//};
//inline int lowbit(int x){
//	return x&(-x);
//}
//int getSum(vector<Node*> &Q, int ID){
//	long long sum=0;
//	while(ID>0){
//		sum+=BIT[ID];
//		ID-=lowbit(ID);
//	}
//	return sum;
//}
//void update(vector<Node*> &Q, int ID, int v){
//	while(ID<MAX){
//		BIT[ID]+=v;
//		ID+=lowbit(ID);
//	}
//}
int main(){
	int K,N,num;
	cin>>N>>K;
//	fill(BIT,BIT+MAX,0);
//	vector<Node *> Q(N+1);
	int top[K];
	int cnt=0;
	for(int i=1;i<=N;i++){
		cin>>num;
		if(cnt<K) top[cnt++]=num;
		else {
			int m=top[0];
			int idx=0;
			for(int j=1;j<K;j++){
				if(m>top[j]){
					m=top[j];
					idx=j;
				}
			}
			if(m<num) {
				top[idx]=num;
			}
		}
	}
	
	sort(top,top+cnt,greater<int>());
	for(int i=0;i<cnt;i++){
		if(i>0) cout<<" ";
		cout<<top[i];
	}
}
