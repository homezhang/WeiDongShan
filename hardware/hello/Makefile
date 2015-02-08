hello : hello.o a.o
	gcc -o $@ $^

%.o : %.c
	gcc -o 	$@ -c $<

clean :
	rm *.o hello
