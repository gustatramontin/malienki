#include <ncurses.h>
#include <math.h>

int h,w;

void draw_line(int r1,int c1,int r2, int c2, char ch) {
    mvaddch(r1,c1,ch);

    int r,c;
    float px, py;
    r = r1;
    c = c1;
    px = c1;
    py = r1;

    float slope = atan2((float) r2 - (float) r1,(float) c2 - (float) c1);
    float x_move = cos(slope);
    float y_move = sin(slope);

    while (r <= r2 && c <= c2) {

        px += x_move;
        py += y_move;

        r = round(py);
        c = round(px);
        
        mvaddch(r,c, ch);
    }

}

void draw_board() {

    draw_line(0,w/3,h,w/3, '*');
    draw_line(0,2*w/3,h,2*w/3, '*');

    draw_line(h/3,0,h/3,w, '*');
    draw_line(2*h/3,0,2*h/3,w, '*');
}

int main() {
    initscr();
    noecho();
    cbreak(); 

    getmaxyx(stdscr,h,w);

    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; 
    int current = 'x';


    while (true) {

    draw_board();

    refresh();

    int ch = getch();

    switch ((char) ch) {
        case 'q':
            break;
    }
    }

    endwin();
}
