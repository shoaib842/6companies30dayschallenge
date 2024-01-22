class ThroneInheritance {
public:
    ThroneInheritance(std::string kingName) : kingName(std::move(kingName)) {}

    void birth(std::string parentName, std::string childName) {
        family[parentName].push_back(childName);
    }

    void death(std::string name) {
        dead.insert(name);
    }

    std::vector<std::string> getInheritanceOrder() {
        std::vector<std::string> ans;
        dfs(kingName, ans);
        return ans;
    }

private:
    std::unordered_set<std::string> dead;
    std::unordered_map<std::string, std::vector<std::string>> family;
    std::string kingName;

    void dfs(const std::string& name, std::vector<std::string>& ans) {
        if (dead.find(name) == dead.end())
            ans.push_back(name);
        if (family.find(name) == family.end())
            return;

        for (const std::string& child : family[name])
            dfs(child, ans);
    }
};
