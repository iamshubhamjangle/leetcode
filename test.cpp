class Solution {
    const uint64_t MOD = 184467440737091;

    public:
    vector<int> sumPrefixScores(vector<string> &words) {
        unordered_map<uint64_t, int> pref;
        for (auto w: words) {
            uint64_t hash = 0;

            for (auto c: w) {
                hash = (131313 * hash + (c - 96)) % MOD;
                ++pref[hash];
            }

        }

        vector<int> answer;
        for (auto w: words) {
            uint64_t hash = 0;
            int ans = 0;
            for (auto c: w) {
                hash = (131313 * hash + (c - 96)) % MOD;
                ans += pref[hash];
            }
            answer.push_back(ans);
        }

        return answer;
    }
};