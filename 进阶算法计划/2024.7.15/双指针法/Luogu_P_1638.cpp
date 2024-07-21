#include <bits/stdc++.h>
#define rep(a,b,c) for(int a = b;a <= c;++a)
using namespace std;

const int N = 1e6 + 6, M = 2e3 + 3;
int n,m,w;
int l,r,mn = 1e6 + 1;
int a[N], c[M];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    rep(i,1,n)cin >> a[i];
    ++w,++c[a[1]];
    int j=1;
    rep(i,1,n){
        //1.找到第一个包含m种元素的右端点
        while(w < m && j <= n) {
            ++j;
            if(!c[a[j]])++w;
            ++c[a[j]];
        }
        if(j > n)break;
        //2.记录
        if(j - i + 1 < mn) {
            mn = j - i + 1,l = i,r = j;
        }
        //3.消除贡献
        --c[a[i]];
        if(!c[a[i]])--w;
    }
    cout << l << ' ' << r << '\n';
    return 0;
}

//ACplease!!!