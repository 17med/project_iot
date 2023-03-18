from flask import Flask,redirect,url_for,render_template
x=0

app = Flask(__name__)

@app.route("/")
def hi():
    return render_template("index.html",x=x)
@app.route("/state")
def state():
    return "<p>{}</p>".format(x)
@app.route("/change")
def change():
    
    global x
    
    if(x==0):
        x=1
    else:
        x=0
    print(f"change {x}")
    return redirect(url_for("state"))
@app.route("/<path:path>")
def el(path):
    return redirect(url_for("hi"))

