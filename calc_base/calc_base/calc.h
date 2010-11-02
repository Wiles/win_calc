#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Token.h"

class Calculator{
public:

	Calculator( void )
	{
		equationStream = NULL;
	}
	~Calculator( void )
	{
	}

	int Calculator::Solve( string& expression, string& solution, bool fixParans );


private:

	int Primary( void );
	int Term( void );
	int Expression( void );
	TokenStream ts;
	stringstream* equationStream;
	bool parenthesesFix( string& s );

};