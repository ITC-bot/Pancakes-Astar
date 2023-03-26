# Juegos-de-los-Pancakes-aplicando-Astar
Juego de los pancakes (pancake sorting) aplicando el algoritmo A* el cual es una mejora del de búsqueda de amplitud pero con heuristicas

Hecho por Marcos Zacarias, ITC-TM, Universidad Autonoma de Baja California Sur

Pequeña explicacion de las funciones:

--"void voltear(string& pancakes, int k)" Esta función recibe una cadena de caracteres, en este caso, los pancakes, y un entero k, y voltea los primeros k caracteres de la cadena. Se utiliza para simular la acción de voltear un número determinado de pancakes en una pila.

--"bool esta_ordenada(string pancakes)" Esta función recibe una cadena de caracteres pancakes y devuelve true si la cadena está ordenada de forma ascendente, es decir, si cada caracter es mayor o igual al caracter que le precede en la cadena. Se llama para verificar si el parametro que recibe esta ordenado.

--"vector generar_sucesores(string pancakes)" Esta función recibe una cadena de caracteres pancakes y devuelve un vector de cadenas de caracteres, son las posibles opciones de voltear distintos numeros de pancakes del arreglo. Se usa para generas sucesores de la cadena actual que recibe y los agrega a la cola de busqueda.

--"string generar_caracteres_aleatorios(int n)" Esta función recibe un entero n y devuelve una cadena de caracteres de longitud n, se usa para generar caracteres aleatorios, asi ahorrando estar pidiendo al usuario que se ingrese caracter por caracter.

--"int h4(const string& pancakes, const string& target)"
Esta función es la heurística utilizada por el algoritmo de búsqueda A*. Recibe dos cadenas de caracteres, pancakes y target, y devuelve un entero que representa el costo estimado desde pancakes hasta target. La heurística utilizada es la siguiente: para cada posición de pancakes, si el caracter en esa posición es diferente al caracter correspondiente en target, se suma 1 al costo. Además, si hay dos caracteres consecutivos en pancakes que están separados por más de una posición en target, se suma 1 al costo. Por ejemplo, si pancakes es "adcbe" y target es "abcde", el costo estimado será 2, ya que hay dos caracteres diferentes ("d" y "b") y un par de caracteres consecutivos separados por más de una posición ("c" y "e").

--"void a_star(string pancakes)"
Esta función es la implementación del algoritmo de búsqueda A*. Recibe una cadena de caracteres pancakes y busca la solución para ordenarla utilizando la heurística h4. La función utiliza una cola de prioridad (priority_queue) para mantener los nodos a explorar, ordenados según el costo estimado de la solución (costo actual más costo estimado restante). La función también utiliza un conjunto (unordered_set) para almacenar los nodos visitados y evitar explorar nodos repetidos. La función comienza explorando pancakes y generando sus sucesores mediante la función generar_sucesores. Para cada sucesor, se calcula el costo estimado utilizando la función h4 y se añade a la cola de prioridad si no ha sido visitado antes. La función sigue explorando nodos hasta que encuentra la solución (ordenación) o hasta que la cola de prioridad está vacía.

--"int main()" Esta es la función principal del programa. Solicita al usuario el número de caracteres de la pila de pancakes, genera una configuración aleatoria de pancakes utilizando la función generar_caracteres_aleatorios y llama a la función bfs para llevar a cabo la búsqueda por amplitud.
