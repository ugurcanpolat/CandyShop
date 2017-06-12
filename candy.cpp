/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 14.05.2017
 */

#include "candy.h"

Candy::Candy() { // Default constructor
	stock = 0;
	price = 0;
}

Candy::Candy(string label, float amount, float ppkg) {
	name = label;
	stock = amount;
	price = ppkg;
}

Candy::Candy(const Candy& copy) { // Copy constructor
	name = copy.name;
	stock = copy.stock;
	price = copy.price;
}

string Candy::getName() const {
	return name;
}

float Candy::getStock() const {
	return stock;
}

float Candy::getPrice() const {
	return price;
}

float Candy::getCost() const {
	return stock * price;
}

DESSERT Candy::getType() const { // Get dessert type
	return CANDY;
}
