//File Name: Rock Paper Scissors.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Assignment Number: 2
//Description: 
/*
 * Write a C++ program that plays the game of Rock Paper Scissors with a human player.
 * Each game has two players and consists of several rounds. During each round, each player simultaneously chooses rock, paper, or scissors.
 * For this assignment, a game consists of 20 rounds.
 * The winner of each round is determined as follows:
 *
 	 • Rock can break scissors, so rock wins over scissors.
 	 • Paper can cover rock, so paper wins over rock.
 	 • Scissors can cut paper, so scissors win over paper.
 	 • It’s a tie if both players chose the same thing.
 */
//Last Changed: Feb 3, 2017

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_ROUNDS = 20;  // max rounds per game

enum Player { HUMAN, COMPUTER, TIE };   // players and winners
enum Thing  { ROCK, PAPER, SCISSORS };  // what each player chooses

int human_choice ();
int computer_choice();
int winner (int human_input, int computer_input);

// Call by reference to retain the number of wins of each player to print the summary
void record_win (int &human_wins, int &computer_wins, int &ties, int round_winner);

void summary(int human_wins, int computer_wins, int ties);

/**
 * The main. Play a game consisting of MAX_ROUNDS.
 * Print the number of human player wins, computer wins, and ties.
 */

int main()
{
  int human_wins = 0;
  int computer_wins = 0;
  int ties = 0;
  int round, human_input, computer_input, round_winner;
  for (round=1; round <= MAX_ROUNDS; round++) // iterate the game for 20 rounds
  {
    cout << "Round " << round << endl;
    human_input = human_choice(); // get the human player's choice
    while ( 3 == human_input) // an invalid choice has been entered by human player
      human_input = human_choice(); // get a valid human player's choice

    //The random seed is initialized to a value representing the current time (calling time) to generate a different value for every iteration
    srand(time(NULL));  // seed the random number generator

    computer_input = computer_choice(); // get computer's choice using random number generator

    round_winner = winner(human_input, computer_input); // determine the winner of the round

    record_win (human_wins, computer_wins, ties, round_winner); // update the number of times each player won the rounds
  }
  summary(human_wins, computer_wins, ties); // print the summary of total wins of each player
  return 0;
}

void record_win(int &human_wins, int &computer_wins, int &ties, int round_winner)
{
  if (round_winner == HUMAN )
    human_wins++;
  else
    if (round_winner == COMPUTER )
      computer_wins++;
    else
      ties++;
  return;
}

int human_choice()
{
  Thing human_input;
  char human_choice_char;
  cout << "  Your choice? ";
  cin >> human_choice_char;
  switch (human_choice_char) // Accepts both lowercase and uppercase input
  {
    case 'r':
    case 'R':
      cout << endl;
      cout << "  You chose ROCK." << endl;
      human_input = ROCK;
      return human_input;
      break;
    case 'p':
    case 'P':
      cout << endl;
      cout << "  You chose PAPER." << endl;
      human_input = PAPER;
      return human_input;
      break;
    case 's':
    case 'S':
      cout << endl;
      cout << "  You chose SCISSORS." << endl;
      human_input = SCISSORS;
      return human_input;
      break;
    default:
      cout << endl;
      cout << "  *** ERROR: Valid choices are R, P, or S" << endl;
      return 3;
      break;
  }
}

int computer_choice()
{
  int computer_input;
  string computer_choice_word;
  computer_input = rand() % 3; //computer_input will be in the range of 0 to 2
  switch (computer_input)
  {
    case ROCK:
      computer_choice_word = "ROCK.";
      break;
    case PAPER:
      computer_choice_word = "PAPER.";
      break;
    case SCISSORS:
      computer_choice_word = "SCISSORS.";
      break;
  }
  cout << "  The computer chose " << computer_choice_word << endl;
  return computer_input;
}

int winner (int human_input, int computer_input)
{
  Player round_winner;
  if ((human_input == ROCK && computer_input == SCISSORS) || (human_input == PAPER && computer_input == ROCK) || (human_input == SCISSORS && computer_input == PAPER))
  {
    cout << "  The winner is you." << endl;
    cout << endl;
    round_winner = HUMAN;
  }
  else
  if ((computer_input == ROCK && human_input == SCISSORS) || (computer_input == PAPER && human_input == ROCK) || (computer_input == SCISSORS && human_input == PAPER))
  {
    cout << "  The winner is the computer." << endl;
    cout << endl;
    round_winner = COMPUTER;
  }
  else
  {
    cout << "  It is a tie." << endl;
    cout << endl;
    round_winner = TIE;
  }
  return round_winner;
}

void summary(int human_wins, int computer_wins, int ties)
{
  cout << "Summary" << endl;
  cout << "-------" << endl;
  cout << setw(15) << right << "Human wins: " << human_wins << endl;
  cout << setw(14) << right << "Computer wins: " << computer_wins << endl;
  cout << setw(15) << right << "Ties: " << ties << endl;
  return;
}
