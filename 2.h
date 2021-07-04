#include <iostream>
#include <cstdio>
using namespace std;

class mString
{
	char *str;
	int n;

	static int amount;
    public:
        static int get_amount();

        mString();
    
        mString(const char *ch);
    
        mString(const mString &c);
    
        ~mString();
    
        int len() const;
    
        bool empty() const;
    
        mString& append(char ch);
    
        mString& append(const char *ch);
    
        mString& insert(char ch, int pos);
    
        mString& insert(const char *ch, int pos);

        mString& remove(int pos);

        mString& remove(int pos1, int pos2);
    
        int search(const char *ch) const;
    
        void print() const;

        const mString operator+(const mString& op) const;
    
        friend const mString operator+(const char* st, const mString& op);

        const mString operator*(int a) const;
    
        friend const mString operator*(int a, const mString& op);

        mString& operator=(const mString& op);

        const bool operator>(const mString& op) const;
    
        friend const bool operator>(const char* st, const mString& op);

        const bool operator<(const mString& op) const;
    
        friend const bool operator<(const char* st, const mString& op);
    
        const bool operator>=(const mString& op) const;

        friend const bool operator>=(const char* st, const mString& op);

        const bool operator<=(const mString& op) const;
    
        friend const bool operator<=(const char* st, const mString& op);

        const bool operator==(const mString& op) const;
    
        friend const bool operator==(const char* st, const mString& op);

        char& operator[](int a);

        friend ostream& operator<<(ostream& os, const mString& op);
};
