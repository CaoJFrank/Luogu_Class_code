#include <bits/stdc++.h>
#define int unsigned long long
#define rep(a,b,c)for(int a = b; a <= c; ++a)
using namespace std;

const int N = 1e7+5;
int a[N],b[N];
void solve() {
    int n,m;
    cin >> n >> m;
    rep(i,1,n)cin >> a[i];
    rep(i,1,m)cin >> b[i];
    int j=1,ans=0;
    rep(i,1,n) {
        //1. 第一个b[j] >= a[i]
        while(b[j] < a[i] && j<=m) { 
            ++j;
        }
        if(j > m)break;
        //2. 最后一个b[j] == a[i]的下一个
        int cnt=0;
        while(b[j] == a[i] && j<=m) {
            ++j,++cnt;
        }
        
        //3. 求值
        ans^=cnt;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}

//ACplease!!!