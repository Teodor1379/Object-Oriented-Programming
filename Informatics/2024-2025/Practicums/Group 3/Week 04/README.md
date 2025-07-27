# Седмица 4.
# Двоични файлове. Работа при пряк достъп.



<div align="justify">



## Задача 1 🔎 (Минимално Число, Максимално Число) 🔎

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/easy-green)

### 📖 Описание:

Създайте програма, която прочита двоичен файл `Numbers.dat`, който съдържа целочислени стойности от тип `int32_t`. На стандартния изход изведете минималното и максималното число от прочетените във файла. Помислете има ли как да прочетете тези числа без да ги зареждате в паметта на процеса на програмата.

### 💡 Примери:

```txt
The numbers are: 1 2 3

Min Number is: 1
Max Number is: 3
```

```txt
The numbers are: 7 6 5 4 3 2 1

Min Number is: 1
Max Number is: 7
```

```txt
The numbers are: 9 1 8 2 7 3 6 4 5

Min Number is: 1
Max Number is: 9
```


## Задача 2 📄 (Размер на Файл) 📄

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/easy-green)

### 📖 Описание:

Създайте програма, която прочита от стандартния вход име на двоичен файл и извежда на стандартния изход размера на файла в байтове, като използвате само функциите от фамилията `seek` и `tell`.

### 💡 Примери:

```txt
Enter the file path: Numbers.dat

File Size is: 12
```

```txt
Enter the file path: Numbers.dat

File Size is: 28
```

```txt
Enter the file path: Numbers.dat

File Size is: 36
```


## Задача 3 📦 (Предмети) 📦

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/easy-green)

### 📖 Описание:

Създайте програма, която съдържа структура `Item`, която да има полета за цена и количество. Създайте сериализация и десериализация на поредица обекти от тип `Item` в двоичен файл. Изведете на стандартния изход общата сума на всички предмети от прочетен двоичен файл с данни. Изведете на стандартния изход количеството на предмета с най-ниска цена. Изведете на стандартния изход количеството на предмета с най-висока цена. Ако има повече от един обект с еднаква най-ниска цена, то за предмета с най-ниска цена намерете онзи с най-ниското количество. Ако има повече от един обект с еднаква най-висока цена, то за предмета с най-висока цена намерете онзи с най-високо количество.

### 💡 Примери:

```txt
Enter the file path: Items1.dat

The items content is:
Item: 1.50 1.00
Item: 1.00 3.00
Item: 3.00 9.00

The price of the items is: 5.50

The Min Price Item Quality is: 3.00
The Max Price Item Quality is: 9.00
```

```txt
Enter the file path: Items2.dat

The items content is:
Item: 1.10 1.00
Item: 1.20 2.00
Item: 1.30 3.00
Item: 2.10 1.00
Item: 2.20 2.00
Item: 2.30 3.00
Item: 9.00 9.00

The price of the items is: 19.20

The Min Price Item Quantity is: 1.00
The Max Price Item Quantity is: 9.00
```

```txt
Enter the file path: Items3.dat

The items content is:
Item: 1.0 2.0
Item: 2.0 1.0
Item: 3.0 3.0
Item: 1.0 1.0
Item: 2.0 3.0
Item: 3.0 2.0
Item: 1.0 3.0
Item: 2.0 2.0
Item: 3.0 1.0

The price of the items is: 18.00

The Min Price Item Quantity is: 1.0
The Max Price Item Quantity is: 3.0
```


## Задача 4 👨 (Сортиране на Хора) 👩

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/easy-green)

### 📖 Описание:

Създайте програма, която да съдържа структурата `Person`, която да има полета за име, което е символен низ до `255` символа, възраст и пол. Реализирайте сериализация и десериализация на поредица от обекти от тип `Person` в двоичен файл. Изведете на стандартния изход сортираната по име редица от хора, като в началото на редицата са мъже, а в края на редицата са жени. Ако има дублиращи се хора по име от еднакъв пол, то тези дубликати да се сортират по възраст.

### 💡 Примери:

```txt
Enter the file path: People1.bin

The people are:
Person: Teo1        19
Person: Teo2        20
Person: Teo3        21

The people are:
Person: Teo1        19
Person: Teo2        20
Person: Teo3        21
```

