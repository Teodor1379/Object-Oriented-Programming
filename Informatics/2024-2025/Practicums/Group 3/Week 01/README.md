# Седмица 1
# Допълнение към курса по УП. Изброен тип.



<div align="justify">


## Задача 1 🔢 (Броене на Числа) 🔢

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/easy-green)

### 📖 Описание:

Създайте програма, която прочита от стандартния вход число `N` и извежда на стандартния изход сумата на всички числа от `1` до `N`, които се делят на `3` или на `5` или на `7`, броени с кратностите им точно веднъж, дори ако едно число се дели на някое от посочените делители едновременно.

### 💡 Примери:

```txt
Enter the limit: 10
The sum of the multiples of 3, 5, 7 is: 40
```

```txt
Enter the limit: 100
The sum of the multiples of 3, 5, 7 is: 2838
```

```txt
Enter the limit: 1000
The sum of the multiples of 3, 5, 7 is: 272066
```


## Задача 2 🧐 (Шифър на Цезар) 🧐

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/easy-green)

### 📖 Описание:

Създайте програма, която прочита от стандартния вход символен низ и криптира текста според шифъра на Цезар, извеждайки криптирания текст на стандартния изход. Шифърът на Цезар е метод на субституция на буквите, при който всеки символ от латинската азбука се заменя със символа от латинската азбука на `Shift` позиции след текущия.

### 💡 Примери:

```txt
Enter the shift: 0
Enter the string: ABC
The string is: ABC
```

```txt
Enter the shift: 1
Enter the string: ABCXYZ
The string is: BCDYZA
```

```txt
Enter the shift: 3
Enter the string: ABCXYZ
The string is: DEFABC
```


## Задача 3 🧠 (Хитри Операции) 🧠

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/easy-green)

### 📖 Описание:

Създайте програма, която прочита от стандартния вход три числа и извежда на стандартния изход минималното число, максималното число и средното число по големина, използвайки единствено булеви изрази, без условни конструкции.

### 💡 Примери:

```txt
Enter the number: 1
Enter the number: 2
Enter the number: 3

Min Number is: 1
Max Number is: 3
Avg Number is: 2
```

```txt
Enter the number: 3
Enter the number: 2
Enter the number: 1

Min Number is: 1
Max Number is: 3
Avg Number is: 2
```

```txt
Enter the number: 3
Enter the number: 9
Enter the number: 7

Min Number is: 3
Max Number is: 9
Avg Number is: 7
```


## Задача 4 ⬜ (Правоъгълници) ⬜

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/easy-green)

### 📖 Описание:

Създайте програма, която изчислява периметъра и лицето на правоъгълник, която има версии за целочислени и реалнозначни стойности.

### 💡 Примери:

```txt
Enter the side of the rectangle: 1
Enter the side of the rectangle: 3

The PERIMETER   of the rectangle is: 8
The AREA        of the rectangle is: 3

Enter the side of the rectangle: 1.5
Enter the side of the rectangle: 2.5

The PERIMETER   of the rectangle is: 8
The AREA        of the rectangle is: 3.75
```

```txt
Enter the side of the rectangle: 2
Enter the side of the rectangle: 4

The PERIMETER   of the rectangle is: 12
The AREA        of the rectangle is: 8

Enter the side of the rectangle: 2.25
Enter the side of the rectangle: 3.75

The PERIMETER   of the rectangle is: 12
The AREA        of the rectangle is: 8.4375
```

```txt
Enter the side of the rectangle: 1
Enter the side of the rectangle: 1

The PERIMETER   of the rectangle is: 4
The AREA        of the rectangle is: 1

Enter the side of the rectangle: 1.0
Enter the side of the rectangle: 1.0

The PERIMETER   of the rectangle is: 4
The AREA        of the rectangle is: 1
```


## Задача 5 📊 (Операции с Масив) 📊

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Създайте програма, която прочита от стандартния вход размер на масив и заделя динамично памет за него. На стандартния изход изведете минималното число, максималното число, сумата и произведението на числата в масива.

### 💡 Примери:

