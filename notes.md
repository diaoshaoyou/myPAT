# 模拟

## A1124（AC）

1、在vector中判断某元素是否存在：变成set。若find()找不到，返回的是尾指针，不是NULL

```c++
set<string> st(winner.begin(), winner.end());
if(st.find(name)==st.end()){
    return true;
}
```

## A1065（部分正确）

### 思路

long long表示范围[-2^63^, 2^63^-1]​，用long long定义ABC

没考虑A+B会溢出的问题

### 更优解

2种溢出的情况：(1)A>0且B>0但sum<0。sum过大溢出，一定>C       true

(2)A<0且B<0但sum>0。sum过小溢出，一定<C        false

？？用cin最后一个点就过不去，scanf就可以。离谱

```c++
cin>>A>>B>>C;//不过
scanf("%lld %lld %lld", &A, &B, &C);//过
```

## A1031（AC）

## A1148（第3个点错误）

### 思路

我是枚举假设lie1和lie2说谎，再统计出所有人的身份。如果身份满足有2狼人，且说谎二人中有1狼人，则找到答案；反之找不到。但是第3个点“运行时错误”，但查了数组好像也没越界，不知为啥。

### 更优解

直接枚举假设w1和w2是狼人，竟然巨tm简单！！照着写了，结果段错误。

```c++
int State[N+1];//这样就tm段错误，不知道为什么。。
vector<int> State(N+1);//这样就对了
```

## A1048（AC）

### 思路

虽然是枚举，但也不能真的O(n^2^)枚举，不然超时。用val[num]来表示是否存在num。每读入一个数num，查val[M-num]看它的互补数是否存在，若存在就是潜在答案；若不存在就标记下，置val[num]=1。这样只要O(n)。

## A1017（第4个点错误）？？？

不知道哪里错了啊！！！思路都跟柳神的一样，但就是过不去。绝望。。

1、优先队列的使用

```c++
//优先队列=队列+自动排序,containor必须是用数组实现的容器,一般写vector
priority_queue<type, containor, cmp> XXX;
priority_queue<int, vector<int>, greater<int> > Q;//小根堆, 默认是less<int>大根堆
Q.top();//队列中的最小值
```

## A1105（AC）A1109（AC）A1049（AC）

# 排序

## A1028（超时）

### 思路

```c++
map<int map<string, int> > record;//整这么复杂不好使，老老实实struct record，根据C的取值排序
```

自己用的冒泡排序，太麻烦，最后结果还超时。

### 更优解

用系统自带的sort函数，自定义cmp()，快很多！！！

```c++
sort(arr, arr+n, cmp);//arr是数组起点，n是数组长度，cmp是自定义比较函数
int cmp(int A, int B){
	return A<B;//递增排序
}
//此题arr是struct record *的数组。cmp传入值也为2个指针，按照不同要求排序(见源码)
```

## A1025（AC）

1、合并vector用insert函数

```c++
V1.insert(loc, begin, end);//在V1的loc前插入地址区间[begin, end)的内容
V1.insert(V1.end(), V2.begin(), V2.end());//把V2合并到V1尾部
```

2、long long的输出和读入

```c++
printf("%lld", n); scanf("%lld", &n);//用于long long类型
printf("%ld", n); scanf("%ld", &n);//用于long类型
//long long读入: cin, scanf; 输出: 只能printf,不可用cout
```

## A1016（超时）



## A1080（不会）

### 思路

1、统计学生总成绩，做rank（没问题）

2、录取时，别从每个学校出发统计前几名录取。从每个学生（rank从高到低）出发，依次看他投报的学校招生名额remain[i]是否满了，没满就录取。

### 二刷

我真的开了眼了，最后倒在格式错误。。。

```c++
for(int i=0;i<M;i++){
    if(i>0) cout<<endl;//没有单独判断空的情况，就tm格式错误。暂时未想到反例
	sort(admit[i].begin(),admit[i].end());
	for(int j=0;j<admit[i].size();j++){
		if(j>0) cout<<" ";
		cout<<admit[i][j];
	}
}
for(int i=0;i<M;i++){
	if(admit[i].empty()) {
		cout<<endl;
		continue;
	}
	sort(admit[i].begin(),admit[i].end());
	for(int j=0;j<admit[i].size();j++){
		if(j>0) cout<<" ";
		cout<<admit[i][j];
	}
	if(i<M-1) cout<<endl;
}
```



## A1075（超时+1个点没过）

### 思路

读入+rank+统计分数+输出。没过的点：不显示的用户是score全为-1或-2的，而非看total是否为0

### 更优解

1、rank有更简洁的写法

```c++
List[1]->rank=1;
for(int i=2;i<N+1;i++){
	List[i]->rank=i;
	if(List[i]->total == List[i-1]->total){
		List[i]->rank=List[i-1]->rank;
	}
} 	
```

2、读入：ID用int存，直接做下标，这样便于确认当前读入是否之前出现过，读入只要O(n)。原来：每读入一个就去遍历原List，看是否出现过，读入要O(n^2^)，也是超时的原因。

```c++
vector<User *> List(N+1);//从1开始有效 
for(int i=0;i<N+1;i++){//提前为每个都设置好空间和初值，用ID做下标
	User *u=new User;
	u->ID=i;
	List[i]=u;
}
```

## A1089（1个点没过）

### 思路

归并排序时自己写的merge有问题，第3个点过不了；用系统sort则可过。（能不用自己排序就不用）

## A1098（AC）

1、堆的下沉适应最好写成函数，不然建堆和排序都得写一遍

## A1117（部分正确）

### 思路

刚开始题目都没读懂。。。求E，使大于E的数有E个。

从大到小排列。对于mile[E]，必须>E+1，这样mile[0]--mile[E]共E+1个数，都>E+1。所以遍历mile[i]，若mile[i]<=i+1，则停止遍历，i就是所求。

```c++
sort(A, A+N, greater<int>());//从大到小排
```

## A1129（第5个点没过）

### 思路

1、用大小为K的向量rec来存推荐序号，每读入一个数，输出rec；然后更新该数的频率和rec，再rec重排序。

2、测试点5错误原因：读入的序号有重复时，由于rec是vector，会重复记录序号；实际上如果rec中已存在该序号，只要改变frequency即可。例如输入第一行：9 3，第二行：1 1 1 1 3 2 4 3 2。**使用vector时要特别注意数字重复的情况**。

## A1141（AC）A1055（AC）A1137（AC）

## A1153（第3、4个点超时）！！！

1、这题真的搞人心态啊！第4个点有时超时，有时不超时。超时原因：用了cout。**cout运行时间是printf的3倍**，超时实在优化不了可以试试printf。。

2、map也很容易超时，因为底层用红黑树实现；替代品unordered_map用哈希实现，更快。

## A1101（各种错误）

### 思路

用O(n^2^)硬算肯定不行，运行超时。复习时遇到过：每一轮快排完，基准点都会确定最终位置。所以找出已经在最终位置的数字，但它们也不一定都是基准点，反例：4 2 3 1 5（其中2和3都不是）针对反例我没啥好思路，还是遍历比较，结果会超时。

1、运行超时：反例不要遍历比较。**用Max记录第i个点之前的最大值**，若Max<num[i]，则符合条件。

2、格式错误：这题真的很诡异，他要求除了答案外还要多一个回车。那么若个数为0，要打两个回车。

# 字符串处理

## A1140（AC）

1、用迭代器遍历vector

