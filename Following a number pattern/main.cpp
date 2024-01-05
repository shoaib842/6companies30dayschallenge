class Solution {
public:
    std::string printMinNumberForPattern(const std::string& s) {
        std::string ans = "";
        std::string st = "";
        int n = 1;
        
        for (char i : s) {
            st += std::to_string(n);
            if (i == 'I') {
                ans += std::string(st.rbegin(), st.rend());
                st = "";
            }
            n++;
        }
        
        st += std::to_string(n);
        ans += std::string(st.rbegin(), st.rend());
        
        return ans;
    }
};
