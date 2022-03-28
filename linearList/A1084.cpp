#include<bits/stdc++.h>
using namespace std;
int main(){
	char s1[81];
	set<char>s2;
	vector<char> res;
	char ch;
	int L=0;
	scanf("%c", &ch);
	while(ch!='\n'){
		if(ch>='a' && ch<='z'){
			ch=ch-'a'+'A';
		}
		s1[L++]=ch;
		scanf("%c", &ch);
	}
	scanf("%c", &ch);
	while(ch!='\n'){
		if(ch>='a' && ch<='z'){
			ch=ch-'a'+'A';
		}
		s2.insert(ch);
		scanf("%c", &ch);
	}
	set<char> tmpSet;
	for(int i=0;i<L;i++){
		if(s2.find(s1[i])==s2.end() && tmpSet.find(s1[i])==tmpSet.end()){
			res.emplace_back(s1[i]);
			tmpSet.insert(s1[i]);
		}
	}

	for(auto it=res.begin(); it!=res.end(); it++)
		cout<<*it;
}
