





int	main(int ac, char **av)
{
	t_game		*game;

	if (ac != 2)
		return (print_error(ERR_ARG), 1);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (print_error(ERR_MEMORY), 1);
	ft_memset(game, 0, sizeof(t_game));
	
	if (parse_cub(game, av[1]))
		return (game_free(game), 1);
		
	print_elements(game);//TEMPORAL
	
	if (start_game(game))
	
	game_free(game);//this free + 'exit' must be called when 'esc' or 'close window' are pressed
//	printf("EXIT PROPERLY \U0001F44D\n\n");//DEBUG
	return (0);//probably the program never is gonna finish here
}

void error(void)
{
	ft_printf("MLX error code: %d\n", mlx_errno);
	ft_printf("%s", mlx_strerror(mlx_errno));//prints the error string that describes the error code
	exit(EXIT_FAILURE);//attention, first must be freed all mallocs from parsing part
}
int	start_game(t_game *game)
{
	mlx_t *mlx;
	
	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	if (!mlx)
		return (error(), 1);
	if (init_game(mlx, game))
		 return (error(), 1);
	
//	printf("start_game\n");//DEBUG
	
//It is executed each frame, updated accordingly every keypress/movement 
	mlx_loop_hook(mlx, loop_updater, game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

void reset_player_direction(t_game *game, char orientation)
{
    if (orientation == 'N') {
        game->player.dir.x = 0;
        game->player.dir.y = -1;
    } else if (orientation == 'S') {
        game->player.dir.x = 0;
        game->player.dir.y = 1;
    } else if (orientation == 'E') {
        game->player.dir.x = 1;
        game->player.dir.y = 0;
    } else if (orientation == 'W') {
        game->player.dir.x = -1;
        game->player.dir.y = 0;
    }
}

int	init_game(mlx_t *mlx, t_game *game)
{
	game->mlx = mlx;
	game->is_moving = 1;//it means that the images must be redrawn 
//	game->player.dir.x = 1;//player looks to EAST (1, 0) as a starting value
	reset_player_direction(game, game->player.orientation);
	
/*-----BACKGROUND img declaration, painting and putting into the mlx window-------*/	
	game->img_back = mlx_new_image(mlx, 1000, 500);
	if (!game->img_back)
		return (error(), 1);
	draw_background(game);//pot anar aqui o 2 lineas mes avall
	if (mlx_image_to_window(game->mlx, game->img_back, 0, 0) < 0)
		return (error(), 1);

		
/*-----RAYCASTING img declaration, paint and put into the mlx window-------*/
//	game->img_ray = mlx_new_image(mlx, 1000, 500);
//	if (!game->img_ray)
//		return (error(), 1);
//	execute_raycasting(game);/*---RAYCASTING CODE IS PENDING------*/


/*-----MINIMAP img declaration, painting and putting into the mlx window-------*/
	game->img_mmap = mlx_new_image(mlx, (WIDTH / 5), (HEIGHT / 5));
	if (!game->img_mmap)
		return (error(), 1);
	draw_minimap(game);
	mlx_image_to_window(game->mlx, game->img_mmap, 0, 0);

//	printf("init_game\n");//DEBUG
	return (0);
}

/* Draws a tile on the mini_map image at x, y position.*/
void draw_minimap_tile(mlx_image_t *img_mmap, uint32_t x, uint32_t y,
						 uint32_t color)
{
    uint32_t	i;
    uint32_t	j;

    i = 0;
    while (i < TILE_SIZE)
    {
        j = 0;
        while (j < TILE_SIZE)
        {
            //Draws only the pixels located inside the mini_map limits
            if ((uint32_t)x + i >= 0 && (uint32_t)x + i < img_mmap->width \
			&& (uint32_t)y + j >= 0 && (uint32_t)y + j < img_mmap->height)
                mlx_put_pixel(img_mmap, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void	draw_minimap_player(mlx_image_t *img_mmap, uint32_t x, uint32_t y,
							 uint32_t color)
{
 	int i;
    int j;

    i = 0;
    while (i < 4)//player will have 4 pix high
    {
        j = 0;
        while (j < 4)//player will have 4 pix wide
        {
            // Solo dibuja los píxeles que están dentro de los límites del mini_map
//            if ((uint32_t)x + i >= 0 && (uint32_t)x + i < img_mmap->width \
//			&& (uint32_t)y + j >= 0 && (uint32_t)y + j < img_mmap->height)
                mlx_put_pixel(img_mmap, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void	draw_minimap_frame(mlx_image_t *img_mmap, uint32_t x, uint32_t y,
							 uint32_t color)
{
//	while (y < 100) VOLVER A UN TAMANYO FIJO SI NO ES EFICIENTE
	while (y < (HEIGHT / 5))
	{
		x = 0;
		while (x < (WIDTH / 5))
		{
			if (y == 0 || y == ((HEIGHT / 5) - 1))
			{
				 mlx_put_pixel(img_mmap, x, y, color);
				 x++;
			}
			else
			{
				mlx_put_pixel(img_mmap, 0, y, color);
				mlx_put_pixel(img_mmap, ((WIDTH / 5) - 1), y, color);
				x = 300;
			}	
		}
		y++;
	}
}
/*Draws the visible part of the map into the minimap*/
void	draw_minimap_only_visible_tiles(t_game *game)
{
    game->mmap.row = game->mmap.start_row;
    while (game->mmap.row <= game->mmap.end_row \
	&& game->map_arr[game->mmap.row] != NULL)
    {
        game->mmap.col = game->mmap.start_col;
        while (game->mmap.col <= game->mmap.end_col \
		&& game->map_arr[game->mmap.row][game->mmap.col] != '\0')
        {
            // Calcular la posición del tile en la imagen del minimapa
            game->mmap.x \
			= (game->mmap.col * TILE_SIZE) - game->mmap.map_offset_x;
            game->mmap.y \
			= (game->mmap.row * TILE_SIZE) - game->mmap.map_offset_y;
            // Dibujar el tile solo si está dentro de los límites del minimapa
        	if (game->mmap.x >= 0 && game->mmap.x < game->img_mmap->width \
			&& game->mmap.y >= 0 && game->mmap.y < game->img_mmap->height)
			{
            	if (game->map_arr[game->mmap.row][game->mmap.col] == '1' \
				|| game->map_arr[game->mmap.row][game->mmap.col] == ' ')
					draw_minimap_tile(game->img_mmap, game->mmap.x,
					 game->mmap.y, game->parser.elem.c_opposite);
            }
            game->mmap.col++;
        }
        game->mmap.row++;
    }
}

void draw_minimap(t_game *game)
{
    // Calcular la posición del jugador en el minimapa (centro)
    game->mmap.pl_screen_x = game->img_mmap->width >> 1;
    game->mmap.pl_screen_y = game->img_mmap->height >> 1;

    // Calcular el desplazamiento del mapa para centrar el minimapa en el jugador
	//ESTE ES EL PARAM QUE HACE MOVER EL MAP DENTRO DEL MINIMAP
//   game->mmap.map_offset_x = (game->pl_orig[0] * TILE_SIZE) -
//								 game->mmap.pl_screen_x;
	game->mmap.map_offset_x = (game->player.pos.x * TILE_SIZE) -\
								 game->mmap.pl_screen_x;							 

//    game->mmap.map_offset_y = (game->pl_orig[1] * TILE_SIZE) -
//								 game->mmap.pl_screen_y;
	game->mmap.map_offset_y = (game->player.pos.y * TILE_SIZE) -\
								 game->mmap.pl_screen_y;

    // Calcular los límites de las filas y columnas que deben dibujarse
	// Calcular columna de inicio
	if (game->mmap.map_offset_x < 0)
	    game->mmap.start_col = 0;  // Si el offset es negativo, comenzamos desde la primera columna
	else
	    game->mmap.start_col = game->mmap.map_offset_x / TILE_SIZE;  // Si es positivo, calculamos la columna correspondiente
	// Calcular fila de inicio
	if (game->mmap.map_offset_y < 0)
	    game->mmap.start_row = 0;  // Si el offset es negativo, comenzamos desde la primera fila
	else
	    game->mmap.start_row = game->mmap.map_offset_y / TILE_SIZE;  // Si es positivo, calculamos la fila correspondiente
	// Calcular columna de final
    game->mmap.end_col = ((game->mmap.map_offset_x +\
						 game->img_mmap->width) / TILE_SIZE);
	// Calcular fila de final
    game->mmap.end_row = ((game->mmap.map_offset_y +\
						 game->img_mmap->height) / TILE_SIZE);

	print_minimap_vars(game);//DEBUG

    // Dibujar los tiles visibles en el minimapa
	draw_minimap_only_visible_tiles(game);
	
    // Dibujar la posición del jugador centrada en el minimapa
    draw_minimap_player(game->img_mmap, game->mmap.pl_screen_x + 3,
						 game->mmap.pl_screen_y + 4, 0x000000FF);
    
    // Dibujar el marco del minimapa
   draw_minimap_frame(game->img_mmap, 0, 0, 0x000000FF);
}

void clear_image(mlx_image_t *img, uint32_t color)
{
	uint32_t	y;
	uint32_t	x;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

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

//---------------------MINIMAP----------------------------
	if (game->is_moving)//si ha habido un movimiento en el juego
	{
		clear_image(game->img_mmap, 0x00000000);
		draw_minimap(game);
		mlx_image_to_window(game->mlx, game->img_mmap, 0, 0);
		game->is_moving = false;
	}
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