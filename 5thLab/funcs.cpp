#include "funcs.h"

bool pointInput(Point3D& p)
{
	std::cout << "Input point\n";
	if (std::cin >> p.x >> p.y >> p.z)
		return 0;

}

Surface::Surface(const Vector3D& vec1, const Vector3D& vec2)
{
	v1 = vec1;
	v2 = vec2;
}

Surface::Surface()
{
	v1;
	v2;
}

Equation::Equation()
{
	A = 0;
	B = 0;
	C = 0;
	D = 0;
}

Equation::Equation(const Surface& s)
{
	Surface surf = s;
	A = surf.v1.getB() * surf.v2.getC() - surf.v1.getC() * surf.v2.getB();
	B = surf.v1.getA() * surf.v2.getC() - surf.v1.getC() * surf.v2.getA();
	C = surf.v1.getA() * surf.v2.getB() - surf.v1.getB() * surf.v2.getA();
	D = -surf.v1.getA() * A - surf.v1.getB() * B - surf.v1.getC() * C;
}

//Exchange two rows of a matrix
void swap(double mat[4][4], int row1, int row2, int col)
{
	for (int i = 0; i < col; i++)
	{
		int temp = mat[row1][i];
		mat[row1][i] = mat[row2][i];
		mat[row2][i] = temp;
	}
}

//Find rank of a matrix
int rankOfMatrix(double mat[4][4])
{
	int rank = 4;

	for (int row = 0; row < rank; row++)
	{
		if (mat[row][row])
		{
			for (int col = 0; col < 4; col++)
			{
				if (col != row)
				{
					double mult = (double)mat[col][row] /
						mat[row][row];
					for (int i = 0; i < rank; i++)
						mat[col][i] -= mult * mat[row][i];
				}
			}
		}
		else
		{
			bool reduce = true;

			for (int i = row + 1; i < 4; i++)
			{
				if (mat[i][row])
				{
					swap(mat, row, i, rank);
					reduce = false;
					break;
				}
			}
			if (reduce)
			{
				rank--;
 
				for (int i = 0; i < 4; i++)
					mat[i][row] = mat[i][rank];
			}
			row--;
		}
	}
	return rank;
}

//If ranks of matrices are equal, surfaces are parallel
bool isParallel(const Surface& s1, const Surface& s2)
{

	Equation eq1(s1), eq2(s2);

	double mat1[4][4] = { {eq1.A, eq1.B, eq1.C, 0}, {eq2.A, eq2.B, eq2.C, 0} };
	int rank1 = rankOfMatrix(mat1);
	double mat2[4][4] = { {eq1.A, eq1.B, eq1.C, -eq1.D}, {eq2.A, eq2.B, eq2.C, -eq2.D} };
	int rank2 = rankOfMatrix(mat2);
	return rank1 == rank2;
}