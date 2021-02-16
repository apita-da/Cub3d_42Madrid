#include "cub3d.h"

int		key_press(int keycode, t_big *big)
{
	write(1, "1\n", 2);
	if (keycode == 53)
	{
		printf("el programa se ha cerrado con éxito");
		exit(0);
	}
	if(keycode == KEY_UP_W)
		big->mov.key_w = 1;
	else if(keycode == KEY_DOWN_S)
		big->mov.key_s = 1;
	else if(keycode == KEY_LEFT_A)
		big->mov.key_a = 1;
	else if(keycode == KEY_RIGHT_D)
		big->mov.key_d = 1;
	else if(keycode == KEY_MOV_LEFT_Q)
		big->mov.key_q = 1;
	else if(keycode == KEY_MOV_RIGHT_E)
		big->mov.key_e = 1;
	return(1);
}

int		key_release(int keycode, t_big *big)
{
	write(1, "2\n", 2);
	
	if(keycode == KEY_UP_W)
		big->mov.key_w = 0;
	else if(keycode == KEY_DOWN_S)
		big->mov.key_s = 0;
	else if(keycode == KEY_LEFT_A)
		big->mov.key_a = 0;
	else if(keycode == KEY_RIGHT_D)
		big->mov.key_d = 0;
	else if(keycode == KEY_MOV_LEFT_Q)
		big->mov.key_q = 0;
	else if(keycode == KEY_MOV_RIGHT_E)
		big->mov.key_e = 0;
	 return(0);
}

void	movement0(t_big *big)
{
	if(big->mov.key_w == 1)
	{
		printf("x:%f y:%f\n", big->ray.posX, big->ray.posY);
		if(big->map.mapa[(int)(big->ray.posX + big->ray.dirX * 0.1)][(int)big->ray.posY] == 0) 
			big->ray.posX += big->ray.dirX * 0.1;
		if(big->map.mapa[(int)big->ray.posX][(int)(big->ray.posY + big->ray.dirY * 0.1)] == 0)
			 big->ray.posY += big->ray.dirY * 0.1;

	}
	if(big->mov.key_s == 1)
	{
		printf("x:%f y:%f\n", big->ray.posX, big->ray.posY);
		if(big->map.mapa[(int)(big->ray.posX - big->ray.dirX * 0.1)][(int)big->ray.posY] == 0) 
			big->ray.posX -= big->ray.dirX * 0.1;
		if(big->map.mapa[(int)big->ray.posX][(int)(big->ray.posY - big->ray.dirY - 0.1)] == 0)
			 big->ray.posY -= big->ray.dirY * 0.1;
		
	}
	if(big->mov.key_e == 1)
	{
		double oldDirX = big->ray.dirX;
		big->ray.dirX = big->ray.dirX * cos(-0.1) - big->ray.dirY * sin(-0.1);
		big->ray.dirY = oldDirX * sin(-0.1) + big->ray.dirY * cos(-0.1);
		double oldPlaneX = big->ray.planeX;
		big->ray.planeX = big->ray.planeX * cos(-0.1) - big->ray.planeY * sin(-0.1);
		big->ray.planeY = oldPlaneX * sin(-0.1) + big->ray.planeY * cos(-0.1);
	}
}


