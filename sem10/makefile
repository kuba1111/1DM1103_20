all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-ile: all
	./mydb baza.csv count_students

dodaj-kuba: all
	./mydb baza.csv add_student Jakub Łabędzki 0379 kukuba@op.pl

dodaj-drift: all
	./mydb baza.csv add_course 557997157 poctawy_driftingu 2020W

dodaj-ocene_kubie: all
	./mydb baza.csv add_student_to_course 557997157 0379 4.0 dobrze_ale_wymaga_treningu

test-memory: all
	valgrind  ./mydb baza.csv count_students --leak-check=full

