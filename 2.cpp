#include <iostream>
#include <cstdio>
#include "2.h"

using namespace std;

int mString :: amount = 0;

int mString :: get_amount() { return amount; }

mString :: mString() { n = 0; str = 0; ++amount; }

mString :: mString(const char* st) 
{
   	for(n = 0, str = 0; st && st[n]; ++n);
        
	if (n)
	{
		str = new char[n];
		if (!str)
			throw "memory error";
	}
	for(int i = 0; n && i <= n; ++i)
             	str[i] = st[i];
	++amount;
}
mString :: mString(const mString& op) 
{
	str = 0;
    n = op.n;

	if (n)
	{
		str = new char[n];
		if (!str)
			throw "memory error";
	}   
      	for(int i = 0; n && i <= n; ++i)
             	str[i] = op.str[i];
	++amount;
}

mString :: ~mString() 
{ 
	if (str)
		delete [] str;
	--amount;
}
int mString :: len() const { return n; }

bool mString :: empty() const { return !n; }

mString& mString :: append(const char* ch) 
{
	if (!ch)
		return(*this);
 	
	int p, i;
        
 	for(p = 0; ch[p]; ++p);	
       	
	char *st = new char[n + p];
	if (!st) 
		throw "memory error";
            
    for(i = 0; i < n; ++i)
    		st[i] = str[i];
	
	if (str)
		delete [] str;
	
	for(i = n; i <= n + p; ++i)
       		st[i] = ch[i - n];	
	str = st;
     	n += p;
	
	return (*this);
}
mString& mString :: append(char ch)
{
	char *st(new char[n + 1]);
	if (!st) 
		throw "memory error";

	for(int i = 0; i < n; ++i)
                st[i] = str[i];
    if (str)
		delete [] str;
	
	st[n++] = ch;
     	str = st;

	return (*this);
}
mString& mString :: insert(const char* ch, int pos) 
{ 	      	
    if ((pos < 0) || (pos >= n))
		throw "position is not suitable";
	int i, p;
       	 
	for(p = 0; ch && ch[p]; ++p);	
	    
	char *st(new char[n + p]);
 	if (!st) 
		throw "memory error";
       
    for(i = 0; i < pos; ++i)
                st[i] = str[i];
	for(int k = 0; k < p; ++i, ++k)
		st[i] = ch[k];
    for(; i < n + p; ++i)
          	st[i] = str[i - p];
        
	if (str)
		delete [] str;
	
	str = st;
	n += p;
	
	return (*this);
}       
mString& mString :: insert(char ch, int pos) 
{
	if ((pos < 0) || (pos >= n))
		throw "position is not suitable";
	int i;
            
	char *st(new char[n + 1]);
    if (!st) 
		throw "memory error";
    
    for(i = 0; i < pos; ++i)
                st[i] = str[i];
    for(st[pos] = ch, ++i; i < n + 1; ++i)
                st[i] = str[i - 1];
        
	if (str)
		delete [] str;
	
	str = st;	
	n += 1;
	
	return (*this);
}

mString& mString :: remove(int pos) 
{
	if ((pos < 0) || (pos >= n))
		throw "position is not suitable";
	int i;
	char *st(new char[n - 1]);
 	if (!st) 
		throw "memory error";
           
    for(i = 0; i < pos; ++i)
      		st[i] = str[i];
    for(; i < n - 1; ++i)
                st[i] = str[i + 1];
    if (str)
		delete [] str;
	
	str = st;
	n -= 1;	
	
	return (*this);
}
mString& mString :: remove(int pos1, int pos2) 
{
	if ((pos1 < 0) || (pos1 >= n) || (pos2 < 0) || (pos2 >= n) || (pos1 > pos2))
		throw "position is not suitable";
	int i;
	char *st = 0;
	
	if (n - pos2 + pos1)
	{
		st = new char[n - pos2 + pos1];
	   	if (!st) 
			throw "memory error";
	}
	for(i = 0; i < pos1; ++i)
		st[i] = str[i];
	for(i = pos2 + 1; i < n; i++)
		st[i - pos2 - 1 + pos1] = str[i];
	if (str)
		delete [] str;
	
	str = st;
	n -= pos2 - pos1;
	
	return (*this);
}
int mString :: search(const char* ch) const
{
	int len;

	for(len = 0; ch && ch[len]; ++len);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < len; j++)
			if (ch[j] == str[i + j])
            {
				if (j + 1 == len)
					return i;
            }
			else 
				break;
	return -1;		
}
void mString :: print() const
{ 
	if (str) 
		cout << str << endl;
}
const mString mString :: operator+(const mString& op) const { return mString(*this).append(op.str); }

const mString operator+(const char* st, const mString& op) { return mString(st) + op; }

const mString mString :: operator*(int a) const
{
	if (a < 0)
		throw "position is not suitable";

	mString tmp;
	
	for(int i = 0; i < a; ++i)
		tmp.append(str);
	
	return tmp;
}
const mString operator*(int a, const mString& op) { return op * a; }

mString& mString :: operator=(const mString& op) 
{
    if (n)
        remove(0, n - 1);
    append(op.str);
    
	return (*this);
}
const bool mString :: operator>(const mString& op) const
{
	for(int i = 0; str && op.str && str[i] && op.str[i]; ++i)
		if (str[i] != op.str[i])
			return str[i] > op.str[i];
	return n > op.n;
}
const bool operator>(const char* st, const mString& op) { return mString(st) > op; }

const bool mString :: operator<(const mString& op) const
{
	for(int i = 0; str && op.str && str[i] && op.str[i]; ++i)
		if (str[i] != op.str[i])
			return str[i] < op.str[i];
	return n < op.n;
}
const bool operator<(const char* st, const mString& op) { return mString(st) < op; }

const bool mString :: operator>=(const mString& op) const { return !((*this) < op); }

const bool operator>=(const char* st, const mString& op) { return !(st < op); }

const bool mString :: operator<=(const mString& op) const { return !((*this) > op); }

const bool operator<=(const char* st, const mString& op) { return !(st > op); }

const bool mString :: operator==(const mString& op) const { return ((*this) >= op) && ((*this) <= op); }

const bool operator==(const char* st, const mString& op) { return (st >= op) && (st <= op); }

char& mString :: operator[](int a) 
{ 
	if (a < 0)
		throw "position is not suitable";
	return str[a]; 
}
ostream& operator<<(ostream& os, const mString& op)
{
    if (op.str)
        os << op.str;
    return os;
}