```c++
for(vector<int>::iterator it=V1.begin();it!=V1.end();it++)
//或者
for(auto it=V1.begin();it!=V1.end();it++)
```

2、各种转换

```c++
stoi():把string变成int
atoi():把char数组变成int
to_string():把int变成string
c_str():把string变成char
char*直接赋给string:把char变成string
```

3、substr()函数

```c++
substr(pos, n);
//pos:子串起点，从0开始         n:子串长度，总字符数
```

## A1061（1个点没过）

算day的时候，判断string1和string2相同的字母应该是A-G，而非A-Z，因为一个星期只有7天

## A1113（AC）

1、用sort！！！（自己写的排序会超时）

## A1062（AC）

## A1112（AC）

### 思路

1、遍历，把所有字符装入set

2、讲重复次数！=k的倍数的字符剔除set

3、遍历，将遇到的重复次数==k倍数又在set中的字符按序存到vector中

4、遍历，删掉重复字符，得到original（前3步为了排除重复k次但不是坏的键）

### 更优解



## A1077（AC）

```c++
reverse(v.begin(), v.end());//把向量倒序
```

## A082（AC）

# STL

## A1054（AC）

1、map相关操作

```c++
map<int, int> Color;//创立
Color.insert(...);//插入
Color.find(key)==Color.end();//判断key是否在map中，类似set的判定
vector<pair<int, int> > v(Color.begin(), Color.end());//map排序必须赋给线性vector
sort(v.begin(), v.end(), cmp);//再用sort排序
```

## A1022（AC）

### 思路

我并未用到map。把书本信息存为struct，所有书本构成一个数组。每读进一个query，就遍历数组，寻找目标书本。

1、getline()函数的崩溃瞬间

cin遇空格或回车就停止，会把结束符放在缓冲区。getline(cin, str)遇回车就停止，结束符不放在缓冲区。因此，cin过后要调用getline，则需额外调用一次getline读取缓冲区里的结束符。

```c++
//输入为W回车hello
cin>>s;//s="W"
getline(cin, s1);//s1=回车
getline(cin, s2);//s2="hello"
//输入为W空格hello
cin>>s1;//s1="W"
getline(cin, s2);//s2=" hello" , 把结束符空格也包含进来了
```

2、string找子串

```C++
if(str.find(sub)==str.npos)//npos是一个没找到就返回的默认值
    //not find
```

## A1047（运行超时？？？）

？？？不知为啥就是运行超时，思路跟柳神的一样。。。

## A1063（AC）

1、有现成的求交集并集差集的函数

```c++
set<int> A, B, inS, uS, dS;//inS=A*B, uS=A+B, dS=A-B
set_intersection(A.begin(),A.end(),B.begin(),B.end(),inserter(inS,inS.begin()));
set_union(A.begin(),A.end(),B.begin(),B.end(),inserter(uS,uS.begin()));
set_difference(A.begin(),A.end(),B.begin(),B.end(),inserter(dS,dS.begin()));
```

2、保留小数位数

```c++
printf("%.nf", number);//n是需要保留的小数位数，小数少了右侧自动补0
```

# 数字处理相关

## A1132（AC）

1、注意判断整除前，得先判断除数是否为0

## A1073（AC）A1069（AC）

## A1060（一个点没过）

### 思路

考虑4种情况：（1）0		（2）无小数点的整数：123		（3）小数：12.3		（4）无故多0的数：0023.4，忘记考虑了，导致一个点没过

## A1002（AC）？？

这题，仿佛有那个什么大病。多项式相加时，相同系数的指数直接相加，根本不用算和再求log，不是传统的数学求法，是我想多了。。。

## A1116（AC）A1152（AC）A1029（AC）A1019（AC）A1058（AC）A1100（AC）

## A1027（AC）

1、string的数字间差值≠字符差值

```c++
string str1="A"+2;//str为"#"
str1+='A'+2;//str1为"#C",把左边char类型加给了string类型,它会自动转换成string
```

## A1093（超时）

想不到更好的思路了，正常遍历要O(n^2^)，会超时。

### 更优解

1、对于每个A，能组成的PAT数量=前面的P数量*后面的T数量。这样只要O(n)。

2、对10000000007取模后的数存不下int32位，属于int64位。所以别忘了将sum设成long long。

## A1104（测试点2错误，坑）！！！

### 思路

1、这是一道神奇的题目，只要10分钟就能写出答案，但测试点2经人反馈后有问题，导致很难找出原因。

2、测试点2错误原因：double多次累加导致偏差变得很大很大。当N比较大时，别用double存浮点数！！！！因为double表示十进制小数是用无限接近的手段，不是正好表示；当足够多的数累加时，偏差变得很明显。其实是语言问题，java有能精确计算的大数类``BigDecimal``，最后没有偏差；但c++只有double，偏差明显。解决方法：将读入的数放大1000倍（目前测试用例精确到小数点后3位），用long long存。

3、我的思路：存好前N个数和Sum[N]，找规律得所有数之和=$\sum (Sum[i]*(2*i+N))$，其中$i\in[1,N]$  我用我的方法放大1000倍存还是错误，不知道为啥。。

4、柳神思路：针对每个数List[i]，它在以List[1]~List[i-1]为首的子列中都出现了N-i+1次，在以自己为首的子列中也出现了N-i+1次，所以共出现i*(N-i+1)次。例如0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8中，0.3在0.1, 0.2, 0.3为首的子列中都出现(8-3+1=6)次，共出现3 * 6=18次，和为0.3*18=5.4

```c++
for(int i=1;i<=N;i++){
    cin>>num;
    sum+=(long long)(num*1000)*i*(N-i+1);
}
```

## A1015（第3个点错误）

### 思路

刚开始看错题了，又浪费了很多时间。。这本该是道水题。第3个点错误原因：十进制转成其他进制后位数变多，用int已经表示不下了，只能用char数组存！！！**注意选择数据类型能表示的范围**

## A1088（第3个点错误）

### 思路

归根到底是求最大公因数，其他细节我用了C++中的操作符重载，所以代码量多了一点。剩下把分子分母化简，测试点3答案错误。

### 更优解

直接找到最大公因数，分子分母都除一下。用辗转相除法。柳神的记得住就记，记不住用循环也行。

```c++
long int gcd(long int a, long int b){//辗转相除法 
	long int r=a%b;
	while(r!=0){//循环更好理解
		a=b;
		b=r;
		r=a%b;
	}
	return a; 
}
long int gcd(long int a, long int b){
	return b==0?a:gcd(b,a%b);//柳神的超简洁写法,是上面一个的变形
}
```

## A1081（AC）

## A1024（第6、8个点错误）

1、错误原因：**选用的数据类型范围太小**。自以为long long类型范围够用，但是若10^10^操作100次仍未到对称，则会超出long long可表示的范围。所以只能用字符串来实现加。实现时有个小bug，找了半天！！吐了。。

```c++
int L=s1.length();
int carry=0, sum=0;
for(int i=L-1;i>=0;i--){
	sum=(s1[i]-'0')+(s2[i]-'0')+carry;
	if(sum<=9){//写成sum<9了，忘了9，我tm直接裂开！！ 
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
```

2、string的insert()使用

```c++
str1.insert(pos, str2);//pos是以0为起点的,原来在pos处的值往后挪
str1.insert(1,"HH");//str1=="123",插入后变成"1HH23"
```

## A1136（AC）

