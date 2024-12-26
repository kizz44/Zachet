#include <iostream>
#include <vector>
#include <cmath>
#include <Windows.h>

using namespace std;

void Gauss(const vector<vector<double>>& A, const vector<double>& b, vector<double>& x, double tolerance, int maxIterations) {
    int n = A.size();
    for (int k = 0; k < maxIterations; ++k) {
        vector<double> x_old = x;

        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        double maxError = 0.0;
        for (int i = 0; i < n; ++i) {
            maxError = max(maxError, fabs(x[i] - x_old[i]));
        }

        if (maxError < tolerance) {
            cout << "������� ������� �� " << k + 1 << " ��������." << endl;
            return;
        }
    }
    cout << "���������� ������������ ���������� ��������." << endl;
}

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n;
    cout << "������� ���������� ���������� (����������� �������) �� ������ �������� � ������: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);
    vector<double> x(n, 0.0);

    cout << "������� ������������ ������� A (������������ " << n << "x" << n << "):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "������� ��������� ����� ������� b:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    double tolerance;
    cout << "������� ���������� �����������: ";
    cin >> tolerance;

    int maxIterations;
    cout << "������� ������������ ���������� ��������: ";
    cin >> maxIterations;

    Gauss(A, b, x, tolerance, maxIterations);

    cout << "������� �������:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    return 0;
}