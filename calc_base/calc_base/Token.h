#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define NUMBER 'N'
#define END 'E'

enum ERROR_MESSAGE{
	OK,
	EMPTY_EXPRESSION,
	PAREN_ERROR,
	FORMAT_ERROR,
	DIVIDE_BY_ZERO,
};


inline void  error( ERROR_MESSAGE errorType ){ throw( errorType ); };

using namespace std;

class Token{
public:
	char kind;
	int value;
	Token( void ){};
	Token( char ch ):kind( ch ){}
	Token( char ch, int val ):kind( ch ), value( val ){}
};


class TokenStream{
public:
	TokenStream();
	Token get( stringstream* stream);
	void putback( Token t );
	void ignore( char c );

private:
	bool full;
	Token buffer;
	stringstream* sStream;
};
