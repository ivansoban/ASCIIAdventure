#include <iostream>
#include <ncurses.h>
#include "world.h"
#include "tile.h"
#include "player.h"
#include "item.h"
#include "enemy.h"

//Compile: c++ test1.cpp tile.cpp world.cpp player.cpp item.cpp person.cpp -o t_world -lncurses -IIncludes/
//Run:     ./t_world

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

void printGame(int cur_row , int cur_col , int row , int col , int xInWorld , int yInWorld , world w) { // set up init screen

	int init_cur_row = cur_row;	                  // middle of screen; 
	int init_cur_col = cur_col;

	int _xInWorld = xInWorld;
	int _yInWorld = yInWorld;

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

	xInWorld = _xInWorld - (row/2);
	yInWorld = _yInWorld - (col/2);

	while (xInWorld < WORLD_MAX && init_cur_row < row) {

		while (yInWorld < WORLD_MAX && init_cur_col < col) {

			tile c_tile = w.getTile(xInWorld , yInWorld);
			
			if (xInWorld >= 0 && yInWorld >= 0) mvprintw(init_cur_row , init_cur_col , "%c" , c_tile.getVisibleChar());

			yInWorld++;
			init_cur_col++;

		}

		xInWorld++;
		init_cur_row++;
		yInWorld = _yInWorld - (col/2);
		init_cur_col = 0;

	}
		
}



int random(int e) { // 0 to e exclusive

	srand(time(NULL));
	return rand() % e;

}

void mainLoop(int cur_row , int cur_col , int row , int col , int xInWorld , int yInWorld , world w) {

	int ch;

	while(1) {

		ch = wgetch(stdscr);
		getmaxyx(stdscr,row,col);

		if (ch == KEY_LEFT) {

			tile n_tile = w.getTile(xInWorld , yInWorld - 1);
			if (n_tile.isWalkable()) {
				clear();
				printGame(cur_row , cur_col , row , col , xInWorld , yInWorld - 1, w);
				mvprintw(cur_row , cur_col , "%s" , "&");
				yInWorld = yInWorld - 1;
				refresh();
			}

		}

		if (ch == KEY_RIGHT) {

			tile n_tile = w.getTile(xInWorld , yInWorld + 1);
			if (n_tile.isWalkable()) {
				clear();
				printGame(cur_row , cur_col , row , col , xInWorld , yInWorld + 1, w);
				mvprintw(cur_row , cur_col , "%s" , "&");
				yInWorld = yInWorld + 1;
				refresh();
			}

		}

		if (ch == KEY_UP) {

			tile n_tile = w.getTile(xInWorld - 1 , yInWorld);
			if (n_tile.isWalkable()) {
				clear();
				printGame(cur_row , cur_col , row , col , xInWorld - 1 , yInWorld , w);
				mvprintw(cur_row , cur_col , "%s" , "&");
				xInWorld = xInWorld - 1;
				refresh();
			}

		}

		if (ch == KEY_DOWN) {

			tile n_tile = w.getTile(xInWorld + 1, yInWorld);
			if (n_tile.isWalkable()) {
				clear();
				printGame(cur_row , cur_col , row , col , xInWorld + 1 , yInWorld , w);
				mvprintw(cur_row , cur_col , "%s" , "&");
				xInWorld = xInWorld + 1;
				refresh();
			}

		}

		if (ch == 27) {
			break;
		}

	}

}

int main()
{	

	/*************************
	*  world initialization  *
	*************************/

	int row,col;									  // max x and y variables
	int cur_row,cur_col; 							  // middle of the screen variables
	world w("world.w");								  
	tile start = getStartPosition(w);
	int xInWorld = start.getX();
	int yInWorld = start.getY();

	/*************************
	* ncurses initialization *
	*************************/

	initscr();
	curs_set(0);
	clear();
	noecho();	
	cbreak();									
	getmaxyx(stdscr,row,col);
	cur_row = row/2;                                  // The row and col coordinates
	cur_col = col/2;                                  // for the middle of the screen

	keypad(stdscr , TRUE);                            // makes the keys active

	/*************************
	* world/player printing  *
	*************************/

	w.addEnemyToTile(20,10,'E');

	printGame(cur_row , cur_col , row , col , xInWorld , yInWorld , w);

	player p("Ivan" , "Wizard");

	mvprintw(cur_row , cur_col , "%s" , "&");     // Print character

	refresh();

	/*************************/	

	mainLoop(cur_row , cur_col , row , col , xInWorld , yInWorld , w);								

	endwin();								/* End curses mode		  */

	return 0;

}