# Седмица 2
# Структури. Разположение в паметта. Битови полета. Разделна компилация.



<div align="justify">



## Задача 1 🟡 (Точки) 🟠

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/easy-green)

### 📖 Описание:

Създайте програма, която има реализирана структура за точка от тримерното евклидово пространство. Програмата да прочита стойностите на три точки от стандартния вход и да извежда на стандартния изход периметъра и лицето на триъгълника, описан с тези три точки. Също така за триъгълника да се изведе информация за типа му спрямо страните му - равнобедрен, равностранен, разностранен, както и да се върне типа на триъгълника спрямо ъглите му - остроъгълен, правоъгълен, тъпоъгълен.

### 💡 Примери:

```txt
Enter the coordinates of the point: 1 0 0
Enter the coordinates of the point: 0 1 0
Enter the coordinates of the point: 0 0 1

The PERIMETER   of the triangle is: 4.242641
The AREA        of the triangle is: 0.866025
```

```txt
Enter the coordinates of the point: -1  0  0
Enter the coordinates of the point:  0 -1  0
Enter the coordinates of the point:  0  0 -1

The PERIMETER   of the triangle is: 4.242641
The AREA        of the triangle is: 0.866025
```

```txt
Enter the coordinates of the point: 3 3 0
Enter the coordinates of the point: 3 0 3
Enter the coordinates of the point: 0 3 3

The PERIMETER   of the triangle is: 12.727922
The AREA        of the triangle is: 7.794229
```


## Задача 2 ➡️ (Вектори) ⬅️

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/easy-green)

### 📖 Описание:

Създайте програма, която има реализирана структура за вектор от тримерното евклидово пространство. Реализирайте съответните методи за инициализиране на вектор от стандартния вход, за извеждане на вектор на стандартния изход, за събиране на два вектора, за умножение на вектори поелементно, за умножение на вектор със скалар.

### 💡 Примери:

В показаните примери първият резултат е сумата на `Vector 1` и `Vector 2`. В показаните примери вторият резултат е произведението на `Vector 1` и `Vector 2`. В показаните примери третият резултат е произведението на `Vector 3` и `number`.

```txt
Enter the data for Vector 1: 1 0 0
Enter the data for Vector 2: 0 1 0
Enter the data for Vector 3: 0 0 1

Enter the number: 3

The vector is: ( X: 1.000; Y: 1.000; Z: 1.000; )
The vector is: ( X: 0.000; Y: 0.000; Z: 0.000; )
The vector is: ( X: 0.000; Y: 0.000; Z: 3.000; )
```

```txt
Enter the data for Vector 1: -1 -1 -1
Enter the data for Vector 2: -1 -1 -1
Enter the data for Vector 3:  3  7  9

Enter the number: 1

The vector is: ( X: -2.000; Y: -2.000; Z: -2.000; )
The vector is: ( X:  1.000; Y:  1.000; Z:  1.000; )
The vector is: ( X:  3.000; Y:  7.000; Z:  9.000; )
```

```txt
Enter the data for Vector 1:  1  0 -1
Enter the data for Vector 2: -1  0  1
Enter the data for vector 3:  9  9  9

Enter the number: 0.5

The vector is: ( X:  0.000; Y: 0.000; Z:  0.000; )
The vector is: ( X: -1.000; Y: 0.000; Z: -1.000; )
The vector is: ( X:  4.500; Y: 4.500; Z:  4.500; )
```


## Задача 3 ℹ️ (Комплексни Числа) ℹ️

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/easy-green)

### 📖 Описание:

Създайте програма, която има реализирана структура за комплексно число. Реализирайте съответните методи за аритметични действия над комплексни числа. Реализирайте функция, която да връща комплексно-спрегнатото на дадено комплексно число. Реализирайте и функции, които да проверяват дали числото е реално или чисто имагинерно. Реализирайте функции, които да могат да сравняват дали две комплексни числа са равни или не са равни. Демонстрирайте работата на всеки метод във вашата програма.

### 💡 Примери:

В показаните примери първият резултат е сумата на `Complex Number 1` и `Complex Number 2`. В показаните примери вторият резултат е разликата на `Complex Number 2` и `Complex Number 3`. В показаните примери третият резултат е произведението на `Complex Number 3` и `Complex Number 4`. В показаните примери четвъртият пример е частното на `Complex Number 4` и `Complex Number 1`.

