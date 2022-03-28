#include<bits/stdc++.h>
using namespace std;
struct Stu{
	int ID;
	int E;
	int I;
	int G;
	int Rank;
	vector<int> prefer;
};
int cmp(Stu *p1, Stu *p2){
	if(p1->G==p2->G) return p1->E>p2->E;
	else return p1->G>p2->G;
}
int main(){
	int N,M,K,s,tmp;
	cin>>N>>M>>K;
	vector<int> quota;
	vector<Stu*> List;
	vector<int> admit[M];//学校招进的人
	vector<int> lastRank(M,0);//学校招进的人中最低的rank 
	for(int i=0;i<M;i++) {
		cin>>tmp;
		quota.emplace_back(tmp);
	}
	if(N==0){
		for(int i=1;i<M;i++)
			cout<<endl;
		return 0;
	}	
	for(int i=0;i<N;i++){
		Stu *p=new Stu;
		p->ID=i;
		cin>>p->E>>p->I;
		p->G=p->E+p->I;
		for(int j=0;j<K;j++) {
			cin>>s;
			p->prefer.emplace_back(s);
		}
		List.emplace_back(p);
	}
	sort(List.begin(),List.end(),cmp);
	//get rank
	List[0]->Rank=1;
	for(int i=1;i<N;i++){
		if(List[i]->G==List[i-1]->G&&List[i]->E==List[i-1]->E)
			List[i]->Rank=List[i-1]->Rank;
		else 
			List[i]->Rank=i+1;
	}

	for(int i=0;i<N;i++){
		for(auto it=List[i]->prefer.begin();it<List[i]->prefer.end();it++){
			if(admit[*it].size()<quota[*it]){//还有余额 
				admit[*it].emplace_back(List[i]->ID);
				lastRank[*it]=lastRank[*it]<List[i]->Rank?List[i]->Rank:lastRank[*it];
				break;
			}
			else if(admit[*it].size()>=quota[*it]&&lastRank[*it]==List[i]->Rank){//没余额，但是rank一样 
				admit[*it].emplace_back(List[i]->ID);
				break;
			}
		}
	}
	for(int i=0;i<M;i++){
		if(admit[i].empty()) {//一定要判断空的情况，不然格式错误。。 
			cout<<endl;
			continue;
		}
		sort(admit[i].begin(),admit[i].end());
		for(int j=0;j<admit[i].size();j++){
			if(j>0) cout<<" ";
			cout<<admit[i][j];
		}
		if(i<M-1) cout<<endl;
	}
} 
