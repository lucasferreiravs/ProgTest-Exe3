/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <ctype.h>
#include <cstring>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stoi;

//Concatenate string with a char function
string Concat(string s, char c)
{
    return s += c; 
}

//Remove last character function
string Remove(string s)
{
    if (s != "")
        s.erase(s.end()-1);
    
    return s;
}

//Function to determine if it's possible to match two strings in a certain number os steps
bool ConcatRemove(string s, string t, int k)
{
    //operations counter
    int ope = 0;

    //strings to char arrays to compare each character
    char s_char[s.length() + 1];
    char t_char[t.length() + 1];

    //Passing the strings to char arrays
    strcpy(s_char, s.c_str());
    strcpy(t_char, t.c_str()); 
    
    //Temporary string
    string temp = s;
       
    //Remove iterations
    for (int i = 0; i <= s.length()-1; i++)
    {
        //If a character is different, the program starts removing all the characters after it
        if (s_char[i] != t_char[i])
        {
             for (int r = s.length()-1; r >= i; r--)
             {
                temp = Remove(temp);
                ope++;
             } 
             
             break;
        }
        
    }

    //Concatenate iterations
    for (int i = 0; i <= t.length()-1; i++)
    {
        //If a character is different, it will append to the temp string
        if (t_char[i] != s_char[i])
        {
            temp = Concat(temp, t_char[i]);
            ope++;
        }
        
    }       
    
    //Print the result and the operations needed
    //cout << temp << endl;
    //cout << ope << endl;
       
    //return true if it's possible
    if ((t == temp) and (ope <= k))
        return true;
    else
        return false;
}

//Checking if a string is a lowercase and valid ascii[a..z] letter
bool CheckLower(string s)
{
    char letters[s.length() + 1];
 
    strcpy(letters, s.c_str());
 
    for (int i = 0; i < s.length(); i++)
    {   
        if (!islower(letters[i]))
        {
            return false;
            exit;
        }
    }
    
    return true;
}

//Checking if a string is lower alredy checks if its formed only by letters ascii[a..z]
bool CheckLetter(string s)
{
    char letters[s.length() + 1];
 
    strcpy(letters, s.c_str());
 
    for (int i = 0; i < s.length(); i++)
    {   
        if (!isalpha(letters[i]))
        {
            return false;
            exit;
        }
    }
    
    return true;
}

//Checking if a string contains only numbers, checking each digit
bool CheckDigit(string s)
{
    char letters[s.length() + 1];
 
    strcpy(letters, s.c_str());
 
    for (int i = 0; i < s.length(); i++)
    {   
        if (!isdigit(letters[i]))
        {
            return false;
            exit;
        }
    }
    
    return true;
}

//Main class that requires input from the user and validates the entry information
int main()
{
    
    string s  = "";
    string t  = "";
    string sk = "";
    int    k  = 0;
    
    //Input validations, where the program will keep requesting inputs in case of invalid information
    
    //Checks if the inicial string is lowercase(also a valid letter) and if it's lower than 100 characters 
    do
    { 
        cout << "Enter a valid lowercase inicial string: ";
        cin >> s;
    }    
    while(!CheckLower(s) or (s.length()>100));

    //Checks if the desired string is lowercase(also a valid letter) and if it's lower than 100 characters 
    do
    { 
        cout << "Enter a valid lowercase desired string: ";
        cin >> t;
    }    
    while(!CheckLower(t) or (t.length()>100));

    //Checks if the operations number is a valid digit and if it's between 1 and 100.
    do
    { 
        cout << "Enter a number of operations [0..100]: ";
        cin >> sk;
        
        if (CheckDigit(sk))
            k = stoi(sk);
    }    
    while((k < 1) or (k > 100));

    //Return of the function which determines if it's possible to transform the strings in a certain operations number
    if (ConcatRemove(s,t,k))
        cout << "Yes, it is POSSIBLE to convert the inicial string into the desired string in " << k << " operations"<< endl;
    else
        cout << "No, it is NOT POSSIBLE to convert the inicial string into the desired string in " << k << " operations"<< endl;


    return 0;
}
