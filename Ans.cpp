
// #include <bits/stdc++.h>
// using namespace std;

// int numDecodings(string s) {
//     int n = s.size();
//     if (n == 0 || s[0] == '0') return 0;
//     // dp[i] means the number of ways to decode s[0...i-1]
//     vector<int> dp(n + 1, 0);
//     dp[0] = 1; // Base case: an empty string has one way to decode (doing nothing)
//     dp[1] = s[0] != '0' ? 1 : 0;

//     for (int i = 2; i <= n; ++i) {
//         int oneDigit = s[i - 1] - '0';
//         int twoDigits = (s[i - 2] - '0') * 10 + oneDigit;
//         // Single digit decode option (1 to 9)
//         if (oneDigit >= 1) {
//             dp[i] += dp[i - 1];
//         }
//         // Two digit decode option (10 to 26)
//         if (twoDigits >= 10 && twoDigits <= 26) {
//             dp[i] += dp[i - 2];
//         }
//     }
//     return dp[n];
// }

// int main() {
//     string s;
//     cin >> s;
//     cout << numDecodings(s) << endl;
//     return 0;
// }



#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll dp[20][2][2000];

ll countValidNumbers(const string &N, int pos, bool tight, ll product, ll K) {
    if (product > K) return 0;          
    if (pos == N.size()) return 1;       
    
    if (dp[pos][tight][product] != -1) return dp[pos][tight][product];
    
    int limit = tight ? (N[pos] - '0') : 9; 
    ll count = 0;
    
    for (int digit = 0; digit <= limit; ++digit) {
        count += countValidNumbers(
            N,
            pos + 1,
            tight && (digit == limit),
            (digit == 0 && product == 1) ? 1 : product * digit, // Avoid product 0 by setting to 1
            K
        );
    }
    
    return dp[pos][tight][product] = count;
}

int main() {
    ll N, K;
    cin >> N >> K;
    // Convert N to string for easier digit-by-digit processing
    string N_str = to_string(N);
    // Initialize dp table with -1 (for memoization)
    memset(dp, -1, sizeof(dp));
    // Calculate the result
    ll result = countValidNumbers(N_str, 0, true, 1, K) - 1; // Subtract 1 to exclude 0
    cout << result << endl;
    
    return 0;
}