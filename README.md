# Magic-with-Cpp
Cpp codes to interesting statements
## Problem 1: No accident, please
Given 3 different sets of coordinates of airports for ‘N’ different flights started from the same
point of time and place. Draw the flight path for the individual flights such that there is no
intersection of flight paths for safety and optimization.
For example:

Input :

Flight 1: 1,1 2,2 3,3

Flight 2: 1,1 2,4 3,2

Flight 3: 1,1 4,2 3,4

![erfv](https://github.com/user-attachments/assets/ed82f474-eb13-4cb0-84b2-0f5ea292557b)





## Problem 2: My Money My Shares
Ram, Sham and Rahim went for shopping apples. They bought an apple worth 100 rupees.
Ram paid 50 rupees, Sham paid 30 rupees and Rahim paid 20 rupees. Each apple is tagged
with its weight on it. Write a program to distribute apples such that the quantity of apples they
get is in best proportionate to the amount they paid.
Note: you cannot cut an apple into pieces have to allocate the whole apple to one of them.
For example :
If there are 8 apples of 400g, 100g, 400g, 300g, 200g, 300g,100g, and 200g then we can
distribute them as

Ram : 400g , 400g , 200g (total 1kg , 50%)

Sham : 300g , 300g (tatal 600g , 30%)

rahim , 200g , 100g , 100g (tatal 400g , 20%)

Expected program output :
run distribute_apple

Enter apple weight in grams (-1 to stop ): 400

Enter apple weight in grams (-1 to stop ): 100

Enter apple weight in grams (-1 to stop ): 400

Enter apple weight in grams (-1 to stop ): 300

Enter apple weight in grams (-1 to stop ): 200

Enter apple weight in grams (-1 to stop ): 300

Enter apple weight in grams (-1 to stop ): 100

Enter apple weight in grams (-1 to stop ): 200

Enter apple weight in grams (-1 to stop ): -1

Distribution Result :

Ram: 400 400 100

Sham: 300, 300

Rahim : 200 , 100 , 100

## Problem 3: Kill All And Return Home
Assume you have a chessboard.
Place ‘soldiers’ on random cells on the board.
Then, place a ‘specialized castle’ in a random cell.
The properties of the ‘special castle’ are the following:

1. It can only move in front.

2. When it ‘kills’ a soldier, will only move to ‘it's left’

3. When it ‘kills’ a soldier, the cell becomes empty

4. Important: It can ‘jump’ over soldiers.

The following picture demonstrates 3 ways a ‘specialized castle’ can come ‘home’

![iohkjbscd](https://github.com/user-attachments/assets/f4807c52-3718-4a25-b9e6-829699a53a3b)


Red Path:

1. Starting cell: (1,2)

2. Kill at (1,9). Then, turn left.

3. Jump over (5,9), Kill at (8,9). Then, turn left

4. Kill at (8,2). Then, turn left

5. Jump over (4,2). Return home

Green Path:

1. Starting cell: (1,2)

2. Kill at (1,9), then turn left

3. Kill at (5,9), then turn left

4. Kill at (5,6), then turn left

5. Kill at (2,6), then turn left

6. Kill at (2,8), then turn left

7. Kill at (4,8), then turn left

8. Jump over (4,2), Kill at (4,1), then turn left

9. Kill at (1,1), then turn left

10. Go home to (1,2)

Write a program for the above game, sample output is given below :

Run Program :

find_my_home_castle –soldiers 11

Enter coordinates for soldier 1: 1,1

Enter coordinates for soldier 2: 8,9

Enter coordinates for soldier 3: 1,9

Enter coordinates for soldier 4: 4,1

Enter coordinates for soldier 5: 4,2

Enter coordinates for soldier 6: 4,8

Enter coordinates for soldier 7: 2,6

Enter coordinates for soldier 8: 5,6

Enter coordinates for soldier 9: 8,2

Enter coordinates for soldier 10: 5,9

Enter coordinates for soldier 11: 2,8

Enter the coordinates for your “special” castle: 1,2

Thanks. There are 3 unique paths for your ‘special_castle’

Path 1

=======

Start (1,2)

Kill (1,9). Turn Left

Jump (5,9)

Kill (8,9). Turn Left

Kill (8,2). Turn Left

Jump (4,2).

Arrive (1,2)

Path 2:

=======

Start: (1,2)

Kill (1,9). Turn Left

Kill (5,9). Turn Left

Kill (5,6). Turn Left

Kill (2,6). Turn Left

Kill (2,8). Turn Left

Kill (4,8). Turn Left Jump (4,2).

Kill (4,1). Turn Left

Kill (1,1). Turn Left

Arrive (1,2)

Path 3:

=======

Note to students: You know what Path 3 should look like.







