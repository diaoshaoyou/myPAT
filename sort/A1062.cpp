#include <bits/stdc++.h>
using namespace std;

struct person{
	int ID;
	int virtue;
	int talent;
	int total;
};
int cmp(person *A, person *B){
	if(A->total==B->total){
		if(A->virtue == B->virtue){
			return A->ID < B->ID;
		}
		else return A->virtue > B->virtue;
	}
	else return A->total > B->total;
}
int main(){
	vector<person*> Sage, Noble, Fool, Rest;
	int N,L,H;
	int id, vir,tal;
	int M=0;
	cin>>N>>L>>H;
	for(int i=0;i<N;i++){
		cin>>id>>vir>>tal;
		if(tal<L || vir<L){
			continue;
		}
		M++;
		person *p=new person;
		p->ID=id;
		p->talent=tal;
		p->virtue=vir;
		p->total=tal+vir;
		if(vir>=H && tal>=H){//sage
			Sage.emplace_back(p);
		}
		else if(tal<H && vir>=H){
			Noble.emplace_back(p);
		}
		else if(vir<H && tal<H && vir>=tal){
			Fool.emplace_back(p);
		}
		else {
			Rest.emplace_back(p);
		}
	}
	sort(Sage.begin(), Sage.end(), cmp);
	sort(Noble.begin(), Noble.end(), cmp);
	sort(Rest.begin(), Rest.end(), cmp);
	sort(Fool.begin(), Fool.end(), cmp);
	
	//print:
	cout<<M<<endl;
	int i=0;
	int len=Sage.size();
	for(i=0;i<len;i++)
		cout<<Sage[i]->ID<<" "<<Sage[i]->virtue<<" "<<Sage[i]->talent<<endl;
	len=Noble.size();
	for(i=0;i<len;i++)
		cout<<Noble[i]->ID<<" "<<Noble[i]->virtue<<" "<<Noble[i]->talent<<endl;
	len=Fool.size();
	for(i=0;i<len;i++)
		cout<<Fool[i]->ID<<" "<<Fool[i]->virtue<<" "<<Fool[i]->talent<<endl;
	len=Rest.size();
	for(i=0;i<len;i++){
		cout<<Rest[i]->ID<<" "<<Rest[i]->virtue<<" "<<Rest[i]->talent;
		if(i<len) cout<<endl;
	}
}
