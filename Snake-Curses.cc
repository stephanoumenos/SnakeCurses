
#include "Snake-Curses.h"

Snake::Snake(int h, int w) : height(h), width(w)
{
	notOver = true;

	time_usec = 50000;

	map.resize(height, std::vector<int>(width));
	for(int i = 0; i < height; ++i)
		for(int j = 0; j < width; ++j)
			map[i][j] = 0;
	head_i = height/2;
	head_j = width/2;
	/* Sets initial state */
	map[head_i][head_j] = 3;
	map[head_i + 1][head_j] = 2;
	map[head_i + 2][head_j] = 1;

	snake_length = 3;

	srand(time(NULL));

	orientation = UP;

	Snake::spawn_food();

	Snake::draw_map();

}

void
Snake::refresh_game()
{
	Snake::move();
	Snake::draw_map();
}

void
Snake::spawn_food()
{
	int i_food = rand() % height;
	int j_food = rand() % width;
	while(map[i_food][j_food] != 0){
		i_food = rand() % height;
		j_food = rand() % width;
	}
	map[i_food][j_food] = FOOD;
}

void
Snake::move_up()
{
	if(orientation != DOWN)
		orientation = UP;
}

void
Snake::move_down()
{
	if(orientation != UP)
		orientation = DOWN;
}

void
Snake::move_left()
{
	if(orientation != RIGHT)
		orientation = LEFT;
}

void
Snake::move_right()
{
	if(orientation != LEFT)
		orientation = RIGHT;
}

void
Snake::decreases_one()
{
	for(int i = 0; i < height; ++i)
		for(int j = 0; j < width; ++j)
			if(map[i][j] > 0)
				map[i][j]--;
}

void
Snake::move()
{
	int i_dest = head_i, j_dest = head_j;

	switch(orientation){
		case UP: i_dest--; break;
		case DOWN: i_dest++; break;
		case LEFT: j_dest--; break;
		case RIGHT: j_dest++; break;
	}
	// Uncomment for easy mode (if the snake'd hit the wall, she appears on the opposite side)
//	if(i_dest == height){
//		i_dest = 0;
//	} else if(i_dest < 0){
//		i_dest = height-1;
//	} else if(j_dest == width){
//		j_dest = 0;
//	} else if(j_dest < 0){
//		j_dest = width-1;
//	}
	
	if(i_dest < 0 || i_dest == height || j_dest < 0 || j_dest == width || map[i_dest][j_dest] > 0){
		Snake::game_over();
		return;
	}

	if(map[i_dest][j_dest] == -1){
		snake_length++;
		map[i_dest][j_dest] = snake_length;
		time_usec = (time_usec*4)/5;
		Snake::spawn_food();
	} else{
		Snake::decreases_one();
		map[i_dest][j_dest] = snake_length;
	}

	head_i = i_dest;
	head_j = j_dest;
}

void
Snake::draw_map()
{
	wmove(stdscr, 0, 0);
	for(int i = 0; i < height; ++i){
		for(int j = 0; j < width; ++j){
			if(map[i][j] == 0){
				addch(' ');
			} else{
				addch(ACS_BLOCK);	
			}
		}
	}
	wrefresh(stdscr);	
}

void
Snake::game_over()
{
	notOver = false;

}