```txt
Enter the data for Complex Number 1: 1 0
Enter the data for Complex Number 2: 0 1
Enter the data for Complex Number 3: 1 1
Enter the data for Complex Number 4: 0 0

The Complex Number is: ( Re:  1.000; Im: 1.000; )
The Complex Number is: ( Re: -1.000; Im: 0.000; )
The Complex Number is: ( Re:  0.000; Im: 0.000; )
The Complex Number is: ( Re:  0.000; Im: 0.000; )

The kind of Complex Number 1 is: REAL
The kind of Complex Number 2 is: IMAG
The kind of Complex Number 3 is: CMPL
The kind of Complex Number 4 is: REAL
```

```txt
Enter the data for Complex Number 1: 5 4
Enter the data for Complex Number 2: 4 5
Enter the data for Complex Number 3: 3 7
Enter the data for Complex Number 4: 1 9

The Complex Number is: ( Re:   9.000; Im:  9.000; )
The Complex Number is: ( Re:   1.000; Im: -2.000; )
The Complex Number is: ( Re: -60.000; Im: 34.000; )
The Complex Number is: ( Re:   1.000; Im:  1.000; )

The kind of Complex Number 1 is: CMPL
The kind of Complex Number 2 is: CMPL
The kind of Complex Number 3 is: CMPL
The kind of Complex Number 4 is: CMPL
```

```txt
Enter the data for Complex Number 1: 0.5 0.5
Enter the data for Complex Number 2: 1.5 1.5
Enter the data for Complex Number 3: 4.5 4.5
Enter the data for Complex Number 4: 3.5 3.5

The Complex Number is: ( Re:  2.000; Im:  2.000; )
The Complex Number is: ( Re: -3.000; Im: -3.000; )
The Complex Number is: ( Re:  0.000; Im: 31.500; )
The Complex Number is: ( Re:  7.000; Im:  0.000; )

The kind of Complex Number 1 is: CMPL
The kind of Complex Number 2 is: CMPL
The kind of Complex Number 3 is: CMPL
The kind of Complex Number 4 is: CMPL
```


## Задача 4 🥷🏻 (Нинджи) 🥷🏻

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/easy-green)

### 📖 Описание:

Създайте програма, която има реализирана структура `Ninja`, която има първо име, трето име, вид колан, вид оръжие, както и пол. Първото име има максимален размер от `256` символа. Третото име има максимален размер от `256` символа. Видът колан да е изброен тип по преценка на програмиста. Видът оръжие да е изброен тип по преценка на програмиста. Полът да бъде булев резултат. Реализирайте функции за създаване на нинджа, за извеждане на информацията за нинджа на стандартния изход, за филтриране на нинджи по вид колан, за филтриране на нинджи по вид оръжие, за филтриране на нинджи по пол. Приемете, че данните за филтрите са валидни.

Направете съответните проверки за това дали нинджата има коректно зададено първо име и коректно зададено трето име. Всяко име трябва да е непразно, да не съдържа цифри, да не съдържа невалидни символи и да използва конвенцията за имена, т.е. първата буква е главна латинска буква, а останалите букви са малки латински букви.

### 💡 Примери:

```txt
Enter the number of ninjas: 3


Enter the ninjas in your program:

Enter the first name    of the ninja: Hattori
Enter the third name    of the ninja: Hanzo
Enter the belt          of the ninja: Black
Enter the weapon        of the ninja: Katana
Enter the gender        of the ninja: 1

Enter the first name    of the ninja: Ishikawa
Enter the third name    of the ninja: Goemon
Enter the belt          of the ninja: White
Enter the weapon        of the ninja: Sai
Enter the gender        of the ninja: 1

Enter the first name    of the ninja: Fuma
Enter the third name    of the ninja: Kotaro
Enter the belt          of the ninja: Red
Enter the weapon        of the ninja: Nunchaku
Enter the gender        of the ninja: 1


Enter the filter of the ninjas:
1. Belt
2. Weapon
3. Gender

Enter the option from the menu: 1

Input the string: Black

The ninjas in your program are:

The first name  of the ninja is: Hattori
The third name  of the ninja is: Hanzo
The belt        of the ninja is: Black
The weapon      of the ninja is: Katana
The gender      of the ninja is: MALE
```

