class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for(int i {1}; i < 1001 ; i++)
            addBack(i);
    }

    int popSmallest() {
        int value = *st.begin();
        st.erase(st.begin());
        return value;
    }

    void addBack(int num) {
        if (std::find(st.begin(), st.end(), num) == st.end())
            st.emplace(num);
    }
private:
    std::set<int> st;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
