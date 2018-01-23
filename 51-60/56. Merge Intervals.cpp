//不明白排序函数为什么要写成静态的
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
    static bool cmp(Interval a, Interval b)
    {
        if(a.start != b.start) return a.start < b.start;
        return a.end < b.end;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans;
        int s, e;
        s = intervals[0].start;
        e = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++)
        {
            int mid = intervals[i].start;
            if(s <= mid && e >= mid) e = max(intervals[i].end, e);
            else
            {
                Interval cur = Interval(s, e);
                ans.push_back(cur);
                s = mid;
                e = intervals[i].end;
            }
        }
        Interval cur = Interval(s, e);
        ans.push_back(cur);
        return ans;
    }
};