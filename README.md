# Виртуальная функция

Создать абстрактный класс с виртуальной функцией «Норма». Создать
производные классы «Комплексные числа», «Вектор из 10 элементов», «Матрица
(2х2)». Определить функцию нормы: для комплексных чисел - модуль в квадрате, для
вектора - корень квадратный из суммы элементов по модулю, для матрицы -
максимальное значение по модулю

Создаю абстрактный класс Math (разделён на определение Math.h и реализацию
функции Math.cpp), в этом классе создаю функцию «Норма» с конструктором,
возможностью записи в файл и вывода из файла.
Создаю класс ComplexNumbers (для действительного числа) (также разделён на h /
cpp), в этот класс направляется 2 числа (действительная часть, мнимая часть), после
в классе ведётся расчёт комплексного числа по формуле $$\mid Z \mid ^2 = a^2 + b^2$$
Создаю класс MVector (для вектора) (также разделён на h / cpp), в этот класс
направляется 10 чисел, после в классе ведётся расчёт вектора из 10 элементов по
формуле $$\sqrt{\sum_{i=1}^{10}{a_{i}}}$$  
Создаю класс Matrix (для матрицы) (также разделён на h / cpp), в этот класс
направляется 4 числа, после в классе ведётся подсчёт матрицы.