## A1023（AC）

1、vector的insert()使用

```c++
v.insert(iter, val);//往迭代器iter所指位置的前面插入一个val
v.insert(v.begin(), val);//往头部前面插入一个
```

## A1096（不会）

### 思路

用双重循环暴力求解。从2~sqrt(N)枚举连乘的第一个数，一直往后乘直到不能被N整除。最后找最长的连乘组合。注意：素数要单独考虑，因为素数只要自身N，而这个N>sqrt(N)不会被枚举到。

### 二刷

第2、4个点没过。思路很清楚，自以为可以倒着求，从sqrt(N)+1开始求连乘的终点，但是！！！题目求的是smallest sequence！！离谱啊离谱。。。

## A1009（AC）

# 线性表

## A1051（AC）

## A1056（AC）

## A1133（AC，大坑）

### 思路

把节点的地址当做List的下标存，遍历，把不同类别的节点挑出来存好，最后输出。

第一次只用一个数组newList另存了所有节点，但会段错误！原因：输入的节点中有些构不成链表的一部分，是多余的。所以最后输出时遍历数组newList，要重新计算长度，不能直接用N！

### 更优解

第二次看了柳神的代码，用3种vector分别存3种节点，最后输出时用的是vector.size()，避开了N，所以AC。

## A1074（AC，大坑）

### 思路

把每个节点按顺序装入vector，这样反转可以利用系统自带的reverse()函数，不用自己写。next地址在输出时考虑，直接输出下一个节点的地址即可。

### 更优解

大坑！大坑！大坑！第一次List存的是每个节点指针，最后一个点会段错误。第二次存的是结构体，最后一个点会答案错误。

原因：输入的节点中有些构不成链表的一部分，是多余的。所以最后输出时遍历向量res，要重新计算长度，不能直接用N！

## A1052（部分正确）

### 更优解

第五个点（不该错）：首行输出首地址时，也要控制5位输出，用%05d

第六个点（有点坑）：空链表要输出“0 -1”，我只输出了"0"

## A1032（AC）

有个点差点没过，又忘了保证5位地址格式。

## A1092（AC）A1041（AC）A1050（AC）A1084（AC）A1120（AC）A1121（AC）1149（AC）A1144（AC）A1097（AC）

## A1145（AC）

### 思路

正常的hash运算。有个点题目没明说，猜对的：存在一些数没法插进去，解决冲突时会陷入死循环，所以设置循环次数上限为Size。查找上述数时也会死循环，查找次数上限也为Size。

## A1057（运行超时）树状数组！！！

### 思路

题目实现起来简单，但PeekMedian时用排序查询会超时。柳神树状数组的方法没看懂。。。看似简单，实则不简单。

### 更优解

1、分块法求中位数：

```c++
//找中位数时先粗略筛选,找block;再细筛,找cnt
int cnt[MAX];//每个key出现的次数，key：1~100000 
int block[317];//将每316个key分到一个block, 316=sqrt(100000),共317个block
int findMid(int pos){
	int sum=0, i=0;
	while(sum+block[i]<pos){//先从block找 
		sum+=block[i];
		i++;
	}
	i=i*316;
	while(sum+cnt[i]<pos){//再从cnt找 
		sum+=cnt[i];
		i++;	
	}
	return i;
}树状数组
```

2、树状数组（用于**随时变化序列求第K大数**）

```c++
//-x=x的二进制取反加一，也相当于最右边的1之左的所有数都取反
int lowbit(int x){
    return x&(-x);//=最右边的1和其之右的0，相当于x能整除的最大2的乘方数，如2,4,8等
}
```

树状数组定义：BIT[i]=从第i个往前数lowbit(i)个数之和，BIT的下标从1开始

<img src="D:\typora\Pictures\1646983987241.png" alt="1646983987241" style="zoom:60%;" />

```c++
//T=O(logn)
int getSum(int x){//计算第1~x个数之和,找到刚好全部覆盖第1~x个数的BIT即可
    int tmpX=x,sum=0;
    while(tmpX>0){
        sum+=BIT[tmpX];
        tmpX-=lowbit(tmpX);
    }
    return sum;
}
//T=O(logn)
void update(int x, int v){//给第x个数加上v, BIT也要更新, 把覆盖了BIT[x]的都更新.
//可以找覆盖最近的,递归更新。eg.A[6]加v，则BIT[6]更新;BIT[6]最近覆盖=BIT[8],BIT[8]更新;BIT[8]最近覆盖=BIT[16],BIT[16]更新
//找最近：取增量=lowbit(x),相当于原来的最右1又加上1,会进位,就会覆盖BIT[x]
    while(x<N){//N是最大范围
        BIT[x]+=v;//update
        x+=lowbit(x);//找到覆盖BIT[x]的最近的BIT
    }
}
```

3、树状数组经典问题：1~N的整数组成序列，对于每个数x，求在x左边且比x小的数有几个（面试问到了，当时完全不知道是什么甚至理解错了题意，离大谱。。。）

```c++
//此题中原数组A[i]存的是数i出现的次数
//getSum(x):得到1~x出现次数之和, update(x,1):x出现次数+1
int main(){
    for(int i=0;i<N;i++){
        cin>>num;
        update(num,1);//数num出现次数+1,相当于A[num]值要加1
        printf("%d", getSum(num-1));//输出1~(num-1)出现的次数之和，就是小于num的数的总个数。可以一边读一遍输出，因为后面没输入的数组A中也没记录
    }
}
```

若整数不是连续1~N，可以用结构体存val，再另外赋一个ID；也可以用map转换一下。eg. {1111111,0,45,8888}在大小上和{4,1,2,3}等价。

4、树状数组求中位数

相当于一个随时变化的序列，去查它的中位数，跟上main差不多，可以用树状数组做。已知中位数pos的位置，即找到一个i使得getSum(i)>=pos。直接1~MAX遍历，会超时；二分查找才可以。（又一个坑点。。）

```c++
int findMid(int pos){
	int r=MAX,l=1,mid;
	while(l<r){
		mid=(r+l)/2;
		if(getSum(mid)>=pos) r=mid;
		else l=mid+1;
	}
	return l;
}
```



## A1078（AC）

1、判断素数时，特殊情况n==1别忘了。

## A1044（超时）！！！

### 思路

最简单的就是以每个数为起点往后找，记录下和为M的终点。这样T=O(n^2^)，会超时。我很难把二分查找和本题联系起来。

### 更优解

用sum[N+1]存前N个钻石的总价值，则第i-j个钻石的总价值=sum[j]-sum[i]。以每个钻石为起点，比如D[start]为起点，则要找sum[rear]=sum[start-1]+M。因为sum递增，所以这个sum[rear]可以在start~N+1之间二分查找。这样T=O(nlogn)。





# 树

## A1102（AC）

### 思路

每个节点的下标=data，所以用数组存节点，再记录头结点，就可以遍历树了

## A1064（不会）

### 思路

这题真的很自闭，单纯用类似大根堆的方法不行，会导致整体不是二叉查找树。由于二叉查找树的中序遍历是递增数列，所以把原数列排序，然后中序遍历该树，与此同时赋值到相应位置。（这处真的很难理解。。写1099时有类似思路）

```c++
int idx=0;
void inOrder(int List[], int cur){
	if(cur>=N) return;
	inOrder(List, cur*2+1);
	Tree[cur]=List[idx++];//!!!此处跟一般的中序遍历不同
	inOrder(List, cur*2+2);
}
```

