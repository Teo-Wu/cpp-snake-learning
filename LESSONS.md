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

Once you're ready, you can _git merge lesson03_.

---

## Lesson 03

#### Prequisites
- Loops

#### Files
- _components/Point.cpp_
- _components/Point.h_
- _main.cpp_

#### Task

This Task will be a little on the short side. We plan to implement our Snake as a collection of points on the screen and for that, each point should be able to move by itself. This is the objective of this lesson.

1) Some new functions have appeared in _components/Point.*_ which you should inspect and try to implement.
2) Go to _main.cpp_ and see the new __mainL03__ which will use the movement functions now implemented to make one point move across the screen diagonally. Try it out!
3) As you can see, we use a for-loop for this but C++ has some other types of loop which you should familiarize yourself with. Try and play around with the commented-out loops and get the same result by using while and do-while loops.

Once you're ready, you can _git merge lesson04_.

---

## Lesson 04

#### Prequisites
- Arrays
- Switch-Statement

#### Files
- _components/Snake.cpp_
- _components/Snake.h_
- _main.cpp_

#### Task

Now things are getting serious! The snake has smelled our delicous food and is appearing - beware its poisonous fangs.

1) You will notice the new component _components/Snake.*_ which you should inspect closely.
2) C++ has whats called a switch-statement which acts like many if-else-if-else chained. Look at _Snake::updateHead_ and play around with it to figure out how a switch works.
3) Even though our snake is far from complete, we want to see it! As we decided the snake to be made up of a list of points, use a modern for-each loop to call _print()_ on all points of the snakes body.
4) You have already interacted with std::vector by now. Look at the documentation for it and figure out its purpose and what else you can do with it. Play around!

Once you're ready, you can _git merge lesson05_.

---

## Lesson 05

#### Prequisites
- Iterators/Iterating over Elements of Container

#### Files
- _components/Snake.cpp_
- _components/Snake.h_
- _main.cpp_

#### Task

The snake showed up but something is wrong. Its growing constantly without even having food. Lets fix that as we want to be super biologically accurate: no growth without energy. And as our snake can't eat yet, it should not grow at all.

This one is quite difficult. Don't worry if it takes a lot of time and if you're really stuck, try the master branch with its solution.

1) The culprit is our snakes _Snake::move()_ function which we must fix in order for the snake to stop growing endlessly.
2) There are some hints written as todos but these leave a lot of room for the implementation. If you need some help, search for iterators (over std::vector) or use a for-loop over all indices from the back. These are just suggestions - try to come up with your own solution!
3) Try this out in main where you can still use the __mainL04__ from the previous task.

Once you're ready, you can _git merge lesson06_.

---

## Lesson 06

#### Prequisites
None

#### Files
- _components/Snake.cpp_
- _components/Snake.h_
- _main.cpp_

#### Task

Our snake seems invincible for now and can't eat. Run into a wall - nothing will happen. Bite yourself - no injury. Try to eat the snack - you will just slither over it. Sad Snake :(

1) See the changes to _components/Snake.*_ and try to implement the test functions which we will use later on.
2) After implementing them, move to _main.cpp_ where __mainL06__ will allow you to test the newly written functions.
3) Figure out how you can test the bit-itself and bit-snack by yourself.

Once you're ready, you can _git merge lesson07_.

---

## Lesson 07

#### Prequisites
None

#### Files
- _components/Snake.cpp_
- _components/Snake.h_
- _main.cpp_

#### Task

The snake just learned to grow by itself! How?

1) See the changes to _components/Snake.*_ and try to understand the new code which allows the snake to grow.
2) Play around with this in _main.cpp_.

Once you're ready, you can _git merge lesson08_.

---

## Lesson 08

#### Prequisites
None

#### Files
- _game/Controller.cpp_
- _game/Controller.h_
- _main.cpp_

#### Task

Even though our snake and snack are ready, we a re still not at the point where we can play. This is where the game controller comes in.

1) Inspect the new files in _game/Controller.*_ and try to figure out their purpose.
2) In the main game-function called _Controller::act()_ there are still some unimplemented sections. Fix that!
3) There is a rudimentary game loop implemented for your use in _main.cpp_ as __mainL08__ with which you can test out what you have achieved.

---

## Improvements

If youre still hungy for more learning, check out the master branch which does things a little differently. Try to understand everything and maybe fix the weird speed difference between vertical and horizontal snake travel (Graphics has the set-vertical which you could use). You could also implement a highscore system and allow the game state to be written to a file in order to keep high scores. Good luck and thanks for working through this!