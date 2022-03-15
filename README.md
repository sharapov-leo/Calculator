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
EXAMPLES
  EXAMPLE 1 Grammar File Input
    Input gramma name>general
    Gramma:general.txt
  EXAMPLE 2 Evaluation of an expression
    Source>(123) * 3
    Source:temp.ss
    1|(123) * 3
    2|
    _________________
    SLA2022
    ______________________
    <-  (
    1     [ (|0| 0|  ]
    <-  $dec
    2     [ 123|0| 0|  ]
        T4 -> $dec #13
    3     [ 123|0| 0| 123 ]
        T3 -> T4 #10
    4     [ 123|0| 0| 123 ]
        T2 -> T3 #7
    5     [ 123|0| 0| 123 ]
        T1 -> T2 #3
    6     [ 123|0| 0| 123 ]
         E -> T1 #2
    7     [ 123|0| 0| 123 ]
    <-  )
    8     [ )|0| 0|  ]
        T4 -> ( E ) #14
    9     [ (|0| 0| 123 ]
        T3 -> T4 #10
    10     [ (|0| 0| 123 ]
    <-  *
    11     [ *|0| 0|  ]
    <-  $dec
    12     [ 3|0| 0|  ]
        T4 -> $dec #13
    13     [ 3|0| 0| 3 ]
        T3 -> T3 * T4 #11
    14     [ (|0| 0| 369 ]
        T2 -> T3 #7
    15     [ (|0| 0| 369 ]
        T1 -> T2 #3
    16     [ (|0| 0| 369 ]
         E -> T1 #2
    17     [ (|0| 0| 369 ]
         S -> E #1
    Code:
    369
```
