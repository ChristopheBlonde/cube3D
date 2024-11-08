/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <cblonde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:26:30 by cblonde           #+#    #+#             */
/*   Updated: 2024/11/08 12:19:47 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define MOUSE_SPEED 0.0015

int		handle_input(t_data *data);
void	handle_keys_anim(t_data *data);
void	handle_player_visibility(t_data *data);
int		handle_keyrelease_anim(int keysym, t_data *data);
void	handle_minimap_changed(t_data *data);

#endif
