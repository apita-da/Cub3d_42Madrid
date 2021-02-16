
		 //move forward if no wall in front of you
		if(mlx_key_hook(KEY_UP_W))
		{
		if(big->map.mapa[(int)(posX + dirX * 0.66)][(int)posY] == 0) posX += dirX * 0.66;
		[big->ray.mapY][big->ray.mapX] 
		if(big->map.mapa[(int)posX][(int)(posY + dirY * 0.66)] == 0) posY += dirY * 0.66;
		}
		//move backwards if no wall behind you
		if(keyDown(KEY_DOWN_S))
		{
		if(big->map.mapa[(int)(posX - dirX * 0.66)][(int)posY] == 0) posX -= dirX * 0.66;
		if(big->map.mapa[(int)posX][(int)(posY - dirY * 0.66)] == 0) posY -= dirY * 0.66;
		}
		//rotate to the right
		if(keyDown(KEY_MOV_RIGHT_E))
		{
		//both camera direction and camera plane must be rotated
		double oldDirX = dirX;
		dirX = dirX * cos(-0.66) - dirY * sin(-0.66);
		dirY = oldDirX * sin(-0.66) + dirY * cos(-0.66);
		double oldPlaneX = planeX;
		planeX = planeX * cos(-0.66) - planeY * sin(-0.66);
		planeY = oldPlaneX * sin(-0.66) + planeY * cos(-0.66);
		}
		//rotate to the left
		if(keyDown(KEY_MOV_LEFT_Q))
		{
		//both camera direction and camera plane must be rotated
		double oldDirX = dirX;
		dirX = dirX * cos(0.66) - dirY * sin(0.66);
		dirY = oldDirX * sin(0.66) + dirY * cos(0.66);
		double oldPlaneX = planeX;
		planeX = planeX * cos(0.66) - planeY * sin(0.66);
		planeY = oldPlaneX * sin(0.66) + planeY * cos(0.66);
		}
