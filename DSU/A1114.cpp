//尝试建图做，用dfs求连通分量，这样会内存超出 
//只能又回到并查集 
#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
struct Node{
	int ID;
	float area;
	float estate;
	int num;
};
Node List[MAX];
int Rep[MAX];//家族代表人，ID最小的那人。初始时=自身 
set<int> total;
vector<int> res;
int cmp(int idx1, int idx2){
	if(List[idx1].area == List[idx2].area){
		return List[idx1].ID < List[idx2].ID;
	}
	else{
		return List[idx1].area > List[idx2].area;
	}
}
int findRep(int id){
	while(1){
		if(id==Rep[id]||Rep[id]==-1) break;	//有些人未被输入，r==-1
		id=Rep[id];
	}
	return id;
}
void Union(int id1,int id2){
	int r1=findRep(id1);
	int r2=findRep(id2);
	if(r1!=r2){
		int m=r1>r2?r2:r1;
		int M=r1>r2?r1:r2;
		Rep[M]=m;
	} 
} 
int main(){
	int N, k,child, id,p1,p2,cnt=0;
	fill(Rep,Rep+MAX,-1);
	cin>>N;
	for(int i=0;i<MAX;i++){
		List[i].area=0;
		List[i].estate=0;
		List[i].num=1;
		List[i].ID=i;
	}
	if(N<=0) return 0;
	//read in
	for(int i=0;i<N;i++){
		cin>>id>>p1>>p2>>k;
		total.emplace(id);
		if(p1!=-1){
			total.emplace(p1);
			Union(p1,id);
		}
		if(p2!=-1){
			total.emplace(p2);
			Union(p2,id);
		}
		
		for(int j=0;j<k;j++){
			cin>>child;
			total.emplace(child);
			Union(child,id);
		}
		cin>>List[id].estate>>List[id].area;
	}
	//统计 
	for(auto it=total.begin();it!=total.end();it++){
		int rep=findRep(*it);
		res.emplace_back(rep);
		if(rep!=*it){ 
			List[rep].area+=List[*it].area;
			List[rep].estate+=List[*it].estate;   
			List[rep].num++;    
		}                        
	}
	set<int> tmp(res.begin(),res.end());
	res.assign(tmp.begin(),tmp.end());//消除res中的重复
	//print out 
	int L=res.size();
	for(int i=0;i<L;i++){
		List[res[i]].area/=List[res[i]].num;
		List[res[i]].estate/=List[res[i]].num;
		cnt++;
	}
	sort(res.begin(),res.end(),cmp);
	cout<<cnt<<endl;
	for(int i=0;i<L;i++){
		if(i>0) cout<<endl;
		printf("%.04d %d %.3f %.3f", List[res[i]].ID, List[res[i]].num, List[res[i]].estate, List[res[i]].area);
	}
}
