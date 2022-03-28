#include<bits/stdc++.h>
using namespace std;
void add(string &s1, string &s2){
	int L=s1.length();
	int carry=0, sum=0;
	for(int i=L-1;i>=0;i--){
		sum=(s1[i]-'0')+(s2[i]-'0')+carry;
		if(sum<=9){//！！写成sum<9了，忘了了9，我tm直接裂开！！ 
			carry=0;
			s1[i]=sum+'0';
		}
		else{//进位 
			carry=1;
			s1[i]='0'+sum-10;
		}
	}
	if(carry){//最高位进位了 
		s1.insert(0,"1");
	}
}
int main(){
	string N,tmp;
	int K,step=0;
	cin>>N>>K;
	for(;step<K;step++){
		tmp=N;
		reverse(N.begin(),N.end());
		if(N.compare(tmp)==0) break;//可以遍历N比较对称性，倒转后直接比较字符串更方便 
		add(N,tmp);
	}
	cout<<N<<endl;
	printf("%d",min(step,K));
}
