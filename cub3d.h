/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: houtworm <codam@houtworm.net>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 10:46:35 by houtworm      #+#    #+#                 */
/*   Updated: 2023/11/06 01:16:25 by houtworm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "getnextline/get_next_line.h"
# include "mlx/include/MLX42/MLX42.h"
# include <stdio.h>

typedef struct			s_sprite
{
	double				distance;
	double				x;
	double				y;
	int					type;
	int					number;
}						t_sprite;

typedef struct			s_draw
{
	double				transformx;
	double				transformy;
	int					spritescreen;
	int					vmovescreen;
	int					spriteheight;
	int					spritewidth;
	int					drawstarty;
	int					drawstartx;
	int					drawendy;
	int					drawendx;
	int					texx;
	int					texy;
}						t_draw;

typedef struct			s_varlist
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	mlx_image_t			*fstat;
	mlx_image_t			*tstat;
	mlx_image_t			*cstat;
	mlx_image_t			*kstat;
	mlx_image_t			*astat;
	mlx_image_t			*hstat;
	mlx_image_t			*wimg;
	mlx_texture_t		*temptext;
	mlx_texture_t		**walltext;
	mlx_texture_t		**decotext;
	mlx_texture_t		**picktext;
	mlx_texture_t		**nazitext;
	mlx_texture_t		**gun0text;
	mlx_texture_t		**gun1text;
	mlx_texture_t		**gun2text;
	mlx_texture_t		**gun3text;
	t_sprite			*sprite;
	int					spritecount;
	int					w;
	int					h;
	char				**map;
	double				frametime;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	int					vaim;
	int					jump;
	double				run;
	double				raydirx;
	double				raydiry;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				walldist;
	int					lineheight;
	int					side;
	double				oldmouseposx;
	double				oldmouseposy;
	int32_t				fcolor;
	int32_t				ccolor;
	int					*distance;
	int					treasure;
	int					tottreasure;
	int					tottime;
	double				anitime;
	double				firetime;
	int					enemies;
	int					kills;
	int					mgun;
	int					ggun;
	int					ammo;
	int					weapon;
	int					reload;
	int					hp;
}						t_varlist;

// MAIN
t_varlist	initgame(void);
int			ft_errorexit(char *reason, char *function, int code);
void		ft_printstats(t_varlist *vl);
void		ft_cleanup(t_varlist *vl);
// PARSE
t_varlist	ft_parseconfigfile(t_varlist vl, char *filename);
char		**ft_getmap(t_varlist *vl, int fd);
char		ft_addwalktroughdecor(t_varlist *vl, int x, int y, int number);
char		ft_addsoliddecor(t_varlist *vl, int x, int y, int number);
char		ft_addpickup(t_varlist *vl, int x, int y, int number);
char		ft_addenemy(t_varlist *vl, int x, int y, int number);
// INPUT
void		ft_processinput(t_varlist *vl);
void		ft_processturn(t_varlist *vl, double rotspeed);
void		ft_processmove(t_varlist *vl, double movespeed);
void		ft_processacro(t_varlist *vl, double movespeed);
void		ft_processguns(t_varlist *vl);
void		keyhook(mlx_key_data_t kd, void *param);
void		scrollhook(double xdelta, double ydelta, void *param);
void		resizehook(int x, int y, void *param);
void		cursorhook(double x, double y, void *param);
// DRAW
void		ft_raycast(t_varlist *vl, int x, int mapx, int mapy);
void		ft_drawmap(t_varlist *vl);
void		ft_drawweapon(t_varlist *vl);
int			ft_gettextx(t_varlist *vl);
uint32_t	ft_gettextcolor(mlx_texture_t *texture, int texty, int textx);
// SPRITE
void		ft_drawsprite(t_varlist *vl, t_draw *draw, int x);
t_draw		*ft_initdrawsprite(t_varlist *vl, int i);
void		ft_getdrawstartend(t_varlist *vl, t_draw *draw);
void		ft_drawsprites(t_varlist *vl);
void		ft_checkpickup(t_varlist *vl);
#endif
