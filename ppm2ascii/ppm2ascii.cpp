// ppm2ascii.cpp 
// Lisa Jacklin
// CS 201
// 11/15/2021
//

// what is our algorithm?
// This will be wordy while writing/debugging
// Agile - get it working for parrot.ppm

/*This is the first few lines of parrot.ppm
P3
# CREATOR: GIMP PNM Filter Version 1.1
80 80
255
0
0
1
10
11
8
*/

#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <fstream>
#include <sstream>
using std::ifstream;

int main()
{
    cout << "Program to convert a ppm to ascii art" << endl;

    // open the file
    string infile = "parrot.ppm";
    ifstream fin(infile);
    if (!fin) {
        cout << "Error opening " << infile << endl;
        exit(1);
    }
    else { cout << "Opened " << infile << endl; }

    // read the magic number
    string line;
    getline(fin, line);
    if (line[0] == 'P' && line[1] == '3') {
        cout << "PPM (text)" << endl;
    }
    else {
        cout << "Unable to read magic number P3" << endl;
        exit(2);
    }

    // quick and dirty - process comment
    getline(fin, line);
    if (line[0] == '#') {
        cout << "Ignoring comment" << endl;
    }

    // this won't handle comments
    int xres, yres, maxval;
    fin >> xres >> yres >> maxval;
    if (!fin) {
        cout << "Error reading stream" << endl;
        exit(3);
    }
    cout << "Image size: " << xres << " x " << yres << endl;
    cout << "Maxval = " << maxval << endl;

    // loop for xres * yres iterations
    int r, g, b, iy;
    double y;
    char values[] = "@@@###***+++--- ";
    for (int i = 0; i < xres * yres; i++) {
        fin >> r >> g >> b;
        if (!fin) {
            cout << "Error reading stream" << endl;
            exit(4);
        }
        // Y = 0.2126R + 0.7152G + 0.0722B (from HW7)
        y = 0.2126 * r + 0.7152 * g + 0.0722 * b;
        // test
        if (y < 0.0 || y >= 256.0) cout << "ERROR!!!!!!!!!!!" << endl;
        //    cout << r << " " << g << " " << b;
        //    cout << " => " << y;
        iy = (int)y;
        // iy should be [0...255]
        if (iy < 0 || iy > 255) cout << "ERROR!!!!!!!!!!!!!!" << endl;
        //    cout << " => " << iy;
        iy /= 16;
        // iy should be [0...15]
        if (iy < 0 || iy > 15) cout << "ERROR!!!!!!!!!!!!!!" << endl;
        //    cout << " => " << iy << endl;
        cout << values[iy];
        if (i % 80 == 79) cout << endl;
    }

    cout << "Program finished" << endl;
}