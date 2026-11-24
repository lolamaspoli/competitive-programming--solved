#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i = (int) a; i < (int) b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (int)b-1; i>=(int)a;--i)
#define dforn(i,n) for(int i = (int)n-1; i>=0; i--)
#define fore(e,c) for(const auto &e: (c))
#define pb push_back
#define ln '\n'
#define sz(c) ((int)c.size())
#define zero(v) memset(v,0,sizeof(v))
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;


const int MAXN = 101;
int modulo = 1e9+7;

int memo[MAXN]; // memo[i] : cantidad de maneras distintas de formar la suma i usando las monedas

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int coins[n];

    forn(i, n){
        cin >> coins[i];
    }

    memo[0] = 1; //caso base
    for(int c : coins){ // for monedas afuera : cuento combinaciones
        forr(i,1, x+1){     //d adelante para atras: monedas infinitas
            if(i>=c){
                memo[i] = (memo[i] + memo[i-c])%modulo;
            }
            //cout << " i: " << i << " memo[i]:" << memo[i] << ln;
        }
    }
    cout << memo[x] << ln;

}
