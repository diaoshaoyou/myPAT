 #include<bits/stdc++.h>
 using namespace std;
 int main(){
 	int N,tmp;
 	cin>>N;
 	set<int> num;
 	for(int i=0;i<N;i++){
	 	cin>>tmp;
	 	if(tmp>0) num.emplace(tmp);
	}
	if(num.empty()){
		cout<<1;
		return 0;
	} 
	int j=1;
	for(auto it=num.begin();it!=num.end();it++){
		if(*it>j){
			break;
		}
		else j++;
	}
	cout<<j;
 }
