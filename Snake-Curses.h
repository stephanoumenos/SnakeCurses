
#ifndef SNAKE_H
#define SNAKE_H

#include <curses.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

#define FOOD -1

typedef std::vector< std::vector<int> > matrix;

enum Orientation {LEFT, RIGHT, UP, DOWN};

class Snake{

	public:
		Snake(int h, int w);
		int time_usec;
		void move_up();
		void move_down();
		void move_left();
		void move_right();
		bool notOver;
		void refresh_game();
	
	private:
		matrix map;
		int height, width;
		int head_i, head_j;
		int snake_length;
		enum Orientation orientation;

		void draw_map();
		void spawn_food();
		void decreases_one();
		void move();
		void game_over();
		
};



#endif
