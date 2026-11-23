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
const int MAXSUM = 100001;

bool memo[MAXSUM]; // memo[i] : true si i es una suma valida.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int coins[n];
    forn(i, n){
        cin >> coins[i];
    }

    int sumas = 0;
    memo[0] = true; //caso base
    for(int c : coins){  
        dforn(j, MAXSUM ){  //para atras asi no repite elementos
            if(j>=c){
                memo[j] = memo[j-c];
            }
        }
    }
    forr(i, 1, MAXSUM){
        if(memo[i])sumas++;
    }
    cout << sumas << ln;
    forr(i, 1, MAXSUM ){
        if(memo[i]){
            cout << i << " ";
        }
    }

    return 0;
}
