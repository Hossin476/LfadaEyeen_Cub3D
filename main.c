/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:21:34 by ykhourba          #+#    #+#             */
/*   Updated: 2023/10/12 15:44:41 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_textures(t_data *data, t_texture *texture, t_player *player)
{
	player->ea = load_textures(texture->ea);
	player->so = load_textures(texture->so);
	player->no = load_textures(texture->no);
	player->we = load_textures(texture->we);
	data->ea = img_to_double_pointer(player->ea);
	data->so = img_to_double_pointer(player->so);
	data->no = img_to_double_pointer(player->no);
	data->we = img_to_double_pointer(player->we);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_utils		*util;
	t_player	player;
	t_clfr		clfr;

	if (argc != 2)
		return (printf("Error:\nIncorrect parsing"), exit(1), 1);
	util = ft_validate_scene(*(argv + 1), &clfr);
	if (!util)
		return (printf("Error:\nIncorrect parsing"), exit(1), 1);
	data.utils = util;
	util->height = HEIGHT;
	util->width = WIDTH;
	set_textures(&data, util->texture, &player);
	data.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", 1);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	init_player(&player, util, &data, &clfr);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_key_hook(data.mlx, ft_handle_moves, &player);
	mlx_loop_hook(data.mlx, update, &player);
	mlx_cursor_hook(data.mlx, handle_mouse, &player);
	mlx_loop(data.mlx);
	ft_free_all(&player);
}
