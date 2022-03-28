#include<bits/stdc++.h>
using namespace std;
struct query{
	int ID;
	int cnt;
};
int cmp(query &q1, query &q2){
	if(q1.cnt==q2.cnt) return q1.ID<q2.ID;
	return q1.cnt>q2.cnt;
}
int main(){
	int N,K,num;
	cin>>N>>K;
	vector<query> rec;
	set<int> S;
	query List[N+1];
	vector<vector<int> > res;
	for(int i=0;i<N+1;i++){
		List[i].ID=i;
		List[i].cnt=0;
	}
	for(int i=0;i<N;i++){
		cin>>num;
		if(i==0) {
			List[num].cnt++;
			rec.emplace_back(List[num]);
			S.emplace(num);
		}
		else{
			vector<int> v={num};
			for(auto it=rec.begin();it!=rec.end();it++){
				v.emplace_back(it->ID);
			}
			res.emplace_back(v);
			//update
			List[num].cnt++;
			if(S.find(num)==S.end()){
				if(rec.size()<K){
					rec.emplace_back(List[num]);
					S.emplace(num);
				} 
				else if(rec.back().cnt<List[num].cnt){
					S.erase(rec.back().ID);
					rec.pop_back();
					rec.emplace_back(List[num]);
					S.emplace(num);
				}
				else if(rec.back().cnt==List[num].cnt&&rec.back().ID>num){
					S.erase(rec.back().ID);
					rec.pop_back();
					rec.emplace_back(List[num]);			
					S.emplace(num);		
				}
			}
			else{
				for(int k=0;k<rec.size();k++){
					if(rec[k].ID==num) {
						rec[k].cnt++;
						break;
					}
				}
			}
			sort(rec.begin(),rec.end(),cmp);
			
		}
	}
	for(int i=0;i<res.size();i++){
		if(i>0) cout<<endl;
		cout<<res[i][0]<<":";
		for(int j=1;j<res[i].size();j++){
			cout<<" "<<res[i][j];
		}
	} 
}
