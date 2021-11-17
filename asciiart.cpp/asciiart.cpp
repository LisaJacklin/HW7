// asciiart.cpp.cpp 
//CS 201 Homework 7 code Lecture
//Lisa Jacklin
//11/15/2021
//Code Day!

//Homework 7. Main Code
//ppm file to read and print to black and white

//0-255 used for colors

//Header: first four lines with whats shown (pixels, size, name)

#include <iostream>

#if 0
#CREATOR: GIMP PNM Filter Version 1.1
80 80
255
0
0
1
10
11
9
#endif
//end header

int main()
{
	//open the ppm file
	//input file stream
	std::string filename = "parrot.ppm"
		ifstream(filename);
	if (!fin) {
		std::cout << "Error opening" << filename << "\n";
		exit(1);
	}
	std::cout << "Opened " << filename << "\n";


	//read (and verify) the header information
	string line;
	getline(fin, line);
	if (line[0] == 'P' && line[1] == '3') {
		std::cout << "PPM (text)" << "\n";
	}
	else {
		std::cout << "Unable to read magic number P3" << "\n";
		exit(2);
	}

	//quick and dirty - process the comment
	getline(fin, line);
	if (line[0] == '#') {
		std::cout << "ignore the comment\n";
	}

	//read the image size and max value
	int xres, yres, maxval;
	fin >> xres >> yres >> maxval;
	if (!fin) {
		std::cout << "Error reading res \n";
		exit(3);
	}

	std::cout << "image size " << xres << "x" << yres << "\n";
	std::cout << "Maxval = " << maxval << "\n";
	// TODO - check values are valid

	//read the RGB pixels
	int r, g, b;
	int pixels2read = xres * yres;

	for (int i = 0, i < pixels2read; i++) {
		fin >> r >> g >> b;
		if (!fin) {
			std::cout << "Error reading pixels\n";
			exit(3);
		}
		//convert to grayscale
		y = 0.2126 * r + 0.7152 * g + 0.00722 * b;
		//std::cout << i << " = " << r << " "<< g << " " << b <<" \n";
		//std::cout << "-->" << y << "\n";
			//largest value that should be shown here is 255

		if (y < 0 || y >255) { std::cout << "y out of range\n"; exit(4); }

		// map y to an ascii character
		// output each pixel as ascii
		const char values[] = "01234567";
		int y2ascii = y / 32;
		// TODO - for homework adjust to 0 to 15 range ( change 255 to max of 15 out)
		//changes const char values[] and int y2ascii y / ?

		std::cout << "-> " << y2ascii << "\n";
		if (y < 0 || y2ascii >7) { std::cout << "y2ascii out of range\n"; exit(5); }

		std::cout << values[y2ascii];
		if (i % xres == 79) {
			std::cout << "\n";

		}

		std::cout << "Done\n";

	}
}