```txt
Enter the file path: People2.bin

The people are:
Person: Rick        50
Person: Daryl       45
Person: Morgan      41
Person: Negan       52
Person: Carol       49
Person: Maggie      47
Person: Glenn       35

The people are:
Person: Daryl       45
Person: Glenn       35
Person: Morgan      41
Person: Negan       52
Person: Rick        50
Person: Carol       49
Person: Maggie      47
```

```txt
Enter the file path: People3.bin

The people are:
Person: Leon        21
Person: Ada         24
Person: Chris       25
Person: Claire      19
Person: Jill        23
Person: Albert      38
Person: Carlos      21
Person: Josh        28
Person: Alice       25

The people are:
Person: Albert      38
Person: Carlos      21
Person: Chris       25
Person: Josh        28
Person: Leon        21
Person: Ada         24
Person: Alice       25
Person: Claire      19
Person: Jill        23
```


## Задача 5 🗂️ (Файлови Числа) 🗂️

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Създайте програма, която прочита двоичен файл `Numbers.dat`, който съдържа целочислени стойности от тип `int32_t`. Съдържанието на файла да бъде сортирано спрямо обичайната наредба на цели числа, но без да използвате буферен масив за съхранение на данните от файла. След това прочетете съдържанието на файла и го изведете на стандартния изход.

### 💡 Примери:

```txt
Before  Sorting: 1 2 3
After   Sorting: 1 2 3
```

```txt
Before  Sorting: 3 4 5 6 2 1
After   Sorting: 1 2 3 4 5 6
```

```txt
Before  Sorting: 9 8 7 6 5 4 3 2 1
After   Sorting: 1 2 3 4 5 6 7 8 9
```


## Задача 6 🍔 (Поръчки) 🍔

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Създайте програма, която съдържа структура `Order`, съдържаща полета за цена, както и идентификатор на потребител на поръчката. Такива поръчки да се четат от двоичен файл `Orders.bin`, в която е записана информация за поръчките. Във файла `Customers.bin` се съдържат данните за валидни идентификатори на потребители. Изведете в двоичен файл `Results.bin` информация за това кой потребител е направил най-малко поръчки, кой потребител е направил най-много поръчки, кой потребител е платил най-малко, кой потребител е платил най-много. Изведете колко потребители не са направили нито една поръчка.

### 💡 Примери:

```txt
The orders are:
Order is: 1 1
Order is: 2 2
Order is: 3 3

The identifiers are: 1 2 3

Min Orders Customer is: 1
Max Orders Customer is: 1

Min Prices Customer is: 1
Max Prices Customer is: 3

Not real Customers are: 0
```

```txt
The orders are:
Order is: 1 1
Order is: 2 2
Order is: 3 3
Order is: 4 4
Order is: 3 3
Order is: 2 2
Order is: 1 1

The identifiers are: 1 2 3 4 5 6 7

Min Orders Customer is: 4
Max Orders Customer is: 1

Min Prices Customer is: 1
Max Prices Customer is: 3

Not real Customers are: 3
```

```txt
The orders are:
Order is: 1 1
Order is: 2 2
Order is: 3 3
Order is: 3 1
Order is: 2 2
Order is: 3 3
Order is: 1 4
Order is: 1 4
Order is: 1 4

The identifiers are: 1 2 3 4 5 6 7 8 8 9

Min Orders Customer is: 1
Max Orders Customer is: 4

Min Prices Customer is: 4
Max Prices Customer is: 3

Not real Customers are: 5
```


## Задача 7 👤 (Имена) 👤

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Създайте програма, която прочита от стандартния вход `N` пъти следните данни: първо име на човек, второ име на човек, години на човек, и след това записва тези резултати в двоичен файл, чието име се чете от стандартния вход. Числото `N` също се чете от стандартния вход. Приемете, че първото име и последното име на човек са символни низове с максимална дължина `1024`. Изведете на стандартния изход отделно човека с най-късо име и човека с най-дълго име.

### 💡 Примери:

```txt
Enter the size: 1

Enter the file path: Humans.bin

Enter Name 1: Emil
Enter Name 2: Kamenov
Enter the Age: 24

Min Name Human is: Emil         Kamenov     24
Max Name Human is: Emil         Kamenov     24
```

