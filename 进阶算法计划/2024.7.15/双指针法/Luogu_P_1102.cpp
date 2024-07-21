#include <bits/stdc++.h>
#define rep(a,b,c) for(int a = b;a <= c;++a)
#define int long long
using namespace std;

const int N=2e5+5;
int n,c;
int a[N],cnt[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;
    rep(i,1,n)cin >> a[i];
    sort(a + 1, a + 1 + n);
    rep(i,1,n) {
        cnt[i]=cnt[i-1] * (int) (a[i] == a[i-1]) + 1;
    }
    int j=1, ans=0;
    rep(i,1,n) {
        //1.
        while(a[i+1] == a[i] && i + 1 <= n){
            ++i;
        }
        //2. 
        while(a[j] < a[i] - c && j <= n){
            ++j;
        }
        if(j > n)break;
        //3. 
        int cur=0;
        while(a[j] == a[i] - c && j <= n){
            ++j,++cur;
        }
        //4.
        ans += cur * cnt[i];
    }
    cout << ans << '\n';
    return 0;
}

//ACplease!!!