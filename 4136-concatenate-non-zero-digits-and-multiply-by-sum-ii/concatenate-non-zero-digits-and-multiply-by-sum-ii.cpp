class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;

        // 1. Precompute powers of 10 modulo 10^9 + 7
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // 2. Filter and store non-zero digits and their original counts
        vector<int> digits;
        vector<int> prefix_sum = {0}; // To quickly get sum of digits
        vector<long long> prefix_val = {0}; // To quickly extract number value
        
        // map_idx[i] stores how many non-zero elements are strictly before index i
        vector<int> map_idx(m + 1, 0); 
        
        for (int i = 0; i < m; i++) {
            map_idx[i] = digits.size();
            if (s[i] != '0') {
                int d = s[i] - '0';
                digits.push_back(d);
                prefix_sum.push_back(prefix_sum.back() + d);
                prefix_val.push_back((prefix_val.back() * 10 + d) % MOD);
            }
        }
        map_idx[m] = digits.size(); // Boundary case

        vector<int> answer;
        answer.reserve(queries.size());

        // 3. Process each query in O(1) time
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            // Find the boundary indices in our compressed "digits" array
            int L_idx = map_idx[l];
            int R_idx = map_idx[r + 1]; // exclusive upper bound

            // If there are no non-zero digits in this range
            if (L_idx >= R_idx) {
                answer.push_back(0);
                continue;
            }

            // Calculate the total digit sum for the range
            long long sum = prefix_sum[R_idx] - prefix_sum[L_idx];

            // Extract the concatenated integer value using math:
            // value = (prefix_val[R] - prefix_val[L] * 10^(R - L)) % MOD
            int num_digits = R_idx - L_idx;
            long long x = (prefix_val[R_idx] - (prefix_val[L_idx] * pow10[num_digits]) % MOD + MOD) % MOD;

            // Compute final answer for the query
            long long ans = (x * sum) % MOD;
            answer.push_back(ans);
        }

        return answer;
    }
};