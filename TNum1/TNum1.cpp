#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>


#define crivo_0_sz 10000010

typedef long long ll;

using namespace std;

bitset<crivo_0_sz> crivo_0;

vector<ll> primos_0;
vector<ll> primos_1;

ll lims_0[2] = {0,crivo_0_sz};
ll lims_1[2] = {0,0};

bool isPrime(ll n, bool out=false);

void createVectorAux(ll start , ll end){
    lims_1[0] = start;
    lims_1[1] = end;

    primos_1.clear();

    for(ll i = start ; i <= end ; i++){
        if(isPrime(i)) primos_1.push_back(i); 
    }

    return;
}

template<unsigned int len>
void createCrivo(bitset<len>& crivo, ll start = 0 , ll end = len){
    
    if (start == 0){
        crivo.set();
        crivo.reset(0);
        crivo.reset(1);
        crivo.set(2);
        start = 2;
    }
    
    primos_0.push_back(2);

    for(ll i = 4 ; i < (end) ; i+=2) crivo_0.set(i,false);

    for(ll i = 3 ; i < (end) ; i+=2){
        if(crivo_0.test(i)){
            primos_0.push_back(i);
            for(ll j = i*i ; j < end ; j+=i ){
                crivo.reset(j);
            }                
        }
    }

}

void solve(ll start, ll end,vector<ll>& primos){
    auto p0 =   std::upper_bound(primos.begin(),primos.end(),start,less_equal<>());
    auto p1 = --std::upper_bound(primos.begin(),primos.end(),end,less<>());

    auto D = distance(p0,p1);

    if(D<=0) cout<<"There are no adjacent primes.\n";
    else{

        ll v_min = -1, v_max = -1;

        vector<ll> diff(D);
        for (int i = 0; i <= (D-1) ; i++){
            diff[i] = *(p1-i) - *(p1-i-1);
            if(v_min == -1 || diff[i]<=diff[v_min]) v_min = i;
            if(v_max == -1 || diff[i]>=diff[v_max]) v_max = i;
        }

        printf("%lld,%lld are closest, %lld,%lld are most distant.\n",
            *(p1-v_min-1),*(p1-v_min),*(p1-v_max-1),*(p1-v_max));

    }   
}



int main(){
    
    createCrivo<crivo_0_sz>(crivo_0);
    ll start,end;

    while (scanf("%lld %lld",&start,&end)>0){
        if(start>=lims_0[0] && end <= lims_0[1]){
            solve(start,end,primos_0);
        }else if(start>=lims_1[0] && end <= lims_1[1]){
            solve(start,end,primos_1);
        }else{
            createVectorAux(start,end);
            solve(start,end,primos_1);
        }
    }

    return 0 ;
}

bool isPrime(ll n, bool out){
	if (n <= crivo_0_sz)
		return crivo_0[n];      // Verifica se eh primo em O(1) !!!!

	for (size_t i = 0; i < primos_0.size() && primos_0[i]*primos_0[i] <= n; ++i){  // para todos os primos calculados na faixa do crivo
		if (n % primos_0[i] == 0){
			if(out) cout << "divisor = " << primos_0[i] << endl;
			return false;
		}
	}
	return true;
}