/* ft_ping.h  */
/* luis-fif */
/*  42      */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_options
{
	char	*hostname;	// desteny
	int	verbose;	// -v
	int	numeric;	// -n (bonus)
	int	ttl;		// --ttl (bonus)
	int	count;		// -c (bonus, number of packages)
	double	interval;	// -i (bonus)
} t_options;


