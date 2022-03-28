#include<bits/stdc++.h>
using namespace std;
char Letter[26][7][5];
void Print(vector<int> &word){
	for(int i=0;i<7;i++){
		for(int j=0;j<word.size();j++){
			if(j>0) cout<<" ";
			for(int k=0;k<5;k++){
				printf("%c",Letter[word[j]][i][k]);
			}
		}
		if(i<6) cout<<endl;
	}
}
int main(){
	for(int i=0;i<26;i++){
		for(int j=0;j<7;j++){
			scanf("%s",Letter[i][j]);
		}
	}
	vector<vector<int> > sentence;
	vector<int> word;
	char ch;
	scanf("\n%c",&ch);
	while(ch!='\n'){
		if(ch>='A'&&ch<='Z'){
			word.emplace_back(ch-'A');
		}
		else{
			if(!word.empty()){//注意间隔符连续出现的情况,测试点1和2 
				sentence.emplace_back(word);//next word
				word.clear();
			}
		}
		scanf("%c",&ch);
	}
	if(!word.empty()) sentence.emplace_back(word);//测试点3和4，当结尾是\n也算间隔符 
 	int L=sentence.size();
	if(L==0) return 0;
	for(int i=0;i<L;i++){
		if(i>0) cout<<endl<<endl;
		Print(sentence[i]);
	}
} 
