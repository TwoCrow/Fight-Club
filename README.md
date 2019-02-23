# Fight-Club
An independent project that generates random fighters that fight against one another.

PLEASE NOTE
---
This program is HORRIBLY UNFINISHED. It's just a fun little project that I started working on in my spare time. In its current state,
it is very unfinished, and I don't doubt that I am causing a memory leak somewhere. I am ignoring these for now in the interest of having the program working for a single, less-complex task: generating the fighters.

As I work on the program, I will update the code here and update this readme to reflect these changes.

Program Overview - Unfinished State (or Build v. 0.1)
---
Currently, the program generates 10 random fighters, and prints the data associated with each fighter to the screen.

The data that is printed follows this template:
<first name> <last name>, <age>
Weight: <weight>
Fighting Style: <fighting style>
Record: <wins>-<losses>

Each of these values are randomly generated. The first and last names for each fighter are randomly picked from the first-names.txt and
last-names.txt files.

Program Overview - Intended State (or Build v. 1.0)
---
At the end of the program, I hope to implement the following functionalities, and fix these issues:

1. Eliminate all memory leaks.
2. Have 8 fighters randomly generated each time on startup of the program.
3. Allow the user to view each of the fighters before the first round.
4. Allow the user to bet on the outcome of each round.
5. Implement an algorithm to calculate a fighter's "fight score", which determines their relative strength.
6. Possibly implement an algorithm to determine the outcome of a round beyond checking if one fight score is greater than another.
7. Allow users to meddle in the fighting by altering the fighters in some way. i.e. letting users rename fighters (for fun), and give users a method of altering the stats of the fighters
8. Implement an algorithm that creates a more accurate win-loss record, instead of having a randomly generated win-loss record.
