//*********����*********
//
//Ҫ����λ���������м���Ǹ����������m+n��������������(m+n)/2�������ż����������(m+n)/2��(m+n)/2+1��������ƽ����
//���仰˵���������������������ҵ�k��������ڵ�һ����������k/2����a���ڵڶ�����������k-k/2����b��
//���a>b���ڶ���������ǰk-k/2�����б�Ȼ��������k���������ڶ�������ǰk-k/2������������֮��Ȼ


class Solution {
public:
    int find_k(vector<int>& a, int l, int r, vector<int>& b, int ll, int rr, int k)
    {
        if(r - l < rr - ll) return find_k(b, ll, rr, a, l, r, k);
        if(rr == ll) return a[l+k-1];
        if(k == 1) return min(a[l], b[ll]);

        int q = min(k/2, rr-ll);
        int p = k - q;
        if(a[l+p-1] > b[ll+q-1]) return find_k(a, l, r, b, ll+q, rr, k - q);
        return find_k(a, l+p, r, b, ll, rr, k - p);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int len1 = nums1.size();
         int len2 = nums2.size();
         int k = (len1 + len2) / 2;
         if((len1+len2)&1)
            return find_k(nums1, 0, len1, nums2, 0, len2, k+1);
         else
            return (find_k(nums1, 0, len1, nums2, 0, len2, k+1) + find_k(nums1, 0, len1, nums2, 0, len2, k)) / 2.0;;
    }
};
