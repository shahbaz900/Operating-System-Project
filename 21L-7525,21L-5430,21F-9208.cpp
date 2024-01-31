#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <ctime>
#include<fstream>
#include<cstdio>
#include <sys/stat.h>
#include <string>
#include<pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/fs.h>
#include <string>
#include <vector>
#include <cstdlib>
#include<algorithm>
using namespace std;
mutex mtx_a1;
mutex mtx_boot_screen;
mutex mtx_start_time_and_calendar;
mutex mtx_notepad;
mutex mtx_calculator;
mutex mtx_create_file;
mutex mtx_rock_paper_scissor;
mutex mtx_copy_file;
mutex mtx_delete_file;
mutex mtx_check_file_info;
mutex mtx_guessthenumber;
mutex mtx_create_process;
mutex mtx_process_message;
mutex mtx_grantee;
mutex mtx_interrupt;
mutex mtx_flappy;
mutex mtx_tic_tac_toe;
mutex mtx_hangman;
mutex mtx_mem_match;
int az = 0;
void boot_screen() 
{
    mtx_boot_screen.lock();
    cout << "WELCOME TO FSA OPERATING SYSTEM..." << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout << "OPERATING SYSTEM LOADED:)" << endl;
    mtx_boot_screen.unlock();
}
void* start_time_and_calendar(void*) {
    az=0;
    mtx_start_time_and_calendar.lock();
    cout << endl << "entered calendar" << endl;
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "enter 1 to break:";
    cin >> az;
    if (az == 1) {
        mtx_start_time_and_calendar.unlock();
        pthread_exit(nullptr);
    }
    cout << "The local date and time is: " << dt << endl;
    mtx_start_time_and_calendar.unlock();
    return nullptr;
}

void* notepad(void*) 
{
az=0;
cout<<endl<<"entered notepad"<<endl;
  string a,str;
  mtx_notepad.lock();
cout << "enter 1 to break:";
    cin >> az;
    if (az == 1) {
        mtx_notepad.unlock();
        pthread_exit(nullptr);
    }
  fstream ob;
  ob.open("test.txt", ios::out);  // opening file in writing mode
  
    string line;
   do {
        std::cout << "Enter input (or 'z' to exit): ";
        std::getline(std::cin, line);

        // Process input if it is not 'z'
        if (line != "z") {
            std::cout << "Input: " << line << std::endl;
        }
    } while (line != "z");
  ob.close();  // closing the file
  ob.open("test.txt", ios::in);  // again opening the file but in reading mode

  while (!ob.eof()) {
    string str1;

    ob >> str1;  // reading word by word from file and storing in str

    cout << str1 << "\n";  // printing str
  }

  ob.close();  // closing the file after use
    mtx_notepad.unlock();
 return nullptr;
}

void* calculator(void*) 
{
az=0;
cout<<endl<<"entered calculator"<<endl;
    mtx_calculator.lock();
cout << "enter 1 to break:";
    cin >> az;
    if (az == 1) {
        mtx_calculator.unlock();
        pthread_exit(nullptr);
    }
      double num1, num2;
    char op;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;

    switch (op) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1+num2 << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " <<num1-num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1*num2 << endl;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Error: cannot divide by zero" << endl;
            } else {
                cout << num1 << " / " << num2 << " = " << num1/num2 << endl;
            }
            break;
        default:
            cout << "Error: invalid operator" << endl;
            break;
    }
    mtx_calculator.unlock();
 return nullptr;
}

void* create_file(void*)
 {
az=0;
cout<<endl<<"entered cerate file"<<endl;
    mtx_create_file.lock();
cout << "enter 1 to break:";
    cin >> az;
    if (az == 1) {
        mtx_create_file.unlock();
        pthread_exit(nullptr);
    }
    string filename;
    cout << "Enter the name of the file to be created: ";
    cin >> filename;

    ofstream file(filename); // create a new file with the given filename
    if (file.is_open()) {
        cout << "File created successfully." << endl;

        // write some content to the file
        file << "Hello, this is some content written to the file." << endl;
        file << "You can write anything you want here." << endl;

        file.close(); // close the file
    } else {
        cout << "Error creating file." << endl;
    }
    mtx_create_file.unlock(); return nullptr;
}

