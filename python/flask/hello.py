from flask import Flask, request , render_template
from markupsafe import escape 

app = Flask(__name__)

@app.route("/hello/")
@app.route("/hello/<name>")
def hello(name=None):
    return render_template("hello.html", person=name)

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        return "POST"
    else:
        return "GET"
    
@app.get('/login2')
def login_get():
    return "GET"

@app.post("/login2")
def login_post():
    return "POST"

@app.route("/")
def hello_world():
    return "<p>Hello, World</p>"

@app.route("/<name>")
def hello_index(name):
    return f"Hello, {escape(name)}!"

@app.route("/user/<username>")
def show_user_profile(username):
    return f"User {escape(username)}"

@app.route("/post/<int:post_id>")
def show_post(post_id):
    return f"Post {post_id}"

@app.route("/path/<path:subpath>")
def hsow_subpath(subpath):
    return f"Subpath {escape(subpath)}"