/*********************
 * Fecha: 8 de agosto de 2022
 * Autor: Mitchell Bemrin
 * Tema: Introducccion al algebra lineal con EIGEN
 * Materia: introduccion a la HPC
 * **********************/

#include <iostream>
#include<vector>
#include <eigen3/Eigen/Dense>

/*Se crean los tipos de daots personalizados*/
// Tipo de datos matriz 3x3 flotante
typedef Eigen::Matrix<float,3,3> MiMatriz3x3f;

//Tipo de dato vector 3 flotante
typedef Eigen::Matrix<float,3,1> MiVector3x3f;

//Tipo de dato matriz nxn flotante
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> MiMatrizd;

int main()
{
    //Se declara las variables de llos tipos anteriores
    MiMatriz3x3f mA;
    MiVector3x3f vB;
    MiMatrizd mDyn(10,15);

    //Se inicializan las variables anteriores

    std::cout << "=='Se inicializan las variables anteriores'==" << std::endl;
    //mA en ceros
    mA = MiMatriz3x3f::Zero();
    std::cout << "\n mA en ceros \n" << mA <<std::endl;

    //mA en identidad
    mA = MiMatriz3x3f::Identity();
    std::cout << "\n mA en identidad \n" << mA << std::endl;

    //vB inicializado en numeros aleatorios
    vB = MiVector3x3f::Random();
    std::cout << "\n vB aleatorio \n" << vB << std::endl;

    //Se inicializa manualmenta la mA
    mA << 1,2,3,4,5,6,7,8,9;
    std::cout << "\n mA Manualmente \n" << mA << std::endl;

    mA(1,1) = 10;
    std::cout << "\n mA Manualmente arreglo 1\n" << mA << std::endl;

    //Se imprime la Matriz transpuesta
    std::cout << "\n mA Manualmente arreglo 2\n" << mA.transpose() << std::endl;

    //Se imprime de nuevo la matriz
    std::cout << "\n mA Manualmente arreglo 3\n" << mA << std::endl;

    //Se sobreescribe sobre matriz transpuesta
    mA.transposeInPlace();
    std::cout << "\n mA Manualmente arreglo 4\n" << mA << std::endl;

    std::cout << "=='Funcion MAP'==" <<std::endl;

    //Se crea una data int
    int datosInt[]= {1,2,3,4};

    //Se mapea en un Vector de enteros (4x1)
    Eigen::Map<Eigen::RowVectorXi> v_map(datosInt,4);
    std::cout << "\n Vector map \n" << v_map << std::endl;

    //Se mapea en una Matriz dada en un vector flotante
    std::vector<float> vDatos = {1,2,3,5,4,3,1,3,4};

    Eigen::Map<MiMatriz3x3f> M_map(vDatos.data());
    std::cout << "\n Matriz map \n" << M_map << std::endl;

    std::cout << "=='Aritmetica'==" << std::endl;
    //Se crean dos matrices 2x2
    Eigen::Matrix2d a;
    a << 1,2,3,4;

    Eigen::Matrix2d b;
    b << 0,1,1,0;

    Eigen::Matrix2d resultado;

    //Se imprimen las matrices anteriores
    std::cout << "\n Matriz a \n" << a << std::endl;
    std::cout << "\n Matriz B\n" << b << std::endl;

    std::cout << "==' Operaciones Elemente Wise '==" << std::endl;
    resultado = a.array() + b.array();

    std::cout << "==' Suma element wise a + b'==" << std::endl;
    std::cout << "\n Matriz Resultado\n" << resultado << std::endl;

    std::cout << "==' Operaciones Elemente Wise '==" << std::endl;
    resultado = a.array() - b.array();

    std::cout << "==' Resta element wise a - b'==" << std::endl;
    std::cout << "\n Matriz Resultado\n" << resultado << std::endl;

    std::cout << "==' Operaciones Elemente Wise '==" << std::endl;
    resultado = a.array() * b.array();

    std::cout << "==' Multiplicacion element wise a * b'==" << std::endl;
    std::cout << "\n Matriz Resultado\n" << resultado << std::endl;

    std::cout << "==' Operaciones Elemente Wise '==" << std::endl;
    resultado = a.array() / b.array();

    std::cout << "==' Division element wise a / b'=="  << std::endl;
    std::cout << "\n Matriz Resultado\n" << resultado << std::endl;

    //Se requiere que la matriz b se multiplicada por 4
    resultado = 4 * b.array();

    std::cout << "==' Multiplicacion element wise 4 * b'==" << std::endl;
    std::cout << "\n Matriz Resultado\n" << resultado << std::endl;

    std::cout << "=='Acceso parcial a las estructuras'==" << std::endl;
    //Se crea una matriz con numeros aleatorios
     Eigen::MatrixXf matrizDinamica = Eigen::MatrixXf::Random(4,4);
     std::cout << "\n Matriz Aleatoria\n" << matrizDinamica << std::endl;


    //Se requiere extraer el bloque central de la matriz anterior
     Eigen::MatrixXf matrizDinamica02 = Eigen::MatrixXf::Random(6,6);
     std::cout << "\n Matriz Aleatoria 6x6 \n" << matrizDinamica02 << std::endl;

     //Copia matriz
     Eigen::Matrix2f m_bloque;
     m_bloque = matrizDinamica02.block(2,2,2,2);
     std::cout << "\n Matriz Vacia extrayendo el bloque de la matriz anterior\n" << m_bloque<< std::endl;

    //Bloque 4x3
    Eigen::MatrixXf  m_bloque2(4,3);
    m_bloque2 = matrizDinamica02.block(2,2,4,3);
    std::cout << "\n Matriz Vacia extrayendo el bloque de la matriz anterior\n" << m_bloque2<< std::endl;

    //Se requiere que el bloque de 2x2 inicial de la matriz aleatoria sea 0
    matrizDinamica02.block(0,0,2,2) *= 0;
    std::cout << "\n Matriz Vacia extrayendo el bloque de la matriz anterior\n" << matrizDinamica02<< std::endl;

    //Se quiere que la fila 3 de la matriz aleatoriase le sume -4
    matrizDinamica02.row(2).array() += -4;
    std::cout << "\n Matriz aleatoria\n" << matrizDinamica02<< std::endl;

    //Se quiere que la columna 5 de la matriz aleatoriase le sume 5
    matrizDinamica02.col(3).array() += 5;
    std::cout << "\n Matriz aleatoria\n" << matrizDinamica02<< std::endl;

    //Se reuqire que la ultima columna sea dividida entre 0
    matrizDinamica02.col(5).array() /= 0;
    std::cout << "\n Matriz aleatoria\n" << matrizDinamica02<< std::endl;

    //BROADCASTING: TRASMISION
    //Se crea una matriza aleatoria 2x4
    Eigen::MatrixXf mat_transmi = Eigen:: MatrixXf:: Random(2,4);
    std::cout << "\n Matriz aleatoria 2x4\n" << mat_transmi<< std::endl;

    //Se crea un vector por columnas
    Eigen::VectorXf Vec_transmi(2);
    Vec_transmi << 100, 100;
    std::cout << "\n Vector\n" << Vec_transmi << std::endl;

    //Se trasmite por columna a cada elemento
    mat_transmi.colwise() += Vec_transmi;
    std::cout << "\n Matriz suma por columna broadcast \n" << mat_transmi<< std::endl;

    //Operaciones de reduccion sobre Matrices y vectores
    //Se crea una matriz doble 3x3
    Eigen::Matrix3d m_reduction;
    m_reduction << 3,4,5,
                   6,7,8,
                   3,2,1;
    std::cout << "\n Operaciones de Reduccion\n" << m_reduction<< std::endl;

    //reduccion sum() suma cada elemento de la matriz o vector
    std::cout << "\n Reduccion sum()\n" << m_reduction.sum()<< std::endl;

    //reduccion prod() multiplicacion cada elemento de la matriz o vector
    std::cout << "\n Reduccion prod()\n" << m_reduction.prod()<< std::endl;

    //reduccion mean() promedio cada elemento de la matriz o vector
    std::cout << "\n Reduccion mean()\n" << m_reduction.mean()<< std::endl;

    //reduccion minCoeff() coheficiente minimo cada elemento de la matriz o vector
    std::cout << "\n Reduccion minCoeff()\n" << m_reduction.minCoeff()<< std::endl;

    //reduccion maxCoeff() coheficiente maximo cada elemento de la matriz o vector
    std::cout << "\n Reduccion maxCoeff()\n" << m_reduction.maxCoeff()<< std::endl;

    //reduccion trace() sumatoria de la diagonal principal cada elemento de la matriz
    std::cout << "\n Reduccion trace()\n" << m_reduction.trace()<< std::endl;
    return 0;
}

