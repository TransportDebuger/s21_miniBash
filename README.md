# s21_miniBash

���������� ������ Bash �� ������ � �������: cat, grep.

## Information

### cat �������

> cat ��� ������ ������ ������ Unix, ��������, ������ 1, � ������� pr, ������� PDP-7 � Multics ��� ����������� ������ ����� �� �����.

### cat �������������

Cat - ���� �� �������� ����� ������������ ������ � Unix-�������� ������������ ��������. ������� ����� ��� ��������������� ������� � ��������� ��������� ������: �����������, ����������� �� ����� � �������� �����.

`cat [OPTION] [FILE]...`

### cat �����

| � | ����� | �������� |
| ------ | ------ | ------ |
| 1 | -b (GNU: --number-nonblank) | �������� ������ �������� ������ |
| 2 | -e ������������ � -v (GNU only: -E �� �� �����, �� ��� ���������� -v) | ����� ���������� ������� ����� ������ ��� $  |
| 3 | -n (GNU: --number) | �������� ��� �������� ������ |
| 4 | -s (GNU: --squeeze-blank) | ������� ��������� ������� ������ ����� |
| 5 | -t ������������ � -v (GNU: -T �� �� �����, �� ��� ���������� -v) | ����� ���������� ���� ��� ^I |

### grep �������

> ������� ������� ������ ������ �� PDP-11 ����� ����������, ����� ������ �� �. ���������. ���������������� ����� ������� ����������� ��� ����, ����� ���������� ��������� ��������� ������. ��������� �������� ed (����� ��������� ���������) ���� ��������� ���������� ���������, �� �� ��� �������������� ��� ������ �������� ������ ������, ������� ������� ������ ���� ��� � ��������� ����������. �� ������ ��� ��������, ������ ��� � ed ������� g / re / p �������� ��� ������, ��������������� ��������� �������. 
grep ������� ��� ������� � ������ 4 Unix. ������, ��� �� ������� ����������� ��� �������� ������������ ��������, �������� �������� grep �������������� ��������� ��������� ������������ �������� � Unix.

### grep �������������

`grep [options] template [file_name]`

### grep �����

| � | ����� | �������� |
| ------ | ------ | ------ |
| 1 | -e | ������ |
| 2 | -i | ���������� �������� ��������.  |
| 3 | -v | ����������� ����� ������ ������������. |
| 4 | -c | ������� ������ ���������� ����������� �����. |
| 5 | -l | ������� ������ ����������� �����.  |
| 6 | -n | ���������� ������ ������ ������ ������� ������ �� ����� �����. |
| 7 | -h | ������� ����������� ������, �� ��������� �� ������� ������. |
| 8 | -s | ��������� ��������� �� ������� � �������������� ��� ���������� ������. |
| 9 | -f file | �������� ���������� ��������� �� �����. |
| 10 | -o | �������� ������ ����������� (��������) ����� ��������� ������. |

## �������

- ��������� ������ ���� ����������� �� ����� �� ��������� C11 � �������������� ����������� gcc 
- ��� �������� cat � grep ������ ���������� � ����� develop � ������ src/cat/ � src/grep/ ��������������  
- �� ������������ ���������� � ���������� �� ������������ ����������� ����� � ������������ �������. �������� �������� �� ������� legacy � obsolete � ����������� ������������ �� ����� � ������������ �����������. ��������������� �� �������� POSIX.1-2017 
- ��� ��������� ���� ���������� �������������� Google Style
- ��������� ������ ������������ ����� ����������� ���� � ����������� ��������� ������
- ������ �������� ������ ���� ��������� � ������� Makefile � ���������������� ������: s21_cat, s21_grep  
- ���� ������������ ��������� ����������, � Makefile ������ ���� �������� �������� ������, ����������������� �� �����������/�������� 
- ���������� �������� ��������������� ������� ��� ���� ��������� ������ � ������� ��������, �� ���� ��������� � ���������� �������� ������ Bash
- ��������� ������ ���� ����������� � ������������ � ���������� ������������ ����������������
- ���������� ��������� ������������ ����, ���������������� ����� ������ ����� ���������. ����� ������ ����� ������� � ��������� ����� src/common
- ����� ������������ ����������� � ������������� ���������� ����� ��, ����� ������������ ��������������� ������������� ���������� �� ������ ��������
- ������������ ��������� ��� ������������� ��������� �������� �� ����� ��������
- ���� ����� stdin ������������ �� �����������

## ������ 1. �at

���������� ����������� ������� cat:
- ��������� ���� ������ (������� GNU ������), ��������� [����](#cat-�����)
- ��������, ������������ � ��������� ����� ������ ������������� � ���������� src/cat/
- �������� ����������� ���� ������ ������������� � ���������� src/cat/ � ���������� s21_cat

## ������ 2. grep

���������� ����������� ������� grep:
- ��������� ��������� ������: `-e`, `-i`, `-v`, `-c`, `-l`, `-n`
- ��� ���������� ��������� ����� ������������ ������ ���������� pcre ��� regex  
- ��������, ������������ � make ����� ������ ������������� � ���������� src/grep/
- �������� ����������� ���� ������ ������������� � ���������� src/grep/ � ���������� s21_grep

## ������ 3 (�������������). ���������� ��������� ������ ������� grep

�������������� ������� �� �������������� �����. ���������� ����������� ������� grep:
- ��������� ���� ������, �������: `-h`, `-s`, `-f`, `-o`
- ��� ���������� ��������� ����� ������������ ������ ���������� pcre ��� regex  
- ��������, ������������ � make ����� ������ ������������� � ���������� src/grep/
- �������� ����������� ���� ������ ������������� � ���������� src/grep/ � ���������� s21_grep

## ������ 4 (�������������). ���������� ���������� ������ ������� grep

�������������� ������� �� �������������� �����. ���������� ����������� ������� grep:
- ��������� ���� ������, ������� �� _������_ ���������� (��������, `-iv`, `-in`)
- ��� ���������� ��������� ����� ������������ ������ ���������� pcre ��� regex
- ��������, ������������ � make ����� ������ ������������� � ���������� src/grep/
- �������� ����������� ���� ������ ������������� � ���������� src/grep/ � ���������� s21_grep


**cat** - includes files for s21_cat project

**grep** - includes files for s21_grep project

**common** - includes common files for both projects
