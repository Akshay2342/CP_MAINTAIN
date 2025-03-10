// #include <iostream>
// #include <vector>
// #include <queue>
// #include <map>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// void insertNode(TreeNode* &root, int u, int v, char lr) {
//     if (root == nullptr) return;
    
//     if (root->val == u) {
//         if (lr == 'L') {
//             root->left = new TreeNode(v);
//         } else if (lr == 'R') {
//             root->right = new TreeNode(v);
//         }
//     } else {
//         insertNode(root->left, u, v, lr);
//         insertNode(root->right, u, v, lr);
//     }
// }

// vector<int> levelOrderTraversal(TreeNode* root) {
//     vector<int> result;
//     if (root == nullptr) {
//         return result;
//     }

//     queue<TreeNode*> q;
//     q.push(root);

//     while (!q.empty()) {
//         TreeNode* node = q.front();
//         q.pop();

//         if (node != nullptr) {
//             result.push_back(node->val);
//             q.push(node->left);
//             q.push(node->right);
//         } else {
//             result.push_back(-1);
//         }
//     }

//     return result;
// }

// int main() {
//     int n;
//     cin >> n;

//     TreeNode* root = nullptr;
//     map<int, TreeNode*> nodes; 
    
//     for (int i = 0; i < n-1; ++i) {
//         int u, v;
//         char lr;
//         cin >> u >> v >> lr;
        
//         if (nodes.find(u) == nodes.end()) {
//             nodes[u] = new TreeNode(u);
//             if (root == nullptr) root = nodes[u];
//         }
        
//         if (lr == 'L') {
//             nodes[u]->left = new TreeNode(v);
//             nodes[v] = nodes[u]->left;
//         } else if (lr == 'R') {
//             nodes[u]->right = new TreeNode(v);
//             nodes[v] = nodes[u]->right;
//         }
//     }
//     int k ; cin>>k;
//     vector<int> trav = levelOrderTraversal(root);
// int i = 0;
// vector<int> fans;
// while (i < trav.size()) {
//     int ct = 0;
//     while (i < trav.size() && trav[i] == -1) {
//         ct++;
//         i++;
//     }
    
//     if (ct > 0) {
//         fans.push_back(ct);
//     }
    
//     if (i < trav.size()) {
//         fans.push_back(trav[i]);
//         i++;
//     }
// }
// fans.pop_back();
// string ans ="";
// for(int i=0;i<k;i++){
//    if(i<fans.size()) ans += (fans[i]+'0');
//     else ans += '!';
// }
// cout << ans <<endl;
//     return 0;
// }
 #include <bits/stdc++.h>
 using namespace std;
#define int long long

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
typedef vector<int> vi;
typedef vector<string> vs;
 #define prec(x)                     cout << fixed << setprecision(x)
#define bpc(x)                      __builtin_popcountll(x)
#define cy                          cout << "YES" << endl
#define cn                          cout << "NO" << endl
#define M                           1000000007
#define pi                          3.14159265358979323846
#define ull                          unsigned long long
#define read(a, n)                  for(int i=0;i<n;i++)    cin >> a[i]
#define print(a, n) for(int i=0;i<n;i++) cout << a[i] << " "; cout << endl
vector<int>prime;
#define INF (long long)1e18
set<int>prime_set;
#define all(x) x.begin(), x.end()
#define vpii vector<pair<int,int>>
#define mpii map<<int,int
 #define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb                          push_back
#define pp                          pop_back
/*------------------------------------------------FUNCTIONS------------------------------------------------*/
//Modular Operations 
 
int madd(int a,int b) 
{
    return (a+b)%M;
}
int msub(int a,int b)
{
    return (((a-b)%M)+M)%M;
}
int mmul(int a,int b)
{
    return ((a%M)*(b%M))%M;
}
int mpow(int base,int exp) 
{
    int res = 1;
    while(exp) 
    {
        if(exp%2==1)
        {
            res = (res*base)%M;
        }
        exp>>=1;
        base=(base*base)%M;
    }
    return res;
}
int minv(int base)
{
    return mpow(base,M-2);
}
int mdiv(int a,int b)
{
    return mmul(a,minv(b));
}
 
