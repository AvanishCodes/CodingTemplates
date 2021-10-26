'''Minimum Coins Problem: Given a value N, find the minimum number of coins required to make the change.

    Input: N = 15
    Coins: [1, 7, 10]
    Output: 3
'''

class MinimumCoins:
    '''MinimumCoins Class

    Attributes:
        _limit (int): The limit of the problem.
        _coins (list): The list of coins.
        _dp (list): The dynamic programming table.

    Methods:
        solve(): Solve the problem.
        get_result(): Get the result of the problem.

    Raises:
        TypeError: If limit is not an integer.
        TypeError: If coins is not a list.
        TypeError: If any element of coins is not an integer.

    Examples:
        >>> mc = MinimumCoins(15, [1, 7, 10])
        >>> mc.get_result(15)
        3
    '''
    _limit = int()
    _coins = list()
    _dp = list()

    def __init__(self, limit, coins):
        '''Constructor

        Args:
            limit (int): The limit of the problem.
            coins (list): The list of coins.
        
        Returns:
            None

        Raises:
            TypeError: If limit is not an integer.
            TypeError: If coins is not a list.
            TypeError: If any element of coins is not an integer.
        '''
        if not isinstance(limit, int):
            raise TypeError("limit must be an integer.")
        if not isinstance(coins, list):
            raise TypeError("coins must be a list.")
        for coin in coins:
            if not isinstance(coin, int):
                raise TypeError("All elements of coins must be integers.")
        self._limit = limit
        self._coins = coins
        self._dp = [(limit+10) for _ in range(limit + 1)]
        self.solve()
        return


    def solve(self):
        '''Solve the problem.

        Args:
            None

        Returns:
            None

        Raises:
            None
        '''
        self._dp[0] = 0
        for i in range(1, self._limit + 1):
            for coin in self._coins:
                if i >= coin:
                    self._dp[i] = min(self._dp[i], 1 + self._dp[i - coin])
        return

    def get_result(self, amount: int) -> int:
        '''Get the result of the problem.

        Args:
            None

        Returns:
            int: The minimum number of coins.

        Raises:
            TypeError: If amount is not an integer.

        Examples:
            >>> mc = MinimumCoins(15, [1, 7, 10])
            >>> mc.get_result(15)
            3
        '''
        if not isinstance(amount, int):
            raise TypeError("amount must be an integer.")
        return self._dp[amount]

'''
if __name__ == "__main__":
    # Test
    N = 15
    coins = [1, 7, 10]
    minimum_coins = MinimumCoins(N, coins)
    print(minimum_coins.get_result(N))
'''