```txt
Enter the number of ninjas: 7


Enter the ninjas in your program:

Enter the first name    of the ninja: Leonardo
Enter the third name    of the ninja: San
Enter the belt          of the ninja: Black
Enter the weapon        of the ninja: Katana
Enter the gender        of the ninja: 1

Enter the first name    of the ninja: Raphael
Enter the third name    of the ninja: San
Enter the belt          of the ninja: Black
Enter the weapon        of the ninja: Sai
Enter the gender        of the ninja: 1

Enter the first name    of the ninja: Donatello
Enter the third name    of the ninja: San
Enter the belt          of the ninja: Black
Enter the weapon        of the ninja: BoStaff
Enter the gender        of the ninja: 1

Enter the first name    of the ninja: Michelangelo
Enter the third name    of the ninja: San
Enter the belt          of the ninja: Black
Enter the weapon        of the ninja: Nunchaku
Enter the gender        of the ninja: 1

Enter the first name    of the ninja: Splinter
Enter the third name    of the ninja: San
Enter the belt          of the ninja: Black
Enter the weapon        of the ninja: Naginata
Enter the gender        of the ninja: 1

Enter the first name    of the ninja: Karai
Enter the third name    of the ninja: Saki
Enter the belt          of the ninja: Black
Enter the weapon        of the ninja: Katana
Enter the gender        of the ninja: 0

Enter the first name    of the ninja: April
Enter the third name    of the ninja: O'Neil
Enter the belt          of the ninja: Green
Enter the weapon        of the ninja: Sai
Enter the gender        of the ninja: 0


Enter the filter of the ninjas:

1. Belt
2. Weapon
3. Gender

Enter the option from the menu: 2

Input the string: Katana

The ninjas in your program are:

The first name  of the ninja is: Leonardo
The third name  of the ninja is: San
The belt        of the ninja is: Black
The weapon      of the ninja is: Katana
The gender      of the ninja is: MALE

The first name  of the ninja is: Karai
The third name  of the ninja is: Saki
The belt        of the ninja is: Black
The weapon      of the ninja is: Katana
The gender      of the ninja is: FEMALE
```

```txt
Enter the number of ninjas: 9

Enter the ninjas in your program:

Enter the first name    of the ninja: Leonardo
Enter the third name    of the ninja: San
Enter the belt          of the ninja: Black
Enter the weapon        of the ninja: Katana
Enter the gender        of the ninja: 1

Enter the first name    of the ninja: Raphael
Enter the third name    of the ninja: San
Enter the belt          of the ninja: Black
Enter the weapon        of the ninja: Sai
Enter the gender        of the ninja: 1

Enter the first name    of the ninja: Donatello
Enter the third name    of the ninja: San
Enter the belt          of the ninja: Black
Enter the weapon        of the ninja: BoStaff
Enter the gender        of the ninja: 1

Enter the first name    of the ninja: Michelangelo
Enter the third name    of the ninja: San
Enter the belt          of the ninja: Black
Enter the weapon        of the ninja: Nunchaku
Enter the gender        of the ninja: 1

Enter the first name    of the ninja: Oroku
Enter the third name    of the ninja: Saki
Enter the belt          of the ninja: Black
Enter the weapon        of the ninja: Claws
Enter the gender        of the ninja: 1

Enter the first name    of the ninja: Miyamoto
Enter the third name    of the ninja: Usagi
Enter the belt          of the ninja: Black
Enter the weapon        of the ninja: Katana
Enter the gender        of the ninja: 1

Enter the first name    of the ninja: April
Enter the third name    of the ninja: O'Neil
Enter the belt          of the ninja: Green
Enter the weapon        of the ninja: Sai
Enter the gender        of the ninja: 0

Enter the first name    of the ninja: Karai
Enter the third name    of the ninja: Saki
Enter the belt          of the ninja: Black
Enter the weapon        of the ninja: Katana
Enter the gender        of the ninja: 0

Enter the first name    of the ninja: Hamato
Enter the third name    of the ninja: Yoshi
Enter the belt          of the ninja: Black
Enter the weapon        of the ninja: Katana
Enter the gender        of the ninja: 1


Enter the filter of the ninjas:

1. Belt
2. Weapon
3. Gender

Enter the option from the menu: 3

Input the gender: FEMALE


The ninjas in your program are:

The first name  of the ninja is: April
The third name  of the ninja is: O'Neil
The belt        of the ninja is: Green
The weapon      of the ninja is: Sai
The gender      of the ninja is: FEMALE

The first name  of the ninja is: Karai
The third name  of the ninja is: Saki
The belt        of the ninja is: Black
The weapon      of the ninja is: Katana
The gender      of the ninja is: FEMALE
```


