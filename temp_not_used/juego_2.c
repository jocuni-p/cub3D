void	draw_tile(mlx_image_t *game_img, int x, int y, uint32_t color)
{
    int i;
    int j;

    i = 0;
    while (i < TILE_SIZE)
    {
        j = 0;
        while (j < TILE_SIZE)
        {
            //Dibuja solo los píxeles que están dentro de los límites de la imagen principal del juego
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
    while (i < 4) // El jugador será de 4 píxeles de alto
    {
        j = 0;
        while (j < 4) // El jugador será de 4 píxeles de ancho
        {
            if ((uint32_t)x + i >= 0 && (uint32_t)x + i < game_img->width \
			&& (uint32_t)y + j >= 0 && (uint32_t)y + j < game_img->height)
                mlx_put_pixel(game_img, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

int minimap(t_game *game)
{
    // Quitar la creación de la imagen del minimapa
    int x, y;
    int row, col;
    int map_offset_x, map_offset_y; 
    int start_col, end_col, start_row, end_row;
    int player_screen_x, player_screen_y; 

    player_screen_x = game->game_img->width >> 1; 
    player_screen_y = game->game_img->height >> 1; 

    map_offset_x = game->p_x * TILE_SIZE - player_screen_x;
    map_offset_y = game->p_y * TILE_SIZE - player_screen_y;

    start_col = map_offset_x / TILE_SIZE;
    end_col = (map_offset_x + game->game_img->width) / TILE_SIZE;
    start_row = map_offset_y / TILE_SIZE;
    end_row = (map_offset_y + game->game_img->height) / TILE_SIZE;
	
    if (start_row < 0) start_row = 0;
    if (start_col < 0) start_col = 0;
    if (end_row >= game->parser.map.h) end_row = game->parser.map.h - 1;
    if (end_col >= game->parser.map.w) end_col = game->parser.map.w - 1;
	
    row = start_row;
    while (row <= end_row && game->map[row] != NULL)
    {
        col = start_col;
        while (col <= end_col && game->map[row][col] != '\0')
        {
            x = (col * TILE_SIZE) - map_offset_x;
            y = (row * TILE_SIZE) - map_offset_y;

            if (game->map[row][col] == '1' || game->map[row][col] == ' ')
                draw_tile(game->game_img, x, y, game->c_col_opposite);
            col++;
        }
        row++;
    }

    draw_player_tile(game->game_img, player_screen_x + 3, player_screen_y + 2, 0xFFFFFFFF);

    return (0);
}
