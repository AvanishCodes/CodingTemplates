'''Minimum Number of steps required to reach 1
'''

class MinimumStepsToOne:
    '''MinimunStepsToOne Class

    Attributes:
        _steps (int): Minimum number of steps to reach 1
        _number (int): Number to find the minimum steps to reach 1
        _result_list (list): List of numbers of size steps

    Methods:
        get_steps(self, n: int) -> int:
            Get the minimum number of steps to reach 1
        
    Raises:
        Exception: If number is less than 1
    
    Examples:
        >>> MinimumStepsToOne(1)._get_steps(1)
        0
        >>> MinimumStepsToOne(2)._get_steps(2)
        1
        >>> MinimumStepsToOne(3)._get_steps(3)
        2
        >>> MinimumStepsToOne(4)._get_steps(4)
        2
    '''
    _steps = float('inf')
    _number = int()
    _result_list = list()   
    def __init__(self, number:int):
        '''Constructor

        Args:
            number (int): Number to find the minimum steps to reach 1
        
        Returns:
            None

        Raises:
            Exception: If number is less than 1

        Examples:
            >>> MinimumStepsToOne(1)._get_steps(1)
            0
            >>> MinimumStepsToOne(2)._get_steps(2)
            1
            >>> MinimumStepsToOne(3)._get_steps(3)
            2
            >>> MinimumStepsToOne(4)._get_steps(4)
            2
        '''
        if number < 1:
            raise Exception('Number must be greater than 0')
        self._number = number
        # Create a list of numbers of size steps
        self._result_list = [float('inf')] * (number+1)
        self._result_list[0] = float('inf')
        self._result_list[1] = 0
        self._result_list[2] = 1
        self._result_list[3] = 1
        # Generate the result for all the numbers
        for i in range(4, number+1):
            self._result_list[i] = self._result_list[i-1] + 1
            if i % 3 == 0:
                self._result_list[i] = min(self._result_list[i], self._result_list[i//3] + 1)
            if i % 2 == 0:
                self._result_list[i] = min(self._result_list[i], self._result_list[i//2] + 1)
            continue
        return

    def get_steps(self, n: int) -> int:
        '''Get the minimum number of steps to reach 1

        Args:
            n (int): Number to find the minimum steps to reach 1

        Returns:
            int: Minimum number of steps to reach 1

        Raises:
            Exception: If number is less than 1

        Examples:
            >>> MinimumStepsToOne(1)._get_steps(1)
            0
            >>> MinimumStepsToOne(2)._get_steps(2)
            1
            >>> MinimumStepsToOne(3)._get_steps(3)
            2
            >>> MinimumStepsToOne(4)._get_steps(4)
            2

        '''
        if n < 1:
            Exception('Number must be greater than 0')
        if n > self._number:
            raise Exception(f'Number must be less than {self._number}')
        return self._result_list[n]
        return self._result_list[n]


if __name__ == '__main__':
    print(MinimumStepsToOne(10).get_steps(11))