## Задача 5 ⚒️ (Масив) ⚒️

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Създайте програма, която има реализирана структура, която ще представлява контейнер за масив от цели числа. Контейнерът да пази и размерът на масива. Реализирайте съответните методи за създаване на масив, за добавяне на елемент в края на масива, за премахване на елемент от края на масива, за извеждане на това дали масивът е празен, за извеждане на броя на елементите в масива. Демонстрирайте работата на вашата програма, като въвеждате числа от стандартния вход до достигане на `0`, които да добавяте в масива, а след това премахнете последните `3` от добавените елементи, които току-що добавихте, ако е възможно. В началото на програмата, в края на програмата и преди премахването на елементи изведете статистика за получения масив.

### 💡 Примери:

```txt
The SIZE        of the array is: 0
The CAPACITY    of the array is: 2
Is the array empty: true


Enter the numbers: 1 3 7 9 0


The SIZE        of the array is: 4 
The CAPACITY    of the array is: 4
Is the array empty: false

The elements of the array are: 1 3 7 9


The SIZE        of the array is: 1
The CAPACITY    of the array is: 4
Is the array empty: false

The elements of the array are: 1
```

```txt
The SIZE        of the array is: 0
The CAPACITY    of the array is: 2
Is the array empty: true


Enter the numbers: 1 2 3 4 5 6 0


The SIZE        of the array is: 6
The CAPACITY    of the array is: 8
Is the array empty: false

The elements of the array are: 1 2 3 4 5 6


The SIZE        of the array is: 3
The CAPACITY    of the array is: 8
Is the array empty: false

The elements of the array are: 1 2 3
```

```txt
The SIZE        of the array is: 0
The CAPACITY    of the array is: 2
Is the array empty: true


Enter the numbers: 1 2 3 0


The SIZE        of the array is: 3
The CAPACITY    of the array is: 4
Is the array empty: false

The elements of the array are: 1 2 3

The SIZE        of the array is: 0
The CAPACITY    of the array is: 4
Is the array empty: true
```


## Задача 6 🛠️ (Матрица) 🛠️

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Създайте програма, която има реализирана структура, която ще представлява контейнер за матрица от цели числа. Контейнерът да пази и размерите на матрицата. Реализирайте съответните методи за създаване на матрица, за добавяне на ред в матрица, за добавяне на колона на матрица, за премахване на ред на матрица, за премахване на колона на матрица, за извеждане на това дали матрицата е празна, за извеждане на броя на елементите в матрицата. Демонстрирайте работата на вашата програма, като въвеждате елементите на матрицата от стандартния вход, с предварително зададени размери за нея, а след това добавете нов ред, премахнете даден ред, добавете нова колона, премахнете дадена колона. В началото на програмата, в края на програмата и след всяка операция за добавяне и премахване изведете статистика за получената матрица.

### 💡 Примери:

```txt
Enter the ROWS size of the matrix: 3
Enter the COLS size of the matrix: 3
Enter the elements of the matrix:
1 2 3
4 5 6
7 8 9

The elements of the matrix are:
1 2 3
4 5 6
7 8 9
The rows in the matrix are: 3
The cols in the matrix are: 3
Is the matrix empty: false

Enter the elements of the array: 1 5 9
Enter the elements of the array: 4 8 9

Building Row... SUCCESS!

The element of the matrix are:
1 2 3
4 5 6
7 8 9
1 5 9
The rows in the matrix are: 4
The cols in the matrix are: 3
Is the matrix empty: false

Removing Row... SUCCESS!

The elements of the matrix are:
4 5 6
7 8 9
1 5 9
The rows in the matrix are: 3
The cols in the matrix are: 3
Is the matrix empty: false

Building Col... SUCCESS!

The elements of the matrix are:
4 5 6 4
7 8 9 8
1 5 9 9
The rows in the matrix are: 3
The cols in the matrix are: 4
Is the matrix empty: false

Removing Col... SUCCESS!

The elements of the matrix are:
5 6 4
8 9 8
5 9 9
The rows in the matrix are: 3
The cols in the matrix are: 3
Is the matrix empty: false
```

```txt
Enter the ROWS size of the matrix: 2
Enter the COLS size of the matrix: 2
Enter the elements of the matrix:
1 2
3 4

The elements of the matrix are:
1 2
3 4
The rows in the matrix are: 2
The cols in the matrix are: 2
Is the matrix empty: false

Building Row... SUCCESS!

The elements of the matrix are:
1 2
3 4
1 4
The rows in the matrix are: 3
The cols in the matrix are: 2
Is the matrix empty: false

Removing Row... SUCCESS!

The elements of the matrix are:
3 4
1 4
The rows in the matrix are: 2
The cols in the matrix are: 2
Is the matrix empty: false

Building Col... SUCCESS!

The elements of the matrix are:
3 4 3
1 4 4
The rows in the matrix are: 2
The cols in the matrix are: 3
Is the matrix empty: false

Removing Col... SUCCESS!

The elements of the matrix are:
4 3
4 4
The rows in the matrix are: 2
The cols in the matrix are: 2
Is the matrix empty: false
```

