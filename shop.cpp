/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 14.05.2017
 */

#include "shop.h"

template <class type> Shop<type>::Shop() { // Default constructor
	product = NULL;
	productType = NONE;
	numberOfProducts = 0;
	discount = 0;
}

template <class type> Shop<type>::Shop(const type& new_product) {
	product = new type;	
	*product = new_product;
	productType = new_product.getType();
	discount = 0;
	// Number of product is 1 after copying the product.
	numberOfProducts = 1;
}

template <class type> Shop<type>::~Shop() {
	// Release memory if there is.
	if (numberOfProducts == 1)
		delete product;
	else if (numberOfProducts > 1)
		delete [] product;
}

template <class type> const type& Shop<type>::operator[](int i) const{
	// If the item trying to be accessed does not exist, throw an error.
	if (i >= numberOfProducts) {
		if (productType == CANDY)
			throw "We don't have enough candies!";
		else if (productType == COOKIE)
			throw "We don't have enough cookies!";	
		else if (productType == ICECREAM)
			throw "We don't have enough icecream!";
	}	
	// Return product.
	return *(product+i);
}

template <class type> void Shop<type>::add(const type& new_product) {
	// If there is no product yet, create the new one. Then, return.
	if (numberOfProducts == 0) {
		product = new type;
		*product = new_product;
		numberOfProducts++;
		return;
	}
	
	// Create temporary memory to keep data before deleting |product|.
	type *temp = new type[numberOfProducts];
	
	// Copy all products.
	for(int i=0; i < numberOfProducts; i++) 
		temp[i] = *(product+i);
	
	// Release the memory of product to allocate new space.
	if (numberOfProducts == 1)
		delete product;
	else if (numberOfProducts > 1)
		delete [] product;
		
	// Allocate memory for new size.
	product = new type[numberOfProducts+1];
	
	// Get the info stored before re-allocating.
	for(int i=0; i < numberOfProducts; i++) 
		*(product+i) = temp[i];
		
	// Release the memory used by temp.
	delete [] temp;
	
	// If product type has not been set yet, set the type.
	if(productType == NONE)
		productType = new_product.getType();
	
	// Get new product.
	*(product+numberOfProducts) = new_product;
	// Increment number of products.
	numberOfProducts++;
}

template <class type> void Shop<type>::setDiscount(float percentage_off) {
	// Throw the error if discount is out of range.
	if (percentage_off < 0 || percentage_off > 30) 
		throw "Discount rate is out of range!";
	
	// Set the discount.
	discount = percentage_off;
}

template <class type> int Shop<type>::getStock(string name) const {
	// First find the product by name, then return its stock info.
	for (int i = 0; i < numberOfProducts; i++) {
		if(name.compare((*(product+i)).getName()) == 0) 
			return (*(product+i)).getStock();
	}
	// Return 0 if there is no match.
	return 0;
}

template <class type> float Shop<type>::getPrice(string name) const {
	// First find the product by name, then return its price info.
	for (int i = 0; i < numberOfProducts; i++) {
		if(name.compare((*(product+i)).getName()) == 0) 
			return (*(product+i)).getPrice();
	}
	// Return 0 if there is no match.
	return 0;
}

template <class type> float Shop<type>::getCost() const {
	// Get cost of all products.
	float cost = 0;
	for (int i = 0; i < numberOfProducts; i++) {
		cost += (*(product+i)).getCost();
	}
	// Include the tax (%8).
	cost += (cost * TAX) / 100;
	return cost;
}

template <class type> float Shop<type>::getDiscountedCost() const {
	// Get cost excluding discount.
	float cost = getCost();
	cost -= (cost * discount) / 100;
	return cost;
}
