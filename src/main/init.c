/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:49:12 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/09 20:26:50 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_initsprites(t_varlist *vl)
{
	vl->decotext = ft_calloc(4096, 8);
	vl->decotext[0] = mlx_load_png("./assets/decoration/barrel.png");
	vl->decotext[1] = mlx_load_png("./assets/decoration/gbarrel.png");
	vl->decotext[2] = mlx_load_png("./assets/decoration/slamp.png");
	vl->decotext[3] = mlx_load_png("./assets/decoration/armor.png");
	vl->decotext[4] = mlx_load_png("./assets/decoration/pillar.png");
	vl->decotext[5] = mlx_load_png("./assets/decoration/plant.png");
	vl->decotext[6] = mlx_load_png("./assets/decoration/vase.png");
	vl->decotext[7] = mlx_load_png("./assets/decoration/faucet.png");
	vl->decotext[8] = mlx_load_png("./assets/decoration/table.png");
	vl->decotext[9] = mlx_load_png("./assets/decoration/hskel.png");
	vl->decotext[10] = mlx_load_png("./assets/decoration/hlamp.png");
	vl->decotext[11] = mlx_load_png("./assets/decoration/chandel.png");
	vl->decotext[12] = mlx_load_png("./assets/decoration/rubble.png");
}

void	ft_initpickups(t_varlist *vl)
{
	vl->picktext = ft_calloc(4096, 8);
	vl->picktext[0] = mlx_load_png("./assets/pickup/treasure1.png");
	vl->picktext[1] = mlx_load_png("./assets/pickup/treasure2.png");
	vl->picktext[2] = mlx_load_png("./assets/pickup/treasure3.png");
	vl->picktext[3] = mlx_load_png("./assets/pickup/treasure4.png");
	vl->picktext[4] = mlx_load_png("./assets/pickup/hpkit.png");
	vl->picktext[5] = mlx_load_png("./assets/pickup/food.png");
	vl->picktext[6] = mlx_load_png("./assets/pickup/biscuits.png");
	vl->picktext[7] = mlx_load_png("./assets/pickup/gkey.png");
	vl->picktext[8] = mlx_load_png("./assets/pickup/bkey.png");
	vl->picktext[9] = mlx_load_png("./assets/pickup/mgun.png");
	vl->picktext[10] = mlx_load_png("./assets/pickup/ggun.png");
	vl->picktext[11] = mlx_load_png("./assets/pickup/ammo.png");
}

void	ft_initenemies(t_varlist *vl)
{
	vl->gidletext = ft_calloc(4096, 8);
	vl->gidletext[0] = mlx_load_png("./assets/nazi/guard/guard1.png");
	vl->gspottext = ft_calloc(4096, 8);
	vl->gspottext[0] = mlx_load_png("./assets/nazi/guard/fire1.png");
	vl->gspottext[1] = mlx_load_png("./assets/nazi/guard/fire2.png");
	vl->gspottext[2] = mlx_load_png("./assets/nazi/guard/fire3.png");
	vl->gspottext[3] = mlx_load_png("./assets/nazi/guard/fire4.png");
	vl->gdeadtext = ft_calloc(4096, 8);
	vl->gdeadtext[0] = mlx_load_png("./assets/nazi/guard/die1.png");
	vl->gdeadtext[1] = mlx_load_png("./assets/nazi/guard/die2.png");
	vl->gdeadtext[2] = mlx_load_png("./assets/nazi/guard/die3.png");
	vl->gdeadtext[3] = mlx_load_png("./assets/nazi/guard/die4.png");
	vl->gdeadtext[4] = mlx_load_png("./assets/nazi/guard/die5.png");
}

void	ft_initweapons(t_varlist *vl)
{
	vl->gun0text = ft_calloc(4096, 8);
	vl->gun0text[0] = mlx_load_png("./assets/weapon/knife/1.png");
	vl->gun0text[1] = mlx_load_png("./assets/weapon/knife/2.png");
	vl->gun0text[2] = mlx_load_png("./assets/weapon/knife/3.png");
	vl->gun0text[3] = mlx_load_png("./assets/weapon/knife/4.png");
	vl->gun0text[4] = mlx_load_png("./assets/weapon/knife/5.png");
	vl->gun1text = ft_calloc(4096, 8);
	vl->gun1text[0] = mlx_load_png("./assets/weapon/pistol/1.png");
	vl->gun1text[1] = mlx_load_png("./assets/weapon/pistol/2.png");
	vl->gun1text[2] = mlx_load_png("./assets/weapon/pistol/3.png");
	vl->gun1text[3] = mlx_load_png("./assets/weapon/pistol/4.png");
	vl->gun1text[4] = mlx_load_png("./assets/weapon/pistol/5.png");
	vl->gun2text = ft_calloc(4096, 8);
	vl->gun2text[0] = mlx_load_png("./assets/weapon/mgun/1.png");
	vl->gun2text[1] = mlx_load_png("./assets/weapon/mgun/2.png");
	vl->gun2text[2] = mlx_load_png("./assets/weapon/mgun/3.png");
	vl->gun2text[3] = mlx_load_png("./assets/weapon/mgun/4.png");
	vl->gun2text[4] = mlx_load_png("./assets/weapon/mgun/5.png");
	vl->gun3text = ft_calloc(4096, 8);
	vl->gun3text[0] = mlx_load_png("./assets/weapon/ggun/1.png");
	vl->gun3text[1] = mlx_load_png("./assets/weapon/ggun/2.png");
	vl->gun3text[2] = mlx_load_png("./assets/weapon/ggun/3.png");
	vl->gun3text[3] = mlx_load_png("./assets/weapon/ggun/4.png");
	vl->gun3text[4] = mlx_load_png("./assets/weapon/ggun/5.png");
}

void	ft_initmainstuff(t_varlist *vl)
{
	vl->elevtext = ft_calloc(4096, 8);
	vl->elevtext[0] = mlx_load_png("./assets/wall/elevator.png");
	vl->w = 800;
	vl->h = 600;
	vl->sprite = ft_calloc(4096, 8);
	vl->spritecount = 0;
	vl->distance = ft_calloc(4096, 8);
	vl->walltext = ft_calloc(4096, 8);
	vl->vaim = 0;
	vl->jump = 0;
	vl->treasure = 0;
	vl->tottreasure = 0;
	vl->enemies = 0;
	vl->kills = 0;
	vl->mgun = 0;
	vl->ggun = 0;
	vl->ammo = 10;
	vl->hp = 100;
	vl->weapon = 1;
	vl->reloadtime = 0.1;
	vl->firetime = 0;
	vl->reload = 0;
	vl->ccolor = 0;
	vl->fcolor = 0;
	vl->minimap = 0;
	vl->stats = 0;
	vl->menu = 0;
	vl->walltext[0] = NULL;
	vl->walltext[1] = NULL;
	vl->walltext[2] = NULL;
	vl->walltext[3] = NULL;
	vl->tottime = 0;
}

t_varlist	initgame(void)
{
	t_varlist	vl;

	ft_initmainstuff(&vl);
	ft_initsprites(&vl);
	ft_initpickups(&vl);
	ft_initenemies(&vl);
	ft_initweapons(&vl);
	vl.mlx = mlx_init(vl.w, vl.h, "Cub3D", true);
	if (!vl.mlx)
		ft_errorexit("MLX failed to init", "initvarlist", 1);
	vl.img = mlx_new_image(vl.mlx, vl.w, vl.h);
	return (vl);
}
