#include <bits/stdc++.h>
using namespace std;
class Item{
public:
	int ID;
	int frequency;
	
	Item(){
		frequency=0;
		ID=0;
	}
};
int cmp(Item *A, Item *B){
	if(A->frequency == B->frequency){
		return A->ID < B->ID;
	}
	else	return A->frequency > B->frequency;
}
int main(){
	int N,K;
	cin>>N>>K;
	vector<Item*> List(N+1);
	vector<Item*> rec;
	for(int i=0;i<N+1;i++){
		Item *it=new Item;
		it->ID=i;
		List[i]=it; 
	}

	vector<string> res;
	string str;
	int id=0,j=1;
	int L;
	for(int i=0;i<N;i++){
		cin>>id;
		str=to_string(id)+": ";
		if(K==0) {
			res.emplace_back(str);
			continue;	
		}
		if(i==0){
			List[id]->frequency++;
			rec.emplace_back(List[id]);
		}
		else{
			L=rec.size();
			for(j=0;j<L;j++){
				str+=to_string(rec[j]->ID);
				if(j<L-1) str+=" ";
			}
			res.emplace_back(str);
			
			//update:
			List[id]->frequency++;
			set<Item*> s(rec.begin(), rec.end());
			if(s.find(List[id])==s.end()){//原来不在rec中.测试点5：rec记录的item不能有重复！！！ 
				if(L==K){
					if(List[id]->frequency > rec.back()->frequency || (List[id]->frequency==rec.back()->frequency&&id<rec.back()->ID)){
							rec.pop_back();
							rec.emplace_back(List[id]);
					}
				}
				else{
					rec.emplace_back(List[id]);	
				}
			}
			sort(rec.begin(), rec.end(), cmp);
		}
		
	}
	for(auto s=res.begin();s!=res.end();s++){
		if(s>res.begin()) cout<<endl;
		cout<<*s;
	}
}
