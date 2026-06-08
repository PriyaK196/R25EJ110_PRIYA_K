#include <stdio.h>
#include<stdlib.h>
#include <math.h>

#define ROWS 30
#define COLS 60

char canvas[ROWS][COLS];

// Initialize canvas
void initCanvas() {
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<COLS;j++)
            canvas[i][j]='_';
}

// Display canvas
void displayCanvas() {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++)
            printf("%c",canvas[i][j]);
        printf("\n");
    }
}

// Draw point
void drawPoint(int x,int y,char ch) {
    if(x>=0 && x<ROWS && y>=0 && y<COLS)
        canvas[x][y]=ch;
}

// Draw line
void drawLine(int x1,int y1,int x2,int y2) {
    int dx=x2-x1;
    int dy=y2-y1;
    int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);

    float xInc=dx/(float)steps;
    float yInc=dy/(float)steps;

    float x=x1,y=y1;

    for(int i=0;i<=steps;i++) {
        drawPoint(round(x),round(y),'*');
        x+=xInc;
        y+=yInc;
    }
}

// Draw rectangle
void drawRectangle(int x,int y,int w,int h) {
    for(int i=y;i<y+w;i++) {
        drawPoint(x,i,'*');
        drawPoint(x+h-1,i,'*');
    }

    for(int i=x;i<x+h;i++) {
        drawPoint(i,y,'*');
        drawPoint(i,y+w-1,'*');
    }
}

// Draw triangle
void drawTriangle(int x1,int y1,int x2,int y2,int x3,int y3) {
    drawLine(x1,y1,x2,y2);
    drawLine(x2,y2,x3,y3);
    drawLine(x3,y3,x1,y1);
}

// Draw circle
void drawCircle(int xc,int yc,int r) {
    for(int angle=0;angle<360;angle++) {
        double rad=angle*3.14159/180;
        int x=xc+r*cos(rad);
        int y=yc+r*sin(rad);
        drawPoint(x,y,'*');
    }
}

// Delete object area
void deleteArea(int x1,int y1,int x2,int y2) {
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)
            drawPoint(i,j,'_');
}

int main() {
    int choice;

    initCanvas();

    while(1) {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Area\n");
        printf("6. Display Picture\n");
        printf("7. Clear Canvas\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        if(choice==1) {
            int x1,y1,x2,y2;
            printf("Enter x1 y1 x2 y2: ");
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            drawLine(x1,y1,x2,y2);
        }

        else if(choice==2) {
            int x,y,w,h;
            printf("Enter x y width height: ");
            scanf("%d%d%d%d",&x,&y,&w,&h);
            drawRectangle(x,y,w,h);
        }

        else if(choice==3) {
            int x1,y1,x2,y2,x3,y3;
            printf("Enter x1 y1 x2 y2 x3 y3: ");
            scanf("%d%d%d%d%d%d",
                  &x1,&y1,&x2,&y2,&x3,&y3);
            drawTriangle(x1,y1,x2,y2,x3,y3);
        }

        else if(choice==4) {
            int xc,yc,r;
            printf("Enter centerX centerY radius: ");
            scanf("%d%d%d",&xc,&yc,&r);
            drawCircle(xc,yc,r);
        }

        else if(choice==5) {
            int x1,y1,x2,y2;
            printf("Enter delete area x1 y1 x2 y2: ");
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            deleteArea(x1,y1,x2,y2);
        }

        else if(choice==6) {
            displayCanvas();
        }

        else if(choice==7) {
            initCanvas();
        }

        else if(choice==8) {
            break;
        }
    }

    return 0;
}
