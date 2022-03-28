#include<bits/stdc++.h>
#define MAX 20000
using namespace std;
class Stu{
public:
	int assign;
	int final;
	int mid;
	double G;
	string ID;
	Stu(){
		assign=-1;
		final=-1;
		mid=-1;
		G=-1;
	}
	void getG(){
		if(mid>final){
			G=mid*0.4+final*0.6;
			int tmp=floor(G);
			G=G-tmp>=0.5?tmp+1:tmp;
			
		} 
		else{
			G=final;
		}
	}
};
map<string, int> Name;
int cnt=0;
Stu* List[MAX];
vector<Stu*> res;
int cmp(Stu *s1, Stu *s2){
	if(s1->G==s2->G){
		return s1->ID<s2->ID;
	}
	else return s1->G>s2->G;
}
int main(){
	int P,M,N,score;
	string str;
	cin>>P>>M>>N;
	for(int i=0;i<P;i++){
		cin>>str>>score;
		if(Name.find(str)==Name.end()){
			Name.emplace(pair<string,int>(str, cnt++));
			Stu *s=new Stu;
			s->assign=score;
			s->ID=str;
			List[Name[str]]=s; 
		}
		else{
			List[Name[str]]->assign=score;
			List[Name[str]]->ID=str;
		}
	}
	for(int i=0;i<M;i++){
		cin>>str>>score;
		if(Name.find(str)==Name.end()){
			Name.emplace(pair<string,int>(str, cnt++));
			Stu *s=new Stu;
			s->mid=score;
			s->ID=str;
			List[Name[str]]=s; 
		}
		else{
			List[Name[str]]->mid=score;
			List[Name[str]]->ID=str;
		}
	}
	for(int i=0;i<N;i++){
		cin>>str>>score;
		if(Name.find(str)==Name.end()){
			Name.emplace(pair<string,int>(str, cnt++));
			Stu *s=new Stu;
			s->final=score;
			s->ID=str;
			List[Name[str]]=s; 
		}
		else{
			List[Name[str]]->final=score;
			List[Name[str]]->ID=str;
		}
	}
	for(int i=0;i<cnt;i++){
		List[i]->getG();
		if(List[i]->assign>=200&&List[i]->G>=60){
			res.emplace_back(List[i]);
		}
	}	
	sort(res.begin(),res.end(),cmp);
	for(int i=0;i<res.size();i++){
		if(i>0) cout<<endl;
		cout<<res[i]->ID<<" "<<res[i]->assign<<" "<<res[i]->mid<<" "<<res[i]->final<<" ";
		printf("%.0f",res[i]->G);
	}
} 
