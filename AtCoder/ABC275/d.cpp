#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (int i=(a); i<(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define all(obj) (obj).begin(), (obj).end()

const int INFI = 1 << 30;
const ll INFL = 1LL << 60;
// const ll MOD = 1000000007; // 1e9 + 7
// const ll MOD = 998244353;

int main() {
    ll N; cin >> N;
    set<ll> st;
    st.insert(0LL);
    st.insert(N);
    queue<ll> q;
    q.push(N);
    while (!q.empty()) {
        ll m = q.front();
        q.pop();
        // st.insert(m);
        if (!st.count(m/2LL)) {
            st.insert(m/2LL);
            q.push(m/2LL);
        }
        if (!st.count(m/3LL)) {
            st.insert(m/3LL);
            q.push(m/3LL);
        }
    }

    map<ll, ll> func;
    st.erase(0LL);
    func[0LL] = 1LL;
    for (const ll &k : st) {
        func[k] = func[k/2LL] + func[k/3ll];
    }

    cout << func[N] << endl;
    return 0;
}