class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>temp(nums1.begin(), nums1.end());
        for (int i=0, j=0, k=0; k<nums1.size(); k++)
        {
            if (i==m)
            {
                nums1[k]=nums2[j];
                j++;
            }
            else if (j==n)
            {
                nums1[k]=temp[i];
                i++;
            }
            else if (temp[i]<nums2[j])
            {
                nums1[k]=temp[i];
                i++;
            }
            else
            {
                nums1[k]=nums2[j];
                j++;
            }
        }
    }
};