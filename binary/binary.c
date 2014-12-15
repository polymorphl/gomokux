/*


*/

#include <stdio.h>

typedef unsigned char uchar;

// void	put_bin(uchar c)
// {
// 	int i = 9;
// 	printf("num = %d\n", c);
// 	while (--i >= 0)
// 		printf("-> %d\n", c >> i);
// 	printf("\n");
// }

uchar	set_in(uchar map, uchar pos, uchar mask)
{
	uchar tmp = 0;
	tmp |= mask;
	tmp <<= pos * 2;
	return (map |= tmp);
}

uchar	get_in(uchar map, uchar pos)
{
	char dec[4] = {6, 4, 2, 0};
	uchar b = map;
	b <<= dec[pos];
	return (b >>= dec[pos] + (pos * 2));
}

// dans le bit ->
// rangée : 3  2  1  0
// octet  : 00 00 00 00

int main(int argc, char const *argv[])
{
	uchar mask = 128; // <- 10 00 00 00
	uchar set = set_in(mask, 2, 1); // je set à la rangée 2 la valeur 1: 10 >01< 00 00
	uchar get = get_in(set, 3); // je get la valeur à la rangée 3: >10< 01 00 00

	if (get & 2) { // si get == 2 alors 10 & 10 == 1 donc ca match
		printf("ca match !\n");
	} else {
		printf("ca match pas !\n");
	}
	return 0;
}
