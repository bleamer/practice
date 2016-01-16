from flask import Flask, render_template, request, jsonify

app = Flask(__name__)

@app.route("/hello")
def hello():
	return "Hello World!"


@app.route("/", methods=['GET','POST'])
def home():
	if request.method == 'POST':
		value = int(request.form.get('first'))
		value_two = int(request.form.get('second'))
		# value_two = int(request.form['number-two'])
		add_one = value + value_two*203;
		# return render_template('index.html', string="Testing!", value=add_one)
		data = {"total": str(add_one)}
		return jsonify(data)
	return render_template('index.html', string="WORRRRLD!")

if __name__ == '__main__':
	app.run(debug=True)