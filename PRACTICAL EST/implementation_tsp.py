class Solution:
    def tsp(self, cost):
        n = len(cost)
        dp = [[-1] * (1 << n) for _ in range(n)]

        def solve(pos, mask):
            if mask == (1 << n) - 1:
                return cost[pos][0]

            if dp[pos][mask] != -1:
                return dp[pos][mask]

            ans = float('inf')

            for city in range(n):
                if (mask & (1 << city)) == 0:
                    ans = min(ans, cost[pos][city] + solve(city, mask | (1 << city)))

            dp[pos][mask] = ans
            return ans

        return solve(0, 1)
