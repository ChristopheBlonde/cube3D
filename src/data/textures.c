# include "cube.h"

// int		**init_tex_tab(t_line *line)
// {
// 	int		**tab;
// 	int		i;

// 	tab = malloc(sizeof(int *) * (NB_OF_TEX));
// 	i = 0;
// 	while (i < NB_OF_TEX)
// 	{
// 		tab[i] = malloc(sizeof(int) * TEX_HEIGHT * TEX_WIDTH);
// 		i++;
// 	}
// 	return (tab);
// }

void	init_textures(t_data *data)
{
	t_line	*line;
	int		x;
	int		y;
	int xorcolor;

	line = data->line;
	// line->texture = init_tex_tab(line);
	x = 0;
	while (x < TEX_WIDTH)
	{
		y = 0;
		while (y < TEX_HEIGHT)
		{
			xorcolor = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
			line->texture[0][TEX_WIDTH * y + x] = 65536 * 254 * (x != y && x != TEX_WIDTH - y); //flat red texture with black cross
			line->texture[1][TEX_WIDTH * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			line->texture[2][TEX_WIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			line->texture[3][TEX_WIDTH * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
			y++;
		}
		x++;
	}
}
