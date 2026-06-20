class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // A line can always be formed by 2 points
        if (coordinates.size() <= 2) return true;
        
        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];
        int x1 = coordinates[1][0];
        int y1 = coordinates[1][1];
        
        int dx = x1 - x0;
        int dy = y1 - y0;
        
        // Check if all subsequent points maintain the same slope
        for (int i = 2; i < coordinates.size(); i++) {
            int xi = coordinates[i][0];
            int yi = coordinates[i][1];
            
            // Cross-multiplication to check slope equality: dy/dx == (yi - y0)/(xi - x0)
            if (dy * (xi - x0) != (yi - y0) * dx) {
                return false;
            }
        }
        
        return true;
    }
};;