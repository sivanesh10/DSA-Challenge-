class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size(), m = word.size();
        int ans = 0;

        for (int i = 0; i + m <= n; i++) {

            if (sequence[i] != word[0]) continue;

            int k = 0;
            int j = i;

            while (j + m <= n) {
                bool ok = true;
                for (int t = 0; t < m; t++) {
                    if (sequence[j + t] != word[t]) {
                        ok = false; break;
                    }
                }
                if (!ok) break;

                k++;
                j += m;
            }

            ans = max(ans, k);
        }

        return ans;
    }
};
