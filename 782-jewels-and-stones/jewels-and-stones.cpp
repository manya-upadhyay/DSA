class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        std::unordered_set<char> jewelSet(jewels.begin(), jewels.end());

        int jewelCnt =0;
        for(char stone : stones)
        {
            if(jewelSet.count(stone))
            {
              jewelCnt++;
            }
        }
        return jewelCnt;
    }
};