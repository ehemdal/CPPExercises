Annotated output of fig09_10 exercise

JEH> Object 1 is created BEFORE the main() function runs

	Object 1   constructor runs   (global before main)

	MAIN FUNCTION: EXECUTION BEGINS
	Object 2   constructor runs   (local in main)
	Object 3   constructor runs   (local static in main)

JEH> Objects 5 through 7 are created in order, so the static object is "in-between"
JEH> the others.

	CREATE FUNCTION: EXECUTION BEGINS
	Object 5   constructor runs   (local in create)
	Object 6   constructor runs   (local static in create)
	Object 7   constructor runs   (local in create)

JEH> When function create() ends, the objects that are local to the function are destroyed.
JEH> So objects 5 and 7 go away in reverse order of their creation.

	CREATE FUNCTION: EXECUTION ENDS
	Object 7   destructor runs    (local in create)
	Object 5   destructor runs    (local in create)

JEH> Now execution creates a new object #4 in main().

	MAIN FUNCTION: EXECUTION RESUMES
	Object 4   constructor runs   (local in main)

JEH> Now main() ends.  The local objects are destroyed.  Because the create() function
JEH> is gone, but the main() function is still "cleaning up", the static object
JEH> created in create() is destroyed first.  Finally at the very end of main(),
JEH> the static object that was created in main() [object #3] is destroyed.

	MAIN FUNCTION: EXECUTION ENDS
	Object 4   destructor runs    (local in main)
	Object 2   destructor runs    (local in main)

	Object 6   destructor runs    (local static in create)
	Object 3   destructor runs    (local static in main)

JEH> Finally the first object is destroyed, after main() ends.

	Object 1   destructor runs    (global before main)