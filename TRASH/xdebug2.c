/*Contains all functions that must be repeated/updated every mlx_loop_hook */
void	loop_updater(void *param)
{
	t_game *game = (t_game *)param;
	
	event_listener(game);
	
	
//--------------------BACKGROUND--------------------------
//Esta imagen no deberia actualizarse aqui porque siempre es igual
//	mlx_image_to_window(game->mlx, game->img_back, 0, 0);
//	va en la tercera capa

//	if (game->is_moving)//si ha habido un movimiento en el juego
//	{
//--------------------RAYCASTING--------------------------
//		raycast(); Creates and manages all raycasting. It is updated every loop/frame
//		mlx_image_to_window(game->mlx, game->img_ray, 0, 0);
//		va en segunda capa
//	}

//	if (game->is_moving)//si ha habido un movimiento en el juego
//	{
//---------------------MINIMAP----------------------------
//		minimap(game);
//		update_minimap();//SOLO SE REDIBUJA llamando a draw_minimap SI EL JUGADOR SE HA MOVIDO
//		probablemente debere poner un contador de pulsaciones para determinar si hubo movimiento???
		mlx_image_to_window(game->mlx, game->img_mmap, 0, 0);
//		va en primera capa
		game->is_moving = false;
//	}

	
//	}
//	printf("%i\n", frame_cnt);
	
}void	move(t_game *game, double dir_x, double dir_y, double move_speed)
{
	int	next_move_x;//coor de hacia donde se ha de mover
	int	next_move_y;

	next_move_x = (int)(game->player.pos.x + dir_x * (move_speed + 0.01));
	next_move_y = (int)(game->player.pos.y + dir_y * (move_speed + 0.01));
//anyadimos 0.01 a move_speed para evitar errores de redondeo

	if (game->map_arr[next_move_y][(int)game->player.pos.x] == '0')
		game->player.pos.y += dir_y * move_speed;

	if (game->map_arr[(int)game->player.pos.y][next_move_x] == '0')
		game->player.pos.x += dir_x * move_speed;

	game->is_moving = true;//marca la flag porque te has movido
	
}
/*
void	rotate(t_game *game, )
{
	
}*/


void	event_listener(t_game *game)
{
	if(mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);//+ salir limpiamente del programa
/*
Si se presiona la tecla UP o W, el jugador se mueve hacia adelante en la 
dirección actual a donde mira. move toma las coordenadas de la dirección del jugador 
(scene->player.dir.x y scene->player.dir.y) y SPEED para ajustar la 
velocidad de movimiento.*/

	if(mlx_is_key_down(game->mlx, MLX_KEY_W))
		move(game, game->player.dir.x, game->player.dir.y, SPEED);//mueve hacia palyer dir

/*Si se presiona la tecla DOWN o S, el jugador se mueve hacia atrás. 
Aquí, se invierte la dirección multiplicando por -1 los componentes 
x e y de la dirección del jugador.*/
	if(mlx_is_key_down(game->mlx, MLX_KEY_S))
		move(game, -game->player.dir.x, -game->player.dir.y, SPEED);

	if(mlx_is_key_down(game->mlx, MLX_KEY_A))
		move(game, game->player.dir.y, -game->player.dir.x, SPEED);
		
	if(mlx_is_key_down(game->mlx, MLX_KEY_D))
		move(game, -game->player.dir.y, game->player.dir.x, SPEED);
		
//	if(mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
//		rotate();
//	if(mlx_is_key_down(mlx, MLX_KEY_RIGHT))
//		rotate();
}

