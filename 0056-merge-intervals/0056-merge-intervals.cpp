class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      int n = intervals.size();
      vector<vector<int>> temp;
      sort(intervals.begin(),intervals.end());

      int start,end,prevStart,prevEnd;
      temp.push_back(intervals[0]);
      for(int i=1;i<n;i++) {
        start = intervals[i][0];
        end = intervals[i][1];

        prevStart = temp.back()[0];
        prevEnd = temp.back()[1];

        if(start <= prevEnd) {
            temp.pop_back();
            temp.push_back({prevStart,max(prevEnd,end)});
        }
        else temp.push_back(intervals[i]);
      }
      return temp;
    }
};