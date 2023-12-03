#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// Método de luminosidad para la conversión a escala de grises
void convertirAByN(Mat& imagenEntrada, Mat& imagenSalida) {
    // Iterar sobre cada píxel de la imagen
    #pragma omp parallel for
    for (int r = 0; r < imagenEntrada.rows; r++) {
        for (int c = 0; c < imagenEntrada.cols; c++) {
            Point3_<uchar>* p = imagenEntrada.ptr<Point3_<uchar>>(r, c);

            // Calcular el valor de luminosidad (escala de grises) y asignarlo al píxel en la nueva imagen
            uchar valorGris = static_cast<uchar>(0.299 * p->x + 0.587 * p->y + 0.114 * p->z);

            imagenSalida.at<uchar>(r, c) = valorGris;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " tyler.jpg output_openmp.jpg" << endl;
        return 1;
    }

    Mat imagenEntrada = imread(argv[1], IMREAD_COLOR);

    if (imagenEntrada.empty()) {
        cerr << "Error: No se pudo abrir o encontrar la imagen." << endl;
        return 1;
    }

    // Crear la imagen de salida en escala de grises
    Mat imagenSalida(imagenEntrada.rows, imagenEntrada.cols, CV_8UC1);

    // Medir el tiempo de ejecución usando la clase chrono
    auto inicio = chrono::high_resolution_clock::now();

    // Implementar la conversión a escala de grises con OpenMP
    convertirAByN(imagenEntrada, imagenSalida);

    auto fin = chrono::high_resolution_clock::now();
    auto duracion = chrono::duration_cast<chrono::milliseconds>(fin - inicio);

    cout << "Conversión completada en " << duracion.count() << " milisegundos." << endl;

    // Guardar la imagen de salida en escala de grises
    imwrite(argv[2], imagenSalida);

    return 0;
}
