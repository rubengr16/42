#include <stdio.h>
#include <string.h>
#include "libft.h"
int main()
{
            char    *src = "this is a good nyancat !\r\n";
            char    dst1[0xF0];
            char    dst2[0xF0];
            int     size = strlen(src);

            memmove(dst1, src, size);
            ft_memmove(dst2, src, size);	
			printf("\n %s", dst2);
			printf("\n %s", dst1);
}
