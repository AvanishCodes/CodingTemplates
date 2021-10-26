'''Wines Problem
'''
from copy import deepcopy


class WinesProblem:
    '''Wines Problem

    Given an array of integers representing the price of wines, find the maximum profit that can be made by buying and selling one or more wines.
    It is given that the price of the wines are strictly increasing.

    Attributes:
        _prices: list of integers representing the price of wines

    Methods:
        solve: Solve the problem

    Examples:
        >>> WinesProblem([2, 3, 5, 1, 4]).solve()
        50
    '''
    _prices = [2, 3, 5, 1, 4]

    def __init__(self, prices: list):
        self._prices = prices
        pass

    def _solveUtil(self, prices: list, dp: list, i: int, j: int, y: int) -> int:
        '''Solve the problem

        Args:
            prices: list of integers representing the price of wines
            i: starting index
            j: ending index

        Returns:
            integer representing the maximum profit that can be made by buying and selling one or more wines
        '''
        if i > j:
            return 0
        if dp[i][j] != 0:
            return dp[i][j]
        
        opt1 = prices[i]*y + self._solveUtil(prices, deepcopy(dp), i+1, j, y+1)         # Note that making a deepcopy is important
        opt2 = prices[j]*y + self._solveUtil(prices, deepcopy(dp), i, j-1, y+1)         # Note that making a deepcopy is important
        dp[i][j] = max(opt1, opt2)
        return dp[i][j]

    def solve(self, prices: list=_prices) -> int:
        '''Solve the problem

        Args:
            prices: list of integers representing the price of wines

        Returns:
            integer representing the maximum profit that can be made by buying and selling all the wines
        '''
        dp = [[0] * len(prices)] * len(prices)
        self._solveUtil(prices, dp, 0, len(prices) - 1, 1)

        print(dp)
        return dp[0][len(prices) - 1]
'''
if __name__ == '__main__':
    print(WinesProblem([2, 3, 5, 1, 4]).solve())
'''