// ppm2pgm.cpp 
// Lisa Jacklin
// CS 201
// 11/17/2021
//


//--Including the libraries
#include<stdio.h>
#include<ppm.h>
#include<math.h>
#include<pgm.h>

int main() {

	//----Declaration of variables
	int i, j, cols, rows, format;
	pixval maxval, r, g, b;
	pixel* x;
	gray maxvalg;
	gray** y;
	FILE* fp1, * fp2;

	//----Reading image
	fp1 = fopen("tetra1.ppm", "r");
	fp2 = fopen("tetrag1.pgm", "w");
	ppm_readppminit(fp1, &cols, &rows, &maxval, &format);
	x = pgm_allocrow(cols);
	y = pgm_allocarray(cols, rows);
	maxvalg = (maxval);
	pgm_writepgminit(fp2, cols, rows, maxvalg, 1);

	//---For loop to read every pixel value
	for (i = 0; i < rows; i++) {
		ppm_readppmrow(fp1, x, cols, maxval, format);
		for (j = 0; j < cols; j++) {
			r = PPM_GETR(x[j]);/* Red intensity */
			g = PPM_GETG(x[j]);/* Green intensity */
			b = PPM_GETB(x[j]);/* Blue intensity */

   //----Following statement assigns the grayvalue to each pixel.
			y[i][j] = (gray)(.299 * r + .587 * g + .114 * b);
		}

		/*---Writing the output image---*/
		pgm_writepgmrow(fp2, y[i], cols, maxvalg, 1);
	}

    cout << "Program finished" << endl;
}