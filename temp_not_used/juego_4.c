#include "../include/cub3d.h"


void	draw_mini_map_frame(mlx_image_t *img_minimap, int x, int y, uint32_t color)
{
	while (y < 200)
	{
		x = 0;
		while (x < 300)
		{
			if (y == 0 || y == 199)
			{
				 mlx_put_pixel(img_minimap, x, y, color);
				 x++;
			}
			else
			{
				mlx_put_pixel(img_minimap, 0, y, color);
				mlx_put_pixel(img_minimap, 299, y, color);
				x = 300;
			}	
		}
		y++;
	}
}

/* Draws a tile on the mini_map image at x, y position.*/
void draw_tile(mlx_image_t *img_minimap, int x, int y, uint32_t color)
{
    int i;
    int j;

    i = 0;
    while (i < TILE_SIZE)
    {
        j = 0;
        while (j < TILE_SIZE)
        {
            //Draws only the pixels located inside the mini_map limits
            if ((uint32_t)x + i >= 0 && (uint32_t)x + i < img_minimap->width \
			&& (uint32_t)y + j >= 0 && (uint32_t)y + j < img_minimap->height)
                mlx_put_pixel(img_minimap, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void	draw_player_tile(mlx_image_t *img_minimap, int x, int y, uint32_t color)
{
 	int i;
    int j;

    i = 0;
    while (i < 4)//player will be 4 pix high
    {
        j = 0;
        while (j < 4)//player will be 4 pix wide
        {
            // Solo dibuja los píxeles que están dentro de los límites del mini_map
            if ((uint32_t)x + i >= 0 && (uint32_t)x + i < img_minimap->width \
			&& (uint32_t)y + j >= 0 && (uint32_t)y + j < img_minimap->height)//Creo que puedo prescindir de esta condicion??
                mlx_put_pixel(img_minimap, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

/*Draws a small image of the map. The player keeps centered all time and the 
map moves around it. Map color is the opposite to the ceiling color to get a 
better visual effect.*/
void draw_img_minimap(t_game *game)
{
    int x, y;
    int row, col;
    int map_offset_x, map_offset_y; // Para centrar al jugador
    int start_col, end_col, start_row, end_row; // Límites de los tiles visibles
    int player_screen_x, player_screen_y; // Posición del jugador dentro del mini_map

    // Calcular el desplazamiento (offset) para centrar el minimapa en el jugador
    player_screen_x = game->img_minimap->width >> 1; // Jugador en el centro de mini_map (eje X)
    player_screen_y = game->img_minimap->height >> 1; // Jugador en el centro de mini_map (eje Y)
	//Sustituir las divisiones por desplazamientos de bits (/2 = >> 1)

    // Calcular la esquina superior izquierda del minimapa en el mapa global
    map_offset_x = game->p_x  * TILE_SIZE - player_screen_x;
    map_offset_y = game->p_y  * TILE_SIZE - player_screen_y;

    // Calcular los límites de las filas y columnas que deben dibujarse
    start_col = map_offset_x / TILE_SIZE;
    end_col = (map_offset_x + WIDTH) / TILE_SIZE;
    start_row = map_offset_y / TILE_SIZE;
    end_row = (map_offset_y + HEIGHT) / TILE_SIZE;
	
    // Asegurar que los valores no se salgan de los límites del mapa
    if (start_row < 0)
		start_row = 0;
    if (start_col < 0)
		start_col = 0;
    if (end_row >= game->parser.map.h)
		end_row = game->parser.map.h - 1;
    if (end_col >= game->parser.map.w)
		end_col = game->parser.map.w - 1;
	
    // Dibujar los tiles visibles en el minimapa
    row = start_row;
    while (row <= end_row && game->map[row] != NULL)
    {
        col = start_col;
        while (col <= end_col && game->map[row][col] != '\0')
        {
            // Calcular la posición del tile en la imagen del minimapa
            x = (col * TILE_SIZE) - map_offset_x;
            y = (row * TILE_SIZE) - map_offset_y;

            // Si el tile es una pared o un espacio, lo dibuja
            if (game->map[row][col] == '1' || game->map[row][col] == ' ')
//              draw_tile(mini_map, x, y, get_ceiling_opposite_color(parser));
				draw_tile(game->img_minimap, x, y, game->parser.elem.c_opposite);
            col++;
        }
        row++;
    }
    // Dibujar la posición del jugador centrada en el minimapa (>> 1 == / 2)
//    draw_tile(mini_map, player_screen_x - TILE_SIZE / 2, player_screen_y - TILE_SIZE / 2, 0xFFFFFFFF);
	draw_player_tile(game->img_minimap, player_screen_x + 3, player_screen_y + 2, 0xFFFFFFFF);//algo desplazado respecto al mapa, lo centro con +3 y +2

	// Draws a white frame surrounding the mini_map
	draw_mini_map_frame(game->img_minimap, 0, 0, 0xFFFFFFFF);
}

void draw_img_background(t_game *game)
{
    int y;
    int x;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(game->img_backgr, x, y, game->parser.elem.c_color);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(game->img_backgr, x, y, game->parser.elem.f_color);
			x++;
		}
		y++;
	}
}

int	init_game(mlx_t *mlx, t_game *game, t_parser *parser)
{
	game->map = parser->raw_map;
	game->p_x = parser->map.player_x;
	game->p_y = parser->map.player_y;
	game->p_view = parser->map.player_view;
	game->mlx = mlx;
	game->img_backgr = mlx_new_image(mlx, 1000, 500);
	game->img_raycasting = mlx_new_image(mlx, 1000, 500);
	game->img_minimap = mlx_new_image(mlx, 300, 200);
	if (!game->img_backgr || !game->img_raycasting || !game->img_minimap)
		return (error(), 1);
	draw_img_background(game);
	draw_img_minimap(game);
	return (0);
}

/*Contains all functions that must be repeated/updated every mlx loop*/
void	updater(void *param)
{
	t_game *game = (t_game *)param;
	
//	event_listener(); ESTA FUNCION NO SE BIEN DONDE HA DE IR
	
//--------------------BACKGROUND--------------------------
	mlx_image_to_window(game->mlx, game->img_backgr, 0, 0);
//	va en la tercera capa

//--------------------RAYCASTING--------------------------
//	raycast(); Creates and manages all raycasting. It is updated every cicle/frame
	mlx_image_to_window(game->mlx, game->img_raycasting, 0, 0);
// va en segunda capa

//---------------------MINIMAP----------------------------
//	minimap(game);
//	update_minimap();//SOLO SE REDIBUJA llamando a draw_minimap SI EL JUGADOR SE HA MOVIDO
	//probablemente debere poner un contador de pulsaciones para determinar si hubo movimiento???
	mlx_image_to_window(game->mlx, game->img_minimap, 0, 0);
//va en primera capa
	
}

int	start_game(t_game *game, t_parser *parser)
{
	mlx_t *mlx;
	
	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	if (!mlx)
		return (error(), 1);
	if (init_game(mlx, game, parser))
		 return (error(), 1);
	mlx_loop_hook(game->mlx, updater, game);
//		return (error(), 1);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}


int	main(int ac, char **av)
{
	t_parser	parser;
	t_game		game;

	if (ac != 2)
		return (print_error(ERR_ARG), 1);
	init_parser(&parser);
	if (parse_cub(&parser, av[1]))
		return (parser_free(&parser), 1);
	if (start_game(&game, &parser))
	parser_free(&parser);
	return (0);
}