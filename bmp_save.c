/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp_save.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 13:56:53 by tuperera       #+#    #+#                */
/*   Updated: 2020/01/23 13:52:44 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				render_img(t_raycaster *rc)
{
	int x;

	x = 0;
	g_z_buffer = (double *)malloc(sizeof(double) * g_win_x);
	rc->img_ptr = mlx_new_image(rc->mlx_ptr, g_win_x, g_win_y);
	rc->addr = mlx_get_data_addr(rc->img_ptr, &(rc->bits_per_pixel),
								&(rc->line_length), &(rc->endian));
	get_texture_img(rc);
	while (x < g_win_x)
	{
		initial_calc(rc, x);
		perform_dda(rc);
		calc_wall_height(rc);
		calculatetext(rc);
		calculatetextsouth(rc);
		calculatetexteast(rc);
		calculatetextwest(rc);
		g_z_buffer[x] = rc->perp_wall_dist;
		draw_vert_line(rc, x);
		x++;
	}
	sprite_cast(rc);
	return (0);
}

void			writer(t_bmpheader bmp_head, int fd)
{
	write(fd, &bmp_head.type, 2);
	write(fd, &bmp_head.size, 4);
	write(fd, &bmp_head.reserved1, 2);
	write(fd, &bmp_head.reserved2, 2);
	write(fd, &bmp_head.offset, 4);
	write(fd, &bmp_head.dib_header_size, 4);
	write(fd, &bmp_head.width_px, 4);
	write(fd, &bmp_head.height_px, 4);
	write(fd, &bmp_head.num_planes, 2);
	write(fd, &bmp_head.bits_per_pixel, 2);
	write(fd, &bmp_head.compression, 4);
	write(fd, &bmp_head.image_size_bytes, 4);
	write(fd, &bmp_head.x_resolution_ppm, 4);
	write(fd, &bmp_head.y_resolution_ppm, 4);
	write(fd, &bmp_head.num_colors, 4);
	write(fd, &bmp_head.important_colors, 4);
}

void			pop_bmp_head(t_bmpheader *bmp_head)
{
	bmp_head->type = 0x4d42;
	bmp_head->reserved1 = 0;
	bmp_head->reserved2 = 0;
	bmp_head->offset = 54;
	bmp_head->dib_header_size = 40;
	bmp_head->width_px = g_win_x;
	bmp_head->height_px = g_win_y;
	bmp_head->size = 54 + (bmp_head->height_px * bmp_head->width_px * 3);
	bmp_head->num_planes = 1;
	bmp_head->bits_per_pixel = 24;
	bmp_head->compression = 0;
	bmp_head->image_size_bytes = bmp_head->height_px * bmp_head->width_px * 3;
	bmp_head->x_resolution_ppm = 24;
	bmp_head->y_resolution_ppm = 24;
	bmp_head->num_colors = 0;
	bmp_head->important_colors = 0;
}

void			image_pop(t_raycaster *rc, t_bmpimage bmp_img,
						t_bmpcolor bcolor)
{
	int			i;
	int			j;
	int			pos;
	int			k;

	k = 0;
	i = g_win_y - 1;
	while (i >= 0)
	{
		j = 0;
		while (j != g_win_x)
		{
			pos = ((i * rc->line_length) + (j * (rc->bits_per_pixel / 8)));
			bcolor.pixel = *((unsigned int *)(rc->addr + pos));
			bcolor.r = (bcolor.pixel & 0x00FF0000) >> 16;
			bcolor.g = (bcolor.pixel & 0x0000FF00) >> 8;
			bcolor.b = (bcolor.pixel & 0x000000FF);
			*((unsigned char *)(bmp_img.data) + k) = bcolor.b;
			*((unsigned char *)(bmp_img.data) + k + 1) = bcolor.g;
			*((unsigned char *)(bmp_img.data) + k + 2) = bcolor.r;
			j++;
			k += 3;
		}
		i--;
	}
}

void			bmp_creator(t_raycaster *rc)
{
	t_bmpheader bmp_head;
	t_bmpimage	bmp_img;
	t_bmpcolor	bcolor;
	int			fd;

	fd = open("./img.bmp", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	bcolor.pixel = 0;
	bmp_img.data = malloc(sizeof(unsigned char) * bmp_head.image_size_bytes);
	pop_bmp_head(&bmp_head);
	render_img(rc);
	image_pop(rc, bmp_img, bcolor);
	writer(bmp_head, fd);
	write(fd, bmp_img.data, bmp_head.image_size_bytes);
	close(fd);
}