## A1043（AC）

### 思路

1、选择什么数据结构存树真的很重要！！！！刚开始用数组存，因为不是完全二叉树，真的没法操作；后来改成链表存，非常好写。如果只给出一组数列，二叉树最好用链表；如果节点编好号，给出了左右节点序号，可用数组存。

2、一开始不知道该怎么获得BST。看了博客，可以按照输入序列顺序构造BST，然后求得其preorder，再与输入序列比较。

## A1099（AC）

### 思路

关于A1064的思路我突然悟了！本题中已经构建了固定架构的查找二叉树，要求填入一系列数Num[N]使之成立。因为查找二叉树的inorder是从小到大，所以先把Num[N]从小到大排，再inorder顺序遍历每个树节点，给每个节点赋Num[i]的值。（换成preorder顺序特别好理解，inorder有点抽象）

## A1115（AC）

1、注意每道题的BST定义可能有差别。有的key都不同；有的<=为左子树，>为右子树；有的<为左子树，>=为右子树。

## A1138（AC）

### 思路

1、第一种方法运行超时。每读一个preorder序列数字，都判断它在根节点的左/右，依次下移到对应子节点，再对子节点重复以上操作。这样N个节点共用时O(NlogN)，太慢了。

2、用递归思路。每读一个preorder序列数字，都递归获得它的左右子树；即inorder中它左边的数=它的左子树，inorder中它右边的数=它的右子树。

```c++
int order=0;//依次读取preorder的数
Node* Build(int idx1, int idx2){
	if(order>=N || idx1>idx2)
		return NULL;
	int root=pre[order++];//root就是所读的数，作为根
	int mid=pos[root];//根在inorder中所在位置
	Node *Left=Build(idx1, mid-1);//递归获得左子树
	Node *Right=Build(mid+1, idx2); //递归获得右子树
	Node *p=new Node;
	p->left=Left;
	p->right=Right;
	p->data=root;
	return p;
}
```

## A1127（AC）

### 思路

1、参考A1138的思路。本题要求inorder+postorder->levelorder。postorder倒过来（根右左）类似preorder（根左右），只需要Build()函数递归求Left和Right时换个顺序。

2、变异的levelorder，原先想着用stack辅助。更简洁的方法是：先求得正常的层序遍历数列，找到需要从右往左遍历的数列区间，用reverse()函数。

## A1020（AC）

1、level order时不用自己写队列，可以用系统自带queue<Node*>

```c++
queue<int> Q;
Q.pop();//在开头处剔除第一个
Q.push();//在末尾处增加
cur=Q.front();//队列第一个元素
```

## A1079（AC）

1、第一次遇到DFS，用递归非常简单，非递归还不太会。

2、多用系统自带函数！！求乘方时用pow不超时，自己用循环算就超时。

3、**段错误原因**：一般是数组越界，一种情况是所设数组大小<题目的N的最大值

## A1053（第5个点段错误）

### 更优解

第5个点：竟然在cmp函数翻车了！没有考虑2个路径全部相等但一长一短的情况。

**段错误原因**：函数返回值未囊括所有情况。在某些情况下，函数没有返回值。

```c++
int cmp(vector<int> &v1, vector<int> &v2){
	int i=0;
	int L=min(v1.size(), v2.size());
	for(i=0;i<L;i++){
		if(v1[i]!=v2[i])
			return v1[i]>v2[i];
	}
	return v1.size()>v2.size();//前面全部相等，两个vector一长一短，这个不写会段错误 
}
```

## A1094（AC）

### 思路

思路跟A1079很像，都用dfs算出每个节点的depth。然后再统计相同depth的总人数即可。

## A1090（段错误）

**段错误原因**：原先用map存树结构，会段错误；现在用数组存，就AC。那就少用map

```c++
map<int, vector<int>> tree;//<parent, children>，这样会段错误
vector<int> tree[N];//tree[i]就是节点i的子节点
```

## A1076（AC）

1、BFS时存在环，所以要做好是否已经访问过的标记，否则运行超时。对于每个几点，遍历其子节点，若子节点未被访问，则加入set并做好已访问标记；反之舍弃。再依次对刚刚加入set的节点做BFS。

2、set的插入

```c++
s1.insert(s2.begin(), s2.end());//可以往s1中插入一整个s2
```

## A1021（AC）

1、访问标记一般用数组visited[N]，这次尝试用set，但是每次判断某节点是否在set中（即是否被访问过），太耗时间，会运行超时。所以最好还是用int数组。

## A1013（AC）

## A1086（AC）

### 思路

写的第一道树题就是这个。刚开始不会写。现在重新思考，就是inorder+preorder->postorder。出栈顺序=inorder，入栈顺序=preorder，构建树，再递归得到postorder。

## A1091（最后2个点段错误）！！！

### 思路

1、刚开始三维矩阵中存节点值和值为1的邻居节点（提前求出邻居dfs时不用判断，方便一点），导致内存超出。

2、舍弃邻居vector，只存值，邻居放在dfs中判断，结果段错误。经查资料，**段错误原因**：用DFS递归层数过多，栈溢出。用了BFS递归也栈溢出，建议改用非递归的BFS。

3、非递归BFS：用queue存下某个节点所有邻居，再每次从队列中取一个节点，继续存其所有邻居，重复上述操作直至queue为空。（类似于层序遍历）但是每次从头开始寻找值为1的节点过于浪费时间，会导致最后一个点运行超时。

4、最终版：正常遍历M中所有的点，对每个符合条件的点进行bfs，这样不会重复访问之前的点。

```c++
for(int level=0;level<N;level++){
		for(int i=0;i<L1;i++){
			for(int j=0;j<L2;j++){
				if(M[level][i][j]==1){//寻找到的满足条件的点
					maxSize=1;
					M[level][i][j]=-1;
				 	bfs(level, i, j);//直接在三重循环中做bfs				
					if(maxSize>=Limit)
						sum+=maxSize;	
				}
			}
		}
	}
```

## A1103（不会）？？？

### 思路

看了别人的思路后独立完成，知道思路后还挺简单。

```c++
void dfs(int start, int remain, int amount){
//从start往小了找，找到可以尽量填满remain的数i, amount是还需要找的乘方数量
    for(int i=start;i>0;i--){
		if(amount==1&&remain==num[i]){//最后一个数刚好填满remain 
			tmpRes.emplace_back(i);
			int sum=0;
			for(auto it=tmpRes.begin(); it<tmpRes.end();it++){
				sum+=*it;
			} 
			if(sum>maxSum){//找和最大的答案
				maxSum=sum;
				Res.assign(tmpRes.begin(), tmpRes.end());
			}
			else if(sum==maxSum && Res<tmpRes){
				Res.assign(tmpRes.begin(), tmpRes.end());
			}
			tmpRes.pop_back();//记得pop！！
		}
		else if(num[i]<=remain){//num[i]能塞入remain 
			tmpRes.emplace_back(i);//收了i 
			dfs(i, remain-num[i], amount-1); 
			tmpRes.pop_back();//记得pop！！
		} 
		else//num[i]>remain, num[i]太大了塞不下 
			continue;
	} 
}
dfs(num,N,K);//最初start=num，num满足num^P<=N，最初剩余量=N，还要找K个数
```



## A1147（AC）A1155（AC）

## A1110（第5、6个点错误）完全二叉树判定

### 更优解

