#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{
   int i = 0;
   while (s[i] != '\0')
   {
      i++;
   }
   return i;
}

int charCount(string s, char c)
{
   int i = 0, counter_word = 0;
   while (s[i] != '\0')
   {
      if (s[i] == c)
      {
         counter_word++;
      }
      i++;
   }
   return counter_word;
}

string substring(string s, int d, int h)
{
   string word;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (i >= d && i < h)
      {
         word += s[i];
      }
   }
   return word;
}

string substring(string s, int d) // ok
{
   string word;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (i >= d)
      {
         word += s[i];
      }
   }
   return word;
}

int indexOf(string s, char c) // ok`
{
   int word_position;
   bool assignedValue = false;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (s[i] == c)
      {
         word_position = i;
         assignedValue = true;
         break;
      }
   }
   if (!assignedValue)
      return -1;
   return word_position;
}

int indexOf(string s, char c, int offSet) // ok
{
   int word_position;
   bool assignedValue = false;
   for (int i = offSet; s[i] != '\0'; i++)
   {
      if (s[i] == c)
      {
         word_position = i;
         assignedValue = true;
         break;
      }
   }
   if (!assignedValue)
      return -1;
   return word_position;
}

int indexOf(string s, string toSearch) // ok
{
   int word_position = 0;
   bool assignedValue = false;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (substring(s, i, length(toSearch) + i) == toSearch && !assignedValue)
      {
         word_position = i;
         assignedValue = true;
      }
   }
   if (!assignedValue)
      return -1;
   return word_position;
}

int indexOf(string s, string toSearch, int offset) // ok
{
   int word_position = 0;
   bool assignedValue = false;
   for (int i = offset; s[i] != '\0'; i++)
   {
      if (substring(s, i, length(toSearch) + i) == toSearch && !assignedValue)
      {
         word_position = i;
         assignedValue = true;
      }
   }
   if (!assignedValue)
      return -1;
   return word_position;
}

int lastIndexOf(string s, char c)
{
   int word_position;
   bool assignedValue = false;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (s[i] == c)
      {
         word_position = i;
         assignedValue = true;
      }
   }
   if (!assignedValue)
      return -1;
   return word_position;
}

int indexOfN(string s, char c, int n)
{
   int occurrences = 0;
   int position_of_occurrence = 0;
   if (n <= 0)
      position_of_occurrence = -1;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (occurrences == n)
      {
         position_of_occurrence = i - 1;
         break;
      }
      if (s[i] == c)
      {
         occurrences++;
      }
   }
   if (n > occurrences)
   {
      position_of_occurrence = length(s);
   }
   return position_of_occurrence;
}

int charToInt(char c)
{
   int integer = 0;
   if (c >= '0' && c <= '9')
   {
      integer = c - 48;
   }
   else
   {
      if (c >= 'A' && c <= 'Z')
      {
         integer = (int)c - 55;
      }
      else
      {
         integer = (int)c - 87;
      }
   }
   return integer;
}

char intToChar(int i)
{
   char charValue;
   if (i >= 0 && i <= 9)
   {
      charValue = i + '0';
   }
   else if (i >= 65 && i <= 90)
   {
      charValue = (char)i;
      return charValue;
   }
   else
   {
      return ' ';
   }
   return charValue;
}

int getDigit(int n, int i)
{
   for (int j = 0; j < i; j++)
   {
      n = n / 10;
   }
   return n % 10;
}

int digitCount(int n)
{
   int counter = 0;
   while (n > 0)
   {
      counter++;
      n = n / 10;
   }
   return counter;
}

string intToString(int i)
{
   string string_to_return;
   for (int j = 0; j < digitCount(i); j++)
   {
      string_to_return += intToChar(getDigit(i, j));
   }
   string tmp = "";
   // Reverse
   for (int h = length(string_to_return) - 1; h >= 0; h--)
   {
      tmp += string_to_return[h];
   }
   return tmp;
}

int stringToInt(string s, int b) // ok
{
}

int stringToInt(string s) // ok
{
   return 0;
}

string charToString(char c)
{
   return "";
}

char stringToChar(string s)
{
   return 'X';
}

string stringToString(string s)
{
   return "";
}

string doubleToString(double d)
{
   return "";
}

double stringToDouble(string s)
{
   return 1.1;
}

bool isEmpty(string s)
{
   return true;
}

bool startsWith(string s, string x)
{
   return true;
}

bool endsWith(string s, string x)
{
   return true;
}

bool contains(string s, char c)
{
   return true;
}

string replace(string s, char oldChar, char newChar)
{
   return "";
}

string insertAt(string s, int pos, char c)
{
   return "";
}

string removeAt(string s, int pos)
{
   return "";
}

string ltrim(string s)
{
   return "";
}

string rtrim(string s)
{
   return "";
}

string trim(string s)
{
   return "";
}

string replicate(char c, int n)
{
   return "";
}

string spaces(int n)
{
   return "";
}

string lpad(string s, int n, char c)
{
   return "";
}

string rpad(string s, int n, char c)
{
   return "";
}

string cpad(string s, int n, char c)
{
   return "";
}

bool isDigit(char c)
{
   return true;
}

bool isLetter(char c)
{
   return true;
}

bool isUpperCase(char c)
{
   return true;
}

bool isLowerCase(char c)
{
   return true;
}

char toUpperCase(char c)
{
   return 'X';
}

char toLowerCase(char c)
{
   return 'X';
}

string toUpperCase(string s)
{
   return "";
}

string toLowerCase(string s)
{
   return "";
}

int cmpString(string a, string b)
{
   return 0;
}

int cmpDouble(double a, double b)
{
   return 0;
}

#endif
