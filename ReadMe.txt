'cs507-spring2015-assignment5' repository has two folders :

1. Calculator
2. ExpressionGenerator

============================================================================================================================================================

Calculator :

It contains all the .cpp, .h, and .inl files that have been created for the expression evaluator or calculator project.
This folder also contains the assignment5.mpc file that is used for generating make file or solution file.

 

Steps for running the expression evaluator or calculator application with example:

1. When you run the application, the program will show you the list of strategies as follows :


   Select the strategy no. that you wish to implement
   1 : Postfix
   2 : Postfix - Flyweight
   3 : Postfix - Flyweight and Performance For Add
   4 : Tree
   Enter Strategy No  :



2.Now suppose one wishes to execute the Tree strategy,then one needs to enter 4. 
  The program will then ask you to enter inputfile name -

  Select the strategy no. that you wish to implement
  1 : Postfix
  2 : Postfix - Flyweight
  3 : Postfix - Flyweight and Performance For Add
  4 : Tree
  Enter Strategy No  :4
  Enter input file name :

3.Here we need to provide the entire file path of the file along with the file name and file extension.
  However suppose we want to input a type2_2100.txt which is present in the Calculator folder, we simply have to enter the file name

  Select the strategy no. that you wish to implement
  1 : Postfix
  2 : Postfix - Flyweight
  3 : Postfix - Flyweight and Performance For Add
  4 : Tree
  Enter Strategy No  :4
  Enter input file name :type2_2100.txt


4.After we enter the file name , the program will start executing all the input expressions present in the input file and finally give result as shown below:

  The result = 313
  The result = 1
  The result = 3
  The result = 11
  The result = 0
  The result = 66
  Total expressions = 2100
  The total execution time for Tree Evaluator= 7804
  Do you wish to check for another type of strategy ? (yes / no) :

5.If we enter 'yes' the program will again ask us to select strategy thus looping itself.
  If we select 'no' the program will exit.




============================================================================================================================================================

ExpressionGenerator :

It is the random input expression generator that is being used for creating input expressions. 


Steps for running the expression generator application with example:

1.When you run the application, it will ask you to enter the total no of expressions that you want to enter in the input file as shown below :

  Enter the total no. of expressions that you wish to create :

2. After entering the total no. of expressions it will ask you to enter the expression type.

   The expression type is the combination of 'operator', 'number', '+', '(' and '('.
   For example for creating expressions of type : 
   ( 10 / 5 ) * 5, the input expression type will be : ( number operator number ) operator number 

   However we have also separately provided a '+' symbol for generating expressions that have majority of + operators. 
   For example if we want to generate an expression in which the first operator is always '+' 
   such as 3 + 4 - 5 then the input expression type will be :  number + number operator number 


   Once you enter the expression type , it will prompt you to enter the input file name. Here we need to enter the entire input file path, its name followed by the        file extension. However suppose one wants the files to be created in the ExpressionGenerator folder itself, one only needs to enter the file name.
   
   For Example :

   Enter the total no. of expressions that you wish to create :100
   Enter expression type using a combination of 'operator' , 'number', + , '(' and
   ')' :
   number operator number
   Enter the name of the input file :
   sample1_100.txt



3. After entering the file name, the file will get created and all the expressions will be copied to it and the program will ask us if we wish to create another input     file:

   70 - 89
   2 % 56
   24 * 86
   83 + 89
   27 * 58
   33 * 70
   55 - 90
   Do you wish to generate another type of expression input file (yes / no) :



4. If we enter yes, the program will loop back and if we enter no, the program will exit.


   
============================================================================================================================================================

ValgrindReports:

This folder is present inside the Calculator folder and it contains the Valgrind reports for individual Expression types. 

For example: 
ExpressionType1_valgrind-report contains the valgrind report that has been generated for all type1 expression files ( i.e. type1_500.txt, type1_1100.txt and type1_2100.txt) executed against all the four versions of calculator (i.e. all the four strategies ).

Similar is the case with ExpressionType2_valgrind-report, ExpressionType3_valgrind-report and ExpressionType4_valgrind-report files.


============================================================================================================================================================


Input files : 

All the input files that were used for testing have been placed in the Calculator folder. The naming convention for the file is 'expressionType_noOfExpressions.txt'

For example : type1_500.txt signifies that the file contains 500 expressions of type1.

type1_500.txt, type1_1100.txt, type1_2100.txt, type2_500.txt, type2_1100.txt, type2_2100.txt, type3_500.txt, type3_1100.txt, type3_2100.txt, type4_500.txt, type4_1100.txt and type4_2100.txt are the 12 input files that were used for performance evaluation.

All the input files were generated using the Expression Generator program.


============================================================================================================================================================

Machine Specs : 

Operating System : Windows 7 Ultimate.

Installed memory (RAM) : 4.00 GB 

Processor : Intel(R) Core(TM) i3 CPU M 370 @ 2.40 GHz 2.39 GHz  

System type : 64-bit Operating System

============================================================================================================================================================

NOTE : In the execution of my assignment for strategy pattern, for evaluation of a particular input file the program stops after it encounters end of file instead of QUIT and it asks the user whether he wishes to continue further.
