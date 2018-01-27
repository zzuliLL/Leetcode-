//将nums1中的元素先存起来，这样空间复杂度为O(m)，时间复杂度为O(max(m, n));
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> s;
        for(int i = 0; i < m; i++) s.push_back(nums1[i]);
        int i, j, k; i = j = k = 0;
        while(i < m && j < n)
        {
            if(s[i] < nums2[j]) nums1[k++] = s[i], i++;
            else nums1[k++] = nums2[j], j++; 
        }
        while(i < m) nums1[k++] = s[i], i++;
        while(j < n) nums1[k++] = nums2[j], j++;
    }
};