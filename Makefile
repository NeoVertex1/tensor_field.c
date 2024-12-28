CC = gcc
CFLAGS = -Wall -g -Iinclude -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lgsl -lgslcblas -lm
SRCS = src/main.c src/tensor_field.c src/eigen_solver.c src/data_loader.c src/visualization.c
OBJS = $(SRCS:.c=.o)
EXEC = tensor_field_project

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