换了种思路。层序遍历，前N/2-1个节点必须有2个孩子，而第N/2个节点必须有左孩子，右孩子无所谓。层序遍历顺便做完还能得到last node，完美。

## A1143（不太会）！！！

### 思路

1、用preOrder和inOrder建树，然后求得u和v的dfs路径，进行比较找LCA。建树这块忘记了，弄了好久，然后dfs又不小心写错了，最后这样写很麻烦会超时。非常不合适的方法。

2、再复习一下

```c++
int idx=0,N;
Node* Build(int start, int rear){//!!!
	if(start>rear || idx>N-1) return NULL;
	int root=pre[idx++];
	int Mid=pos[root];
	Node *p=new Node;
	p->data=root;
	Node *L=Build(start, Mid-1);
	Node *R=Build(Mid+1, rear);
	p->left=L;
	p->right=R;
	return p;
}
```

3、dfs中``tmpPath.pop_back();``别再忘了！！！若有多次dfs，记得初始化tmpPath

### 更优解

要想简单，得找规律。由于树是二叉查找树，所以LCA是preOrder中第一个介于v和u之间的数 。如果这样的LCA就是v或者u本身，则那个数是parent。柳神牛逼！

## A1151（AC）

### 思路

上一题是二叉查找树，LCA的特征明显，这题我又不知道怎么做了，所以只能笨办法建树。建树， dfs，比较路径。注意当n1==n2时，单独考虑，因为只能dfs出来一条路径。

### 更优解

竟然又不用建树，我又建树了。。。



## A1135（AC）

### 思路

本以为很难，写起来不难。

（1）preOrder+inOrder建树

（2）dfs遍历，判断红结点的孩子是否为红；到叶节点时，记录每个节点在这条路径上黑孩子的个数，记录每个节点在每条路径上的黑孩子数，存在``vector<int> blackChild[MAX]``，若blackChild[i]中每个元素相同，则是红黑树；反之不是。

## A066（AC）！！AVL建树

### 更优解

```c++
//建AVL树模板
//每读入一个数，就将其插入树中，插入后若不平衡，则立刻旋转调整
for(int i=0;i<N;i++){
    cin>>num;
    root=Insert(root, num);
}
Node *Insert(Node *root, int num){
	if(root==NULL){
		Node *p=new Node;
		p->data=num;
		p->left=NULL;
		p->right=NULL;
		root=p;
	}
	else{
		roType type;//LL,LR,RL,RR,不是旋转方向,而是不平衡出现的位置
		if(root->data<num){//insert right subtree
			root->right=Insert(root->right, num);
			if(getHeight(root->left) - getHeight(root->right)<=-2){
				type=(num>root->right->data)?RR:RL;
				root=Rotate(root,type);
                //root是旋转后的根，在上一层递归中被连到原来的树中
			}
		}
		else if(root->data>num){//insert left subtree
			root->left=Insert(root->left, num);
			if(getHeight(root->left) - getHeight(root->right)>=2){
				type=(num>root->left->data)?LR:LL;
				root=Rotate(root, type);
                //root是旋转后的根，在上一层递归中被连到原来的树中
			}
		}
	}
	return root;
}
```

## A1123（AC）

### 思路

（1）建AVL树：跟A1066一样

（2）完全二叉树的判定：跟A1110一样。前N/2-1个节点要有2个孩子，第N/2个节点至少1个左孩子。

## A1119（不会）！！！

### 思路



# 并查集（都有union和findParent函数）

题目数据的结构画起来跟树差不多，但一般最后数据会被分成几大类别，而树的数据是分明的。

## A1107（部分正确）

### 思路

看上去是个比较简单的题，但就是有第1、4、5个点答案错误。原先的办法考虑不全，还是老老实实用并查集的方法做：union两个节点，要先findParent，再把2个parent合并。并查集一直这个套路。

1、fill()函数

```c++
fill(begin, last, val);//用于给数组填充值val，不用再写循环。填充范围[begin, last)
int A[1000];
int B[100][100];
fill(A, A+1000, -1);//A数组初始化全为-1
fill(B[0], B[0]+100*100, -1);//二维函数略有不同
```

## A1114（不会，一团浆糊）

### 思路

我自己根本没思路，有个人用邻接矩阵建图，再用dfs求连通分量。可以做，但内存超出。

### 更优解

用Rep[MAX]数组记录每个家族的代表。刚开始每个人的代表是他自己（自成一家），然后将其与父母、孩子Union()：先findRep()找出二者家族的代表，2个代表哪个ID小，就选谁为总代表（这样最后就能输出ID最小的人），相当于把2个家族合并成1个。所有家族都合并好后，统计数据，输出。

按照之前并查集的思路，一般是找某个点的父节点/祖宗节点，但这题有爸爸和妈妈节点，不好说选哪个。刚好他要求选ID最小的，所以就找最小ID作为家族的代表。

### 二刷

1、刚开始List中要为每一个Node都申请一个空间，用cnt来表示节点是否出现过。出现过则cnt=1，未出现过则cnt=0。

2、area、cnt和estate的统计不能在Union里面做，因为此时area和estate没完全读完，没法统计。只能后面重新遍历统计。

## A1034（AC）

### 思路

和A1114不同的是，没法边读入边Union()，因为A1114选rep是比较ID大小，而本题是比较T大小，只有所有读完了才知道谁的T最大。所以（1）先读入，计算T，totalT等，记录好读入的数据；（2）重新遍历读入的数据，相联系的2人进行Union()；（3）对符合条件的head排序输出

```c++
struct Node{
	string name;
	int T;
	int totalT;//gang总用时，刚开始=自身T 
	int num;//小弟数
	//刚开始每个人是自身的小弟, num==1; 合并后小弟的num==0;head的num就是gang总人数 
	int head;//刚开始每个人都是自身的head 
};
```

## A1118（AC）

常规解法。

# 图

## A1134（AC）

## A1030（AC）！！！

### 思路

参考各种资料艰难完成的第一个Dijkstra算法雏形，注释详细，可供参考。

```c++
//一个dijkstra算法的模板，双重循环，所以T=O(V*V)
int Dist[MAX][MAX];//题目已知的各个点距离和花销的关系 
int dist[MAX];//当前各个点到起点的最近距离,其余=INF,dist[Start]=0
int visited[MAX];//标记节点是否被访问过 
int pre[MAX];//存最短路径，pre[i]表示路径中 i的前面一个点
Dijkstra(int start, int dest){
    int target;//距离起点最近的点
    int minD;//target到起点最近的距离 
    for(int loop=0; loop<V;loop++){//最开始有V个点未访问(包括起点自身) 
		minD=INF;
         target=-1;//第一次找到的target就是Start
		//找距离起点最近的： 
		for(int i=0;i<V;i++){
			if(visited[i]==0 && dist[i]<minD){
				minD=dist[i];
				target=i;
			}
		} 
        if(target==-1) return;//所有点都访问过了
		visited[target]=1;//找到了最近的点,加入已被访问的集合 
		//update dist:
		for(int i=0;i<V;i++){//i要求是剩余未被访问的点 
			if(visited[i]==0 && dist[i] > minD+Dist[target][i]){
				dist[i]=minD+Dist[target][i];//旧路径不如target参与的新路径，换掉
				pre[i]=target;//若改用新路径，节点i的前一个点就是target
			}
		} 
	}
}
```

## A1087（第2个点答案错误）

### 思路

