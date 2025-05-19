class Solution {
public:
    string triangleType(vector<int>& v) {
        if(v[0] > v[1]) swap(v[0], v[1]);
        if(v[0] > v[2]) swap(v[0], v[2]);
        if(v[1] > v[2]) swap(v[1], v[2]);
        if(v[0] + v[1] <= v[2]) return "none";
        if(v[2] == v[0]) return "equilateral";
        else if(v[1] == v[0] || v[1] == v[2]) return "isosceles";
        return "scalene";
    }
};