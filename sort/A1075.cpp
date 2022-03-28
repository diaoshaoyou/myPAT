#include <bits/stdc++.h>
#define MAX 6
#define max_rank 10001
using namespace std;
int N,M,K;
int mark[MAX];

class User{
public:
	int ID;
	int total;
	int score[MAX];
	int rank;
	int perfectN;
	bool show; 
	
	User(){
		show=false;
		perfectN=0;
		rank=max_rank;
		total=0;
		for(int i=0;i<MAX;i++){
			score[i]=-2; //==-2, never submit; ==-1, compile error; ==0, wrong result
		}
	}
	void getTotal(){
		for(int i=0;i<K;i++){
			if(score[i]>=0){
				show=true;
				total+=score[i];
			}
			if(score[i]==mark[i]){
				perfectN++;
			}
		}	
	} 
};
int cmp(User *A, User *B){
	if(A->total == B->total){
		if(A->perfectN==B->perfectN){
			return A->ID < B->ID;
		}
		else{
			return A->perfectN > B->perfectN;
		}
	}
	else 
		return A->total > B->total;
}
int main(){
	cin>>N>>K>>M;
	vector<User *> List(N+1);//从1开始有效 
	for(int i=0;i<N+1;i++){//提前为每个都设置好空间和初值，用ID做下标，这样不用反复查找当前读入是否出现过 
		User *u=new User;
		u->ID=i;
		List[i]=u;
	}
	for(int i=0;i<K;i++){
		cin>>mark[i];
	}
	int id;
	int pid=-1, s=0;
	for(int i=0;i<M;i++){
		cin>>id>>pid>>s;
//		cout<<id<<endl;
		if(s>List[id]->score[pid-1])
			List[id]->score[pid-1]=s;
//		if(s>=0)
//			List[id]->show=true;	
	}
	
	for(int i=1;i<N+1;i++){
		List[i]->getTotal();
	}
	
	//get rank 
	sort(List.begin()+1, List.end(), cmp);
	//更优解：
	List[1]->rank=1;
	for(int i=2;i<N+1;i++){
		List[i]->rank=i;
		if(List[i]->total == List[i-1]->total){
			List[i]->rank=List[i-1]->rank;
		}
	} 
/*	int r=1, rpt=1;
	for(int i=0;i<L-1;i++){
		if(List[i]->total !=List[i+1]->total){
			List[i]->rank=r;
			r+=rpt;
			rpt=1;
		}
		else{//==
			List[i]->rank=r;
			rpt++;
		}
	}
	List[L-1]->rank=r; */
	
	for(int i=1;i<N+1;i++){
		if(List[i]->show==false){//所有score都是-1或-2，原先没过 
			continue;//not shown on the list
		}
		cout<<List[i]->rank<<" ";
		printf("%05d", List[i]->ID);
		cout<<" "<<List[i]->total<<" ";
		for(int j=0;j<K;j++){
			if(List[i]->score[j]>=0){
				cout<<List[i]->score[j];
			}
			else if(List[i]->score[j]==-1){
				cout<<"0";
			}
			else{
				cout<<"-";
			}
			if(j<K-1){
				cout<<" ";
			}
		}
		if(i<N)
			cout<<endl;
	}
}