void* rock_paper_scissor(void*)
 {
az=0;
cout<<endl<<"entered rock_paper_scissor()"<<endl;
    mtx_rock_paper_scissor.lock();
    srand(time(nullptr)); // seed the random number generator
    cout << "enter 1 to break:";
    cin >> az;
    if (az == 1) {
        mtx_rock_paper_scissor.unlock();
        pthread_exit(nullptr);
    }
    int playerChoice;
    int computerChoice = rand() % 3 + 1; // generate a random number between 1 and 3
    
    cout << "Welcome to Rock, Paper, Scissors!\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
    cout << "Enter your choice: ";
    cin >> playerChoice;
    cout << "You chose ";
    switch (playerChoice) {
        case 1:
            cout << "Rock.\n";
            break;
        case 2:
            cout << "Paper.\n";
            break;
        case 3:
            cout << "Scissors.\n";
            break;
        default:
            cout << "an invalid option.\n";
    }
    cout << "The computer chose ";
    switch (computerChoice) {
        case 1:
            cout << "Rock.\n";
            break;
        case 2:
            cout << "Paper.\n";
            break;
        case 3:
            cout << "Scissors.\n";
            break;
    }
    
    if (playerChoice == computerChoice) {
        cout << "It's a tie!\n";
    } else if (playerChoice == 1 && computerChoice == 3 || playerChoice == 2 && computerChoice == 1 || playerChoice == 3 && computerChoice == 2) {
        cout << "You win!\n";
    } else {
        cout << "You lose!\n";
    }

    mtx_rock_paper_scissor.unlock();
 return nullptr;
}

void* copy_file(void *) 
{
    mtx_copy_file.lock();
    // implementation of copy_file function
    mtx_copy_file.unlock();
return nullptr;
}

void* delete_file(void*) {
az=0;
cout<<endl<<"entered delete_file()"<<endl;
    mtx_delete_file.lock();
if (az == 1) {
        mtx_delete_file.unlock();
        pthread_exit(nullptr);
    }
    const char* file_name = "hello.cpp";
    int result = std::remove(file_name);
    if (result != 0) {
        std::perror("Error deleting file");
    } else {
        std::puts("File successfully deleted");
    }
    mtx_delete_file.unlock();
 return nullptr;
}

void* check_file_info(void*) {
az=0;
cout<<endl<<"entered checkfileinfo()"<<endl;
    mtx_check_file_info.lock();
    string filename;
if (az == 1) {
        mtx_check_file_info.unlock();
        pthread_exit(nullptr);
    }
cout<<"enter filename to check file_info";
cin>>filename;
    struct stat file_info;
    // get file information
    if (stat(filename.c_str(), &file_info) == 0) {
        // output file information
        cout << "File name: " << filename << endl;
        cout << "File size: " << file_info.st_size << " bytes" << endl;
        cout << "Last access time: " << ctime(&file_info.st_atime) << endl;
        cout << "Last modification time: " << ctime(&file_info.st_mtime) << endl;
        cout << "File permissions: " << (file_info.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO)) << endl;
    } else {
        cout << "Error: could not get file information" << endl;}
    mtx_check_file_info.unlock();
 return nullptr;
}

void* guessthenumber(void*) {
az=0;
cout<<endl<<"entered guessthenumber"<<endl;
    mtx_guessthenumber.lock();
    srand(time(NULL)); // seed the random number generator with current time
    int secretNumber = rand() % 100 + 1; // generate a random number between 1 and 100
    int guess;
    int tries = 0;
    cout << "Welcome to Guess the Number!" << endl;
    cout << "I'm thinking of a number between 1 and 100. Can you guess what it is?" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        tries++;

        if (guess < secretNumber) {
            cout << "Too low. Guess again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high. Guess again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << tries << " tries." << endl;
        }
    } while (guess != secretNumber);
    mtx_guessthenumber.unlock();
 return nullptr;
}

void create_process() {
    mtx_create_process.lock();
    // implementation of create_process function
    mtx_create_process.unlock();
}

void process_message() {
    mtx_process_message.lock();
    // implementation of process_message function
    mtx_process_message.unlock();
}

void grantee() {
    mtx_grantee.lock();
    // implementation of grantee function
    mtx_grantee.unlock();
}

