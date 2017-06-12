/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 14.05.2017
 */

#ifndef shop_h
#define shop_h

#include <string>

#define TAX 8

#ifndef dessert_enum
#define dessert_enum
typedef enum Dessert {NONE=0, COOKIE, CANDY, ICECREAM} DESSERT;
#endif

using namespace std;

template <class type> class Shop {
  private:
    type* product;
    DESSERT productType;
    int numberOfProducts;
    float discount;
  public:
    Shop();
    Shop(const type&);
    ~Shop();
    const type& operator[](int i) const;
    template <class type2> friend ostream& operator<<(ostream&, const Shop<type2>&);
    void add(const type&);
    void setDiscount(float);
    int getStock(string) const;
    float getPrice(string) const;
    float getCost() const;
    float getDiscountedCost() const;
};

#endif
