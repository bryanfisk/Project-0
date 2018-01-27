Project 0 for CMP SCI 2250
1/26/18

Project stipulations: 

In this project you will be tasked with writing a program to play a guessing game between another player and your program. Your program will start by initializing an array to 5 fixed values in the ranges of 1-1000 in the array. These values should also be in order (sorted).

Your program will then begin by asking the player to make a guess from 1-1000. For the first guess of the user, your program will only tell the player if they guessed correctly or not. However, the program will keep track of how close they are to the closest element in the array. The program will then go into a loop, asking the player for a new guess each time. If at any time, their new guess is farther away from the closest number than their previous guess, the program will respond with “Getting colder!”. If they get closer to a correct guess, the program should respond with “Getting warmer!”. This should continue until the player guesses one of the numbers in the list. Your program should then output “Success!” and then end.

Example:

Hello, please try and guess one of my numbers between 1and 1000.

Please make a guess: 75

I am sorry, that is incorrect!

Please make a guess: 80

Getting warmer!

Please make a guess: 85

Getting warmer!

Please make a guess: 90

Getting colder!

Please make a guess: 87

Success!

 Your program should contain the following function:

int distanceToClosest(const int solutions[],int SIZE, int guess);

 

This function should take in a sorted array and find the smallest absolute difference between the parameter guess and any member of the solutions array.

 

Error conditions: Your program should make sure the guesses are between 1 and 1000. Guesses outside of the valid range should result in an error message. You can assume the responses are integers.

