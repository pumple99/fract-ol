#include "libft/gnl.h"
#include "libft/pf_printf.h"
#include "libft/libft.h"

static int	get_frac_argu(void)
{
	char	*in;
	char	**in_arr;

	ft_printf("Input [fractal_type] [fractal_argument]\n");
	in = get_next_line(0);
	if (in == (char *)1)
		return (print_try_again());
	else
	{
		in_arr = ft_split(in, ' ');
		free(in);
	}
	return (0);
}

int	main()
{
	int	e;

	e = 0;
	get_frac_argu();
}
