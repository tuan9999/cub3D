/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 11:42:46 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/05 15:56:54 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"

# define INIT_P_DIR_X    -1
# define INIT_P_DIR_Y    0
# define INIT_P_PLANE_X  0
# define INIT_P_PLANE_Y  0.66
# define MV_SPEED        0.099
# define ROT_SPEED       0.0745
# define AMB_LIGHT       7

# define WHITE           0xFFFFFF
# define RED             0xFF0000
# define GREEN           0x00FF00
# define BLUE            0x0000FF
# define BLACK           0x000000

# define K_ESC		53
# define K_W		13
# define K_S		1
# define K_A		0
# define K_D		2
# define K_LEFT		123
# define K_RIGHT	124

# define E_KEY_PRESS        2
# define E_KEY_RELEASE      3
# define E_MOUSE_PRESS      4
# define E_MOUSE_RELEASE    5
# define E_MOUSE_MOVE       6
# define E_EXIT             17

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_sort
{
	int				gap;
	int				swapped;
	int				i;
	int				tempord;
	double			tempdist;
	int				j;
}					t_sort;

typedef struct		s_texture
{
	void			*img_ptr;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	double			wall_x;
	int				text_x;
	int				text_y;
	int				textnum;
}					t_texture;

typedef	struct		s_sprite
{
	void			*img_ptr;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	double			wall_x;
	int				text_x;
	int				text_y;
	int				textnum;
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				draw_start_y;
	int				draw_end_y;
	int				sprite_width;
	int				draw_start_x;
	int				draw_end_x;
	int				stripe;
}					t_sprite;

typedef struct		s_sprite_list
{
	double			x;
	double			y;
}					t_sprite_list;

typedef	struct		s_globals
{
	char			**file;
	int				filelen;
	int				win_x;
	int				win_y;
	t_color			floor_color;
	t_color			ceiling_color;
	unsigned int	fl_color;
	unsigned int	ce_color;
	char			*north_text;
	char			*south_text;
	char			*west_text;
	char			*east_text;
	char			*sprite_text;
	int				movingforward;
	int				movingback;
	int				movingright;
	int				movingleft;
	int				straferight;
	int				strafeleft;
	char			direction;
	int				mapwidth;
	int				mapheight;
}					t_globals;

typedef struct		s_raycaster
{
	void			*mlx_ptr;
	void			*mlx_window;
	void			*img_ptr;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				line_height;
	double			player_pos_x;
	double			player_pos_y;
	double			player_dir_x;
	double			player_dir_y;
	double			player_plane_x;
	double			player_plane_y;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	int				side;
	int				draw_start;
	int				draw_end;
	double			perp_wall_dist;
	t_texture		text;
	t_texture		textsouth;
	t_texture		texteast;
	t_texture		textwest;
	t_sprite		sprite;
	t_globals		globals;
}					t_raycaster;

typedef struct		s_bmpheader
{
	uint16_t		type;
	uint32_t		size;
	uint16_t		reserved1;
	uint16_t		reserved2;
	uint32_t		offset;
	uint32_t		dib_header_size;
	int32_t			width_px;
	int32_t			height_px;
	uint16_t		num_planes;
	uint16_t		bits_per_pixel;
	uint32_t		compression;
	uint32_t		image_size_bytes;
	int32_t			x_resolution_ppm;
	int32_t			y_resolution_ppm;
	uint32_t		num_colors;
	uint32_t		important_colors;
}					t_bmpheader;

typedef struct		s_bmpcolor
{
	int				r;
	int				g;
	int				b;
	unsigned int	pixel;
}					t_bmpcolor;

typedef struct		s_bmpimage
{
	t_bmpheader		header;
	unsigned char	*data;
}					t_bmpimage;

unsigned int		g_color;
int					**g_worldmap;
int					g_num_sprite;
double				*g_z_buffer;
t_sprite_list		*g_sprite_list;

int					get_resolution(char *file, t_raycaster *rc);
int					get_path_north(char *file, t_raycaster *rc);
int					get_path_south(char *file, t_raycaster *rc);
int					get_path_west(char *file, t_raycaster *rc);
int					get_path_east(char *file, t_raycaster *rc);
int					get_path_sprite(char *file, t_raycaster *rc);
int					check_valid(char **file, t_raycaster *rc);
int					get_floor_color(char *file, t_raycaster *rc);
int					get_ceiling_color(char *file, t_raycaster *rc);

void				populate_map(char **file, t_raycaster *rc);
int					check_map(char **file, t_raycaster *rc);
int					freearr(void);
int					freefile(void);
int					malloc_map(t_raycaster *rc);
int					populate_sprite(char **file);
void				assign_paths(char *file, t_raycaster *rc);

void				gnl(char *line, int fd, t_raycaster *rc);
int					get_file(char *argv, t_raycaster *rc);

void				get_texture_img(t_raycaster *rc);
void				calculatetext(t_raycaster *rc);
void				calculatetextsouth(t_raycaster *rc);
void				calculatetexteast(t_raycaster *rc);
void				calculatetextwest(t_raycaster *rc);

unsigned int		ft_put_text(t_raycaster *rc, unsigned int color, int y);
unsigned int		ft_put_text_south(t_raycaster *rc, unsigned int color,
										int y);
unsigned int		ft_put_text_east(t_raycaster *rc, unsigned int color,
										int y);
unsigned int		ft_put_text_west(t_raycaster *rc, unsigned int color,
										int y);

void				change_dir(t_raycaster *rc);
int					init(t_raycaster *rc);
int					bmp_init(t_raycaster *rc);
int					error_check(char **args, int argc, t_raycaster *rc);
int					ft_exit_prgm(void);

void				initial_calc(t_raycaster *rc, int x);
void				init_calc_exten(t_raycaster *rc);
void				perform_dda(t_raycaster *rc);
void				calc_wall_height(t_raycaster *rc);

int					handle_events(int keycode, t_raycaster *rc);
int					handle_release(int keycode, t_raycaster *rc);
int					handle_moving(t_raycaster *rc);

unsigned int		select_wall_color(int map_x, int map_y);
unsigned int		apply_night_effect(unsigned int color, double distance);
unsigned int		convert_fc_color(int r, int g, int b);

void				ft_put_pixel(t_raycaster *rc, unsigned int color,
									int y, int x);
void				draw_vert_line(t_raycaster *rc, int x);
int					render_frame(t_raycaster *rc);

void				sprite_cast(t_raycaster *rc);
void				comb_sort_ex(int *order, double *dist,
									t_sort *sort);
void				comb_sort(int *order, double *dist, int amount);

void				bmp_creator(t_raycaster *rc);

#endif
