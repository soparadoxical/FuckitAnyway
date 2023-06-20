objects = main.o initialize.o main_loop.o shutdown.o \
          error_handling.o engine_options.o display.o eventqueue.o \
          render_timer.o utility.o

allegro_flags = -lallegro -lallegro_primitives


main: $(objects)
	gcc -o main $(objects) $(allegro_flags)

main.o: main.c initialize.h main_loop.h shutdown.h error_handling.h
	gcc -c main.c

initialize.o: initialize.c initialize.h engine_options.h display.h \
              eventqueue.h render_timer.h
	gcc -c initialize.c

main_loop.o: main_loop.c main_loop.h eventqueue.h render_timer.h engine_options.h
	gcc -c main_loop.c

shutdown.o: shutdown.c shutdown.h eventqueue.h display.h render_timer.h
	gcc -c shutdown.c

error_handling.o: error_handling.c error_handling.h
	gcc -c error_handling.c

engine_options.o: engine_options.c engine_options.h utility.h
	gcc -c engine_options.c

display.o: display.c display.h engine_options.h
	gcc -c display.c

eventqueue.o: eventqueue.c eventqueue.h display.h render_timer.h
	gcc -c eventqueue.c

render_timer.o: render_timer.c render_timer.h engine_options.h error_handling.h
	gcc -c render_timer.c

utility.o: utility.c utility.h
	gcc -c utility.c

clean:
	-rm -f main $(objects) *~ \#*\#
