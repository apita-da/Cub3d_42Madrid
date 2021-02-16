/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:42:05 by apita-da          #+#    #+#             */
/*   Updated: 2021/02/16 17:52:46 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
#include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
# define BUFFER_SIZE 42
# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFF
# define KEY_UP_W 13
# define KEY_DOWN_S 1
# define KEY_LEFT_A 0
# define KEY_RIGHT_D 2
# define KEY_MOV_LEFT_Q 12
# define KEY_MOV_RIGHT_E 14


typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}			t_img;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;

}			t_mlx;

typedef struct s_map
{
	char		*line;
	char		*parse;
	int			res_x;
	int			res_y;
	int			flo_colors;
	int			cel_colors;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	char		**mapa;
	
}				t_map;

typedef struct	s_ray
{
	int			x;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int 		lineHeight;
	int 		drawStart;
	int 		drawEnd;
	int			mapX;
	int			mapY;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	double 		sideDistX;
	double 		sideDistY;
	double 		deltaDistX;
	double 		deltaDistY;
	double		perpWallDist;
	double		moveSpeed;
	double		rotSpeed;

}				t_ray;

typedef struct	s_mov
{
	int 		key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_q;
	int			key_e;
	
} 				t_mov;


typedef struct	s_big
{
	t_img		img;
	t_mlx		mlx;
	t_map		map;
	t_ray		ray;
	t_mov		mov;
}				t_big;

// mapa
t_map			*readmap(t_map *map, char *line);
int				get_resolution(t_map *map, char *line);
int				get_lines(t_map *map, char *line);
char			text_north(t_map *map, char *line);
char			text_south(t_map *map, char *line);
char			text_west(t_map *map, char *line);
char			text_east(t_map *map, char *line);
char			text_sprite(t_map *map, char *line);
int				colors_flo(t_map *map, char *line);
int				colors_cel(t_map *map, char *line);
char			*parse_map(t_map *map, char *line);

//utils
int				intlen(int i);
int				get_next_line(int fd, char **line);
char			*ft_strchr(const char *str, int c);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s1);
int				ft_atoi(const char *str);
int 			rgb_int(int red, int green, int blue);
char			check_blanks(char *strs);
char			**ft_split(char const *s, char c);
char 			*str_join(char *buf, char *add);
void			ft_bzero(void *str);
void			*ft_memset(void *str, int c, size_t nb);



// ventana
int				openwin(void);
int 			main(void);
void			my_mlx_pixel_put(t_big *data, int x, int y, int color);
int				exitwin(int keycode);
int				key_release(int keycode, t_big *big);
int				key_press(int keycode, t_big *big);
int				raycasting(t_big *big);
int				game(t_big *big);

// movimiento
void			movement0(t_big *big);


#endif
