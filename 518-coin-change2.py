class Solution:

    def change(self, amount: int, coins) -> int:
        dp = [0 for i in range(amount + 1)]
        dp[0] = 1

        for coin in coins:
            for i in range(coin, amount + 1):
                dp[i] += dp[i - coin]

        return dp[amount]


if __name__ == "__main__":
    sol = Solution()
    print(sol.change(5, [1, 2, 5]))