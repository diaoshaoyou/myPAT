//���Ե�4����ȥ����֪��Ϊɶ�������� 
#include<bits/stdc++.h>
using namespace std;
class Customer{
public:
	double arrive;//ÿ���˵���ʱ�䶼��0��Ϊ��׼���бȽ�
	double T;//����� 
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
	 //������set���������ʱ�䣬��һ��2������ͬʱ������set����ظ���ʱ��Ե������� 
	for(int i=0;i<K;i++) earlyEnd.push(Open);
	for(int i=0;i<L;i++){
		double first=earlyEnd.top();
		if(List[i].arrive<first){//����һ���˽���ʱ���絽 
			List[i].wait=first-List[i].arrive;
			earlyEnd.push(first+List[i].T);//��һ���˽���ʱ��+��ҵ��ʱ�� 
		}
		else{//����ʱ����һ����������� 
			List[i].wait=0;
			earlyEnd.push(List[i].arrive+List[i].T);//���Ե�3�����տ�ʼ���û�����ʱ��ͳһд��first+List[i].T�� 
		}//����ʱ��+��ҵ��ʱ�� 
		earlyEnd.pop();
//		cout<<List[i].wait/60.0<<endl;
		sum+=List[i].wait;
	}
	 printf("%.1f",sum/(60*L));
}
