CC = gcc
AR = ar
M_GR = my_graph.c
M_M = my_mat.o
M_K = my_Knapsack.c
M_MH = my_mat.h
FLAGS = -Wall -g

all: graphs graphsd my_Knapsack my_graph

graphs: libgraph.a
libgraph.a: $(M_M)
	$(AR) -rcs libgraph.a $(M_M)


graphsd: libgraph.so
libgraph.so: $(M_M)
	$(CC) -shared -o libgraph.so $(M_M)

my_Knapsack: $(M_K)
	$(CC) $(FLAGS) -o my_Knapsack $(M_K)

my_Knapsack.o: $(M_K)
	$(CC) $(FLAGS) -fPIC -c $(M_K)

my_graph: $(M_GR) libgraph.a
	$(CC) $(FLAGS) -o my_graph $(M_GR) libgraph.a

my_graph.o: $(M_GR) $(M_MH)
	$(CC) $(FLAGS) -fPIC -c $(M_GR)

my_mat.o: $(M_MH) my_mat.c
	$(CC) $(FLAGS) -fPIC -c my_mat.c


.PHONY: clean all

clean:
	rm -f *.o *.a *.so my_graph my_Knapsack