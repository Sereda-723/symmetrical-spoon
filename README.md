# symmetrical-spoon
Командная домашняя работа по алгоритмическим языкам, АС-23-04, сортировки

## Описание проекта
Проект представляет собой реализацию нескольких алгоритмов сортировки с последовательным доступом: 
- Heap Sort, by Aliev
- Insertion Sort, by Sereda
- Tree Sort, by Serbulova
- Merge Sort, by Batmanov
- Gnome Sort, by Nikitina
- Shaker Sort, by Yakimchik

Данные для тестирования:
- Лучший случай - данные уже отсортированы
- Худший случай - данные отсортированы в обратном порядке
- Случайные данные


### Инструкции по установке
1. Клонируйте репозиторий:
   ```bash
   git clone https://github.com/username/project.git
### Компиляция и запуск
```bash
g++ -Wall -Wextra -g3 -Werror main.cpp data_generator.cpp Heapsort_Aliev.cpp insertionSort_Sereda.cpp mergeSort_Batmanov.cpp BinaryTree_Serbulova.cpp gnomeSort_Nikitina.cpp ShakerSort_Yakimchik.cpp -o output/main.exe
