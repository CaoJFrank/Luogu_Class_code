#include <bits/stdc++.h>
#define rep(a,b,c) for(int a = b;a <= c;++a)
using namespace std;

struct line {
    int l,r;
};


int n,m,sum,ans,k;

signed main() {
    //init
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //input
    cin >> n;
    m = 2 * n;
    vector <int> a(m),rank(m),len(m),d(m);
    vector <line> b(n);
    rep(i,0,n - 1) {
        cin >> b[i].l >> b[i].r;
    }
    //离散化
    rep(i,0,n-1) {
        a[2 * i] = b[i].l;
        a[2 * i + 1] = b[i].r;
    }
    sort(a.begin(),a.end());
    auto ed = unique(a.begin(),a.end());
    k=ed - a.begin();
    rep(i,0,n - 1){
        rank[2 * i] = lower_bound(a.begin(),ed,b[i].l) - a.begin();
        rank[2 * i + 1] = lower_bound(a.begin(),ed,b[i].r) - a.begin();
    }
    //差分
    rep(i,0,n-1) {
        ++d[rank[2 * i]],--d[rank[2 * i + 1]];
    }
    //求出答案
    rep(i,1,k-1){
        len[i] = a[i] - a[i - 1];
    }
    rep(i,0,k-1){
        if(sum) ans += len[i];
        sum += d[i];
    }
    cout << ans << '\n';
    return 0;
}

//ACplease!!!