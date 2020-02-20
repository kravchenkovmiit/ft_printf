
#include "libft.h"

char	*ft_cptoch(char *s, int c)
{
	char	*res;
	char	*smb;

	if (!s)
		return (NULL);
	if (!(smb = ft_strchr(s, c)))
		return (NULL);
	if (!(res = ft_strnew(smb - s)))
		return (NULL);
	res = ft_strncpy(res, s, smb - s);
	return (res);
}
