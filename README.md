# CrossDevelopment QT TODO APP

**Version 1.0**


---

## TestCase

As a testcase I have desited to build a todo app. but unlike the normal ToDo app's this one will have an time element to it.

So how does it work?

You can add multipull task and give each one of them a time limit, whitch can be started and stoped indeviualy to keep track of every task.

What't the use case? 

well let say you have a very strick scetual. it would be the perfect app to help with that. you can add your task as well as your breaks and make you stay write on scetual.

## How can you make the same program form scratch? 

First start of with making a new mainwindow Qt application.

I may case I started with the design as is the easyest way to keep track of what has to be done. the desing needs a Pushbutton to add a new task. and a groupbox where all the task will be displayed.

if that's done just add a onclick action on the add task btn.
Now let make a new class with a dialog form. I named mine AddTask. you could name it whatever you want ofcourse.

Now let start design this dialog form ui. you will need a line edit to enter task names. A way to give the user the abilty to add how long he will be working on the app. I choose a dial for this becouse I tought it would be a more intersting way for the user to interact with the app. this ofcourse has it consucuentions like I had to put a hard limit at 60 min that way the dail had a range from 1 to 60. but if you wanted to work longer than that you would have to make a second task after the 60 min are up. but I sill think that the dial has more pros than cons it looks a lot beter, and you really shoudn't be working longer that 60 min at a time without getting up and taking a little stretch brake anyway. 

let's get back to building the app. after you gave the user a way to enter in there time limit just end the desing with an pushbutton that named "add Task".

so we have an main window and an add task window be we dont have a task yet. well this is where the widget comes in to play
so add an second class this time as a widget I called mine "task".

In this one let also start with the design lets add a checkbox for when the task is done, a label (for task name), a label for the timer witch we will build out with QPainter using primative schapes. and lets add 3 more buttons an start btn to start the timer, an reset btn to reset the timer and a delete btn to delete the task.

so we need a timer but can only use primitive schapes so how would one do this? well let take It one step at a time first of all I will be drawing My QPainter in a label so we will need a pixmap for that. after thats done lets add our first shape a circle, this will be the outercircle of the timer. to draw a circle with QPainter you'll need to use "painter.drawEllipse()" witch as the name suggestes can draw Ellipse and also circle just set the width and height to even number. on top of that let's draw a pie schape give it a different color. to make sure that the circle and pie are fully colored in use a QBrush insted of a QPen the QBrush automaticly fill's in the shape with it's set color. to make a pie shape in QPainter you'll need:
"painter.drawPie()"
after that let add one more schape the inner circle let give it the same color as the pixmap witch in my case would be white.

now you should be left with a round timer schaped object. but how do we make it funcienal well, let think about this for a second we need to make the pie shape bigger over time corseponding to the time given by the user. and since there are 360 degree in a full circle we know how to calculate it.

so let's say the user put in 5 min that let's first start by 5 * 60 to get the min in seconds the reason for doing this is becouse we will be calling are update fuction every 1 sec. now let devide the awser by 360(degrees) and you know with what interval you have to inlarge your pie shape by every second.

example:
5 min * 60 sec = 300
360 degrees / 300 sec = 1.2degrees every second

with this calcualtion so we can change our donute looking drawing to a funcuanale timer.

so what's next? well now we have all the induvidual parts be we still have to glou them together. let start by getting the write information from our addtask class this can be done by using emit and sending it to our main class and from there we give it to the task construtor witch will that use it in the task label and in the timer drawing to calculate the interval.

So when you put it all together it should work like followed. U start the app and press the add task btn this will open the add task window where you can entere you task name and give it a time limit when pressing the add task btn in this window the window will close and the class will emit the task name and time limit to the main window whitch will then inistialse a task widget and give it set veriable with the construtor and the widget will be placed in the mainwindow group box.

I have also added the abilty to change the timer color by going into the action menu and selecting File -> Settings -> Primary Color Picker.

If you allready have a timer active before changing the time than it won't change color but every task after changing the color will have this new color.

