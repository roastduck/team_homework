:1
matrix_make.py > matrix.in
matrix_force < matrix.in > matrix.out
matrix_swj < matrix.in > matrix.ans
spj matrix.in matrix.out matrix.ans spj.log
set /p a=<spj.log
if %a%==0 pause
goto 1
