# CrossDevelopment Ionic Todo App
**Version 1.0**


---

## TestCase

As a testcase I have decided to build a todo app. Unlike the normal ToDo app's this one will have a time element to it.

So how does it work?

You can add multiple task and give each one of them a time limit, which can be started and stoped individually to keep track of every task.

What's the use case? 

well lets say you have a very strict schedule, it would be the perfect app to help with that. you can add your task as well as your breaks and make shure you stay right on schedule.

## How can you make the same program form scratch? 

We're going to build this one in ionic. Every project starts with ionic, you can decide wether or not you're going to use VueJs, React or Angular. For this project we're going to use Angular.
In Angular we have the ability to add services. This is what we're going to use for sharing the data between components. 
After you set up your project. We're going to start building the card component. The card component is build out of three elements. One being Title, 
the second one is Goals list and the last is a Timer which consist out of it's own components. After you've added the card component, you can start designing it.
Designing the Title and the Goals-list is pretty straight forward. But the clock element(time element) is a bit more tricky. Since i wanted to design the clock out of primitive shapes.
The clock is fully build with the HTML-SVG component. It consists out of a SVG-width of 250 and a height of 250. In the SVG we draw 2 circles, one beign the track and the other will call progress.
The track has to contrast well with the background as this will indicate the shape of the progress bar. The progress bar has to contrast well with the track. 
So we can clearly indicate how much progress has been made.
In order for us to animate the progress bar we have to do a couple of things: 
first of all we know that a circle in SVG consist out of 630 sections. All we need to know now is the given time input so we can calculate the amount of sections a second to draw the circle.
So now we have our card component. Now lets implement the add now page. Since every card consist of the elements: Title, Goals and Time. We know that these are the 3 variables we need to add a new task.
We'll add 3 inputs. One for Title, one for Goal and one for the Timer. The Titel input is just a normal text input. 
The goals input will just be a time input, but here you have the ability to add as many new input fields as the user wants. 
We'll achieve this by putting a for-loop around the input Goal field, and adding an add button above the field. When clicked on it, will increment an array. So that the Goals for-loop will add another input field.
and for the clock we'll use an ionic DateTime component.
The component give us a lot of control. We first specify that we're going to be using minutes and seconds. When retrieving the time from the DayTime component, We'll get back not only the time but also the date
which we have to separate. We do this by splitting the variable so we only get back MM:SS. 
We have everything we need now to form a full task. We just have to save it somewhere now. For that we'll be using a DataService. The DataService will have a Todo model. So you'll have to add a class called Todo
and give it a Title string, a Goal string array and a Time string.
Going back to the DataService, here we'll also import the capacitor storage component. Using this storage component we'll be able to save the Todo's array onto our local device.
We will also be using the DataService to share the Todo's data between different components. This way we can easily acces all Todo's, edit them and give it back to the DataService.
Now we can add tasks and have the ability to save and delete them. All that's left to do now is build it for your android or IOS device.
Im going to use android as i have an android device.

first you'll have to build ionic app:
```
Ionic build
```

this will give you a www file which capacitor will use to make a android app from with the following commando:


```
 npx cap add android 
```

for the next step you'll need to have android studio's and the Java SDK and JDK, so it you don't have that yet go install it right now and come back.

```
 npx cap open android 
```

this will open you android studio and import the android file right in there. now use add a vurtiual machine and press run.

if you want the APK file to install the app on your phone just go to toolbar hover over build go to build bundles and APK and select APK's

it will build you app and when done give you a notification to go too the download location.

## Screenshots 

Add Task

<img src="img/1.png"> <img src="img/2.png">
<img src="img/3.png">
<img src="img/4.png">
<img src="img/5.png">
<img src="img/6.png">
<img src="img/7.png">
<img src="img/8.png">