```txt
Enter the size of the array: 3
Enter the elements of the array: 1 2 3

The MIN number of the array is: 1
The MAX number of the array is: 3
The SUM     of the array is: 6
The PRODUCT of the array is: 6
```

```txt
Enter the size of the array: 5
Enter the elements of the array: 5 4 3 2 1

The MIN number of the array is: 1
The MAX number of the array is: 5
The SUM     of the array is: 15
The PRODUCT of the array is: 120
```

```txt
Enter the size of the array: 7
Enter the elements of the array: 1 3 7 9 3 7 1

The MIN number of the array is: 1
The MAX number of the array is: 7
The SUM     of the array is: 31
The PRODUCT of the array is: 3969
```


## Задача 6 ↻ (Транспониране на Матрица) ↻

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Създайте програма, която прочита от стандартния вход размери на матрица и заделя динамично памет за нея. На стандартния изход изведете транспонираната матрица на въведената.

### 💡 Примери:

```txt
Enter the ROWS size of the matrix: 2
Enter the COLS size of the matrix: 2

Enter the elements of the matrix:
1 2
3 4

The transposed matrix is:
1 3
2 4
```

```txt
Enter the ROWS size of the matrix: 3
Enter the COLS size of the matrix: 3

Enter the elements of the matrix:
1 2 3
4 5 6
7 8 9

The transposed matrix is:
1 4 7
2 5 8
3 6 9
```

```txt
Enter the ROWS size of the matrix: 4
Enter the COLS size of the matrix: 4

Enter the elements of the matrix:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

The transposed matrix is:
1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16
```


## Задача 7 👨🏻‍💼 (Възраст на Човек) 👨🏻‍💼

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Създайте програма, която прочита от стандартния вход възраст на човек. На стандартния изход да се изведе съответната възрастова група на потребителя по следната схема:

- `"Young"` - `(1  - 33)`
- `"Average"` - `(34 - 67)`
- `"Old"` - `(68 - 101)`

### 💡 Примери:

```txt
Enter the age of the human: 18
The interval is: Young
```

```txt
Enter the age of the human: 66
The interval is: Average
```

```txt
Enter the age of the human: 100
The interval is: Old
```


## Задача 8 ♥️ (Белот) ♠️

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Създайте програма, която прочита от стандартния вход бои на карти и стойности на карти, а на стандартния изход извежда коя карта има по-голяма сила. Силата на картите е според стандартните правила за игра на белот.

### 💡 Примери:

```txt
Enter the name of the card: CLUB
Enter the name of the card: CLUB
Enter the value of the card: 2
Enter the value of the card: 1
Card 1 is stronger than Card 2!
```

```txt
Enter the name of the card: DIAMOND
Enter the name of the card: HEART
Enter the value of the card: 3
Enter the value of the card: 3
Card 2 is stronger than Card 1!
```

```txt
Enter the name of the card: SPADE
Enter the name of the card: SPADE
Enter the value of the card: A
Enter the value of the card: A
Card 1 is equal to the Card 2!
```


## Задача 9 📛 (Символни Низове) 📛

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Създайте програма, която прочита от стандартния вход `N` на брой символни низа и обръща всеки един от тях, извеждайки ги на стандартния изход. Тук `N` също се въвежда от стандартния вход.

### 💡 Примери:

```txt
Enter the size: 1

Enter the strings:
Hello World!

The strings are:
!dlroW olleH
```

```txt
Enter the size: 3

Enter the strings:
Hello World!
I Love the World!
I Hate the World!

The strings are:
!dlroW olleH
!dlroW eht evoL I
!dlroW eht etaH I
```

```txt
Enter the size: 7

Hello World!
I Love Her!
I Hate Her!
Light curse you!
For the Silver Hand!
The Light is with us!
Enemies of the Light, beware!

The strings are:
!dlroW olleH
!erH evoL I
!erH etaH I
!uoy esruc thgiL
!dnaH revliS eht roF
!su htiw si thgiL ehT
!eraweb ,thgiL eht fo seimenE
```


