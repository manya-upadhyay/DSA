#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> distributeCandies(int candies, int num_people) {
        std::vector<int> result(num_people, 0);
        int loops = 0;
        
        while (candies > 0) {
            for (int i = 0; i < num_people; ++i) {
                // The current person should ideally receive: loops * num_people + (i + 1)
                int expected_candies = loops * num_people + (i + 1);
                
                // Give them either what they expect or whatever is left
                int give = std::min(candies, expected_candies);
                result[i] += give;
                candies -= give;
                
                if (candies == 0) break;
            }
            loops++;
        }
        
        return result;
    }
};