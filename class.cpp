#include "class.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <cmath>
#include<cassert>
// 加法
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result{};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = m1.m[i][j] + m2.m[i][j];
		}
	}
	

	return result;
}
// 減法
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result{};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = m1.m[i][j] - m2.m[i][j];
		}
	}


	return result;
}
//積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result{};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			float Term = 0;
			for (int k = 0; k < 4; k++) {

			Term =Term+ m1.m[i][k] * m2.m[k][j];
			result.m[i][j] = Term;
			}

		}
	}


	return result;
}
//逆行列
Matrix4x4 Inverse(const Matrix4x4& m) {
	Matrix4x4 result{};
	float as =
		m.m[0][0] * m.m[1][1] * m.m[2][2] * m.m[3][3] +
		m.m[0][0] * m.m[1][2] * m.m[2][3] * m.m[3][1] +
		m.m[0][0] * m.m[1][3] * m.m[2][1] * m.m[3][2] -

		m.m[0][0] * m.m[1][3] * m.m[2][2] * m.m[3][1] -
		m.m[0][0] * m.m[1][2] * m.m[2][1] * m.m[3][3] -
		m.m[0][0] * m.m[1][1] * m.m[2][3] * m.m[3][2] -

		m.m[0][1] * m.m[1][0] * m.m[2][2] * m.m[3][3] -
		m.m[0][2] * m.m[1][0] * m.m[2][3] * m.m[3][1] -
		m.m[0][3] * m.m[1][0] * m.m[2][1] * m.m[3][2] +

		m.m[0][3] * m.m[1][0] * m.m[2][2] * m.m[3][1] +
		m.m[0][2] * m.m[1][0] * m.m[2][1] * m.m[3][3] +
		m.m[0][1] * m.m[1][0] * m.m[2][3] * m.m[3][2] +

		m.m[0][1] * m.m[1][2] * m.m[2][0] * m.m[3][3] +
		m.m[0][2] * m.m[1][3] * m.m[2][0] * m.m[3][1] +
		m.m[0][3] * m.m[1][1] * m.m[2][0] * m.m[3][2] -

		m.m[0][3] * m.m[1][2] * m.m[2][0] * m.m[3][1] -
		m.m[0][2] * m.m[1][1] * m.m[2][0] * m.m[3][3] -
		m.m[0][1] * m.m[1][3] * m.m[2][0] * m.m[3][2] -

		m.m[0][1] * m.m[1][2] * m.m[2][3] * m.m[3][0] -
		m.m[0][2] * m.m[1][3] * m.m[2][1] * m.m[3][0] -
		m.m[0][3] * m.m[1][1] * m.m[2][2] * m.m[3][0] +

		m.m[0][3] * m.m[1][2] * m.m[2][1] * m.m[3][0] +
		m.m[0][2] * m.m[1][1] * m.m[2][3] * m.m[3][0] +
		m.m[0][1] * m.m[1][3] * m.m[2][2] * m.m[3][0];

	assert(as != 0.0f);
	float determinantRecp = 1.0f / as;

	result.m[0][0] =
		(
			m.m[1][1] * m.m[2][2] * m.m[3][3] +
			m.m[1][2] * m.m[2][3] * m.m[3][1] +
			m.m[1][3] * m.m[2][1] * m.m[3][2] -
			m.m[1][3] * m.m[2][2] * m.m[3][1] -
			m.m[1][2] * m.m[2][1] * m.m[3][3] -
			m.m[1][1] * m.m[2][3] * m.m[3][2]

			) * determinantRecp;
	result.m[0][1] =
		(
			-
			m.m[0][1] * m.m[2][2] * m.m[3][3] -
			m.m[0][2] * m.m[2][3] * m.m[3][1] -
			m.m[0][3] * m.m[2][1] * m.m[3][2] +
			m.m[0][3] * m.m[2][2] * m.m[3][1] +
			m.m[0][2] * m.m[2][1] * m.m[3][3] +
			m.m[0][1] * m.m[2][3] * m.m[3][2]
			) * determinantRecp;

	result.m[0][2] =
		(

			m.m[0][1] * m.m[1][2] * m.m[3][3] +
			m.m[0][2] * m.m[1][3] * m.m[3][1] +
			m.m[0][3] * m.m[1][1] * m.m[3][2] -
			m.m[0][3] * m.m[1][2] * m.m[3][1] -
			m.m[0][2] * m.m[1][1] * m.m[3][3] -
			m.m[0][1] * m.m[1][3] * m.m[3][2]
			) * determinantRecp;

	result.m[0][3] =
		(
			-
			m.m[0][1] * m.m[1][2] * m.m[2][3] -
			m.m[0][2] * m.m[1][3] * m.m[2][1] -
			m.m[0][3] * m.m[1][1] * m.m[2][2] +
			m.m[0][3] * m.m[1][2] * m.m[2][1] +
			m.m[0][2] * m.m[1][1] * m.m[2][3] +
			m.m[0][1] * m.m[1][3] * m.m[2][2]
			) * determinantRecp;
	//二行目


	result.m[1][0] =
		(
			-
			m.m[1][0] * m.m[2][2] * m.m[3][3] -
			m.m[1][2] * m.m[2][3] * m.m[3][0] -
			m.m[1][3] * m.m[2][0] * m.m[3][2] +
			m.m[1][3] * m.m[2][2] * m.m[3][0] +
			m.m[1][2] * m.m[2][0] * m.m[3][3] +
			m.m[1][0] * m.m[2][3] * m.m[3][2]

			) * determinantRecp;
	result.m[1][1] =
		(

			m.m[0][0] * m.m[2][2] * m.m[3][3] +
			m.m[0][2] * m.m[2][3] * m.m[3][0] +
			m.m[0][3] * m.m[2][0] * m.m[3][2] -
			m.m[0][3] * m.m[2][2] * m.m[3][0] -
			m.m[0][2] * m.m[2][0] * m.m[3][3] -
			m.m[0][0] * m.m[2][3] * m.m[3][2]
			) * determinantRecp;

	result.m[1][2] =
		(
			-
			m.m[0][0] * m.m[1][2] * m.m[3][3] -
			m.m[0][2] * m.m[1][3] * m.m[3][0] -
			m.m[0][3] * m.m[1][0] * m.m[3][2] +
			m.m[0][3] * m.m[1][2] * m.m[3][0] +
			m.m[0][2] * m.m[1][0] * m.m[3][3] +
			m.m[0][0] * m.m[1][3] * m.m[3][2]
			) * determinantRecp;

	result.m[1][3] =
		(

			m.m[0][0] * m.m[1][2] * m.m[2][3] +
			m.m[0][2] * m.m[1][3] * m.m[2][0] +
			m.m[0][3] * m.m[1][0] * m.m[2][2] -
			m.m[0][3] * m.m[1][2] * m.m[2][0] -
			m.m[0][2] * m.m[1][0] * m.m[2][3] -
			m.m[0][0] * m.m[1][3] * m.m[2][2]
			) * determinantRecp;
	//三行目


	result.m[2][0] =
		(

			m.m[1][0] * m.m[2][1] * m.m[3][3] +
			m.m[1][1] * m.m[2][3] * m.m[3][0] +
			m.m[1][3] * m.m[2][0] * m.m[3][1] -
			m.m[1][3] * m.m[2][1] * m.m[3][0] -
			m.m[1][1] * m.m[2][0] * m.m[3][3] -
			m.m[1][0] * m.m[2][3] * m.m[3][1]

			) * determinantRecp;
	result.m[2][1] =
		(
			-
			m.m[0][0] * m.m[2][1] * m.m[3][3] -
			m.m[0][1] * m.m[2][3] * m.m[3][0] -
			m.m[0][3] * m.m[2][0] * m.m[3][1] +
			m.m[0][3] * m.m[2][1] * m.m[3][0] +
			m.m[0][1] * m.m[2][0] * m.m[3][3] +
			m.m[0][0] * m.m[2][3] * m.m[3][1]
			) * determinantRecp;

	result.m[2][2] =
		(

			m.m[0][0] * m.m[1][1] * m.m[3][3] +
			m.m[0][1] * m.m[1][3] * m.m[3][0] +
			m.m[0][3] * m.m[1][0] * m.m[3][1] -
			m.m[0][3] * m.m[1][1] * m.m[3][0] -
			m.m[0][1] * m.m[1][0] * m.m[3][3] -
			m.m[0][0] * m.m[1][3] * m.m[3][1]
			) * determinantRecp;

	result.m[2][3] =
		(
			-
			m.m[0][0] * m.m[1][1] * m.m[2][3] -
			m.m[0][1] * m.m[1][3] * m.m[2][0] -
			m.m[0][3] * m.m[1][0] * m.m[2][1] +
			m.m[0][3] * m.m[1][1] * m.m[2][0] +
			m.m[0][1] * m.m[1][0] * m.m[2][3] +
			m.m[0][0] * m.m[1][3] * m.m[2][1]
			) * determinantRecp;
	//四行目


	result.m[3][0] =
		(
			-
			m.m[1][0] * m.m[2][1] * m.m[3][2] -
			m.m[1][1] * m.m[2][2] * m.m[3][0] -
			m.m[1][2] * m.m[2][0] * m.m[3][1] +
			m.m[1][2] * m.m[2][1] * m.m[3][0] +
			m.m[1][1] * m.m[2][0] * m.m[3][2] +
			m.m[1][0] * m.m[2][2] * m.m[3][1]

			) * determinantRecp;
	result.m[3][1] =
		(

			m.m[0][0] * m.m[2][1] * m.m[3][2] +
			m.m[0][1] * m.m[2][2] * m.m[3][0] +
			m.m[0][2] * m.m[2][0] * m.m[3][1] -
			m.m[0][2] * m.m[2][1] * m.m[3][0] -
			m.m[0][1] * m.m[2][0] * m.m[3][2] -
			m.m[0][0] * m.m[2][2] * m.m[3][1]
			) * determinantRecp;

	result.m[3][2] =
		(
			-
			m.m[0][0] * m.m[1][1] * m.m[3][2] -
			m.m[0][1] * m.m[1][2] * m.m[3][0] -
			m.m[0][2] * m.m[1][0] * m.m[3][1] +
			m.m[0][2] * m.m[1][1] * m.m[3][0] +
			m.m[0][1] * m.m[1][0] * m.m[3][2] +
			m.m[0][0] * m.m[1][2] * m.m[3][1]
			) * determinantRecp;

	result.m[3][3] =
		(

			m.m[0][0] * m.m[1][1] * m.m[2][2] +
			m.m[0][1] * m.m[1][2] * m.m[2][0] +
			m.m[0][2] * m.m[1][0] * m.m[2][1] -
			m.m[0][2] * m.m[1][1] * m.m[2][0] -
			m.m[0][1] * m.m[1][0] * m.m[2][2] -
			m.m[0][0] * m.m[1][2] * m.m[2][1]
			) * determinantRecp;








	return result;
}
////転置
Matrix4x4 Transpose(const Matrix4x4& m) {
	Matrix4x4 result;

	for (int r = 0; r < 4; ++r)
	{
		for (int c = 0; c < 4; c++)
		{

			result.m[c][r] = m.m[r][c];

		}

	}
	return result;
}
//単位行列作成
Matrix4x4 MakeIdentity4x4() {
	Matrix4x4 result =
	{
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f

	};


	return result;

}
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* laber) {
	Novice::ScreenPrintf(x, y, "%s", laber);
	y += kRowHeight;
	
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight, "%6.02f", matrix.m[row][column]);
		}
	}
}