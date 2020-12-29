#include "mat.h"
int main()
{
	int vecs1, result = 0, num;
	cout << "\tInput vector size" << endl;
	cin >> vecs1;
	TVector<int> vec1(vecs1, 0), vec2(vecs1, 0), res(3, 0);
	cout << "\tFirst vector" << endl;
	cin >> vec1;
	cout << "\tSecond vector" << endl;
	cin >> vec2;
	system("cls");
	cout << "\tFirst vector" << endl;
	cout << vec1<< endl;
	cout << "\tSecond vector" << endl;
	cout << vec2 << endl;
	cout << "\tDot product of vectors" << endl;
	cout << vec1 * vec2 << endl;
	cout << "\tComparison of two vectors" << endl;
	if (vec1 == vec2)
		cout << "\tVecrtors are equel" << endl;
	else
		cout << "\tVecrtors aren't equel" << endl;
	cout << "\tAddition of vectors" << endl;
	res = vec1 + vec2;
	cout << res << endl;
	cout << "\tSubtraction of vectors" << endl;
	res = vec1 - vec2;
	cout << res << endl;
	cout << "\tAddition of the first vector and number" << endl;
	cout << "Enter a number" << endl;
	cin >> num;
	res = vec1 + num;
	cout << res << endl;
	cout << "\tSubtraction of of the first vector and number" << endl;
	cout << "Enter a number" << endl;
	cin >> num;
	res = vec1 - num;
	cout << res << endl;
	cout << "\tMultiplication of the first vector by a number" << endl;
	cout << "Enter a number" << endl;
	cin >> num;
	res = vec1 * num;
	cout << res << endl;
	cout << "\tPushBack of the first vector" << endl;
	cout << "Enter a number" << endl;
	cin >> num;
	vec1.pushBack(num);
	cout << vec1<<endl;
	cout << "\tpopBack of the first vector" << endl;
	vec1.popBack();
	cout << vec1<<endl;
	cout << "\tMATRIX" << endl;
	TMatrix<int> mat1(vecs1), mat2(vecs1), ress(vecs1);
	cout << "\tFirst MATRIX " << endl;
	cin >> mat1;
	cout << "\tSecond MATRIX " << endl;
	cin >> mat2;
	cout << "\tFirst M" << endl;
	cout << mat1;
	cout << "\tSecond M" << endl;
	cout << mat2;
	ress = mat1 + mat2;
	cout << "\tAddition of two matrix" << endl;
	cout << ress;
	ress = mat1 - mat2;
	cout << "\tSubtraction of two matrix" << endl;
	cout << ress;
	if(mat1 == mat2)
		cout << "\tMatrix are equel" << endl;
	else
		cout << "\tMatrix are NOT equel" << endl;
	ress = mat1 * mat2;
	cout << "\tMultiplication of two matrix" << endl;
	cout << ress;
}
