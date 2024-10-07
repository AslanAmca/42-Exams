#include "flood_fill.h"

void fill(char **tab, t_point size, t_point begin, char char_to_change)
{
	if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x)
		return;

	if (tab[begin.y][begin.x] != char_to_change)
		return;

	tab[begin.y][begin.x] = 'F';
	fill(tab, size, (t_point){begin.x - 1, begin.y}, char_to_change);
	fill(tab, size, (t_point){begin.x + 1, begin.y}, char_to_change);
	fill(tab, size, (t_point){begin.x, begin.y - 1}, char_to_change);
	fill(tab, size, (t_point){begin.x, begin.y + 1}, char_to_change);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
