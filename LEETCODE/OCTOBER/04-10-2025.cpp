// 11. Container With Most Water



class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        long long maxArea=0;
        while(l<r){
            int width = r-l;
            int minHeight = min(height[l],height[r]);
            long long area = width * minHeight;
            maxArea = max(maxArea, area);

            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxArea;
    }
};
