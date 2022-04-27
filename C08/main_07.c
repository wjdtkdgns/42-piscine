#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex00/ft_strdup.c"
#include "ex01/ft_range.c"
#include "ex02/ft_ultimate_range.c"
#include "ex03/ft_strjoin.c"
#include "ex04/ft_convert_base.c"
#include "ex04/ft_convert_base2.c"
#include "ex05/ft_split.c"

char	*ft_strdup(char *src);

int main(void)
{
	printf("Your: %s\n", ft_strdup("Hello World!"));
	printf("CStdLib: %s\n", strdup("Hello World!"));
	printf("Your: %s\n", ft_strdup("ㅋㅋㅋ"));
	printf("CStdLib: %s\n", strdup("ㅋㅋㅋ"));
    printf("\n\n\n");


    int *p;
    printf("%p\n", ft_range(0, 0));
	printf("%p\n", ft_range(1, 0));
	printf("%p\n", ft_range(1, -1));

    p = ft_range(-1, 1);
	for  (int i = 0; i < 1 - (-1); i++)
		printf("%d ", p[i]);
	printf("\n");

    p = ft_range(-28, 21);
	for  (int i = 0; i < 49; i++)
		printf("%d ", p[i]);
	printf("\n");

    p = ft_range(1, 3);
	for  (int i = 0; i < 3 - 1; i++)
		printf("%d ", p[i]);
    printf("\n\n\n");


    printf("ft_ultimate_range(&p, 0, 0): %d, %p\n", ft_ultimate_range(&p, 0, 0), p);
	printf("ft_ultimate_range(&p, 1, 0): %d, %p\n", ft_ultimate_range(&p, 1, 0), p);
	printf("ft_ultimate_range(&p, 2, 0): %d, %p\n", ft_ultimate_range(&p, 1, 0), p);

    int min;
	int len;
    int max;
    min = -5;
    max = 5;
	len = ft_ultimate_range(&p, min, max);
	printf("ft_ultimate_range(&p, %d, %d): [len %d] ", min, max, len);
	for  (int i = 0; i < max - min; i++)
		printf("%d ", p[i]);
	printf("\n");

    min = 1;
    max = 3;
	len = ft_ultimate_range(&p, min, max);
	printf("ft_ultimate_range(&p, %d, %d): [len %d] ", min, max, len);
	for  (int i = 0; i < max - min; i++)
		printf("%d ", p[i]);
	printf("\n");

    min = -5;
    max = -3;
	len = ft_ultimate_range(&p, min, max);
	printf("ft_ultimate_range(&p, %d, %d): [len %d] ", min, max, len);
	for  (int i = 0; i < max - min; i++)
		printf("%d ", p[i]);
    printf("\n\n\n");



    int size;
	char* texts1[] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "k" };
    char sep1[] = ", ";
    size = 10;
	char *ret = ft_strjoin(size, texts1, sep1);
	printf("%s\n%d\n\n", ret, (int)strlen(ret));
	free(ret);

	char* texts2[] = { };
    char sep2[] = ", ";
    size = 0;
	char *ret2 = ft_strjoin(size, texts2, sep2);
	printf("%s\n%d\n\n", ret2, (int)strlen(ret2));
	free(ret2);

    char* texts3[] = { };
    char sep3[] = ", ";
    size = -1;
	char *ret3 = ft_strjoin(size, texts3, sep3);
	printf("%s\n%d\n\n", ret3, (int)strlen(ret3));
	free(ret3);

	char* texts4[] = { "adasdsa", "", "", "zxcva", "12134", "", "@@", "!", "??", "Hello World!" };
    char sep4[] = " - ";
    size = 9;
	char *ret4 = ft_strjoin(size, texts4, sep4);
	printf("%s\n%d\n\n", ret4, (int)strlen(ret4));
	free(ret4);

	char* texts5[] = { "one word" };
    char sep5[] = " , ";
    size = 1;
	char *ret5 = ft_strjoin(size, texts5, sep5);
	printf("%s\n%d\n\n", ret5, (int)strlen(ret5));
	free(ret5);

	char* texts6[] = { "Diff", "OK", ":D", "\n", "Grade:", "100" };
    char sep6[] = " ";
    size = 6;
	char *ret6 = ft_strjoin(size, texts6, sep6);
	printf("%s\n%d\n\n", ret6, (int)strlen(ret6));
	free(ret6);
    printf("\n\n\n");




	printf("%s\n", ft_convert_base("2147483647", "0123456789", "0123456789abcdef"));
	printf("7fffffff\n");

	printf("%s\n", ft_convert_base("---------7fffffff", "0123456789abcdef", "01"));
	printf("-1111111111111111111111111111111\n");

	printf("%s\n", ft_convert_base("---+--0001023a", "0123456789", "0123456789"));
	printf("-1023\n");

	printf("%s\n", ft_convert_base("-0", "0123456789", "abcdefghij"));
	printf("a\n");

	printf("%s\n", ft_convert_base(" \t\t\t ---+++ff-f", "0123456789abcdef", "0123456789"));
	printf("-255\n");

	printf("%s\n", ft_convert_base("aasdffeessddfffss", "asedf", "ss"));
	printf("(null)\n");

	printf("%s\n", ft_convert_base("  -+-+- -+asdf", "ai sdf", "fdsa"));
	printf("(null)\n");

	printf("%s\n", ft_convert_base("\t\t\t\t \v --++-asdf", "asdf", "fd-as"));
	printf("(null)\n");

	printf("%s\n", ft_convert_base("   -+a", "abcde", ""));
	printf("(null)\n");

	printf("%s\n", ft_convert_base(" -+a", "", "df"));
	printf("(null) \n");
    printf("\n\n\n");

	int		i;

    char	**array;
    char    *str = ",1,2,3";
    char    *charset = ",";
	array = ft_split(str, charset);
	i = 0;
	while (array[i])
	{
		printf("'%s' (len=%d)\n", array[i], (int)strlen(array[i]));
		i++;
	}
    printf("\n");

    char	**array1;
    char    *str1 = "Hello.,World,.!!KOKO!ZZZ.Hello.Good.World!KK!ZORO,Good";
    char    *charset1 =",.!";
	array1 = ft_split(str1, charset1);
	i = 0;
	while (array1[i])
	{
		printf("'%s' (len=%d)\n", array1[i], (int)strlen(array1[i]));
		i++;
	}
     printf("\n");

    char	**array2;
    char    *str2 = "abcakaabcaakaabce";
    char    *charset2 ="bck";
	array2 = ft_split(str2, charset2);
	i = 0;
	while (array2[i])
	{
		printf("'%s' (len=%d)\n", array2[i], (int)strlen(array2[i]));
		i++;
	}
}
