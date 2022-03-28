#include<bits/stdc++.h>
using namespace std;
int N;
int List[21][2];
int res=1;
int main(){
	cin>>N;
	fill(List[0], List[0]+2*21, -1);
	string c1, c2;
	set<int> S;
	for(int i=0;i<N;i++){
		S.emplace(i);
	}
	for(int i=0;i<N;i++){
		cin>>c1>>c2;
		if(c1.compare("-")!=0){
			List[i][0]=stoi(c1);
			S.erase(stoi(c1));
		}
		if(c2.compare("-")!=0){
			List[i][1]=stoi(c2);
			S.erase(stoi(c2));
		}
	}
	auto it=S.begin();
	int root=*it;
	int last=0, cnt=0, tmp=N>>1;
	int cur=root;
	queue<int> Q;
	Q.push(cur);
	while(!Q.empty()){
		cur=Q.front();
		Q.pop();
		cnt++;
		if(cnt<=tmp){
			if(List[cur][0]!=-1){
				Q.push(List[cur][0]);
			}
			else {
				res=0;
				break;
			}
			if(List[cur][1]!=-1){
				Q.push(List[cur][1]);
			}	
			else if(cnt<tmp){
				res=0;
				break;
			}
		}
	}
	last=cur;
	if(res==1){
		cout<<"YES "<<last;
	}
	else{
		cout<<"NO "<<root;
	}
}
