// Copyright (c) Arturo Vilar Carretero
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.4

#pragma once

#include "Geometry.hpp"

class Collision_manager 
{

public:

	void check_circle_sides(Circle& circle, Wall& square_floor, Wall& square_right, Wall& square_left);

	void check_circle_circle(Circle& circle1, Circle& circle2);
};