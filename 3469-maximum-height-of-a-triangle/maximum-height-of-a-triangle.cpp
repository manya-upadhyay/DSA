class Solution {
public:
    int checkHeight(int firstColor, int secondColor) {
        int height = 0;
        int ballsNeeded = 1; 

        while (true) {
            if (height % 2 == 0) {
                if (firstColor >= ballsNeeded) {
                    firstColor -= ballsNeeded;
                } else {
                    break;
                }
            } 
            else {
                if (secondColor >= ballsNeeded) {
                    secondColor -= ballsNeeded;
                } else {
                    break;
                }
            }
            height++;     
            ballsNeeded++; 
        }
        return height;
    }

    int maxHeightOfTriangle(int red, int blue) {
        int startWithRed = checkHeight(red, blue);
        int startWithBlue = checkHeight(blue, red);
        return max(startWithRed, startWithBlue);
    }
};