## Задача 10 👨🏻‍🔧 (Динамичен Масив - Реализация) 👨🏻‍🔧

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Създайте програма, която прочита от стандартния вход размер на масив и заделя динамично памет за него. Да се реализират следните функционалности в програмата: създаване на масив с входен размер, изтриване на масив, проверка дали масив е празен, добавяне на елемент на последна позиция, премахване на елемент от последна позиция.

### 💡 Примери:

```txt
Enter the size: 3

Enter the elements of the array: 1 2 3
The elements of the array are: 1 2 3
The elements of the array are: 1 2 3 1379
The elements of the array are: 1 2 3
```

```txt
Enter the size: 7

Enter the elements of the array: 1 2 3 4 5 6 7
The elements of the array are: 1 2 3 4 5 6 7
The elements of the array are: 1 2 3 4 5 6 7 1237
The elements of the array are: 1 2 3 4 5 6 7
```

```txt
Enter the size: 9

Enter the elements of the array: 1 2 3 4 5 6 7 8 9
The elements of the array are: 1 2 3 4 5 6 7 8 9
The elements of the array are: 1 2 3 4 5 6 7 8 9 1379
The elements of the array are: 1 2 3 4 5 6 7 8 9
```


## Задача 11 🔎 (Бързо Търсене в Матрица) 🔍

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Създайте програма, която прочита от стандартния вход число `N`, което е размер на динамично заделена матрица. За всеки от редовете на матрицата приложете алгоритъма за `Binary Search`, докато намерите елемента `K`, който също се прочита от стандартния вход. На стандартния изход изведете дали този елемент е намерен в матрицата.

### 💡 Примери:

```txt
Enter the element: 1

Enter the ROWS of the matrix: 3
Enter the COLS of the matrix: 3

Enter the elements of the matrix:
1 2 3
4 5 6
7 8 9

The element WAS found!
```

```txt
Enter the element: 9

Enter the ROWS of the matrix: 3
Enter the COLS of the matrix: 3

Enter the elements of the matrix:
3 2 1
6 5 4
9 8 7

The element WAS found!
```

```txt
Enter the element: 17

Enter the ROWS of the matrix: 4
Enter the COLS of the matrix: 4

Enter the elements of the matrix:
 1  2  3  4
 5  6  7  8
 9 10 11 12
13 14 15 16

The element WAS NOT found!
```


## Задача 12 🔐 (Файлови Права) 🔐

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Създайте програма, която прочита от стандартния вход число, което ще е битова комбинация от правата на достъп върху `UNIX` обект от файловата система. Правата на достъп върху такъв обект представлява поредица от `3` символа - съответно за четене, за писане и за изпълнение. Ако някое от правата не съществува, на позицията, отредена му за него в рамките на символния низ, се изписва `-`. В зависимост от стойността на битовата комбинация, прочетена като десетично число, изпишете всяко от съответните права: право за четене `r`, право за писане `w`, право за изпълнение `x`, неналично право `-`.

### 💡 Примери:

```txt
Enter the number: 4
The permissions are: r--
```

```txt
Enter the number: 6
The permissions are: rw-
```

```txt
Enter the number: 7
The permissions are: rwx
```


## Задача 13 🕵️ (Търсачи на Числа) 🕵️

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/impossible-black)

### 📖 Описание:

Създайте програма, която прочита от стандартния вход число `N`, което е размер на динамично заделена матрица от цифри, и положително число `K`. В матрицата да се провери дали съществува път, който, при конкатенация на цифрите на клетките в рамките на пътя, образува числото `K`.

### 💡 Примери:

```txt
Enter the number: 1

Enter the ROWS size of the matrix: 3
Enter the COLS size of the matrix: 3

Enter the elements of the matrix:
1 2 3
4 5 6
7 8 9

The path of the number WAS found!
```

```txt
Enter the number: 14569

Enter the ROWS size of the matrix: 3
Enter the COLS size of the matrix: 3

Enter the elements of the matrix:
1 2 3
4 5 6
7 8 9

The path of the number WAS found!
```

```txt
Enter the number: 1234

Enter the ROWS size of the matrix: 3
Enter the COLS size of the matrix: 3

Enter the elements of the matrix:
1 2 3
4 5 6
7 8 9

The path of the number WAS NOT found!
```


</div>
