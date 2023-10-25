/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:21:25 by ykhourba          #+#    #+#             */
/*   Updated: 2023/10/16 11:22:29 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"

# define TILE_SIZE 24.0
# define HEIGHT 720.0
# define WIDTH 1280.0

typedef struct s_texture
{
	char	*so;
	int		fd;
	char	*str;
	char	*img;
	char	*no;
	char	*we;
	char	*ea;
	char	*fr;
	char	*cl;
}			t_texture;

typedef struct s_clfr
{
	int	fr;
	int	cl;
}		t_clfr;

typedef struct s_colors
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;
	uint32_t	i;
	uint32_t	j;
	int			count;
}				t_colors;

typedef struct s_cord
{
	double	pointx;
	double	pointy;	
}			t_cord;

typedef struct s_map
{
	char			*line;
	int				length;
	struct s_map	*next;
}					t_map;

typedef struct s_utils
{
	t_texture	*texture;
	char		**map;
	double		height;
	double		width;
	double		map_width;
	double		map_height;
}				t_utils;

typedef struct s_wall
{
	double	wall_ht;
	double	wall_dist;
	double	proj_dist;
	double	wall_strip_ht;
	double	ray_increment;
	double	ray_start;
	double	y1;
	double	y2;
	double	height;
	double	width;
	int		i;
}			t_wall;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_utils		*utils;
	t_texture	*texture;
	char		*adr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	uint32_t	**ea;
	uint32_t	**no;
	uint32_t	**we;
	uint32_t	**so;
}				t_data;

typedef struct s_ray
{
	double	hx;
	double	hy;
	double	vx;
	double	vy;
	double	ray_angle;
	int		isvertwallhit;
	int		ishorzwallhit;
	double	vertical_distance;
	double	horizantal_distance;
	double	sm;
}			t_ray;

typedef struct s_circle
{
	double	x_center;
	double	y_center;
}			t_circle;

typedef struct s_player
{
	double			x;
	double			y;
	double			angle;
	double			fov;
	double			speed;
	double			turn_speed;
	double			turn_direction;
	double			walk_direction;
	double			side_direction;
	double			last_x;
	t_data			*data;
	t_circle		*circle;
	t_utils			*util;
	t_ray			*ray;
	t_wall			*wall;
	t_clfr			*clfr;
	mlx_texture_t	*ea;
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
}					t_player;

typedef struct s_intersict
{
	double	step_y;
	double	step_x;
	double	p_y;
	double	p_x;
}			t_instersict;

typedef struct s_minimap
{
	double	pointx;
	double	pointy;
	int		width;
	int		height;
	int		i;
	int		j;
}			t_minimap;

// parsing
int				ft_strcmp(const char *s1, const char *s2);
int				ft_fill_texture(int fd, t_texture *texture);
int				ft_skip_newline2(char *line);
char			*ft_strtrim(char const *s1, char const *set);
int				is_valid_line(char *arg);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
void			*ft_memset(void *str, int c, size_t n);
t_texture		*init_texture(void);
int				ft_check_sides(char *line, t_texture *texture);
int				get_map(t_map **headmap, int fd);
t_texture		*fetching_file(char *scene, t_map **headmap);
int				ft_length(char *tirmed);
int				get_width(t_map *headmap);
int				get_height(t_map *headmap);
void			fill_line(char *map, char *line, int width);
char			**lst_to_arr(t_map *headmap);
void			addback(t_map **headmap, t_map *item);
t_map			*new_item(char *line, int length);
int				ft_strlen2(const char *str);
void			map_validation(char **map);
int				is_player_char(char c);
int				is_border(char **map, int i, int j);
int				has_space_around(char **map, int i, int j);
void			error_handling(int status);
t_utils			*ft_validate_scene(char *scene, t_clfr *clfr);
void			clear_map(char **map);
void			txt_clear(t_texture *texture);
void			lst_clear(t_map *headmap);
void			validate_texture(t_texture *texture, t_clfr *clfr);
char			**ft_split(char const *s, char *str);
int				check_color_range(char **find);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *str, int c);
char			*get_next_line(int fd);
char			*ft_strrchr(const char *str, int c);
// drawing
void			draw_circle(t_player *player, t_circle *circle,
					int radius, int color);
void			draw_player(t_player *player);
void			draw_player2(t_player *player);
void			ft_draw_map(t_player *player);
void			draw_minimap_pixel(t_player *player,
					t_minimap map, int i, int j);

// player
void			init_player(t_player *player,
					t_utils *util, t_data *data, t_clfr *clfr);
int				get_player_pos(t_utils *util, int mode);
void			set_player_angle(t_player *player, char c);

// hooks
void			ft_handle_moves(mlx_key_data_t keydata, void *arg);
void			update(void *param);
int32_t			pixel_color(int32_t r, int32_t g, int32_t b, int32_t a);
void			handle_mouse(double xpos, double ypos, void *param);

// utils
int				get_grid_height(char **grid);
int				is_facing_down(double ray);
int				is_facing_right(double ray);
int				is_wall(double posx, double posy, char **map);
void			normalize_angle(double *angle);
void			ft_free_all(t_player *player);
void			ft_free_texture(uint32_t **texture, mlx_texture_t *img);

// rays
void			vertical_ray(double angle, t_player *player, t_ray *ray);
void			horizantal_ray(double angle, t_player *player, t_ray *ray);
void			wall_projection(t_player *player);

// textures
mlx_texture_t	*load_textures(char *side);
u_int32_t		**img_to_double_pointer(mlx_texture_t *img);
void			ft_putx_texture(t_player *player,
					t_cord *point, t_ray *ray, t_wall *wall);
int				ft_check_no_so(t_player *player,
					t_cord *point, t_ray *ray, t_wall *wall);
void			set_color(t_colors *colors,
					mlx_texture_t *img, uint32_t	**pixels);

// wall utils
void			check_wall(t_wall *wall, double *step);
void			check_ray(t_ray *ray, t_wall *wall, t_player *player);
void			init_vals(t_wall *wall, t_player *player);
double			check_xtext1(t_ray *ray, double ray_start,
					double x_text, t_player *player);
double			check_xtext(t_ray *ray, double ray_start,
					double x_text, t_player *player);

#endif