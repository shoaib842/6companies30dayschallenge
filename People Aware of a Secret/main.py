class Solution:
    def peopleAwareOfSecret(self, n, delay, forget):
        kMod = 10**9 + 7
        share = 0
        dp = [0] * n
        dp[0] = 1

        for i in range(1, n):
            if i - delay >= 0:
                share += dp[i - delay]
            if i - forget >= 0:
                share -= dp[i - forget]
            share += kMod
            share %= kMod
            dp[i] = share

        # People before day `n - forget - 1` already forget the secret.
        return sum(dp[-forget:]) % kMod
