class ProductOfNumbers {
public:
    vector<int> numbers{1};
    int id = 0;
    ProductOfNumbers() {
    
    }
    
    void add(int num) {
        
        numbers.push_back(num);
    }
    
    int getProduct(int k) {

        int prod = 1;
        for(int i = numbers.size() - 1; i >= numbers.size() - k; i--){
            prod *= numbers[i];
        }
        return prod;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */