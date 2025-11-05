/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerner <pgerner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:09:51 by cgerner           #+#    #+#             */
/*   Updated: 2025/07/14 12:44:24 by pgerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# define TEXTURE_SIZE 128
# define NB_TEXTURE	4
# define WIDTH 1280
# define HEIGHT 720
# define FORWARD        119
# define BACKWARD        115
# define LEFT        97
# define RIGHT        100
# define KEY_UP       65362
# define KEY_DOWN     65364
# define KEY_LEFT     65361
# define KEY_RIGHT    65363
# define ESC      65307

typedef enum e_directions
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3,
}	t_directions;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_texture
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		width;
	int		height;
	int		line_length;
	int		endian;
}			t_texture;

typedef struct s_imgs
{
	t_texture	*north;
	t_texture	*south;
	t_texture	*west;
	t_texture	*east;
}				t_imgs;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	char				**file;
	char				**map;
	char				**map_cpy;
	char				*str;
	char				*line;
	char				*tmp;
	char				*north_path;
	char				*south_path;
	char				*west_path;
	char				*east_path;
	int					map_start;
	int					map_end;
	int					count_no;
	int					count_so;
	int					count_we;
	int					count_ea;
	int					count_floor;
	int					count_ceiling;
	int					count_player;
	int					rows;
	int					column;
	int					fd;
	int					color_parsed;
	int					map_x;
	int					map_y;
	int					step_x;
	int					step_y;
	int					side_wall;
	int					draw_start;
	int					draw_end;
	double				delta_dist_x;
	double				delta_dist_y;
	double				dist_ray_x;
	double				dist_ray_y;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				cam_x;
	double				cam_y;
	double				plane_x;
	double				plane_y;
	double				ray_x;
	double				ray_y;
	double				wall_x;
	double				speed;
	int					*tex_buffer[NB_TEXTURE];
	t_directions		*directions;
	t_color				*color;
	t_color				*ceiling;
	t_color				*floor;
	t_imgs				*imgs;
}						t_data;

void				*error(t_data *data, char *tmp);
char				*join(char *s1, char *s2);
int					ft_sochr(char *str, char *s);
void				error_fd(t_data *data, int value);
int					ft_atoi_cub(const char *str);
void				draw_window(t_data *data, int x);
int					check_value(t_data *data);
int					check_nb_of_value(t_data *data);
int					check_line(char **line, t_data *data);
int					check_column(char **column, t_data *data);
int					check_walled(t_data *data);
void				location_player(char **loc, t_data *data);
int					check_end_file(t_data *data);
int					check_last_line_map(char *line);
int					is_map_line(char *line);
int					first_line_map(char *line);
int					is_map_column(char *line);
int					find_last_line_map(char **map);
int					is_line_map(char *line);
int					is_first_char_valid(t_data *data);
int					is_valid_config_char(char c);
int					is_valid_map_char(char c);
int					is_whitespace(char c);
void				reading_map(char **argv, t_data *data);
int					parsing(char **argv, t_data *data);
void				fill_spaces(t_data *data);
void				replace_spaces(t_data *data);
int					has_empty_line(char *str);
char				*convert_map_line(char *line);
int					texture_num(t_data *data);
void				init_textures_buffer(t_data *data);
int					parse_line_before_map(t_data *data);
t_color				*create_color(void);
int					parse_color(t_data *data, t_color *color);
void				free_all(t_data *data);
void				free_char(char **s);
int					destroy(t_data *data);
int					create_color_map(t_color *color);
void				rotate_right(t_data *data);
void				rotate_left(t_data *data);
int					cast_ray(t_data *data);
int					on_keypress(int keysym, t_data *data);

#endif