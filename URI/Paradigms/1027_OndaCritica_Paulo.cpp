#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<long int, null_type, less<long int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*
	o.find_by_order(index)
	o.order_of_key(value)	
	o.find(value)
*/

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007ll

#define MP make_pair
#define PB push_back
#define F first
#define S second

#define MAXN 100010
#define MAXM 
#define endl '\n'

#define cind(a) scanf("%lf", &a)
#define cinc(a) scanf(" %c", &a)
#define cinll(a) scanf("%lld", &a)

#define cini(a) scanf("%ld", &a)
#define cin2i(a, b) scanf("%ld %ld", &a, &b)
#define cin3i(a, b, c) scanf("%ld %ld %ld", &a, &b, &c)
#define cin4i(a, b, c, d) scanf("%ld %ld %ld %ld", &a, &b, &c, &d)
#define cin5i(a, b, c, d, e) scanf("%ld %ld %ld %ld %ld", &a, &b, &c, &d, &e)

#define coutd(a) printf("%lf", a)
#define coutdl(a) printf("%lf\n", a)
#define coutc(a) printf("%c", a)
#define coutcl(a) printf("%c\n", a)
#define coutll(a) printf("%lld", a)
#define coutlll(a) printf("%lld\n", a)

#define couti(a) printf("%ld", a)
#define coutil(a) printf("%ld\n", a)
#define cout2i(a, b) printf("%ld %ld\n", a, b)
#define cout3i(a, b, c) printf("%ld %ld %ld\n", a, b, c)
#define cout4i(a, b, c, d) printf("%ld %ld %ld %ld\n", a, b, c, d)
#define cout5i(a, b, c, d, e) printf("%ld %ld %ld %ld %ld\n", a, b, c, d, e)

#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

typedef long long int ll;
typedef pair<long int, long int> pii;

pii vet[1010];
int n;

int memo[1010][1010][2];

int pd(int i, int b, bool up){
	
	if(i > n)
		return 0;
	
	if(memo[i][b][up] != -1)
		return memo[i][b][up];
	
	if(b == 0){
		return memo[i][b][up] = max(pd(i+1, 0, up), 1 + max(pd(i+1, i, true), pd(i+1, i, false)) );
	}
	
	if(vet[b].F == vet[i].F)
		return memo[i][b][up] = pd(i+1, b, up);
		
	if(up){
		
		if( (vet[i].S - vet[b].S) == 2)
			return memo[i][b][up] = max(pd(i+1, b, up), pd(i+1, i, !up) + 1);
		else
			return memo[i][b][up] = pd(i+1, b, up);
		
	}else{
		
		if( (vet[b].S - vet[i].S) == 2)
			return memo[i][b][up] = max(pd(i+1, b, up), pd(i+1, i, !up) + 1);
		else
			return memo[i][b][up] = pd(i+1, b, up);		
	}
	
	return memo[i][b][up] = 0;
}

int main(){	
	
	while(cin >> n){
		memset(memo, -1, sizeof(memo));
		
		for(int i=1; i<=n;  i++){
			cin >> vet[i].F  >> vet[i].S;
		}
		
		sort(vet+1, vet+n+1);
		
		cout << pd(1, 0, true) << endl;
	}
		
	return 0;
}
