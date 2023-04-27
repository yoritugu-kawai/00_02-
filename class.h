#pragma once
struct   Matrix4x4 {
	float m[4][4];
};
// 加法
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);
// 減法
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);
////積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
////逆行列
Matrix4x4 Inverse(const Matrix4x4& m);
////転置
Matrix4x4 Transpose(const Matrix4x4& m);
////単位行列作成
Matrix4x4 MakeIdentity4x4();

static const int kColumnWidth = 60;
static const int kRowHeight = 20;
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* laber);