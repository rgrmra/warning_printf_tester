#ifndef TEST_H
# define TEST_H

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

static int n;

static void	redirect_fd(int *file_desc, int *copy_out)
{
	*file_desc = open("temp", O_RDWR | O_CREAT | O_TRUNC, 0666);
	*copy_out = dup(fileno(stdout));
	dup2(*file_desc, fileno(stdout));
}

static void	reset_output(int *copy_out)
{
	dup2(*copy_out, fileno(stdout));
	close(*copy_out);
}

static void	clean_up(FILE *file)
{
	if (fclose(file))
	{
		fprintf(stderr, "Cannot close temp file\n");
		exit (1);
	}
	if (remove ("temp"))
	{
		fprintf(stderr, "Cannot remove temp file\n");
		exit (1);
	}
}

static int	compare_results(const char *str, const int fd, int m, int y)
{
	FILE	*file;
	char	res[1024];
	int		size;
	int		fdread;
	
	bzero(res, 1024);
	fdread = open("temp", O_RDONLY, 0666);
	size = read(fdread, res, 1024);
	close(fdread);
	file = fdopen(fd, "r");
	clean_up(file);
	n += 1;
	if (memcmp(str, res, size) == 0 && m == y)
		printf("\033[0;32m%d.OK\033[0m ", n);
	else
	{
		printf("\033[0;31m%d.KO\033[0m ", n);
		printf("\nExpected:\t%d %s\n  Result:\t%d %s\n\n", y, str, m, res);
	}
	return (0);
}

#define test_noargs(fmt)								\
{														\
	static int			fd;								\
	static int			cp;								\
	char		str[1024];								\
	int			ft_size;								\
	int			pf_size;								\
														\
	redirect_fd(&fd, &cp);								\
	ft_size = ft_printf(fmt);							\
	pf_size = sprintf(str, fmt);						\
	reset_output(&cp);									\
	compare_results(str, fd, ft_size, pf_size);			\
}

#define test(fmt, ...)									\
{														\
	static int			fd;								\
	static int			cp;								\
	char		str[1024];								\
	int			ft_size;								\
	int			pf_size;								\
														\
	redirect_fd(&fd, &cp);								\
	ft_size = ft_printf(fmt, __VA_ARGS__);				\
	pf_size = sprintf(str, fmt, __VA_ARGS__);			\
	reset_output(&cp);									\
	compare_results(str, fd, ft_size, pf_size);			\
}

int	ft_printf(const char *fmt, ...);

#endif
