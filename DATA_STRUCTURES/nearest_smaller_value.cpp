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

const ll INFLL = 1e18; // 9e18 puede desbordar si le sumás algo, 1e18 es más seguro xd
const int INF = 1e9;
const int MAXN = 5000;
vector<pii> adj[MAXN];




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int nros[n];
    forn(i, n){
        cin >> nros[i];
    }
    stack<pii> st; //(numero, posicion)
    forn(i, n){

        while(!st.empty() && nros[i] <= st.top().first){
            st.pop();
        }
        if( st.empty() ){
            cout << "0" << " ";
        } else {
            cout << st.top().second << " ";
        }
        st.push({nros[i], i+1});
    }

    return 0;
}
