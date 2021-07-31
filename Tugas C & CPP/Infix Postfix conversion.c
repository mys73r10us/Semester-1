#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
struct infix
{
	char target[MAX] ;
	char stack[MAX] ;
	char *s, *t ;
	int top, l ;
} ;
 
void initinfix ( struct infix * ) ;
void setexpr ( struct infix *, char * ) ;
void push ( struct infix *, char ) ;
char pop ( struct infix * ) ;
void convert ( struct infix * ) ;
int priority ( char c ) ;
void show ( struct infix ) ;
 
void main( )
{
	struct infix q ;
	char expr[MAX] ;
	initinfix ( &q ) ;
	printf ( "\nMasukkan text Infix: " ) ;
	gets ( expr ) ;
	setexpr ( &q, expr ) ;
	convert ( &q ) ;
	printf ( "Prefix: " ) ;
	show ( q ) ;
	getch( ) ;
}
void initinfix ( struct infix *pq )
{
	pq -> top = -1 ;
	strcpy ( pq -> target, "" ) ;
	strcpy ( pq -> stack, "" ) ;
	pq -> l = 0 ;
}
// reverse text dari infix
void setexpr ( struct infix *pq, char *str )
{
	pq -> s = str ;
	strrev ( pq -> s ) ;
	pq -> l = strlen ( pq -> s ) ;
	*( pq -> target + pq -> l ) = '\0' ;
	pq -> t = pq -> target + ( pq -> l - 1 ) ;
}
//menambahkan operator ke dalam stack */
void push ( struct infix *pq, char c )
{
	if ( pq -> top == MAX - 1 )
		printf ( "\nStack penuh.\n" ) ;
	else
	{
		pq -> top++ ;
		pq -> stack[pq -> top] = c ;
	}
}
// pop operator dari stack
char pop ( struct infix *pq )
{
	if ( pq -> top == -1 )
	{
		printf ( "Stack kosong\n" ) ;
		return -1 ;
	}
	else
	{
		char item = pq -> stack[pq -> top] ;
		pq -> top-- ;
		return item ;
	}
}
//conversi text infix ke postfix
void convert ( struct infix *pq )
{
	char opr ;
	while ( *( pq -> s ) )
	{
		if ( *( pq -> s ) == ' ' || *( pq -> s ) == '\t' )
		{
			pq -> s++ ;
			continue ;
		}
		if ( isdigit ( *( pq -> s ) ) || isalpha ( *( pq -> s ) ) )
		{
			while ( isdigit ( *( pq -> s ) ) || isalpha ( *( pq -> s ) ) )
			{
				*( pq -> t ) = *( pq -> s ) ;
				pq -> s++ ;
				pq -> t-- ;
			}
		}
		if ( *( pq -> s ) == ')' )
		{
			push ( pq, *( pq -> s ) ) ;
			pq -> s++ ;
		}
		if ( *( pq -> s ) == '*' || *( pq -> s ) == '+' || *( pq -> s ) == '/' || *( pq -> s ) == '%' || *( pq -> s ) == '-' || *( pq -> s ) == '$' )
		{
			if ( pq -> top != -1 )
			{
				opr = pop ( pq ) ;
				while ( priority ( opr ) > priority ( *( pq -> s ) ) )
				{
					*( pq -> t ) = opr ;
					pq -> t-- ;
					opr = pop ( pq ) ;
				}
				push ( pq, opr ) ;
				push ( pq, *( pq -> s ) ) ;
			}
			else
				push ( pq, *( pq -> s ) ) ;
				pq -> s++ ;
		}
		if ( *( pq -> s ) == '(' )
		{
			opr = pop ( pq ) ;
			while ( opr != ')' )
			{
				*( pq -> t ) = opr ;
				pq -> t-- ;
				opr = pop ( pq ) ;
			}
			pq -> s++ ;
		}
	}
	while ( pq -> top != -1 )
	{
		opr = pop ( pq ) ;
		*( pq -> t ) = opr ;
		pq -> t-- ;
	}
	pq -> t++ ;
}
//Mengatur prioritas
int priority ( char c )
{
	if ( c == '$' )
		return 3 ;
	if ( c == '*' || c == '/' || c == '%' )
		return 2 ;
	else
	{
		if ( c == '+' || c == '-' )
			return 1 ;
		else
			return 0 ;
	}
}
// Menampilkan hasil konversi 
void show ( struct infix pq )
{
	while ( *( pq.t ) )
	{
		printf ( " %c", *( pq.t ) ) ;
		pq.t++ ;
	}
}
