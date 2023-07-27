#include <iostream>
#include <string>

struct Person {

	std::string name;
	int health_points;
	int armor;
	int damage;

};

void initializing_fieid(bool is_field[][20]) {

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {

			is_field[i][j] = false;
		}
	}
}
int main() {

	std::srand(std::time(nullptr));

	Person opponents[5];	

	for (int i = 0; i < 5; ++i) {

		opponents[i].name = "Opponent#" + std::to_string(i + 1);
		opponents[i].health_points = std::rand() % 101 + 50;
		opponents[i].armor = std::rand() % 51;
		opponents[i].damage = std::rand() % 15 + 15;
	}


	for (int i = 0; i < 5; ++i) {

		std::cout << "name " << opponents[i].name << " " << "health_points " << opponents[i].health_points << " " << "armor " << opponents[i].armor << " " << opponents[i].damage << std::endl;

	}







	bool is_field[20][20];

	initializing_fieid(is_field);





	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {

			if (is_field[i][j] == 0) {

				std::cout << "." << " ";

			}
			
		}
		std::cout << std::endl;
	}


}