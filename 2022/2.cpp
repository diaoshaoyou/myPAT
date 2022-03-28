#include<bits/stdc++.h>
using namespace std;
int main(){
	long long N,apple;
	long long sum=0;
	double avg;
	multiset<long long> List;
	vector<vector<double> > res;
	cin>>N;
	for(long long i=1;i<=N;i++){
		cin>>apple;
		vector<double> v(2);
		List.emplace(apple);
		sum+=apple;
		avg=sum*100.0/i;
		int tmp=(int)(avg);
		tmp=avg-tmp>=0.5?tmp+1:tmp;
		v[0]=tmp*1.0/100;
		auto it=List.begin();
		int cnt=0;
		for(;it!=List.end();it++){
			cnt++;
			if(cnt==(i+1)/2) break;
		}
		v[1]=*it;		
		res.emplace_back(v);
	}
	for(long long i=0;i<N;i++){
		if(i>0) cout<<endl;
		printf("%.2f %.0f",res[i][0],res[i][1]);
	}
} 