```txt
Enter the size: 3

Enter the file path: Humans.bin

Enter Name 1: Asen
Enter Name 2: Bozhilov
Enter the Age: 24

Enter Name 1: Azniv
Enter Name 2: Kasparqn
Enter the Age: 22

Enter Name 1: Evgeniq
Enter Name 2: Velikova
Enter the Age: 18

Min Name Human is: Asen     Bozhilov    24
Max Name Human is: Evgeniq  Velikova    18
```

```txt
Enter the size: 7

Enter the file path: Humans.bin

Enter Name 1: Radoslava
Enter Name 2: Hristova
Enter the Age: 22

Enter Name 1: Atanas
Enter Name 2: Semerdjiev
Enter the Age: 22

Enter Name 1: Dafina
Enter Name 2: Petkova
Enter the Age: 20

Enter Name 1: Dimitar
Enter Name 2: Dimitrov
Enter the Age: 23

Enter Name 1: Kalin
Enter Name 2: Nikolov
Enter the Age: 24

Enter Name 1: Trifon
Enter Name 2: Trifonov
Enter the Age: 22

Enter Name 1: Petar
Enter Name 2: Armyanov
Enter the Age: 22

Min Name Human is: Kalin        Nikolov     24
Max Name Human is: Radoslava    Hristova    22
```


## Задача 8 📆 (Възрасти) 📆

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/medium-yellow)

### 📖 Описание:

Създайте програма, която прочита от стандартния вход име на двоичен файл, в който са записани следните данни: първо име на човек, второ име на човек, години на човек, и след това отпечатва на стандартния изход данните за тези хора. Приемете, че първото име и последното име на човек са символни низове с максимална дължина `1024`. Изведете на стандартния изход отделно човека, който е най-млад, и човека, който е най-стар.

Изведете подходящи съобщения при грешки или при невалидни данни. Невалидни данни в рамките на тази задача са години на човек, които са неположителни числа.

### 💡 Примери:

```txt
Enter the file path: Persons1.bin

The persons are:
Person: John        Wick        52
Person: Eve         Macarro     20
Person: Winston     Scott       71

The person with Min Age is: Eve         Macarro     20
The person with Max Age is: Winston     Scott       71
```

```txt
Enter the file path: Persons2.bin

The persons are:
Person: Rick        Grimes      50
Person: Daryl       Dyxon       45
Person: Morgan      Jones       41
Person: Negan       Smith       52
Person: Carol       Peletier    49
Person: Maggie      Green       47
Person: Glenn       Rhee        35

The person with Min Age is: Glenn       Rhee        35
The person with Max Age is: Negan       Smith       52
```

```txt
Enter the file path: Persons3.bin

The persons are:
Person: Leon        Kennedy     21
Person: Ada         Wong        24
Person: Chris       Redfield    25
Person: Claire      Redfield    19
Person: Jill        Valentine   23
Person: Albert      Wesker      38
Person: Carlos      Oliveira    21
Person: Josh        Stone       28
Person: Alice       Abernathy   25

The person with Min Age is: Claire      Redfield    19
The person with Max Age is: Albert      Wesker      38
```


## Задача 9 ⭐ (Странни Имена) ⭐

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Създайте програма, която има структура за потребител, който има следните характеристики: име, заделено с точна големина, цяло число за идентификатор, цяло число за възраст. Да се запишат в двоичен файл `Data.bin` данните за поредица от хора, без да се валидират, а след това в рамките на същия файл да се премахнат невалидните данни за потребители. Помислете дали трябва да съхранявате и още някакви данни за потребителите, за да работите със символни низове, заделени с точна големина.

### 💡 Примери:

```txt
```

```txt
```

```txt
```


## Задача 10 👨‍🏫 (Релация) 👨‍🏫

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Създайте програма, която има структура `Pair`, която представлява наредена двойка от естествени числа. Създайте структура, която представя релация. В релацията има най-много `30` наредени двойки и структурата пази текущия си размер.

* Напишете функция, която прочита релация от даден двоичен файл.
* Напишете функция, която записва релация в даден двоичен файл.
* Напишете функция, която добавя наредена двойка към релация.
* Напишете функция, която проверява дали релация е рефлексивна.
* Напишете функция, която проверява дали релация е иррефлексивна.
* Напишете функция, която проверява дали релация е симетрична.
* Напишете функция, която проверява дали релация е слабо антисиметрична.
* Напишете функция, която проверява дали релация е силно антисиметрична.
* Напишете функция, която проверява дали релация е транзитивна.
* Напишете функция, която проверява дали релация е антитранзитивна.
* Напишете функция, която проверява дали релация е на еквивалентност.
* Напишете функция, която проверява дали релация е на частична наредба.
* Напишете функция, която създава топологическа наредба на релация.

