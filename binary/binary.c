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

int main(int argc, char const *argv[])
{
	if (get_in(set_in(128, 2, 1), 3) & 2) {
		printf("ca match !\n");
	}
	return 0;
}
