

The code can be run using flask. After running it, you can enter the link, It will take you to the login page. If you do not
already have an account, you can create an account from the icon above Once you log in, you will see your own page, where you
will see a table listing your goals, their details, status, and the time they were set or the time they were completed,
depending on the situation. If you are new, the table will appear empty, create your goals!! How ? There are icons at the top
on the left side, which include creating a new goal or specifying a goal that it has finished, and an icon to show you the
schedule of your actual goals. It may take you back to the home page. Also at the top of the page on the right side there is an icon to log out!

New icon: To record newmove,


historu icon: to show all your moving

app.py :Open up app.py. Atop the file are a bunch of imports, among them CS50’s SQL module and a few helper functions. More on those soon.

After configuring Flask, notice how this file disables caching of responses (provided you’re in debugging mode, which you are by default in your code50 codespace), lest you make a change to some file but your browser not notice. Notice next how it configures Jinja with a custom “filter,” usd, a function (defined in helpers.py) that will make it easier to format values as US dollars (USD). It then further configures Flask to store sessions on the local filesystem (i.e., disk) as opposed to storing them inside of (digitally signed) cookies, which is Flask’s default. The file then configures CS50’s SQL module to use project.db.

Thereafter are a whole bunch of routes, only two of which are fully implemented: login and logout. Read through the implementation of login first. Notice how it uses db.execute (from CS50’s library) to query finance.db. And notice how it uses check_password_hash to compare hashes of users’ passwords. Also notice how login “remembers” that a user is logged in by storing his or her user_id, an INTEGER, in session. That way, any of this file’s routes can check which user, if any, is logged in. Finally, notice how once the user has successfully logged in, login will redirect to "/", taking the user to their home page. Meanwhile, notice how logout simply clears session, effectively logging a user out.

Notice how most routes are “decorated” with @login_required (a function defined in helpers.py too). That decorator ensures that, if a user tries to visit any of those routes, he or she will first be redirected to login so as to log in.

Notice too how most routes support GET and POST. Even so, most of them (for now!) simply return an “apology,” since they’re not yet implemented.

project.db : data base

helpers.py : Next take a look at helpers.py. Ah, there’s the implementation of apology. Notice how it ultimately renders a template, apology.html. It also happens to define within itself another function, escape, that it simply uses to replace special characters in apologies. By defining escape inside of apology, we’ve scoped the former to the latter alone; no other functions will be able (or need) to call it.

Next in the file is login_required. No worries if this one’s a bit cryptic, but if you’ve ever wondered how a function can return another function, here’s an example!

Thereafter is lookup, a function that, given a symbol (e.g., NFLX), returns a stock quote for a company in the form of a dict with three keys: name, whose value is a str, the name of the company; price, whose value is a float; and symbol, whose value is a str, a canonicalized (uppercase) version of a stock’s symbol, irrespective of how that symbol was capitalized when passed into lookup.

Last in the file is usd, a short function that simply formats a float as USD

templates : A file containing html files ,Now look in templates/. In login.html is, essentially, just an HTML form, stylized with Bootstrap. In apology.html, meanwhile, is a template for an apology. Recall that apology in helpers.py took two arguments: message, which was passed to render_template as the value of bottom, and, optionally, code, which was passed to render_template as the value of top. Notice in apology.html how those values are ultimately used! And here’s why 0:-)

Last up is layout.html. It’s a bit bigger than usual, but that’s mostly because it comes with a fancy, mobile-friendly “navbar” (navigation bar), also based on Bootstrap. Notice how it defines a block, main, inside of which templates (including apology.html and login.html) shall go. It also includes support for Flask’s message flashing so that you can relay messages from one route to another for the user to see.
index.html Where this page contains the table in which your goals will be listed , register.html This page contains a new registration page format , new.html Where it contains the formatting of the goals entry page , done.html It contains the target setting page format as finished

requirements.txt : Next take a quick look at requirements.txt. That file simply prescribes the packages on which this app will depend.


I hope you enjoy recording your own moving robot