/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 14.05.2017
 */

#ifndef candy_h
#define candy_h

#include <string> 

using namespace std;

#ifndef dessert_enum
#define dessert_enum
typedef enum Dessert {NONE=0, COOKIE, CANDY, ICECREAM} DESSERT;
#endif

class Candy {
  private:
    string name;
    float stock;
    float price;	
  public:
    Candy();
    Candy(string, float, float);
    Candy(const Candy&);
    ~Candy() {};
    string getName() const;
    float getStock() const;
    float getCost() const;
    float getPrice() const;
    DESSERT getType() const;
    friend ostream& operator<<(ostream&, const Candy&);
};

#endif
