/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:19:47 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/26 23:40:09 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*permite al jugador moverse en la dirección deseada, verificando que no 
choque con paredes u obstáculos. Primero calcula las coordenadas futuras 
(next_x y next_y), comprueba si el jugador puede moverse allí sin colisión, 
y si es posible, actualiza la posición del jugador.*/
/* Actualiza la posición del jugador en función de un vector de dirección (fx, fy) y
 una velocidad de movimiento (move_speed).*/
 
void	move(t_game *game, float dir_x, float dir_y, float move_speed)
{
    float next_move_x;
    float next_move_y;

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


void rotate(t_game *game, float angle)
{
    float dir;
    float plane;

    // Rotates the player.dir using the formula for turning
    dir = game->player.dir.x;
    game->player.dir.x = game->player.dir.x * cos(angle) - game->player.dir.y * sin(angle);
    game->player.dir.y = dir * sin(angle) + game->player.dir.y * cos(angle);

    // Rotates the camera plane using the formula for turning
    plane = game->player.plane.x;
    game->player.plane.x = game->player.plane.x * cos(angle) - game->player.plane.y * sin(angle);
    game->player.plane.y = plane * sin(angle) + game->player.plane.y * cos(angle);

	game->is_moving = true;
}

/*Si se presiona la tecla W, el jugador se mueve hacia adelante en la 
dirección actual a donde mira. move toma las coordenadas de la dirección del jugador 
(scene->player.dir.x y scene->player.dir.y) y SPEED ajusta la velocidad de movimiento.*/

/*Si se presiona la tecla S, el jugador se mueve hacia atrás. 
Aquí, se invierte la dirección multiplicando por -1 los componentes
 x e y de la dirección del jugador.*/

// If we add much more functionality, we will need to split the event listener down into
// several parts, one for each group of keys, e.g. AWSD + up + down
// move 

void	try_to_move_forward(t_game *game)
{
	if(mlx_is_key_down(game->mlx, MLX_KEY_W) || mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move(game, game->player.dir.x, game->player.dir.y, game->player.speed);//moves towards palyer.dir
}

void	try_to_move_backward(t_game *game)
{
	if(mlx_is_key_down(game->mlx, MLX_KEY_S) || mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move(game, -game->player.dir.x, -game->player.dir.y, game->player.speed);
}

void	try_to_strafe(t_game *game)
{
	if(mlx_is_key_down(game->mlx, MLX_KEY_A))
		move(game, game->player.dir.y, -game->player.dir.x, game->player.speed);
	if(mlx_is_key_down(game->mlx, MLX_KEY_D))
		move(game, -game->player.dir.y, game->player.dir.x, game->player.speed);
}

void	try_to_rotate(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate(game, -game->player.rotation_speed * 80);//angulo de giro para el player y el plane
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate(game, game->player.rotation_speed * 80);//angulo de giro para el player y el plane
}

void	try_to_teleport(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_Y))
		teleport_to_original_position(game);
}

void	try_to_run(t_game *game)
{
	if(mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT) && !game->player.is_running)
		sprint_on(game);
	if(!mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT) && game->player.is_running)
		sprint_off(game);
}

void	process_movement(t_game *game)
{
	try_to_move_forward(game);
	try_to_move_backward(game);
	try_to_strafe(game);
	try_to_rotate(game);
	try_to_run(game);
	try_to_teleport(game);
}

void	event_listener(t_game *game)
{
	if(mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		error_mlx(game);
	process_movement(game);
	// if(mlx_is_key_down(game->mlx, MLX_KEY_W) || mlx_is_key_down(game->mlx, MLX_KEY_UP))
	// 	move(game, game->player.dir.x, game->player.dir.y, game->player.speed);//moves towards palyer.dir
	// if(mlx_is_key_down(game->mlx, MLX_KEY_S) || mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	// 	move(game, -game->player.dir.x, -game->player.dir.y, game->player.speed);
	// if(mlx_is_key_down(game->mlx, MLX_KEY_A))
	// 	move(game, game->player.dir.y, -game->player.dir.x, game->player.speed);
	// if(mlx_is_key_down(game->mlx, MLX_KEY_D))
	// 	move(game, -game->player.dir.y, game->player.dir.x, game->player.speed);
	// if (mlx_is_key_down(game->mlx, MLX_KEY_Y))
	// 	teleport_to_original_position(game);
	// if(mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT) && !game->player.is_running)
	// 	sprint_on(game);
	// if(!mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT) && game->player.is_running)
	// 	sprint_off(game);
}

void	sprint_on(t_game *game)
{
	game->player.speed *= 2;
	game->player.rotation_speed += ROTATION_SPEED / 2;
	game->player.is_running = true;
}

void	sprint_off(t_game *game)
{
	game->player.speed *= 0.5;
	game->player.rotation_speed -= ROTATION_SPEED / 2;
	game->player.is_running = false;
}

void	teleport_to_original_position (t_game *game)
{
	reset_player_direction(game);
	game->player.pos.x = game->player.orig_pos.x;
	game->player.pos.y = game->player.orig_pos.y;
	game->is_moving = true;
}