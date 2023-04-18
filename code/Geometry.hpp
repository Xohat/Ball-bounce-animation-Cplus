// Copyright (c) Arturo Vilar Carretero
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.4

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

struct Wall
{
	Vector2f position = { 0.f, 0.f };
	Vector2f speed = { 0.f, 0.f };
	float bounciness = 1.5f;
	float width;
	float height;

	Wall(float given_width, float given_height, const Vector2f& initial_positon)
	{
		width = given_width;
		height = given_height;
		position = initial_positon;
	}

	void draw(RenderWindow& renderer)
	{
		RectangleShape rectangle({ width, height });

		rectangle.setFillColor(Color::Green);
		rectangle.setSize({ width, height });
		rectangle.setPosition(position);

		renderer.draw(rectangle);
	}
};

struct Circle
{
	Vector2f gravity = { 0, 150.f };
	Vector2f position = { 0.f, 0.f };
	Vector2f speed = { 80.f, 200.f };
	float    restitution = 0.6f;
	float    radius;
	float	 mass = 0.f;

	Circle(float given_radius, const Vector2f& initial_position, float item_mass)
	{
		position = initial_position;
		radius = given_radius;
		mass = item_mass;
	}

	void update(float t)
	{
		speed += gravity * t;
		position += speed * t;
	}

	void draw(RenderWindow& renderer)
	{
		CircleShape circle(radius);

		circle.setFillColor(Color::White);
		circle.setPosition(position - Vector2f(radius, radius));

		renderer.draw(circle);
	}
};