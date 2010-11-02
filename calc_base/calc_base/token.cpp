#include "token.h"



TokenStream::TokenStream():full( false ),buffer( 0 ){
}

Token TokenStream::get( stringstream* stream){
	if( full ){
		full = false;
		return buffer;
	}
	
	char ch;
	
	*stream >> ch;

	
	if( stream->eof() )
	{
		return Token( END );
	}

	switch( ch ){
		case'(':
		case')': 
		case'+': 
		case'-': 
		case'*': 
		case'/': 
		case'%':
			return Token( ch );
		case'.':
		case'0': case'1': case'2': case'3': case'4':
		case'5': case'6': case'7': case'8': case'9':
			stream->putback( ch );
			int val;
			*stream >> val;
			return Token( NUMBER, val );
		default:
			error( FORMAT_ERROR );
			
	}
	return 0;
}

void TokenStream::putback( Token t ){
	if ( full ){
		error( FORMAT_ERROR );
	}
	buffer = t;
	full = true;
}

void TokenStream::ignore( char c ){
	
	if( full && c==buffer.kind ){
		full = false;
		return;
	}
	full = false;

	char ch = 0;

	while( cin>>ch ){
		if( ch == c ){
			return;
		}
	}
}
