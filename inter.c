/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 14:23:13 by abeznik       #+#    #+#                 */
/*   Updated: 2022/03/03 14:31:09 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "nothing" "This sentence hides nothing" | cat -e
nothig$
$>./inter | cat -e
$
*/

int	main(int argc, char **argv)
{
	int res = 0;
	if (argc == 3)
	{
		for (int i = 0; argv[1][i]; i++)
		{
			res = 0;
			for (int a = i - 1; a >= 0; a--)
			{
				if (argv[1][i] == argv[1][a])
					res = 1;
			}
			if (res == 0)
			{
				for (int x = 0; argv[2][x]; x++)
				{
					if (argv[1][i] == argv[2][x])
						res = 1;
				}
				if (res == 1)
					write(1, &argv[1][i], 1);
			}
		}
	}
	write(1, "\n", 1);
}