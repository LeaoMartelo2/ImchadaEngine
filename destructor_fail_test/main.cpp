#include <iostream>
#include <memory>

class MyClass {
    public:
        MyClass() {
            std::cout << "Constructor called!\n";
        }

        ~MyClass() {
            std::cout << "Destructor called\n";
        }
};

int main(int argc, char *argv[]) {

    std::cout << "before scope\n";
    {
        std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();
    }

    std::cout << "outside the scope \n";

    return 0;
}

/*this is calling the descructor 2 times idk what is happening, WILL cause undefined behaviour */

/* i've come to the conclusion .reset() calls the class destructor, maybe */

/* only ptr.get()->~MyClass() returns 2 destrctor outputs idk whats happening anymore lmao */

/* only using .reset() seems to work, as i only get 1 destructor output, i assume its from the .reset() method
 * could be because its going out of scope, but from previous testing, returning the main function ends the program
 * before it can get out of scope, this is a memory leak, and it only happens not to be one on the main function,
 * cuz it ends the program lol */
