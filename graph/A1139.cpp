#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
vector<int> List[MAX];
vector<vector<int> >res[101];
int cmp(vector<int> &v1, vector<int> &v2){
	if(v1[0]==v2[0]) return v1[1]<v2[1];
	else return v1[0]<v2[0];
}
int main(){
	int E,V,p1,p2,K;
	string str1,str2;
	for(int i=0;i<MAX;i++){
		List[i].emplace_back(1);
	}
	cin>>V>>E;
	for(int i=0;i<E;i++){
		cin>>str1>>str2;//注意-0000的特殊情况！！！ 
		p1=stoi(str1);
		p2=stoi(str2);
		List[abs(p1)][0]=str1[0]=='-'?-1:1;//性别相同时不能用ID相乘，因为有个ID==0;额外开辟第0位存性别 
		List[abs(p1)].emplace_back(abs(p2)); //存的都是序号，无关性别 
		List[abs(p2)][0]=str2[0]=='-'?-1:1;
		List[abs(p2)].emplace_back(abs(p1));
	}
	cin>>K;
	
	vector<int> v(2);
	int L1,L2,L3;
	for(int loop=0;loop<K;loop++){
		cin>>p1>>p2;
		if(p1==p2) continue;
		
		int ap1=abs(p1);
		int ap2=abs(p2);
		L1=List[ap1].size();
		for(int i=1;i<L1;i++){
			int mid1=List[ap1][i];
			if(List[mid1][0]==List[ap1][0]&&mid1!=ap2&&mid1!=ap1){//判断性别相同时不能用ID相乘，因为有个ID==0	
				L2=List[mid1].size();
				for(int j=1;j<L2;j++){
					int mid2=List[mid1][j];
					if(List[mid2][0]==List[ap2][0]&&mid2!=ap2&&mid2!=ap1){
						L3=List[mid2].size();
						for(int k=1;k<L3;k++){
							if(List[mid2][k]==ap2&&mid1!=mid2){
								v[0]=mid1;
								v[1]=mid2;
								res[loop].emplace_back(v);
								break;
							}
						}
					}
				}
			}
		}
		sort(res[loop].begin(),res[loop].end(),cmp);
	}
	for(int i=0;i<K;i++){
		if(i>0) cout<<endl;
		cout<<res[i].size();
		for(auto it=res[i].begin();it<res[i].end();it++){
			printf("\n%04d %04d",(*it)[0],(*it)[1]);
		}
	}
} 