```txt
Enter the ROWS size of the matrix: 1
Enter the COLS size of the matrix: 1
Enter the elements of the matrix:
1

The elements of the matrix are:
1
The rows in the matrix are: 1
The cols in the matrix are: 1
Is the matrix empty: false

Enter the elements of the array: 1
Enter the elements of the array: 1

Building Row... SUCCESS!

The elements of the matrix are:
1
1
The rows in the matrix are: 2
The cols in the matrix are: 1
Is the matrix empty: false

Removing Row... SUCCESS!

The elements of the matrix are:
1
The rows in the matrix are: 1
The cols in the matrix are: 1
Is the matrix empty: false

Building Col... SUCCESS!

The elements of the matrix are:
1 1
The rows in the matrix are: 1
The cols in the matrix are: 2
Is the matrix empty: false

Building Col... SUCCESS!

The elements of the matrix are:
1
The rows in the matrix are: 1
The cols in the matrix are: 1
Is the matrix empty: false
```


## Задача 7 📚 (Библиотека) 📚

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Създайте програма, която има реализирана структура за книга и реализирана структура за библиотека. Книгата съответно да притежава полета за заглавие, заделено с точна големина, име на автора, заделено с точна големина, цена, както и брой копия в библиотеката. Библиотеката съответно да притежава полета за адрес, заделен с точна големина, масив от книги, както и брой читатели в библиотеката. Библиотеката да поддържа най-много `13` различни книги. На стандартния изход изведете средната цена на книгите в библиотеката, книгата с най-малко копия, книгата с най-много копия, броя на всички копия в библиотеката, минималната цена на книга, максималната цена на книга.

### 💡 Примери:

```txt
Enter the address   of the library: Lozenets, Sofia
Enter the readers   of the library: 1
Enter the size      of the library: 1

Enter the information about the books:

    Enter the title     of the book: The 48 Laws of Power
    Enter the author    of the book: Robert Greene
    Enter the price     of the book: 9.99
    Enter the copies    of the book: 1

The avg cost of the books in the library is: 9.99
The min cost of the books in the library is: 9.99
The max cost of the books in the library is: 9.99

The book with min copies is: The 48 Laws of Power
The book with max copies is: The 48 Laws of Power

The number of copies in the library is: 1
```

```txt
Enter the address   of the library: Lozenets, Sofia
Enter the readers   of the library: 3
Enter the size      of the library: 3

Enter the information about the books:

    Enter the title     of the book: The 48 Laws of Power
    Enter the author    of the book: Robert Greene
    Enter the price     of the book: 9.99
    Enter the copies    of the book: 1

    Enter the title     of the book: The 33 Strategies of War
    Enter the author    of the book: Robert Greene
    Enter the price     of the book: 16.99
    Enter the copies    of the book: 9

    Enter the title     of the book: The Laws of Human Nature
    Enter the author    of the book: Robert Greene
    Enter the price     of the book: 27.99
    Enter the copies    of the book: 3

The avg cost of the books in the library is: 18.32
The min cost of the books in the library is: 9.99
The max cost of the books in the library is: 27.99

The book with min copies is: 48 Laws of Power
The book with max copies is: The 33 Strategies of War

The number of copies in the library is: 13
```

```txt
Enter the address   of the library: Lozenets, Sofia
Enter the readers   of the library: 7
Enter the size      of the library: 7

Enter the information about the books:

    Enter the title     of the book: The 48 Laws of Power
    Enter the author    of the book: Robert Greene
    Enter the price     of the book: 9.99
    Enter the copies    of the book: 1

    Enter the title     of the book: The 33 Strategies of War
    Enter the author    of the book: Robert Greene
    Enter the price     of the book: 16.99
    Enter the copies    of the book: 9

    Enter the title     of the book: The Laws of Human Nature
    Enter the author    of the book: Robert Greene
    Enter the price     of the book: 27.99
    Enter the copies    of the book: 3

    Enter the title     of the book: The Art of Seduction
    Enter the author    of the book: Robert Greene
    Enter the price     of the book: 14.99
    Enter the copies    of the book: 7

    Enter the title     of the book: Mastery
    Enter the author    of the book: Robert Greene
    Enter the price     of the book: 23.99
    Enter the copies    of the book: 3

    Enter the title     of the book: The Prince
    Enter the author    of the book: Niccolo Machiavelli
    Enter the price     of the book: 49.99
    Enter the copies    of the book: 1

    Enter the title     of the book: The Bible
    Enter the author    of the book: ???
    Enter the price     of the book: 0.01
    Enter the copies    of the book: 13

The avg cost of the book in the library is: 20.56
The min cost of the book in the library is: 0.01
The max cost of the book in the library is: 49.99

The book with min copies is: The 48 Laws of Power
The book with max copies is: The Bible

The number of copies in the library is: 37 
```


