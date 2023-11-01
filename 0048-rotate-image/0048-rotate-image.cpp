class Solution {
public:
    tuple<int, int> cord(int y, int x, int n)
    {
        int newY = x;
        int newX = n - 1 - y;

        return make_tuple(newY, newX);
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < (n + 1) / 2; j++)
            {
                tuple<int, int> one = cord(i, j, n);
                tuple<int, int> two = cord(get<0>(one), get<1>(one), n);
                tuple<int, int> three = cord(get<0>(two), get<1>(two), n);
                tuple<int, int> four = cord(get<0>(three), get<1>(three), n);

                int temp = matrix[get<0>(one)][get<1>(one)];
                matrix[get<0>(one)][get<1>(one)] = matrix[get<0>(four)][get<1>(four)];
                matrix[get<0>(four)][get<1>(four)] = matrix[get<0>(three)][get<1>(three)];
                matrix[get<0>(three)][get<1>(three)] = matrix[get<0>(two)][get<1>(two)];
                matrix[get<0>(two)][get<1>(two)] = temp;
            }
        }
    }
};