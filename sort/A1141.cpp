#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
struct Node{
	int Rank;
	double sum;
	string name;
	int num;
};
map<string, int> School;
int cmp(Node *n1, Node *n2){
	if((int)n1->sum==(int)n2->sum){
		if(n1->num==n2->num){
			return n1->name<n2->name;
		}
		else return n1->num<n2->num;
	}
	else return (int)n1->sum>(int)n2->sum;
}
int main(){
	int N,cnt=0;
	string str,ID;
	int score;
	double rate;
	cin>>N;
	Node *List[MAX];
	for(int i=0;i<MAX;i++) {
		List[i]=NULL;
	}
	for(int i=0;i<N;i++){
		cin>>ID>>score>>str;
		if(ID[0]=='T') rate=1.5;
		else if(ID[0]=='A') rate=1;
		else if(ID[0]=='B') rate=1/1.5;
		transform(str.begin(),str.end(),str.begin(),::tolower);
		if(School.find(str)==School.end()){
			School.emplace(pair<string,int>(str,cnt++));
			Node *p=new Node;
			p->num=1;
			p->sum=score*rate;
			p->name=str;	
			List[School[str]]=p;		
		}
		else{
			List[School[str]]->num++;
			List[School[str]]->sum+=score*rate;
			List[School[str]]->name=str;
		}
	}
	if(cnt==0) {
		cout<<0;
		return 0;
	}
	sort(List,List+cnt,cmp);
	List[0]->Rank=1;
	for(int i=1;i<cnt;i++){
		if((int)List[i]->sum==(int)List[i-1]->sum){
			List[i]->Rank=List[i-1]->Rank;
		}
		else
			List[i]->Rank=i+1;
	}
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++){
		if(i>0) cout<<endl;
		cout<<List[i]->Rank<<" "<<List[i]->name<<" "<<(int)List[i]->sum<<" "<<List[i]->num;
	}
} 
