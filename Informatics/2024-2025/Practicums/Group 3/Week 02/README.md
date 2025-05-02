# Седмица 2
# Структури. Разположение в паметта. Битови полета. Разделна компилация.



## Задача 1 🟡 (Точка) 🟠

![Static Badge](https://img.shields.io/badge/easy-green)


### 📖 Описание:

Създайте програма, която има реализирана структура за точка от тримерното евклидово пространство. Програмата да прочита стойностите на три точки от стандартния вход и да извежда на стандартния изход периметъра и лицето на триъгълника, описан с тези три точки. Също така за триъгълника да се изведе информация за типа му спрямо страните му - равнобедрен, равностранен, разностранен, както и да се върне типа на триъгълника спрямо ъглите му - остроъгълен, правоъгълен, тъпоъгълен.

### 💡 Примери:

```
Enter the coordinates of the point: 1 0 0
Enter the coordinates of the point: 0 1 0
Enter the coordinates of the point: 0 0 1

The PERIMETER   of the triangle is: 4.242641
The AREA        of the triangle is: 0.866025
```

```
Enter the coordinates of the point: -1  0  0
Enter the coordinates of the point:  0 -1  0
Enter the coordinates of the point:  0  0 -1

The PERIMETER   of the triangle is: 4.242641
The AREA        of the triangle is: 0.866025
```

```
Enter the coordinates of the point: 3 3 0
Enter the coordinates of the point: 3 0 3
Enter the coordinates of the point: 0 3 3

The PERIMETER   of the triangle is: 12.727922
The AREA        of the triangle is: 7.794229
```


## Задача 2

![Static Badge](https://img.shields.io/badge/easy-green)

### 📖 Описание:

Създайте програма, която има реализирана структура за вектор от тримерното евклидово пространство. Реализирайте съответните методи за инициализиране на вектор от стандартния вход, за извеждане на вектор на стандартния изход, за събиране на два вектора, за умножение на вектори поелементно, за умножение на вектор със скалар.

### 💡 Примери:

В показаните примери първият резултат е сумата на `Vector 1` и `Vector 2`. В показаните примери вторият резултат е произведението на `Vector 1` и `Vector 2`. В показаните примери третият резултат е произведението на `Vector 3` и `number`.

```
Enter the data for Vector 1: 1 0 0
Enter the data for Vector 2: 0 1 0
Enter the data for Vector 3: 0 0 1

Enter the number: 3

The vector is: ( X: 1.000; Y: 1.000; Z: 1.000; )
The vector is: ( X: 0.000; Y: 0.000; Z: 0.000; )
The vector is: ( X: 0.000; Y: 0.000; Z: 3.000; )
```

```
Enter the data for Vector 1: -1 -1 -1
Enter the data for Vector 2: -1 -1 -1
Enter the data for Vector 3:  3  7  9

Enter the number: 1

The vector is: ( X: -2.000; Y: -2.000; Z: -2.000; )
The vector is: ( X:  1.000; Y:  1.000; Z:  1.000; )
The vector is: ( X:  3.000; Y:  7.000; Z:  9.000; )
```

```
Enter the data for Vector 1:  1  0 -1
Enter the data for Vector 2: -1  0  1
Enter the data for vector 3:  9  9  9

Enter the number: 0.5

The vector is: ( X:  0.000; Y: 0.000; Z:  0.000; )
The vector is: ( X: -1.000; Y: 0.000; Z: -1.000; )
The vector is: ( X:  4.500; Y: 4.500; Z:  4.500; )
```

## Задача 3

![Static Badge](https://img.shields.io/badge/easy-green)

### 📖 Описание:

Създайте програма, която има реализирана структура за комплексно число. Реализирайте съответните методи за аритметични действия над комплексни числа. Реализирайте функция, която да връща комплексно-спрегнатото на дадено комплексно число. Реализирайте и функции, които да проверяват дали числото е реално или чисто имагинерно. Реализирайте функции, които да могат да сравняват дали две комплексни числа са равни или не са равни. Демонстрирайте работата на всеки метод във вашата програма.

### 💡 Примери:

В показаните примери първият резултат е сумата на `Complex Number 1` и `Complex Number 2`. В показаните примери вторият резултат е разликата на `Complex Number 2` и `Complex Number 3`. В показаните примери третият резултат е произведението на `Complex Number 3` и `Complex Number 4`. В показаните примери четвъртият пример е частното на `Complex Number 4` и `Complex Number 1`.

```
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

```
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

```
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

## Задача 4

![Static Badge](https://img.shields.io/badge/easy-green)


### 📖 Описание:

Създайте програма, която има реализирана структура `Ninja`, която има първо име, трето име, вид колан, вид оръжие, както и пол. Първото име има максимален размер от `256` символа. Третото име има максимален размер от `256` символа. Видът колан да е изброен тип по преценка на програмиста. Видът оръжие да е изброен тип по преценка на програмиста. Полът да бъде булев резултат. Реализирайте функции за създаване на нинджа, за извеждане на информацията за нинджа на стандартния изход, за филтриране на нинджи по вид колан, за филтриране на нинджи по вид оръжие, за филтриране на нинджи по пол.

Направете съответните проверки за това дали нинджата има коректно зададено първо име и коректно зададено трето име. Всяко име трябва да е непразно, да не съдържа цифри, да не съдържа невалидни символи и да използва конвенцията за имена, т.е. първата буква е главна латинска буква, а останалите букви са малки латински букви.

### 💡 Примери:

```
Enter the number of ninjas:

Enter the ninjas in your program:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:
```

```
Enter the number of ninjas:

Enter the ninjas in your program:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:
```

```
Enter the number of ninjas:

Enter the ninjas in your program:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:

Enter the first name    of the ninja:
Enter the third name    of the ninja:
Enter the belt          of the ninja:
Enter the weapon        of the ninja:
Enter the gender        of the ninja:
```


## Задача 5

![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Създайте програма, която има реализирана структура, която ще представлява контейнер за масив от цели числа. Контейнерът да пази и размерът на масива. Реализирайте съответните методи за създаване на масив, за добавяне на елемент в края на масива, за премахване на елемент от края на масива, за извеждане на това дали масивът е празен, за извеждане на броя на елементите в масива. Демонстрирайте работата на вашата програма, като въвеждате символи от стандартния вход до генериране на `EOF`, които да добавяте в масива, а след това премахнете последните 3 от добавените елементи, които току-що добавихте, ако е възможно. В началото на програмата, в края на програмата и преди премахването на елементи изведете статистика за получения масив.

### 💡 Примери:

```
The SIZE        of the array is: 0
The CAPACITY    of the array is: 2
Is the array empty: true

Enter the numbers: 1 3 7 9

The SIZE        of the array is: 4 
The CAPACITY    of the array is: 8
Is the array empty: false
The elements of the array are: 1 3 7 9

The SIZE        of the array is: 1
The CAPACITY    of the array is: 8
Is the array empty: false
The elements of the array are: 1
```

```
The SIZE        of the array is: 0
The CAPACITY    of the array is: 2
Is the array empty: true

Enter the numbers:

The SIZE        of the array is:
The CAPACITY    of the array is:
Is the array empty: false

The SIZE        of the array is:
The CAPACITY    of the array is:
Is the array empty: 
```

```
The SIZE        of the array is: 0
The CAPACITY    of the array is: 2
Is the array empty: true

Enter the numbers:

The SIZE        of the array is:
The CAPACITY    of the array is:
Is the array empty: false

The SIZE        of the array is:
The CAPACITY    of the array is:
Is the array empty: false
```

## Задача 6

![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Създайте програма, която има реализирана структура, която ще представлява контейнер за матрица от цели числа. Контейнерът да пази и размерите на матрицата. Реализирайте съответните методи за създаване на матрица, за добавяне на ред в матрица, за добавяне на колона на матрица, за премахване на ред на матрица, за премахване на колона на матрица, за извеждане на това дали матрицата е празна, за извеждане на броя на елементите в матрицата.

### 💡 Примери:


## Задача 7

![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Създайте програма, която има реализирана структура за книга и реализирана структура за библиотека. Книгата съответно да притежава полета за заглавие, заделено с точна големина, име на автора, заделено с точна големина, цена, както и брой копия в библиотеката. Библиотеката съответно да притежава полета за адрес, масив от книги, както и брой читатели в библиотеката. Библиотеката да поддържа най-много `13` различни книги. На стандартния изход изведете средната цена на книгите в библиотеката, книгата с най-много копия, книгата с най-много копия, минималната цена на книга, максималната цена на книга.

### 💡 Примери:

## Задача 8

![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Тео е най-големият купонджия - за него е по-важно да посещава редовно участията на любимите си изпълнителки Десита, Симона, Лидия и Мирела по дискотеките, отколкото да посещава лекции и упражнения по Висша Алгебра и Обектно Ориентирано Програмиране. Тео иска да си направи систематизиран график за текущата седмица, с помощта на който никога няма да пропусне участие - ако някога пропусне участие на някоя Алфа дива хитачка, няма да може да си го прости. Помогнете му, като реализирате структура за участие, което съдържа име на изпълнител и място на участието - символни низове, заделени с точна големина, както и ден от седмицата, в който ще бъде участието. За да представите деня от седмицата, създайте подходящ изброим тип.

Съобразете се със следните данни:

1. Тео не ходи на други участия, освен на споменатите изпълнителки `Dessita`, `Simona`, `Lidiq`, `Mirela`. С други думи Тео предпочита упражненията по Висша Алгебра пред участията на други изпълнители.
2. Тео все пак държи на образованието и за него е важно да решава от време на време и задачи по математика и задачи по програмиране. Затова в събота той решава 24 часа задачи и не посещава участия на изпълнители.

Създайте масив от участия за текущата седмица и го сортирайте според деня от седмицата.

### 💡 Примери:

## Задача 9

![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Създайте програма, която да репрезентира дробно число, използващо `32` бита, която съдържа две различни репрезентации - обикновен запис, представляващ цяла и дробна част, и стандартен запис, представляващ мантиса, порядък и знак. Мантисата, порядъкът и знакът са съответно с размери `23`, `8`, `1` бита. В рамките на паметта за конкретна инстанция трябва да се съдържа точно един от двата записа, но не и двата записа едновременно.

### 💡 Примери:


## Задача 10

![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Създайте програма, която да репрезентира поредица от 8 флага, представяща се по 2 различни начина - като 8 различни еднобитови флагове и като неотрицателно цяло число. В рамките на паметта за конкретна инстанция трябва да се съдържа точно едно от двете представяния, но не и двете представяния едновременно.

### 💡 Примери:

## Задача 11

![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Шишарко е решил да събира шишарки от забранените гори. Всяка шишарка в гората се идентифицира с номер, който представлява цяло число, и информация за това дали шишарката е малка или голяма, като това се описва със символен низ. Забележете, че тази информация задължилено се описва чрез двата символни низа, които са взаимноизключващи се. Създайте програма, която да помогне на Шишарко да разбере колко големи и колко малки шишарки е събрал, като имате предвид, че Шишарко разбира дали шишарката е малка или голяма едва когато има достъп до дадената шишарка. С други думи информацията за размера на шишарката винаги е на едно и също място за всяка шишарка в кошницата на Шишарко - вашата памет на програмата.

### 💡 Примери:


## Задача 12

![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Създайте структура, която представлява песен, която съдържа следните характеристики: заглавие, име на изпълнител, жанр, рейтинг, брой слушания. Заглавието и името на изпълнителя са символни низове с максимална големина `100` символа. Жанрът може да бъде `Pop`, `Techno`, `Pop-Folk`, `House`, `Dupstep`. Рейтингът е дробно число в интервала `[0.0 ; 10.0]`. Създайте структура `Playlist`, която се описва с най-много 64 песни. Реализирайте следните функции: добавяне на песен в колекцията - ако капацитетът е запълнен, принтирайте подходящо съобщение, връщане на указател към песен по подаден предикат, приемащ като аргумент 1 песен, сортиране на песните по подаден предикат, приемащ като аргумент 2 песни.

### 💡 Примери:

## Задача 13

![Static Badge](https://img.shields.io/badge/impossible-black)

### 📖 Описание:

Създайте програма, която да реализира структура за възел `Node`. Всеки възел съдържа поле за съдържание, което е цяло число, както и указател към възел. В една примерна поредица от възли всеки възел има указател към следващ възел, а последният възел има указател съм стойност `nullptr`. Създайте методи за добавяне на възел, за намиране на броя на елементите в поресица от възли, за намиране на сумата на елементите в поредица от възли. Демонстрирайте работата на вашата програма, като въвеждате числа от стандартния вход до въвеждане на числото `0`. След това изведете на стандартния изход поредицата от възли, размера на поредицата, сумата на поредицата.

### 💡 Примери:

```
Enter the numbers: 1 3 7 9 0

The SIZE        of the sequence is: 4
The CAPACITY    of the sequence is: 20

The sequence is: 1 3 7 9
```

```
Enter the numbers: 1 2 3 4 5 6 7 8 9 10 9

The SIZE        of the sequence is: 10
The CAPACITY    of the sequence is: 55

The sequence is: 1 2 3 4 5 6 7 8 9 10
```

```
Enter the numbers: 0

The SIZE        of the sequence is: 0
The CAPACITY    of the sequence is: 0

Empty sequence!
```
