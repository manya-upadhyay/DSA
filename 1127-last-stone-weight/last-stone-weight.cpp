class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1)
        {
            std:: sort(stones.begin(),stones.end(), std::greater<int>());

            int stone1 = stones[0];
            int stone2 = stones[1];

            stones.erase(stones.begin());
            stones.erase(stones.begin());

            if(stone1!= stone2)
            {
                stones.push_back(stone1-stone2);
            }
        }

        return stones.empty() ? 0 : stones[0];
    }
};