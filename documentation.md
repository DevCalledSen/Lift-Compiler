# Official Lift Documentation

### Simple to learn. Powerful when you need it.

---
Current Lift Compiler version: v0.1.0
---

***

## **1.0 Lift setup**
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
