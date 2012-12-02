#include <iostream>
#include <ncurses.h>
#include "world.h"
#include "tile.h"

tile getStartPosition(world & w) {

	for (int i = 0; i < WORLD_MAX; ++i) {
		for (int j = 0; j < WORLD_MAX; ++j) {

			tile cur = w.getTile(i,j);
			char ch = cur.getVisibleChar();
			if (ch == 'X') {
				cur.setRowAndCol(i,j);
				return cur;
			}
		}
	}

	tile e = w.getTile(0,0);
	return e;

}

int main()
{	
	int row,col;
	int cur_row,cur_col;
	world w("world.w");
	tile start = getStartPosition(w);

	initscr();
	curs_set(0);
	clear();
	noecho();	
	cbreak();									
	getmaxyx(stdscr,row,col);
	cur_row = row/2;                                  // The row and col coordinates
	cur_col = col/2;                                  // for the middle of the screen

	keypad(stdscr , TRUE);                            // makes the keys active
	
	{ // set up init screen
		int init_cur_row = cur_row;	                  // middle of screen; 
		int init_cur_col = cur_col;

		int xInWorld = start.getX();                  // The row and col coordinates
		int yInWorld = start.getY();                  // for the start of world.

		while (init_cur_col > 0) {
			
			if (yInWorld < 0) break;

			tile c_tile = w.getTile(xInWorld , yInWorld);
			mvprintw(init_cur_row , init_cur_col , "%c" , c_tile.getVisibleChar());
			init_cur_col--;
			yInWorld--;

		}

		while (init_cur_col < col) {

			if (yInWorld >= WORLD_MAX) break;

			tile c_tile = w.getTile(xInWorld , yInWorld);
			mvprintw(init_cur_row , init_cur_col , "%c" , c_tile.getVisibleChar());
			init_cur_col++;
			yInWorld++;

		}
		
		init_cur_row = 0;
		init_cur_col = 0;

		xInWorld = start.getX() - (row/2 + 1);
		yInWorld = start.getY() - (col/2 + 1);

		while (xInWorld < WORLD_MAX && init_cur_row < row) {

			while (yInWorld < WORLD_MAX && init_cur_col < col) {

				tile c_tile = w.getTile(xInWorld , yInWorld);
				
				if (xInWorld >= 0 && yInWorld >= 0) mvprintw(init_cur_row , init_cur_col , "%c" , c_tile.getVisibleChar());

				yInWorld++;
				init_cur_col++;

			}

			xInWorld++;
			init_cur_row++;
			yInWorld = start.getY() - (col/2 + 1);
			init_cur_col = 0;

		}
		
	}

	mvprintw(cur_row , cur_col , "%s" , "&");     // Print character

	refresh();									

	int ch;

	while(1) {

		ch = wgetch(stdscr);
		getmaxyx(stdscr,row,col);

		if (ch == KEY_LEFT)
		{
			clear();
			mvprintw(cur_row , cur_col - 1 , "%s" , "&");
			cur_col = cur_col - 1;
			refresh();
		}
		if (ch == KEY_RIGHT)
		{
			clear();
			mvprintw(cur_row , cur_col + 1 , "%s" , "&");
			cur_col = cur_col +  1;
			refresh();
		}
		if (ch == KEY_UP)
		{
			clear();
			mvprintw(cur_row - 1 , cur_col , "%s" , "&");
			cur_row = cur_row - 1;
			refresh();
		}
		if (ch == KEY_DOWN)
		{
			clear();
			mvprintw(cur_row + 1 , cur_col , "%s" , "&");
			cur_row = cur_row + 1;
			refresh();
		}
		if (ch == 27)
		{
			break;
		}

	}

	endwin();								/* End curses mode		  */

	return 0;
}