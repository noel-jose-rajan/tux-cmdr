#include <stdio.h>
#include <termios.h>
#include <unistd.h>

struct CHARACTER_BODY {
  int x;
  int y;
  char icon;
};

#define BOX_HEIGHT 15;
#define BOX_WIDTH 100;

char getch() {
  struct termios oldt, newt;
  char ch;

  tcgetattr(STDIN_FILENO, &oldt); // Save terminal settings
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);        // Disable canonical mode and echo
  tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings

  ch = getchar(); // Read single char

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore terminal settings
  return ch;
}


void render() {

}

int main() {

  return 0;
}
