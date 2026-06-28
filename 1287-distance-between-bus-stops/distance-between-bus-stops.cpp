#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int distanceBetweenBusStops(std::vector<int>& distance, int start, int destination) {
        // Ensure start is always the smaller index to simplify range accumulation
        if (start > destination) {
            std::swap(start, destination);
        }
        
        int clockwise_distance = 0;
        for (int i = start; i < destination; ++i) {
            clockwise_distance += distance[i];
        }
        
        int total_distance = std::accumulate(distance.begin(), distance.end(), 0);
        
        // Counterclockwise distance is the remainder of the circle
        int counterclockwise_distance = total_distance - clockwise_distance;
        
        return std::min(clockwise_distance, counterclockwise_distance);
    }
};