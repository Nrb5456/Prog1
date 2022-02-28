/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

   	int x_size = 800;
	int y_size = 801;
	int x_grid = 100;
	int y_grid = 100;

	Lines grid;
	for (int x=x_grid; x<x_size; x+=x_grid)
		grid.add(Point{x,0},Point{x,y_size});
	for (int y = y_grid; y<y_size; y+=y_grid)
		grid.add(Point{0,y},Point{x_size,y});

	Vector_ref<Rectangle> rect;

    for (int i = 0; i < x_size; i += x_grid) {
        rect.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        rect[rect.size() - 1].set_fill_color(Color::red);
        win.attach(rect[rect.size() - 1]);
    }

    Image img1 {Point{0, 300}, "kuty.jpeg"};
    Image img2 {Point{200, 0}, "kuty.jpeg"};
    Image img3 {Point{600, 200}, "kuty.jpeg"};
    Image img_m {Point{0, 0}, "kuty_2.gif"};

    img1.set_mask(Point{0, 0}, 200, 200);
    img2.set_mask(Point{0, 0}, 200, 200);
    img3.set_mask(Point{0, 0}, 200, 200);
    img_m.set_mask(Point{0, 0}, 100, 100);

    win.attach(grid);
	win.attach(img1);
	win.attach(img2);
	win.attach(img3);
    win.attach(img_m);
    win.wait_for_button();

    for(int i = 0; i < 701; i += 100){   
        for(int j = 0; j < 700; j += 100){
            img_m.move(100, 0);
            win.wait_for_button();
        }
        if(i < 700){
        	img_m.move(-700, 100);
        	win.wait_for_button();
    	}
    }
}