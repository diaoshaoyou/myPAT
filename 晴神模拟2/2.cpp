# include<bits/stdc++.h>
using namespace std;
int main(){
	int N,one=0,num,maxL=0,maxR=0;
	int left=0,right=0;
	vector<int> List;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>num;
		List.emplace_back(num);
		if(num==0) {
			if(maxR-maxL<right-left){
				maxL=left;
				maxR=right;
			}
			left=right;
		}
		else {
			one++;
			right++;
		}
	}
	
	
}
