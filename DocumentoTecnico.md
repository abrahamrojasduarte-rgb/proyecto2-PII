1. Descripción General del Sistema
   Soul Knight es un motor de simulación en consola que modela una aventura de exploración de mazmorras. El sistema carga datos desde archivos de texto, construye una representación interna del mundo compuesto por niveles, salas, enemigos, items y eventos, y ejecuta una simulación donde el estado cambia dinámicamente según las reglas implementadas.

El programa no es un videojuego gráfico; es una simulación orientada a objetos donde cada componente del mundo tiene responsabilidades claras y el comportamiento emergente resulta de la interacción entre objetos.

2. Temática de la Aventura
   Ambientación de fantasía medieval oscura. Un héroe solitario explora tres niveles de mazmorras subterráneas infestadas de criaturas (esqueletos, goblins, zombis) con el objetivo de derrotar a los tres jefes que controlan cada nivel.

3. Formato de los Archivos de Entrada\
   characters.txt\
   Knight 120 15\
   Wizard 80 25\
   Rogue 90 20\
   Priest 100 10\
   Formato: nombre salud ataque (separados por espacio)\

enemies.txt\
Goblin 25 5\
Skeleton 30 6\
SkeletonKing 100 18\
Formato: nombre salud ataque (separados por espacio). Enemigos con salud >= 80 se clasifican automáticamente como jefes.

events.txt\
Spike Trap|You stepped on a hidden spike trap!|0|15\
Formato: nombre|descripcion|tipo|valor (separados por |). Tipos: 0=trampa, 1=tesoro, 2=descanso, 3=misterio.\

items.txt\
weapon|Iron Sword|12|A sturdy iron blade\
potion|Small Potion|20|Restores a small amount of HP\
Formato: tipo|nombre|valor|descripcion (separados por |).

4. Principales Clases y Relaciones
   Diagrama de Herencia\
   Entity (abstracta)\
   ├── Characters (jugador)\
   └── Enemy (enemigo)\

Room (abstracta)\
├── SimpleRoom\
└── BossRoom\

Ability (abstracta)\
├── KnightAbility\
├── WizardAbility\
├── RogueAbility\
└── PriestAbility\
Relaciones entre Clases\
Relación	Tipo	Descripción\
Characters → Ability	Composición	Cada personaje posee una habilidad\
Characters → Inventory	Composición	Cada personaje tiene un inventario\
Level → Room*	Agregación	Un nivel contiene múltiples salas\
GameEngine → Level*	Agregación	El motor gestiona múltiples niveles\
GameEngine → Characters	Composición	El motor contiene al jugador\
GameEngine → Logger	Composición	El motor contiene el logger\
GameEngine → EventSystem	Composición	El motor contiene el sistema de eventos\
GameEngine → ItemManager	Composición	El motor contiene el gestor de items\
CombatSystem	Utilidad estática	Resuelve combates entre entidades\
CharacterManager	Fábrica	Carga y crea personajes desde archivo\
EnemyManager	Fábrica	Carga y crea enemigos desde archivo
5. Decisiones Relevantes de Diseño
   5.1 Patrón Strategy para Habilidades
   Se implementó el patrón Strategy mediante la clase abstracta Ability con métodos virtuales onAttack(), onDefense() y onTurn(). Cada clase de personaje tiene una implementación concreta que modifica el comportamiento del combate sin alterar la lógica del CombatSystem.

Justificación: Permite agregar nuevas clases de personaje sin modificar el sistema de combate existente (principio Open/Closed).

5.2 Clase Template Item
La clase Item utiliza programación genérica para permitir items con diferentes tipos de valor. Actualmente se usa Item<int> para armas (bonus de ataque) y pociones (puntos de curación).

Justificación: Demuestra el uso de templates y permite extensibilidad futura (por ejemplo, Item<string> para items con efectos descriptivos).

5.3 Iterador Personalizado en Inventory\
La clase Inventory implementa un iterador personalizado que permite recorrer todos los items (armas y pociones) de forma uniforme usando la interfaz begin()/end().

Justificación: Demuestra comprensión de iteradores y permite recorrer el inventario con range-based for loops.

5.4 Polimorfismo en Rooms\
Las salas (Room) son abstractas con dos implementaciones concretas: SimpleRoom (genera enemigos aleatorios) y BossRoom (genera un jefe específico). El Level trabaja con punteros a Room sin conocer el tipo concreto.

Justificación: Permite agregar nuevos tipos de sala (sala de trampa, sala de tesoro) sin modificar la lógica del nivel.

5.5 Sistema de Eventos\
El EventSystem carga eventos desde archivo y los activa con probabilidad configurable. Cada evento tiene un tipo y un valor que modifica el estado del jugador.

