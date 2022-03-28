//非常规数学求和方法 
#include<bits/stdc++.h>
using namespace std;
struct Poly{
	double ex;
	double coe;
};
int cmp(Poly &p1, Poly &p2){
	return p1.ex>p2.ex;
}
int main(){
	int k1,k2;
	cin>>k1;
	Poly A[k1];
	for(int i=0;i<k1;i++){
		cin>>A[i].ex>>A[i].coe;
	}
	cin>>k2;
	if(k1==0&&k2==0) {
		cout<<0;
		return 0;
	}
	Poly B[k2];
	for(int i=0;i<k2;i++)
		cin>>B[i].ex>>B[i].coe;
	sort(A, A+k1, cmp);
	sort(B, B+k2, cmp);
	vector<Poly*> C;
	int i1=0,i2=0;
	int flag=0;//两个都有指数=0的项 
	while(i1<k1 && i2<k2){
		Poly *p=new Poly;
		if(A[i1].ex==B[i2].ex){
			p->ex=A[i1].ex;
			p->coe=A[i1].coe+B[i2].coe;//相同指数的直接相加，根本不用求和再log 
			i1++;
			i2++;
		}
		else if(A[i1].ex<B[i2].ex){
			p->ex=B[i2].ex;
			p->coe=B[i2].coe;
			i2++;
		}
		else{
			p->ex=A[i1].ex;
			p->coe=A[i1].coe;
			i1++;
		}
		if(p->coe!=0)
			C.emplace_back(p);
	}		
	while(i1<k1){
		if(A[i1].coe==0)
			continue;
		Poly *p=new Poly;
		p->ex=A[i1].ex;
		p->coe=A[i1].coe;
		i1++; 
		C.emplace_back(p);
	}
	while(i2<k2){
		if(B[i2].coe==0)
			continue;
		Poly *p=new Poly;
		p->ex=B[i2].ex;
		p->coe=B[i2].coe;
		i2++; 
		C.emplace_back(p);
	}
	int L=C.size();
	int exist=0;//指数=1的项是否存在 
	if(flag){
		for(int i=0;i<L;i++){
			if(C[i]->ex==1){
				exist=1;
				C[i]->coe++;
				break;
			}
		}
		if(exist==0){
			Poly *tmp=C.back();
			C.pop_back();
			Poly *p=new Poly;
			p->coe=1;
			p->ex=1;
			C.emplace_back(p);
			C.emplace_back(tmp);
			L++;
		}		
	}
	
	cout<<L;
	for(int i=0;i<L;i++){
		printf(" %.0f ", C[i]->ex);
		printf("%.1f", C[i]->coe);
	}
} 
