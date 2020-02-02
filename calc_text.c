/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_text.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/15 17:30:09 by tuperera       #+#    #+#                */
/*   Updated: 2020/01/19 14:57:53 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			get_texture_img(t_raycaster *rc)
{
	rc->text.img_ptr = mlx_png_file_to_image(rc->mlx_ptr, g_north_text,
					&(rc->text.width), &(rc->text.height));
	rc->text.addr = mlx_get_data_addr(rc->text.img_ptr,
	&(rc->text.bits_per_pixel), &(rc->text.line_length), &(rc->text.endian));
	rc->textsouth.img_ptr = mlx_png_file_to_image(rc->mlx_ptr,
				g_south_text, &(rc->textsouth.width), &(rc->textsouth.height));
	rc->textsouth.addr = mlx_get_data_addr(rc->textsouth.img_ptr,
	&(rc->textsouth.bits_per_pixel), &(rc->textsouth.line_length),
	&(rc->text.endian));
	rc->texteast.img_ptr = mlx_png_file_to_image(rc->mlx_ptr,
				g_east_text, &(rc->texteast.width), &(rc->texteast.height));
	rc->texteast.addr = mlx_get_data_addr(rc->texteast.img_ptr,
		&(rc->texteast.bits_per_pixel), &(rc->texteast.line_length),
		&(rc->texteast.endian));
	rc->textwest.img_ptr = mlx_png_file_to_image(rc->mlx_ptr, g_west_text,
						&(rc->textwest.width), &(rc->textwest.height));
	rc->textwest.addr = mlx_get_data_addr(rc->textwest.img_ptr,
			&(rc->textwest.bits_per_pixel), &(rc->textwest.line_length),
			&(rc->textwest.endian));
	rc->sprite.img_ptr = mlx_png_file_to_image(rc->mlx_ptr, g_sprite_text,
			&(rc->sprite.width), &(rc->sprite.height));
	rc->sprite.addr = mlx_get_data_addr(rc->sprite.img_ptr,
		&(rc->sprite.bits_per_pixel), &(rc->sprite.line_length),
		&(rc->sprite.endian));
}

void			calculatetext(t_raycaster *rc)
{
	if (rc->side == 0)
		rc->text.wall_x = rc->player_pos_y +
			rc->perp_wall_dist * rc->ray_dir_y;
	else
		rc->text.wall_x = rc->player_pos_x +
			rc->perp_wall_dist * rc->ray_dir_x;
	rc->text.wall_x -= floor((rc->text.wall_x));
	rc->text.text_x = (int)(rc->text.wall_x * (double)(rc->text.width));
	if (rc->side == 0 && rc->ray_dir_x > 0)
		rc->text.text_x = rc->text.width - rc->text.text_x - 1;
	if (rc->side == 1 && rc->ray_dir_y < 0)
		rc->text.text_x = rc->text.width - rc->text.text_x - 1;
}

void			calculatetextsouth(t_raycaster *rc)
{
	if (rc->side == 0)
		rc->textsouth.wall_x = rc->player_pos_y +
			rc->perp_wall_dist * rc->ray_dir_y;
	else
		rc->textsouth.wall_x = rc->player_pos_x +
			rc->perp_wall_dist * rc->ray_dir_x;
	rc->textsouth.wall_x -= floor((rc->textsouth.wall_x));
	rc->textsouth.text_x = (int)(rc->textsouth.wall_x *
							(double)(rc->textsouth.width));
	if (rc->side == 0 && rc->ray_dir_x > 0)
		rc->textsouth.text_x = rc->textsouth.width - rc->textsouth.text_x - 1;
	if (rc->side == 1 && rc->ray_dir_y < 0)
		rc->textsouth.text_x = rc->textsouth.width - rc->textsouth.text_x - 1;
}

void			calculatetexteast(t_raycaster *rc)
{
	if (rc->side == 0)
		rc->texteast.wall_x = rc->player_pos_y +
			rc->perp_wall_dist * rc->ray_dir_y;
	else
		rc->texteast.wall_x = rc->player_pos_x +
			rc->perp_wall_dist * rc->ray_dir_x;
	rc->texteast.wall_x -= floor((rc->texteast.wall_x));
	rc->texteast.text_x = (int)(rc->texteast.wall_x *
							(double)(rc->texteast.width));
	if (rc->side == 0 && rc->ray_dir_x > 0)
		rc->texteast.text_x = rc->texteast.width - rc->texteast.text_x - 1;
	if (rc->side == 1 && rc->ray_dir_y < 0)
		rc->texteast.text_x = rc->texteast.width - rc->texteast.text_x - 1;
}

void			calculatetextwest(t_raycaster *rc)
{
	if (rc->side == 0)
		rc->textwest.wall_x = rc->player_pos_y +
			rc->perp_wall_dist * rc->ray_dir_y;
	else
		rc->textwest.wall_x = rc->player_pos_x +
			rc->perp_wall_dist * rc->ray_dir_x;
	rc->textwest.wall_x -= floor((rc->textwest.wall_x));
	rc->textwest.text_x = (int)(rc->textwest.wall_x *
							(double)(rc->textwest.width));
	if (rc->side == 0 && rc->ray_dir_x > 0)
		rc->textwest.text_x = rc->textwest.width - rc->textwest.text_x - 1;
	if (rc->side == 1 && rc->ray_dir_y < 0)
		rc->textwest.text_x = rc->textwest.width - rc->textwest.text_x - 1;
}
