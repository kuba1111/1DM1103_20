DEPS=main.o odczyt_zapis.o kalkulator.o
zad8: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic -lm
%.o: %.c
	cc -c $^ -o $@
clean:
	rm -f zad8
	rm -f *.o