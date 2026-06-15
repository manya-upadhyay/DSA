class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>cnt(501,0);
        for(int num : arr)
        {
            cnt[num]++;
        }

        for(int i=500; i>0; i--)
        {
            if(cnt[i]==i)
             {
                return i;
              }
        }
        return -1;
    }
};