#include <vector>
#include <algorithm>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    std::vector<std::vector<int>> mergedIntervals;
    
    if (intervals.empty()) return mergedIntervals;
    
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });
    
    mergedIntervals.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= mergedIntervals.back()[1]) {
            mergedIntervals.back()[1] = std::max(mergedIntervals.back()[1], intervals[i][1]);
        } else {
            mergedIntervals.push_back(intervals[i]);
        }
    }
    
    return mergedIntervals;
}
