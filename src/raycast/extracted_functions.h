// Extracted Function Declarations
// This file was generated automatically.

//functions from ./raycast.c
void	print_inter_param(t_inter_param param);
void	print_ray_info(t_ray *ray);
float	normalize_angle(float angle);
float	my_angle_in_radians(float angle);
float	angle_in_radians(float angle);
void	initialize_player(t_player *player, float x, float y, float angle);
void	initialize_array_of_rays(t_ray **rays, int array_size);
void	reset_ray_values(t_ray *ray);
void	free_array_of_rays(t_ray **rays, int array_size);
void	initialize_raycast_info(int column, t_game *game);
void	configure_dda(t_game *game, t_ray *ray);
void	execute_dda(t_game *game, t_ray *ray);
void	compute_wall_intersections(t_game *game, t_ray *ray);
int		execute_raycasting(t_game *game);
void	draw_wall(t_ray *ray, mlx_image_t *img, int x, int bottom_pixel, int top_pixel);
void	render_frame(t_game *game);
