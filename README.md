# ItemTracker/GroceryTracker

Summarize the project and what problem it was solving:
* Converts data of items/groceries purchased throughout the day into a map with a key pair value showing the total frequency per item. This information is then displayed in various outputs based on user menu choice. This is helpful for figuring out which products sell the most frequently.
* You can search by item name, display all items, or show a histogram visual aid.
* Includes the ability to change the file name from the default to analyze other data files.
* The default file it reads from is: "CS210_Project_Three_Input_File.txt"
* Data for the session is stored and overwritten in: "frequency.dat"
  
What did you do particularly well?
* I think I handled the separation of data/io and the presentation/controller layer quite well. It makes it easy to test and swap in different UI functionality. I also followed Google C++ style so that the code is readable to others.

Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
* I've already considered several modifications to enhance/improve the project. I want to incorporate auto-scaling for the histogram and perhaps an additional visual output as an x/y chart.
* I've also considered a case insensitive approach utilizing std::tolower and std::transform, so it makes everything lowercase, including the search. 

Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
* Handling exceptions was a bit tricky at first, I was experiencing an issue with how I handled the throw for opening the file and loading data not properly catching. I fixed it by adding an outer try/catch in main().

What skills from this project will be particularly transferable to other projects or course work?
* I found it very helpful and methodical to build projects by breaking down the problems, turning that into classes, and going from there. The course didn't really cover this much besides a small section on UML, but I've been trying to utilize system architecture more thanks to the projects we do.
* The stream processing and map usage in data tasks will be quite helpful. And the menu's input sanitization pattern of pauseAndClear is something I've been reusing in console tools.

How did you make this program maintainable, readable, and adaptable?
* It's simplistic, there is only a has-a relationship between the classes. No pointers or cleanup required. I utilized readable google style naming. The code is quite adaptable as is, you can easily change the data file with what I've included, and adding a GUI would only require another controller class.

![image](https://github.com/user-attachments/assets/a656336b-05dd-46b1-937a-46fcc1bef150)