1、多条最短路径的Dijkstra算法。多条路径刚开始用二维数组存且没用dfs，导致了第2个点错误。

```c++
//多条最短路径，要对上题中的pre和update过程做改动，用dfs找到最佳路径
vector<int> pre[201];//存多条最短路径的前驱点 
//update:
		for(int i=0;i<V;i++){
			if(visited[i]==0 && cost[i]>minC+Cost[target][i]){
				cost[i]=minC+Cost[target][i];
				pre[i].clear();//清空原来记录的最短路径 
				pre[i].emplace_back(target);//存新的前驱点
			}
			else if(visited[i]==0 && cost[i]==minC+Cost[target][i]){
				pre[i].emplace_back(target); //存新的前驱点
			}
		}
```

2、用了dfs后，第2个点过了，但是第1个点又错误。原因：dfs写错，已在注释中标出。

```c++
//把pre的遍历想象成树，树根->叶子=dest->start的路径
void dfs(int dest){
	tmpPath.emplace_back(dest);
	if(dest==0){//到达叶子节点
		pathN++;//统计最短路径总条数
		int sum=0;
		double avg=0;
		for(auto i=tmpPath.begin(); i!=tmpPath.end(); i++){
			sum+=Happy[*i];
		}
		avg=1.0*sum/(tmpPath.size()-1);
		if(sum>maxHappy){
			maxHappy=sum;
			maxAvg=avg;//maxAvg=最大happy的平均值，而非最大的avg
			Path=tmpPath;
		}
		else if(sum==maxHappy && avg>maxAvg){
			maxAvg=avg;
			Path=tmpPath;
		}
//		tmpPath.clear();//不能直接清除，有可能2条路径共用了部分节点！！！！ 
	}
	else{
		for(auto it=pre[dest].begin(); it!=pre[dest].end(); it++){
			dfs(*it);
		}	
	}
	tmpPath.pop_back();//当前点走完后要pop，回到父节点，方便父节点dfs下一个孩子 
}
```

## A1003（AC）

前面的艰辛过了之后就很容易了

## A1072（AC）

### 思路

1、起点不断变化的Dijkstra算法。纠结了半天用邻接表还是邻接矩阵，最后还是用邻接矩阵了，把station和house混在一起建立矩阵，用下标范围区分。事实证明不要想太多。

2、注意：筛选条件是到station最近距离的最大值，而非最近的距离

3、最开始第2个点答案错误。错误原因：dijkstra的外层循环次数=总结点数，最开始写成house数

```c++
for(int loop=0;loop<House+1;loop++)//错误
for(int loop=0;loop<House+Station+1;loop++)//正确，下次直接写while(1)
```

## A1111（第2、4个点错误）

第2个点错误原因：

第4个点错误原因：处理多条路径pre时，有个笔误

## A1018（第5、7个点错误，坑！）

### 思路

1、第7个点错误原因：只能沿着最短路径的方向收集多余自行车，分给后面的节点，后面节点多出来的不能填到前面去，只能计入回收总量，例如路径上自行车数为5->0->10，并不能把最后一个节点上挪5个给中间的，需要送出5个，并回收5个。大坑，题目也没明确说呀！！！

若某节点多余车，存到back中；若某节点少车，先从back中取，若back还不够则从起点取（即增加send）。下面是求send和back过程，刚开始send写错。

```c++
int send=0, back=0, D=0;
for(auto i=tmpPath.begin(); i<tmpPath.end(); i++){
	D=Bike[*i]-C/2;			
	if(D>0)//车多余 
		back+=D;
	else if(D<0){//D<=0,车不够 
		D=-D;
         if(back-D<0){//back也不够补
			send+=D-back;//再从中心send, send是+=而非=！！send是个一直累积的数 
			back=0;//back全部拿来补，变成0 
		}
		else{
			back-=D;//不够的从back中取 
         }
	}
}
```

2、第5个点错误原因：要求先按send最小，再按back最小排序。然而我不是错这个，我tm写错了。。。最近笔误太多了。。

```c++
else if(send==minSend && back<minBack){
	minBack=back;//我写反成 back=minBack;  我在做梦。。
	Path.assign(tmpPath.begin(), tmpPath.end());
}
```

## A1122（AC）

## A1126（第3个点错误）

第3个点错误原因：知识性问题。欧拉图必须要求是连通图，所以还得判断连通性！！

## A1139（部分正确，略坑）

1、又踩进格式的坑了！！ID是4位，输出时不够位数要加0！！！

2、注意ID=-0000或0000的坑。所以不能用int读，会把性别吃掉，要用string读。判断性别相同时不能用ID相乘，因为有个ID==0。格外开辟一位用来存性别。



## A1150（AC）A1142（AC）A1146（AC）A1154（AC）

# 贪心（看中的是思路，代码都较简单）

## A1125（AC）

### 思路

优先合并较短的绳子。将绳子从短到长排序，依次相加再除以2，最后的结果取整即可。

## A1033（第2、4个点错误）

1、测试点2错误原因：如果没有初始距离为0的站，返回“最大距离=0.00”

2、测试点4错误原因：当距离终点<最远里程而且中间还有加油站时，若中间加油站比现在的便宜，则加油；若比现在的贵，则直达终点不加油。之前一直默认要停下加油。反例如下：

```c++
50 800 12 3
7 0
6 600
7 700
```

3、judge系统的bug：若加油站在终点之外的反例未被测试到。反例如下：

```c++
50 700 12 3
7 0
6 600
6 1200
```

## A1037（AC）

## A1038（第5个点错误）

### 思路

第5个点错误原因：有个很恶心的反例，32和3231，应该是先3231再32，原先的cmp函数没考虑。还包括32321和32也没法比较。

### 更优解

归根到底是比较str1和str2组成的数字哪个更小，所以直接比较str1+str2和str1+str2哪个小！！！太绝了太绝了

## A1070（第2个点错误，略坑）

第2个点错误原因：月饼数量单位是 thousand tons，不一定是整数，不能设置成int类型！！！说明有些错误是数据类型设置错误引起的。

## A1067（不太会）

### 思路

1、刚开始看成任意2数交换了，次数怎么算都不对。

2、0不在正确位置时会处理，但当0处于0号位时，不知怎么处理。方法：找到数组中还不在正确位置的数，与0交换；之后重复上述操作，以0为基准进行交换。

3、找仍不在正确位置的数：普通遍历会超时。用queue存好所有不在正确位置的数，到时候遍历Queue，已经在正确位置了就pop，这样可避免重复遍历。

# 动态规划

 将大问题划分为小问题进行解决，类似分治法。但不同点是经分解得到的子问题往往不是互相独立的 ( 即下一个子阶段的求解是建立在上一个子阶段的解的基础上，进行进一步的求解 ) 

最最重要的是找到状态转移方程！！！

## A1068（不会）！！！

### 思路

1、0-1背包问题

要求装入背包中的物品的总价值最大，并且物品的总重量不超出背包的容量 。每次遍历到的第 i 个物品，根据 weight[i] 与 value[i] 来确定是否需要将该物品放入背包中。``v[i][j] `` ：前 i 个物品组合后放入总容量为j的背包中的最大价值（不是i个物品都放入，选性价比最高的一些）

