// Copyright (c) Arturo Vilar Carretero
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.4

#include "Collision_manager.hpp"

void Collision_manager::check_circle_sides(Circle& circle, Wall& square_floor, Wall& square_right, Wall& square_left)
{
	if (circle.position.y + circle.radius > square_floor.position.y)
	{
		circle.speed.y = -circle.speed.y * circle.restitution * square_floor.bounciness;
		circle.position.y = square_floor.position.y - circle.radius;
		circle.radius = circle.radius * 0.85;
	}

	if (circle.position.x + circle.radius > square_right.position.x)
	{
		circle.speed.x = -circle.speed.x * circle.restitution;
		circle.position.x = square_right.position.x - circle.radius;
		circle.radius = circle.radius * 0.85;
	}

	if (circle.position.x - circle.radius < square_left.position.x)
	{
		circle.speed.x = -circle.speed.x * circle.restitution;
		circle.position.x = square_left.position.x + circle.radius;
		circle.radius = circle.radius * 0.85;
	}
}

void Collision_manager::check_circle_circle(Circle& circle1, Circle& circle2)
{
	if (circle2.position.x + circle2.radius < circle1.position.x + circle1.radius)
	{
		circle1.speed.x = -circle1.speed.x * circle1.restitution;
		circle2.speed.x = -circle2.speed.x * circle2.restitution;

		circle1.position.x = (circle2.position.x + circle2.radius) + circle1.radius;
		circle2.position.x = (circle1.position.x + circle1.radius) + circle2.radius;

		circle1.radius = circle1.radius * 1.2f;
		circle2.radius = circle2.radius * 1.2f;
	}
}