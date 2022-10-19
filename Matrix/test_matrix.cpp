#include "Matrix.h"
#include "Matrix.cpp"

using std::vector;

int main() {
    //*************testing Matrix(int, int) constructor ************
    try {
        Matrix<int>(0, 4).print();
    }
    catch (std::logic_error& ex) {
        std::cout << ex.what() << std::endl;
    }
    try {
        Matrix<double>(10, 4).print();
    }
    catch (std::logic_error& ex) {
        std::cout << ex.what() << std::endl;
    }

    vector<vector<int> > v{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int> > v2{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matrix<int> m(v);
    Matrix<int> m2(v2);

    //********* testing operator+ *****************
    try {
        m + Matrix<int>(3, 4);
    }
    catch (std::logic_error& ex) {
        std::cout << ex.what() << std::endl;
    }
    Matrix<int> m3 = m + m2;
    std::cout << std::endl;
    m3.print();
    //********* testing template class *****************
    vector<vector<double> > dv{
        {1.5, 2.6, 3.8, 4.6},
        {11.5, 12.6, 5.8, 4.5}
    };

    vector<vector<double> > dv2{
        {1.5, 2.6, 3.8, 4.6},
        {11.5, 12.6, 5.8, 4.5}
    };
    Matrix<double> m4 = Matrix<double>(dv) + Matrix<double>(dv2);
    std::cout << std::endl;
    m4.print();
    //*********************PART2****************
    //*********************GETTING ATTENDANCE CODE****************
    std::cout << "\nGETTING ATTENDANCE CODE" << std::endl;
    std::vector<std::vector<double> > vec{
        {1.3, 1.5, 1.5, 0.6, 0.455},
        {1.3, 0.2, 1.5, 0.35, 0.795},
        {0.5, 1, 1.5, 0.5, 0.75}
    };
    std::vector<std::vector<double> > vec2{
        {1.4, 2, 2.1, 1, 1.2},
        {1, 0.4, 1.5, 2.5, 2},
        {1, 2.3, 0.5, 1.4, 0.6},
        {1, 0.2, 1.5, 2.2, 1.6},
        {1, 1.7, 0.5, 2.1, 0.6}
    };
    std::vector<std::vector<double> > vec3{
        {11.5, 15.68, 3.75, 9.7, 37.5},
        {13.51,   7.5, 31.5, 5.76, 6.91},
        {16,  8.5, 17.765, 15, 6.25}
    };
    Matrix<double> mat1(vec);
    Matrix<double> mat2(vec2);
    Matrix<double> mat3(vec3);
    Matrix<double> mat4 = mat1 * mat2;
    mat4 = mat4 + mat3;
    mat4.print();
    std::cout << "\nAttendance code is " << mat4.getAttendance() << std::endl;
    return 0;
}