void interrupt() {
    mtx_interrupt.lock();
    // implementation of interrupt function
    mtx_interrupt.unlock();
}
void * tic_tac_toe(void*)
{
mtx_tic_tac_toe.lock();
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  char player = 'X';
  int row, col;

  cout << "Welcome to Tic Tac Toe!" << endl;

  for (int i = 0; i < 9; i++) {
    // Print the current board
    cout << "   1   2   3" << endl;
    cout << "1  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "  ---+---+---" << endl;
    cout << "2  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "  ---+---+---" << endl;
    cout << "3  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;

    // Get the player's move
    cout << "Player " << player << ", enter your move (row column): ";
    cin >> row >> col;

    // Check if the move is valid
    if (row < 1 || row > 3 || col < 1 || col > 3) {
      cout << "Invalid move. Please try again." << endl;
      i--;
      continue;
    }
    if (board[row-1][col-1] != ' ') {
      cout << "That space is already taken. Please try again." << endl;
      i--;
      continue;
    }

    // Update the board with the player's move
    board[row-1][col-1] = player;

    // Check if the game is over
    if (board[0][0] == player && board[0][1] == player && board[0][2] == player ||
        board[1][0] == player && board[1][1] == player && board[1][2] == player ||
        board[2][0] == player && board[2][1] == player && board[2][2] == player ||
        board[0][0] == player && board[1][0] == player && board[2][0] == player ||
        board[0][1] == player && board[1][1] == player && board[2][1] == player ||
        board[0][2] == player && board[1][2] == player && board[2][2] == player ||
        board[0][0] == player && board[1][1] == player && board[2][2] == player ||
        board[0][2] == player && board[1][1] == player && board[2][0] == player) {
      cout << "Player " << player << " wins!" << endl;
      break;
    }
    if (i == 8) {
      cout << "It's a tie!" << endl;
      break;
    }

    // Switch to the other player
    if (player == 'X') {
      player = 'O';
    } else {
      player = 'X';
    }
  }
mtx_tic_tac_toe.unlock();
return nullptr;
}
void * hangman(void*)
{
az=0;
mtx_hangman.lock();
  const int MAX_WRONG = 8;
  vector<string> words;  
  words.push_back("GUESS");
  words.push_back("HANGMAN");
  words.push_back("DIFFICULT");

  srand(static_cast<unsigned int>(time(0)));
  random_shuffle(words.begin(), words.end());
  const string THE_WORD = words[0];  
  int wrong = 0;  
  string soFar(THE_WORD.size(), '-');  
  string used = ""; 

  cout << "Welcome to Hangman. Good luck!\n";
  while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
    cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";
    cout << "\nYou've used the following letters:\n" << used << endl;
    cout << "\nSo far, the word is:\n" << soFar << endl;
    char guess;
    cout << "\n\nEnter your guess: ";
    cin >> guess;
    guess = toupper(guess);  
    while (used.find(guess) != string::npos) {
      cout << "\nYou've already guessed " << guess << endl;
      cout << "Enter your guess: ";
      cin >> guess;
      guess = toupper(guess);
    }
    used += guess;
    if (THE_WORD.find(guess) != string::npos) {
      cout << "That's right! " << guess << " is in the word.\n";
      for (int i = 0; i < THE_WORD.length(); ++i) {
        if (THE_WORD[i] == guess) {
          soFar[i] = guess;
        }
      }
    } else {
      cout << "Sorry, " << guess << " isn't in the word.\n";
      ++wrong;
    }
  }
  if (wrong == MAX_WRONG) {
    cout << "\nYou've been hanged!";
  } else {
    cout << "\nYou guessed it!";
  }
  cout << "\nThe word was " << THE_WORD << endl;
mtx_hangman.unlock();
return nullptr;
}
void* kernel_mode(void*)
{
cout<<endl<<"DONOT MODIFY KERNEL ELSE YOUR SYSTEM CAN BLAST!!!!"<<endl;
 pthread_exit(nullptr);
    int fd = open("/dev/sda", O_RDONLY); // open a device file
    if (fd < 0) {
        cout << "Failed to open device file" << endl;
        pthread_exit(nullptr);
    }

    int ret = ioctl(fd, BLKGETSIZE64, 0); // issue an ioctl call to the device file
    if (ret < 0) {
        cout << "ioctl call failed" << endl;
    } else {
        cout << "Device size: " << ret << endl;
    }

    close(fd); // close the device file
    pthread_exit(nullptr);
}

