// Leet-Code link : https://leetcode.com/problems/check-if-it-is-a-straight-line/description/




// T.C :  O(n)
// S.C : O(1)

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {

        int x1=coordinates[0][0];
        int y1=coordinates[0][1];
        int x2=coordinates[1][0];
        int y2=coordinates[1][1];

        int dx_=(x2-x1);
        int dy_=(y2-y1);

        for(int i=1;i<coordinates.size();i++){
            
            int dx=coordinates[i][0]-coordinates[i-1][0];
            int dy=coordinates[i][1]-coordinates[i-1][1];

            if((dx*dy_) != (dy*dx_))return false;
        }

        return true;
        
    }
};
