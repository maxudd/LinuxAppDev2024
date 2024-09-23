#include <stdlib.h>
#include <ncurses.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);

int main (int argc, char *argv[]){
    FILE *file = fopen(argv[1], "r");

    
    WINDOW *my_win;
    int startx, starty, width, height;

    initscr();
    curs_set(0);
    cbreak();
    keypad(stdscr, TRUE);

    starty = 1;
    startx = 4;
    height = LINES - 2*starty;
    width = COLS - 2*startx;

    char fchar;
    int rows = 0;

    while ((fchar = fgetc(file)) != EOF)
        if (fchar == '\n') rows++;
    
    rewind(file);
    char **strings = (char **)malloc(rows * sizeof(char *));

    int col_counter = 0, ii = 0;
    int working_width = width - 2;
    while ((fchar = fgetc(file)) != EOF){
        if (fchar == '\n'){
            col_counter++;
            strings[ii] = (char *)malloc((col_counter > working_width ? working_width : col_counter) * sizeof(char));
            ii++;
            col_counter = 0;
        }
        else{
            col_counter++;
        }
    }
    rewind(file);

    int row = 0, col = 0;
    char fchar1;
    while ((fchar1 = fgetc(file)) != EOF) {
        if (fchar1 == '\n') {
            if (col <= working_width-1) strings[row][col] = '\0';
            row++;
            col = 0;
        } 
        else if (col > working_width-1) 
            continue;
        else {
            strings[row][col] = fchar1;
            col++;
        }
    }

    fclose(file);


    printw("File: %s, %d lines", argv[1], rows);
    refresh();
    my_win = create_newwin(LINES - 2*starty, COLS - 2*startx, starty, startx);
    int start_string = 0;
    wrefresh(my_win);

    int c_final;
    for (;;){
        c_final = rows < height -2 ? rows-1-start_string : height - 2;

        for (int c=0; c < c_final; c++){
            mvwprintw(my_win, c+1, 1, "%s", strings[c+start_string]);
        }
        wrefresh(my_win);

        int ch = getch();
        if ((ch == KEY_BACKSPACE) & (start_string >= 1))  {
            start_string--;
            rows++;
        }
        if ((ch == 32) & (rows > height-1)){
            start_string++;
            rows--;
        }
        if (ch == 27)  break;

        werase(my_win);
        box(my_win, 0 , 0);
        wrefresh(my_win);
    }

    endwin();
    for (int i = 0; i < rows; i++) {
        free(strings[i]);
    }
    free(strings);
    return 0;

}


WINDOW *create_newwin(int height, int width, int starty, int startx){
    WINDOW *local_win;
    local_win = newwin(height, width, starty, startx);
    box(local_win, 0 , 0);
    wmove(local_win, 1, 1);
    wrefresh(local_win);
    return local_win;
}
