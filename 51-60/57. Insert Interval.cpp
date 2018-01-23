//简单模拟下
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int s = newInterval.start, e = newInterval.end;
        vector<Interval> ans;
        int i;
        for(i = 0; i < intervals.size(); i++)
        {
            if(intervals[i].end >= s) break;
            ans.push_back(intervals[i]);
        }
        if(i == intervals.size()) ans.push_back(newInterval);
        else
        {
            Interval cur;
            if(intervals[i].start <= s) cur.start = intervals[i].start;
            else cur.start = s;
            for( ; i < intervals.size(); i++)
            {
                if(intervals[i].end >= e) break;
            }
            if(i == intervals.size())
            {
                cur.end = e;
                ans.push_back(cur);
            }
            else if(intervals[i].start <= e)
            {
                cur.end = intervals[i].end;
                ans.push_back(cur);
                i++;
                for( ; i < intervals.size(); i++) ans.push_back(intervals[i]);
            }
            else
            {
                cur.end = e;
                ans.push_back(cur);
                for( ; i < intervals.size(); i++) ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};