void* memory_match(void*)
{
az=0;
mtx_mem_match.lock();
cout<<"enter 1 to stop the process:";
cin>>az;
if(az==1){if (az == 1) {
        mtx_mem_match.unlock();
        pthread_exit(nullptr);
    }
}
const int size = 4;
    char board[size][size] = { {'A', 'B', 'C', 'D'},
                               {'E', 'F', 'G', 'H'},
                               {'A', 'B', 'C', 'D'},
                               {'E', 'F', 'G', 'H'} };
    bool revealed[size][size] = { false };
    int row1, col1, row2, col2;
    int pairsFound = 0;
    srand(time(NULL));
    while (pairsFound < size * size / 2) {
      
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (revealed[i][j]) {
                    cout << board[i][j] << " ";
                } else {
                    cout << "* ";
                }
            }
            cout << endl;
        }
    
        cout << "Enter row and column of first card: ";
        cin >> row1 >> col1;
        while (revealed[row1][col1]) {
            cout << "Card already revealed. Enter row and column of first card: ";
            cin >> row1 >> col1;
        }
        revealed[row1][col1] = true;
        cout << "First card: " << board[row1][col1] << endl;
       
        cout << "Enter row and column of second card: ";
        cin >> row2 >> col2;
        while (revealed[row2][col2]) {
            cout << "Card already revealed. Enter row and column of second card: ";
            cin >> row2 >> col2;
        }
        revealed[row2][col2] = true;
        cout << "Second card: " << board[row2][col2] << endl;
     
        if (board[row1][col1] == board[row2][col2]) {
            cout << "Match!" << endl;
            pairsFound++;
        } else {
            cout << "No match." << endl;
            revealed[row1][col1] = false;
            revealed[row2][col2] = false;
        }
    }
    cout << "Congratulations! You found all the pairs." << endl;
mtx_mem_match.unlock();
return nullptr;
}
void * alloc_mem(void*)
{
//to do this on kernel level see kernel mode function
mtx_a1.lock();
int ram1=8;
cout<<"how much ram you want to allocate?:";
cin>>ram1;
if(ram1>2)
{
cout<<ram1<<" cannot be allocated as it is too high for the system.";
}
else
{cout<<"ram allocated";}
mtx_a1.unlock();
return nullptr;
}
int main()
{
    cout << "Menu:\n";
    cout << "1. Display time and calendar\n";
    cout << "2. Open notepad\n";
    cout << "3. Open calculator\n";
    cout << "4. Create a file\n";
    cout << "5. Play rock-paper-scissors\n";
    cout << "6. Copy a file\n";
    cout << "7. Delete a file\n";
    cout << "8. Check file info\n";
    cout << "9. Play guess the number game\n";
    cout << "10. Enter kernel mode\n";
    cout << "11. Play tic-tac-toe game\n";
    cout << "12. Play hangman game\n";
    cout << "13. Play memory match game\n";
    cout << "14. Allocate memory\n";
    cout << "15. Exit\n";
 thread t1(boot_screen);
 t1.join();

pthread_t t2;
pthread_create(&t2,nullptr,&start_time_and_calendar,nullptr);
  pthread_join(t2,nullptr);
pthread_t t3;
pthread_create(&t3,nullptr,&notepad,nullptr);
  pthread_join(t3,nullptr);
pthread_t t4;
pthread_create(&t4,nullptr,&calculator,nullptr);
  pthread_join(t4,nullptr);
pthread_t t5;
pthread_create(&t5,nullptr,&create_file,nullptr);
  pthread_join(t5,nullptr);
pthread_t t6;
pthread_create(&t6,nullptr,&rock_paper_scissor,nullptr);
  pthread_join(t6,nullptr);
pthread_t t7;
pthread_create(&t7,nullptr,&copy_file,nullptr);
  pthread_join(t7,nullptr);
pthread_t t8;
pthread_create(&t8,nullptr,&delete_file,nullptr);
  pthread_join(t8,nullptr);
pthread_t t9;
pthread_create(&t9,nullptr,&check_file_info,nullptr);
  pthread_join(t9,nullptr);
pthread_t t10;
pthread_create(&t10,nullptr,&guessthenumber,nullptr);
pthread_join(t10,nullptr);
pthread_t t11;
pthread_create(&t11, nullptr, &kernel_mode, nullptr);
pthread_join(t11, nullptr);
pthread_t t12;
pthread_create(&t12,nullptr,&tic_tac_toe,nullptr);
pthread_join(t12,nullptr);
pthread_t t13;
pthread_create(&t13,nullptr,&hangman,nullptr);
pthread_join(t13,nullptr);
pthread_t t14;
pthread_create(&t14,nullptr,&memory_match,nullptr);
pthread_join(t14,nullptr);
pthread_t t15;
pthread_create(&t15,nullptr,&alloc_mem,nullptr);
pthread_join(t15,nullptr);
return 0;
}
