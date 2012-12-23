#include "world.h"
#include <fstream>
#include <iostream>
#include <string>


world::world(std::string w) {
	
	std::ifstream worldFile;
	const char * wc = w.c_str();
	worldFile.open(wc);

	if (worldFile.is_open()) {
		
		int rowCount = 0;
		while (worldFile.good()) {

			int in;
			std::string nl = "\n";
			std::string line;

			getline(worldFile,line);
			in = line.rfind(nl);
			if (in != std::string::npos) {
				line.replace(in,nl.length(),"");
			}

			for (int i = 0 ; i < line.length() ; ++i){
				
				this->wholeWorld[rowCount][i].setVisibleChar(line.at(i));

			}

		rowCount++;

		}

	}

	worldFile.close();	

}

void world::showWorld() {

	for (int i = 0 ; i < WORLD_MAX ; ++i) {
		for (int j = 0 ; j < WORLD_MAX ; ++j) {
			std::cout << this->getTile(i,j).getVisibleChar();
		}
		std::cout<<std::endl;
	}

}

tile world::getTile(int row , int col) {

	if (row < WORLD_MAX && col < WORLD_MAX) return this->wholeWorld[row][col];
	else { return this->wholeWorld[0][0]; }

}

void world::addEnemyToTile(int row , int col , char c) {

	enemy::enemy * e = new enemy(20 , 20 , c);

	wholeWorld[row][col].setEnemy(e); // TODO: change to new .setEnemy(enemy::enemy *)
	wholeWorld[row][col].setVisibleChar(c);


}