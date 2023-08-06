

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_i {
	void	        *img;
	unsigned char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    int     w;
    int     h;
}				t_i;

typedef struct s_data
{
    void    *mlx;
    void    *window;
    t_i     img;
    t_i     img_ptr;
}   t_data;

int cross(int key, t_data *data)
{
    if (key == 53)
    {
        mlx_destroy_window(data->mlx, data->window);
        printf("DESTROY\n");
        exit(0);
    }
    return (0);
}
int main()
{
    t_data  data;

    data.mlx = mlx_init();
    data.window = mlx_new_window(data.mlx, 360, 200, "MLX");
   // data.img.img = mlx_xpm_file_to_image(data.mlx, "./textures/1337.xpm", 
    //    &data.img.w, &data.img.h);


   // data.img.addr = (unsigned char *)mlx_get_data_addr(data.mlx, &data.img.bits_per_pixel, 
   //                         &data.img.line_length, &data.img.endian);
    
    data.img_ptr.img = mlx_new_image(data.mlx, 360, 200);
    data.img_ptr.addr = (unsigned char *)mlx_get_data_addr(data.img_ptr.img,
                            &data.img_ptr.bits_per_pixel, 
                            &data.img_ptr.line_length, &data.img_ptr.endian);

    printf("bpp = %d\n", data.img_ptr.bits_per_pixel);
    printf("line_length = %d\n", data.img_ptr.line_length);
    printf("endian = %d\n", data.img_ptr.endian);
     int pos = (1 * data.img_ptr.line_length + 1 * (data.img_ptr.bits_per_pixel / 8));
        printf("pos = %d\n", pos);
  
        data.img_ptr.addr[pos] = 255;
    mlx_put_image_to_window(data.mlx, data.window, data.img_ptr.img, 5, 5);
    mlx_hook(data.window, 2, 0, cross, &data);
    mlx_loop(data.mlx);
}