(1) ``v[0][i] = v[i][0]=0;`` // 表示前0个物品最大价值=0，背包总容量为0的物品最大价值=0
(2) 当 ``weight[i] > j`` 时，``v[i][j] = v[i-1][j];`` // 当准备新增的第i个商品的重量>当前背包的容量时，就直接使用上一种装入策略，即i-1种物品
(3) 当 ``j >= weight[i]`` 时： ``v[i][j]=max{v[i-1][j], value[i] + v[i-1][j-weight[i]]};``// 状态转移方程。当准备新增的第i个商品的重量<=当前背包的容量时，要么取上一种装入策略（不放第i个），要么第i个商品价值+前i-1个商品价值（放了第i个）
``v[i-1][j-weight[i]]``：把前 i-1 个商品装到总容量=`` j-weight[i]``的包中的最大价值

2、

## A1007（不会）！！！

### 思路

我想的是判断下一个加的数的正负，正则加上，负则从计算原来seq的和，并这个数开始重新统计seq。相当于找最长一串正子列。考虑的有问题，反例： -2, 11, -4, 13, -5, -2的最大子列为11，-4，13，中间就有负数。

### 更优解

判断加上下一个数后的sum的正负，sum<0则重置整个sum=0，并从下一个数开始重新统计seq。因为sum为负时，再下一个数无论正负都会被拖小。sum>=0则比较sum和maxSum的关系，sum>maxSum时记录下左右坐标；sum<maxSum时继续往右读取。

## A1040（AC）

它本来是个DP问题，但我直接简单模拟就写出来了 （黑人问号.jpg）

## A1045（不会）！！！

### 思路

1、最长不下降子列问题LIS

在一个序列中，找到一个最长的不下降子列（可以不连续）。如果枚举，每个数都有取/不取2种情况，复杂度为O(2^n^)，显然不行。

<img src="D:\typora\Pictures\1.png" style="zoom: 70%;" />

<img src="D:\typora\Pictures\2.png" style="zoom: 67%;" />

```c++
//状态转移方程：dp[i]=max(1, dp[j]+1)
//向每一个在A[i]前面的A[j]询问要不要加上自己;实在不行自己单干
int dp[N];//以Num[i]结尾的序列的LIS的最长长度
fill(dp,dp+N,0);
dp[0]=1;//第0个元素别无选择，最长就是1
int maxL=0;
for(int i=0;i<N;i++){
	for(int j=0;j<i;j++){ 		
		if(Num[i]>=Num[j]&&dp[j]+1>dp[i])//可以加入，且加入能刷新自己的最长长度 
			dp[i]=dp[j]+1;//加入，刷新最长长度
	}
	if(dp[i]==0)//没人愿意接纳，只能自己单干 
		dp[i]=1;
	if(dp[i]>maxL) maxL=dp[i]; 
} 
cout<<maxL;
```

2、将本题转换成LIS（绝！）

（1）将color[N]中不喜欢的颜色去掉。（2）将Eva喜欢的从左到右颜色按从小到大的顺序编号，将color[N]也转换成对应编号。这样要保证Eva喜欢的顺序，也就是保证找到的子列不下降，即找最长不下降子列！！！看穿了本质就很简单了。

# other

## A1128（第1个点错误）

第1个点错误原因：注意审题，2个皇后不能在同一对角线，是任意两个皇后，不是相邻两个皇后。（我只考虑了相邻的）

# 模拟

A1167（AC）A1166（AC）A1165（AC）A1164（AC）：100，2h

A1163（AC）A1162（AC）A1161（AC）A1160（测试点3,4运行超时）：92，3h

A1159（AC）A1158（测试点2错误）1157（AC）A1156（AC）：94，3h

2018年考研机试（都做过了）：100，1.25h

2022.3PAT：58，2.5h

2021年考研机试（第4题险些0分）：95，3h

2017年考研机试（第4题之前就没做出来）：86，3h

2020年保研机试：90，3h

柳神模拟一：62，3h





## A1160（第3、4个点超时）！！！

### 思路

暴力遍历：遍历K位数，找符合条件的。求各位数和：转成string，再遍历求各位数

### 更优解

1、求各位数和：直接用int数据类型%10得到各位数。转string太耗时间，会超时

2、需要用到点数学上的分析，若末尾不是9，n=m+1，相邻两数必然互质。所以末尾必然=9，这样不用遍历K位数，只要遍历K-1位，最后末尾+9即可。遍历次数变成原来的1/10。

## A1158（第2个点错误）

看了下提示，写出来了。

测试点2错误原因：**并查集不熟练写错**。在统计有哪些帮派头目时，遍历suspect数组，把suspect[i]当成了i的头目，其实不是。因为suspect[i]只是i的上级，findFather(i)才是i的头目。

## 2022春PAT第2题（运行超时）树状数组

昨天刚看完的树状数组，他做了一点拓展，范围过大要用结构体替换，tmd就不会了。。。

姥姥知乎上说用K大小数组存，每读入一个数更新数组即可。我感觉这样做好像也超时，没验证过。。

## 2022春PAT第4题（完全不会）

## 2021年考研机试第4题（第5、6个点超时+第3个点错误）

### 思路

一直很纠结用什么保存分解出的序列，因为要去除某个值，如果在中间的话数组不好去。最终用了table[MAX]存每个i出现的次数。

### 更优解

直接用vector存，只不过vector从小到大排序，这样去除最大值的时候很方便。



## 柳神模拟一题2（超时）

### 思路

把所有素数都找到，再找到所有平衡素数。每输入一个数，就去平衡素数的集合里找存不存在。有2个点写的比较耗时：素数的判定，遍历平衡素数集合。

### 更优解

1、素数判定用素数表筛法，用bool Prime[]记录是否为素数。当对于2~MAX每一个数，它们和素数表中每个数的乘积都是合数，直接置为false。

```c++
void getPrime(){
	for(int i=2;i<MAX;i++){
		if(isPrime[i]) Prime.emplace_back(i);
		for(int j=0;j<Prime.size()&&Prime[j]*i<MAX;j++){//i与素数表中所有素数的乘积都是合数 
			isPrime[Prime[j]*i]=false;
		}
	}
} 
```

2、提前用nextBan记录好每个数的下一个平衡素数， 这样就不用每次查找了。这样判断平衡素数也省力了，因为nextBan[平衡素数]==它自身。

## 柳神模拟一题4（答案错误）

1、INF设太小了，题目数据都比INF大了！！

2、数据类型：由于题目数据大，要用long long存weight，int太小

3、findRep()可以顺便进行**路径压缩**：1->2->4->5把它变成1->5，2->5，4->5

4、dfs出来得到的path是反的，所以要比较路径大小时是要先reverse，vector可以直接用<比

5、不需要把Djikstra放在循环里做好多遍，因为一遍就能知道到所有点的最短路径！要做好几遍的是DFS，因为每次目的地不同。









