#include "calc.h"

int main( void )
{
	Calculator calc;
	while( cin )
	{
		string input;
		string output;
		cout << "> ";
		cin >> input;
		
		int retval = calc.Solve( input, output, true );
		if( retval != OK )
		{
			cout << "Error" << endl;
		}
		else{

			cout << "= " << output << endl;
		}
	}
	return 0;
}