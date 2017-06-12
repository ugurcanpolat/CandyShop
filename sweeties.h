/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 14.05.2017
 */

#ifndef sweeties_h
#define sweeties_h

#include <string> 

using namespace std;

#ifndef dessert_enum
#define dessert_enum
typedef enum Dessert {NONE=0, COOKIE, CANDY, ICECREAM} DESSERT;
#endif

class Sweeties {
  private:
    string name;
    float stock;
    float price;
    DESSERT type;
  public:
    Sweeties();
    Sweeties(string, float, float, int);
    Sweeties(const Sweeties&);
    ~Sweeties() {};
    string getName() const;
    float getStock() const;
    float getPrice() const;
    float getCost() const;
    DESSERT getType() const;
    friend ostream& operator<<(ostream&, const Sweeties&);
};

#endif
