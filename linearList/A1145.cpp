#include<bits/stdc++.h>
using namespace std;
int isPrime(int n){
	int tmp=sqrt(n);
	int flag=1;
	for(int i=2;i<=tmp;i++){
		if(n%i==0){
			flag=0;
			break;
		}
	}
	return flag;
}
int main(){
	int Size, N ,M, num, idx,incre;
	cin>>Size>>N>>M;
	while(!isPrime(Size)){
		Size++;
	}
	int List[Size];
	vector<int> uninsert;
	int tmp, flag=1, tmpT=0;
	double T=0;
	fill(List, List+Size, -1);
	for(int i=0;i<N;i++){
		cin>>num;
		incre=1;
		idx=num%Size;
		tmp=idx;
		flag=1;
		while(List[tmp]!=-1){
			tmp=(idx+incre*incre)%Size;
			incre++;
			if(incre>=Size){//题目没仔细说，盲猜一个上限=Size 
				flag=0;
				break;
			}
		}
		if(flag)
			List[tmp]=num;
		else
			uninsert.emplace_back(num);
	}
	for(int i=0;i<M;i++){
		cin>>num;
		tmpT=0;
		idx=num%Size;
		tmp=idx;
		incre=1;
		while(List[tmp]!=num && List[tmp]!=-1){
			tmpT++;
			tmp=(idx+incre*incre)%Size;
			incre++;
			if(tmpT>=Size) {
				break;
			}
		}
		T+=tmpT+1;
	}
	for(auto it=uninsert.begin(); it<uninsert.end();it++){
		cout<<*it<<" cannot be inserted."<<endl;
	}	
	T=T/M;
	printf("%.1f", T);
}
