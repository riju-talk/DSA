#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        long long prefixA = 0;
        long long maxB = 0;
        long long ans = 0;

        for (int i = 0; i < min(n, k); i++) {
            prefixA += a[i];
            maxB = max(maxB, (long long)b[i]);

            // i+1 quests used for unlocking
            long long remaining = k - (i + 1);
            long long total = prefixA + remaining * maxB;
            ans = max(ans, total);
        }

        cout << ans << "\n";
    }
    return 0;
}
