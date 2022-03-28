//找对好的cmp函数。sort一下即可 
#include<bits/stdc++.h>
using namespace std;
int cmp(string &str1, string &str2){
//	int i=0,j=0;
//	int L1=str1.length();
//	int L2=str2.length();
//	while(i<L1 && j<L2){
//		if(str1[i]==str2[j]){
//			i++;
//			j++;
//		}
//		else if(str1[i]<str2[j])
//			return 1;
//		else return 0;
//	}
//	if(i<L1){
//		return str1[i]<str2[0];
//	}
//	else if(j<L2){
//		return str2[j]>str1[0];
//	}
//	else return 1;
	return str1+str2 < str2+str1;//太绝了，太绝了！ 
}
int main(){
	int N;
	string str;
	vector<string> List, res;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>str;
		List.emplace_back(str);
	}
	sort(List.begin(), List.end(), cmp);
	int k=0, cnt=0, last0=1;
	for(int i=0;i<N;i++){
		if(last0==1){
			k=0; 
			while(k<List[i].length() && List[i][k]=='0'){
				k++;
			}
			if(k==List[i].length()) {
				cnt++;
				last0=1;
			}
			else last0=0;
			List[i]=List[i].substr(k, List[i].length()-k);
		}
		cout<<List[i];
	}
	if(cnt==N) cout<<0;
}
