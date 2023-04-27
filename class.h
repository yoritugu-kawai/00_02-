#pragma once
struct   Matrix4x4 {
	float m[4][4];
};
// ���@
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);
// ���@
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);
////��
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
////�t�s��
Matrix4x4 Inverse(const Matrix4x4& m);
////�]�u
Matrix4x4 Transpose(const Matrix4x4& m);
////�P�ʍs��쐬
Matrix4x4 MakeIdentity4x4();

static const int kColumnWidth = 60;
static const int kRowHeight = 20;
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* laber);