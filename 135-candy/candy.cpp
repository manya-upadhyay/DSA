class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int totalCandies=n;
        int i=1;
        while(i<n)
        {
            if(ratings[i]==ratings[i-1])
            {
                i++;
                continue;
            }
            int currPeak=0;
            while(i<n && ratings[i]>ratings[i-1])
            {
                currPeak++;
                totalCandies= totalCandies+currPeak;
                i++;
            }
            if(i==n)
            {
                return totalCandies;
            }
            int currValley=0;
            while(i<n && ratings[i]<ratings[i-1])
            {
                currValley++;
                totalCandies= totalCandies+currValley;
                i++;
            }
            totalCandies = totalCandies-min(currPeak,currValley);
        }
        return totalCandies;
    }
};