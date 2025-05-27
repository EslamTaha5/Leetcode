class Solution {
public:
    int differenceOfSums(int n, int m) {
         return (n + 1) * n / 2 -
         m * (n / m) * (n / m + 1);
    }
};