class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {
        std::vector<int> record;

        for (const std::string& op : operations) {
            if (op == "+") {
                // Add the sum of the last two scores
                int top1 = record[record.size() - 1];
                int top2 = record[record.size() - 2];
                record.push_back(top1 + top2);
            } 
            else if (op == "D") {
                // Double the last score
                record.push_back(2 * record.back());
            } 
            else if (op == "C") {
                // Invalidate/remove the last score
                record.pop_back();
            } 
            else {
                // It's an integer, convert string to int and record it
                record.push_back(std::stoi(op));
            }
        }

        // Sum up all the valid scores in the record
        return std::accumulate(record.begin(), record.end(), 0);
    }
};