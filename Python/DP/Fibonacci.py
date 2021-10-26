'''Fibonacci Class Implementation
'''
class Fibonacci:
    '''Fibonacci Class

    Attributes:
        _capacity: capacity of the Fibonacci sequence
        _fib: the Fibonacci sequence

    Methods:
        get: get the nth Fibonacci number
        size: get the capacity of the Fibonacci sequence

    Raises:
        TypeError: if n is not an integer
        ValueError: if n is less than 2

    Examples:
        >>> fib = Fibonacci(10)
        >>> fib.get(0)
        0
        >>> fib.get(1)
        1
        >>> fib.get(20)
        -1
        >>> fib.size()
        10
    '''
    _capacity = 0   # Default capacity of Fibonacci sequence
    _fib = []
    def __init__(self, n: int)->None:
        '''Constructor
        
        Args:
            n: capacity of the Fibonacci sequence
        
        Returns:
            None

        Raises:
            TypeError: if n is not an integer

        Examples:
            >>> fib = Fibonacci(10)
            >>> fib.get(0)
            0
            >>> fib.get(1)
            1
            >>> fib.get(20)
            -1
        '''
        if not isinstance(n, int):
            raise TypeError('n must be an integer')
        if n <  2:
            raise ValueError('n must be greater than or equal to 2')
        self._capacity = n
        self._fib = [0] * n
        self._fib[0] = 0
        self._fib[1] = 1
        for i in range(2, n):
            self._fib[i] = self._fib[i-1] + self._fib[i-2]
            continue
        return

    def get(self, n: int)->int:
        '''Get the nth Fibonacci number

        Args:
            n: the nth Fibonacci number

        Returns:
            the nth Fibonacci number

        Raises:
            TypeError: if n is not an integer

        Examples:
            >>> fib = Fibonacci(10)
            >>> fib.get(0)
            0
            >>> fib.get(1)
            1
            >>> fib.get(20)
            -1
        '''
        if not isinstance(n, int):
            raise TypeError('n must be an integer')
        if n < 0 or n >= self._capacity:
            return -1
        return self._fib[n]

    def size(self):
        '''Get the capacity of the Fibonacci sequence

        Args:
            None

        Returns:
            the capacity of the Fibonacci sequence

        Raises:
            None

        Examples:
            >>> fib = Fibonacci(10)
            >>> fib.size()
            10
        '''
        return self._capacity


'''
if __name__ == '__main__':
    fib = Fibonacci(10)
    print(fib.get(0))
    print(fib.get(1))
    print(fib.get(2))
    print(fib.get(3))
    print(fib.get(4))
    print(fib.get(5))
    print(fib.get(6))
    print(fib.get(7))
    print(fib.get(8))
    print(fib.get(9))
    print(fib.get(10))
    print(fib.get(11))
'''