## Задача 8 🌐 (Дискотека) 🌐

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Тео е най-големият купонджия - за него е по-важно да посещава редовно участията на любимите си изпълнителки Десита, Симона и Лидия по дискотеките, отколкото да посещава лекции и упражнения по Висша Алгебра и Обектно Ориентирано Програмиране. Тео иска да си направи систематизиран график за текущата седмица, с помощта на който никога няма да пропусне участие - ако някога пропусне участие на някоя Алфа дива хитачка, няма да може да си го прости. Помогнете му, като реализирате структура за участие, което съдържа име на изпълнител и място на участието - символни низове, заделени с точна големина, както и ден от седмицата, в който ще бъде участието. За да представите деня от седмицата, създайте подходящ изброим тип.

Съобразете се със следните данни:

1. Тео не ходи на други участия, освен на споменатите изпълнителки `Dessita`, `Simona`, `Lidiq`. С други думи Тео предпочита упражненията по Висша Алгебра пред участията на други изпълнители.
2. Тео все пак държи на образованието и за него е важно да решава от време на време и задачи по математика и задачи по програмиране. В събота и неделя той решава по 24 часа задачи и не посещава участия на изпълнители.

Създайте масив от участия за текущата седмица и го сортирайте според деня от седмицата. Ако се случи така, че има повече от едно участие в един ден, то тези участия да бъдат сортирани в реда на изпълнителките, посочен в началото на условието.

### 💡 Примери:

```txt
Enter the number of events: 1

Enter the information about the events:

    Enter the singer    of the event: Dessita
    Enter the place     of the event: Bushido
    Enter the weekday   of the event: 0

The sorted evnets are:

    Event singer    is: Dessita
    Event place     is: Bushido
    Event weekday   is: 0
```

```txt
Enter the number of events: 3

Enter the information about the events:
    Enter the singer    of the event: Lidiq
    Enter the place     of the event: Bushido
    Enter the weekday   of the event: 0

    Enter the singer    of the event: Dessita
    Enter the place     of the event: Club 33
    Enter the weekday   of the event: 0

    Enter the singer    of the event: Simona
    Enter the place     of the event: Eleven
    Enter the weekday   of the event: 0

The sorted events are:

    Event singer    is: Dessita
    Event place     is: Club 33
    Event weekday   is: Monday

    Event singer    is: Simona
    Event place     is: Eleven
    Event weekday   is: Monday

    Event singer    is: Lidiq
    Event place     is: Bushido
    Event weekday   is: Monday
```

```txt
Enter the number of events: 7

Enter the information about the events:

    Enter the singer    of the event: Lidiq
    Enter the place     of the event: Bushido
    Enter the weekday   of the event: 0

    Enter the singer    of the event: Lidiq
    Enter the place     of the event: Bushido
    Enter the weekday   of the event: 3

    Enter the singer    of the event: Dessita
    Enter the place     of the event: Club 33
    Enter the weekday   of the event: 0

    Enter the singer    of the event: Simona
    Enter the place     of the event: Eleven
    Enter the weekday   of the event: 0

    Enter the singer    of the event: Dessita
    Enter the place     of the event: Club 33
    Enter the weekday   of the event: 1

    Enter the singer    of the event: Simona
    Enter the place     of the event: Eleven
    Enter the weekday   of the event: 2

    Enter the singer    of the event: Dessita
    Enter the place     of the event: Club 33
    Enter the weekday   of the event: 4

The sorted events are:

    Event singer    is: Dessita
    Event place     is: Club 33
    Event weekday   is: Monday

    Event singer    is: Simona
    Event place     is: Eleven
    Event weekday   is: Monday

    Event singer    is: Lidiq
    Event place     is: Bushdio
    Event weekday   is: Monday

    Event singer    is: Dessita
    Event place     is: Club 33
    Event weekday   is: Tuesday

    Event singer    is: Simona
    Event place     is: Eleven
    Event weekday   is: Wednesday

    Event singer    is: Lidiq
    Event place     is: Bushido
    Event weekday   is: Thursday

    Event singer    is: Dessita
    Event place     is: Club 33
    Event weekday   is: Friday
```


