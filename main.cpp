/*
 * Taller Eigen
 * Autor: Mitchell Bermin
 * Fecha: 22 ago 2022
 * Materia: introduccion a HPC
*/

#include <iostream>
#include <eigen3/Eigen/Dense>

using namespace std;

int main()
{
    //EJERCICIO 1
    //Se declaran las dos matrices
       Eigen::Matrix2i m1;
       m1 << 4, -2,
            1, -7;
       Eigen::Matrix2i m2;
       m2 << -1, 2,
            6, -5;

   //Se realiza el calculo y se imprime el resultado
       Eigen::MatrixXi m3;
       m3 = (3*m1) - (4*m2);
       cout << "EJERCICIO #1: \n";
       cout << "3A - 4B = X\n" << m3 << "\n" <<endl;

   //EJERCICIO 2
   //Se declaran las dos matrices a operar
       Eigen::Matrix2d m4;
       m4 << 0, -1,
            2, 1;
       Eigen::Matrix2d m5;
       m5<< 1, 2,
            3, 4;

    //Se realiza el calculo y se imprime el resultado
       Eigen::MatrixXd m6;
       m6 = ((m5*m4*3) - (4*m4))/2;
       cout << "EJERCICIO #2: \n";
       cout << "(2X + 4A = 3B) = \n" << m6 << "\n"  <<endl;

   //EJERCICIO 3
   //Se declaran las tres matrices a operar.
       Eigen::Matrix2d m7;
       m7<< -3, -2,
              3, 3;
       Eigen::Matrix2d m8;
       m8 << 5, 3,
             9, 4;
       Eigen::Matrix2d m9;
       m9 << 1, 1,
             0, 0;

   //Se realiza el calculo y se imprime el resultado
   Eigen::Matrix2d aux = m7 * m8.transpose();
   Eigen::Matrix2d extra = aux.inverse();
   Eigen::Matrix2d result = m9 * extra;
   cout << "EJERCICIO #3: \n";
   cout << "A*X*B^T = C \n" << result << "\n" <<endl;

   //EJERCICIO 4
   //Se declaran las matrices a operar
   Eigen::Matrix2d m10;
   m10<< 2, 1,
       -4, -3;
   Eigen::Matrix2d m11;
   m11 << 2, 2,
          6, 4;

   //Se realiza el calculo y se imprime el resultado
   Eigen::Matrix2d aux2 = m10.inverse();
   cout << "EJERCICIO #4: \n";
   cout << "XA = B \n" << m11 * aux2 << "\n" <<endl;

   //EJERCICIO 5
   //Se declaran las matrices a operar

   Eigen::MatrixXf m12(2,3);
   m12<< 3, 0, -1,
        0, 2, 1;
   Eigen::MatrixXf m13(3,2);
   m13 << 1,2,
          1,0,
          0,6;
   Eigen::MatrixXf m14(2,2);
   m14 << -2, 0,
         -2, -5;

   //Se realiza el calculo y se imprime el resultado
   Eigen::MatrixXf op1 = m12 * m13;
   Eigen::MatrixXf op2 = m14 + op1;
   Eigen::MatrixXf op3 = 2 * op2;
   cout << "EJERCICIO #5: \n";
   cout << " X = 2(AB + C) \n" << op3 << "\n" <<endl;

   //EJERCICIO 6
   //Se declaran las matrices a operar
   Eigen::Matrix3d m15;
   m15<< 1, 5, -1,
        -1, 2, 2,
        0, -3, 3;
   Eigen::Matrix3d m16;
   m16 << -1, -4, 3,
          1, -2, -2,
          -3, 3, -5;

   //Se realiza el calculo y se imprime el resultado
   Eigen::Matrix3d m17 = m15 + (3 * m16) ;
   cout << "EJERCICIO #6: \n";
   cout << "A + 3B = X\n"<< m17  << "\n" <<endl;

   //EJERCICIO 7
   //Se declaran las matrices a operar

   Eigen::Matrix3d m18;
   m18<<  2, 7, 3,
          3, 9, 4,
          1, 5, 3;

   Eigen::Matrix3d m19;
   m19<<  1, 0, 2,
          0, 1, 0,
          0, 0, 1;

   //Se realiza el calculo y se imprime el resultado
   Eigen::Matrix3d auxx = m18.inverse();
   cout << "EJERCICIO #7: \n";
   cout << "XA = B \n" << m19 * auxx << "\n"  <<endl;

   //EJERCICIO 8
   //Se declaran las matrices a operar
   Eigen::Matrix3d m20;
   m20 <<  1, 1, 1,
           6, 5, 4,
         13, 10, 8;

   Eigen::Matrix3d m21;
   m21 <<  0, 1, 2,
           1, 0, 2,
           1, 2, 0;

   //Se realiza el calculo y se imprime el resultado
   Eigen::Matrix3d auxx2 = m20.inverse();
   Eigen::Matrix3d result2 = auxx2 * m21;
   cout << "EJERCICIO #8: \n";
   cout << "AX = B \n" << result2 << "\n" <<endl;

   //EJERCICIO 9
   //Se declaran las matrices a operar
   Eigen::Matrix2d m22;
   m22 <<  3, -1,
           0,  2;

   //Se realiza el calculo y se imprime el resultado
   Eigen::MatrixXd auxx3 = m22.transpose();
   Eigen::MatrixXd opt1 = auxx3 * m22;
   Eigen::MatrixXd opt2 = opt1 - (2 * m22);
   cout << "EJERCICIO #9: \n";
   cout << "A^T*A - 2A = X \n" << opt2 << "\n" <<endl;

   //EJERCICIO 10
   //Se declaran las matrices a operar
   Eigen::Matrix2d m23;
   m23 <<  4, 2,
          -1, 0;

   //Se realiza el calculo y se imprime el resultado
   Eigen::MatrixXd opt3 = m23 * m23;
   Eigen::MatrixXd opt4 = m23 * opt3;
   cout << "EJERCICIO #10: \n";
   cout << "A³ = X \n" << opt4 << "\n"  <<endl;

   //EJERCICIO 11
   //Se declaran las matrices a operar
   Eigen::Matrix2d m24;
   m24<<  2,4,
          3,2;

   Eigen::Matrix2d m25;
   m25<< 1,0,
         2,1;

   Eigen::Matrix2d m26;
   m26<< 7,5,
         6,1;

   //Se realiza el calculo y se imprime el resultado
   Eigen::MatrixXd o1 = m24.transpose() * m25;
   Eigen::MatrixXd o2 = m26 * o1.reverse();
   cout << "EJERCICIO #11: \n";
   cout << "a^T*XB = C \n" << o2 << "\n" <<endl;

   //EJERCICIO 12
   //Se declaran las matrices a operar
   Eigen::MatrixXd m27(2,3);
   m27<<  1, 0, -2,
          2, -1, 3;

   Eigen::MatrixXd m28(3,2);
   m28<<   2, -3,
           -2, 0,
           -1, -2;

   //Se realiza el calculo y se imprime el resultado
   Eigen::MatrixXd auxx4 = m27 * m27.transpose();
   Eigen::MatrixXd auxx5 = 2 * m27 * m28;
   Eigen::MatrixXd result3 =  auxx4 - auxx5;
   cout << "EJERCICIO #12: \n";
   cout << "AA^T - 2AB = X \n" << result3 << "\n" <<endl;

   //EJERCICIO 13
   //Se declaran las matrices a operar
   Eigen:: MatrixXd m29 (1,3);
   m29 << 4, 8, 12;

   Eigen:: MatrixXd m30 (3,2);
   m30 << 3, 2,
          0, 1,
         -1, 0;

   Eigen:: MatrixXd m31 (2,1);
   m31 << 4,
         -1;
   //Se realiza el calculo y se imprime el resultado
   Eigen:: MatrixxXd auxx6 = m29 * m30;
   Eigen:: MatrixxXd result7 = auxx6 * m31;
   cout << "EJERCICIO #13: \n";
   cout << "ABC = X \n" << result7 << "\n" <<endl;

   //EJERCICIO 14
   //Se declaran las matrices a operar
   Eigen::Matrix3d m32;
   m32<<  2, 5, 7,
          6, 3, 4,
          5, -2, -3;

   Eigen::Matrix3d m33;
   m33<< -1, 1, 0,
          0, 1, 1,
          1, 0, -1;

   //Se realiza el calculo y se imprime el resultado
   Eigen::MatrixXd result8 = m33 * m33.inverse();
   cout << "EJERCICIO #14: \n";
   cout << "XA = B \n" << result8 << "\n" <<endl;

   //EJERCICIO 15
   //Se declaran las matrices a operar

   Eigen::Matrix4d m34;
   m34<<  1, 1, 1, 1,
          1, 1, -1, -1,
          1, -1, 1, -1,
          1, -1, -1, 1;

   Eigen::Matrix4d m35;
   m35<<  1, 1, 0, 0,
          1, 0, 1, 0,
          1, 0, 0, 1,
          1, 0, 1, 1;

   //Se realiza el calculo y se imprime el resultado
   Eigen::Matrix4d multi = m34.inverse();
   Eigen::Matrix4d result9 = multi * m35;
   cout << "EJERCICIO #15: \n";
   cout << "AX = B \n" << result9 <<endl;

   return 0;
}

