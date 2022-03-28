#include<bits/stdc++.h>
using namespace std;
int N; 
vector<int> List[100002];
int minDeep=100010, minN=0;
void getDeep(int root, int curDeep){
	if(!List[root].empty()){
		for(auto it=List[root].begin(); it!=List[root].end(); it++){
			getDeep(*it, curDeep+1);
		}
	}
	else{//leaf
		if(curDeep<minDeep){
			minDeep=curDeep;
			minN=1;
		}
		else if(curDeep==minDeep){
			minN++;
		}
	}
}
int main(){
	double P, r;
	cin>>N>>P>>r;
	int k=0, child;
	for(int i=0;i<N;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>child;
			List[i].emplace_back(child);
		}
	}
	
	getDeep(0, 1);
	double sum=P*pow(1+r/100, minDeep-1);
	printf("%.4f %d", sum, minN);
}
