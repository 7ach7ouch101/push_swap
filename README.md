# push_swap
In this project i made the data sort on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed i hade to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting.

The project aims to implement a sorting algorithm using two stacks named "a" and "b." The objective is to sort the numbers in stack "a" in ascending order using a set of provided operations such as swapping elements, pushing elements between stacks, rotating elements, and reverse rotating elements.

The learning objectives of the project are to focus on rigor, the use of C programming language, and understanding basic algorithms, particularly their complexity.

The program, named "push_swap," requires the implementation of a Makefile and source files (*.h, *.c). Global variables are not allowed. The program takes a list of integers as an argument, representing the initial state of stack "a." It should output the minimum number of instructions required to sort stack "a," with the smallest number at the top. Each instruction should be separated by a newline character.

The rules for the project include not exceeding the maximum number of allowed operations and ensuring that the numbers are properly sorted. Errors, such as non-integer arguments, integers larger than the maximum value, or duplicate arguments, should be handled and result in an "Error" message displayed on the standard error.

During the evaluation process, a provided binary called "checker_OS" will be used to verify the correctness of the output. It will count the number of instructions and check if the numbers are sorted correctly. If the output fails the checks, it will display "KO."

Example usage and evaluation process are provided, including sorting a list of integers and handling error cases.
