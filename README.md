# Coding excercises in C++14

I have programmed computers since I was a kid, but my academic training
is in computational physics. As a Ph. D. student at the University of
Illinois, I taught myself C++ and Java, reading 
[_Design Patterns_][gof]
by the Gang of Four and Bjarne Stroustrup's tome 
[_The C++ Programming Language_][stroustrup]
cover to cover. Nevertheless, my computing skills are heavy on numerical
methods, especially Monte Carlo techniques for many-body quantum physics 
([pi-qmc][piqmc]) and linear algebraic techniques for implicit 
solutions to partial differential equations ([ECHELON][echelon]). 
Since then I have also studied software craftsmanship, which offers 
another beautiful and practical perspective computer programming.

Mid-career, I decided to leave behind my physics professorship and
embrace the life of a software developer. As part of this, I have tried 
to learn how computer scientists think. About five years ago, my friend,
the very insightful Nicholas Vaidyanathan, told me I should formally learn 
computer algorithms. I followed up by taking soom MOOC classes on algorithms
and confirmed that there was a lot I could learn.

Recently Nick pointed me to Gayle Laakmann McDowell's incredible book, 
[_Cracking the Coding Interview_][mcdowell]. This gem is exactly what I needed! 
In physics, I have guided so many students through professional development,
carefully teaching and testing them to think like physicists. Problem
solving is critical, being able to do things like calculating the crtitical
temperature for Bose-Einstein Condensation on a white board starting from
fundamental physics concepts and calculus technques. McDowel's book is an
incredible overview of the Computer Science canon of problems, organized by
concept, and laid out ingeniously with progressive hints and beautiful 
discussions of possible solutions.

In an effort to become a better C++ programmer, I am tackling these problems.
Because I work with C++14 and CUDA in my job as Software Engineering
Manager at Stone Ridge Technology, I am using this as an opportunity to
better understand C++14 and the Standard Template Library (STL). So far, the
experience has been very rewarding. I have read most of the chapters
and questions, but not the solutions. Day by day, I have been pondering these
problems without writing code, studying my thought process and filling
in gaps in my knowledge of algorithms and details of the C++14 STL.
Now I am in the process of testing myself by writing solutions in my
vim editor and seeing if they work. This github repo is my log of this
process.

One note on style: I am intentionally keeping this code sparse and simple.
My emphasis is whether I can see that my solutions are clear and correct.
In my professional work, I focus on code that is understandable by others:
clear variable and function names, well designed classes, descriptive
unit test coverage, and appropriate comments. That is not my goal in these
problems! Further, to respect Ms. McDowell's excellent work, I am not
restating her questions or giving much context. Please buy her book, read it,
and enjoy it for yourself.


[stroustrup]: http://stroustrup.com/4th.html
[gof]: https://en.wikipedia.org/wiki/Design_Patterns
[piqmc]: https://github.com/phys-tools/pi-qmc
[echelon]: http://stoneridgetechnology.com/echelon
[mcdowell]: http://www.gayle.com/books/
