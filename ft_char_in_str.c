#include "lib.h"

int	ft_char_in_str(char c, char *match)
{
	while (*match)
		if (c == *match++)
			return (1);
	return (0);
}
