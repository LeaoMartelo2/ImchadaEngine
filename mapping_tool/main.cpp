#include <cstring>
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>

#define CANVAS_HEIGHT 30
#define CANVAS_WIDTH 80
#define MAX_FILENAME_LEN 256

void draw_canvas(WINDOW *win, char canvas[CANVAS_HEIGHT][CANVAS_WIDTH]) {
  for (int y = 0; y < CANVAS_HEIGHT; ++y) {
    for (int x = 0; x < CANVAS_WIDTH; ++x) {
      mvwaddch(win, y + 1, x + 1, canvas[y][x]);
    }
  }
  wrefresh(win);
}

void prompt_filename(WINDOW *win, char *filename) {
  echo();
  mvwprintw(win, 1, 1, "Enter file name: ");
  wrefresh(win);
  wgetnstr(win, filename, MAX_FILENAME_LEN - 1);
  noecho();
}

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(1);

  // terminal size
  int term_height, term_width;
  getmaxyx(stdscr, term_height, term_width);

  // filename input win
  int input_height = 5;
  int input_width = 40;
  int input_start_y = (term_height - input_height) / 2;
  int input_start_x = (term_width - input_width) / 2;
  WINDOW *input_win =
      newwin(input_height, input_width, input_start_y, input_start_x);
  box(input_win, 0, 0);
  wrefresh(input_win);

  // filename
  char filename[MAX_FILENAME_LEN] = {0};
  prompt_filename(input_win, filename);

  delwin(input_win);

  // main canvas

  int start_y = (term_height - CANVAS_HEIGHT) / 2;
  int start_x = (term_width - CANVAS_WIDTH) / 2;
  WINDOW *canvas_win =
      newwin(CANVAS_HEIGHT + 2, CANVAS_WIDTH + 2, start_y, start_x);
  box(canvas_win, 0, 0);
  wrefresh(canvas_win);

  char canvas[CANVAS_HEIGHT][CANVAS_WIDTH];
  memset(canvas, ' ', sizeof(canvas)); // fill the arraw with spaces

  int ch;
  int cursor_x = 1, cursor_y = 1; // Start inside the box
  while ((ch = getch()) != 27) {  // ESC to quit
    switch (ch) {
    case KEY_UP:
      if (cursor_y > 1)
        cursor_y--;
      break;
    case KEY_DOWN:
      if (cursor_y < CANVAS_HEIGHT)
        cursor_y++;
      break;
    case KEY_LEFT:
      if (cursor_x > 1)
        cursor_x--;
      break;
    case KEY_RIGHT:
      if (cursor_x < CANVAS_WIDTH)
        cursor_x++;
      break;
    case KEY_BACKSPACE:
    case 127:
      canvas[cursor_y - 1][cursor_x - 1] = ' ';
      break;

    default:
      if (ch >= 32 && ch <= 126) { // visible ascii table
        canvas[cursor_y - 1][cursor_x - 1] = ch;
      }
      break;
    }
    werase(canvas_win);
    box(canvas_win, 0, 0);
    draw_canvas(canvas_win, canvas);
    wmove(canvas_win, cursor_y, cursor_x);
    wrefresh(canvas_win);
    usleep(10000);
  }

  // Cleanup
  delwin(canvas_win);
  endwin();

  // Save the canvas contents to the specified file
  std::ofstream outfile(filename);
  if (outfile.is_open()) {
    for (int y = 0; y < CANVAS_HEIGHT; ++y) {
      for (int x = 0; x < CANVAS_WIDTH; ++x) {
        outfile << canvas[y][x];
      }
      outfile << '\n';
    }
    outfile.close();
    std::cout << "Canvas saved to " << filename << std::endl;
  } else {
    std::cerr << "Error: Could not open file for writing." << std::endl;
  }

  return 0;
}
