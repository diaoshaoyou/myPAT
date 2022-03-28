#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
int N,D, remain, maxCnt;
vector<int> Item;
int table[1000001];
int main(){
	cin>>N>>D;
	remain=D;
	fill(table,table+MAX,0);
	int tmp;
	for(int i=0;i<N;i++){
		cin>>tmp;
		Item.emplace_back(tmp);
	}
	for(int i=0;i<N;i++){
		cin>>tmp;
		for(int j=0;j<N;j++){
			if(Item[j]-tmp>D) continue;
			table[Item[j]-tmp]++;
		}
	}
	int sum=0,flag=0;
	for(int i=0;i<=D;i++){
		tmp=table[i]*i;
		if(sum+tmp>D) {
			int j=1;
			while(j<table[i]){
				if(sum+i*j>D) break;
				j++;
				maxCnt++;
			}
			sum+=i*(j-1);
			remain=D-sum;
			flag=1;
			break;
		}
		maxCnt+=table[i];
		sum+=tmp;
	}

	if(flag==0){
		remain=D-sum;
	}
	cout<<maxCnt<<" "<<remain;
	
}
