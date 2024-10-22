
typedef struct s_map
{
	int	w;
	int	h;
	int	player_qty;
	int	player_view;
	int	player_x;
	int	player_y;
}		t_map;

/*-------Parsing variables-------*/
typedef struct s_parser
{
	t_cub	*cub;//List containing every line from file.cub
	t_cub	*cub_firstline;
	t_cub	*map_firstline;//points to the first line after the elements
	t_elem	elem;
	t_map	map;//map infos
	char	**raw_map;//map before to be parsed
}			t_parser;


typedef struct s_game//It will be passed to the graphic part of cu3D
{
	t_parser	parser;
	char		**map;//already parsed and formated to rectangular shape
	int			p_x;
	int			p_y;
	char		p_view;
	mlx_t		*mlx;
	mlx_image_t	*game_img;
//	char	*no;
//	char	*so;
//	char	*ea;
//	char 	*we;
	uint32_t	c_col;
	uint32_t	f_col;
	uint32_t	c_col_opposite;
}			t_game


#include  "../include/cub3d.h"

void	draw_mini_map_frame(mlx_image_t *mini_map, int x, int y, uint32_t color)
{
	while (y < 200)
	{
		x = 0;
		while (x < 300)
		{
			if (y == 0 || y == 199)
			{
				 mlx_put_pixel(mini_map, x, y, color);
				 x++;
			}
			else
			{
				mlx_put_pixel(mini_map, 0, y, color);
				mlx_put_pixel(mini_map, 299, y, color);
				x = 300;
			}	
		}
		y++;
	}
}

/* Draws a tile on the mini_map image at x, y position.*/
void draw_tile(mlx_image_t *game_img, int x, int y, uint32_t color)
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
            if ((uint32_t)x + i >= 0 && (uint32_t)x + i < game_img->width \
			&& (uint32_t)y + j >= 0 && (uint32_t)y + j < game_img->height)
                mlx_put_pixel(game_img, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void	draw_player_tile(mlx_image_t *game_img, int x, int y, uint32_t color)
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
            if ((uint32_t)x + i >= 0 && (uint32_t)x + i < game_img->width \
			&& (uint32_t)y + j >= 0 && (uint32_t)y + j < game_img->height)//Creo que puedo prescindir de esta condicion??
                mlx_put_pixel(game_img, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

/*Displays a small image of the map on the upper left corner on the main image.
The player keeps centered all time and the map moves around it. 
Map color is the opposite to the ceiling color to get a better visual effect.*/
int minimap(t_game *game)
{
    int x, y;
    int row, col;
    int map_offset_x, map_offset_y; // Para centrar al jugador
    int start_col, end_col, start_row, end_row; // Límites de los tiles visibles
    int player_screen_x, player_screen_y; // Posición del jugador dentro del mini_map

    // Calcular el desplazamiento (offset) para centrar el minimapa en el jugador
    player_screen_x = game->game_img->width >> 1; // Jugador en el centro de mini_map (eje X)
    player_screen_y = game->game_img->height >> 1; // Jugador en el centro de mini_map (eje Y)
//Sustituido las divisiones por desplazamientos de bits (/2 = >> 1)

    // Calcular la esquina superior izquierda del minimapa en el mapa global
    map_offset_x = game->p_x  * TILE_SIZE - player_screen_x;
    map_offset_y = game->p_y  * TILE_SIZE - player_screen_y;

    // Calcular los límites de las filas y columnas que deben dibujarse
    start_col = map_offset_x / TILE_SIZE;
    end_col = (map_offset_x + game->game_img->width) / TILE_SIZE;
    start_row = map_offset_y / TILE_SIZE;
    end_row = (map_offset_y + game->game_img->height) / TILE_SIZE;
	
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
				draw_tile(game->game_img, x, y, game->c_col_opposite);
            col++;
        }
        row++;
    }
    // Dibujar la posición del jugador centrada en el minimapa (>> 1 == / 2)
	draw_player_tile(game->game_img, player_screen_x + 3, player_screen_y + 2, 0xFFFFFFFF);//algo desplazado respecto al mapa, lo centro con +3 y +2

	// Draws a white frame surrounding the mini_map
	draw_mini_map_frame(game->game_img, 0, 0, 0xFFFFFFFF);
    return (0);
}

/*Contains all functions that must be repeated/updated every mlx loop*/
void	updater(void *param)
{
	t_game *game = (t_game *)param;
//	event_listener();
//	raycast();
	if (minimap(game))
		exit (EXIT_FAILURE);
}

int	init_game(mlx_t *mlx, t_game *game, t_parser *parser)
{
	game->map = parser->raw_map;
	game->p_x = parser->map.player_x;
	game->p_y = parser->map.player_y;
	game->p_view = parser->map.player_view;
	game->mlx = mlx;
	game->game_img = mlx_new_image(mlx, 2000, 1000);//Main image creation
	if (!game->game_img)
		return (error(), 1);
	game->c_col = parser->elem.c_color;
	game->f_col = parser->elem.f_color;
	game->c_col_opposite = get_opposite_color(parser);
	return (0);
	
}


void error(void)
{
	ft_printf("MLX error code: %d\n", mlx_errno);
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
int	start_game(t_game *game, t_parser *parser)
{
	mlx_t *mlx;
	
	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	if (!mlx)
		return (error(), 1);
	if (init_game(mlx, game, parser))
		 return (error(), 1);
	if (mlx_image_to_window(game->mlx, game->game_img, 0, 0) == -1)
		return (error(), 1);
	if(mlx_loop_hook(game->mlx, updater, game))
		return (error(), 1);
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
