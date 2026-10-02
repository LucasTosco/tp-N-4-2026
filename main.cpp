#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//Defino los structs que voy a utilizar

struct ComandaHistorica
  {
  char  fecha[11];        // "DD-MM-AAAA"
  char  nombreMozo[50];   // el nombre completo, repetido en cada venta
  int   codigoProducto;
  int cantidad;
  float comision;
  };



struct Producto
{
    int codigo;
    char descripcion[50];
    float precio;
    int stockActual;
};

//Segun la consigna strcut auxiliares

struct Mozo
{
   int idMozo;
   char nombre[50];
   char password[20];
   float totalComision;
};



struct Comanda
{  int idMozo;
int codigoProducto;
int cantidad;
float comision;
};



//la constante de cuanto es la propina

const float TASA_COMISION = 0.10f;   // la comision de cada venta es el 10% de lo vendido


int main()
{
   // 1. Verificación de tamaño del struct (Exigido por la cátedra para no leer basura)
       if (sizeof(ComandaHistorica) != 76)
       {
           cout << "Error: El tamano de la estructura es de " << sizeof(ComandaHistorica)
                << " bytes y deberia ser 76." << endl;
           return 1;
       }

       // 2. Ruta directa al archivo de prueba que tenés disponible
       const char* rutaArchivo = "datos/comandas_historicas.dat";

       ifstream archivo(rutaArchivo, ios::binary);

       if (!archivo.is_open())
       {
           cout << " no se pudo abrir el archivo " << rutaArchivo << endl;
           return 1;
       }

       cout << " Archivo binario cargado " << endl;

       //bucle de lectura registro por registro
       ComandaHistorica reg;
       int contadorRegistros = 0;

       while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(ComandaHistorica)))
       {
           contadorRegistros++;
       }

       archivo.close();

       cout << " Total de registros procesados: " << contadorRegistros << endl;

       return 0;

}