Justificación: Agrega variabilidad a la simulación y demuestra carga de datos estructurados desde archivo con validación.

5.6 Sobrecarga de Operadores\
Se implementó sobrecarga de operadores en múltiples clases:

Entity: operadores ==, <, > para comparación, y << para inserción en stream.\
Characters: operadores += (curación) y -= (daño).\
Item<T>: operadores ==, <, > para comparación de items, y << para display.\
Inventory: operador << para mostrar el contenido.\
Justificación: Mejora la expresividad del código y la integración con la biblioteca estándar.

6. Estrategia de Manejo de Memoria y Recursos
   Memoria Dinámica
   Los niveles (Level) gestionan salas mediante punteros raw (Room*) con liberación explícita en el destructor.\
   El GameEngine libera los niveles en su destructor.\
   Las habilidades (Ability*) son liberadas por el destructor de Characters.
   Principio RAII
   Logger abre el archivo en el constructor y lo cierra en close().\
   Los managers (CharacterManager, EnemyManager) cargan datos en el constructor.\
   ofstream se usa con scope controlado en generateReport().\
   Prevención de Fugas
   Cada clase que posee memoria dinámica implementa un destructor apropiado.\
   Se evitan copias innecesarias de objetos grandes usando referencias. 
7. Manejo de Archivos y Errores\
   Archivos\
   Todos los archivos se acceden mediante rutas relativas.\
   Se valida la apertura exitosa de cada archivo antes de leerlo.\
   Se validan los datos leídos (valores positivos, formatos correctos).\
   Los archivos de salida (log.txt, report.txt) se generan automáticamente.\
   Excepciones
   runtime_error: archivos no encontrados, enemigos no encontrados.\
   invalid_argument: datos inválidos, selección fuera de rango.\
   main() captura excepciones con handlers específicos por tipo.\
   Se usa cin.fail() para validar entrada del usuario con recuperación.
8. Técnicas del Curso Utilizadas\
   Técnica	Uso en el Proyecto	Justificación\
   Herencia	Entity→Characters/Enemy, Room→SimpleRoom/BossRoom, Ability→*Ability	Modelar jerarquías naturales del dominio\
   Polimorfismo	Room*, Ability* con métodos virtuales	Comportamiento dinámico sin conocer tipo concreto\
   Clases abstractas	Entity, Room, Ability	Definir interfaces y contratos\
   Templates	Item	Genericidad para items con diferentes tipos de valor\
   Iteradores	Inventory::Iterator	Recorrido uniforme de contenedor personalizado\
   Sobrecarga de operadores	==, <, >, +=, -=, <<	Expresividad y integración con STL\
   Manejo de archivos	ifstream/ofstream en managers y logger	Persistencia y carga de datos\
   Excepciones	try/catch con tipos específicos	Control robusto de errores\
   Patrón Strategy	Ability y sus implementaciones	Comportamiento intercambiable en combate\
   Patrón Factory	CharacterManager, EnemyManager	Creación de objetos desde datos externos\
   STL containers	vector, string, mt19937	Almacenamiento eficiente y generación aleatoria\
   Encapsulamiento	Atributos privados con getters/setters	Protección del estado interno\
9. Evidencia de Ejecución\
   Salida de consola (ejemplo)\
   ║           SOUL KNIGHT                ║\
   ║     Dungeon Adventure Simulator      ║


Choose your hero:\
+------+------------+--------+--------+\
| #    | Name       | Health | Attack |\
+------+------------+--------+--------+\
| 1    | Knight     | 120    | 15     |\
| 2    | Wizard     | 80     | 25     |\
| 3    | Rogue      | 90     | 20     |\
| 4    | Priest     | 100    | 10     |\
+------+------------+--------+--------+\

Select character (1-4): 2\
Archivos generados\
log.txt: Bitácora completa con entradas numeradas\
report.txt: Reporte final con estadísticas de la aventura
10. Limitaciones y Posibles Mejoras\
    Limitaciones Actuales\
    El recorrido es lineal (no hay bifurcaciones ni elección de camino).\
    No hay sistema de guardado/carga de partida.\
    Los items se usan inmediatamente en lugar de almacenarse para uso posterior.\
    La interfaz es puramente textual.
    Posibles Mejoras
    Implementar un mapa con grafos para exploración no lineal.\
    Agregar sistema de guardado usando serialización.\
    Implementar un inventario activo donde el jugador elija cuándo usar items.\
    Agregar más tipos de sala (tienda, trampa, puzzle).\
    Implementar smart pointers (unique_ptr) para gestión automática de memoria.\
    Agregar sistema de logros/achievements.