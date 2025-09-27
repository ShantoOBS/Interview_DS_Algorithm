
/*
    	Company Tags  		          : will update later
    	Leetcode Link 		          : https://leetcode.com/problems/largest-triangle-area/description/?envType=daily-question&envId=2025-09-27
*/


/*************************************************************** C++ *************************************************/
//Approach-1 (Brute Force)
// T.C : O(n^3)
// S.C : O(1)
class Solution {
public:
    double solve(double x1,double y1,double x2,double y2,double x3,double y3){
        return abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2.0;
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0;

        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                for (int k = j+1; k < n; k++) {
                    double area = solve(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]);
                    maxArea = max(maxArea, area);
                }

        return maxArea;
    }
};
