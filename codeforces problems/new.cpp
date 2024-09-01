#include "bits/stdc++.h"
#define ll long long
using namespace std;
#define endl "\n"

int max_effective_batch_length(const vector<int>& batch_a, const vector<int>& batch_b) {
    int n = batch_a.size();
    if (n == 0) return 0;
    
    // dp[i][0] - max length of effective batch ending with batch_a[i]
    // dp[i][1] - max length of effective batch ending with batch_b[i]
    vector<vector<int>> dp(n, vector<int>(2, 1));
    int max_length = 1;
    
    for (int i = 1; i < n; ++i) {
        if (batch_a[i] >= batch_a[i-1]) {
            dp[i][0] = dp[i-1][0] + 1;
        }
        if (batch_a[i] >= batch_b[i-1]) {
            dp[i][0] = max(dp[i][0], dp[i-1][1] + 1);
        }
        
        if (batch_b[i] >= batch_b[i-1]) {
            dp[i][1] = dp[i-1][1] + 1;
        }
        if (batch_b[i] >= batch_a[i-1]) {
            dp[i][1] = max(dp[i][1], dp[i-1][0] + 1);
        }
        
        max_length = max(max_length, dp[i][0]);
        max_length = max(max_length, dp[i][1]);
    }
    
    return max_length;
}

int main() {
    vector<int> batch_a = {5, 2, 4, 1};
    vector<int> batch_b = {3, 6, 2, 2};
    
    int result = max_effective_batch_length(batch_a, batch_b);
    cout << "Maximum length of effective batch: " << result << endl;
    
    return 0;
}
