# Official Lift Documentation

### Simple to learn. Powerful when you need it.

---
Current Lift Compiler version: v0.1.0
---

***

## **1 Lift setup**
  * **1.1 Verifying the compiler**
  > *to verify the Lift installation in the terminal type:*
  ```bash
  lift --version
  ```

  * **1.2 Making your first project**
  > *to make a new project in Lift in the terminal type:*
  ```bash
  lift new "project-name"
  ```

  * **1.3 How the project is organised**
  > *once your project folder is created inside it you should see:*
  ```text
  project-name/
  ├── libraries.liftl
  ├── settings.lifts
  └── main.lift
  ```

  * **1.4 What libraries.liftl is**
  > *libraries.liftl is a file that is used to list all the libraries your project will use. An example of it is:*
  ```liftl
  use math[1.0.0];
  use algorithm[1.0.0];
  ```

  * **1.5 What settings.lifts is**
  > *settings.lifts is a file that is used to edit the settings of the Lift compiler. An example of it is:*
  ```lifts
  warnings = false;
  optimization = true;
  ```
  
  * **1.6 What main.lift is**
  > *main.lift is the main project file that gets compiled. An example of it is:*
  ```lift
  outputln("Hello, World!");
  ```

## **2 Beginner syntax**
  * **2.1 Basic output**
  > *Lift has two output commands output() and outputln() examples:*
  ```lift
  output("Hello, World!\n");
  outputln("Hello, World!");

  outputln("5 + 3 = ", 5+3);
  ```

  * **2.2 Basic variables**
  > *In lift declaring a variable is simple:*
  ```lift
  var x = 5;
  var name = "John";
  ```

  * **2.3 Repeat loop**
  > *In lift for the loop beginners can use repeat:*
  ```lift
  repeat 5 {
    outputln("Hello, World!");
  }
  ```

  * **2.4 Basic if logic**
  > *If you want to check if something is equal, greater, lower than something using if is the perfect way:*
  ```lift
  var x = 6;
  if x > 5 {
    outputln("x is greater than 5");
  }
  ```

  * **2.5 Basic input**
  > *For input in lift you can use the input() command:*
  ```lift
  var name = "";
  input(name);
  outputln("Hello, ", name);
  ```

  * **2.6 Arithmetics and Logic**
  > *Lift arithmetics consists of:*
  * \+
  * \-
  * \*
  * /
  * //
  > *Lift basic logic consists of:*
  * ==
  * !=
  * \>
  * <
  * \>=
  * <=
