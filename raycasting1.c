#include "cub3d.h"

int game(t_big *big)
{
	raycasting1(big);
	mlx_put_image_to_window(big->mlx.mlx_ptr, big->mlx.win, big->img.img_ptr, 0, 0);


	return (0);
}

int	raycasting1(t_big *big)
{
	int		w; //res_x
	int		h; //res_y

	big->ray.posX = 10, big->ray.posY = 10;  //x and y start position
  	big->ray.dirX = -1, big->ray.dirY = 0; //initial direction vector
  	big->ray.planeX = 0, big->ray.planeY = 0.66; //the 2d raycaster version of camera plane
	big->ray.x = 0;
	w = big->map.res_x;
	h = big->map.res_y;
	// printf("%i\n", w);
	// printf("%i\n", h);

	while(big->ray.x < w)
	{
     	//calculate ray position and direction
		big->ray.cameraX = 2 * big->ray.x / (double)w - 1; //x-coordinate in camera space
      	big->ray.rayDirX = big->ray.dirX + big->ray.planeX * big->ray.cameraX;
      	big->ray.rayDirY = big->ray.dirY + big->ray.planeY * big->ray.cameraX;
    	//which box of the map we're in
		big->ray.mapY = (int)big->ray.posX;
      	big->ray.mapX = (int)big->ray.posY;
		//length of ray from current position to next x or y-side
		//length of ray from one x or y-side to next x or y-side
		big->ray.deltaDistX = fabs(1 / big->ray.rayDirX);
		big->ray.deltaDistY = fabs(1 / big->ray.rayDirY);
		//calculate step and initial sideDist
		if(big->ray.rayDirX < 0)
		{
			big->ray.stepX = -1;
			big->ray.sideDistX = (big->ray.posX - big->ray.mapY) * big->ray.deltaDistX;
		}
		else
		{
			big->ray.stepX = 1;
			big->ray.sideDistX = (big->ray.mapY + 1.0 - big->ray.posX) * big->ray.deltaDistX;
		}
		if(big->ray.rayDirY < 0)
		{
			big->ray.stepY = -1;
			big->ray.sideDistY = (big->ray.posY - big->ray.mapX) * big->ray.deltaDistY;
		}
		else
		{
			big->ray.stepY = 1;
			big->ray.sideDistY = (big->ray.mapX + 1.0 - big->ray.posY) * big->ray.deltaDistY;
		}
		big->ray.hit = 0;
		while (big->ray.hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if(big->ray.sideDistY < big->ray.sideDistX)
			{
				big->ray.sideDistY += big->ray.deltaDistX;
				big->ray.mapY += big->ray.stepX;
				big->ray.side = 0;
			}
			else
			{
				big->ray.sideDistX += big->ray.deltaDistX;
				big->ray.mapX += big->ray.stepY;
				big->ray.side = 1;
			}
			//Check if ray has hit a wall
			if(big->map.mapa[big->ray.mapY][big->ray.mapX] != '0')
				big->ray.hit = 1;
		}
	  	//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if(big->ray.side == 0)
			big->ray.perpWallDist = (big->ray.mapY - big->ray.posX + (1 - big->ray.stepX) / 2) / big->ray.rayDirX;
		else
			big->ray.perpWallDist = (big->ray.mapX - big->ray.posY + (1 - big->ray.stepY) / 2) / big->ray.rayDirY;
		//Calculate height of line to draw on screen
      	big->ray.lineHeight = (int)(h / big->ray.perpWallDist);
		//calculate lowest and highest pixel to fill in current stripe
		big->ray.drawStart = (-big->ray.lineHeight / 2) + (h / 2);
		if(big->ray.drawStart < 0)
			big->ray.drawStart = 0;
		big->ray.drawEnd = (big->ray.lineHeight / 2) + (h / 2);
		if(big->ray.drawEnd >= h)
			big->ray.drawEnd = h - 1;
      	//choose wall color
		//give x and y sides different brightness
      	//if(side == 1) {color = color / 2;}

		//pinta mapa
		h = 0;
		while(h <= big->ray.drawStart)
		{
			my_mlx_pixel_put(&*big, big->ray.x, h, big->map.cel_colors);
			h++;
		}
		while(h > big->ray.drawStart && h <= big->ray.drawEnd)
		{
			my_mlx_pixel_put(&*big, big->ray.x, h, BLUE);
			h++;
		}
		while(h > big->ray.drawEnd && h < big->map.res_y)
		{
			my_mlx_pixel_put(&*big, big->ray.x, h, big->map.flo_colors);
			h++;
		}
		movement0(big);
		big->ray.x++;
	}
	return (0);
}