//测试点4过不去，不知道为啥。。。。 
#include<bits/stdc++.h>
using namespace std;
class Customer{
public:
	double arrive;//每个人到的时间都以0点为基准进行比较
	double T;//按秒存 
	double wait;
	Customer(int h,int m,int s,int t){
		T=t*60;
		arrive=h*3600+m*60+s;
	}
};
int cmp(Customer &c1, Customer &c2){
	return c1.arrive<c2.arrive;
}
int main(){
	int Open=8*3600;
	int N,K,h,m,s,t;
	cin>>N>>K;
	vector<Customer> List;
	 for(int i=0;i<N;i++){
	 	scanf("%d:%d:%d %d",&h,&m,&s,&t);
	 	if(t>60) continue; 
	 	if(h<17||(h==17&&m==0&&s==0)){
		 	Customer New(h,m,s,t);
		 	List.emplace_back(New);
	 	}
	 }
	 sort(List.begin(),List.end(),cmp);
	 int L=List.size();
	 if(L==0) {
	 	cout<<"0.0";
	 	return 0;
	 }
	 double sum=0;
	 priority_queue<double, vector<double>, greater<double> > earlyEnd;
	 //不能用set存最早结束时间，万一有2个窗口同时结束，set会把重复的时间吃掉！！！ 
	for(int i=0;i<K;i++) earlyEnd.push(Open);
	for(int i=0;i<L;i++){
		double first=earlyEnd.top();
		if(List[i].arrive<first){//比上一个人结束时间早到 
			List[i].wait=first-List[i].arrive;
			earlyEnd.push(first+List[i].T);//上一个人结束时间+办业务时长 
		}
		else{//到的时候上一个人早结束了 
			List[i].wait=0;
			earlyEnd.push(List[i].arrive+List[i].T);//测试点3！！刚开始该用户结束时间统一写成first+List[i].T了 
		}//到达时间+办业务时长 
		earlyEnd.pop();
//		cout<<List[i].wait/60.0<<endl;
		sum+=List[i].wait;
	}
	 printf("%.1f",sum/(60*L));
}