//Function of converting a number into its binary string
string tobinary(int n)
{
    string s="";
    int x=64;
    while(x--)
    {
        if(n&1)
        {
            s+="1";
        }
        else
        {
                s+="0";
        }
        n>>=1;
    }
    while(s[s.size()-1]=='0')
    {
        s.pop_back();
    }
    reverse(s.begin(),s.end());
    return s;
}
 
//Function of converting a binary string into a number
int todecimal(string s)
{
    int ans=0;
    reverse(s.begin(),s.end());
    int p=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            ans+=p;
        }
        p*=2;
    }
    return ans;
}
 
//Function for creating a vector of prime numbers
void primes(int n)
{
    prime.assign(n+1,1);
    for (int p=2;p*p<=n;p++) 
    {
        if(prime[p]) 
        {
            for (int i=p*p;i<=n;i+=p)
            {
                prime[i]=0;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i])
        {
            prime_set.insert(i);
        }
    }
}
 
//Conditional sorting in vector of pairs
bool sortcon(const pair<int,int>&a,const pair<int,int>&b)
{
    if(a.first==b.first)
    {
        return(a.second>b.second);
    }
    return a.first<b.first;
}

vector<int> primefact(int x){
    vector<int> pf;
    if(x%2 ==0){
        while(x){
            pf.push_back(2);
            x=x/2;
            if((x)%2==0) {  continue; }
            else break;
        }
    }
        for(int i=3;i* i <= x ;i+=2){
            if(x%i ==0){
            while(x){
            pf.push_back(i);
            x=x/i;
            if((x)%i==0) {  continue; }
            else break;
        }
    }
}
if(x>2) pf.push_back(x);
    return pf;
}

 #ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<": "; deb(x); cerr << endl;
#else
#define debug(x)
#endif
 
void deb(int t) {cerr << t;}
void deb(string t) {cerr << t;}
void deb(char t) {cerr << t;}
void deb(double t) {cerr << t;}
void deb(ull t) {cerr << t;}
 
template <class T, class V> void deb(pair <T, V> p) {cerr << "{"; deb(p.ff); cerr << ","; deb(p.ss); cerr << "}";}
template <class T> void deb(vector <T> v) {cerr << "[ "; for (T i : v) {deb(i); cerr << " ";} cerr << "]";}
template <class T> void deb(set <T> v) {cerr << "[ "; for (T i : v) {deb(i); cerr << " ";} cerr << "]";}
template <class T> void deb(multiset <T> v) {cerr << "[ "; for (T i : v) {deb(i); cerr << " ";} cerr << "]";}
template <class T, class V> void deb(map <T, V> v) {cerr << "[ "; for (auto i : v) {deb(i); cerr << " ";} cerr << "]";}
//*----------------------------------------MAINCODE----------------------------------------------*//

const int N = 1e6;

bool func( int x, vector<vector<int>> &A){
    for(auto it : A){
        
    }
}

void solve(int n , vector<vector<int>> A){
    // vector<pair<int,int>> v;
    
    // for(auto it : A){
    //     v.push_back({it[0] ,it[2]  });
    //     v.push_back({it[1]+1 , -1*it[2] });
    // }
    // sort(v.begin(),v.end());
    // int cur=0;
    // int ans =0;
    // for(auto i : v){
    //     cur += i.second;
    //     ans = max(ans,cur);
    // }
    // cout << ans << endl;

    // int lo =0;
    // int hi =1e9+10;
    // while(hi - lo > 1){
    //     int mid = (hi + lo)/2;
    //     // if(func())

    // }

}
int32_t main(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int tt=1;
 while(tt--)
 {
solve(3, {{2,2,1},{2,3,3},{2,3,1}} );
 }
 }