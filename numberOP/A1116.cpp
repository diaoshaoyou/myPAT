#include<bits/stdc++.h>
using namespace std;
int isprime(int n){
	int tmp=sqrt(n);
	for(int i=2;i<=tmp;i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}
int main(){
	int N, id;
	cin>>N;
	map<int, int> list;
	set<int> S;
	for(int i=1;i<=N;i++){
		cin>>id;
		if(i==1){
			list.emplace(pair<int,int>(id, 0));
			continue;
		}
		if(isprime(i)){
			list.emplace(pair<int, int>(id, 1));
		}
		else{
			list.emplace(pair<int,int>(id, 2));
		}
	}
	int K;
	cin>>K;
	vector<int> query(K);
	for(int i=0;i<K;i++)
		cin>>query[i];
	for(int i=0;i<K;i++){
		id=query[i];
		if(list.find(id)==list.end()){//not exist
			printf("%04d: Are you kidding?", id);
		}
		else if(S.find(id)!=S.end()){
			printf("%04d: Checked", id);
		}
		else{
			S.emplace(id);
			switch(list[id]){
				case 0:
					printf("%04d: Mystery Award", id);
					break;
				case 1:
					printf("%04d: Minion", id);
					break;
				case 2:
					printf("%04d: Chocolate", id);
			}
		}
		if(i<K-1) cout<<endl;
	}
}
