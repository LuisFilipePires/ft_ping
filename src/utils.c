/* utils.c */

void init(t_alloc alloc)
{
	puts ("init ok");
	t_option *opt;

	opt = malloc ( sizeof (t_option));

	if (!opt)
	{
		fprintf(stderr, "ERROR: malloc fail\n");
		return (1);
	}

	memset (opt, o , sizeof(t_option));

	

	alloc->opt = opt;
}
