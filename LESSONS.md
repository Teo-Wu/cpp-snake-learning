## Lesson 01

#### Prequisites
- Classes
- Functions

#### Files
- _components/Point.cpp_
- _components/Point.h_
- _main.cpp_

#### Task
1) With the point-class we represent a single dot on screen, giving it a position and character as "image". Begin by inspecting _components/Point.h_ and _components/Point.cpp_ and figure out what a header (.h) and code (.cpp) file contain and how they differ.
2) When an instance of a class in C++ is created, its constructor is used to initialize values. At some point, the created instance will get destroyed which uses the destructor. Read about these two and implement them in _components/Point.cpp_.
3) Select to call __mainL01__ in __main__ of _main.cpp_ and think or read about the purpose of this function as the applications entry point.
4) See what happens when you run the application now and play around with the point or maybe create multiple. You can also modify the destructor to do something special (like print to the command line).
5) Go to _components/Point.*_ again and look at the member variables x,y and img. Notice that they are defined in a "private" region. Try to modify these directly in the main function __mainL01__. If that does not work, you can implement the getters and setters marked with TODO in _components/Point.cpp_
6) Continue exploring around with the point and see what happens.

Once you're ready, you can _git merge lesson02_.

---

## Lesson 02

#### Prequisites
- Random Numbers
- Functions
- Pointers/References

#### Files
- _components/Snack.cpp_
- _components/Snack.h_
- _main.cpp_

#### Task
Every little snake needs to eat. And no snake will appear without food, which is why we begin by providing this essential item.

1) We want to implement the _Snack_ as an instance of the Point-Class from the previous Task. Therefore we will write a function that turns an ordinary Point into a delicious Snack. This will be called _generateSnack_ and we will implement it in _components/Snack.*_ where you can see the skeleton for the function.
2) A Snack must be placed at a random point when generating, so set its x and y value to a random value that fits on the playing field (see the comment in the function skeleton for a hint).
3) A Snack must also look enticing, so set its image to the one defined as SNACK_CHAR and then display the delicious snack.
4) Experiment and use __mainL02__ to test if your code works.
5) Notice anything interesting with how we pass the Point to the generateSnack-function? The function requests a pointer which is the address of an object instance. To get the address of an existing object, we use operator&. Read up on pointers and references.