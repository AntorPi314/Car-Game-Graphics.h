#include <graphics.h>
#include <iostream>
using namespace std;
int page=0;
int cx=370, cy=550;
void start();

void sayWin() {
    while(1) {
        setactivepage(page);
        setvisualpage(1-page);
        setbkcolor(BLACK);
        cleardevice();
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 6);
        outtextxy(260, 300, "You Win");
        settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
        outtextxy(260, 370, "Press Enter...");
        if (GetAsyncKeyState(VK_RETURN)) {
            cx=370, cy=550;
            break;
        }
        page=1-page;
        delay(10);
    }
}

void sayLose() {
    while(1) {
        setactivepage(page);
        setvisualpage(1-page);
        setbkcolor(BLACK);
        cleardevice();
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 6);
        outtextxy(260, 300, "You Lose!");
        settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
        outtextxy(260, 370, "Press Enter...");
        if (GetAsyncKeyState(VK_RETURN)) {
            cx=370, cy=550;
            break;
        }
        page=1-page;
        delay(10);
    }
}

void carRed() {
    int x=370, y=200;
    readimagefile("car_red.jpg", x, y, x+70, y+110);
}

void check(int x, int y) {
    if(x>370-70 && x<370+70 && y>200-110 && y<200+110) {
        sayLose();
    }
}
void backgroud() {
    cleardevice();
    setbkcolor(GREEN);
    cleardevice();
    rectangle(200, -1, 600, 700);
    setfillstyle(SOLID_FILL, CYAN);
    floodfill(209, 9, WHITE);
    carRed();
}

void car() {
    int x=cx, y=cy;
    readimagefile("car.jpg", x, y, x+70, y+110);
}

void start() {
    while (1) {
        setactivepage(page);
        setvisualpage(1-page);
        if (GetAsyncKeyState(VK_UP)) {
            cy-=20;
            if(cy<0) {
                sayWin();
            }
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            cy+=20;
        }
        if (GetAsyncKeyState(VK_LEFT)) {
            if(cx>222) {
                cx -= 14;
            }
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            if(cx<510) {
                cx += 14;
            }
        }
        check(cx, cy);
        cleardevice();
        backgroud();
        car();

        page=1-page;
        delay(10);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    initwindow(800,700,"Car Game");
    backgroud();
    car();
    start();
    getch();
    closegraph();
    return 0;
}