## Задача 9 📝 (Числов Запис) 📝

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Създайте програма, която да репрезентира дробно число, използващо `32` бита, която съдържа две различни репрезентации - обикновен запис, представляващ цяла и дробна част, и стандартен запис, представляващ мантиса, порядък и знак. Цялата и дробната част са съответно по `16` бита. Мантисата, порядъкът и знакът са съответно с размери `23`, `8`, `1` бита. В рамките на паметта за конкретна инстанция трябва да се съдържа точно един от двата записа, но не и двата записа едновременно.

### 💡 Примери:

```txt
Enter the number - Whole Part: 1
Enter the number - Fract Part: 0

Form 1 of the number is: 1.0
Form 2 of the number is: +1.0e0
```

```txt
Enter the number - Whole Part: 13
Enter the number - Fract Part: 79

Form 1 of the number is: 13.79
Form 2 of the number is: +1.379e1
```

```txt
Enter the number - Whole Part: -97
Enter the number - Fract Part: 31

Form 1 of the number is: -97.31
Form 2 of the number is: -9.731e1
```


## Задача 10 👾 (Битове) 👾

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Създайте програма, която да репрезентира поредица от 8 флага, представяща се по 2 различни начина - като 8 различни еднобитови флагове и като неотрицателно цяло число. В рамките на паметта за конкретна инстанция трябва да се съдържа точно едно от двете представяния, но не и двете представяния едновременно.

### 💡 Примери:

```txt
Enter the number: 0

The number is: 00001100
The number is: 0
```

```txt
Enter the number: 3

The number is: 11001100
The number is: 3
```

```txt
Enter the number: 9

The number is: 10011100
The number is: 9
```


## Задача 11 🌰 (Шишарки) 🌰

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Шишарко е решил да събира шишарки от забранените гори. Всяка шишарка в гората се идентифицира с номер, който представлява цяло число, и информация за това дали шишарката е малка или голяма, като това се описва със символен низ. Забележете, че тази информация задължилено се описва чрез двата символни низа, които са взаимноизключващи се. Създайте програма, която да помогне на Шишарко да разбере колко големи и колко малки шишарки е събрал, като имате предвид, че Шишарко разбира дали шишарката е малка или голяма едва когато има достъп до дадената шишарка. С други думи информацията за размера на шишарката винаги е на едно и също място за всяка шишарка в кошницата на Шишарко - вашата памет на програмата.

### 💡 Примери:

```txt
Enter the size of the basket: 1

The number of SML cones are: 0
The number of BIG cones are: 1
```

```txt
Enter the size of the basket: 3

The number of SML cones are: 1
The number of BIG cones are: 2
```

```txt
Enter the size of the basket: 7

The number of SML cones are: 3
The number of BIG cones are: 4
```


## Задача 12 🎧 (Музика) 🎧

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Създайте структура, която представлява песен, която съдържа следните характеристики: заглавие, име на изпълнител, жанр, рейтинг, брой слушания. Заглавието и името на изпълнителя са символни низове с максимална големина `256` символа. Жанрът може да бъде `Pop`, `Techno`, `House`, `Dubstep`. Рейтингът е дробно число в интервала `[0.0 ; 10.0]`. Създайте структура `Playlist`, която се описва с най-много `64` песни. Реализирайте следните функции: ако капацитетът е запълнен, принтирайте подходящо съобщение, връщане на указател към песен по подаден предикат, приемащ като аргумент `1` песен, сортиране на песните по подаден предикат, приемащ като аргумент `2` песни. Демонстрирайте работата на вашата програма, като създадете плейлист, запълните го с песни, а след това сортирате тези песни и намерите точно конкретна. Сортирането и търсенето може да се случи по критерий, избрани от програмиста.

### 💡 Примери:

