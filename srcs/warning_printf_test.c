/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning_printf_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:54:49 by rde-mour          #+#    #+#             */
/*   Updated: 2023/12/02 16:55:47 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(int argc, char **argv)
{
	int	i;
	char str[1024];
	char **flags;
	const char *s;

	if (argv == (void *)0 || argc == 1 || strcmp(argv[1], "m") == 0)
	{
		argc = 1;
		printf("\033[0;95m\nMANDATORY\n\033[0m");
		char *flagss[] = {"", 0};
		flags = flagss;
	}
	else
	{
		if (strcmp(argv[1], "b") == 0)
			argc = 1;
		printf("\033[0;95m\nBONUS\n\033[0m");
		char *flagss[] = {"", "-", "-.", "-.5", "-10", "-10.", "-10.5", "+",
			"+.", "+.5", "+10", "+10.", "+10.5", "-+", "-+.", "-+.5", "-+10",
			"-+10.", "-+10.5", "0", "0.", "0.5", "010", "010.", "010.5", "-0",
			"-0.", "-0.5", "-010", "-010.", "-010.5", " ", " .", " .5", " 10",
			" 10.", " 10.5", "- ", "- .", "- .5", "- 10", "- 10.", "- 10.5",
			"#", "#.", "#.5", "#10", "#10.", "#10.5", "-#", "-#.", "-#.5",
			"-#10", "-#10.", "-#10.5", ".", ".5", ".10", ".1", 0 };
		flags = flagss;
	}

	printf("\033[0;93mcategory: null\033[0m\n");
	test_noargs(NULL);
	printf("\033[0;93m\ncategory: null arguments\033[0m\n");
	test_noargs("t");
	test_noargs("teste");
	test_noargs("csdiupxX");

	i = 0;
	while (flags[i])
	{
		if (argc == 1 || strcmp(argv[1], "c") == 0)
		{
			sprintf(str, " %%%sc ", flags[i]);
			printf("\033[0;93m\ncategory:%s\033[0m\n", str);
			s = str;
			test(s, 'c');
			test(s, '\n');
			test(s, 97);
			test(s, 0);
		}

		if (argc == 1 || strcmp(argv[1], "s") == 0)
		{
			sprintf(str, " %%%ss ", flags[i]);
			printf("\033[0;93m\ncategory:%s\033[0m\n", str);
			s = str;
			test(s, "");
			test(s, (char *)0);
			test(s, "some string with %s here");
			test(s, "can you handle \t and \n?");
			test(s, "{} al$#@@@^&$$^#^@@^$*((&");
			sprintf(str, " x%%%ssx ", flags[i]);
			s = str;
			test(s, "");
			test(s, (char *)0);
			test(s, "some string with %s here");
			test(s, "can you handle \t and \n?");
			test(s, "{} al$#@@@^&$$^#^@@^$*((&");
			sprintf(str, " %%%ss %%%ss %%%ss ", flags[i], flags[i], flags[i]);
			s = str;
			test(s, "And", "Some", "Join");
			test(s, "And", (char *)0, "Join");
			test(s, "And", "Some", "Join");
			sprintf(str, " x%%%ssx x%%%ssx x%%%ssx ", flags[i], flags[i], flags[i]);
			s = str;
			test(s, "And", "Some", "Join");
			test(s, "And", (char *)0, "Join");
			test(s, "And", "Some", "Join");
		}

		if (argc == 1 || !strcmp(argv[1], "d"))
		{
			sprintf(str, " %%%sd ", flags[i]);
			printf("\033[0;93m\ncategory:%s\033[0m\n", str);
			s = str;
			test(s, 1);
			test(s, -1);
			test(s, -0);
			test(s, 0);
			test(s, 10);
			test(s, -10);
			test(s, INT_MAX);
			test(s, INT_MIN);
			sprintf(str, " x%%%sdx ", flags[i]);
			s = str;
			test(s, 1);
			test(s, -1);
			test(s, -0);
			test(s, 0);
			test(s, 10);
			test(s, -10);
			test(s, INT_MAX);
			test(s, INT_MIN);
			sprintf(str, " %%%sd %%%sd %%%sd ", flags[i], flags[i], flags[i]);
			s = str;
			test(s, 10000, 0, INT_MIN);
			sprintf(str, " x%%%sdx x%%%sdx x%%%sdx ", flags[i], flags[i], flags[i]);
			s = str;
			test(s, 10000, 0, INT_MIN);
		}

		if (argc == 1 || !strcmp(argv[1], "i"))
		{
			sprintf(str, " %%%si ", flags[i]);
			printf("\033[0;93m\ncategory:%s\033[0m\n", str);
			s = str;
			test(s, 1);
			test(s, -1);
			test(s, -0);
			test(s, 0);
			test(s, 10);
			test(s, -10);
			test(s, INT_MAX);
			test(s, INT_MIN);
			sprintf(str, " x%%%six ", flags[i]);
			s = str;
			test(s, 1);
			test(s, -1);
			test(s, -0);
			test(s, 0);
			test(s, 10);
			test(s, -10);
			test(s, INT_MAX);
			test(s, INT_MIN);
			sprintf(str, " %%%si %%%si %%%si ", flags[i], flags[i], flags[i]);
			s = str;
			test(s, 10000, 0, INT_MIN);
			sprintf(str, " x%%%six x%%%six x%%%six ", flags[i], flags[i], flags[i]);
			s = str;
			test(s, 10000, 0, INT_MIN);
		}

		if (argc == 1 || !strcmp(argv[1], "u"))
		{
			sprintf(str, " %%%su ", flags[i]);
			printf("\033[0;93m\ncategory:%s\033[0m\n", str);
			s = str;
			test(s, 1);
			test(s, -1);
			test(s, -0);
			test(s, 0);
			test(s, 10);
			test(s, -10);
			test(s, INT_MAX);
			test(s, INT_MIN);
			sprintf(str, " x%%%sux ", flags[i]);
			s = str;
			test(s, 1);
			test(s, -1);
			test(s, -0);
			test(s, 0);
			test(s, 10);
			test(s, -10);
			test(s, INT_MAX);
			test(s, INT_MIN);
			sprintf(str, " %%%su %%%su %%%su ", flags[i], flags[i], flags[i]);
			s = str;
			test(s, 10000, 0, INT_MIN);
			sprintf(str, " x%%%sux x%%%sux x%%%sux ", flags[i], flags[i], flags[i]);
			s = str;
			test(s, 10000, 0, INT_MIN);
		}

		if (argc == 1 || !strcmp(argv[1], "p"))
		{
			sprintf(str, " %%%sp ", flags[i]);
			printf("\033[0;93m\ncategory:%s\033[0m\n", str);
			s = str;
			test(s, "");
			test(s, (void *)-0);
			test(s, (void *)0);
			test(s, (void *)12345);
			test(s, (void *)-12345);
			test(s, (void *)ULONG_MAX);
			sprintf(str, " x%%%spx ", flags[i]);
			s = str;
			test(s, "");
			test(s, (void *)-0);
			test(s, (void *)0);
			test(s, (void *)12345);
			test(s, (void *)-12345);
			test(s, (void *)ULONG_MAX);
			sprintf(str, " %%%sp %%%sp %%%sp ", flags[i], flags[i], flags[i]);
			s = str;
			test(s, (void *)ULONG_MAX, (void *)0, (void *)-12345);
			test(s, (void *)ULONG_MAX, "", (void *)ULONG_MAX);
			sprintf(str, " x%%%spx x%%%spx x%%%spx ", flags[i], flags[i], flags[i]);
			s = str;
			test(s, (void *)ULONG_MAX, (void *)0, (void *)-12345);
			test(s, (void *)ULONG_MAX, "", (void *)ULONG_MAX);
		}

		if (argc == 1 || !strcmp(argv[1], "x"))
		{
			sprintf(str, " %%%sx ", flags[i]);
			printf("\033[0;93m\ncategory:%s\033[0m\n", str);
			s = str;
			test(s, 1);
			test(s, -1);
			test(s, -0);
			test(s, 0);
			test(s, 10);
			test(s, -10);
			test(s, INT_MAX);
			test(s, INT_MIN);
			sprintf(str, " x%%%sxx ", flags[i]);
			s = str;
			test(s, 1);
			test(s, -1);
			test(s, -0);
			test(s, 0);
			test(s, 10);
			test(s, -10);
			test(s, INT_MAX);
			test(s, INT_MIN);
			sprintf(str, " %%%sx %%%sx %%%sx ", flags[i], flags[i], flags[i]);
			s = str;
			test(s, 10000, 0, INT_MIN);
			sprintf(str, " x%%%sxx x%%%sxx x%%%sxx ", flags[i], flags[i], flags[i]);
			s = str;
			test(s, 10000, 0, INT_MIN);
		}

		if (argc == 1 || !strcmp(argv[1], "X"))
		{
			sprintf(str, " %%%sX ", flags[i]);
			printf("\033[0;93m\ncategory:%s\033[0m\n", str);
			s = str;
			test(s, 1);
			test(s, -1);
			test(s, -0);
			test(s, 0);
			test(s, 10);
			test(s, -10);
			test(s, INT_MAX);
			test(s, INT_MIN);
			sprintf(str, " X%%%sXX ", flags[i]);
			s = str;
			test(s, 1);
			test(s, -1);
			test(s, -0);
			test(s, 0);
			test(s, 10);
			test(s, -10);
			test(s, INT_MAX);
			test(s, INT_MIN);
			sprintf(str, " %%%sX %%%sX %%%sX ", flags[i], flags[i], flags[i]);
			s = str;
			test(s, 10000, 0, INT_MIN);
			sprintf(str, " X%%%sXX X%%%sXX X%%%sXX ", flags[i], flags[i], flags[i]);
			s = str;
			test(s, 10000, 0, INT_MIN);
		}
		i++;
	}

	if (argc == 1 || !strcmp(argv[1], "X"))
	{
		printf("\033[0;93m\ncategory: %%\033[0m\n");
		test_noargs(" %% ");
		test_noargs(" %%%%%%");
		test_noargs(" %%c%%s%%d%%i%%u%%p%%x%%X ");
		test_noargs(" %%cc%%ss%%dd%%ii%%uu%%pp%%x%%XX ");
		test_noargs(" %%-d ");
		test_noargs(" %%0d ");
		test_noargs(" %%+d ");
		test_noargs(" %% d ");
		test_noargs(" %%#x ");
		test_noargs(" %%c ");
		test_noargs(" %%s ");
		test_noargs(" %%d ");
		test_noargs(" %%i ");
		test_noargs(" %%u ");
		test_noargs(" %%p ");
		test_noargs(" %%x ");
		test_noargs(" %%X ");
		test_noargs(" %%c%%c ");
		test_noargs(" %%s%%s ");
		test_noargs(" %%d%%d ");
		test_noargs(" %%i%%i ");
		test_noargs(" %%u%%u ");
		test_noargs(" %%p%%p ");
		test_noargs(" %%x%%x ");
		test_noargs(" %%X%%X ");
		test(" %d%%#x ", INT_MAX);
	}
	return (0);
}
