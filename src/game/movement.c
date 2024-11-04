/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:19:47 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/04 18:48:10 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*permite al jugador moverse en la dirección deseada, verificando que no 
choque con paredes u obstáculos. Primero calcula las coordenadas futuras 
(next_x y next_y), comprueba si el jugador puede moverse allí sin colisión, 
y si es posible, actualiza la posición del jugador.*/
/* Actualiza la posición del jugador en función de un vector de dirección (fx, fy) y
 una velocidad de movimiento (move_speed).*/
 
void	move(t_game *game, double dir_x, double dir_y, double move_speed)
{
    double next_move_x;
    double next_move_y;

    next_move_x = game->player.pos.x + dir_x * (move_speed + 0.01);
    next_move_y = game->player.pos.y + dir_y * (move_speed + 0.01);

    if (game->map_arr[(int)next_move_y][(int)game->player.pos.x] == '0' \
		|| game->map_arr[(int)next_move_y][(int)game->player.pos.x] == 'N' \
		|| game->map_arr[(int)next_move_y][(int)game->player.pos.x] == 'S' \
		|| game->map_arr[(int)next_move_y][(int)game->player.pos.x] == 'E' \
		|| game->map_arr[(int)next_move_y][(int)game->player.pos.x] == 'W')
        game->player.pos.y += dir_y * move_speed;
    if (game->map_arr[(int)game->player.pos.y][(int)next_move_x] == '0' \
		|| game->map_arr[(int)game->player.pos.y][(int)next_move_x] == 'N' \
		|| game->map_arr[(int)game->player.pos.y][(int)next_move_x] == 'S' \
		|| game->map_arr[(int)game->player.pos.y][(int)next_move_x] == 'E' \
		|| game->map_arr[(int)game->player.pos.y][(int)next_move_x] == 'W')
        game->player.pos.x += dir_x * move_speed;
    game->is_moving = true;
}


void rotate(t_game *game, double angle)
{
    float dir;
    float plane;

    // Rotar la dirección del jugador (aplicando la formula de giro)
    dir = game->player.dir.x;
    game->player.dir.x = game->player.dir.x * cos(angle) - game->player.dir.y * sin(angle);
    game->player.dir.y = dir * sin(angle) + game->player.dir.y * cos(angle);

    // Rotar el plano de la cámara (aplicando la formula de giro)
    plane = game->player.plane.x;
    game->player.plane.x = game->player.plane.x * cos(angle) - game->player.plane.y * sin(angle);
    game->player.plane.y = plane * sin(angle) + game->player.plane.y * cos(angle);

	game->is_moving = true;
}



void	event_listener(t_game *game)
{
	if(mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);//+ salir limpiamente del programa
/*
Si se presiona la tecla W, el jugador se mueve hacia adelante en la 
dirección actual a donde mira. move toma las coordenadas de la dirección del jugador 
(scene->player.dir.x y scene->player.dir.y) y SPEED ajusta la velocidad de movimiento.*/

	if(mlx_is_key_down(game->mlx, MLX_KEY_W))
		move(game, game->player.dir.x, game->player.dir.y, SPEED);//mueve hacia palyer dir

/*Si se presiona la tecla S, el jugador se mueve hacia atrás. 
Aquí, se invierte la dirección multiplicando por -1 los componentes x e y de la dirección del jugador.*/
	if(mlx_is_key_down(game->mlx, MLX_KEY_S))
		move(game, -game->player.dir.x, -game->player.dir.y, SPEED);// * 0.5 reduce the speed by half.

	if(mlx_is_key_down(game->mlx, MLX_KEY_A))
		move(game, game->player.dir.y, -game->player.dir.x, SPEED);
		
	if(mlx_is_key_down(game->mlx, MLX_KEY_D))
		move(game, -game->player.dir.y, game->player.dir.x, SPEED);

	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate(game, -ROTATION_SPEED * 42);//angulo de giro para el player y el plane
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate(game, ROTATION_SPEED * 42);//angulo de giro para el player y el plane

//	if(mlx_is_key_put_down(game->mlx, MLX_KEY_SHFT)) //TODO FOR ROMAN
//		SPEED *= 2;

//	if(mlx_is_key_put_up(game->mlx, MLX_KEY_SHFT))
//		SPEED *= 0.5;


}
