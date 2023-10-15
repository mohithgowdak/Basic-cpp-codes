#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> mat;

public:
    Matrix(const std::vector<std::vector<int>>& input) : mat(input) {}

    Matrix operator+(const Matrix& other) const {
        Matrix result(mat);
        for (size_t i = 0; i < mat.size(); ++i) {
            for (size_t j = 0; j < mat[i].size(); ++j) {
                result.mat[i][j] += other.mat[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(mat);
        for (size_t i = 0; i < mat.size(); ++i) {
            for (size_t j = 0; j < mat[i].size(); ++j) {
                result.mat[i][j] -= other.mat[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(mat.size(), std::vector<int>(other.mat[0].size(), 0));
        for (size_t i = 0; i < mat.size(); ++i) {
            for (size_t j = 0; j < other.mat[0].size(); ++j) {
                for (size_t k = 0; k < other.mat.size(); ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    void print() const {
        for (const auto& row : mat) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::vector<std::vector<int>> a = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> b = {{6, 5}, {4, 3}, {2, 1}};

    Matrix A(a);
    Matrix B(b);

    std::cout << "Matrix A:" << std::endl;
    A.print();

    std::cout << "\nMatrix B:" << std::endl;
    B.print();

    Matrix sum = A + B;
    std::cout << "\nSum of A and B:" << std::endl;
    sum.print();

    Matrix diff = A - B;
    std::cout << "\nDifference of A and B:" << std::endl;
    diff.print();

    Matrix product = A * B;
    std::cout << "\nProduct of A and B:" << std::endl;
    product.print();

    return 0;
}
