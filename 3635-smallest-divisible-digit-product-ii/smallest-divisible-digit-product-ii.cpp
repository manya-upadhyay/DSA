#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    struct Factor {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    };

    Factor getFactors(long long n) {
        Factor f;
        while (n % 2 == 0) { f.c2++; n /= 2; }
        while (n % 3 == 0) { f.c3++; n /= 3; }
        while (n % 5 == 0) { f.c5++; n /= 5; }
        while (n % 7 == 0) { f.c7++; n /= 7; }
        if (n > 1) return {-1, -1, -1, -1};
        return f;
    }

    Factor getDigitFactors(int d) {
        if (d <= 1) return {0, 0, 0, 0};
        return getFactors(d);
    }

    int memo[60][40];

    int dp(int c2, int c3) {
        c2 = max(0, c2);
        c3 = max(0, c3);
        if (c2 == 0 && c3 == 0) return 0;
        if (memo[c2][c3] != -1) return memo[c2][c3];

        int ans = 1e9;
        // Try digits containing factors of 2 and 3
        if (c2 >= 3) ans = min(ans, 1 + dp(c2 - 3, c3));     // Digit 8
        if (c3 >= 2) ans = min(ans, 1 + dp(c2, c3 - 2));     // Digit 9
        if (c2 >= 1 && c3 >= 1) ans = min(ans, 1 + dp(c2 - 1, c3 - 1)); // Digit 6
        if (c2 >= 2) ans = min(ans, 1 + dp(c2 - 2, c3));     // Digit 4
        if (c2 >= 1) ans = min(ans, 1 + dp(c2 - 1, c3));     // Digit 2
        if (c3 >= 1) ans = min(ans, 1 + dp(c2, c3 - 1));     // Digit 3

        return memo[c2][c3] = ans;
    }

    int minDigitsNeeded(Factor f) {
        int c2 = max(0, f.c2), c3 = max(0, f.c3);
        int c5 = max(0, f.c5), c7 = max(0, f.c7);
        return c5 + c7 + dp(c2, c3);
    }

    string constructMinDigits(Factor f, int length) {
        int c2 = max(0, f.c2), c3 = max(0, f.c3);
        int c5 = max(0, f.c5), c7 = max(0, f.c7);

        vector<int> digits;
        while (c7 > 0) { digits.push_back(7); c7--; }
        while (c5 > 0) { digits.push_back(5); c5--; }

        // Reconstruct optimal digits for 2 and 3
        while (c2 > 0 || c3 > 0) {
            int best_d = -1;
            // Pick largest digit (9 down to 2) to keep result lexicographically small
            for (int d : {9, 8, 7, 6, 5, 4, 3, 2}) {
                Factor df = getDigitFactors(d);
                if (df.c5 > 0 || df.c7 > 0) continue;
                if (c2 >= df.c2 && c3 >= df.c3) {
                    if (dp(c2 - df.c2, c3 - df.c3) == dp(c2, c3) - 1) {
                        best_d = d;
                        break;
                    }
                }
            }
            if (best_d != -1) {
                digits.push_back(best_d);
                Factor df = getDigitFactors(best_d);
                c2 -= df.c2;
                c3 -= df.c3;
            }
        }

        while ((int)digits.size() < length) {
            digits.push_back(1);
        }

        sort(digits.begin(), digits.end());
        string res = "";
        for (int d : digits) res += to_string(d);
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        memset(memo, -1, sizeof(memo));

        Factor target = getFactors(t);
        if (target.c2 == -1) return "-1";

        int n = num.length();
        int first_zero = -1;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
        }

        vector<Factor> pref(n + 1);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i];
            if (num[i] != '0') {
                Factor df = getDigitFactors(num[i] - '0');
                pref[i + 1].c2 += df.c2;
                pref[i + 1].c3 += df.c3;
                pref[i + 1].c5 += df.c5;
                pref[i + 1].c7 += df.c7;
            }
        }

        for (int i = n; i >= 0; --i) {
            if (first_zero != -1 && i > first_zero) continue;

            Factor current = pref[i];
            Factor rem = {
                target.c2 - current.c2,
                target.c3 - current.c3,
                target.c5 - current.c5,
                target.c7 - current.c7
            };

            if (i == n) {
                if (minDigitsNeeded(rem) <= 0) return num;
                continue;
            }

            int start_digit = (num[i] - '0') + 1;
            for (int d = start_digit; d <= 9; ++d) {
                Factor df = getDigitFactors(d);
                Factor next_rem = {
                    rem.c2 - df.c2,
                    rem.c3 - df.c3,
                    rem.c5 - df.c5,
                    rem.c7 - df.c7
                };

                int req = minDigitsNeeded(next_rem);
                int rem_len = n - 1 - i;
                if (req <= rem_len) {
                    string ans = num.substr(0, i) + to_string(d);
                    ans += constructMinDigits(next_rem, rem_len);
                    return ans;
                }
            }
        }

        int req = minDigitsNeeded(target);
        int len = max(n + 1, req);
        return constructMinDigits(target, len);
    }
};