#include <stdio.h>
#include <termios.h>
#include <unistd.h>

struct CHARACTER_BODY {
  int x;
  int y;
  char icon;
};

int BOX_HEIGHT = 15;
int BOX_WIDTH = 100;

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

void print_line(int line_length) {

  for (int k = 0; k < line_length; k++) {
    printf("*");
  }
  printf("\n");
}

void boundary_setter(struct CHARACTER_BODY character) {

  int row_start = 0;
  int row_end = BOX_HEIGHT - 1;

  // Row Render
  for (int x = 0; x < BOX_HEIGHT; x++) {

    if (x == row_start || x == row_end) {
      print_line(BOX_WIDTH);
    } else {

      for (int y = 0; y < BOX_WIDTH; y++) {

        if (y == 0) {
          printf("*");
        } else if (y == BOX_WIDTH - 1) {
          printf("*\n");
        } else {

          if (x == character.x && y == character.y) {

            printf("%c", character.icon);
          } else {
            printf(" ");
          }
        }
      }
    }
  }
}

int main() {

  struct CHARACTER_BODY character;

  character.x = 5;
  character.y = 10;
  character.icon = '*';

  char c;

  while (1) {

    printf("\033[H\033[J");

    boundary_setter(character);

    // Wait 1 second before rerunning

    c = getch(); // gets key immediately without Enter

    switch (c) {

    case 'w':
      character.x = character.x - 1;
      break;
    case 's':
      character.x = character.x + 1;
      break;
    case 'a':
      character.y = character.y - 1;
      break;
    case 'd':
      character.y = character.y + 1;
      break;
    }

    if (c == 'q') {
      break; // quit on 'q'
    }
  }

  return 0;
}