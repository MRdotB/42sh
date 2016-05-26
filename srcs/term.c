/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:00:28 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/26 17:13:05 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcsh.h"

void	term_setup(struct termios **config, int ti)
{
	struct termios	new;

//	catch_signal();
	if (!(*config = (struct termios *)ft_memalloc(sizeof(struct termios))))
		return ;
	tcgetattr(STDIN_FILENO, *config);
	new = **config;
	new.c_iflag |= IGNBRK;
	new.c_lflag |= ISIG;
	new.c_lflag &= ~(ICANON | ECHO);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &new);
}

void	term_restore(struct termios **config)
{
	char	cp[3];

	term_clear();
	cmdgoto(0, 0);
	cmdput("ve");
	cmdput("te");
	tcsetattr(STDIN_FILENO, TCSANOW, *config);
	signal(SIGTSTP, SIG_DFL);
	cp[0] = (*config)->c_cc[VSUSP];
	cp[1] = '\n';
	cp[2] = '\0';
	ioctl(isatty(STDOUT_FILENO), TIOCSTI, &cp);
	free(*config);
	*config = NULL;
}

void	term_clear(void)
{
	int	i;

	i = termsize(1);
	while (--i >= 0)
	{
		cmdgoto(0, i);
		cmdput("dl");
	}
}

int		termsize(int xy)
{
	int				ret;
	struct winsize	win;

	ret = 0;
	if (!ioctl(STDIN_FILENO, TIOCGWINSZ, &win))
		ret = (xy) ? win.ws_row : win.ws_col;
	return (ret);
}
