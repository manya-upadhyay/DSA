#include <vector>
#include <queue>

class KthLargest {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int maxSize;

public:
    KthLargest(int k, std::vector<int>& nums) {
        maxSize = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        // If the heap grows larger than k, remove the smallest element
        if (minHeap.size() > maxSize) {
            minHeap.pop();
        }
        
        // The top of the min-heap is now the k-th largest element
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */