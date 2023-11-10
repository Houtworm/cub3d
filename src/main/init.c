/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 16:49:12 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/10 09:13:39 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_initsprites(t_varlist *vl)
{
	vl->decotxt = ft_calloc(4096, 8);
	vl->decotxt[0] = mlx_load_png("./assets/decoration/barrel.png");
	vl->decotxt[1] = mlx_load_png("./assets/decoration/gbarrel.png");
	vl->decotxt[2] = mlx_load_png("./assets/decoration/slamp.png");
	vl->decotxt[3] = mlx_load_png("./assets/decoration/armor.png");
	vl->decotxt[4] = mlx_load_png("./assets/decoration/pillar.png");
	vl->decotxt[5] = mlx_load_png("./assets/decoration/plant.png");
	vl->decotxt[6] = mlx_load_png("./assets/decoration/vase.png");
	vl->decotxt[7] = mlx_load_png("./assets/decoration/faucet.png");
	vl->decotxt[8] = mlx_load_png("./assets/decoration/table.png");
	vl->decotxt[9] = mlx_load_png("./assets/decoration/hskel.png");
	vl->decotxt[10] = mlx_load_png("./assets/decoration/hlamp.png");
	vl->decotxt[11] = mlx_load_png("./assets/decoration/chandel.png");
	vl->decotxt[12] = mlx_load_png("./assets/decoration/rubble.png");
}

void	ft_initpickups(t_varlist *vl)
{
	vl->picktxt = ft_calloc(4096, 8);
	vl->picktxt[0] = mlx_load_png("./assets/pickup/treasure1.png");
	vl->picktxt[1] = mlx_load_png("./assets/pickup/treasure2.png");
	vl->picktxt[2] = mlx_load_png("./assets/pickup/treasure3.png");
	vl->picktxt[3] = mlx_load_png("./assets/pickup/treasure4.png");
	vl->picktxt[4] = mlx_load_png("./assets/pickup/hpkit.png");
	vl->picktxt[5] = mlx_load_png("./assets/pickup/food.png");
	vl->picktxt[6] = mlx_load_png("./assets/pickup/biscuits.png");
	vl->picktxt[7] = mlx_load_png("./assets/pickup/gkey.png");
	vl->picktxt[8] = mlx_load_png("./assets/pickup/bkey.png");
	vl->picktxt[9] = mlx_load_png("./assets/pickup/mgun.png");
	vl->picktxt[10] = mlx_load_png("./assets/pickup/ggun.png");
	vl->picktxt[11] = mlx_load_png("./assets/pickup/ammo.png");
}

void	ft_initenemies(t_varlist *vl)
{
	vl->gfiretxt = ft_calloc(4096, 8);
	vl->gfiretxt[0] = mlx_load_png("./assets/nazi/guard/fire1.png");
	vl->gfiretxt[1] = mlx_load_png("./assets/nazi/guard/fire2.png");
	vl->gfiretxt[2] = mlx_load_png("./assets/nazi/guard/fire3.png");
	vl->gfiretxt[3] = mlx_load_png("./assets/nazi/guard/fire4.png");
	vl->gdeadtxt = ft_calloc(4096, 8);
	vl->gdeadtxt[0] = mlx_load_png("./assets/nazi/guard/die1.png");
	vl->gdeadtxt[1] = mlx_load_png("./assets/nazi/guard/die2.png");
	vl->gdeadtxt[2] = mlx_load_png("./assets/nazi/guard/die3.png");
	vl->gdeadtxt[3] = mlx_load_png("./assets/nazi/guard/die4.png");
	vl->gdeadtxt[4] = mlx_load_png("./assets/nazi/guard/die5.png");
}

void	ft_initweapons(t_varlist *vl)
{
	vl->gun0txt = ft_calloc(4096, 8);
	vl->gun0txt[0] = mlx_load_png("./assets/weapon/knife/1.png");
	vl->gun0txt[1] = mlx_load_png("./assets/weapon/knife/2.png");
	vl->gun0txt[2] = mlx_load_png("./assets/weapon/knife/3.png");
	vl->gun0txt[3] = mlx_load_png("./assets/weapon/knife/4.png");
	vl->gun0txt[4] = mlx_load_png("./assets/weapon/knife/5.png");
	vl->gun1txt = ft_calloc(4096, 8);
	vl->gun1txt[0] = mlx_load_png("./assets/weapon/pistol/1.png");
	vl->gun1txt[1] = mlx_load_png("./assets/weapon/pistol/2.png");
	vl->gun1txt[2] = mlx_load_png("./assets/weapon/pistol/3.png");
	vl->gun1txt[3] = mlx_load_png("./assets/weapon/pistol/4.png");
	vl->gun1txt[4] = mlx_load_png("./assets/weapon/pistol/5.png");
	vl->gun2txt = ft_calloc(4096, 8);
	vl->gun2txt[0] = mlx_load_png("./assets/weapon/mgun/1.png");
	vl->gun2txt[1] = mlx_load_png("./assets/weapon/mgun/2.png");
	vl->gun2txt[2] = mlx_load_png("./assets/weapon/mgun/3.png");
	vl->gun2txt[3] = mlx_load_png("./assets/weapon/mgun/4.png");
	vl->gun2txt[4] = mlx_load_png("./assets/weapon/mgun/5.png");
	vl->gun3txt = ft_calloc(4096, 8);
	vl->gun3txt[0] = mlx_load_png("./assets/weapon/ggun/1.png");
	vl->gun3txt[1] = mlx_load_png("./assets/weapon/ggun/2.png");
	vl->gun3txt[2] = mlx_load_png("./assets/weapon/ggun/3.png");
	vl->gun3txt[3] = mlx_load_png("./assets/weapon/ggun/4.png");
	vl->gun3txt[4] = mlx_load_png("./assets/weapon/ggun/5.png");
}

t_varlist	initgame(void)
{
	t_varlist	vl;

	ft_resetvars(&vl);
	ft_initsprites(&vl);
	ft_initpickups(&vl);
	ft_initenemies(&vl);
	ft_initweapons(&vl);
	vl.mlx = mlx_init(vl.w, vl.h, "Cub3D", true);
	if (!vl.mlx)
		ft_errorexit("MLX failed to init", "initvarlist", 1);
	return (vl);
}
