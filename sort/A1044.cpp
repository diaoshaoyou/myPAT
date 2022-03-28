#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
int minD=MAX;
int N, Money;
int cnt=0,rear=0;
int Sum[MAX];//前N个钻石之和 
int cmp(vector<int> &v1, vector<int> &v2){
	return v1[0]<v2[0];
}
void biSearch(int i){
	rear=-1;
	int left=i;
	int right=N;
	int mid;
	while(left<right){
		mid=(left+right)/2;
		if(Sum[mid]-Sum[i]>Money){
			right=mid-1;
		}
		else if(Sum[mid]-Sum[i]<Money){
			left=mid+1;
		}
		else{//==
			rear=mid;
			break;
		}
	}
	if(rear==-1){
		rear=Sum[right]-Sum[i]>=Money?min(N,right):min(N,right+1);
	}
}
int main(){
	cin>>N>>Money;
	fill(Sum,Sum+N+1,0);
	vector<int> res[MAX], tmpRes;
	for(int i=1;i<=N;i++){
		cin>>Sum[i];
		Sum[i]+=Sum[i-1];
	}
	for(int i=0;i<N;i++){
		tmpRes.clear();
		tmpRes.emplace_back(i+1);
		biSearch(i);
		tmpRes.emplace_back(rear);
		if(Sum[rear]-Sum[i]-Money>=0 && Sum[rear]-Sum[i]-Money<minD){
			minD=Sum[rear]-Sum[i]-Money;
			cnt=0;
			res[cnt++]=tmpRes;
		}
		else if(Sum[rear]-Sum[i]-Money>=0 && Sum[rear]-Sum[i]-Money==minD){
			res[cnt++]=tmpRes;	
		}
	}
	sort(res, res+cnt, cmp);
	for(int i=0;i<cnt;i++){
		if(i>0) cout<<endl;
		cout<<res[i][0]<<"-"<<res[i][1];
	}
}
