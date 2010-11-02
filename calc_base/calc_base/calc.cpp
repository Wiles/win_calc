#include "calc.h"


int Calculator::Solve( string& expression, string& solution, bool fixParans )
{
	int iSolution;
	stringstream solutionSteam;

	if( fixParans == true )
	{
		if( parenthesesFix( expression ) == false ){
			return PAREN_ERROR;
		}
	}

	equationStream = new stringstream( expression, ios_base::in );
	
	if( equationStream == NULL )
	{
		return EMPTY_EXPRESSION;
	}

	try{

		iSolution = Expression();
	}
	catch( ERROR_MESSAGE error_type ){
		delete equationStream;
		return error_type;
	}
	
	delete equationStream;

	solutionSteam << iSolution;

	solution = solutionSteam.str();

	return OK;	
}

int Calculator::Primary( void )
{
	Token t = ts.get( equationStream );
	int d;

	switch( t.kind )
	{
		case( '(' ):
		d = Expression();
		t = ts.get( equationStream );
		if( t.kind != ')' ){
			error( PAREN_ERROR );
		}
		return d;
	case NUMBER:
		return t.value;
	case'-':
		return - Primary();
	case'+':
		return Primary();
	default:
		error( FORMAT_ERROR );		
	}
	return 0;
}

int Calculator::Term( void )
{
	int left = Primary();
	Token t = ts.get( equationStream );
	int d;

	while( true )
	{
		
		switch( t.kind )
		{		
		case( '*' ):
			left *= Primary();
			t = ts.get( equationStream );
			break;
		case( '/' ):
			d = Primary();
			if ( d == 0 ){
				error( DIVIDE_BY_ZERO );
			}
			left /= d;
			t = ts.get( equationStream );
			break;
		//Open Parentheses after a number is counted as an implied multiplication
		case( '(' ):
			ts.putback( t );
			left *= Primary();
			t = ts.get( equationStream );
			break;

		default:
			ts.putback( t );
			return left;
		}
	}
}

int Calculator::Expression( void )
{
	int left = Term();
	Token t = ts.get( equationStream );

	while( true )
	{	switch( t.kind ){
		case( '+' ):
			left += Term();
			t = ts.get( equationStream );
			break;
		case( '-' ):
			left -= Term();
			t = ts.get( equationStream );
			break;
		case( END ):
			return left;
		default:
			ts.putback(t);
			return left;
		}
	}
}


bool Calculator::parenthesesFix( string& s )
{
	int parenCount = 0;

	for( unsigned int i = 0; i < s.length(); ++i )
	{
		if( s[i] == '(' )
		{
			++parenCount;
		}
		else if( s[i] == ')' )
		{
			--parenCount;
		}
	}
	
	if( parenCount > 0 ){
		for( int j = 0; j < parenCount; ++j )
		{
			s += ')';
		}
	}
	else if( parenCount < 0 )
	{
		return false;
	}
	return true;
}