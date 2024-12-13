
#include <iostream> 
#include <cmath>
#include <iomanip>
#include <unistd.h>

using namespace std;

// determines whether its the users turn or the computers turn
bool isComputersTurn(int cmptStatus);
bool isPlayersTurn(int playerStatus);

bool playerWonStatus(int playerScore, int computerScore); // evaluates the final outcome of the game; if human wins, return true.

int main() {
 


	int playerPebblesTaken;
	int computerPebblesTaken;
	int totalPebbles = 21;
	
	// scores for human and computer scores; increment later when one wins
	int playerScore = 0;
	int computerScore = 0;
    
    cout << "21   ______   ______  ______   ______   _        ______  ______  \n";
    cout << "    | |  | \\ | |     | |  | \\ | |  | \\ | |      | |     / |      \n";
    cout << "    | |__|_/ | |---- | |--| < | |--| < | |   _  | |---- '------. \n";
    cout << "    |_|      |_|____ |_|__|_/ |_|__|_/ |_|__|_| |_|____  ____|_/ \n";
    cout << "_________________________________________________________________\n";
	
	// turn status; determines whos turn is it 
	int playerStatus = 0;
	int cmptStatus = 1; // set cmptStatus as true first, because computer goes first
	
	cout << "Welcome to... \n";
	
	cout << "Loading game\n";
	sleep(3); // loading game for 3 seconds 
	
	cout << "Let's play!\n";

	
	do {
	    
	    // computer chooses between 1 and 3 everytime; srand(time(0)) allows for different sequence to be generated every run
	    srand(time(0));
	    computerPebblesTaken = (rand() % 3) + 1;
	    
		if (isComputersTurn(cmptStatus) == true) {
			
		      cout << "Computer is thinking...\n";
			  sleep(2);
			  
			  // case when computer takes the last few pebbles
			  if (computerPebblesTaken >= totalPebbles) {
			      computerPebblesTaken = totalPebbles;
			      totalPebbles -= computerPebblesTaken;
			      cout << "Computer takes " << computerPebblesTaken << " pebbles\n";
			      cout << "There are " << totalPebbles << " pebbles left\n";
			      ++playerScore;
			      
			  } else if (computerPebblesTaken < totalPebbles) {
			      
			        totalPebbles -= computerPebblesTaken;
			        cout << "Computer takes " << computerPebblesTaken << " pebbles\n";
			        cout << "There are " << totalPebbles << " pebbles left\n";
			        --cmptStatus;
			        ++playerStatus;
			  }
			  
			  
			  
		        
		} else if (isPlayersTurn(playerStatus) == true) {
			  cout << "Enter the number of pebbles you would take between 1 and 3:\n";
			  cin >> playerPebblesTaken;
			  
			  if (playerPebblesTaken < 0 || playerPebblesTaken > 3 || playerPebblesTaken > totalPebbles) {
			      cout << "Sorry, you cannot do that. Please try again!\n";
			
			  } else if (playerPebblesTaken < totalPebbles) {
			      totalPebbles -= playerPebblesTaken;
			      cout << "You took " << playerPebblesTaken << " pebbles\n";
			      cout << "There are " << totalPebbles << " pebbles left\n";
			      --playerStatus;
			      ++cmptStatus;
			      
			 // end of game condition when player is forced to take all the pebbles
			  } else if (playerPebblesTaken == totalPebbles) {
			      totalPebbles -= playerPebblesTaken;
			      cout << "You took " << playerPebblesTaken << " pebbles\n";
			      cout << "There are " << totalPebbles << " pebbles left\n";
			      ++computerScore;
			  }
			  
			  
		
		}
	
	} while (totalPebbles > 0);
	
    
	
	cout << "Game over -";
    
    if (playerWonStatus(playerScore, computerScore) == true) {
        cout << " player wins!";
    } else {
        cout << " computer wins!";
    }
			
	
	


}


bool isComputersTurn(int cmptStatus) { 
	if (cmptStatus == 1) {
		return true;
	} else {
		return false;
	}

}

bool isPlayersTurn(int playerStatus) {
	if (playerStatus == 1) {
		return true;
	} else {
		return false;
	}
}

bool playerWonStatus(int playerScore, int computerScore) {
    
    if (playerScore > computerScore) {
        return true; // if player wins, return true
    } else {
        return false; // if computer wins, return false
    }
    
}


