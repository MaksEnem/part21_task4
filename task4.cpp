#include <iostream>
#include <string>
#include <cstdlib>

struct Person {

	std::string name;
	int health_points;
	int armor;
	int damage;
	int coordinate_x;
	int coordinate_y;
};

void initializing_opponents(Person& opponents, int &i) {	
	
		opponents.name = "Opponent#" + std::to_string(i + 1);
		opponents.health_points = std::rand() % 101 + 50;
		opponents.armor = std::rand() % 51;
		opponents.damage = std::rand() % 16 + 15;	

}

void initializing_heroy(Person& opponents) {
	
	std::cout << "Enter your character's name: ";
	std::cin >> opponents.name;

	std::cout << "Enter the number of health points for your character: ";
	std::cin >> opponents.health_points;

	std::cout << "Enter the number of armor for your character: ";
	std::cin >> opponents.armor;

	std::cout << "Enter the number of damage for your character: ";
	std::cin >> opponents.damage;
}

void initializing_fieid(char field[][20]) {

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {

			field[i][j] = '.';
		}
	}
}

void initializing_game_fieid_opponents(Person& opponents, char field[][20]) {

		do {

			opponents.coordinate_x = std::rand() % 20;
			opponents.coordinate_y = std::rand() % 20;

		} while (field[opponents.coordinate_x][opponents.coordinate_y] != '.');

		field[opponents.coordinate_x][opponents.coordinate_y] = 'E';

}

void initializing_game_fieid_heroy(Person& opponents, char field[][20]) {

	do {

		opponents.coordinate_x = 10;
		opponents.coordinate_y = 10;

	} while (field[opponents.coordinate_x][opponents.coordinate_y] != '.');

	field[opponents.coordinate_x][opponents.coordinate_y] = 'P';

}

void playing_field(char field[][20]) {

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {

			if (field[i][j] == '.') {

				std::cout << "." << " ";

			}
			else if (field[i][j] == 'E') {

				std::cout << "E" << " ";

			}
			else if (field[i][j] == 'P') {

				std::cout << "P" << " ";

			}

		}
		std::cout << std::endl;
	}

}

int main() {

	std::srand(std::time(nullptr));


	Person opponents[6];	


	for (int i = 0; i < 5; ++i) {			

		initializing_opponents(opponents[i], i);
	}


	initializing_heroy(opponents[5]);


	 char field[20][20];


	initializing_fieid(field);


	for (int i = 0; i < 5; ++i) {

		initializing_game_fieid_opponents(opponents[i], field);
	}	

	
	initializing_game_fieid_heroy(opponents[5], field);

	playing_field(field);

	








	bool is_result = true;

	while (is_result) {

		int step;
		char step_heroy;


		for (int i = 0; i < 6; ++i) {

			if (i < 5) {


				step = std::rand() % 4;

				if (step == 0) {

					if (opponents[i].coordinate_x == 19) {

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'E';

					}
					else {				

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = '.';
						opponents[i].coordinate_x += 1;						

						if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] != 'P') {

							if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] != 'E') {
																
								field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'E';

							}
							else if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] == 'E') {

								opponents[i].coordinate_x -= 1;
								field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'E';
							}
						}
						else if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] == 'P') {

							std::cout << "fight!!!!!";

						}
					}
				}
				else if (step == 1) {


					if (opponents[i].coordinate_x == 0) {

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'E';

					}
					else {

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = '.';

						opponents[i].coordinate_x -= 1;

						if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] != 'P') {

							if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] != 'E') {

								field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'E';
							}
							else if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] == 'E') {

								opponents[i].coordinate_x += 1;
								field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'E';
							}
						}
						else if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] == 'P') {

							std::cout << "fight!!!!!";

						}
					}
				}
				else if (step == 2) {

					if (opponents[i].coordinate_y == 19) {

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'E';

					}
					else {

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = '.';

						opponents[i].coordinate_y += 1;

						if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] != 'P') {

							if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] != 'E') {

								field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'E';
							}
							else if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] == 'E') {

								opponents[i].coordinate_y -= 1;
								field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'E';
							}
						}
						else if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] == 'P') {

							std::cout << "fight!!!!!";

						}
					}
				}
				else if (step == 3) {

					if (opponents[i].coordinate_y == 0) {

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'E';

					}
					else {

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = '.';

						opponents[i].coordinate_y -= 1;

						if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] != 'P') {

							if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] != 'E') {

								field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'E';
							}
							else if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] == 'E') {

								opponents[i].coordinate_y += 1;
								field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'E';
							}
						}
						else if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] == 'P') {

							std::cout << "fight!!!!!";

						}
					}
				}
			}
			else if (i == 5) {
				
				playing_field(field);
				do {

					std::cout << "Make a move with the keys: l, r, u, d: ";
					std::cin >> step_heroy;

				} while (step_heroy != 'l' && step_heroy != 'r' && step_heroy != 'u' && step_heroy != 'd');


				if (step_heroy == 'l') {

					if (opponents[i].coordinate_y == 0) {

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'P';

					}
					else {

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = '.';

						opponents[i].coordinate_y -= 1;

						if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] == 'E') {

							std::cout << "fight!";

						}
						else {
							
							field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'P';

						}
					}
				}
				else if (step_heroy == 'r') {

					if (opponents[i].coordinate_y == 19) {

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'P';

					}
					else {

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = '.';

						opponents[i].coordinate_y += 1;

						if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] == 'E') {

							std::cout << "fight!";

						}
						else {

							field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'P';

						}
					}
				}
				else if (step_heroy == 'u') {

					if (opponents[i].coordinate_x == 0) {

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'P';

					}
					else {

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = '.';

						opponents[i].coordinate_x -= 1;

						if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] == 'E') {

							std::cout << "fight!";

						}
						else {

							field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'P';

						}

					}
				}
				else if (step_heroy == 'd') {

					if (opponents[i].coordinate_x == 19) {

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'P';

					}
					else {

						field[opponents[i].coordinate_x][opponents[i].coordinate_y] = '.';

						opponents[i].coordinate_x += 1;
						if (field[opponents[i].coordinate_x][opponents[i].coordinate_y] == 'E') {

							std::cout << "fight!";

						}
						else {

							field[opponents[i].coordinate_x][opponents[i].coordinate_y] = 'P';

						}

					}
				}
				std::cout << std::endl;

				playing_field(field);

			}
		}
	}
}