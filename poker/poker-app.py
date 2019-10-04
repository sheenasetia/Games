from flask import Flask,render_template
import random
import poker1
app=Flask(__name__)

@app.route('/')
def welcome():
	deck=['2C','2D','2H','2S',
	'3C','3D','3H','3S',
	'4C','4D','4H','4S',
	'5C','5D','5H','5S',
	'6C','6D','6H','6S',
	'7C','7D','7H','7S',
	'8C','8D','8H','8S',
	'9C','9D','9H','9S',
	'TC','TD','TH','TS',
	'JC','JD','JH','JS',
	'QC','QD','QH','QS',
	'KC','KD','KH','KS']
	random.shuffle(deck)
	hidden=['cover','cover','cover','cover','cover']
	cards1=[deck[0],deck[1],deck[2],deck[3],deck[4]]
	cards2=[deck[5],deck[6],deck[7],deck[8],deck[9]]
	output=poker1.examp(cards1,cards2)
	if output == cards1 :
	   	winner="User1"
	else:
		winner="Computer" 
	#winner="user1"
	return render_template("home.html",winner=winner,user1_card11=hidden,user1_card12=cards1,
		user2_card21=hidden,user2_card22=cards2)

@app.route('/sheena')
def welcome2():
	return "hello sheena"

if __name__ =='__main__':
	print(app.config)
	app.config['DEBUG']=True
	app.run()