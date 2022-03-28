#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<char> S1;
	set<char> S2;
	char ch;
	scanf("%c", &ch);
	while(ch!='\n'){
		S1.emplace_back(ch);
		scanf("%c", &ch);
	}
	scanf("%c", &ch);
	while(ch!='\n'){
		S2.insert(ch);
		scanf("%c", &ch);
	}
	for(auto it=S1.begin();it!=S1.end();it++){
		if(S2.find(*it)==S2.end()){
			printf("%c", *it);
		}
	}
}
