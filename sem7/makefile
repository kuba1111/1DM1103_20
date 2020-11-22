

DEPS=main.o spis.o ranking.o
zad5: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic
%.o: %.c
	cc -c $^ -o $@
clean:
	rm -f zad5
	rm -f *.o