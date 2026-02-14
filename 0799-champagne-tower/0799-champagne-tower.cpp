class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double cups[101][101] = {0.0};

        cups[0][0] = poured;

        for(int r = 0 ; r <= query_row ; r++){
            for(int c = 0 ; c <= r ; c++){
                if(cups[r][c] > 1){
                    double exceed = cups[r][c]-1;
                    cups[r][c] = 1;
                    cups[r+1][c] += (exceed)/2;
                    cups[r+1][c+1] += (exceed)/2;
                }
            }
        }

        return cups[query_row][query_glass];
    }
};