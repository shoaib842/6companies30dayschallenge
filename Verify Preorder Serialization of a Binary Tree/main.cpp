class Solution {
public:
    bool isValidSerialization(std::string preorder) {
        int degree = 1;  // out-degree (children) - in-degree (parent)
        std::istringstream iss(preorder);
        std::string node;

        while (std::getline(iss, node, ',')) {
            degree -= 1;
            if (degree < 0) {
                return false;
            }
            if (node != "#") {
                degree += 2;
            }
        }

        return degree == 0;
    }
};
