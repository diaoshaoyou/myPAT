#include <bits/stdc++.h>

using namespace std;
struct Student{
	long long ID;
	int score;
	int loc;
	int finalR;
	int localR;
};
int cmp(Student *A, Student *B){
	if(A->score == B->score){
		return A->ID < B->ID;
	}
	else
		return A->score > B->score;
}
void getRank(vector<Student*> &vec, int choice){//choice==0, local; ==1, final
	int rpt=1;
	int rk=1;
	int i=0;
	for(i=0;i<vec.size()-1;i++){
		if(vec[i]->score == vec[i+1]->score){
			if(choice==0){
				vec[i]->localR=rk;
			}
			else{
				vec[i]->finalR=rk;
			}
			rpt++;
		}
		else{//!=
			if(choice==0){
				vec[i]->localR=rk;
			}
			else{
				vec[i]->finalR=rk;
			}
			rk+=rpt;
			rpt=1;
		}
	}
	//last one:
	if(choice==0){
		vec[i]->localR=rk;
	}
	else{
		vec[i]->finalR=rk;
	}
	
} 
int main(){
	int N, K, j;
	cin>>N;
	vector<struct Student*> info;
	for(int i=0;i<N;i++){
		cin>>K;
		vector<struct Student*> v;
		for(j=0;j<K;j++){
			struct Student *p=new Student;
			cin>>p->ID>>p->score;
			p->finalR=0;
			p->localR=0;
			p->loc=i+1;
			v.emplace_back(p);
		}
		//get local ranks
		sort(v.begin(), v.end(), cmp);
		getRank(v,0);
		
		info.insert(info.end(), v.begin(), v.end());//merge!!
	}
	//get final ranks
	sort(info.begin(),info.end(),cmp);
	getRank(info,1);
	

	//print
	int L=info.size();
	cout<<L<<endl;
	for(int i=0;i<L;i++){
		printf("%013lld ", info[i]->ID);//long longÊä³öÎª%lld 
		cout<<info[i]->finalR<<" "<<info[i]->loc<<" "<<info[i]->localR;
		if(i<L-1)
			cout<<endl;
	}	
	
}
