#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-240,0}, 120, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-120,0}, 120, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{x_max()-540,0}, 100, 40, "Next x:"}, 
    next_y{Point{x_max()-370,0}, 100, 40, "Next y:"},
    xy_out{Point{115,0}, 150, 40, "Current (x,y):"},
    color_menu{Point{x_max()-120,40},120,60,Menu::vertical,"color"},
    color_menu_button{Point{x_max()-120, 40}, 120, 40, "Color menu", cb_color_menu},
    style_menu{Point{x_max()-240, 40}, 120, 60, Menu::vertical,"style"},
    style_menu_button{Point{x_max()-240, 40}, 120, 40, "Style menu",cb_style_menu}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");

    color_menu.attach(new Button{Point{0,0},0,0,"Red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"Blue",cb_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"Black",cb_black});
    attach(color_menu);
    color_menu.hide();
    attach(color_menu_button);

    style_menu.attach(new Button{Point{0,0},0,0,"Solid",cb_solid});
    style_menu.attach(new Button{Point{0,0},0,0,"Dashed",cb_dash});
    style_menu.attach(new Button{Point{0,0},0,0,"Dotted",cb_dot});
    attach(style_menu);
    style_menu.hide();
    attach(style_menu_button);

    attach(lines);
}

void Lines_window::cb_red(Address, Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::cb_blue(Address, Address pw)
{
    reference_to<Lines_window>(pw).blue_pressed();
}

void Lines_window::cb_black(Address, Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
}

void Lines_window::cb_color_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).color_menu_pressed();
}

void Lines_window::cb_solid(Address, Address pw)
{
    reference_to<Lines_window>(pw).solid_pressed();
}

void Lines_window::cb_dash(Address, Address pw)
{
    reference_to<Lines_window>(pw).dash_pressed();
}

void Lines_window::cb_dot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dot_pressed();
}

void Lines_window::cb_style_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).style_menu_pressed();
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str()); //str() string format

    redraw();
}