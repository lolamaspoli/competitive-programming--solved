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

int memo[MAXSUM][MAXN]; // memo[i][j] : 1 si i es una suma valida usando las primeras j monedas, 0 si no, -1 si no se.
int coins[MAXN];

int dp(int suma, int c){           //c esta 1-indexed
    if (suma < 0 || c == 0) return 0;
    if(suma == 0 ) return 1;  //caso base
    if(memo[suma][c] != -1) return memo[suma][c];
    memo[suma][c] = dp(suma, c-1) || dp(suma-coins[c-1], c-1);   //no uso esa moneda nueva o la uso y veo si llego a la suma
    return memo[suma][c];
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int total = 0;
    forn(i, n){
        cin >> coins[i];
        total += coins[i];
    }
    memset(memo, -1, sizeof(memo));
    int sumas = 0;
    dp(total, 1);

    forr(i, 1, MAXSUM){
        if(memo[i][n])sumas++;
    }
    cout << sumas << ln;
    forr(i, 1, MAXSUM ){
        if(memo[i][n]){
            cout << i << " ";
        }
    }

    return 0;
}
