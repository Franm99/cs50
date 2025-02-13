from flask import Flask, render_template, request, redirect
import sqlite3

app = Flask(__name__)

con = sqlite3.connect('froshims.db', check_same_thread=False)
cur = con.cursor()

REGISTRANTS = {}

SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee",
]


@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/deregister", methods=["POST"])
def deregister():
    
    # Forget registrant
    id = request.form.get("id")
    if id:
        cur.execute("DELETE FROM registrants WHERE id = ?", [id])
    return redirect("/registrants")


@app.route("/register", methods=["POST"])
def register():
    
    # Validate name
    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="Missing name")
    
    # Validate sport
    sports = request.form.getlist("sport")
    if not sports:
        return render_template("error.html", message="Missing sport")
    for sport in sports:
        if sport not in SPORTS:
            return render_template("error.html", message="Invalid sport")
                        
    # Remember registrant
    for sport in sports:
        cur.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", [name, sport])
    
    # Confirm registration
    return redirect("/registrants")


@app.route("/registrants")
def registrants():
    registrants = cur.execute("SELECT * FROM registrants")
    registrants_list = registrants.fetchall()
    # TODO convert sqlite result into a object type structure, so I can take the values with dot syntax.
    print(registrants_list)
    return render_template("registrants.html", registrants=registrants_list)


if __name__ == "__main__":
    app.run(debug=True)