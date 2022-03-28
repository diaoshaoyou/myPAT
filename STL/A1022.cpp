#include <bits/stdc++.h>
using namespace std;
struct Book{
	string info[6];
	//0: ID
	//1: title;
	//2: author;
	//3: keyword;
	//4: publisher;
	//5: year;
};
int cmp(string &A, string &B){
	if(A.compare(B)<0) return 1;
	else return 0;
}
int main(){
	string s;
	int M,N;
	cin>>M;
	vector<Book *> Library;
	getline(cin, s);//把cin遗留在缓冲区的回车去掉！！！！ 
	for(int i=0;i<M;i++){
		Book *b=new Book;
		for(int j=0;j<6;j++){
			getline(cin, s);
			b->info[j]=s;
		}
		Library.emplace_back(b);
	}
	cin>>N;
	getline(cin, s);//把cin遗留在缓冲区的回车去掉！！！ 
	int choice, Find=0;
	vector<Book *>::iterator it;
	vector<vector<string> > res(N);
	for(int i=0;i<N;i++){
		Find=0;
		getline(cin, s);
		res[i].emplace_back(s);
		choice=stoi(s.substr(0,1));
		s=s.substr(3, s.length()-3);
		for(it=Library.begin();it!=Library.end();it++){
			if(choice==3){//keywords
				if((*it)->info[choice].find(s)!=(*it)->info[choice].npos){//find
					Find=1;
					res[i].emplace_back((*it)->info[0]);
				}
			}
			else{
				if(s.compare((*it)->info[choice])==0){
					Find=1;
					res[i].emplace_back((*it)->info[0]);
				}
			}
		}
		if(Find==0) res[i].emplace_back("Not Found");
		else{
			sort(res[i].begin()+1, res[i].end(), cmp);
		}
	}
	
	//print:
	for(int i=0;i<N;i++){
		if(i>0) cout<<endl;
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j];
			if(j<res[i].size()-1) cout<<endl; 
		}
		
	}
}
