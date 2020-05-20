CC = gcc          # compiler
CFLAGS = -Wall -g # warnings must have "-" before them
			      # -Wall = warn all problems
			      # -g = flag used when to debugging

#TARGETS 

main : main.o api.o # all .o files must have their sources specified ((*))
                    # the name of the generated executable conventionally  
                    #has the same name as the first file 

main.o : main.c # (*)
api.o : api.c api.h # (*)

clean: rm *.o* main # removes all objects (.o) files after 