~~A1008 Elevator	简单模拟~~
~~A1006 Sign In and Sign Out	简单模拟~~
~~A1036 Boys vs Girls	简单模拟~~
~~A1011 World Cup Betting	简单模拟~~
~~A1124 Raffle for Weibo Followers	简单模拟~~
~~A1042 Shuffling Machine	简单模拟~~
~~A1046 Shortest Distance	简单模拟~~
~~A1065 A+B and C (64bit)	简单模拟~~
~~A1054 The Dominant Color	Map的使用~~
~~A1039 Course List for Student	Map的使用~~
~~A1047 Student List for Course	Map的使用~~
~~A1063 Set Similarity	Set的使用~~
~~A1022 Digital Library	Map的使用~~
~~A1140 Look-and-say Sequence	字符串处理~~
~~A1005 Spell It Right	字符串处理~~
~~A1035 Password	字符串处理~~
~~A1077 Kuchiguse	字符串处理~~
~~A1112 Stucked Keyboard	字符串处理~~
~~A1071 Speech Patterns	字符串处理~~
~~A1061 Dating	字符串处理~~
~~A1082 Read Number in Chinese	字符串处理（细节比较复杂）~~
~~A1031 Hello World for U	图形输出~~
~~A1109 Group Photo	排队问题~~
A1014 Waiting in Line	快乐模拟
~~A1017 Queueing at Bank	快乐模拟~~
A1026 Table Tennis	快乐模拟
~~A1139 First Contact	快乐模拟~~
~~A1132 Cut Integer	数字处理~~
~~A1069 The Black Hole of Numbers	数字处理~~
~~A1073 Scientific Notation	数字处理~~
~~A1108 Finding Average	数字处理~~
~~A1060 Are They Equal	数字处理~~
~~A1001 A+B Format 数字相加格式化输出	数字处理~~
~~A1002 A+B for Polynomials 多项式相加	多项式加法~~
~~A1009 Product of Polynomials 多项式乘法	多项式除法~~
~~A1029 Median	中位数~~
~~A1027 Colors in Mars	进制转换~~
~~A1019 General Palindromic Number	进制转换~~
~~A1058 A+B in Hogwarts	进制转换~~
A1010 Radix	进制转换、二分查找
~~A1104 Sum of Number Segments	排列组合~~
~~A1093 Count PAT’s	排列组合~~
~~A1148 Werewolf - Simple Version	枚举~~
~~A1048 Find Coins	枚举~~
~~A1023 Have Fun with Numbers	大整数加法~~
~~A1024 Palindromic Number	大整数加法~~
~~A1136 A Delayed Palindrome	大整数加法~~
~~A1081 Rational Sum	最大公因数~~
~~A1088 Rational Arithmetic	最大公因数~~
~~A1015 Reversible Primes	进制转换、素数~~
~~A1152 Google Recruitment	素数判定~~
~~A1059 Prime Factors	素数~~
~~A1116 Come on! Let’s C	素数~~
~~A1096 Consecutive Factors	因数分解~~
~~A1120 Friend Numbers	散列~~
~~A1121 Damn Single	散列~~
~~A1050 String Subtraction	散列~~
~~A1084 Broken Keyboard	散列~~
~~A1041 Be Unique	散列~~
~~A1092 To Buy or Not to Buy	散列~~
~~A1144 The Missing Number	散列~~
~~A1149 Dangerous Goods Packaging	散列~~
~~A1128 N Queens Puzzle	八皇后问题~~
~~A1012 The Best Rank	排序~~
~~A1028 List Sorting	排序~~
A1095 Cars on Campus	排序
A1016 Phone Bills	排序
~~A1025 PAT Ranking	排序~~
~~A1062 Talent and Virtue	排序~~
~~A1055 The World’s Richest	排序~~
~~A1083 List Grades	排序~~
~~A1141 PAT Ranking of Institutions	排序~~
~~A1117 Eddington Number	排序~~
~~A1080 Graduate Admission	排序~~
~~A1113 Integer Set Partition	排序~~
A1129 Recommendation System	排序
~~A1075 PAT Judge	排序~~
~~A1153 Decode Registration Card of PAT	排序~~
~~A1070 Mooncake	贪心~~
~~A1113 Integer Set Partition	贪心~~
~~A1037 Magic Coupon	贪心~~
~~A1125 Chain the Ropes	贪心~~
~~A1038 Recover the Smallest Number	贪心~~
~~A1067 Sort with Swap(0, i)	贪心~~
~~A1033 To Fill or Not to Fill	贪心~~
~~A1100 Mars Numbers	打表~~
A1085 Perfect Sequence	二分查找
A1044 Shopping in Mars	二分查找
~~A1089 Insert or Merge	插入排序、归并排序~~
~~A1098 Insertion or Heap Sort	插入排序、堆排序~~
~~A1101 Quick Sort	快速排序主元的选取~~
~~A1051 Pop Sequence	栈~~
~~A1056 Mice and Rice	队列~~
~~A1074 Reversing Linked List	链表~~
~~A1032 Sharing	链表~~
~~A1133 Splitting A Linked List	链表~~
~~A1052 Linked List Sorting	链表~~
~~A1097 Deduplication on a Linked List	链表、散列~~
~~A1076 Forwards on Weibo	BFS~~
~~A1103 Integer Factorization	DFS~~
~~A1091 Acute Stroke	DFS、BFS~~
~~A1004 Counting Leaves	DFS~~
~~A1013 Battle Over Cities	DFS~~
~~A1147 Heaps	堆的判定~~
~~A1155 Heap Paths	堆的判定~~
~~A1078 Hashing	hash~~
~~A1145 Hashing - Average Search Time	hash~~
~~A1020 Tree Traversals	树的遍历、DFS~~
~~A1021 Deepest Root	树的遍历、树的深度、DFS~~
~~A1079 Total Sales of Supply Chain	广义树~~
~~A1090 Highest Price in Supply Chain	广义树~~
~~A1106 Lowest Price in Supply Chain	广义树~~
~~A1094 The Largest Generation	广义树~~
~~A1130 Infix Expression	广义树~~
~~A1086 Tree Traversals Again	树~~
~~A1102 Invert a Binary Tree	树~~
~~A1053 Path of Equal Weight	树~~
~~A1064 Complete Binary Search Tree	树~~
~~A1043 Is It a Binary Search Tree	树~~
~~A1099 Build A Binary Search Tree	树~~
~~A1127 ZigZagging on a Tree	树~~
~~A1115 Counting Nodes in a BST	树~~                                                                                           ~~A1138 Postorder Traversal	树~~
~~A1110 Complete Binary Tree	完全二叉树~~
~~A1143 Lowest Common Ancestor	LCA~~
~~A1151 LCA in a Binary Tree	LCA~~
~~A1135 Is It A Red-Black Tree	红黑树判定~~
~~A1066 Root of AVL Tree	AVL树~~
~~A1123 Is It a Complete AVL Tree	AVL树、完全二叉树~~
~~A1107 Social Clusters	并查集~~
~~A1118 Birds in Forest	并查集~~
~~A1034 Head of a Gang	并查集~~
~~A1114 Family Property	并查集~~
~~A1134 Vertex Cover	图~~
~~A1122 Hamiltonian Cycle	哈密顿圈的判别~~
~~A1126 Eulerian Path	欧拉图的判别~~
~~A1142 Maximal Clique	团~~
~~A1150 Travelling Salesman Problem	中国邮递员问题~~
~~A1146 Topological Order	拓扑序列的判别~~
~~A1003 Emergency 救援最短路径和最大救援部队	Dijkstra算法~~
~~A1072 Gas Station	Dijkstra算法~~
~~A1087 All Roads Lead to Rome	Dijkstra算法~~
~~A1030 Travel Plan	Dijkstra算法~~
~~A1018 Public Bike Management	Dijkstra算法、DFS~~
~A1111 Online Map	Dijkstra算法
~~A1057 Stack	分块~~
~~1007 Maximum Subsequence Sum	动态规划~~
~~A1045 Favorite Color Stripe	最长不下降子序列~~
~~A1040 Longest Symmetric String	最长回文子串~~
A1068 Find More Coins	0-1背包