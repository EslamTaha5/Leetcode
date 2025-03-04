class Solution {
public:
    bool can(int n, int power){
        if(!n) return true;
        if(power > n) return false;
        return can(n, power * 3) || can(n - power, power * 3);
    }
    bool checkPowersOfThree(int n) {
        return can(n, 1);
    }
};