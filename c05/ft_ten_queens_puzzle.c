#include <unistd.h>
#include <stdio.h>
void brd_printer(int *line, int *cnt)
{
	int		p;
	
	p = -1;
	while (++p < 10)
		write(1, line + 48, 1);
	(*cnt)++;
}

int	pos_avail(int *line, int *rsv, int i, int q)
{
	int		l;
	int		r;
	int		t;
	
	l = i + 1;
	r = q + 1;
	while (l-- && r--) {
		if (l > 0 && (q >= line[l - 1] - 1 && q <= line[l - 1] + 1))
			return (0);
		if (line[l - 1] == r - 1 || line[l - 1] == r + 1)
			return (0);
	}
	if (i == 9)
	{
		t = 0;
		while (t < i) {
			if (!line[t])
				return (0);
		}
	}
	rsv[line[i]] = 0;
	line[i] = q;
	rsv[q] = 1;
	printf("-----\n");

	while (*line) {
		printf("%d",*(line++));
	}
	printf("\n");
	while (*rsv) {
		printf("%d",*(rsv++));
	}
	printf("\n");

	return (1);
}

void	set_pos(int *line, int *rsv, int i, int *cnt)
{
	int		q;
	
	q = -1;
	if (line[i])
		q = line[i];
	while (i < 10 && ++q < 10)
	{
		line[i] = q;
		if (rsv[q] == 1)
			continue ;
		else
		{
			if (pos_avail(line, rsv, i, q))
				set_pos(line, rsv, i + 1, cnt);
		}
	}
	if (line[9] && pos_avail(line, rsv, i, q))
		brd_printer(line, cnt);
}

int	ft_ten_queens_puzzle(void)
{
	int		line[10];
	int		rsv_c[10];
	int		cnt[1];
	int		init;
	
	init = -1;
	while (++init < 10)
	{
		line[init] = 0;
		rsv_c[init] = 0;
	}
	cnt[0] = 0;
	set_pos(line, rsv_c, 0, cnt);
	return (*cnt);
}

int main (void)
{
	int a;
	a = ft_ten_queens_puzzle();
	printf("%d", a);
}
