/********************************************************
This header file is used to store the constants used in
our program. At this time it only defines one constant--PI.

The constants are wrapped in a preprocessor directive that
ensures that the contents of this header file are included
by the compiler only once, even if perhaps nested modules
in a modular program instruct the compiler to include
this header file.
********************************************************/
#ifndef _CONST_H_INCLUDED_



const double PI = 3.14159;



#define _CONST_H_INCLUDED_
#endif /* _CONST_H_INCLUDED_ */
