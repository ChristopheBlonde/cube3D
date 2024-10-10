# include "cube.h"


int	**init_tex_tab(void)
{
	int	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(int *) * NB_OF_TEX);
	while (i < NB_OF_TEX)
	{
		tab[i] = malloc(sizeof(int) * (TEX_HEIGHT * TEX_WIDTH));
		i++;
	}
	return (tab);
}

void	init_textures(t_data *data)
{
	t_line	*line;
	int		x;
	int		y;
	int xorcolor;
	int	witdh;
	int height;

	line = data->line;
	line->texture = init_tex_tab();
	line->texture[0] = mlx_xpm_file_to_image(data->win->mlx_ptr, data->map.no, &witdh, &height);
	x = 0;
	while (x < TEX_WIDTH)
	{
		y = 0;
		while (y < TEX_HEIGHT)
		{
			xorcolor = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
			// line->texture[0][TEX_WIDTH * y + x] = 65536 * 254 * (x != y && x != TEX_WIDTH - y); //flat red texture with black cross
			line->texture[1][TEX_WIDTH * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			line->texture[2][TEX_WIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			line->texture[3][TEX_WIDTH * y + x] = 256 * xorcolor; //xor green
			y++;
		}
		x++;
	}
}
