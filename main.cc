
#include "Snake-Curses.h"


int
main()
{
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);

	int height, width;

	getmaxyx(stdscr, height, width);

	Snake SnakeGame(height, width);

	int key_pressed;
	
	while(SnakeGame.notOver){
		key_pressed = getch();
		if(key_pressed != ERR)
			switch(key_pressed){
				case (int) 'w': SnakeGame.move_up(); break;
				case (int) 'a': SnakeGame.move_left(); break;
				case (int) 's': SnakeGame.move_down(); break;
				case (int) 'd': SnakeGame.move_right(); break;
			}
		SnakeGame.refresh_game();
		usleep(SnakeGame.time_usec);
	}


	endwin();
	return 0;
}

