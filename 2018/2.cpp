#include<bits/stdc++.h>
using namespace std;
int isP(int s){
	if(s<=1) return 0;
	int tmp=sqrt(s);
	for(int i=2;i<=tmp;i++){
		if(s%i==0) return 0;
	}
	return 1;
}
int main(){
	int Size,N,M,num;
	cin>>Size>>N>>M;
	while(!isP(Size)){
		Size++;
	}
	vector<int> Hash(Size,-1);
	int incre=1,idx;
	for(int i=0;i<N;i++){
		cin>>num;
		incre=1;
		idx=num%Size;
		int tmp=idx;
		while(Hash[tmp]!=-1){
			tmp=(int)(idx+pow(incre,2))%Size;
			incre++;
			if(incre>Size) break;
		}
		if(Hash[tmp]!=-1) {
			cout<<num<<" cannot be inserted."<<endl; 
			continue;
		} 
		Hash[tmp]=num;
	}
	int sum=0;
	for(int i=0;i<M;i++){
		cin>>num;
		incre=1;
		idx=num%Size;
		int tmp=idx;
		while(Hash[tmp]!=num&&Hash[tmp]!=-1){
			tmp=(int)(idx+pow(incre,2))%Size;
			incre++;
			if(incre>Size) break;
		}
//		cout<<incre<<endl;
		sum+=incre;
	}
	printf("%.1f",1.0*sum/M);
}
