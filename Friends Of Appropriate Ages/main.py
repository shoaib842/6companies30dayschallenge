class Solution:
    def numFriendRequests(self, ages):
        def request(age_a, age_b):
            return not (age_b <= 0.5 * age_a + 7 or age_b > age_a or age_b > 100 and age_a < 100)

        ans = 0
        count = Counter(ages)

        for age_a, count_a in count.items():
            for age_b, count_b in count.items():
                if request(age_a, age_b):
                    if age_a == age_b:
                        ans += count_a * (count_b - 1)
                    else:
                        ans += count_a * count_b

        return ans
