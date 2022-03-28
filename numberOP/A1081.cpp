#include<bits/stdc++.h>
using namespace std;
class Rational{
public:
	long int Son;
	long int Mother;
	string Simple;
	Rational(long int s, long int m){
		build(s,m);
	}
	void build(long int s, long int m){
		if(m<0){
			s=-s;
			m=-m;
		}
		Son=s;
		Mother=m;
		getSimple();
	}
	void getSum(long s1, long int m1){
		this->build(s1*this->Mother+this->Son*m1,m1*this->Mother);
	}
private:
	long int gcd(long int a, long int b){
		long int r=a%b;
		while(r!=0){
			a=b;
			b=r;
			r=a%b;
		}
		return b;
	}
	void getSimple(){
		Simple.clear();
		if(Son==0){
			Simple="0";
			return ;
		}
		//»¯¼ò 
		long int GCD=gcd(abs(Son),Mother);
		Son/=GCD;
		Mother/=GCD;
		//Éú³ÉSimple
		if(Son<0) Simple="(";
		int Int=Son/Mother;
		if(Int!=0){
			Simple+=to_string(Int);
			int remain=Son-Int*Mother;
			if(remain!=0)
				Simple+=(" "+to_string(abs(remain))+"/"+to_string(Mother));
		} 
		else{
			Simple+=(to_string(Son)+"/"+to_string(Mother));
		}
		if(Son<0) Simple+=")";
	}
		
};
int main(){
	int N,pos;
	string str;
	cin>>N;
	Rational res(0,1);
	for(int i=0;i<N;i++){
		cin>>str;
		pos=str.find_first_of('/');
		res.getSum(stoi(str.substr(0,pos)), stoi(str.substr(pos+1, str.length()-pos-1)));
	}
	cout<<res.Simple;
}
