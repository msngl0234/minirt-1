NAME = minirt
TEST_NAME = minirt_test
# 📁 Kaynak dosyalar
SRCS = ray.c camera.c color.c render.c sphere.c  vector.c plane.c shading_utils.c mlx_utils.c lighting_utils.c shadow_utils.c cylinder.c
MAIN = main.c
TEST = test.c
MAIN_OBJS = $(SRCS:.c=.o) main.o
TEST_OBJS = $(SRCS:.c=.o) test.o

# ⚙️ Derleyici ve bayraklar
CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99

# 🧱 MiniLibX ayarları (macOS)
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

#MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# 🎯 Varsayılan hedef
all: $(NAME)

# 🔨 Derleme
$(NAME): $(MAIN_OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN_OBJS) $(MLX_FLAGS)

# 🔨 Derleme
test: $(TEST_OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(TEST_NAME) $(TEST_OBJS) $(MLX_FLAGS)

# 📦 .o dosyaları oluştur
%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

# 🧹 Temizlik hedefleri
clean:
	rm -f $(MAIN_OBJS) $(TEST_OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all
