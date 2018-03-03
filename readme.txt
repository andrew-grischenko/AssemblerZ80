*** Z80 Assembler ***

[ENG]
This assembler is developed for assembling source files written on 
the ZILOG Z80 assembler language. Full command set is supported. This 
version has such restrictions as:
- expressions are not supported, it means that the command ADD A,35+34
  will not be recognized;
- identifier length < 30 chars;
- the number of identifiers < 300;

Using.
  asm_z80.exe file.asm
Generated files:
  - file.lst - list file;
  - file.map - lable table;
  - file.bin - binary file;

Copyrights. The author of this product is Hryshchenko Andrew 
(vital@akcecc.kiev.ua). Using of this product is absolutely free. 
Author is not responsible of any damage, both direct and inderect, 
that may cause using of this product. Source code modification is 
free with the condition that modification author and purposes should 
be noted in readme.txt

[RUS]
Этот ассемблер предназначен для ассемблирования исходных файлов на 
языке ассемблера процессора Zilog Z80. Поддерживается полный набор 
команд. Данная версия имеет существенное ограничение: 
  - не поддерживаются выражения, т.е. команда ADD A,35+45 не будет 
    распознана как корректная;
  - длина идентификаторов < 32 симвлов;
  - количество идентификаторов < 300;

Использование.
  asm_z80.exe file.asm
Генерируемые файлы:
  - file.lst - листинг;
  - file.map - таблица меток;
  - file.bin - двоичный файл;

Авторские права. Разработчиком данного продукта является 
Грищенко Андрей (vital@akcecc.kiev.ua). Использование данного продукта
и исходных файлов абсолютно свободное. Автор не несет никакой 
ответственности за возможный ущерб, как прямой так и косвенный, от 
использования данного продукта. Модификация исходных кодов свободна 
при условии указания в сопроводительной записке автора и цели
модификации.

*** END ***