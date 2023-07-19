#include <stdio.h>

/**
error: cannot assign to variable 'a' with const-qualified type 'const int'
        a = 42;
        ~ ^
const_test.c:5:12: note: variable 'a' declared const here
        const int       a;
        ~~~~~~~~~~~~~~~~^
1 error generated.
*/
/**
 * correct way to declare a const variable
 * const int a = 42;
*/
int	main(void)
{
	const int	a;

	a = 42;
	printf("a = %d\n", a);
	return (0);
}
