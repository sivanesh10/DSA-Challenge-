class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int leftMax = 0;
        int rightMax = n-1;
        int maxi = 0;
        while (leftMax < rightMax) {
            maxi = max(min(height[leftMax],height[rightMax]) * (rightMax - leftMax),maxi);
            if(height[leftMax] < height[rightMax]) leftMax++;
            else rightMax--;
        }
        return maxi;
    }
};