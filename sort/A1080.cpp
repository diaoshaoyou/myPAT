//select：扫描所有学生，若他选中的学校名额有剩余，则加上。不需要另外从学校角度考虑 
#include <bits/stdc++.h>
using namespace std;

class Student{
public:
	int ID;
	int GE;
	int GI;
	double Gtotal;
	int rank;
	vector<int> prefer;
	
	Student(){
		GE=0;
		GI=0;
		Gtotal=0;
		rank=-1;
	}

};
int N, M, K;
vector<Student *> persons;

int cmp1(Student *A, Student *B){
	if(A->Gtotal == B->Gtotal){
		return A->GE > B->GE;
	}
	else 
		return A->Gtotal > B->Gtotal;
}
int cmp2(int A, int B){
	return A < B;
}
int main(){
	cin>>N>>M>>K;
	int quota[M];
	int remain[M];
	int lastRank[M];
	int tmp;
	
	for(int i=0;i<M;i++){
		cin>>quota[i];
		remain[i]=quota[i];
		lastRank[i]=-1;
	}	

	for(int i=0;i<N;i++){
		Student *p=new Student;
		p->ID=i;
		cin>>p->GE>>p->GI;
		for(int j=0;j<K;j++){
			cin>>tmp;
			p->prefer.emplace_back(tmp);
		}
		p->Gtotal=(p->GE+p->GI)*1.0/2;
		persons.emplace_back(p);
	}
	//get rank
	sort(persons.begin(), persons.end(), cmp1);
	int r=1, repeat=1;
	for(int i=0;i<N-1;i++){
		if(persons[i]->Gtotal == persons[i+1]->Gtotal && persons[i]->GE == persons[i+1]->GE){
			repeat++;
			persons[i]->rank=r;
		}
		else{
			persons[i]->rank=r;
			r+=repeat;
			repeat=1;
		}
	}
	persons[N-1]->rank=r;
	
	//select!!!
	int L=0,idx=0,flag=0;
	vector<vector<int> > res;
	for(int k=0;k<M;k++){
		res.emplace_back(vector<int> ());//push empty vector into res
	}
	for(int i=0;i<N;i++){
		L=persons[i]->prefer.size();
		flag=0;
		for(int j=0;j<L;j++){
			if(flag) break;//already find school
			idx=persons[i]->prefer[j];
			if( remain[idx]>0){//have remaining
				remain[idx]--;
				res[idx].emplace_back(persons[i]->ID);
				flag=1;
				lastRank[idx]=persons[i]->rank;
			}
			else if(lastRank[idx]==persons[i]->rank){//remain[idx]==0
				flag=1;
				res[idx].emplace_back(persons[i]->ID);
			}
		}
	}	
	//debug: 
//	for(int i=0;i<N;i++){
//		cout<<persons[i]->ID<<"# "<<persons[i]->rank<<"# ";
//		for(int j=0;j<K;j++){
//			cout<<persons[i]->prefer[j]<<" ";
//		}
//		cout<<endl;
//	}
	//debug end
	
	//print
	for(int i=0;i<M;i++){
		sort(res[i].begin(), res[i].end(), cmp2);
		L=res[i].size();
		if(L==0){
			cout<<endl;
			continue;
		}
		for(int j=0;j<L;j++){
			cout<<res[i][j];
			if(j<L-1)
				cout<<" ";
		}
		if(i<M-1) cout<<endl;
	}
}
