# OOPS Theory Detailed (Interview Revision)

## 1. Class
- A class is a user-defined blueprint that groups:
- Data members (state)
- Member functions (behavior)
- It provides access control using `private`, `protected`, `public`.

Example idea:
- `class Car { int speed; void accelerate(); };`

## 2. Object
- An object is a runtime instance of a class.
- Memory for non-static members is allocated per object.
- Member functions operate on object state through the implicit `this` pointer.

## 3. Encapsulation
- Encapsulation means binding data and methods in one unit, and protecting data from direct misuse.
- Usually achieved by:
- Keeping fields `private`
- Exposing controlled methods (`set/get`, business operations)

Why interviewers care:
- Prevents invalid state.
- Makes code maintainable and testable.

## 4. Abstraction
- Abstraction means exposing only required interface while hiding implementation details.
- In C++, commonly done via:
- Abstract classes (`= 0` pure virtual function)
- Public APIs with hidden internal logic

Key line:
- User knows **what** to do, not **how** it is done internally.

## 5. Inheritance
- Inheritance lets a derived class reuse and extend a base class.
- Relationship: **is-a** (Dog is-an Animal).

Types (common in interviews):
- Single inheritance
- Multilevel inheritance
- Multiple inheritance
- Hierarchical inheritance
- Hybrid inheritance

Access modes:
- `public` inheritance: public stays public, protected stays protected
- `protected` inheritance: public/protected become protected
- `private` inheritance: public/protected become private

## 6. Polymorphism
- Polymorphism = one interface, multiple forms.

### Compile-time polymorphism
- Function overloading
- Operator overloading
- Resolved by compiler

### Runtime polymorphism
- Function overriding with `virtual`
- Call resolved at runtime using vtable/vptr mechanism

Interview note:
- Runtime polymorphism works through base pointer/reference.

## 7. Virtual Function
- A `virtual` function in base class allows derived class override to be called dynamically.

Important:
- If function is not virtual, base pointer call binds to base version (static binding).

## 8. Virtual Destructor
- If class is used polymorphically (has virtual functions), destructor should be virtual.
- Reason: deleting derived object via base pointer must call derived destructor first.

Bad:
- `Base* p = new Derived; delete p;` with non-virtual base destructor.

## 9. Constructor
- Special member function called automatically on object creation.
- Used for initialization.

Types:
- Default constructor
- Parameterized constructor
- Copy constructor
- Move constructor (modern C++)

## 10. Destructor
- Called automatically when object goes out of scope or `delete` is used.
- Used for resource cleanup (memory/file/socket lock etc.).
- Name form: `~ClassName()`

## 11. Copy Constructor
- Signature: `ClassName(const ClassName& other)`
- Called when creating a new object from existing object.

When critical:
- Class manages dynamic resource (raw pointer ownership).

## 12. Copy Assignment Operator
- Signature: `ClassName& operator=(const ClassName& other)`
- Called when assigning one existing object to another.
- Must handle:
- Self-assignment (`if (this == &other)`)
- Existing resource cleanup
- Exception-safe copy pattern

## 13. Shallow Copy vs Deep Copy
- Shallow copy: pointer value copied; both objects point to same memory.
- Deep copy: separate memory allocated and content copied.

Risk with shallow copy:
- Double delete
- Shared unintended mutation

## 14. Rule of 3 / Rule of 5 / Rule of 0
- Rule of 3:
- If class needs custom destructor, copy constructor, or copy assignment, it usually needs all 3.
- Rule of 5 (C++11+):
- Add move constructor and move assignment.
- Rule of 0:
- Prefer designing classes so compiler-generated special functions are enough (use RAII types like `std::string`, `std::vector`, smart pointers).

## 15. Static Data Member
- Belongs to class, not objects.
- Single shared copy for all objects.
- Defined once outside class.

Use cases:
- Object count
- Shared configuration

## 16. Static Member Function
- Called with class name: `ClassName::func()`
- No `this` pointer available.
- Can directly access only static members.

## 17. Friend Function
- Non-member function declared with `friend` can access private/protected members.
- Useful for:
- Operator overloading with symmetry (`<<`, `>>`, binary operators)
- Tight helper utilities

Tradeoff:
- Breaks strict encapsulation, so use only when justified.

## 18. Operator Overloading
- Gives custom meaning to operators for user-defined types.

Common overloads:
- Arithmetic: `+ - * /`
- Comparison: `== != <`
- Stream: `<< >>`

Guidelines:
- Keep semantics intuitive.
- Preserve expected behavior.
- Avoid overloading that confuses readability.

## 19. `this` Pointer
- Implicit pointer in non-static member functions.
- Points to current object.

Uses:
- Resolve naming conflict (`this->x = x`)
- Return current object (`return *this`)

## 20. Access Specifiers Quick Summary
- `private`: only same class access
- `protected`: same class + derived class
- `public`: accessible everywhere (where object is visible)

## 21. Interface vs Abstract Class (Interview angle)
- C++ does not have a separate `interface` keyword.
- Interface style is represented by abstract class with only pure virtual functions and virtual destructor.

## 22. Common Interview Pitfalls
- Forgetting virtual destructor in polymorphic base class.
- Shallow copying raw pointers.
- Returning reference to local variable.
- Object slicing: assigning derived object to base object by value.
- Overusing inheritance when composition is better.

## 23. Frequently Asked Quick Differences
- Class vs Struct in C++:
- Default access in `class` is `private`, in `struct` is `public`.
- Otherwise both can have methods, constructors, inheritance.

- Overloading vs Overriding:
- Overloading: same scope, same name, different parameters.
- Overriding: derived class redefines base virtual function with same signature.

- Early binding vs Late binding:
- Early: compile-time, non-virtual calls.
- Late: runtime, virtual calls.

## 24. Best Practices
- Prefer composition over inheritance unless clear `is-a` relationship.
- Use `override` keyword for overridden methods.
- Use `const` correctness (`func() const`) where applicable.
- Prefer smart pointers and STL containers over raw pointers.
- Keep classes small and single-responsibility focused.

---
Use this with:
- `06_oops_interview_important.cpp` for runnable examples
- `01` to `05` files for concept-wise practice
