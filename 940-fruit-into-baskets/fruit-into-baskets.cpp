class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0, maxLen=0;
        unordered_map<int,int>basket;
        for(r=0; r<fruits.size(); r++)
        {
            basket[fruits[r]]++;

            while(basket.size()>2)
            {
                basket[fruits[l]]--;
                if(basket[fruits[l]]==0)
                {
                    basket.erase(fruits[l]);
                }
                l++;
            }
            maxLen = max(maxLen,r-l+1);
        }
        return maxLen;
    }
};