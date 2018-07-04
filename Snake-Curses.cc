
#include "Snake-Curses.h"

Snake::Snake(int h, int w) : height(h), width(w)
{
	map.resize(height, std::vector<int>(width));
	for(int i = 0; i < height; ++i)
		for(int j = 0; j < width; ++j)
			map[i][j] = 0;
	head_i = height/2;
	head_j = width/2;
	tail_i = head_i - 2;
	tail_j = head_j - 2;

}

void
Snake::Refresh_Screen()
{
	wrefresh(stdscr);	
}
