/* Animal shelter
- enQeue any animal
- deQueueAny or deQueueCat or deQueueDog

- Use queue STL from c++
- Use 2 queues: 1 for dog and 1 for cat
- And also keep track of time ordering by using int order
- order++ for enqueue
 */

#include<iostream>
#include<queue>
#include<string>

using namespace std;
class animal
{
private:
  queue<int> dog, cat;
  int order;
public:
  animal()
  {
    order=0;
  };
  void enQueue(string a)
  {
    if(a=="cat")
      {
	cat.push(order);
	order++;
      }
    else
      {
	dog.push(order);
	order++;
      }
  };
  void deQueueAny(string a)
  {
    if(a=="dog")
      {
	int tmp = dog.front();
	dog.pop();
      }
    else
      {
	int tmp = cat.front();
	cat.pop();
      }
  };
  void deQueueCat()
  {
    cat.pop();
  };
  void deQueueDog()
  {
    dog.pop();
  };
};

int main()
{
  animal zoo;
  zoo.enQueue("cat");
  zoo.enQueue("cat");
  zoo.enQueue("cat");
  zoo.enQueue("dog");
  zoo.enQueue("cat");
  zoo.enQueue("dog");

  zoo.deQueueAny("cat");
  zoo.deQueueCat();
}


