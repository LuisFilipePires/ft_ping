/* main.c */
#include "ft_ping.h"


int main(int argc, char **argv)
{

	t_alloc		alloc;


	init(alloc);

	ft_parsing (argc, argv, alloc->opt);


	printf("memory alloc.opt: %p \n", (void*)alloc->opt);



	return (0);
}
