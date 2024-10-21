int	main(int argc, char **argv)
{
	t_core	core;

	core = (t_core){};
	core.scene = create_scene(argc, argv);
	print_scene(&core.scene);
	begin_window(&core, 1280, 960);
//	/init_minimap(&core.scene, core.img);
//	init_animation(core.img, &core.scene.a, SPRITE_TEX);
	mlx_loop_hook(core.mlx, game_loop, &core);
//	mlx_close_hook(core.mlx, (void (*)(void *))mlx_close_window, core.mlx);
	mlx_loop(core.mlx);
	dispose_scene(&core.scene);
	dispose_mlx(core.mlx);
	return (EXIT_SUCCESS);
}
void	game_loop(void *param)
{
	t_core			*core;
	mlx_image_t		*image;
	static int8_t	frame_count = 0;

	core = (t_core *)param;
	image = core->img;
	event_listener(core->mlx, &core->scene);
//	mouse_listener(core->mlx, &core->scene);
//	update_doors(&core->scene.map, frame_count);
//	raycast(image, core->scene);
	minimap(image, core->scene);
//	animation(image, &core->scene.a);
//	frame_count++;
}

void	event_listener(mlx_t *mlx, t_scene *scene)
{
	if (mlx_is_	key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
//	if (mlx_is_key_down(mlx, MLX_KEY_SPACE) || mlx_is_mouse_down(mlx,
//			MLX_MOUSE_BUTTON_LEFT))
//		interact(scene);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		move(scene, scene->player.dir.x, scene->player.dir.y, SPEED);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		move(scene, -scene->player.dir.x, -scene->player.dir.y, SPEED);
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		move(scene, scene->player.dir.y, -scene->player.dir.x, SPEED);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		move(scene, -scene->player.dir.y, scene->player.dir.x, SPEED);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		rotate(scene, -SENSITIVITY * 42);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		rotate(scene, SENSITIVITY * 42);
}
static void	move(t_scene *scene, float fx, float fy, double move_speed)
{
//fx y fy es a donde te quieres mover en floats
//move _speed es la longitud del salto que va a dar el player al moverse (tendra que dar mas o menos saltos para llegar a fx y se vera mas o mens fluido el movimiento)
	int	next_y;
	int	next_x;

	next_y = (int)(scene->player.pos.y + fy * (move_speed + 0.01));
	next_x = (int)(scene->player.pos.x + fx * (move_speed + 0.01));
	if (scene->map.cells[next_y][(int)(scene->player.pos.x)] == SPACE)
//		|| scene->map.cells[next_y][(int)(scene->player.pos.x)] == DOOR_OPEN)
//		scene->player.pos.y += fy * move_speed;
		scene->player.pos.y += 0.01;//variar segun la velocidad deseada
	if (scene->map.cells[(int)(scene->player.pos.y)][next_x] == SPACE)
//		|| scene->map.cells[(int)(scene->player.pos.y)][next_x] == DOOR_OPEN)
		scene->player.pos.x += fx * move_speed;
}

void	rotate(t_scene *scene, double angle)
{
	float	dir;
	float	plane;

	dir = scene->player.dir.x;
	scene->player.dir.x = scene->player.dir.x * cos(angle) - scene->player.dir.y
		* sin(angle);
	scene->player.dir.y = dir * sin(angle) + scene->player.dir.y * cos(angle);
	plane = scene->player.plane.x;
	scene->player.plane.x = scene->player.plane.x * cos(angle)
		- scene->player.plane.y * sin(angle);
	scene->player.plane.y = plane * sin(angle) + scene->player.plane.y
		* cos(angle);
}
