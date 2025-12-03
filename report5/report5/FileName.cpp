#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

struct Matrix3 {
    int m[3][3];
};

void printMatrix(const Matrix3& A) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << setw(5) << A.m[i][j] << " ";
        }
        cout << '\n';
    }
}

void printMatrixDouble(double A[3][3]) {
    cout << fixed << setprecision(4);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << setw(10) << A[i][j] << " ";
        }
        cout << '\n';
    }
}

Matrix3 generateRandomMatrix(int low = -9, int high = 9) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(low, high);

    Matrix3 A;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            A.m[i][j] = dist(gen);
        }
    }
    return A;
}

int generateRandomScalar(int low = -9, int high = 9) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(low, high);
    return dist(gen);
}

Matrix3 addMatrix(const Matrix3& A, const Matrix3& B) {
    Matrix3 C{};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            C.m[i][j] = A.m[i][j] + B.m[i][j];
    return C;
}

Matrix3 subMatrix(const Matrix3& A, const Matrix3& B) {
    Matrix3 C{};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            C.m[i][j] = A.m[i][j] - B.m[i][j];
    return C;
}

Matrix3 scalarMul(const Matrix3& A, int k) {
    Matrix3 C{};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            C.m[i][j] = k * A.m[i][j];
    return C;
}

Matrix3 mulMatrix(const Matrix3& A, const Matrix3& B) {
    Matrix3 C{};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int sum = 0;
            for (int k = 0; k < 3; ++k) {
                sum += A.m[i][k] * B.m[k][j];
            }
            C.m[i][j] = sum;
        }
    }
    return C;
}

int determinant(const Matrix3& A) {
    int a = A.m[0][0], b = A.m[0][1], c = A.m[0][2];
    int d = A.m[1][0], e = A.m[1][1], f = A.m[1][2];
    int g = A.m[2][0], h = A.m[2][1], i = A.m[2][2];

    int det = a * (e * i - f * h)
        - b * (d * i - f * g)
        + c * (d * h - e * g);
    return det;
}

bool isInvertible(const Matrix3& A, int& det_out) {
    det_out = determinant(A);
    return det_out != 0;
}

void inverse(const Matrix3& A, double inv[3][3]) {
    int a = A.m[0][0], b = A.m[0][1], c = A.m[0][2];
    int d = A.m[1][0], e = A.m[1][1], f = A.m[1][2];
    int g = A.m[2][0], h = A.m[2][1], i = A.m[2][2];

    int det = determinant(A);
    double invDet = 1.0 / static_cast<double>(det);

    inv[0][0] = (e * i - f * h) * invDet;
    inv[0][1] = -(b * i - c * h) * invDet;
    inv[0][2] = (b * f - c * e) * invDet;

    inv[1][0] = -(d * i - f * g) * invDet;
    inv[1][1] = (a * i - c * g) * invDet;
    inv[1][2] = -(a * f - c * d) * invDet;

    inv[2][0] = (d * h - e * g) * invDet;
    inv[2][1] = -(a * h - b * g) * invDet;
    inv[2][2] = (a * e - b * d) * invDet;
}

int main() {

    Matrix3 A = generateRandomMatrix();
    Matrix3 B = generateRandomMatrix();
    int k = generateRandomScalar();

    cout << "==== 무작위로 생성된 행렬 및 스칼라 ====\n";
    cout << "행렬 A:\n";
    printMatrix(A);
    cout << "\n행렬 B:\n";
    printMatrix(B);
    cout << "\n정수 스칼라 k: " << k << "\n\n";

    cout << "==== 행렬 덧셈 및 뺄셈 ====\n";
    Matrix3 C_add = addMatrix(A, B);
    Matrix3 C_sub = subMatrix(A, B);
    cout << "A + B:\n";
    printMatrix(C_add);
    cout << "\nA - B:\n";
    printMatrix(C_sub);
    cout << "\n";

    cout << "==== 스칼라 곱셈 ====\n";
    Matrix3 kA = scalarMul(A, k);
    Matrix3 kB = scalarMul(B, k);
    cout << "k * A:\n";
    printMatrix(kA);
    cout << "\nk * B:\n";
    printMatrix(kB);
    cout << "\n";

    cout << "==== 행렬 곱셈 ====\n";
    Matrix3 AB = mulMatrix(A, B);
    Matrix3 BA = mulMatrix(B, A);
    cout << "A * B:\n";
    printMatrix(AB);
    cout << "\nB * A:\n";
    printMatrix(BA);
    cout << "\n";

    cout << "==== 역행렬 존재 여부 및 계산 ====\n";

    int detA = 0, detB = 0;

    bool invA = isInvertible(A, detA);
    cout << "det(A) = " << detA << "\n";
    if (invA) {
        cout << "A는 역행렬을 가질 수 있다.\n";
        double Ainv[3][3];
        inverse(A, Ainv);
        cout << "A^(-1):\n";
        printMatrixDouble(Ainv);
    }
    else {
        cout << "A는 det(A) = 0 이므로 역행렬을 가질 수 없다.\n";
    }
    cout << "\n";

    bool invB = isInvertible(B, detB);
    cout << "det(B) = " << detB << "\n";
    if (invB) {
        cout << "B는 역행렬을 가질 수 있다.\n";
        double Binv[3][3];
        inverse(B, Binv);
        cout << "B^(-1):\n";
        printMatrixDouble(Binv);
    }
    else {
        cout << "B는 det(B) = 0 이므로 역행렬을 가질 수 없다.\n";
    }

    return 0;
}
