/** Make a cake
 * @author Jason M. Li
 * @date 2022.3.15
 * @version 1.0.0
 */

#include <iostream>
#include <cstdio>
#include <string>

std::string repeat(char ch, int times) { return std::string(times, ch); }

std::string print_middle(int total, std::string text, char fill=' ') { // Print in middle
	int left = (total - text.size()) / 2,
	right = total - text.size() - left;
	return repeat(fill, left) + text + repeat(fill, right);
}

const int poss[2][4] = {
	{2, 1, 0, 1},
	{4, 2, 1, 1}
},
lens[2][4] = {
	{1, 3, 5, 3},
	{2, 4, 5, 3}
};

/** Print a cake.
 * @param age      The age of the person(0 -> not display)
 * @param height   The height of the cake (unit: char) (the main part, usually much higher)
 * @param width    The width of the cake (unit: char) (should be more than 14 / prefer multiple of 7)
 * @param status   The status of the candle (0: off, 1: on, 2: leaning)
 * @param name     The name of the person (length should be less than param "width")
 */
void cake(int width=21, int height=10, int age=0, int status=1, const char *name="") {
	int i, j,
	candles_num = width / 7, // left/right: 1ch / width: 5ch / wrap: 2ch -> 7=1, 14=2, 21=3..
	candles_gap = width % 7, // The total length of gap. 1fr + 2fr... + 1fr / round
	candles_gap_fr = 2 + (candles_num - 1) * 2, // total frs
	candles_gap_exp = 0,
	candles_gaps[candles_num],
	candles_last = -1;
	// Candles
	for (i=0; i<candles_num; i++) {
		candles_gap_exp += ((i == 0)? 1: 2) * candles_gap;
		int add_pos = (candles_gap_exp + candles_gap_fr / 2) / candles_gap_fr;
		candles_gaps[i] = add_pos + 1 + (int)(i == 0);
		candles_gap_exp -= add_pos * candles_gap_fr;
		candles_last += candles_gaps[i] + 6;
	}
	switch (status) {
		case 1: case 2: {
			for (i=0; i<4; i++) {
				for (int j=0; j<candles_num; j++) {
					std::cout << repeat(' ', poss[status - 1][i] + candles_gaps[j]) << repeat('*', lens[status - 1][i]) << repeat(' ', 6 - lens[status-1][i] - poss[status-1][i]);
				}
				std::cout << std::endl;
			}
			break;
		}
		case 0: {
			for (i=0; i<4; i++) {
				for (j=0; j<candles_num; j++) {
					std::cout << repeat(' ', candles_gaps[j] + 2) << '|' << repeat(' ', 3);
				}
				std::cout << std::endl;
			}
			break;
		}
	}
	for (i=0; i<candles_num; i++) {
		std::cout << repeat(' ', candles_gaps[i]) << "----- ";
	}
	std::cout << std::endl;
	for (i=0; i<4; i++) {
		for (j=0; j<candles_num; j++) {
			std::cout << repeat(' ', candles_gaps[j]) << "|   | ";
		}
		std::cout << std::endl;
	}
	std::cout << '|';
	for (i=0; i<candles_num; i++) {
		std::cout << repeat('=', candles_gaps[i] - (int)(i == 0)) << "|___|=";
	}
	std::cout << repeat('=', width - candles_last) << '|' << std::endl;
	// wish & name & age
	std::cout << '|' << print_middle(width, "Happy birthday") << '|' << std::endl;
	if (strlen(name) >= 1) std::cout << '|' << print_middle(width, name) << '|' << std::endl;
	if (age != 0) std::cout << '|' << print_middle(width, std::to_string(age)) << '|' << std::endl;
	std::cout << '|' << repeat('=', width) << '|' << std::endl;
	for (i=0; i<height; i++) {
		std::cout << '|' << repeat('~', width) << '|' << std::endl;
	}
	std::cout << '|' << repeat('_', width) << '|' << std::endl;
	std::cout << '|' << repeat('=', width) << '|' << std::endl;
}