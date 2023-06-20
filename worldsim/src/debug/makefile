objects = main.o initialize.o main_loop.o shutdown.o error_handling.o engine_options.o display.o eventqueue.o render_timer.o world_cycle_timer.o medium_ether.o world.o utility.o
debug_flags = -g -Wall
allegro_flags = -lallegro -lallegro_primitives

main: $(objects)
	gcc -o main $(objects) $(allegro_flags)

main.o: initialize.h main_loop.h shutdown.h error_handling.h
	gcc -c main.c $(debug_flags)

initialize.o: initialize.c initialize.h engine_options.h error_handling.h display.h eventqueue.h render_timer.h world_cycle_timer.h
	gcc -c initialize.c $(debug_flags)

main_loop.o: main_loop.c main_loop.h eventqueue.h render_timer.h engine_options.h world_cycle_timer.h world.h
	gcc -c main_loop.c $(debug_flags)

shutdown.o: shutdown.c shutdown.h display.h render_timer.h world_cycle_timer.h engine_options.h
	gcc -c shutdown.c $(debug_flags)

error_handling.o: error_handling.c error_handling.h
	gcc -c error_handling.c $(debug_flags)

engine_options.o: engine_options.c engine_options.h error_handling.h utility.h
	gcc -c engine_options.c $(debug_flags)

display.o: display.c display.h engine_options.h
	gcc -c display.c $(debug_flags)

eventqueue.o: eventqueue.c eventqueue.h display.h render_timer.h world_cycle_timer.h
	gcc -c eventqueue.c $(debug_flags)

render_timer.o: render_timer.c render_timer.h engine_options.h error_handling.h
	gcc -c render_timer.c $(debug_flags)

world_cycle_timer.o: world_cycle_timer.c world_cycle_timer.h error_handling.h
	gcc -c world_cycle_timer.c $(debug_flags)

medium_ether.o: medium_ether.c medium_ether.h
	gcc -c medium_ether.c $(debug_flags)
	
world.o: world.c world.h medium_ether.h
	gcc -c world.c $(debug_flags)

utility.o: utility.c utility.h
	gcc -c utility.c $(debug_flags)
	


clean:
	-rm -f main $(objects) ./*~ ./#*#
