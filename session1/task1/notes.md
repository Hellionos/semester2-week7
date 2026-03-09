from python code:
python crash.py
Traceback (most recent call last):
  File "/workspaces/semester2-week7/session1/task1/crash.py", line 9, in <module>
    assign_values(data)
  File "/workspaces/semester2-week7/session1/task1/crash.py", line 5, in assign_values
    x[i] = (i + 1) * (i + 1);
    ~^^^
IndexError: list assignment index out of range

from c code:
gcc crash.c -o crash && ./crash
Done!
*** stack smashing detected ***: terminated
Aborted (core dumped)

how do these crashes differ?


which program would be easier to debug on the basis of its observed behaviour? why?
the python program would be easier to debug because the error message gives more information about what has gone wrong and where in the code is the bug