class Solution:
    def beautifulIndices(self, s: str, a: str, b: str, k: int) -> List[int]:
        def kmp(s, pattern):
            res = []
            lps = get_lps(pattern)
            i, j = 0, 0

            while i < len(s):
                if s[i] == pattern[j]:
                    i += 1
                    j += 1

                if j == len(pattern):
                    res.append(i - j)
                    j = lps[j - 1]

                elif i < len(s) and s[i] != pattern[j]:
                    # Mismatch after j matches
                    # Don't match lps[0..lps[j - 1]] since they will match anyway.
                    if j != 0:
                        j = lps[j - 1]
                    else:
                        i += 1

            return res

        def get_lps(s):
            lps = [0] * len(s)
            i, j = 1, 0

            while i < len(s):
                if s[i] == s[j]:
                    j += 1
                    lps[i] = j
                    i += 1
                else:
                    if j != 0:
                        j = lps[j - 1]
                    else:
                        lps[i] = 0
                        i += 1

            return lps

        ans = []
        indices_a = kmp(s, a)
        indices_b = kmp(s, b)
        indices_b_index = 0  # indices_b's index

        for i in indices_a:
            # The constraint is: |j - i| <= k. So, -k <= j - i <= k.
            # So, move `indices_b_index` s.t. j - i >= -k, where j := indices_b[indices_b_index].
            while indices_b_index < len(indices_b) and indices_b[indices_b_index] - i < -k:
                indices_b_index += 1

            if indices_b_index < len(indices_b) and indices_b[indices_b_index] - i <= k:
                ans.append(i)

        return ans
