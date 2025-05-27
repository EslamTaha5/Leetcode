class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = (n + 1) * n / 2;
        int div = m * (n / m) * (n / m + 1);
        return sum - div;
    }
};