#include <iostream>
using namespace std;
 
class Time {
   private:
      int hours;             // 0 to 23
      int minutes;           // 0 to 59
      
   public:
      // required constructors
      Time() {
         hours = 0;
         minutes = 0;
      }
      Tiempo(int h, int m) {
         horas = h;
         minutos = m;
      }
      
      // Método para mostrar la hora
      void mostrarTiempo() {
         cout << "Hora: " << horas << " Minutos: " << minutos << endl;
      }
      
      // Operador de incremento prefijo
      Tiempo operator++ () {
         // Incrementamos los minutos
         ++minutos;
         // Si los minutos superan 60, incrementamos la hora y restamos 60 minutos
         if(minutos >= 60) {
            ++horas;
            minutos -= 60;
         }
         // Devolvemos el nuevo objeto con la hora actualizada
         return Tiempo(horas, minutos);
      }
      
      // Operador de incremento posfijo
      Tiempo operator++( int ) {
         // Guardamos el valor original antes del incremento
         Tiempo T(horas, minutos);
         
         // Incrementamos los minutos
         ++minutos; 
         //minutos++=5;                   
         
         // Si los minutos superan 60, incrementamos la hora y restamos 60 minutos
         if(minutos >= 60) {
            ++horas;
            minutos -= 60;
         }
         
         // Devolvemos el valor original antes del incremento
         return T; 
      }
};

int main() {
   // Creamos dos objetos de la clase Tiempo: T1 con 11:59 y T2 con 10:40
   Tiempo T1(11, 59), T2(10,40);

   // Incrementamos T1 usando el operador ++ prefijo
   ++T1;                    // Esto incrementará T1 en 1 minuto

   // Mostramos la nueva hora de T1
   T1.mostrarTiempo();        // Mostrará la hora actualizada de T1

   // Ahora incrementamos T1 usando el operador ++ posfijo
   Tiempo T3 = T1++;          // Esto incrementará T1 pero devolverá el valor anterior

   // Mostramos los resultados
   cout << "\nDespués de los incrementos:" << endl;
   cout << "T1 (incremento prefijo):";
   T1.mostrarTiempo();        // Mostrará la hora final de T1
   cout << "T3 (valor antes del incremento posfijo):";
   T3.mostrarTiempo();        // Mostrará el valor original antes del incremento posfijo

   return 0;
}
