/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:46:35 by houtworm          #+#    #+#             */
/*   Updated: 2024/03/01 15:12:34 by fsarkoh          ###   ########.fr       */
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

# define DOOR_CLOSING		0
# define DOOR_OPENING		1
# define DOOR_IDLE			2
# define DOOR_SPEED			0.01
# define DOOR_TILL_CLOSE	5

typedef struct s_door
{
	int				x;
	int				y;
	double			closedness;
	unsigned int	status;
	double			time;

}				t_door;

typedef struct s_sprite
{
	double				distance;
	double				x;
	double				y;
	double				anitime;
	int					type;
	int					number;
	int					status;
}						t_sprite;

typedef struct s_draw
{
	double				tfx;
	double				tfy;
	int					sprs;
	int					vmov;
	int					sprh;
	int					sprw;
	int					drawstarty;
	int					drawstartx;
	int					drawendy;
	int					drawendx;
	int					x;
	int					y;
}						t_draw;

typedef struct s_varlist
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	mlx_image_t			*fstat;
	mlx_image_t			*tstat;
	mlx_image_t			*cstat;
	mlx_image_t			*kstat;
	mlx_image_t			*astat;
	mlx_image_t			*hstat;
	mlx_image_t			**mstat;
	mlx_image_t			*wimg;
	mlx_image_t			*mimg;
	mlx_image_t			*oimg;
	mlx_image_t			*fimg;
	mlx_texture_t		*temptxt;
	mlx_texture_t		**walltxt;
	mlx_texture_t		**elevtxt;
	mlx_texture_t		**doortxt;
	mlx_texture_t		**decotxt;
	mlx_texture_t		**picktxt;
	mlx_texture_t		**gfiretxt;
	mlx_texture_t		**gdeadtxt;
	mlx_texture_t		**gun0txt;
	mlx_texture_t		**gun1txt;
	mlx_texture_t		**gun2txt;
	mlx_texture_t		**gun3txt;
	t_sprite			*sprite;
	t_door				**doors;
	int					spritecount;
	int					w;
	int					h;
	char				**map;
	int					mapsizey;
	int					mapsizex;
	double				frametime;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	int					mapx;
	int					mapy;
	int					vaim;
	int					jump;
	double				run;
	double				raydirx;
	double				raydiry;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				wdist;
	int					lineh;
	int					side;
	double				oldmouseposx;
	double				oldmouseposy;
	int32_t				fcolor;
	int32_t				ccolor;
	int					*distance;
	int					treasure;
	int					tottreasure;
	double				tottime;
	double				firetime;
	int					enemies;
	int					kills;
	int					mgun;
	int					ggun;
	int					ammo;
	int					weapon;
	int					reload;
	double				reloadtime;
	int					hp;
	int					minimap;
	int					stats;
	int					menu;
	char				*cubfile;
	int					flash;
	int					flashcolor;
}						t_varlist;

// MAIN
t_varlist	initgame(void);
int			ft_errorexit(char *reason, char *function, int code);
void		ft_printstats(t_varlist *vl);
void		ft_cleanup(t_varlist *vl);
void		ft_resetvars(t_varlist *vl);
void		ft_restartgame(t_varlist *vl);
void		ft_raycast(t_varlist *vl, int x);
int			ft_prepcast(t_varlist *vl, int x);
int			ft_getstepx(t_varlist *vl, int mapx);
int			ft_getstepy(t_varlist *vl, int mapy);
// PARSE
t_varlist	ft_parseconfigfile(t_varlist vl, char *filename);
void		ft_checkline(t_varlist *vl, char *line);
char		**ft_getmap(t_varlist *vl, int fd);
t_door		**ft_initdoors(t_varlist *vl);
t_door		*ft_get_door(t_varlist *vl, int x, int y);
void		ft_update_doors(t_varlist *vl);
char		ft_checkmapelement(t_varlist *vl, char element, int x, int y);
char		ft_initplayer(t_varlist *vl, char dir, int x, int y);
char		ft_addwalktroughdecor(t_varlist *vl, int x, int y, int number);
char		ft_addsoliddecor(t_varlist *vl, int x, int y, int number);
char		ft_addpickup(t_varlist *vl, int x, int y, int number);
char		ft_addenemy(t_varlist *vl, int x, int y, int number);
int			ft_floodfill(t_varlist vl);
int			ft_flood(t_varlist vl, char **fillmap, int x, int y);
// INPUT
void		ft_processinput(t_varlist *vl);
void		ft_processturn(t_varlist *vl, double rotspeed);
void		ft_processmove(t_varlist *vl, double mvs, double mvy, double mvx);
void		ft_processacro(t_varlist *vl, double movespeed);
void		ft_processguns(t_varlist *vl);
void		keyhook(mlx_key_data_t kd, void *param);
void		scrollhook(double xdelta, double ydelta, void *param);
void		resizehook(int x, int y, void *param);
void		cursorhook(double x, double y, void *param);
// DRAW
void		ft_drawmap(t_varlist *vl);
void		ft_drawweapon(t_varlist *vl);
void		ft_drawsprite(t_varlist *vl, t_draw *draw, int x, int i);
void		ft_drawsprites(t_varlist *vl);
int			ft_gettextx(t_varlist *vl);
uint32_t	ft_gettextcolor(mlx_texture_t *texture, int texty, int textx);
void		ft_flashscreen(t_varlist *vl, int x, int y, uint32_t color);
void		ft_drawminimap(t_varlist *vl);
void		ft_finish(t_varlist *vl);
void		ft_youdied(t_varlist *vl);
// ACTION
void		ft_checkpickup(t_varlist *vl);
void		ft_firebullet(t_varlist *vl);
void		ft_enemyaction(t_varlist *vl);
void		ft_fireweapon(t_varlist *vl);
void		ft_interact(t_varlist *vl);
void		ft_checkhealth(t_varlist *vl);
#endif
