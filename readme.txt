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
���� ��������� ������������ ��� ��������������� �������� ������ �� 
����� ���������� ���������� Zilog Z80. �������������� ������ ����� 
������. ������ ������ ����� ������������ �����������: 
  - �� �������������� ���������, �.�. ������� ADD A,35+45 �� ����� 
    ���������� ��� ����������;
  - ����� ��������������� < 32 �������;
  - ���������� ��������������� < 300;

�������������.
  asm_z80.exe file.asm
������������ �����:
  - file.lst - �������;
  - file.map - ������� �����;
  - file.bin - �������� ����;

��������� �����. ������������� ������� �������� �������� 
�������� ������ (vital@akcecc.kiev.ua). ������������� ������� ��������
� �������� ������ ��������� ���������. ����� �� ����� ������� 
��������������� �� ��������� �����, ��� ������ ��� � ���������, �� 
������������� ������� ��������. ����������� �������� ����� �������� 
��� ������� �������� � ���������������� ������� ������ � ����
�����������.

*** END ***