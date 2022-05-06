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
   return 0;
}

int charToInt(char c)
{
   return 0;
}

char intToChar(int i)
{
   return 'X';
}

int getDigit(int n, int i)
{
   return 0;
}

int digitCount(int n)
{
   return 0;
}

string intToString(int i)
{
   return "";
}

int stringToInt(string s, int b) // ok
{
   return 0;
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
