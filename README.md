# Calculator

Основой данной работы является транслятор кода, принадлежащий Голикову Константину Павловичу, который преподает в Московском Авиационном Институте.
Вместе с моими длинной арифметикой, лексическим анализатором, грамматикой и правилами трансляции получается калькулятор целых неотрицательных больших чисел.

```
NAME
  calc - non-negative integer calculator
DESCRIPTION
  The Calc utility is a code translator. It is supposed to take the name of the grammar file. You need to enter "general". Data from standard input is written to the temp file. In the input line, you can specify the name of the file to be translated. If it is written without an extension, then the program looks for a file with the same name, but with the .txt extension. The translation result is sent to the standard output and to the temp file.
LEXICAL CONVENTIONS
  $dec - number
  $id - identificator
  $bool - constants #t and #f
  $oper - operators
    + addition
    - subtraction
    * multiplication
    / division
    < less than
    > greater than
    == equality
GRAMMAR
  <sentence> ::= <expression>
  <expression> ::= <t1>
  <t1> ::= <t2> |
           <t1> < <t2> |
           <t1> > <t2> |
           <t2> == <t2>
  <t2> ::= <t3> |
           <t2> + <t3> |
           <t2> - <t3>
  <t3> ::= <t4> |
           <t3> * <t4> |
           <t3> / <t4>
  <t4> ::= $dec |
           ( <expression> )
```
