/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_ex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 12:00:54 by tuperera       #+#    #+#                */
/*   Updated: 2020/01/27 16:37:41 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_put_text(t_raycaster *rc, unsigned int color, int y)
{
	int d;
	int pos;

	d = (256 * y) - (128 * g_win_y) + (128 * rc->line_height);
	rc->text.text_y = ((d * rc->text.height) / rc->line_height) / 256;
	if (rc->text.text_y > 63)
		rc->text.text_y = 63;
	pos = ((rc->text.text_y * rc->text.line_length) +
				(rc->text.text_x * (rc->text.bits_per_pixel / 8)));
	color = *((unsigned int *)(rc->text.addr + pos));
	if (rc->side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}

unsigned int	ft_put_text_south(t_raycaster *rc, unsigned int color, int y)
{
	int d;
	int pos;

	d = (256 * y) - (128 * g_win_y) + (128 * rc->line_height);
	rc->textsouth.text_y = ((d * rc->textsouth.height) / rc->line_height) / 256;
	if (rc->textsouth.text_y > 63)
		rc->textsouth.text_y = 63;
	pos = ((rc->textsouth.text_y * rc->textsouth.line_length) +
				(rc->textsouth.text_x * (rc->textsouth.bits_per_pixel / 8)));
	color = *((unsigned int *)(rc->textsouth.addr + pos));
	if (rc->side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}

unsigned int	ft_put_text_east(t_raycaster *rc, unsigned int color, int y)
{
	int d;
	int pos;

	d = (256 * y) - (128 * g_win_y) + (128 * rc->line_height);
	rc->texteast.text_y = ((d * rc->texteast.height) / rc->line_height) / 256;
	if (rc->texteast.text_y > 63)
		rc->texteast.text_y = 63;
	pos = ((rc->texteast.text_y * rc->texteast.line_length) +
				(rc->texteast.text_x * (rc->texteast.bits_per_pixel / 8)));
	color = *((unsigned int *)(rc->texteast.addr + pos));
	if (rc->side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}

unsigned int	ft_put_text_west(t_raycaster *rc, unsigned int color, int y)
{
	int d;
	int pos;

	d = (256 * y) - (128 * g_win_y) + (128 * rc->line_height);
	rc->textwest.text_y = ((d * rc->textwest.height) / rc->line_height) / 256;
	if (rc->textwest.text_y > 63)
		rc->textwest.text_y = 63;
	pos = ((rc->textwest.text_y * rc->textwest.line_length) +
				(rc->textwest.text_x * (rc->textwest.bits_per_pixel / 8)));
	color = *((unsigned int *)(rc->textwest.addr + pos));
	if (rc->side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}
