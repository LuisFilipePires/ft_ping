/*parsing*/

#include "ft_ping.h"

void ft_parsing(int argc, char **argv, t_options *opt)
{

	int	option;

	option = 0;
	
	while ((option = getopt(argc, argv, "v?")) != -1)
	{
		switch (option)
		{
			case 'v':
				//active verbose
				opt->verbose = 1;
				break;
			case '?':
				// show help/how to
				break;
			default:
				break;
		}
	
	}
}
