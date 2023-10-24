#include <bits/stdc++.h>

using namespace std;

// Variables para circunferencia
const int radio=3;

// Coordenadas origen para el nuevo sistema de coordenadas
const int h = 10, k=10; 
void gotoxy(int x,int y)
{
    // Nuevo sistema de coordenadas
    int x_ = h + x;
    int y_ = k + y;
    printf("%c[%d;%dfo",0x1B,y_,x_);
}

typedef struct point {
    private:
        float x, y, z;
    public:
        point(float x, float y, float z){
            this->x = x;
            this->y = y;
            this->z = z;
        };
        
        float& getX(){return this->x;}
        float& getY(){return this->y;}
        float& getZ(){return this->z;}

} point;

void solve(){
    system("clear");
//    for(int x0=h-radio; x0<=(h+radio); x0++){
//        int f = 2*k, s=sqrt(4*pow(k,2)-4*(pow(k,2)-(radio+x0-h)*(radio-x0+h)));
//        int y0=(f + s)/2;
//        int y1=(f - s)/2;
//        gotoxy(x0, y0);
//        gotoxy(x0, y1);
//    }
    float beta=6, alfa=0;
    int X, Y;
    for(; alfa <=360; alfa+=beta){
        X = radio*(cos(beta)*cos(alfa)-sin(beta)*sin(alfa));
        Y = radio*(sin(beta)*cos(alfa)+sin(alfa)*cos(beta));
        gotoxy(h+X, k+Y);
        cout << X << ", " << Y << '\n';
    }

    getchar();
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
}