```txt
Enter the size of the playlist: 3

Enter the name      of the song: Moy si merak
Enter the singer    of the song: Simona
Enter the genre     of the song: Pop
Enter the rating    of the song: 9.9
Enter the views     of the song: 1379

Enter the name      of the song: Piqnice
Enter the singer    of the song: Simona
Enter the genre     of the song: Pop
Enter the rating    of the song: 9.5
Enter the views     of the song: 1000

Enter the name      of the song: May poludqh
Enter the singer    of the song: Simona
Enter the genre     of the song: Pop
Enter the rating    of the song: 9.3
Enter the views     of the song: 500

The sorted playlist is:

The name    of the song is: Moy si merak
The singer  of the song is: Simona
The genre   of the song is: Pop
The rating  of the song is: 9.3
The views   of the song is: 500

The name    of the song is: Piqnice
The singer  of the song is: Simona
The genre   of the song is: Pop
The rating  of the song is: 9.5
The views   of the song is: 1000

The name    of the song is: Moy si merak
The singer  of the song is: Simona
The genre   of the song is: Pop
The rating  of the song is: 9.9
The views   of the song is: 1379

The MIN Rating Song is: UNKNOWN
The MAX Rating Song is: Moy si merak
```

```txt
Enter the size of the playlist: 3

Enter the name      of the song: Maturata
Enter the singer    of the song: Lidiq
Enter the genre     of the song: Pop
Enter the rating    of the song: 9.7
Enter the views     of the song: 1000

Enter the name      of the song: GPS-a
Enter the singer    of the song: Lidiq
Enter the genre     of the song: Pop
Enter the rating    of the song: 9.0
Enter the views     of the song: 500

Enter the name      of the song: V racete na drug
Enter the singer    of the song: Lidiq
Enter the genre     of the song: Pop
Enter the rating    of the song: 8.7
Enter the views     of the song: 1

The sorted playlist is:

The name    of the song is: V racete na drug
The singer  of the song is: Lidiq
The genre   of the song is: Pop
The rating  of the song is: 8.7
The views   of the song is: 1

The name    of the song is: GPS-a
The singer  of the song is: Lidiq
The genre   of the song is: Pop
The rating  of the song is: 9
The views   of the song is: 500

The name    of the song is: Maturata
The singer  of the song is: Lidiq
The genre   of the song is: Pop
The rating  of the song is: 9.7
The views   of the song is: 1000

The MIN Rating Song is: V racete na drug
The MAX Rating Song is: UNKNOWN
```

```txt
Enter the size of the playlist: 3

Enter the name      of the song: GPS-a
Enter the singer    of the song: Dessita
Enter the genre     of the song: Pop
Enter the rating    of the song: 10.0
Enter the views     of the song: 1379

Enter the name      of the song: #Musala
Enter the singer    of the song: Dessita
Enter the genre     of the song: Pop
Enter the rating    of the song: 0.0
Enter the views     of the song: 1

Enter the name      of the song: Tvoyata zhena
Enter the singer    of the song: Dessita
Enter the genre     of the song: Pop
Enter the rating    of the song: 8.0
Enter the views     of the song: 1000

The sorted playlist is:

The name    of the song is: #Musala
The singer  of the song is: Dessita
The genre   of the song is: Pop
The rating  of the song is: 0
The views   of the song is: 1

The name    of the song is: Tvoyata zhena
The singer  of the song is: Dessita
The genre   of the song is: Pop
The rating  of the song is: 8
The views   of the song is: 1000

The name    of the song is: GPS-a
The singer  of the song is: Dessita
The genre   of the song is: Pop
The rating  of the song is: 10
The views   of the song is: 1379

The MIN Rating Song is: #Musala
The MAX Rating Song is: GPS-a
```


## Задача 13 🔧 (Свързан Списък) 🔧

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/impossible-black)

### 📖 Описание:

Създайте програма, която да реализира структура за възел `Node`. Всеки възел съдържа поле за съдържание, което е цяло число, както и указател към възел. В една примерна поредица от възли всеки възел има указател към следващ възел, а последният възел има указател съм стойност `nullptr`. Създайте методи за добавяне на възел, за намиране на броя на елементите в поресица от възли, за намиране на сумата на елементите в поредица от възли. Демонстрирайте работата на вашата програма, като въвеждате числа от стандартния вход до въвеждане на числото `0`. След това изведете на стандартния изход поредицата от възли, размера на поредицата, сумата на поредицата.

### 💡 Примери:

```txt
Enter the numbers: 1 3 7 9 0

The SIZE        of the sequence is: 4
The CAPACITY    of the sequence is: 20

The sequence is: 1 3 7 9
```

```txt
Enter the numbers: 1 2 3 4 5 6 7 8 9 10 9

The SIZE        of the sequence is: 10
The CAPACITY    of the sequence is: 55

The sequence is: 1 2 3 4 5 6 7 8 9 10
```

```txt
Enter the numbers: 0

The SIZE        of the sequence is: 0
The CAPACITY    of the sequence is: 0

Empty sequence!
```



</div>
