#include "UserTable.h"
#include "Rectang.h"
#include "ShapeList.h"
#include "Pixel.h"
#include "Text.h"
#include "Pixel.h"

using namespace std;

class Point
{
public:
	int x;
	int y;
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

class Point3D
{
public:
	int x;
	int y;
	int z;
	Point3D(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

int main()
{
	initwindow(1700, 810);
	Painter::fill_background(WHITE);
	UserTable user_table;

	//========================= The sun =========================
	Shape theSun;
	int x = 50, y = 10;
	Moving *sun = new Moving(x, 30 - y);
	theSun.add_circle(0 + x, 30 - y, 7);
	theSun.add_line(0 + x, 40 - y, 0 + x, 45 - y);
	theSun.add_line(-8 + x, 37 - y, -13 + x, 40 - y);
	theSun.add_line(-10 + x, 30 - y, -15 + x, 30 - y);
	theSun.add_line(-8 + x, 23 - y, -13 + x, 20 - y);
	theSun.add_line(0 + x, 20 - y, 0 + x, 15 - y);
	theSun.add_line(8 + x, 37 - y, 12 + x, 39 - y);
	theSun.add_line(8 + x, 23 - y, 12 + x, 20 - y);
	theSun.add_line(10 + x, 30 - y, 15 + x, 30 - y);

	//========================= Air balloon =========================
	Shape hotAirBalloonShape;
	Moving *airBal = new Moving(-55, 51);
	hotAirBalloonShape.add_circle(-55, 51, 9);
	hotAirBalloonShape.add_line(-62, 45, -60, 40);
	hotAirBalloonShape.add_line(-48, 45, -50, 40);
	hotAirBalloonShape.add_line(-60, 39, -50, 39);
	hotAirBalloonShape.add_line(-60, 34, -50, 34);
	hotAirBalloonShape.add_line(-60, 34, -60, 39);
	hotAirBalloonShape.add_line(-50, 34, -50, 39);

	//========================= Mountain =========================
	Shape mountain_shape;
	mountain_shape.add_triangle(-105, 0, -80, 50, -55, 0);
	mountain_shape.add_triangle(-55, 0, -30, 35, 0, 0);
	// Fill first mountain
	mountain_shape.add_line(-95, 0, -75, 40);
	mountain_shape.add_line(-85, 0, -70, 31);
	mountain_shape.add_line(-75, 0, -65, 22);
	mountain_shape.add_line(-65, 0, -60, 11);
	// Fill second mountain
	mountain_shape.add_line(-45, 0, -24, 28);
	mountain_shape.add_line(-35, 0, -20, 20);
	mountain_shape.add_line(-25, 0, -14, 14);
	mountain_shape.add_line(-15, 0, -8, 8);

	//========================= Water wheel =========================
	Shape waterWheel;
	waterWheel.add_circle(-60, -15, 1);
	waterWheel.add_circle(-60, -15, 7);
	waterWheel.add_line(-60, -14, -60, -9);
	waterWheel.add_line(-61, -14, -66, -11);
	waterWheel.add_line(-61, -16, -66, -18);
	waterWheel.add_line(-60, -16, -60, -21);
	waterWheel.add_line(-59, -16, -54, -18);
	waterWheel.add_line(-59, -14, -54, -12);
	waterWheel.add_circle(-60, -15, 8);
	waterWheel.add_line(-57, -23, -54, -30);
	waterWheel.add_line(-56, -23, -53, -30);
	waterWheel.add_line(-64, -23, -67, -30);
	waterWheel.add_line(-63, -23, -66, -30);
	waterWheel.add_line(-63, -26, -56, -26);
	waterWheel.add_line(-64, -27, -55, -27);

	//========================= Grass =========================
	Shape grass;
	// line
	grass.add_line(-20, -1, -60, -62);
	grass.add_line(-60, -62, -105, -62);
	grass.add_line(-105, -62, -105, -1);

	//========================= The house =========================
	// the bone
	Shape theHouse;
	theHouse.add_rectangle(50, -20, 70, -40);
	theHouse.add_triangle(50, -20, 59, -11, 70, -20);
	// the roof
	Shape houseFurnitures;
	houseFurnitures.add_rectangle(52, -22, 58, -28);
	houseFurnitures.add_line(55, -22, 55, -28);
	houseFurnitures.add_line(52, -25, 58, -25);
	houseFurnitures.add_rectangle(61, -30, 67, -40);
	houseFurnitures.add_pixel(63, -35);

	//========================= Trees =========================
	// Trunks
	Shape trunks;
	trunks.add_line(91, -47, 91, -20);
	trunks.add_line(91, -40, 82, -35);
	trunks.add_line(91, -37, 97, -32);
	// Leaves
	Shape leaves;
	leaves.add_circle(91, -20, 9);
	leaves.add_circle(97, -32, 4);
	leaves.add_circle(82, -35, 7);

	user_table.draw_shape(&waterWheel, MAGENTA);

	user_table.draw_shape(&grass, LIGHTGREEN);
	user_table.draw_shape(grass.get_symmetry_oy(), LIGHTGREEN);

	user_table.draw_shape(&theHouse, RED);
	user_table.draw_shape(&houseFurnitures, LIGHTBLUE);

	user_table.draw_shape(&leaves, GREEN);
	user_table.draw_shape(&trunks, BROWN);
	user_table.draw_shape(trunks.get_symmetry_oy(), BROWN);
	user_table.draw_shape(leaves.get_symmetry_oy(), GREEN);

	//===============================================================
	//========================= Remote ctrl =========================
	//===============================================================

	int font = 10;

	Text ctrlPal("CONTROL PANEL");
	ctrlPal.set_style(font, 3);
	ctrlPal.draw_at(new Rectang(90, 3, 120, 3));

	Text mainPro("MAIN PROGRAM");
	mainPro.set_style(font, 3);
	mainPro.draw_at(new Rectang(1650, 3, 1700, 3));

	Text xPos("X");
	xPos.set_style(font, 3);
	xPos.draw_at(new Rectang(215, 40, 300, 40));

	Text yPos("Y");
	yPos.set_style(font, 3);
	yPos.draw_at(new Rectang(400, 40, 410, 40));

	Text sunTitle("Sun");
	sunTitle.set_style(font, 1);
	sunTitle.draw_at(new Rectang(30, 73, 30, 83));

	Rectang xSun(100, 78, 165, 103);
	xSun.draw();

	Rectang ySun(175, 78, 240, 103);
	ySun.draw();

	Text airTitle("Air");
	airTitle.set_style(font, 1);
	airTitle.draw_at(new Rectang(30, 113, 30, 113));

	Text balTitle("balloon");
	balTitle.set_style(font, 1);
	balTitle.draw_at(new Rectang(30, 133, 30, 138));

	Rectang xAirBal(100, 128, 165, 153);
	xAirBal.draw();

	Rectang yAirBal(175, 128, 240, 153);
	yAirBal.draw();

	//========================= 3D rectangle =========================
	Text rec3D("3D RECTANGLE");
	rec3D.set_style(font, 3);
	rec3D.draw_at(new Rectang(70, 198, 90, 218));

	Text xRect("X");
	xRect.set_style(font, 2);
	xRect.draw_at(new Rectang(80, 228, 90, 228));

	Rectang xRec3D(10, 258, 80, 285);
	xRec3D.draw();

	Text yRect("Y");
	yRect.set_style(font, 2);
	yRect.draw_at(new Rectang(385, 228, 90, 228));

	Rectang yRec3D(90, 258, 160, 285);
	yRec3D.draw();

	Text zRect("Z");
	zRect.set_style(font, 2);
	zRect.draw_at(new Rectang(700, 228, 90, 228));

	Rectang zRec3D(170, 258, 240, 285);
	zRec3D.draw();

	Text lTitle("Len");
	lTitle.set_style(font, 2);
	lTitle.draw_at(new Rectang(5, 288, 100, 288));

	Rectang length3D(10, 318, 80, 345);
	length3D.draw();

	Text wTitle("Wid");
	wTitle.set_style(font, 2);
	wTitle.draw_at(new Rectang(190, 288, 245, 288));

	Rectang width3D(90, 318, 160, 345);
	width3D.draw();

	Text hTitle("Hei");
	hTitle.set_style(font, 2);
	hTitle.draw_at(new Rectang(350, 288, 400, 288));

	Rectang height3D(170, 318, 240, 345);
	height3D.draw();

	

	int countFrame = 0;
	int sunUpCount = -10;
	Pixel mouse_cur_pos;
	Pixel mouse_click_pixel;

	while (true)
	{
		//===============================================================
		//========================= 2D GRAPHICS =========================
		//===============================================================

		user_table.draw_shape(&mountain_shape, DARKGRAY);
		user_table.draw_shape(mountain_shape.get_symmetry_oy(), DARKGRAY);

		delay(30);

		// clear objects
		user_table.clear_shape(&theSun);
		user_table.clear_shape(&hotAirBalloonShape);

		//===============================================================
		// We code here : move and then draw an object

		// move and then drawing Object1
		if (countFrame % 5 == 0)
		{

			if (sunUpCount < 15)
			{
				theSun.move_up();
				sun->move_up();
			}
			else
			{
				theSun.move_down();
				sun->move_down();
			}

			sunUpCount++;
		}

		user_table.draw_shape(&theSun, LIGHTRED);

		// move and then drawing move and then drawing Object2
		if (countFrame < 26)
		{
			hotAirBalloonShape.move_right();
			airBal->move_right();
		}
		else
		{
			hotAirBalloonShape.move_left();
			airBal->move_left();
		}

		user_table.draw_shape(&hotAirBalloonShape, LIGHTMAGENTA);

		//===============================================================
		if (countFrame == 50)
		{
			countFrame = 0;
		}
		countFrame++;

		if (sunUpCount == 30)
		{
			sunUpCount = 0;
		}

		//===============================================================
		//========================= 3D GRAPHICS =========================
		//===============================================================

		mouse_cur_pos.cur_mouse_pos();
		mouse_click_pixel.mouse_click();

		if (mouse_click_pixel.is_in(&xRec3D) || mouse_click_pixel.is_in(&length3D))
		{
			user_table.clear_shape(theSun);
			user_table.clear_shape(hotAirBalloonShape);
			user_table.clear_shape(mountain_shape);
			user_table.clear_shape(waterWheel);
			user_table.clear_shape(grass);
			user_table.clear_shape(theHouse);
			user_table.clear_shape(houseFurnitures);
			user_table.clear_shape(trunks);
			user_table.clear_shape(leaves);
			user_table.clear_shape(mountain_shape.get_symmetry_oy());
			user_table.clear_shape(grass.get_symmetry_oy());
			user_table.clear_shape(trunks.get_symmetry_oy());
			user_table.clear_shape(leaves.get_symmetry_oy());

			int len, wid, hei, beginx, beginy, beginz;
			Text input;

			input.cin_at(xRec3D);
			beginx = input.get_num();

			input.cin_at(yRec3D);
			beginy = input.get_num();

			input.cin_at(zRec3D);
			beginz = input.get_num();

			input.cin_at(length3D);
			len = input.get_num();

			if (len % 2 == 1)
				len++;

			input.cin_at(width3D);
			wid = input.get_num();

			input.cin_at(height3D);
			hei = input.get_num();

		
			vector<Point3D *> point_3d;

			point_3d.push_back(new Point3D(beginx, beginy + wid, beginz));				   // A
			point_3d.push_back(new Point3D(beginx + len, beginy + wid, beginz));		   // B
			point_3d.push_back(new Point3D(beginx + len, beginy, beginz));				   // C
			point_3d.push_back(new Point3D(beginx, beginy, beginz));						   // D
			point_3d.push_back(new Point3D(beginx, beginy + wid, beginz + hei));		   // E
			point_3d.push_back(new Point3D(beginx + len, beginy + wid, beginz + hei)); // F
			point_3d.push_back(new Point3D(beginx + len, beginy, beginz + hei));		   // G
			point_3d.push_back(new Point3D(beginx, beginy, beginz + hei));				   // H

			vector<Point *> point_list;

			point_list.push_back(new Point(point_3d[0]->x - point_3d[0]->y / sqrt(2), point_3d[0]->z - point_3d[0]->y / sqrt(2))); // A
			point_list.push_back(new Point(point_3d[1]->x - point_3d[1]->y / sqrt(2), point_3d[1]->z - point_3d[1]->y / sqrt(2))); // B
			point_list.push_back(new Point(point_3d[2]->x - point_3d[2]->y / sqrt(2), point_3d[2]->z - point_3d[2]->y / sqrt(2))); // C
			point_list.push_back(new Point(point_3d[3]->x - point_3d[3]->y / sqrt(2), point_3d[3]->z - point_3d[3]->y / sqrt(2))); // D
			point_list.push_back(new Point(point_3d[4]->x - point_3d[4]->y / sqrt(2), point_3d[4]->z - point_3d[4]->y / sqrt(2))); // E
			point_list.push_back(new Point(point_3d[5]->x - point_3d[5]->y / sqrt(2), point_3d[5]->z - point_3d[5]->y / sqrt(2))); // F
			point_list.push_back(new Point(point_3d[6]->x - point_3d[6]->y / sqrt(2), point_3d[6]->z - point_3d[6]->y / sqrt(2))); // G
			point_list.push_back(new Point(point_3d[7]->x - point_3d[7]->y / sqrt(2), point_3d[7]->z - point_3d[7]->y / sqrt(2))); // H

			Shape *shape = new Shape;

			shape->add_line(point_list[0]->x, point_list[0]->y, point_list[1]->x, point_list[1]->y);		 	// AB
			shape->add_line_net_dut(point_list[2]->x, point_list[2]->y, point_list[3]->x, point_list[3]->y); 	// CD
			shape->add_line_net_dut(point_list[3]->x, point_list[3]->y, point_list[0]->x, point_list[0]->y); 	// DA
			shape->add_line(point_list[1]->x, point_list[1]->y, point_list[2]->x, point_list[2]->y);		 	// BC
			shape->add_line(point_list[4]->x, point_list[4]->y, point_list[5]->x, point_list[5]->y); 			// EF
			shape->add_line(point_list[5]->x, point_list[5]->y, point_list[6]->x, point_list[6]->y); 			// FG
			shape->add_line(point_list[6]->x, point_list[6]->y, point_list[7]->x, point_list[7]->y);		 	// GH
			shape->add_line(point_list[7]->x, point_list[7]->y, point_list[4]->x, point_list[4]->y);		 	// HE
			shape->add_line(point_list[0]->x, point_list[0]->y, point_list[4]->x, point_list[4]->y);		 	// AE
			shape->add_line(point_list[1]->x, point_list[1]->y, point_list[5]->x, point_list[5]->y); 			// BF
			shape->add_line(point_list[2]->x, point_list[2]->y, point_list[6]->x, point_list[6]->y);		 	// CG
			shape->add_line_net_dut(point_list[3]->x, point_list[3]->y, point_list[7]->x, point_list[7]->y);	// DH

			// Text A("A: "), B("B: "), C("C: "), D("D: "), E("E: "), F("F: "), G("G: "), H("H: ");

			// A.add("0,0,0");
			// B.add(d);
			// B.add(",0,0");
			// C.add(d);
			// C.add(",");
			// C.add(r);
			// C.add(",0");
			// D.add("0,");
			// D.add(r);
			// D.add(",0");
			// E.add("0,0,");
			// E.add(c);
			// F.add(d);
			// F.add(",0,");
			// F.add(c);
			// G.add(d);
			// G.add(",");
			// G.add(r);
			// G.add(",");
			// G.add(c);
			// H.add("0,");
			// H.add(r);
			// H.add(",");
			// H.add(c);

			// A.set_style(6, 1);
			// B.set_style(6, 1);
			// C.set_style(6, 1);
			// D.set_style(6, 1);
			// E.set_style(6, 1);
			// F.set_style(6, 1);
			// G.set_style(6, 1);
			// H.set_style(6, 1);

			// A.draw_at(new Rectang(600, 60, 650, 70));
			// B.draw_at(new Rectang(900, 60, 950, 70));
			// C.draw_at(new Rectang(1200, 60, 1250, 70));
			// D.draw_at(new Rectang(1500, 60, 1550, 70));
			// E.draw_at(new Rectang(1800, 60, 1850, 70));
			// F.draw_at(new Rectang(2100, 60, 2150, 70));
			// G.draw_at(new Rectang(2400, 60, 2450, 70));
			// H.draw_at(new Rectang(2700, 60, 2750, 70));

			user_table.draw_shape(shape, MAGENTA);

			getch();
			user_table.clear_shape(shape);
			Painter::set_color_will_fill(WHITE);
			bar(300, 60, 1500, 100);
		}

		//===== DATA X-Y =====
		Text::SETSTYLE(font, 1);
		Text::draw_num(xSun.x1 + 10, xSun.y1 + 4, sun->xCenter);
		Text::draw_num(ySun.x1 + 10, ySun.y1 + 4, sun->yCenter);
		Text::draw_num(xAirBal.x1 + 10, xAirBal.y1 + 4, airBal->xCenter);
		Text::draw_num(yAirBal.x1 + 10, yAirBal.y1 + 4, airBal->yCenter);
	}

	getchar();
	return 0;
}
