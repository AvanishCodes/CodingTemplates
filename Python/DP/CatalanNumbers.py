'''Catalan Numbers
'''


class CatalanNumbers:
    '''Catalan Numbers

    The n-th Catalan number is the number of ways of partitioning n items
    into two non-empty subsets. The formula for the number of ways of
    partitioning n items into two non-empty subsets is:

    C(n) = (2n)! / (n+1)!n!

    The first few Catalan numbers are:
    [1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796]

    The n-th Catalan number can be computed by the following recursive
    formula:
    C[n+1] = C[n] * (4n+2) / (n+2)

    Attributes:
        _limit (int): The limit of the Catalan numbers to generate
        _catalan_list (list): The first 10 Catalan numbers

    Methods:
        get_catalan_number(n)
            Get the n-th Catalan number
        _generate_catalan_numbers(limit)
            Generate the first 10 Catalan numbers
        
    Examples:
        >>> CatalanNumbers().get_catalan_number(10)
        16796
    '''
    _limit = int(10)  # default limit of the Catalan numbers is 10
    _catalan_list = list()

    def __init__(self, limit=10):
        '''Constructor
        
        Args:
            limit (int): The limit of the Catalan numbers to generate

        Returns:
            None

        Raises:
            ValueError: If limit is not a positive integer

        Examples:
            >>> CatalanNumbers(10)
            CatalanNumbers(10)
        '''
        if isinstance(limit, int) and limit >= 0:
            self._limit = limit+1
            self._generate_catalan_numbers(self._limit)
        else:
            raise ValueError('limit must be a non-negative integer.')
    def _generate_catalan_numbers(self, limit=10):
        '''Generate the first 10 Catalan numbers

        Args:
            limit (int): The limit of the Catalan numbers to generate

        Returns:
            list: The first 10 Catalan numbers

        Raises:
            ValueError: If limit is not a positive integer

        Examples:
            >>> CatalanNumbers()._generate_catalan_numbers(10)
            [1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796]
        '''
        if isinstance(limit, int) and limit >= 0:
            self._catalan_list = [0]*(self._limit+1)
            self._catalan_list[0] = 1
            self._catalan_list[1] = 1
            for i in range(2, self._limit):
                for j in range(i):
                    self._catalan_list[i] += self._catalan_list[j] * \
                        self._catalan_list[i-j-1]
        else:
            raise ValueError('limit must be a non-negative integer.')
        return

    def get_catalan_number(self, n):
        '''Get the n-th Catalan number

        Args:
            n (int): The index of the Catalan number

        Returns:
            int: The n-th Catalan number

        Raises:
            ValueError: If n is not a positive integer

        Examples:
            >>> CatalanNumbers().get_catalan_number(10)
            16796
        '''
        if isinstance(n, int) and n >= 0:
            if n > self._limit:
                self._limit = n+1
                self._generate_catalan_numbers(n)
            return self._catalan_list[n]
        else:
            raise ValueError('n must be a non-negative integer.')

    def limit(self):
        '''Get the limit of the Catalan numbers

        Args:
            None

        Returns:
            int: The limit of the Catalan numbers

        Examples:
            >>> CatalanNumbers().limit()
            10
        '''
        return (self._limit-1)