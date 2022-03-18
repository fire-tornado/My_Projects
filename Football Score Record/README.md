In this project, I tried to implement a football database management system in the **Oracle Apex** environment. Here we have different tables for league information, team list, manager database, player database, fixture database, goal database, and card information. We have 3 different types of users (Admin, Manager, and User). The Admin has all the tables and pages available to him. A manager can enter and view data in different tables. A user can only view that data. I have implemented **triggers** and **sequences** for every table. For fetching data from a table and its corresponding parent table, I used standard **SQL queries** and **PLSQL functions**. I also implemented a fixture calendar for different matches. From there, we can easily find upcoming matches. For the goal and card databases, I implemented a pie chart and a standard bar diagram for finding the max goal scorer, max assist, and most cards (Yellow and Red). We can find the max goals and cards in terms of both players and teams. This means we can also find which team scored the maximum number of goals, etc. There are other features like total goals scored this season, total cards, maximum goal scorers of a particular team, etc.

For the interface, I have used background pictures for pages and added the logo of our application. I created a userfriendly navigation menu.
  
# Application Pages:
* Home (Accessible by all users)
* Administrator (Accessible by only the database designer and admin)
* League info (Accessible by all users)
* Create League (Accessible by manager and admin)
* Team list (Accessible by all users)
* Create Team (Accessible by manager and admin)
* Manager database (Accessible by all users)
* Manager entry (Accessible by manager and admin)
* Player details (Accessible by all users)
* Player entry (Accessible by manager and admin)
* Fixture (Calendar)
* Match info (Accessible by all users)
* Match entry (Accessible by manager and admin)
* Goal database (Accessible by all users)
* Goal entry (Accessible by manager and admin)
* Top Goal Scorer (Pie Chart and Bar Diagram)
* Top Assist (Pie Chart and Bar diagram)
* Card information (Pie Chart and Bar Diagram included)
