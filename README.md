# ProgTest-Exe3
Solution for the item 3 of the Programming Test

Code written in C++ to attend item 3 of the Programming Skill Test:

"Consider a string containing lowercase characters from the Portuguese alphabet. You can perform two types of operations on this string:
1. Concat a lowercase character from the Portuguese alphabet at the end of the string.
2. Remove the last character from the string. If the string is empty, it will remain empty.

Given an integer k and two strings s and t, determine if you can convert s to t using exactly k operations described above on s. If possible, the program prints 'yes', otherwise it prints 'no'.

Develop a C/C++ or Java language program that implements and uses the ConcatRemove (s, t, k) function. It should return the results 'yes' or 'no'.
The function has the following parameters:
s: starting string
t: desired string
k: an integer that represents the number of operations

Constrains
a) 1 <= | s | <= 100
b) 1 <= | t | <= 100
c) 1 <= k <= 100
d) s and t consists of lowercase letters of the Portuguese alphabet, ascii [a-z]"

------------------------------------------------------------------------------------------------------------------------------------------------------

There are comments in the file explaining some steps and functions used.

Test: Running the code in a C++ compiler, it will request the user to type the start string, desired string and the operations number.

After that it will show in the output screen whether it's possible or not to convert the strings in a given number of operations.

Note: In the input step, the program will keep asking to input information if it's not meeting the constraints, such as Uppercase letters, out of range (0..100) or invalid numeric digits (k input).
