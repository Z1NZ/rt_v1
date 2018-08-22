/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:10:51 by srabah            #+#    #+#             */
/*   Updated: 2016/03/17 22:14:08 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_matrice
{
	double		m[3][3];
	int			x;
	int			y;
}				t_matrice;

typedef struct	s_mouse
{
	double		x;
	double		y;
}				t_mouse;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_sphere
{
	int			rayon;
	int			color;
	t_vector	org;
}				t_sphere;
/*
** struct light
**	ka  lumières ambiante
**	kd diffuse
**	ks spéculaire
**	ia l'intensité de la lumière ambiante
**	n le paramètre de brillance
*/
typedef struct	s_light
{
	double		hue;
	double		ka;
	double		kd;
	double		ks;
	double		ia;
	double		n;
	int			rayon;
	int			color;
	t_vector	org;
}				t_light;

typedef struct	s_cylindre
{
	int			rayon;
	int			color;
	t_vector	org;
	t_vector	axe;
	t_vector	angle;
}				t_cylindre;

typedef struct	s_cone
{
	int			rayon;
	int			color;
	t_vector	angle;
	t_vector	org;
	t_vector	axe;
	double		anno;
}				t_cone;

typedef struct	s_lims
{
	int			ymin;
	int			ymax;
}				t_lims;

typedef struct	s_plane
{
	t_vector	n;
	double		d;
	int			color;
}				t_plane;

typedef	struct	s_cam
{
	t_vector	org;
	t_vector	angle;
}				t_cam;

typedef struct	s_env
{
	int			select;
	void		*win;
	void		*mlx;
	void		*img;
	char		*img_addr;
	t_mouse		mouse;
	t_cam		cam;
	t_light		light;
	t_light		light_bis;
	t_plane		plan;
	t_sphere	sphere;
	t_cylindre	cylindre;
	t_cone		cone;
}				t_env;

typedef struct	s_thrarg
{
	t_lims		lims;
	t_env		*e;
}				t_thrarg;

typedef struct	s_ray
{
	t_vector	org;
	t_vector	dir;
}				t_ray;

# define NUM_THREADS		8
# define KEYPRESSMASK		(1L<<0)
# define KEYPRESS			2
# define CLAMP(X, min, max)	(X >= min) ? ((X <= max) ? X : max) : min
# define HEIGHT				800
# define WIDTH				800
# define DEEP				2000
# define KEY_0				82
# define KEY_1				83
# define KEY_2				84
# define KEY_3				85
# define KEY_4				86
# define KEY_5				87
# define KEY_6				88
# define KEY_7				89
# define KEY_8				91
# define KEY_9				92
# define KEY_PLUS			69
# define KEY_MOINS			78
# define KEY_ESC			53
# define KEY_ENTER			36
# define KEY_TAB			48
# define KEY_A				0
# define KEY_B				11
# define KEY_C				8
# define KEY_D				2
# define KEY_F				3
# define KEY_I				34
# define KEY_J				38
# define KEY_L				37
# define KEY_K				40
# define KEY_M				46
# define KEY_N				45
# define KEY_O				31
# define KEY_P				35
# define KEY_S				1
# define KEY_X				7
# define KEY_W				13
# define KEY_Q				12
# define KEY_E				14
# define KEY_Z				6
# define LEFT				123
# define UP					126
# define RIGHT				124
# define DOWN				125
# define SCROLL_UP			5
# define SCROLL_DOWN		4
# define LEFT_CLIC			1
# define MID_CLIC			2
# define RIGHT_CLIC			3
# define HOME				256
# define END				193
# define DELETE				117
# define PAGE_DOWN			121
# define FN					279
# define PAGE_UP			116
# define SHIFT				258
# define CONTROL			269

/*
** core
*/
int				core_key_hook(int kc, t_thrarg *threads);
void			core_put_pixel(int x, int y, int color, t_env *e);
void			*core_ray_trace(void *data);
void			core_init_threads(t_thrarg *threads);
int				core_mouse_hook(int bouton, int x, int y, t_thrarg *threads);
int				core_color_spec(int color_o, int color_l, double il, double ib);
int				core_color_add(int a_color, int b_color);
int				core_color_shadow(int color_obj, double p_div);
int				core_ret(t_vector abc, double *hit, double delta);
t_ray			core_ray_init(t_ray ray, int w, int h);
/*
** libft
*/
void			ft_bzero(void *s, int n);
void			*ft_memalloc(size_t size);
void			*ft_memset(void *b, int c, size_t len);
/*
**  matrice
*/
t_vector		matrice_core(t_ray ray, t_env *e);
t_matrice		*matrice_init_x(double angle);
t_matrice		*matrice_init_y(double angle);
t_matrice		*matrice_init_z(double angle);
t_matrice		*matrice_product(t_matrice *ptr1, t_matrice *ptr2);
t_vector		vector_matrice(t_matrice m, t_vector v);
t_vector		matrice_core_obj(t_vector obj, t_vector angle);
/*
** obj / plan
*/
int				expo_pixel_plan(t_ray ray, t_env *e, t_light light, double hit);
int				hit_plan(t_ray ray, t_plane plan, double *hit);
int				shadow_plan(t_ray ray, t_env *e, double hit);
void			init_plan(t_env *e);
void			hook_plan(int key, t_env *e);
/*
** obj / cone
*/
int				hit_cone(t_ray ray, t_cone cone, double *hit);
void			init_cone(t_env *e);
int				expo_pixel_cone(t_ray ray, t_env *e, t_light l, double hit);
int				shadow_cone(t_ray ray, t_env *e, double hit);
void			hook_cone(int key, t_env *e);
/*
**obj / sphere
*/
int				expo_pixel_sphere(t_ray ray, t_env *e, t_light l, double hit);
int				hit_sphere(t_ray ray, t_sphere sphere, double *hit);
void			init_sphere(t_env *e);
int				shadow_sphere(t_ray ray, t_env *e, double hit);
void			hook_sphere(int key, t_env *e);
/*
**obj / cylindre
*/
int				hit_cylindre(t_ray ray, t_cylindre cylindre, double *hit);
void			init_cylindre(t_env *e);
int				expo_pixel_cylindre(t_ray ray, t_env *e, t_light l, double hit);
int				shadow_cylindre(t_ray ray, t_env *e, double hit);
void			hook_cylindre(int key, t_env *e);
/*
** obj / light
*/
void			init_light(t_env *e);
void			hook_light(int key, t_env *e);
int				hit_light(t_ray ray, t_light light, double *hit);
/*
** obj / light_bis
*/
void			init_light_bis(t_env *e);
void			hook_light_bis(int key, t_env *e);
int				hit_light_bis(t_ray ray, t_light light, double *hit);
/*
** obj / cam
*/
void			hook_cam(int key, t_env *e);
void			init_cam(t_env *e);
/*
** vector
*/
double			vector_norm(t_vector a);
double			vector_dot_product(t_vector v1, t_vector v2);
t_vector		vector_add(t_vector a, t_vector b);
t_vector		vector_normalise(t_vector a);
t_vector		vector_scalar(t_vector a, double scalar);
t_vector		vector_sub(t_vector a, t_vector b);
t_vector		vector_mult(t_vector a, double cof);

#endif
