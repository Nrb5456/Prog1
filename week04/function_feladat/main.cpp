/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main.out `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double slope(double x) { return x/2; }

double square(double x) { return x*x; }

double sl_cos(double x) { return cos(x) + slope(x); }

int main()
{
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 600;

    int x_origo = xmax/2;
    int y_origo = ymax/2;

    int x_scale = 20;
    int y_scale = 20;

    Point origo {x_origo, y_origo};

    Simple_window win {Point{100,100}, xmax, ymax, "Function graphs"};

	Axis x{Axis :: x, Point{100, y_origo}, 400, 400/x_scale, "1 = = 20 pixels"};
	Axis y{Axis :: y, Point{x_origo, 500}, 400, 400/y_scale, "1 = = 20 pixels"};

	x.set_color(Color::red);
	y.set_color(Color::red);

    Function s (one, -10, 11, origo, 400, x_scale, y_scale);
    Function sl (slope, -10, 11, origo, 400, x_scale, y_scale);
    Function sq (square, -10, 11, origo, 400, x_scale, y_scale);
    Function sl_c (sl_cos, -10, 11, origo, 400, x_scale, y_scale);
    Function c (cos, -10, 11, origo, 400, x_scale, y_scale);

    Text t {Point{100, y_origo + y_origo / 2 - 70},"x/2"};

    c.set_color(Color::blue);

	win.attach(x);
	win.attach(y);
    win.attach(s);
    win.attach(sl);
    win.attach(t);
    win.attach(sq);
    win.attach(sl_c);
    win.attach(c);

    win.wait_for_button();

}
