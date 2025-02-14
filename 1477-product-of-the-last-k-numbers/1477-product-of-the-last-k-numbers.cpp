class ProductOfNumbers {
public:
    vector<int> numbers{1};
    int id = 0;
    ProductOfNumbers() {
    
    }
    
    void add(int num) {
        if(!num){
            numbers.clear();
            num = 1;
        }else num *= numbers.back();
        numbers.push_back(num);
    }
    
    int getProduct(int k) {

        if(k >= numbers.size()) return 0;
        return numbers.back() / (numbers[numbers.size() - k - 1]);
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */