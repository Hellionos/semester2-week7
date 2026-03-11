# Task 2

## `undefined.c`

1. Compile  `undefined.c` without any special compiler options:

       gcc undefined.c

2. Run the compiled program to see what it does:

       ./a.out

      :-1539802837

   **Then remove `a.out`**.

3. Recompile `undefined.c`, this time using the `-Wall` option:

       gcc -Wall undefined.c

   What do you see in the terminal?

   undefined.c: In function ‘main’:
undefined.c:9:7: warning: ‘i’ is used uninitialized [-Wuninitialized]
    9 |     j = i + 3;
      |     ~~^~~~~~~
undefined.c:7:9: note: ‘i’ was declared here
    7 |     int i, j;
      |         ^

4. Run the program to verify that behaviour is unchanged, :-1889491157
   **then remove `a.out` once again**.

5. Recompile `undefined.c` using the `-Wall` and `-Werror` options. Does the
   compiler output change in any way? Is an executable generated?
   -Werror gave no error
   :1711717691

   when Werror and Wall ar used together
   undefined.c: In function ‘main’:
undefined.c:9:7: error: ‘i’ is used uninitialized [-Werror=uninitialized]
    9 |     j = i + 3;
      |     ~~^~~~~~~
undefined.c:7:9: note: ‘i’ was declared here
    7 |     int i, j;
      |         ^
cc1: all warnings being treated as errors

## `double_free.c`

1. Compile `double_free.c` using the `-Wall`, `-Wextra` and `-Werror`
   compiler options. Do you see any messages from the compiler?
   Does compilation succeed?

    gcc -Wall -Wextra -Werror double_free.c
double_free.c: In function ‘main’:
double_free.c:16:5: error: pointer ‘a’ used after ‘free’ [-Werror=use-after-free]
   16 |     free(a);
      |     ^~~~~~~
double_free.c:14:5: note: call to ‘free’ here
   14 |     free(a);
      |     ^~~~~~~
cc1: all warnings being treated as errors

2. Run the compiled program. What happens? Do you get any clues about what
   has gone wrong?

   free(): double free detected in tcache 2
   Aborted (core dumped)

   The free() function seems to try to clear the allocated memory of the array(?) two seperate times

3. Repeat Step 1 for `crash.c` from Task 1. What can you conclude from these
   experiments about the compiler options that you have used?
   
-Wall

Enables a broad set of common and important warnings.
Despite the name, it does not enable all warnings—it’s a sensible baseline.
Typical things it catches:

Unused variables or functions
Suspicious if conditions
Possible use of uninitialized variables (in some cases)
Implicit function declarations (C99+ treats this as an error by default)
Missing return statements in non-void functions



-Wextra

Turns on additional warnings that are more opinionated or noisy than -Wall.
Examples:

Unused parameters
Signed/unsigned comparison peculiarities in some cases
Extra checks around conditionals and conversions that aren’t severe enough for -Wall but still helpful




In short: -Wall = “common issues”, -Wextra = “more thorough scrutiny”.

-Werror

Treats all warnings as errors (compilation fails if there’s any warning).
Great for CI and enforcing code hygiene.
You can narrow it with -Werror=warning-name or loosen it with -Wno-error=warning-name.