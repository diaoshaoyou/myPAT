#include<bits/stdc++.h>
#define MAX 3000
using namespace std;
struct Node{
	string name;
	int T;
	int totalT;//gang总用时，刚开始=自身T 
	int num;//小弟数, 刚开始每个人是自身的小弟, num==1; 合并后小弟的num==0;head的num就是gang总人数 
	int head;//刚开始每个人都是自身的head 
};
map<string, int> Map;
Node List[MAX];
int cmp(int idx1, int idx2){
	return List[idx1].name<List[idx2].name;
}
int findHead(int person){
	while(1){
		if(List[person].head==person||List[person].head==-1)
			return person;
		person=List[person].head;
	}
}
void Union(int p1, int p2){
	int h1=findHead(p1);
	int h2=findHead(p2);
	if(h1==h2) return;
	int M=List[h1].T>List[h2].T?h1:h2;
	int m=(M==h1)?h2:h1;
	List[M].num+=List[m].num;
	List[m].num=0;
	List[M].totalT+=List[m].totalT;
	List[m].totalT=0;
	List[M].head=M;
	List[m].head=M;
}
int main(){
	int N,K,t;
	int total=0;
	string str1,str2;
	for(int i=0;i<MAX;i++){
		List[i].T=0;
		List[i].num=1;
		List[i].totalT=0;
		List[i].head=-1;
	}
	cin>>N>>K;
	int idx1,idx2;
	vector<int> in;
	for(int i=0;i<N;i++){
		cin>>str1>>str2>>t;
		if(Map.find(str1)==Map.end()){
			Map.emplace(pair<string, int>(str1,total));
			total++;
		}
		if(Map.find(str2)==Map.end()){
			Map.emplace(pair<string, int>(str2,total));
			total++;
		}	
		idx1=Map[str1];
		idx2=Map[str2];
		List[idx1].name=str1;
		List[idx1].T+=t;
		List[idx1].totalT=List[idx1].T;
		List[idx2].name=str2;
		List[idx2].T+=t;
		List[idx2].totalT=List[idx2].T;
		List[idx1].head=idx1;
		List[idx2].head=idx2;
		in.emplace_back(idx1);
		in.emplace_back(idx2);
	}
	for(int i=0;i<in.size()-1;i+=2){
		Union(in[i],in[i+1]);
	}

	vector<int> res;
	for(int i=0;i<total;i++){
		if(List[i].num>2 && (List[i].totalT>>1)>K){
			List[i].totalT=List[i].totalT>>1;
			res.emplace_back(i);
		}
	}
	sort(res.begin(),res.end(),cmp);
	cout<<res.size();
	for(int i=0;i<res.size();i++){
		cout<<endl<<List[res[i]].name<<" "<<List[res[i]].num;
		
	}
} 
