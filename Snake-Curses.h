
#ifndef SNAKE_H
#define SNAKE_H

#include <curses.h>
#include <vector>
#include <algorithm>


typedef std::vector< std::vector<int> > matrix;


class Snake{

	public:
		Snake(int h, int w);
		
	
	private:
		matrix map;
		int height, width;
		int head_i, head_j;
		int tail_i, tail_j;
		void Refresh_Screen();
	
};




#endif
