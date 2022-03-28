#include<bits/stdc++.h>
using namespace std;
struct Node{
	string name;
	int age;
	int wealth;
};
int cmp(Node *n1, Node *n2){
	if(n1->wealth==n2->wealth){
		if(n1->age==n2->age){
			return n1->name<n2->name;
		}
		else return n1->age<n2->age;
	}
	else return n1->wealth>n2->wealth;
}
int main(){
	int N,K,M,left,right;
	cin>>N>>K;
	Node *List[N];
	vector<Node*> res[K];
	for(int i=0;i<N;i++){
		Node *p=new Node;
		cin>>p->name>>p->age>>p->wealth;
		List[i]=p;
	}
	sort(List,List+N,cmp);
	for(int i=0;i<K;i++){
		int cnt=0;
		cin>>M>>left>>right;
		for(int j=0;j<N;j++){
			if(List[j]->age>=left&&List[j]->age<=right){
				cnt++;
				res[i].emplace_back(List[j]);
			}
			if(cnt==M)
				break;
		}
	}
	for(int i=0;i<K;i++){
		if(i>0) cout<<endl;
		cout<<"Case #"<<i+1<<":"<<endl;
		if(res[i].empty()) {
			cout<<"None";
			continue;
		}
		for(auto it=res[i].begin();it<res[i].end();it++){
			if(it>res[i].begin()) cout<<endl;
 			cout<<(*it)->name<<" "<<(*it)->age<<" "<<(*it)->wealth;
		}
	}
}
