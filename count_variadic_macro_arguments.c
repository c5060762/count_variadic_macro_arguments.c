#include <stdio.h>
#include <stdarg.h>

int count ( void *dummy, ... ) {
	int i = 0;
	va_list args;
	va_start ( args, dummy );
	void *b = NULL;
	do {
		b = va_arg ( args, void * );
		i++;
	} while ( b != NULL );
	va_end ( args );
	return i;
}

#define Count(...) count(__VA_ARGS__,NULL)

int main() {
	char *intFmt = "%d\n";
	printf ( intFmt,  Count ( "a", 3, 'f', 54, 87 ) ); //5   [OK]
	printf ( intFmt,  Count ( "a", 3.5, 'f', 54, 87 ) ); //4 [??]
	printf ( intFmt,  Count ( "a", 3, 'f', 54, intFmt ) ); //5 [OK]
	return 0;
}
