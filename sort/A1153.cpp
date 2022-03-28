#include<bits/stdc++.h>
using namespace std;
struct Node{
	string card;
	int site;
	int date;
	int ID;
	int score;
};
struct Site{
	int site;
	int amount;
};
int cmp1(Node *n1,Node *n2){
	if(n1->score==n2->score)
		return n1->card<n2->card;
	return n1->score>n2->score;
}
int cmp2(Site &s1, Site &s2){
	if(s1.amount==s2.amount){
		return s1.site<s2.site;
	} 
	else return s1.amount>s2.amount; 
}
Site List2[1000];
int main(){
	int N,M;
	cin>>N>>M;
	Node *List[N];
	
	vector<string> res[M];
	string str;
	int s,type,inst;
	for(int i=0;i<N;i++){
		cin>>str>>s;
		Node *p=new Node;
		p->card=str;
		p->site=stoi(str.substr(1,3));
		p->date=stoi(str.substr(4,6));
		p->ID=stoi(str.substr(10,3));
		p->score=s;
		List[i]=p;
	}
	sort(List,List+N,cmp1);
	char ch;
	for(int i=0;i<M;i++){
		cin>>type;
		res[i].emplace_back("Case "+to_string(i+1)+": "+to_string(type)+" ");
		if(type==1){
				cin>>ch;
				res[i][0]+=ch;
				for(int k=0;k<N;k++){
					if(List[k]->card[0]==ch){
						res[i].emplace_back(List[k]->card+" "+to_string(List[k]->score));
					}
				}
				if(res[i].size()==1) res[i].emplace_back("NA");
		}
		else if(type==2){
				cin>>inst;
				res[i][0]+=to_string(inst);
				int cnt=0,sum=0;
				for(int k=0;k<N;k++){
					if(List[k]->site==inst){
						sum+=List[k]->score;
						cnt++;
					}
				}
				if(cnt==0) res[i].emplace_back("NA");
				else res[i].emplace_back(to_string(cnt)+" "+to_string(sum));	
		}
		else if(type==3){
				cin>>str;//测试点1：日期可能0开头，用int类型没法读入0 
				inst=stoi(str);
				res[i][0]+=str;
				if(str.length()!=6){
					res[i].emplace_back("NA");continue;
				}
				for(int k=0;k<1000;k++) {//init
					List2[k].site=k;
					List2[k].amount=0;
				}
				for(int k=0;k<N;k++){
					if(List[k]->date==inst){
						List2[List[k]->site].amount++; 
					}
				}
				sort(List2,List2+1000,cmp2);
				for(int k=0;k<1000&&List2[k].amount>0;k++){
					res[i].emplace_back(to_string(List2[k].site)+" "+to_string(List2[k].amount));
				}
				if(res[i].size()==1) res[i].emplace_back("NA");
		}
	}
	for(int i=0;i<M;i++){
		if(i>0) printf("\n");
		for(auto it=res[i].begin();it<res[i].end();it++){
			if(it>res[i].begin()) printf("\n");
			printf("%s",(*it).c_str());//测试点3、4：不要用cout！！比printf慢好多,会超时！！ 
		}
	}
}
