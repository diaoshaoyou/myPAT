//末尾一定是9,不然n=m+1,相邻两数肯定互质 
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int n;
	int num;
};
int isP(int n){
	if(n<=1) return 0;
	int tmp=sqrt(n);
	for(int i=2;i<=tmp;i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int checkGCD(int a, int b){
	int r=a%b;
	while(r!=0){
		a=b;
		b=r;
		r=a%b;
	}
	return isP(b)&&b>2;
}
int cmp(Node *n1, Node *n2){
	if(n1->n==n2->n)
		return n1->num<n2->num;
	else return n1->n<n2->n;
}
int getSum(int n){//测试点3、4超时！！！不能转string再遍历，会超时；直接用int做 
//	string str=to_string(n);
	int sum=0;
//	for(int i=0;i<str.length();i++){
//		sum+=str[i]-'0';
//	}
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int main(){
	int K,N,m,n;
	cin>>N;
	vector<Node*> res;
	for(int i=0;i<N;i++){
		cin>>K>>m;
		res.clear();
		if(i>0) cout<<endl;
		cout<<"Case "<<i+1;
		int tmp=pow(10,K-1);
		for(int i=pow(10,K-2);i<tmp;i++){//测试点4:只能考虑末尾=9的情况，如果全部遍历测试点4超时 
			if(getSum(i)+9==m){
				n=getSum(i*10+10);
				if(checkGCD(m,n)){
					Node *p=new Node;
					p->n=n;
					p->num=i*10+9;
					res.emplace_back(p);
				}
			}
		}
		if(res.empty()){
			cout<<endl<<"No Solution";
			continue;
		}
		sort(res.begin(),res.end(),cmp);
		for(int j=0;j<res.size();j++){
			cout<<endl<<res[j]->n<<" "<<res[j]->num;
		}
	}
}