### 💡 Примери:

```txt
```

```txt
```

```txt
```


## Задача 11 🏙️ (Градове) 🏙️

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Създайте програма, в която има създадена структура `City`, която описва град и има име, което е символен низ с максимална големина `64` символа, както и брой жители. Създайте и структура `District`, която съдържа в себе си до `20` града и пази текущия си размер. Всички хора също се характеризират с име, което е максимално `256` символа, както и заплата, която изкарват.

* Напишете функция, която записва в двоичен файл една област.
* Напишете функция, която прочита област от двоичен файл, след което сортира градовете в областта според броя жители и записва резултата в два различни двоични файла - съответно според сортирането, изпълнено в низходящ ред, и според сортирането, изпълнено във възходящ ред.
* Напишете функция, която чете данните от двоичния файл `People.dat` и извежда на стандартния изход хората, които изкарват над средната заплата, и хората, които изкарват под средната заплата.
* Напишете методи за добавяне и премахване на хора от двоичен файл.

### 💡 Примери:

```txt
```

```txt
```

```txt
```


## Задача 12 🧮 (Система Точки) 🧮

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/hard-red)

### 📖 Описание:

Да се напише програма, която чете двоичен файл, съдържащ неопределен брой двойки стойности `(x, y)`, представляващи координати в декартовата координатна система. След прочитането на данните да се изчисли центърът на тежестта на всички точки. След това да се намерят трите най-близки точки до центъра на тежестта и техните координати и да се запишат в нов двоичен файл. Тук център на тежестта означава медицентър на системата от точки.

### 💡 Примери:

```txt
Enter the file path: Points1.bin

The points are:
Point: 1.000 1.000
Point: 2.000 2.000
Point: 3.000 3.000

The MediCenter Coordinates are: 2.000 2.000

Closest Point 1 Coordinates are: 2.000 2.000
Closest Point 2 Coordinates are: 1.000 1.000
Closest Point 3 Coordinates are: 3.000 3.000
```

```txt
Enter the file path: Points2.bin

The points are:
Point: 0.000 3.000
Point: 0.500 2.500
Point: 1.000 2.000
Point: 1.500 1.500
Point: 2.000 1.000
Point: 2.500 0.500
Point: 3.000 0.000

The MediCenter Coordinates are: 1.500 1.500

Closest Point 1 Coordinates are: 1.500 1.500
Closest Point 2 Coordinates are: 1.000 2.000
Closest Point 3 Coordinates are: 2.000 1.000
```

```txt
Enter the file path: Points3.bin

The points are:
Point: 1.000 1.000
Point: 2.000 2.000
Point: 3.000 3.000
Point: 1.000 1.000
Point: 2.000 2.000
Point: 3.000 3.000
Point: 9.000 9.000
Point: 9.000 9.000
Point: 9.000 9.000

The MediCenter Coordinates are: 4.333 4.333

Closest Point 1 Coordinates are: 3.000 3.000
Closest Point 2 Coordinates are: 3.000 3.000
Closest Point 3 Coordinates are: 2.000 2.000
```


## Задача 13 🕵️ (Криптиране) 🕵️

### 🧠 Сложност: &nbsp; ![Static Badge](https://img.shields.io/badge/impossible-black)

### 📖 Описание:

Да се направи програма, която "разшифрова" скрито съобщение.

Съобщението представлява двоичен файл с неизвестна дължина. Това, което съхранява, е поредица от цели неотрицателни числа, кодиращи латинската азбука. "Ключът" за съобщението се съхранява в друг двоичен файл и представлява цяло число в интервала `[ 0 ; 255 ]`. Преценете как е най-подходящо да прочетете и съхраните ключа. Шифърът за получаване на правилното съобщение е към всяко число от прочетения файл, съдържащ съобщението, да се добави стойността на прочетения ключ. Изведете разшифрованото съобщение на стандартния изход.

### 💡 Примери:

```
```

```
```

```
```



</div>
