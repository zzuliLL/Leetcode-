//*********二分*********
//
//要找中位数就是找中间的那个数，如果是m+n是奇数，就是找(m+n)/2，如果是偶数，就是找(m+n)/2和(m+n)/2+1两个数的平均数
//换句话说就是在两个有序数组中找第k大的数，在第一个数组中找k/2的数a，在第二个数组中找k-k/2的数b，
//如果a>b，第二个数组中前k-k/2个数中必然不包括第k个数，将第二个数组前k-k/2个数舍弃。反之亦然


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
