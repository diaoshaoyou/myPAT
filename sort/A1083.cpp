#include <bits/stdc++.h>
using namespace std;
struct Record{
	string name;
	string ID;
	int score;
}; 
int cmp(Record *A, Record *B){
	return A->score > B->score;
}
	
int main(){
	vector<Record*> List;
	int N, score1, score2;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		Record *pr=new Record;
		cin>>pr->name>>pr->ID>>pr->score;
		List.emplace_back(pr);
	} 
	cin>>score1>>score2;
	sort(List.begin(), List.end(), cmp);
	int start=N, rear=-1;
	for(int i=0;i<N;i++){
		if( List[i]->score<=score2 && List[i]->score>=score1){
			if(i<start) start=i;
			if(i>rear) rear=i;
		}
	}
	if(start==N) cout<<"NONE";
	for(int i=start; i<=rear;i++){
		cout<<List[i]->name<<" "<<List[i]->ID;
		if(i<rear){
			cout<<endl;
		} 
	}
}
