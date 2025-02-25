        #include <bits/stdc++.h>
        using namespace std;

        #define int long long
        #define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
        typedef vector<int> vi;
        typedef vector<string> vs;
        #define prec(x) cout << fixed << setprecision(x)
        #define bpc(x) __builtin_popcountll(x)
        #define cy cout << "YES" << endl
        #define cn cout << "NO" << endl
        #define M 1000000007
        #define pi 3.14159265358979323846
        #define ull unsigned long long
        #define read(a, n) for(int i=0;i<n;i++) cin >> a[i]
        #define print(a, n) for(int i=0;i<n;i++) cout << a[i] << " "; cout << endl
        #define INF (long long)1e18
        set<int> prime_set;
        #define all(x) x.begin(), x.end()
        #define vpii vector<pair<int,int>>
        #define mpii map<int,int>
        #define fi first
        #define se second
        #define rep(i,a,b) for(int i=a;i<b;i++)
        #define pb push_back
        #define pp pop_back

        // Modular Operations
        int madd(int a, int b) { return (a + b) % M; } int msub(int a, int b) { return (((a - b) % M) + M) % M; } int mmul(int a, int b) { return ((a % M) * (b % M)) % M; } int mpow(int base, int exp) { int res = 1; while (exp) { if (exp % 2 == 1) res = (res * base) % M; exp >>= 1; base = (base * base) % M; } return res; } int minv(int base) { return mpow(base, M - 2); } int mdiv(int a, int b) { return mmul(a, minv(b)); }

        // Convert number to binary string
        string tobinary(int n) { string s = ""; int x = 64; while (x--) { s += (n & 1) ? "1" : "0"; n >>= 1; } while (s[s.size() - 1] == '0') s.pop_back(); reverse(s.begin(), s.end()); return s; }

        // Convert binary string to decimal 
        int todecimal(string s) { int ans = 0, p = 1; reverse(s.begin(), s.end()); for (char c : s) { if (c == '1') ans += p; p *= 2; } return ans; }

        // Create vector of prime numbers

        // Conditional sorting of vector of pairs
        bool sortcon(const pair<int, int>& a, const pair<int, int>& b) { return a.first == b.first ? a.second > b.second : a.first < b.first; }

        // Prime factorization
        vector<int> primefact(int x) { vector<int> pf; if (x % 2 == 0) { while (x % 2 == 0) pf.push_back(2), x /= 2; } for (int i = 3; i * i <= x; i += 2) { if (x % i == 0) { while (x % i == 0) pf.push_back(i), x /= i; } } if (x > 2) pf.push_back(x); return pf; }

        // Debugging macros
        #ifndef ONLINE_JUDGE
        #define debug(x) cerr << #x <<": "; deb(x); cerr << endl;
        #else
        #define debug(x)
        #endif

        void deb(int t) { cerr << t; } void deb(string t) { cerr << t; } void deb(char t) { cerr << t; } void deb(double t) { cerr << t; } void deb(ull t) { cerr << t; }
        template <class T, class V> void deb(pair<T, V> p) { cerr << "{"; deb(p.fi); cerr << ","; deb(p.se); cerr << "}"; } template <class T> void deb(vector<T> v) { cerr << "[ "; for (T i : v) { deb(i); cerr << " "; } cerr << "]"; } template <class T> void deb(set<T> v) { cerr << "[ "; for (T i : v) { deb(i); cerr << " "; } cerr << "]"; } template <class T> void deb(multiset<T> v) { cerr << "[ "; for (T i : v) { deb(i); cerr << " "; } cerr << "]"; } template <class T, class V> void deb(map<T, V> v) { cerr << "[ "; for (auto i : v) { deb(i); cerr << " "; } cerr << "]"; }

        const int MAX_N = 2e6 + 10;

        vector<int> prime(MAX_N , 0);

        void seive(){
            for(int i= 2; i < MAX_N;i++){
            if(prime[i]==0) for(int j = i ; j < MAX_N ; j+= i ){
                    prime[j]=i; 
                }
            }
        }

        void solve() {
            int n; cin>> n;
            map<int, vector<int>> mp;
            for(int i=0;i<n;i++){
                int x; cin >> x;
                while(x != 1){
                    int ct=0;
                    int j = prime[x];
                    if(j == 0){
                        mp[j].pb(1);
                        x=1;
                        continue;
                    }
                 while(x%j==0){
                        x/=j;
                        ct++;
                    }
                    mp[j].pb(ct);
                }
            }
            int ans =1;
            for(auto it : mp){
                if(it.se.size() <= n-2) continue;
                sort(all(it.se));
                int pow =0;
                if(it.se.size() == n-1){
                    pow = it.se[0];
                }else pow = it.se[1];
                while(pow>0){
                    ans *= it.fi;
                    pow--;
                }
            }
            cout << ans << endl;
        }

        // Main Function
        int32_t main() {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            
            int tt=1;
            seive();
            
            while (tt--) {
                solve();
            }
            
            return 0;
        }
