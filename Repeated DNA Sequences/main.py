class Solution:
    def findRepeatedDnaSequences(self, s: str):
        ans = set()
        seen = set()
        
        for i in range(len(s) - 9):
            sequence = s[i:i+10]
            if sequence in seen:
                ans.add(sequence)
            seen.add(sequence)
            
        return list(ans)
